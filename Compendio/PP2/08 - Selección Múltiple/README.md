# VIII. Seleccion Multiple
## Contenido

- [Banco completo](#banco-completo)
  - [Ejercicio VIII.1](#ejercicio-viii1)
  - [Ejercicio VIII.2](#ejercicio-viii2)
  - [Ejercicio VIII.3](#ejercicio-viii3)
  - [Ejercicio VIII.4](#ejercicio-viii4)
  - [Ejercicio VIII.5](#ejercicio-viii5)
  - [Ejercicio VIII.6](#ejercicio-viii6)
  - [Ejercicio VIII.7](#ejercicio-viii7)
  - [Ejercicio VIII.8](#ejercicio-viii8)
  - [Ejercicio VIII.9](#ejercicio-viii9)
  - [Ejercicio VIII.10](#ejercicio-viii10)
  - [Ejercicio VIII.11](#ejercicio-viii11)
  - [Ejercicio VIII.12](#ejercicio-viii12)
  - [Ejercicio VIII.13](#ejercicio-viii13)
  - [Ejercicio VIII.14](#ejercicio-viii14)
  - [Ejercicio VIII.15](#ejercicio-viii15)
  - [Ejercicio VIII.16](#ejercicio-viii16)
  - [Ejercicio VIII.17](#ejercicio-viii17)
  - [Ejercicio VIII.18](#ejercicio-viii18)
  - [Ejercicio VIII.19](#ejercicio-viii19)
  - [Ejercicio VIII.20](#ejercicio-viii20)


La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque mezcla teoría de árboles, heaps, AVL y grafos. La meta es justificar la alternativa correcta, no memorizar letras.

## Banco completo

- [VIII.1](#ejercicio-viii1) | [VIII.2](#ejercicio-viii2) | [VIII.3](#ejercicio-viii3) | [VIII.4](#ejercicio-viii4) | [VIII.5](#ejercicio-viii5)
- [VIII.6](#ejercicio-viii6) | [VIII.7](#ejercicio-viii7) | [VIII.8](#ejercicio-viii8) | [VIII.9](#ejercicio-viii9) | [VIII.10](#ejercicio-viii10)
- [VIII.11](#ejercicio-viii11) | [VIII.12](#ejercicio-viii12) | [VIII.13](#ejercicio-viii13) | [VIII.14](#ejercicio-viii14) | [VIII.15](#ejercicio-viii15)
- [VIII.16](#ejercicio-viii16) | [VIII.17](#ejercicio-viii17) | [VIII.18](#ejercicio-viii18) | [VIII.19](#ejercicio-viii19) | [VIII.20](#ejercicio-viii20)

### Ejercicio VIII.1

Que recorrido permite imprimir de menor a mayor los valores de un ABB?

A. Preorden  
B. Inorden  
C. Postorden  
D. BFS  
E. DFS arbitrario

### Ejercicio VIII.2

En un grafo dirigido, el grado de entrada de un vértice es:

A. cantidad de arcos que salen del vértice  
B. cantidad de arcos que entran al vértice  
C. suma de pesos incidentes  
D. cantidad total de vértices  
E. cantidad de componentes

### Ejercicio VIII.3

Consultar si existe un arco `u -> v` en matriz de adyacencia cuesta:

A. `O(1)`  
B. `O(log n)`  
C. `O(n)`  
D. `O(n log n)`  
E. `O(n^2)`

### Ejercicio VIII.4

Un árbol isomorfo respecto a otro es aquel que:

A. tiene los mismos valores y distinta forma  
B. tiene la misma forma, no necesariamente los mismos valores  
C. tiene todos los niveles llenos  
D. es un heap  
E. es un ABB balanceado

### Ejercicio VIII.5

Para convertir un grafo no dirigido y conexo en árbol, se debe asegurar principalmente que:

A. no tenga ciclos  
B. todos los vértices tengan peso  
C. cada nodo tenga dos hijos  
D. sea dirigido  
E. use matriz de adyacencia

### Ejercicio VIII.6

En un heap con indexacion `0-based`, el hijo derecho de `i` esta en:

A. `2i`  
B. `2i + 1`  
C. `2i + 2`  
D. `i / 2`  
E. `(i - 1) / 2`

### Ejercicio VIII.7

Que estructura se usa naturalmente en BFS?

A. `stack`  
B. `queue`  
C. `priority_queue` siempre  
D. `set`  
E. `map`

### Ejercicio VIII.8

Que estructura se usa naturalmente en DFS iterativo?

A. `queue`  
B. `stack`  
C. `pair`  
D. `heap`  
E. `matrix`

### Ejercicio VIII.9

En un AVL, un caso `LR` se corrige con:

A. derecha en raíz solamente  
B. izquierda en raíz solamente  
C. izquierda en hijo izquierdo y luego derecha en raíz  
D. derecha en hijo derecho y luego izquierda en raíz  
E. no requiere rotacion

### Ejercicio VIII.10

Buscar un valor arbitrario en un heap cuesta:

A. `O(1)`  
B. `O(log n)` siempre  
C. `O(n)`  
D. `O(n log n)`  
E. `O(n^2)`

### Ejercicio VIII.11

La altura de un AVL es:

A. `O(1)`  
B. `O(log n)`  
C. `O(n)`  
D. `O(n log n)`  
E. `O(n^2)`

### Ejercicio VIII.12

HeapSort de menor a mayor normalmente usa:

A. min-heap  
B. max-heap  
C. ABB  
D. AVL  
E. grafo dirigido

### Ejercicio VIII.13

Una lista de adyacencia es especialmente conveniente cuando:

A. el grafo es disperso y se recorren vecinos  
B. el grafo tiene todos los arcos posibles  
C. se necesita consultar cualquier arco en `O(1)`  
D. no hay vértices  
E. solo existen árboles

### Ejercicio VIII.14

Un árbol binario completo se caracteriza porque:

A. todos los niveles están llenos siempre  
B. las hojas del ultimo nivel se ubican lo más a la izquierda posible  
C. todos los nodos tienen dos hijos  
D. siempre es AVL  
E. siempre es heap

### Ejercicio VIII.15

En un árbol enhebrado inorden, una hebra derecha de un nodo suele apuntar a:

A. su padre  
B. su raíz  
C. su sucesor inorden  
D. su hijo izquierdo  
E. un nodo aleatorio

### Ejercicio VIII.16

Dijkstra requiere:

A. pesos negativos  
B. pesos no negativos  
C. grafo sin aristas  
D. solo grafos completos  
E. solo árboles

### Ejercicio VIII.17

Edmonds-Karp se usa para:

A. ordenar heaps  
B. reconstruir árboles  
C. calcular flujo máximo  
D. balancear AVL  
E. hacer inorden

### Ejercicio VIII.18

Si un ABB queda completamente desbalanceado, buscar puede costar:

A. `O(1)`  
B. `O(log n)`  
C. `O(n)`  
D. `O(n log n)`  
E. `O(n^2)`

### Ejercicio VIII.19

En un grafo no ponderado, la distancia minima por cantidad de arcos se obtiene naturalmente con:

A. DFS  
B. BFS  
C. HeapSort  
D. rotaciones AVL  
E. recorrido inorden

### Ejercicio VIII.20

La propiedad principal de un max-heap es:

A. todo subarbol izquierdo es menor que la raíz y todo derecho mayor  
B. cada padre es mayor o igual que sus hijos  
C. todo nodo tiene exactamente dos hijos  
D. el inorden entrega valores ordenados  
E. no se puede representar en arreglo

