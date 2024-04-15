#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int array[MAX_SIZE];
    int top;
} Pilha;

void init(Pilha *pilha) {
    pilha->top = -1;
}

int isEmpty(Pilha *pilha) {
    return (pilha->top == -1) ? 1 : 0;
}

int isFull(Pilha *pilha) {
    return (pilha->top == (MAX_SIZE - 1)) ? 1 : 0;
}

void push(Pilha *pilha, int num) {
    if (isFull(pilha)) {
        printf("ERRO!\nPilha cheia.\n");
        return;
    }
    pilha->top++;
    pilha->array[pilha->top] = num;
}

int pop(Pilha *pilha) {
    if (isEmpty(pilha)) {
        printf("ERRO!\nPilha vazia.\n");
        return -1;
    }
    int num = pilha->array[pilha->top];
    pilha->top--;
    return num;
}

int main() {
    Pilha pilha;
    init(&pilha);

    push(&pilha, 10);

    if (!isEmpty(&pilha)) {
        int value = pop(&pilha);
        printf("Elemento retirado: %d\n", value);
    } else {
        printf("Pilha vazia. Não é possível retirar elementos.\n");
    }

    return 0;
}
