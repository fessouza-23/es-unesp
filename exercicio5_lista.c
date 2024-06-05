#include <stdio.h>
#include <stdlib.h>
#define tam 7

typedef struct no {
    int info;
    struct no* prox;
} Lista;

typedef struct {
    Lista* vetor[tam]; // aponta para uma lista
} Tabela_hash;

int Hash(int chave) {
    return (chave % tam);
}

int insere(Tabela_hash* tabela, int valor) {
    int i = Hash(valor);
    Lista* no = malloc(sizeof(Lista));
    no->info = valor;
    no->prox = NULL;
    Lista** ponteiro = &(tabela->vetor[i]); // ponteiro aponta para primeiro valor da lista em vetor[i]
    while (*ponteiro != NULL && (*ponteiro)->info < valor) {
        ponteiro = &((*ponteiro)->prox);
    }
    no->prox = *ponteiro;
    *ponteiro = no;

    return i;
}

int main() {
    return 0;
}