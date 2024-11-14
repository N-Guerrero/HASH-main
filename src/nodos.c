#include "nodos.h"
nodo_t* crear_nodo(char* clave,void* valor){
    nodo_t* nuevo_nodo=malloc(sizeof(nodo_t));
    if(nuevo_nodo==NULL)
        return NULL;
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    nuevo_nodo->clave=malloc(sizeof(strlen(clave)+1));
    if(nuevo_nodo->clave==NULL)
        return NULL;
    strcpy(nuevo_nodo->clave,clave);

    return nuevo_nodo;
}

void destuir_nodos(nodo_t* nodo,void (*destructor)(void*)){
    while (nodo != NULL) {
        nodo_t* temp = nodo;
        nodo = nodo->siguiente;
        if(destructor!=NULL)
            destructor(temp->valor);
        free(temp->clave);  
        free(temp);
    }
}