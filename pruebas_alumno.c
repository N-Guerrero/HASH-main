#include "pa2m.h"
#include "src/hash.h"
void prueba_crear()
{
	hash_t* tabla_1=hash_crear(1);
	hash_t* tabla_4=hash_crear(4);	
	
	pa2m_afirmar(tabla_1 ==NULL, "tabla_1 vacia");
	pa2m_afirmar(tabla_4 ==NULL, "tabla_4 vacia");
	int a=10,v=23;
	hash_insertar(tabla_1,"hola",&a,NULL);
	hash_insertar(tabla_4,"ha",&v,NULL);
	
	
}

int main()
{
	pa2m_nuevo_grupo("============== ??? ===============");
	prueba_crear();

	return pa2m_mostrar_reporte();
}
