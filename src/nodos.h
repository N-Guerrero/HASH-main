#ifndef __NODOS_H__
#define __NODOS_H__
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct nodo{
    char* clave;
    void* valor;
    struct nodo* siguiente;
}nodo_t;

nodo_t* crear_nodo(char* clave,void* valor);

//bool insertar_nodo(nodo_t* primer_nodo,nodo_t* nuevo_nodo);

void destuir_nodos(nodo_t* nodo,void (*destructor)(void*));



#endif