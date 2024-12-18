#include "nodos.h"
#include <stdlib.h>
nodo_t *crear_nodo(char *clave, void *valor)
{
	if (clave == NULL)
		return NULL;
	nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
	if (nuevo_nodo == NULL)
		return NULL;
	nuevo_nodo->valor = valor;
	nuevo_nodo->siguiente = NULL;
	nuevo_nodo->clave = malloc(strlen(clave) + 1);
	if (nuevo_nodo->clave == NULL) {
		free(nuevo_nodo);
		return NULL;
	}
	strcpy(nuevo_nodo->clave, clave);

	return nuevo_nodo;
}

void destuir_nodos(nodo_t *nodo, void (*destructor)(void *))
{
	while (nodo != NULL) {
		nodo_t *temp = nodo;
		nodo = nodo->siguiente;
		if (destructor != NULL)
			destructor(temp->valor);
		free(temp->clave);
		free(temp);
	}
}

void *buscar_nodo_elemento(nodo_t **primer_nodo, char *clave)
{
	if (primer_nodo == NULL)
		return NULL;
	nodo_t *aux = *primer_nodo;

	if (aux == NULL)
		return NULL;

	while (aux->siguiente != NULL && strcmp(aux->clave, clave) != 0) {
		aux = aux->siguiente;
	}

	if (strcmp(aux->clave, clave) == 0) {
		return aux->valor;
	}
	return NULL;
}
void *quitar_nodo(nodo_t **primer_nodo, char *clave, bool *encontrado)
{
	if (primer_nodo == NULL)
		return NULL;
	nodo_t *aux = *primer_nodo;
	nodo_t *anterior = NULL;
	if (aux == NULL)
		return NULL;

	while (aux != NULL && aux->clave != NULL &&
	       strcmp(aux->clave, clave) != 0) {
		anterior = aux;
		aux = aux->siguiente;
	}

	if (aux == NULL)
		return NULL;
	if (anterior == NULL)
		*primer_nodo = aux->siguiente;
	else {
		anterior->siguiente = aux->siguiente;
	}
	*encontrado = true;
	void *encontrado_p = aux->valor;
	free(aux->clave);
	free(aux);
	return encontrado_p;
}

bool insertar_nodo(nodo_t **primer_nodo, nodo_t *nuevo_nodo, void **encontrado,
		   bool *modificar)
{
	if (nuevo_nodo == NULL || primer_nodo == NULL)
		return false;
	nodo_t *aux = *primer_nodo;

	if (aux == NULL) {
		if (encontrado)
			*encontrado = NULL;
		*modificar = false;
		*primer_nodo = nuevo_nodo;
		return true;
	}

	while (aux->siguiente != NULL &&
	       strcmp(aux->clave, nuevo_nodo->clave) != 0) {
		aux = aux->siguiente;
	}
	if (strcmp(aux->clave, nuevo_nodo->clave) == 0) {
		if (encontrado)
			*encontrado = aux->valor;
		free(aux->clave);
		aux->clave = nuevo_nodo->clave;
		aux->valor = nuevo_nodo->valor;
		free(nuevo_nodo);
		*modificar = true;
		return true;
	}
	*modificar = false;
	aux->siguiente = nuevo_nodo;
	return true;
}