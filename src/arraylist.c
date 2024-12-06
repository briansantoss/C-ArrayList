#include <stdlib.h>
#include <string.h>
#include "../include/arraylist.h"

ArrayList *init_arrlist(size_t capacity) {
    ArrayList *newArr = (ArrayList *) malloc(sizeof(ArrayList));

    int *arrItems = (int *) calloc(capacity, sizeof (int));

    if (newArr == NULL || arrItems == NULL)
        return NULL;

    newArr->items = arrItems; // Atribuindo os espaços reservados ao array
    newArr->size = 0; // Inicializando a variável que guarda o tamanho atual
    newArr->capacity = capacity; // Inicializando a variável de capacidade

    return newArr;
}

static ArrayList *resize_arrlist(ArrayList *arrlist) {
    if (arrlist == NULL)
        return NULL;

    // Definindo variáveis auxiliares
    int oldCapacity = arrlist->capacity;
    int newCapacity = arrlist->capacity * GROWTH_FACTOR;

    int *newItems = (int *) realloc(arrlist->items, newCapacity * sizeof (int));

    if (newItems == NULL)
        return NULL;

    // Inicializando as novas posições alocadas com 0
    memset(newItems + oldCapacity, 0, oldCapacity * sizeof (int));

    arrlist->items = newItems; // Atualiza o ponteiro para os itens
    arrlist->capacity = newCapacity; // Atualiza a capacidade do array

    return arrlist;
}

static bool is_in_bounds(ArrayList *arrlist, int index) {
    return arrlist != NULL && index >= 0 && index < arrlist->size;
}

bool is_empty(ArrayList *arrlist) {
    return arrlist == NULL || arrlist->size == 0;
}

bool is_full(ArrayList *arrlist) {
    return arrlist != NULL && arrlist->size == arrlist->capacity;
}

bool append(ArrayList *arrlist, int value) {
    if (arrlist == NULL) 
        return false;

    if (is_full(arrlist)) {
        if (resize_arrlist(arrlist) == NULL) {
            return false;
        }
    }

    arrlist->items[arrlist->size++] = value; // O tamanho é o índice do novo elemento, por isso o incremento posterior à operação

    return value;
}

int get(ArrayList *arrlist, size_t index) {
    if (is_in_bounds(arrlist, index)) {
        return arrlist->items[index];
    }

    return -1;
}