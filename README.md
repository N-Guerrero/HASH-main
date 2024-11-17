<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA HASH

## Repositorio de Nicolas Martin Guerrero - 112514 - guerreronico81@gmail.com
- Para compilar:

```bash
gcc *.c src/*.c
```

- Para ejecutar:

```bash
./a.out pokedex.csv
```

- Para ejecutar con valgrind:
```bash
valgrind ./a.out pokedex.csv
```
---
##  Funcionamiento

Para realizar este diccionario utilice 2 estructuras, una del hash y otra de nodos. El hash guarda la cantidad de elementos, la capacidad maxima del hash y un puntero a un vector de nodos


Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluir **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).

### Por ejemplo:

El programa funciona abriendo el archivo pasado como parámetro y leyendolo línea por línea. Por cada línea crea un registro e intenta agregarlo al vector. La función de lectura intenta leer todo el archivo o hasta encontrar el primer error. Devuelve un vector con todos los registros creados.

<div align="center">
<img width="70%" src="img/diagrama1.svg">
</div>

En el archivo `sarasa.c` la función `funcion1` utiliza `realloc` para agrandar la zona de memoria utilizada para conquistar el mundo. El resultado de `realloc` lo guardo en una variable auxiliar para no perder el puntero original en caso de error:

```c
int *vector = realloc(vector_original, (n+1)*sizeof(int));

if(vector == NULL)
    return -1;
vector_original = vector;
```


<div align="center">
<img width="70%" src="img/diagrama2.svg">
</div>

Explicá teóricamente los siguientes puntos (no necesariamente en orden, pero por favor usando diagramas):

Qué es un diccionario - Explicá 3 formas diferentes de implementar un diccionario (tabla de hash cuenta como 1)
Qué es una función de hash y qué características debe tener para nuestro problema en particular
Qué es una tabla de Hash y los diferentes métodos de resolución de colisiones vistos (encadenamiento, probing, etc)
Explique por qué es importante el tamaño de la tabla (tanto para tablas abiertas como cerradas)
Dado que en una tabla abierta se pueden encadenar colisiones sin importar el tamaño de la tabla, ¿Realmente importa el tamaño?
Mas te vale que expliques con dibujos
---

## Respuestas a las preguntas teóricas
Incluír acá las respuestas a las preguntas del enunciado (si aplica).
