# X. Ejercicios Integradores Tipo Parcial Real

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque mezcla contenidos como en una PP2 real. La dificultad no esta solo en saber la estructura, sino en leer restricciones, respetar firmas, justificar complejidad y separar cuando el problema pide dibujar, programar o razonar.

## Como estudiar este bloque

Para cada ejercicio:

- subraye la estructura involucrada;
- identifique si el problema es de recorrido, busqueda, ordenamiento, balance o grafo;
- escriba primero la idea y la estructura auxiliar;
- termine con complejidad temporal y espacial.

## Índice

- [X.1](#ejercicio-x1) AVL + HeapSort + comparacion
- [X.2](#ejercicio-x2) reconstruccion con inorden/postorden
- [X.3](#ejercicio-x3) sumas en rango de un AVL
- [X.4](#ejercicio-x4) análisis de grafo por lista de arcos
- [X.5](#ejercicio-x5) grados de salida en grafo dirigido
- [X.6](#ejercicio-x6) ruta optima con compras
- [X.7](#ejercicio-x7) verificacion fuerte de AVL
- [X.8](#ejercicio-x8) flujo máximo

### Ejercicio X.1

Dado el arreglo:

```text
87, 65, 70, 67, 66, 100, 90, 101, 50, 40, 77, 30, 20
```

1. Inserte los valores en un AVL, mostrando rotaciones.
2. Elimine `90` y `65`, usando el menor de los mayores.
3. Con los mismos valores originales, ordene de menor a mayor usando HeapSort.
4. Compare AVL y HeapSort como estructuras/algoritmos.

### Ejercicio X.2

Implemente:

```cpp
Node* buildFromInPost(vector<int>& inorder, vector<int>& postorder);
```

Use:

```text
inorder   = [4, 2, 5, 1, 6, 3, 7]
postorder = [4, 5, 2, 6, 7, 3, 1]
```

Se pide:

1. construir el árbol;
2. escribir su preorden;
3. justificar por qué el ultimo elemento de postorden es la raíz.

### Ejercicio X.3

Dado un AVL y tres enteros `K1`, `K2`, `K3`, implemente:

```cpp
vector<int> calcularSumas(Node* root, int K1, int K2, int K3);
```

Debe retornar todas las sumas posibles de exactamente `K3` valores distintos dentro del rango `[K1, K2]`, ordenadas y sin repetidos.

Ejemplo conceptual:

```text
valores en rango = [2, 4, 8, 10]
K3 = 2
salida = [6, 10, 12, 14, 18]
```

### Ejercicio X.4

Un grafo no dirigido se entrega como lista de arcos:

```cpp
bool checkGraph(NodeLink* list, vector<char>& socialV, vector<char>& aloneV);
```

La función debe:

- detectar lazos;
- agregar vértices con grado al menos `3` en `socialV`;
- agregar vértices con grado `1` en `aloneV`.

Explique que representa el grado en un grafo no dirigido.

### Ejercicio X.5

Dado un grafo dirigido representado por lista de arcos:

```cpp
vector<int> outDegrees(EdgeNode* edges, int n);
```

Los vértices son `0..n-1`. La función debe retornar el grado de salida de cada vértice en tiempo `O(M + N)`.

### Ejercicio X.6

Un supermercado se modela como grafo ponderado no dirigido. La entrada es `A`, la caja es `Z` y hay una lista pequena de secciones obligatorias.

Implemente:

```cpp
int mejorRutaConCompras(vector<vector<pair<int, int>>>& adj,
                        int entrada, int caja,
                        vector<int> compras);
```

Puede asumir `compras.size() <= 10`.

### Ejercicio X.7

Dada la raíz de un árbol binario:

```cpp
bool isAvlMinimo(Node* root);
```

La función debe retornar `true` solo si:

1. cada nodo cumple la propiedad AVL;
2. la altura real del árbol coincide con `ceil(log2(n + 1))`.

Debe ejecutarse en una sola pasada sobre los nodos.

### Ejercicio X.8

Una red de tuberias se modela como grafo dirigido con capacidades. Implemente:

```cpp
int maxFlow(vector<vector<int>> capacity, int s, int t);
```

Debe usar la idea de caminos aumentantes.

