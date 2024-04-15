#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    char array[MAX];
    int topo;
} Pilha;

void iniciar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

bool estaVazio(Pilha *pilha) {
    return (pilha->topo == -1);
}

bool estaCheia(Pilha *pilha) {
    return (pilha->topo == MAX - 1);
}

bool push(Pilha *pilha, char elemento) {
    if (estaCheia(pilha)) {
        printf("Erro\nPilha esta cheia.\n");
        return false;
    } else {
        pilha->topo++;
        pilha->array[pilha->topo] = elemento;
        return true;
    }
}

bool pop(Pilha *pilha) {
    if (estaVazio(pilha)) {
        return false;
    } else {
        pilha->topo--;
        return true;
    }
}

int main() {
    char expressao[MAX];
    Pilha pilha;
    
    while (scanf("%s", expressao) != EOF) {
        iniciar_pilha(&pilha);
        bool flag = true; 
        
        for (int j = 0; expressao[j] != '\0'; j++) {
            if (expressao[j] == '(') {
                if (!push(&pilha, '(')) {
                    flag = false;
                    break;
                }
            } else if (expressao[j] == ')') {
                if (!pop(&pilha)) {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag && estaVazio(&pilha))
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}