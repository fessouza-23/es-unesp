#include <stdio.h>
#include <stdlib.h>

#define array_size 7

typedef struct node {
    int value;
    struct node* next;
} List;

typedef struct {
    List* array[array_size];
} Hash_table; // store lists pointers

int Hash(int key) {
    return (key % array_size);
}

void hash_insert(Hash_table* table, int value) {
    int index = Hash(value);
    printf("Index: %d\n", index);
    List* new_node = malloc(sizeof(List));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->value = value;
    new_node->next = table->array[index];
    table->array[index] = new_node;
}

List* hash_search(Hash_table* table, int value) {
    int index = Hash(value);
    List* node = table->array[index];
    while (node) {
        if (node->value == value)
            return node;
        node = node->next;
    }
    return NULL;
}

int main() {
    Hash_table hash = {0}; // initialize pointers to NULL

    hash_insert(&hash, 7);
    hash_insert(&hash, 14);
    hash_insert(&hash, 33);
    hash_insert(&hash, 44);

    int values_to_search[] = {7, 3, 44, 5};
    for (int i = 0; i < sizeof(values_to_search) / sizeof(values_to_search[0]); i++) {
        List* result = hash_search(&hash, values_to_search[i]);
        if (result) {
            printf("Value %d found in the hash table.\n", values_to_search[i]);
        } else {
            printf("Value %d not found in the hash table.\n", values_to_search[i]);
        }
    }

    for (int i = 0; i < array_size; i++) {
        List* node = hash.array[i];
        while (node) {
            List* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return 0;
}