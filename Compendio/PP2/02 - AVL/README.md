# II. AVL

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque esta basado en ejercicios reales donde se pide insertar, eliminar, indicar factores de balance y reconocer rotaciones. En una prueba no basta con dibujar el árbol final: hay que mostrar en que nodo aparece el primer desbalance y que rotacion lo corrige.

## Índice para estudiar

Primera pasada sugerida:

- [II.1](#ejercicio-ii1) | [II.2](#ejercicio-ii2) | [II.3](#ejercicio-ii3) | [II.6](#ejercicio-ii6)

Segunda pasada sugerida:

- [II.4](#ejercicio-ii4) | [II.5](#ejercicio-ii5) | [II.7](#ejercicio-ii7)

## Convencion

Usaremos:

```text
FB(node) = altura(left) - altura(right)
```

Un nodo esta balanceado si su FB es `-1`, `0` o `1`.

## Estructura base

```cpp
struct Node {
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int value) : value(value), height(1), left(nullptr), right(nullptr) {}
};
```

### Ejercicio II.1

Inserte en un AVL:

```text
10, 20, 30, 25, 5, 35, 40, 15, 27
```

Luego elimine, usando el menor de los mayores:

```text
10, 35, 20
```

Se pide:

1. árbol despues de cada rotacion;
2. FB de los nodos afectados;
3. árbol final.

### Ejercicio II.2

Inserte en un AVL:

```text
68, 45, 29, 75, 90, 70, 34
```

Luego elimine, usando el mayor de los menores:

```text
68, 45, 34, 90
```

Se pide indicar cada caso: `LL`, `RR`, `LR` o `RL`.

### Ejercicio II.3

Para cada secuencia, indique el tipo de rotacion que aparece al insertar el tercer valor:

1. `30, 20, 10`
2. `10, 20, 30`
3. `30, 10, 20`
4. `10, 30, 20`

### Ejercicio II.4

Implemente las funciones base:

```cpp
int height(Node* root);
int balance(Node* root);
Node* rotateRight(Node* y);
Node* rotateLeft(Node* x);
```

### Ejercicio II.5

Implemente:

```cpp
Node* insertAvl(Node* root, int value);
```

Debe omitir valores repetidos.

### Ejercicio II.6

Implemente:

```cpp
bool isAvl(Node* root);
```

La función debe verificar que todos los nodos cumplan `abs(FB) <= 1`.

### Ejercicio II.7

Compare AVL y Heap:

1. cual sirve mejor para busquedas frecuentes;
2. cual sirve mejor para extraer repetidamente el máximo o mínimo;
3. cual mantiene orden total y cual mantiene orden parcial;
4. que costo tiene buscar un valor arbitrario en cada estructura.

