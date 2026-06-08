# VII. Verdadero o Falso

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque sirve para consolidar teoría corta de PP2. En las afirmaciones falsas no basta escribir "F": hay que corregir la idea con lenguaje técnico.

## Índice para estudiar

Banco completo:

- [VII.1](#ejercicio-vii1) | [VII.2](#ejercicio-vii2) | [VII.3](#ejercicio-vii3) | [VII.4](#ejercicio-vii4) | [VII.5](#ejercicio-vii5)
- [VII.6](#ejercicio-vii6) | [VII.7](#ejercicio-vii7) | [VII.8](#ejercicio-vii8) | [VII.9](#ejercicio-vii9) | [VII.10](#ejercicio-vii10)
- [VII.11](#ejercicio-vii11) | [VII.12](#ejercicio-vii12) | [VII.13](#ejercicio-vii13) | [VII.14](#ejercicio-vii14) | [VII.15](#ejercicio-vii15)
- [VII.16](#ejercicio-vii16) | [VII.17](#ejercicio-vii17) | [VII.18](#ejercicio-vii18) | [VII.19](#ejercicio-vii19) | [VII.20](#ejercicio-vii20)

### Ejercicio VII.1

Un árbol es una estructura de datos no lineal que organiza sus datos jerárquicamente.

### Ejercicio VII.2

DFS se puede aplicar a grafos y a árboles; no es exclusivo de grafos.

### Ejercicio VII.3

En un ABB, el recorrido inorden entrega los valores en orden ascendente.

### Ejercicio VII.4

Un árbol AVL se balancea mediante factores de balance y rotaciones; no usa la misma regla que un heap.

### Ejercicio VII.5

Un heap mantiene un orden parcial entre padres e hijos, no un orden total como un ABB.

### Ejercicio VII.6

En una matriz de adyacencia, verificar si existe el arco `u -> v` cuesta `O(1)`.

### Ejercicio VII.7

Un grafo no dirigido puede tener vértices desconectados.

### Ejercicio VII.8

Un árbol binario lleno de profundidad `K` tiene `2^K - 1` nodos (si se define profundidad con la raíz en 1).

### Ejercicio VII.9

Un árbol completo no siempre es lleno.

### Ejercicio VII.10

Un vértice puede tener grado de entrada y grado de salida distintos en un grafo dirigido.

### Ejercicio VII.11

En un árbol enhebrado, algunos punteros que serían `nullptr` se reutilizan como hebras.

### Ejercicio VII.12

Un lazo en un grafo es una arista que conecta un vértice consigo mismo.

### Ejercicio VII.13

HeapSort no es estable porque puede invertir el orden relativo de elementos iguales.

### Ejercicio VII.14

En BFS se usa naturalmente una cola.

### Ejercicio VII.15

En DFS iterativo se usa naturalmente una pila.

### Ejercicio VII.16

Un ABB desbalanceado puede degradar sus búsquedas hasta `O(n)`.

### Ejercicio VII.17

Un AVL garantiza altura `O(log n)`.

### Ejercicio VII.18

Una lista de arcos no permite obtener todos los vecinos de un vértice en `O(1)` sin estructuras auxiliares.

### Ejercicio VII.19

Para que un grafo no dirigido y conexo sea árbol, debe no tener ciclos.

### Ejercicio VII.20

En un heap con indexación `0-based`, el hijo izquierdo de `i` está en `2*i + 1` y el derecho en `2*i + 2`.
