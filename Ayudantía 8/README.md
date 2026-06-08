# Ayudantía 8
## Contenido

- [Objetivo del bloque](#objetivo-del-bloque)
- [Repaso teorico breve](#repaso-teorico-breve)
- [Metodo general de insercion](#metodo-general-de-insercion)
- [Eliminacion en AVL](#eliminacion-en-avl)
- [Casos de rotacion](#casos-de-rotacion)
  - [1. LL](#1-ll)
  - [2. RR](#2-rr)
  - [3. LR](#3-lr)
  - [4. RL](#4-rl)
- [Ejemplos cortos](#ejemplos-cortos)
  - [Ejemplo 1](#ejemplo-1)
  - [Ejemplo 2](#ejemplo-2)
  - [Ejemplo 3](#ejemplo-3)
  - [Ejemplo 4](#ejemplo-4)
- [Ejercicios propuestos](#ejercicios-propuestos)
  - [Ejercicio 1](#ejercicio-1)
  - [Ejercicio 2](#ejercicio-2)
  - [Ejercicio 3](#ejercicio-3)
  - [Ejercicio 4](#ejercicio-4)


Esta ayudantía introduce los árboles AVL, que son árboles binarios de busqueda auto-balanceados. La idea central es mantener la altura controlada para que insertar, buscar y recorrer siga siendo eficiente.

## Objetivo del bloque

- entender que es un AVL y por qué balancea mejor que un BST comun;
- identificar el factor de balance de cada nodo;
- reconocer los cuatro casos de reacomodo: LL, RR, LR y RL;
- practicar inserciones paso a paso con vectores;
- leer el árbol resultante despues de cada insercion.

## Repaso teorico breve

Un AVL es un árbol binario de busqueda donde, para cada nodo, la diferencia entre la altura del subarbol izquierdo y el derecho nunca supera 1 en valor absoluto.

Se usa normalmente esta definicion del factor de balance:

```text
balance(node) = height(left) - height(right)
```

Un nodo esta equilibrado si su balance es `-1`, `0` o `1`.

Cuando una insercion rompe esa regla, el árbol se corrige con rotaciones locales. La insercion sigue siendo la de un BST normal, pero al volver desde la recursión se actualizan alturas y se repara el primer nodo desbalanceado.

## Metodo general de insercion

1. Insertar el valor como en un BST normal.
2. Actualizar alturas de los nodos en el camino de regreso.
3. Calcular el factor de balance.
4. Si hay desbalance, identificar el caso y aplicar la rotacion correspondiente.

## Eliminacion en AVL

La eliminacion en un AVL sigue la misma idea que en un BST comun, pero despues de borrar un nodo tambien se revisa el balance en el camino de regreso.

El proceso general es este:

1. Buscar el valor a eliminar.
2. Si el nodo tiene dos hijos, reemplazarlo por su sucesor inorden o su predecesor inorden.
3. Eliminar el nodo que quedo realmente desconectado.
4. Actualizar alturas mientras se vuelve hacia la raíz.
5. Calcular el factor de balance de cada nodo.
6. Si aparece un desbalance, aplicar la rotacion que corresponda.

En eliminacion pueden aparecer los mismos cuatro casos de reacomodo, pero el criterio se determina por el balance del nodo afectado y de su hijo. La diferencia clave con la insercion es que, despues de borrar, el desbalance puede propagarse más arriba, por lo que a veces hay que corregir más de un nodo en el camino.

Idea practica:

- si el nodo quedo cargado a la izquierda, se revisa su hijo izquierdo;
- si el nodo quedo cargado a la derecha, se revisa su hijo derecho;
- segun el balance del hijo, se decide entre rotacion simple o doble.

## Casos de rotacion

### 1. LL

El nodo se desbalancea hacia la izquierda y la insercion ocurrio en el hijo izquierdo del hijo izquierdo.

Rotacion usada: rotacion simple a la derecha.

```text
    30              20
   /               /  \
  20      ->      10   30
 /
10
```

### 2. RR

El nodo se desbalancea hacia la derecha y la insercion ocurrio en el hijo derecho del hijo derecho.

Rotacion usada: rotacion simple a la izquierda.

```text
10                  20
  \                /  \
   20     ->      10   30
     \
      30
```

### 3. LR

El nodo se desbalancea hacia la izquierda, pero la insercion ocurrio en el hijo derecho del hijo izquierdo.

Rotaciones usadas: primero izquierda en el hijo, luego derecha en el nodo.

```text
    30               30               20
   /                /                /  \
  10      ->       20      ->      10   30
    \             /
     20           10
```

### 4. RL

El nodo se desbalancea hacia la derecha, pero la insercion ocurrio en el hijo izquierdo del hijo derecho.

Rotaciones usadas: primero derecha en el hijo, luego izquierda en el nodo.

```text
10                  10                 20
  \                   \               /  \
   30      ->          20    ->      10   30
  /                      \
 20                       30
```

## Ejemplos cortos

### Ejemplo 1

Inserta `30, 20, 10` en ese orden.

Resultado esperado: aparece un caso `LL` y el árbol queda con `20` como raíz.

### Ejemplo 2

Inserta `10, 20, 30`.

Resultado esperado: aparece un caso `RR` y el árbol queda con `20` como raíz.

### Ejemplo 3

Inserta `30, 10, 20`.

Resultado esperado: aparece un caso `LR` y el árbol queda con `20` como raíz.

### Ejemplo 4

Inserta `10, 30, 20`.

Resultado esperado: aparece un caso `RL` y el árbol queda con `20` como raíz.

## Ejercicios propuestos

### Ejercicio 1

Inserta uno por uno los valores de la secuencia:

[30,20,10,25,27]

Tareas:

1. Dibujar el árbol despues de cada insercion.
2. Indicar en que paso aparece una rotacion.
3. Identificar si la rotacion fue `LL`, `RR`, `LR` o `RL`.
4. Mostrar el árbol final balanceado.

### Ejercicio 2

Inserta uno por uno los valores de la secuencia:

[10,20,30,40,50,25]

Tareas:

1. Registrar todas las alturas intermedias.
2. Indicar cada reacomodo realizado.
3. Explicar por qué el ultimo valor produce un cambio en la parte alta del árbol.

### Ejercicio 3

Inserta uno por uno los valores de la secuencia:

[50,30,70,20,40,60,80,10,25,65]

Tareas:

1. Comprobar si ocurre alguna rotacion.
2. Justificar por qué el árbol se mantiene equilibrado o donde deja de hacerlo.
3. Comparar la altura final con la de un BST comun.

### Ejercicio 4

Inserta uno por uno los valores de la secuencia:

[15,10,20,8,12,17,25,19,18]

Tareas:

1. Dibujar el árbol final.
2. Indicar la ultima rotacion necesaria para restaurar el balance.
3. Marcar los factores de balance de los nodos afectados.

Luego, elimina uno por uno los valores de la secuencia:

[12,20,15]

Tareas:

1. Dibujar el árbol despues de cada eliminacion.
2. Indicar si aparece un desbalance y que rotacion se usa para corregirlo.
3. Comparar el árbol resultante con el que se obtiene solo con inserciones.
