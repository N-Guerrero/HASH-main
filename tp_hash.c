#include "src/hash.h"
#include "src/csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct pokemon {
	char *nombre;
	char tipo;
	int fuerza;
	int destreza;
	int resistencia;
};
bool leer_int(const char *str, void *ctx)
{
	return sscanf(str, "%d", (int *)ctx) == 1;
}

bool leer_caracter(const char *str, void *ctx)
{
	*(char *)ctx = *(char *)str;
	return true;
}
bool crear_string_nuevo(const char *str, void *ctx)
{
	char *nuevo = malloc(strlen(str) + 1);
	if (nuevo == NULL)
		return false;
	strcpy(nuevo, str);
	*(char **)ctx = nuevo;
	return true;
}

void liberar_pokemon(void *pokemon)
{
	struct pokemon *liberado = pokemon;
	if (liberado != NULL) {
		free(liberado->nombre);
		free(liberado);
		liberado = NULL;
	}
}
void agregar_pokemon_desde_archivo(hash_t *pokedex, struct archivo_csv *archivo)
{
	bool (*funciones[5])(const char *, void *) = { crear_string_nuevo,
						       leer_caracter, leer_int,
						       leer_int, leer_int };

	int fuerza;
	int resistencia;
	int destreza;
	char tipo;
	char *nombre = NULL;
	void *punteros[5] = { &nombre, &tipo, &fuerza, &destreza,
			      &resistencia };

	while (leer_linea_csv(archivo, 5, funciones, punteros) == 5) {
		struct pokemon *nuevo_pokemon = malloc(sizeof(struct pokemon));
		nuevo_pokemon->nombre = nombre;
		nuevo_pokemon->fuerza = fuerza;
		nuevo_pokemon->destreza = destreza;
		nuevo_pokemon->tipo = tipo;
		nuevo_pokemon->resistencia = resistencia;

		if (hash_insertar(pokedex, nombre, nuevo_pokemon, NULL))
			printf("%s capturado\n", nuevo_pokemon->nombre);
	}
	cerrar_archivo_csv(archivo);
}
void mostrar_pokemon(struct pokemon *pokemon)
{
	printf("Nombre: %s\nTipo: %c\nFuerza:%d\nDestreza:%d\nResistencia:%d\n",
	       pokemon->nombre, pokemon->tipo, pokemon->fuerza,
	       pokemon->destreza, pokemon->resistencia);
}
bool listar_pokemon(char *clave, void *pokemon, void *ctx)
{
	struct pokemon *pokemon_actual = (struct pokemon *)pokemon;
	int *indice = (int *)ctx;
	if (pokemon_actual == NULL) {
		printf("pokemon NULL\n");
		return false;
	}
	printf("%d. clave: %s valor:%s\n", *indice, pokemon_actual->nombre,
	       clave);
	(*indice)++;
	return true;
}

int main(int argc, char *argv[])
{
	hash_t *hash = hash_crear(5);

	struct archivo_csv *archivo = abrir_archivo_csv(argv[1], ';');

	if (archivo != NULL)
		agregar_pokemon_desde_archivo(hash, archivo);

	int opcion = -1;
	do {
		printf("Pokedex iniciada.\nQue desea hacer?\n");
		printf("1.Buscar pokemon en la pokedex\n2.Listar pokemones capturados\n");
		printf("0.salir\n");
		if (scanf("%d", &opcion) != 1)
			printf("opcion invalida\n");
		if (opcion == 1) {
			printf("que pokemon desea buscar?\n");
			char pokemon_buscado[MAX];
			int correcto = scanf("%99s", pokemon_buscado);
			if (correcto == 0)
				continue;

			char *clave = malloc(strlen(pokemon_buscado) + 1);
			if (clave == NULL)
				return -1;
			strcpy(clave, pokemon_buscado);
			struct pokemon *encontrado = hash_buscar(hash, clave);

			if (encontrado != NULL) {
				printf("Se encontro al pokemon buscado!!\n");
				mostrar_pokemon(encontrado);
			} else {
				printf("pokemon no encontrado\n");
			}
			free(clave);
			opcion = 0;
		}
		if (opcion == 2) {
			size_t cant_pokemons = hash_cantidad(hash);
			int indice = 1;
			if (hash_iterar(hash, listar_pokemon, &indice) ==
			    cant_pokemons) {
				printf("Fin de Pokedex\n");
			}
			opcion = 0;
		}
	} while (opcion != 0);

	hash_destruir_todo(hash, liberar_pokemon);

	return 0;
}