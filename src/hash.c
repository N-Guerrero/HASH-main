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

size_t funcion_hash(const char* clave,size_t capacidad){

    size_t pos = 0;
    

    for (size_t i = 0; clave[i] != '\0'; i++) {
        pos = pos * 3 + (unsigned char)clave[i];
    }

    return pos % capacidad;    
}

bool hash_insertar(hash_t* hash, char* clave, void* valor, void** encontrado){

    if(clave==NULL || hash==NULL)
        return false;
    size_t pos=funcion_hash(clave,hash->capacidad);
    nodo_t* nuevo_nodo=crear_nodo(clave,valor);
    if(nuevo_nodo==NULL)
        return false;
    bool respuesta= insertar_nodo(&(hash->vector[pos]),nuevo_nodo,encontrado);
    if(respuesta)
        hash->cantidad++;
    return respuesta;

}

void* hash_buscar(hash_t* hash, char* clave){
    if(hash==NULL || clave==NULL)
        return NULL;
    
    size_t pos=funcion_hash(clave,hash->capacidad);

    return buscar_nodo_elemento(&(hash->vector[pos]),clave);

}

bool hash_contiene(hash_t* hash, char* clave){
    void* existe = hash_buscar(hash,clave);
    if(existe==NULL)
        return false;
    return true;
}


void* hash_quitar(hash_t* hash, char* clave){
    if(hash==NULL || clave==NULL)
        return NULL;
    
    size_t pos=funcion_hash(clave,hash->capacidad);
    void* respuesta= quitar_nodo(&(hash->vector[pos]),clave);
    if(respuesta!= NULL)
        hash->cantidad--;
    return respuesta;
}

size_t hash_iterar(hash_t* hash, bool (*f)(char*, void*, void*), void* ctx){
    if(hash==NULL || f==NULL)
        return 0;

    size_t cantidad=0;
    for(size_t i=0;i<hash->capacidad;i++){
        if(hash->vector[i]==NULL)
            continue;
        nodo_t* aux=hash->vector[i];
        bool continuar=true;
        while(aux!=NULL && continuar){

            continuar=f(aux->clave,aux->valor,ctx);
            cantidad++;
            aux=aux->siguiente;
        }
    }
    return cantidad;
}