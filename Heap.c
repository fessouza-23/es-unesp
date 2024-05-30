#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct {
    int array[MAX];
    int size;
} Heap;

// Mantém a propriedade de max heap
void max_heapify(Heap* heap, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < heap->size && heap->array[l] > heap->array[i])
        largest = l;
    if (r < heap->size && heap->array[r] > heap->array[largest])
        largest = r;
    if (largest != i) {
        int aux = heap->array[i];
        heap->array[i] = heap->array[largest];
        heap->array[largest] = aux;
        max_heapify(heap, largest);
    }
}

// Constrói um max heap a partir de um array
void build_max_heap(Heap* heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--) {
        max_heapify(heap, i);
    }
}

// Insere um elemento na heap
void insert(Heap* heap, int value) {
    if (heap->size == MAX) {
        printf("Heap cheia\n");
        return;
    }
    int i = heap->size++;
    heap->array[i] = value;

    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        int aux = heap->array[i];
        heap->array[i] = heap->array[(i - 1) / 2];
        heap->array[(i - 1) / 2] = aux;
        i = (i - 1) / 2;
    }
}

// Extrai o maior elemento da heap
int extract_max(Heap* heap) {
    if (heap->size <= 0) {
        printf("Heap vazia\n");
        return -1;
    }
    if (heap->size == 1) {
        return heap->array[--heap->size];
    }

    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    max_heapify(heap, 0);

    return root;
}

// Imprime a heap
void print_heap(Heap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    Heap heap;
    heap.size = 0;

    // Inserir elementos na heap
    insert(&heap, 3);
    insert(&heap, 5);
    insert(&heap, 10);
    insert(&heap, 1);
    insert(&heap, 2);
    insert(&heap, 7);

    // Imprimir a heap
    printf("Heap: ");
    print_heap(&heap);

    // Extrair o máximo
    int max = extract_max(&heap);
    printf("Máximo extraído: %d\n", max);

    // Imprimir a heap após extração
    printf("Heap após extração: ");
    print_heap(&heap);

    return 0;
}
