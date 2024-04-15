#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct cliente {
    int quant_prod;
    struct cliente * prox;
}* noc;

typedef struct funcionario {
    int tempo_process, tempo_gasto;
    struct funcionario * prox;
}* nof;

void cria_lista_cliente(noc * lista) {
    * lista = NULL;
}

void cria_lista_funcionario(nof * lista) {
    * lista = NULL;
}

// Inserir no fim
void enqueue_cliente(noc * lista, int quant_prod) {
    noc no_cliente = (noc) malloc(sizeof(struct cliente));
    no_cliente -> quant_prod = quant_prod;
    no_cliente -> prox = NULL;
    if ( * lista == NULL)
        *
        lista = no_cliente;
    else {
        noc p = * lista;
        while (p -> prox)
            p = p -> prox;
        p -> prox = no_cliente;
    }
}

// Retirar começo
void dequeue_cliente(noc * lista) {
    if ( * lista == NULL)
        return;
    noc p = * lista;
    * lista = p -> prox;
    free(p);
}

bool listaVazia_cliente(noc lista) {
    return (lista == NULL);
}

void enqueue_funcionario(nof * lista, int tempo_process) {
    nof no_funcionario = (nof) malloc(sizeof(struct funcionario));
    no_funcionario -> tempo_process = tempo_process;
    no_funcionario -> prox = * lista;
    no_funcionario -> tempo_gasto = 0;
    * lista = no_funcionario;
}

// Encontra o funcionario livre e com menor tempo de processamento (vi)
nof algumFuncionarioLivre(nof lista) {
    nof p = lista;
    nof possivel_func = NULL; // Inicializa com NULL para garantir que qualquer funcionário livre será considerado
    while (p) {
        if (p -> tempo_gasto == 0) {
            if (possivel_func == NULL || p -> tempo_process < possivel_func -> tempo_process)
                possivel_func = p;
        }
        p = p -> prox;
    }
    return possivel_func;
}

int main() {
    int n, m, v, c; // n = funcionarios, m = cliente;

    scanf("%d %d", & n, & m);

    noc listac;
    nof listaf;
    cria_lista_cliente( & listac);
    cria_lista_funcionario( & listaf);

    for (int i = 0; i < n; i++) {
        scanf("%d", & v);
        enqueue_funcionario( & listaf, v);
    }

    for (int j = 0; j < m; j++) {
        scanf("%d", & c);
        enqueue_cliente( & listac, c);
    }

    int tempo_total = 0, max_tempo = 0;
    noc cliente_atual = listac;
    nof func_mais_lento = NULL;

    // Calcula o tempo total necessário para atender a todos os clientes
    while (!listaVazia_cliente(listac)) {
        cliente_atual = listac;
        nof func_livre = algumFuncionarioLivre(listaf);
        if (func_livre != NULL) // Verifica se há funcionário livre
        {
            func_livre -> tempo_gasto = func_livre -> tempo_process * cliente_atual -> quant_prod;

            // se chegar no ultimo cliente, pega o funcionario com maior tempo_gasto a soma na quant_total
            // se retirar essa parte não soma nada caso o n = m ou n < m
            if (cliente_atual -> prox == NULL) {
                for (nof x = listaf; x != NULL; x = x -> prox) {
                    if (x -> tempo_gasto > max_tempo) {
                        max_tempo = x -> tempo_gasto;
                        func_mais_lento = x;
                    }
                }
                tempo_total += func_mais_lento -> tempo_gasto;
            }
            dequeue_cliente( & listac);
        } else {
            int min_tempo = INT_MAX;
            // Encontra o funcionário com o menor tempo gasto
            for (nof p = listaf; p != NULL; p = p -> prox) {
                if (p -> tempo_gasto < min_tempo)
                    min_tempo = p -> tempo_gasto;
            }
            // Subtrai o tempo mínimo dos funcionários -> precisa subtrair de todos
            // pois todos estao trabalhando ao mesmo tempo
            for (nof p = listaf; p != NULL; p = p -> prox) {
                p -> tempo_gasto -= min_tempo;
            }
            tempo_total += min_tempo;
        }
    }

    printf("%d\n", tempo_total);

    return 0;
}