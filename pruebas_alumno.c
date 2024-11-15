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
void prueba_remplazar(){
	hash_t* tabla_1=hash_crear(1);
	hash_t* tabla_4=hash_crear(4);	
	
	int a=10,v=23,b=40;
	
	pa2m_afirmar(hash_insertar(tabla_1,"hola",&a,NULL), "inseretado %d en tabla_1",a);
	
	pa2m_afirmar(hash_insertar(tabla_4,"hala",&v,NULL), "inseretado %d en tabla_4",v);

	void* anterior=NULL;
	pa2m_afirmar(hash_insertar(tabla_1,"hola",&b,&anterior), "inseretado %d en tabla_1",b);

    pa2m_afirmar(anterior!= NULL,"se remplazo a %d",*(int*)anterior);
  
	hash_destruir(tabla_1);
	hash_destruir(tabla_4);
}

void prueba_buscar(){
	hash_t* tabla_1=hash_crear(1);
	hash_t* tabla_10=hash_crear(10);	
	
	int a=10,v=23;
	
	pa2m_afirmar(hash_insertar(tabla_1,"hola",&a,NULL), "inseretado en tabla_1");
	
	pa2m_afirmar(hash_insertar(tabla_10,"ka",&v,NULL), "inseretado en tabla_10");

	
	int x1=11,x2=12,x3=13,x4=41,x5=51,x6=60;
	pa2m_afirmar(hash_insertar(tabla_10,"mala",&x1,NULL),"insertado %d en tabla_10",x1);
	pa2m_afirmar(hash_insertar(tabla_10,"masa",&x2,NULL),"insertado %d en tabla_10",x2);
	pa2m_afirmar(hash_insertar(tabla_10,"malo",&x3,NULL),"insertado %d en tabla_10",x3);
	pa2m_afirmar(hash_insertar(tabla_10,"mara",&x4,NULL),"insertado %d en tabla_10",x4);
	pa2m_afirmar(hash_insertar(tabla_10,"xala",&x5,NULL),"insertado %d en tabla_10",x5);
	pa2m_afirmar(hash_insertar(tabla_10,"mera",&x6,NULL),"insertado %d en tabla_10",x6);


	void* encontrado=hash_buscar(tabla_10,"xala");
	pa2m_afirmar(*(int*)encontrado==x5,"se encontro a %d",*(int*)encontrado);
	hash_destruir(tabla_1);
	hash_destruir(tabla_10);
}

void prueba_contiene(){
	hash_t* tabla_1=hash_crear(1);
	hash_t* tabla_10=hash_crear(10);	
	
	int a=10,v=23;
	
	pa2m_afirmar(hash_insertar(tabla_1,"hola",&a,NULL), "inseretado en tabla_1");
	
	pa2m_afirmar(hash_insertar(tabla_10,"ka",&v,NULL), "inseretado en tabla_10");

	
	int x1=11,x2=12,x3=13,x4=41,x5=51,x6=60;
	pa2m_afirmar(hash_insertar(tabla_10,"mala",&x1,NULL),"insertado %d en tabla_10",x1);
	pa2m_afirmar(hash_insertar(tabla_10,"masa",&x2,NULL),"insertado %d en tabla_10",x2);
	pa2m_afirmar(hash_insertar(tabla_10,"malo",&x3,NULL),"insertado %d en tabla_10",x3);
	pa2m_afirmar(hash_insertar(tabla_10,"mara",&x4,NULL),"insertado %d en tabla_10",x4);
	pa2m_afirmar(hash_insertar(tabla_10,"xala",&x5,NULL),"insertado %d en tabla_10",x5);
	pa2m_afirmar(hash_insertar(tabla_10,"mera",&x6,NULL),"insertado %d en tabla_10",x6);


	
	pa2m_afirmar(hash_contiene(tabla_10,"xala"),"existe %d en la tabla",x5);
	hash_destruir(tabla_1);
	hash_destruir(tabla_10);
}

void probar_con_NULL(){

	hash_t* mala_tabla=hash_crear(0);
	hash_t* buena_tabla=hash_crear(13);
	pa2m_afirmar(mala_tabla!=NULL,"tabla creada con NULL");
	pa2m_afirmar(hash_insertar(buena_tabla,"mala",NULL,NULL),"insertado NULL en tabla");
	pa2m_afirmar(!hash_insertar(buena_tabla,NULL,NULL,NULL),"insertado con clave NULL en tabla");
	pa2m_afirmar(!hash_insertar(NULL,"mala",NULL,NULL),"insertado con tabla NULL");
	pa2m_afirmar(hash_buscar(buena_tabla,NULL)==NULL,"buscar con clave NULL en tabla");
	pa2m_afirmar(hash_buscar(buena_tabla,NULL)==NULL,"buscar con clave NULL en tabla");
	pa2m_afirmar(hash_buscar(NULL,"mala")==NULL,"buscar en tabla NULL");
	pa2m_afirmar(!hash_contiene(NULL,"mala"),"contiene en tabla NULL");
	pa2m_afirmar(!hash_contiene(buena_tabla,NULL),"contiene NULL en tabla ");


	hash_destruir(mala_tabla);
	hash_destruir(buena_tabla);
}

int main()
{
	pa2m_nuevo_grupo("============== ??? ===============");
	prueba_crear();
	prueba_insertar();
	prueba_remplazar();
	prueba_buscar();
	prueba_contiene();
	probar_con_NULL();


	return pa2m_mostrar_reporte();
}
