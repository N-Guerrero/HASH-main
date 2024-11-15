#include "pa2m.h"
#include "src/hash.h"
void prueba_crear()
{
	hash_t* tabla_1=hash_crear(1);
	hash_t* tabla_4=hash_crear(4);	
	
	pa2m_afirmar(tabla_1 != NULL, "tabla_1 existe");
	pa2m_afirmar(tabla_4 != NULL, "tabla_4 existe");
	hash_destruir(tabla_1);
	hash_destruir(tabla_4);
	
}
void prueba_insertar(){
	hash_t* tabla_1=hash_crear(1);
	hash_t* tabla_4=hash_crear(4);	
	
	int a=10,v=23;
	
	pa2m_afirmar(hash_insertar(tabla_1,"hola",&a,NULL), "inseretado en tabla_1");
	
	pa2m_afirmar(hash_insertar(tabla_4,"ha",&v,NULL), "inseretado en tabla_4");

	hash_destruir(tabla_1);
	hash_destruir(tabla_4);

}

int main()
{
	pa2m_nuevo_grupo("============== ??? ===============");
	prueba_crear();
	prueba_insertar();

	return pa2m_mostrar_reporte();
}
