#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size 7

typedef struct node {
    char *key;
    double value;
    struct node* next;
} List;

typedef struct {
    List* array[array_size];
} Hash_table;

int Hash(const char *key) {
    int hash = 0;
    int weight = 1;
    while (*key) { // until there is a char
        hash = ((hash + *key) * weight) % array_size;
        key++;
        weight++;
    }
    return hash;
}

void hash_insert(Hash_table* table, const char* key, double value) {
    int index = Hash(key);
    printf("Index: %d\n", index);
    List* new_node = malloc(sizeof(List));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->key = strdup(key); // key copy
    new_node->value = value;
    new_node->next = table->array[index];
    table->array[index] = new_node;
}

List* hash_search(Hash_table* table, const char* key) {
    int index = Hash(key);
    List* node = table->array[index];
    while (node) {
        if (strcmp(node->key, key) == 0)
            return node;
        node = node->next;
    }
    return NULL;
}

int main() {
    Hash_table hash = {0};

    hash_insert(&hash, "pera", 9.70);
    hash_insert(&hash, "pare", 1.00);

    const char* keys_to_search[] = {"pera", "pare"};
    for (int i = 0; i < sizeof(keys_to_search) / sizeof(keys_to_search[0]); i++) {
        List* result = hash_search(&hash, keys_to_search[i]);
        if (result) {
            printf("O preço de %s é: %.2f\n", keys_to_search[i], result->value);
        } else {
            printf("%s não encontrado na tabela hash.\n", keys_to_search[i]);
        }
    }

    for (int i = 0; i < array_size; i++) {
        List* node = hash.array[i];
        while (node) {
            List* temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }

    return 0;
}
