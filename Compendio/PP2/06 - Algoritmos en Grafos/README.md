# VI. Algoritmos en Grafos

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque usa firmas y modelos parecidos a pruebas recientes: lista de arcos, grados de entrada/salida, vértices con grado mínimo, lazos, caminos posibles, flujo máximo y caminos optimos en grafos ponderados.

## Índice para estudiar

Primera pasada sugerida:

- [VI.1](#ejercicio-vi1) | [VI.2](#ejercicio-vi2) | [VI.3](#ejercicio-vi3) | [VI.4](#ejercicio-vi4)

Segunda pasada sugerida:

- [VI.5](#ejercicio-vi5) | [VI.6](#ejercicio-vi6) | [VI.7](#ejercicio-vi7) | [VI.8](#ejercicio-vi8)

## Estructuras base

```cpp
class Node {
public:
    int id;
    Node(int id) : id(id) {}
};

class EdgeNode {
public:
    Node* source;
    Node* destination;
    EdgeNode* next;

    EdgeNode(Node* source, Node* destination)
        : source(source), destination(destination), next(nullptr) {}
};
```

### Ejercicio VI.1

Dado un grafo dirigido representado por lista de arcos, implemente:

```cpp
vector<int> outDegrees(EdgeNode* edges, int n);
```

Los vértices tienen ids `0..n-1`. La función debe retornar el grado de salida de cada vértice.

### Ejercicio VI.2

Para un grafo no dirigido representado por lista de arcos:

```cpp
class CharNode {
public:
    char id;
    CharNode(char id) : id(id) {}
};

class NodeLink {
public:
    CharNode* src;
    CharNode* dest;
    NodeLink* next;
};
```

Implemente:

```cpp
bool checkGraph(NodeLink* list, vector<char>& socialV, vector<char>& aloneV);
```

Debe:

- agregar a `socialV` los vértices con grado al menos `3`;
- agregar a `aloneV` los vértices con grado `1`;
- retornar `false` si existe un lazo, es decir, un vértice conectado consigo mismo.

### Ejercicio VI.3

Dada una matriz de adyacencia de un grafo dirigido:

```cpp
vector<vector<int>> matrix;
```

Implemente:

```cpp
int inDegreeMatrix(vector<vector<int>>& matrix, int v);
int outDegreeMatrix(vector<vector<int>>& matrix, int v);
```

### Ejercicio VI.4

Implemente Dijkstra para pesos no negativos:

```cpp
vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src);
```

Cada par representa `{vecino, peso}`.

### Ejercicio VI.5

Una empresa de entregas quiere listar todos los caminos simples desde `src` hasta `dst`.

Implemente:

```cpp
vector<vector<int>> allSimplePaths(vector<vector<int>>& adj, int src, int dst);
```

### Ejercicio VI.6

Implemente flujo máximo usando Edmonds-Karp:

```cpp
int maxFlow(vector<vector<int>> capacity, int s, int t);
```

### Ejercicio VI.7

Suponga un supermercado modelado como grafo ponderado no dirigido. Implemente una función que calcule el costo mínimo desde entrada `A` hasta caja `Z`, pasando por una lista pequena de secciones obligatorias:

```cpp
int mejorRutaConCompras(vector<vector<pair<int, int>>>& adj,
                        int entrada, int caja,
                        vector<int> compras);
```

Puede asumir que `compras.size() <= 10`.

### Ejercicio VI.8

Explique las diferencias entre:

1. lista de arcos;
2. lista de adyacencia;
3. matriz de adyacencia.

Indique en que casos conviene cada una.

