#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1001

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

bool estaCheio(Pilha *pilha) {
    return (pilha->topo == MAX - 1);
}

void push(Pilha *pilha) {
    if(estaCheio(pilha)) {
        printf("ERR0!\nPilha cheia");
    } else {
        pilha->topo++;
        pilha->array[pilha->topo] = '<';
    }
}

void pop(Pilha *pilha) {
    if(estaVazio(pilha)) {
        printf("ERR0\nPilha vazia\n");
    } else {
        if(pilha->array[pilha->topo] == '<') {
            pilha->topo--;
        } else {
            printf("Mismatched diamonds!\n");
        }
    }
}

int main() {
    int cont, diamantes;
    char expressao[MAX];
    Pilha pilha;

    scanf("%d", &cont);

    for (int i = 0; i < cont; i++) {
        scanf("%s", expressao);

        diamantes = 0;

        iniciar_pilha(&pilha);
        for (int j = 0; j < strlen(expressao); j++) {
            if(expressao[j] == '<') {
                push(&pilha);
            } else if(expressao[j] == '>') {
                if(!estaVazio(&pilha)) {
                    diamantes++;
                    pop(&pilha);
                }
            }
        }

        printf("%d\n", diamantes);
        iniciar_pilha(&pilha);

    }

    return 0;
}
