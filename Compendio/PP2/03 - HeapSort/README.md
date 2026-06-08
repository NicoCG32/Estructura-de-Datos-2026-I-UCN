# III. HeapSort

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque entrena los ejercicios de monticulos y HeapSort que aparecen con frecuencia en PP2. El objetivo es leer el heap como arreglo, aplicar `heapify` correctamente y distinguir entre heap como estructura y HeapSort como algoritmo de ordenamiento.

## Índice para estudiar

Primera pasada sugerida:

- [III.1](#ejercicio-iii1) | [III.2](#ejercicio-iii2) | [III.3](#ejercicio-iii3) | [III.5](#ejercicio-iii5)

Segunda pasada sugerida:

- [III.4](#ejercicio-iii4) | [III.6](#ejercicio-iii6) | [III.7](#ejercicio-iii7) | [III.8](#ejercicio-iii8)

## Formulas `0-based`

```text
parent(i) = (i - 1) / 2
left(i) = 2i + 1
right(i) = 2i + 2
```

### Ejercicio III.1

Dado:

```cpp
vector<int> a = {4, 10, 3, 5, 1, 8, 9, 2, 7, 6, 11, 0};
```

Ordene de menor a mayor usando HeapSort. Muestre:

1. max-heap construido;
2. al menos las primeras tres extracciones;
3. arreglo final.

### Ejercicio III.2

Dado:

```cpp
vector<int> a = {45, 12, 38, 7, 21, 49, 3, 33, 16, 29, 41, 1};
```

Ordene de menor a mayor usando HeapSort.

### Ejercicio III.3

Dado:

```cpp
vector<int> a = {3, 7, 12, 14, 18, 21, 23, 25, 28, 32, 37, 41, 45, 50, 55};
```

Ordene de mayor a menor usando HeapSort. Indique que tipo de heap conviene construir.

### Ejercicio III.4

Implemente:

```cpp
void heapifyDown(vector<int>& a, int heapSize, int i);
```

La función debe mantener la propiedad de max-heap.

### Ejercicio III.5

Implemente:

```cpp
void heapSortAsc(vector<int>& a);
```

Debe ordenar de menor a mayor usando max-heap.

### Ejercicio III.6

Implemente:

```cpp
vector<int> combinarHeaps(vector<int> h1, vector<int> h2);
```

Ambos vectores representan max-heaps. Debe retornar un nuevo max-heap con todos los elementos.

### Ejercicio III.7

Construya un min-heap a partir del arreglo:

```cpp
vector<int> a = {20, 12, 61, 33, 48, 81};
```

### Ejercicio III.8

Responda conceptualmente:

1. Por qué un heap no es un ABB?
2. Por qué buscar un valor arbitrario en un heap cuesta `O(n)`?
3. Por qué construir un heap completo cuesta `O(n)` y no `O(n log n)`?
4. Por qué HeapSort no es estable?

