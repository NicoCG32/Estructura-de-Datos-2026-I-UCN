# III. HeapSort

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [III.1](#ejercicio-iii1) | [III.2](#ejercicio-iii2) | [III.3](#ejercicio-iii3) | [III.4](#ejercicio-iii4)
- [III.5](#ejercicio-iii5) | [III.6](#ejercicio-iii6) | [III.7](#ejercicio-iii7) | [III.8](#ejercicio-iii8)

## Ejercicio III.1

Arreglo original:

```text
4, 10, 3, 5, 1, 8, 9, 2, 7, 6, 11, 0
```

Max-heap construido:

```text
11, 10, 9, 7, 6, 8, 3, 2, 5, 4, 1, 0
```

Primeras tres extracciones:

```text
10, 7, 9, 5, 6, 8, 3, 2, 0, 4, 1, 11
9, 7, 8, 5, 6, 1, 3, 2, 0, 4, 10, 11
8, 7, 4, 5, 6, 1, 3, 2, 0, 9, 10, 11
```

Arreglo final:

```text
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
```

## Ejercicio III.2

Max-heap construido:

```text
49, 41, 45, 33, 29, 38, 3, 7, 16, 12, 21, 1
```

Primeras tres extracciones:

```text
45, 41, 38, 33, 29, 1, 3, 7, 16, 12, 21, 49
41, 33, 38, 21, 29, 1, 3, 7, 16, 12, 45, 49
38, 33, 12, 21, 29, 1, 3, 7, 16, 41, 45, 49
```

Arreglo final:

```text
1, 3, 7, 12, 16, 21, 29, 33, 38, 41, 45, 49
```

## Ejercicio III.3

Para ordenar de mayor a menor conviene construir un min-heap. Asi, cada extraccion deja el menor elemento al final, y el arreglo termina en orden descendente.

Min-heap inicial:

```text
3, 7, 12, 14, 18, 21, 23, 25, 28, 32, 37, 41, 45, 50, 55
```

Arreglo final descendente:

```text
55, 50, 45, 41, 37, 32, 28, 25, 23, 21, 18, 14, 12, 7, 3
```

## Ejercicio III.4

```cpp
# include <vector>
# include <algorithm>
using namespace std;

void heapifyDown(vector<int>& a, int heapSize, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && a[left] > a[largest]) {
            largest = left;
        }

        if (right < heapSize && a[right] > a[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        swap(a[i], a[largest]);
        i = largest;
    }
}
```

Complejidad:

- Tiempo: `O(log n)`;
- Espacio adicional: `O(1)`.

## Ejercicio III.5

```cpp
void heapSortAsc(vector<int>& a) {
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(a, n, i);
    }

    for (int end = n - 1; end > 0; end--) {
        swap(a[0], a[end]);
        heapifyDown(a, end, 0);
    }
}
```

Complejidad:

- Construccion del heap: `O(n)`;
- Ordenamiento: `O(n log n)`;
- Espacio adicional: `O(1)`.

## Ejercicio III.6

Una forma correcta no es intercalar arbitrariamente los arreglos. Se concatenan y luego se reconstruye el heap desde los ultimos nodos internos.

```cpp
vector<int> combinarHeaps(vector<int> h1, vector<int> h2) {
    vector<int> result;

    for (int x : h1) result.push_back(x);
    for (int x : h2) result.push_back(x);

    for (int i = (int)result.size() / 2 - 1; i >= 0; i--) {
        heapifyDown(result, result.size(), i);
    }

    return result;
}
```

Ejemplo:

```text
h1 = 100, 19, 36, 17, 3, 25, 1, 2, 7
h2 = 15, 10, 12, 6, 9, 11, 8, 4, 5
```

Un max-heap valido resultante es:

```text
100, 19, 36, 17, 15, 25, 11, 8, 7, 3, 10, 12, 6, 9, 1, 2, 4, 5
```

Complejidad:

- Tiempo: `O(n + m)`;
- Espacio adicional: `O(n + m)` por el vector resultado.

## Ejercicio III.7

Arreglo:

```text
20, 12, 61, 33, 48, 81
```

Min-heap valido:

```text
12, 20, 61, 33, 48, 81
```

Árbol:

```text
          12
       /      \
      20       61
     /  \     /
    33  48   81
```

## Ejercicio III.8

1. Un heap no es un ABB porque no exige que todo el subarbol izquierdo sea menor y todo el derecho mayor. Solo compara padre con hijos.
2. Buscar un valor arbitrario cuesta `O(n)` porque el orden parcial no permite descartar sistematicamente subarboles.
3. Construir un heap cuesta `O(n)` porque la mayoria de los nodos están cerca de las hojas y requieren pocos descensos durante `heapify`.
4. HeapSort no es estable porque realiza intercambios lejanos que pueden invertir el orden relativo de elementos iguales.

