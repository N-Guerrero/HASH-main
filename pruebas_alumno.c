#include "pa2m.h"
#include "src/hash.h"

void prueba_crear()
{
	hash_t *tabla_1 = hash_crear(1);
	hash_t *tabla_4 = hash_crear(4);

	pa2m_afirmar(tabla_1 != NULL, "tabla_1 existe");
	pa2m_afirmar(tabla_4 != NULL, "tabla_4 existe");
	hash_destruir(tabla_1);
	hash_destruir(tabla_4);
}
void prueba_insertar()
{
	hash_t *tabla_1 = hash_crear(1);
	hash_t *tabla_4 = hash_crear(4);

	int a = 10, v = 23;

	pa2m_afirmar(
		hash_insertar(tabla_1,
			      "holacskoajcoaneincaiosclaxcmnoasihiucadslkcnsoj",
			      &a, NULL),
		"inseretado en tabla_1");

	pa2m_afirmar(hash_insertar(tabla_4, "ha", &v, NULL),
		     "inseretado en tabla_4");

	hash_destruir(tabla_1);
	hash_destruir(tabla_4);
}
void prueba_remplazar()
{
	hash_t *tabla_1 = hash_crear(1);
	hash_t *tabla_4 = hash_crear(4);

	int a = 10, v = 23, b = 40;

	pa2m_afirmar(hash_insertar(tabla_1, "hola", &a, NULL),
		     "inseretado %d en tabla_1", a);

	pa2m_afirmar(hash_insertar(tabla_4, "hala", &v, NULL),
		     "inseretado %d en tabla_4", v);

	void *anterior = NULL;
	pa2m_afirmar(hash_insertar(tabla_1, "hola", &b, &anterior),
		     "inseretado %d en tabla_1", b);

	pa2m_afirmar(anterior != NULL, "se remplazo a %d", *(int *)anterior);

	hash_destruir(tabla_1);
	hash_destruir(tabla_4);
}

void prueba_buscar()
{
	hash_t *tabla_1 = hash_crear(1);
	hash_t *tabla_10 = hash_crear(10);

	int a = 10, v = 23;

	pa2m_afirmar(hash_insertar(tabla_1, "hola", &a, NULL),
		     "inseretado en tabla_1");

	pa2m_afirmar(hash_insertar(tabla_10, "ka", &v, NULL),
		     "inseretado en tabla_10");

	int x1 = 11, x2 = 12, x3 = 13, x4 = 41, x5 = 51, x6 = 60;
	pa2m_afirmar(hash_insertar(tabla_10, "mala", &x1, NULL),
		     "insertado %d en tabla_10", x1);
	pa2m_afirmar(hash_insertar(tabla_10, "masa", &x2, NULL),
		     "insertado %d en tabla_10", x2);
	pa2m_afirmar(hash_insertar(tabla_10, "malo", &x3, NULL),
		     "insertado %d en tabla_10", x3);
	pa2m_afirmar(hash_insertar(tabla_10, "mara", &x4, NULL),
		     "insertado %d en tabla_10", x4);
	pa2m_afirmar(hash_insertar(tabla_10, "xala", &x5, NULL),
		     "insertado %d en tabla_10", x5);
	pa2m_afirmar(hash_insertar(tabla_10, "mera", &x6, NULL),
		     "insertado %d en tabla_10", x6);

	void *encontrado = hash_buscar(tabla_10, "xala");
	pa2m_afirmar(*(int *)encontrado == x5, "se encontro a %d",
		     *(int *)encontrado);
	hash_destruir(tabla_1);
	hash_destruir(tabla_10);
}

void prueba_contiene()
{
	hash_t *tabla_1 = hash_crear(1);
	hash_t *tabla_10 = hash_crear(10);

	int a = 10, v = 23;

	pa2m_afirmar(hash_insertar(tabla_1, "hola", &a, NULL),
		     "inseretado en tabla_1");

	pa2m_afirmar(hash_insertar(tabla_10, "ka", &v, NULL),
		     "inseretado en tabla_10");

	int x1 = 11, x2 = 12, x3 = 13, x4 = 41, x5 = 51, x6 = 60;
	pa2m_afirmar(hash_insertar(tabla_10, "mala", &x1, NULL),
		     "insertado %d en tabla_10", x1);
	pa2m_afirmar(hash_insertar(tabla_10, "masa", &x2, NULL),
		     "insertado %d en tabla_10", x2);
	pa2m_afirmar(hash_insertar(tabla_10, "malo", &x3, NULL),
		     "insertado %d en tabla_10", x3);
	pa2m_afirmar(hash_insertar(tabla_10, "mara", &x4, NULL),
		     "insertado %d en tabla_10", x4);
	pa2m_afirmar(hash_insertar(tabla_10, "xala", &x5, NULL),
		     "insertado %d en tabla_10", x5);
	pa2m_afirmar(hash_insertar(tabla_10, "mera", &x6, NULL),
		     "insertado %d en tabla_10", x6);

	pa2m_afirmar(hash_contiene(tabla_10, "xala"), "existe %d en la tabla",
		     x5);
	hash_destruir(tabla_1);
	hash_destruir(tabla_10);
}

bool mostrar(char *clave, void *valor, void *ctx)
{
	int *valor_ = valor;
	printf("valor: %d con clave: %s\n", *valor_, clave);
	return true;
}
bool mostrar_3(char *clave, void *valor, void *ctx)
{
	int *corte = ctx;
	if (*corte == 3)
		return false;
	int *valor_ = valor;
	printf("valor: %d con clave: %s\n", *valor_, clave);
	(*corte)++;
	return true;
}
bool mostrar_5(char *clave, void *valor, void *ctx)
{
	int *corte = ctx;
	if (*corte == 5)
		return false;
	int *valor_ = valor;
	printf("valor: %d con clave: %s\n", *valor_, clave);
	(*corte)++;
	return true;
}
void probar_con_NULL()
{
	hash_t *mala_tabla = hash_crear(0);
	hash_t *buena_tabla = hash_crear(13);
	pa2m_afirmar(mala_tabla != NULL, "tabla creada con NULL");
	pa2m_afirmar(hash_insertar(buena_tabla, "mala", NULL, NULL),
		     "insertado NULL en tabla");
	pa2m_afirmar(!hash_insertar(buena_tabla, NULL, NULL, NULL),
		     "insertado con clave NULL en tabla");
	pa2m_afirmar(!hash_insertar(NULL, "mala", NULL, NULL),
		     "insertado con tabla NULL");
	pa2m_afirmar(hash_buscar(buena_tabla, NULL) == NULL,
		     "buscar con clave NULL en tabla");
	pa2m_afirmar(hash_buscar(buena_tabla, NULL) == NULL,
		     "buscar con clave NULL en tabla");
	pa2m_afirmar(hash_buscar(NULL, "mala") == NULL, "buscar en tabla NULL");
	pa2m_afirmar(!hash_contiene(NULL, "mala"), "contiene en tabla NULL");
	pa2m_afirmar(!hash_contiene(buena_tabla, NULL),
		     "contiene NULL en tabla ");
	pa2m_afirmar(hash_quitar(NULL, "mala") == NULL, "quitar en tabla NULL");
	pa2m_afirmar(hash_quitar(buena_tabla, NULL) == NULL,
		     "quitar NULL en tabla");
	pa2m_afirmar(hash_iterar(buena_tabla, NULL, NULL) == 0,
		     "iterar con f NULL");
	pa2m_afirmar(hash_iterar(NULL, mostrar, NULL) == 0,
		     "iterar con tabla NULL");

	hash_destruir(mala_tabla);
	hash_destruir(buena_tabla);
}

void probar_quitar()
{
	hash_t *tabla_10 = hash_crear(10);

	int v = 23;

	pa2m_afirmar(hash_insertar(tabla_10, "ka", &v, NULL),
		     "inseretado en tabla_10");

	int x1 = 11, x2 = 12, x3 = 13, x4 = 41, x5 = 51, x6 = 60;
	hash_insertar(tabla_10, "mala", &x1, NULL);
	hash_insertar(tabla_10, "masa", &x2, NULL);
	hash_insertar(tabla_10, "malo", &x3, NULL);
	hash_insertar(tabla_10, "mara", &x4, NULL);
	hash_insertar(tabla_10, "xala", &x5, NULL);
	hash_insertar(tabla_10, "mera", &x6, NULL);

	void *quitado = hash_quitar(tabla_10, "xala");

	pa2m_afirmar(*(int *)quitado == x5, "quitado %d de la tabla",
		     *(int *)quitado);

	hash_destruir(tabla_10);
}
void probar_iterar()
{
	hash_t *tabla_10 = hash_crear(10);

	int v = 23;

	pa2m_afirmar(hash_insertar(tabla_10, "ka", &v, NULL),
		     "inseretado en tabla_10");

	int x1 = 11, x2 = 12, x3 = 13, x4 = 41, x5 = 51, x6 = 60;
	hash_insertar(tabla_10, "mala", &x1, NULL);
	hash_insertar(tabla_10, "masa", &x2, NULL);
	hash_insertar(tabla_10, "malo", &x3, NULL);
	hash_insertar(tabla_10, "mara", &x4, NULL);
	hash_insertar(tabla_10, "xala", &x5, NULL);
	hash_insertar(tabla_10, "mera", &x6, NULL);

	pa2m_afirmar(hash_iterar(tabla_10, mostrar, NULL) ==
			     hash_cantidad(tabla_10),
		     "se iteraron %zu elementos", hash_cantidad(tabla_10));

	hash_destruir(tabla_10);
}
void probar_iterar_x_veces()
{
	hash_t *tabla_10 = hash_crear(10);

	int v = 23;

	hash_insertar(tabla_10, "ka", &v, NULL);

	int x1 = 11, x2 = 12, x3 = 13, x4 = 41, x5 = 51, x6 = 60;
	hash_insertar(tabla_10, "mala", &x1, NULL);
	hash_insertar(tabla_10, "masa", &x2, NULL);
	hash_insertar(tabla_10, "malo", &x3, NULL);
	hash_insertar(tabla_10, "mara", &x4, NULL);
	hash_insertar(tabla_10, "xala", &x5, NULL);
	hash_insertar(tabla_10, "mera", &x6, NULL);
	int check = 0;
	int check5 = 0;
	size_t iterar_3 = hash_iterar(tabla_10, mostrar_3, &check);
	pa2m_afirmar(iterar_3 == 4, "se iteraron %zu elementos, check=%d ",
		     iterar_3, check);

	size_t iterar_5 = hash_iterar(tabla_10, mostrar_5, &check5);
	pa2m_afirmar(iterar_5 == 6, "se iteraron %zu elementos,cheack=%d",
		     iterar_5, check5);

	hash_destruir(tabla_10);
}
void probar_cantidad_modificar()
{
	hash_t *tabla_1 = hash_crear(1);

	int a = 10, b = 40;

	pa2m_afirmar(hash_insertar(tabla_1, "hola", &a, NULL),
		     "inseretado %d en tabla_1", a);

	pa2m_afirmar(hash_cantidad(tabla_1) == 1, "cantidad elementos 1");
	void *anterior = NULL;
	pa2m_afirmar(hash_insertar(tabla_1, "hola", &b, &anterior),
		     "inseretado %d en tabla_1", b);
	pa2m_afirmar(hash_cantidad(tabla_1) == 1, "cantidad elementos 1");

	pa2m_afirmar(anterior != NULL, "se remplazo a %d", *(int *)anterior);

	hash_destruir(tabla_1);
}
void probar_muchas_inserciones()
{
	hash_t *tabla_10 = hash_crear(10);
	bool insertados = false;
	for (int i = 0; i < 10000; i++) {
		// Generar una clave única basada en el número
		char clave[16];
		snprintf(clave, sizeof(clave), "%d", i);
		int valor = i;
		void *encontrado = NULL;
		insertados =
			hash_insertar(tabla_10, clave, &valor, &encontrado);
	}
	pa2m_afirmar(insertados, "se insertaron 1000 claves");
	pa2m_afirmar(hash_cantidad(tabla_10) == 10000, "cantidad 1000");

	for (int i = 0; i < 2500; i++) {
		// Generar una clave única basada en el número
		char clave[16];
		snprintf(clave, sizeof(clave), "%d", i);

		hash_quitar(tabla_10, clave);
	}
	printf("quitados\n");
	pa2m_afirmar(hash_cantidad(tabla_10) == 7500, "cantidad %zu",
		     hash_cantidad(tabla_10));

	bool inserta2 = false;
	for (int i = 0; i < 10000; i++) {
		// Generar una clave única basada en el número
		char clave2[16];
		snprintf(clave2, sizeof(clave2), "%d", i);
		int valor2 = i;
		void *encontrado2 = NULL;
		inserta2 =
			hash_insertar(tabla_10, clave2, &valor2, &encontrado2);
	}
	pa2m_afirmar(inserta2, "se insertaron las claves");
	pa2m_afirmar(hash_cantidad(tabla_10) == 10000, "cantidad %zu",
		     hash_cantidad(tabla_10));
	hash_destruir(tabla_10);
}

void probar_insertar_quitar()
{
	hash_t *tabla_1 = hash_crear(1);

	int a = 10, b = 40;

	pa2m_afirmar(hash_insertar(tabla_1, "hola", &a, NULL),
		     "inseretado %d en tabla_1", a);

	pa2m_afirmar(hash_cantidad(tabla_1) == 1, "cantidad elementos 1");
	void *anterior = NULL;
	pa2m_afirmar(hash_insertar(tabla_1, "hola", &b, &anterior),
		     "inseretado %d en tabla_1", b);
	void *quitar = hash_quitar(tabla_1, "hola");
	pa2m_afirmar(*(int *)quitar == b, "elemento quitado es %d, correcto",
		     *(int *)quitar);
	pa2m_afirmar(hash_insertar(tabla_1, "hola", &b, &anterior),
		     "inseretado %d en tabla_1", b);
	pa2m_afirmar(anterior == NULL, "elemento modificado es NULL ");
	hash_destruir(tabla_1);
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
	probar_quitar();
	probar_iterar();
	pa2m_nuevo_grupo("============== ??? ===============");
	probar_cantidad_modificar();
	probar_insertar_quitar();
	pa2m_nuevo_grupo("============== ??? ===============");
	probar_iterar_x_veces();
	probar_muchas_inserciones();

	return pa2m_mostrar_reporte();
}
