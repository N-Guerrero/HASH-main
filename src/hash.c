#include "hash.h"
#include <stdlib.h>
#include "nodos.h"


struct hash{
    nodo_t** vector;
    size_t cantidad;
    size_t capacidad;

};

hash_t* hash_crear(size_t capacidad_inicial){

    hash_t *tabla=calloc(1,sizeof(hash_t));
    if(tabla==NULL)
        return  NULL;
        
    if(capacidad_inicial<=3){
        tabla->vector=calloc(3,sizeof(nodo_t*));
        if(tabla->vector==NULL){
            free(tabla);
            return  NULL;
        }
        tabla->capacidad=3;
           
        return tabla;
    }
    tabla->vector=calloc(capacidad_inicial,sizeof(nodo_t*));
    if(tabla->vector==NULL){
        free(tabla);
        return  NULL;
    }
    tabla->capacidad=capacidad_inicial;
    return tabla;
        
}
void hash_destruir_todo(hash_t* hash, void (*destructor)(void*)){
    if(hash ==NULL || hash->vector==NULL)
        return;
    
    for(size_t i=0;i<hash->capacidad;i++){
        destuir_nodos(hash->vector[i],destructor);
    }
    free(hash->vector);
    free(hash);
}

void hash_destruir(hash_t* hash){
    hash_destruir_todo(hash,NULL);
}

size_t hash_cantidad(hash_t* hash){
    if(hash==NULL)
        return 0;
    return hash->cantidad;
}