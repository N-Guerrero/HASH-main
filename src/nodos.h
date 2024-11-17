#ifndef __NODOS_H__
#define __NODOS_H__
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef struct nodo {
	char *clave;
	void *valor;
	struct nodo *siguiente;
} nodo_t;
//reserva memoria y asigna los valores de un nodo nuevo
nodo_t *crear_nodo(char *clave, void *valor);

void *buscar_nodo_elemento(nodo_t **primer_nodo, char *clave);

void *quitar_nodo(nodo_t **primer_nodo, char *clave, bool *encontrado);

bool insertar_nodo(nodo_t **primer_nodo, nodo_t *nuevo_nodo, void **encontrado,
		   bool *modificar);

void destuir_nodos(nodo_t *nodo, void (*destructor)(void *));

#endif