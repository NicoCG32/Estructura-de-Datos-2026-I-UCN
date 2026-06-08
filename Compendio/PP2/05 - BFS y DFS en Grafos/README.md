# V. BFS y DFS en Grafos

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque trabaja la diferencia entre recorrido en profundidad y recorrido en amplitud. En árboles tambien se puede usar DFS/BFS, pero en grafos aparece una condicion adicional: hay que controlar vértices visitados para no repetir ciclos.

## Índice para estudiar

Primera pasada sugerida:

- [V.1](#ejercicio-v1) | [V.2](#ejercicio-v2) | [V.3](#ejercicio-v3) | [V.6](#ejercicio-v6)

Segunda pasada sugerida:

- [V.4](#ejercicio-v4) | [V.5](#ejercicio-v5) | [V.7](#ejercicio-v7) | [V.8](#ejercicio-v8)

## Convencion

Cuando haya que elegir entre varios vecinos, se visitan en orden alfabetico o numerico ascendente.

### Ejercicio V.1

Considere el grafo dirigido:

```text
A -> B, C
B -> D
C -> D, E
D -> F
E -> F
F -> -
```

Indique:

1. BFS desde `A`;
2. DFS desde `A`;
3. si existe camino desde `C` hasta `F`;
4. si existe camino desde `E` hasta `B`.

### Ejercicio V.2

Implemente:

```cpp
vector<int> bfsTraversal(vector<vector<int>>& adj, int start);
```

El grafo esta representado por lista de adyacencia con vértices `0..n-1`.

### Ejercicio V.3

Implemente DFS iterativo:

```cpp
vector<int> dfsIterTraversal(vector<vector<int>>& adj, int start);
```

Debe usar `stack<int>`.

### Ejercicio V.4

Implemente:

```cpp
bool pathExists(vector<vector<int>>& adj, int src, int dst);
```

Puede usar BFS o DFS, pero debe justificar la estructura elegida.

### Ejercicio V.5

Implemente:

```cpp
int countComponents(vector<vector<int>>& adj);
```

El grafo es no dirigido. Debe retornar la cantidad de componentes conexas.

### Ejercicio V.6

Implemente:

```cpp
int shortestDistanceUnweighted(vector<vector<int>>& adj, int src, int dst);
```

Debe retornar la cantidad minima de arcos entre `src` y `dst`. Si no existe camino, retorne `-1`.

### Ejercicio V.7

Explique por qué BFS es adecuado para distancia minima en grafos no ponderados y por qué DFS no garantiza distancia minima.

### Ejercicio V.8

Responda:

1. Por qué un árbol puede verse como un grafo particular?
2. Que condicion debe cumplir un grafo no dirigido y conexo para ser árbol?
3. Que significa que un vértice este visitado?
4. Que error aparece si no se marca visitado en un grafo con ciclos?

