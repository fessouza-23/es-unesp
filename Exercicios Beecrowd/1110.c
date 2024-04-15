#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no *prox;
} *def_fila;

bool isEmpty(def_fila fila) {
    return (fila == NULL);
}

void start(def_fila* fila) {
    *fila = NULL;
}

// Inserir no fim
void enqueue(def_fila* fila, int info) {
    def_fila no = (def_fila) malloc(sizeof(struct no));
    no->info = info;
    no->prox = NULL;
    if(*fila == NULL) {
        *fila = no;
    } else {
        def_fila p = *fila;
        while(p->prox)
            p = p->prox;
        p->prox = no;
    }
}

// Retirar no começo
void dequeue(def_fila *fila) {
    if(*fila == NULL)
        return;
    def_fila no = *fila;
    *fila = no->prox;
    free(no);
}

void show(def_fila fila) {
    def_fila no = fila;
    printf("[");
    while(no) {
        if(no->prox != NULL) {
            printf("%d, ", no->info);
        } else
            printf("%d", no->info);
        no = no->prox;
    }
    printf("]\n");
}

int numCards(def_fila fila) {
    def_fila no = fila;
    int i = 0;
    while(no) {
        i++;
        no = no->prox;
    }
    return i;
}

int fCard(def_fila fila) {
    def_fila no = fila;
    return no->info;
}

int main() {
    int n, i, fNum;
    int descartadas[100] = {0};

    def_fila fila;

    do {
        scanf("%d", &n);

        if (n == 0)
            break;

        start(&fila);

        for(i = 1; i <= n; i++) {
            enqueue(&fila, i);
        }
        
        i = 0;

        while(numCards(fila) > 1) { 
            fNum = fCard(fila);
            descartadas[i] = fNum; 
            i++;
            dequeue(&fila);
            
            fNum = fCard(fila);
            dequeue(&fila);
            enqueue(&fila, fNum);
        }

        printf("Discarded cards: ");
        for(int j = 0; j < i; j++) { 
            if(j != i - 1) {
                printf("%d, ", descartadas[j]);
            } else
                printf("%d", descartadas[j]);
        }

        printf("\nRemaining card: %d\n", fCard(fila));

    } while(true);

    return 0;
}
