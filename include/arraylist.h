#ifndef ARRAYLIST_H
#define ARRAYLIST_H

// Macro que estabelece quanto o ArrayList vai crescer ao ser redimensionado
#define GROWTH_FACTOR 2

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int *items;
    size_t size;
    size_t capacity;
} ArrayList;

ArrayList *init_arrlist(size_t capacity); // Inicializa um ArrayList com a quantidade de posições passadas via parâmetro 

static ArrayList *resize_arrlist(ArrayList *arrlist); // Redimensiona o ArrayList passado por parâmetro
static bool is_in_bounds(ArrayList *arrlist, int index); // Verifica se uma posição está dentro ou não dos limites do ArrayList (0 <= position < size)

bool is_empty(ArrayList *arrlist); // Retorna True ou False com base na comparação entre a atual carga e capacidade máxima do ArrayList
bool is_full(ArrayList *arrlist); // Retorna True ou False com base na comparação entre a atual carga e capacidade máxima do ArrayList

bool append(ArrayList *arrlist, int value); // Insere o valor passado por parâmetro ao final do ArrayList e retorna True ou false baseado no êxito ou não
int insert_at(ArrayList *arrlist, size_t position, int value); // Insere o valor passado via parâmetro na posição informada 

int get(ArrayList *arrList, size_t index); // Retorna o valor na posição passada por parâmetro

void *pop(ArrayList *arrlist); // Remove o valor que ocupa a última posição do ArrayList
void *remove_at(ArrayList *arrlist, size_t position); // Remove o valor na posição passada via parâmetro

#endif