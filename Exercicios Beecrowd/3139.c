#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct no {
    int info;
    struct no *prox;
} *def_fila;

void start(def_fila *fila) {
    *fila = NULL;
}

// Inserir fim
void enqueue(def_fila *fila, int info) {
    def_fila no = (def_fila) malloc(sizeof(struct no));
    no->info = info;
    no->prox = NULL;
    if(*fila == NULL)
        *fila = no;
    else {
        def_fila p = *fila;
        while(p->prox)
            p = p->prox;
        p->prox = no;
    }
}

// Retirar começo
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

int media30Dias(def_fila fila) {
    def_fila no = fila;
    int sum = 0;
    for(int i = 0; i < 30; i++) {
        sum += no->info;
        no = no->prox;
    }
    sum /= 30;
    return ceil(sum);
}

int main() {
    int atual, meta, val, media, dias = 0;
    def_fila fila;
    start(&fila);

    scanf("%d %d", &atual, &meta);

    for(int i = 0; i < 30; i++) {
        scanf("%d", &val);
        enqueue(&fila, val);
    }

    while(atual < meta) {
        media = media30Dias(fila);
        atual += media;
        dequeue(&fila);
        enqueue(&fila, media);
        dias++;
    }
    printf("%d\n", dias);
    return 0;
}