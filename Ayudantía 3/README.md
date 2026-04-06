# Ayudantía 3: Programación a gran escala y Listas Enlazadas

## Organización de archivos

Ejemplos simples de estructura:

```text
proyecto/
├── include/
├── src/
├── docs/
├── scripts/
└── README.md
```

Si el proyecto crece, puedes separar por módulos:

```text
proyecto/
├── modules/
│   ├── lista/
│   │   ├── include/
│   │   └── src/
│   └── nodo/
│       ├── include/
│       └── src/
├── docs/
├── scripts/
└── README.md
```

### Diferencia entre `.h` y `.cpp`

Ejemplo corto:

```cpp
// Lista.h
#pragma once

class Lista {
public:
    void insertar(int valor);
};
```

```cpp
// Lista.cpp
#include "Lista.h"

void Lista::insertar(int valor) {
    // implementación real
}
```

La idea es simple: `.h` declara y `.cpp` implementa.

### Documentación

Para documentación técnica, recomiendo **Doxygen** como equivalente a Javadoc en C++.

Otras opciones útiles:

- MkDocs
- Sphinx
- README + Markdown en `docs/`

### Scripts

Para compilación y arranque, recomiendo usar `.bat` en Windows:

```bat
@echo off
if not exist build mkdir build
g++ -std=c++17 -Iinclude src\main.cpp src\Lista.cpp src\Nodo.cpp -o build\proyecto.exe
```

```bat
@echo off
build\proyecto.exe
```

Si quieres, también puedes tener equivalentes `.sh` para Linux o macOS pero por mi parte no lo exigiré.

## Introducción a Algoritmos

Un vector es un arreglo dinámico: sus elementos viven en memoria contigua y se accede a ellos por índice. Eso lo hace muy eficiente para lectura directa, aunque insertar o borrar en el medio puede requerir mover varios elementos.

Una linked list funciona distinto: cada nodo guarda su valor y un puntero al siguiente nodo. No necesita memoria contigua, así que es más flexible para crecer, pero para encontrar un elemento hay que recorrer la lista desde el inicio.

La diferencia central es el objetivo de diseño. El vector prioriza acceso rápido por posición; la lista enlazada prioriza inserciones y eliminaciones locales.

Cuando hablamos de interfaz, nos referimos al conjunto de operaciones públicas que ofrece una estructura. Es el contrato que define cómo se usa, sin describir necesariamente cómo está implementada.

En `vector`, la interfaz está orientada a acceso por índice y crecimiento al final. Por eso son comunes operaciones como `push_back`, `pop_back`, `operator[]`, `at`, `size`, `capacity`, `reserve` y `data`.

-> En java es simil al interfaz de 
```java
ArrayList<T>
```

En `list`, la interfaz está orientada a manipular nodos dentro de la secuencia sin mover todos los elementos. Por eso aparecen operaciones como `push_front`, `push_back`, `pop_front`, `pop_back`, `insert`, `erase`, `splice`, `sort` y `reverse`.

-> En java es simil al interfaz de 
```java
LinkedList<T>
```

En resumen: `vector` y `list` pueden almacenar secuencias, pero ofrecen interfaces distintas porque están optimizados para problemas distintos.

-> En java ambos puedes utilizarse con la interfaz de
```java
List<T>
```

## Ejercicios con nodos (sin STL, sin interfaces)

En esta ayudantía se trabaja solo con estructuras de nodos y punteros. No es necesario usar STL.

### Estructuras base sugeridas

```cpp
struct Node {
    int data;
    Node* next;
    Node(int n) : data(n), next(nullptr) {}
};
```

### Ejercicio 1: Insertar por índice

Problema:

Dado el puntero head de una lista simplemente enlazada, insertar un nuevo nodo con value en la posición index. Si index es inválido, no modificar la lista.

Firma:

```cpp
void insertAtIndex(Node*& head, int index, int value);
```

Ejemplos de ejecución:

| Input | Output |
|-------|--------|
| head: `5 -> 10 -> 15`, index: 0, value: 3 | `3 -> 5 -> 10 -> 15` |
| head: `5 -> 10 -> 15`, index: 1, value: 7 | `5 -> 7 -> 10 -> 15` |
| head: `5 -> 10 -> 15`, index: 3, value: 20 | `5 -> 10 -> 15 -> 20` |
| head: ∅, index: 0, value: 42 | `42` |

### Ejercicio 2: Eliminar por índice

Problema:

Dado el puntero head de una lista simplemente enlazada, eliminar el nodo ubicado en la posición index. Si index es inválido, no modificar la lista.

Firma:

```cpp
void eraseAtIndex(Node*& head, int index);
```

Ejemplos de ejecución:

| Input | Output |
|-------|--------|
| head: `5 -> 10 -> 15`, index: 0 | `10 -> 15` |
| head: `5 -> 10 -> 15 -> 20`, index: 1 | `5 -> 15 -> 20` |
| head: `5 -> 10 -> 15`, index: 2 | `5 -> 10` |
| head: `5 -> 10`, index: 5 | `5 -> 10` (sin cambios) |

---

### Ejercicio 3: Add Two Numbers

- Enlace de referencia: <https://leetcode.com/problems/add-two-numbers/description/>

Problema:

Se entregan dos listas enlazadas no vacías que representan dos enteros no negativos en orden inverso (cada nodo guarda un dígito). Debes retornar una nueva lista enlazada con la suma.

Firma:

```cpp
Node* addTwoNumbers(Node* l1, Node* l2);
```

Ejemplos de ejecución:

| Input | Output |
|-------|--------|
| l1: `2 -> 4 -> 3` (342), l2: `5 -> 6 -> 4` (465) | `7 -> 0 -> 8` (807) |
| l1: `9 -> 9 -> 9` (999), l2: `1` (1) | `0 -> 0 -> 0 -> 1` (1000) |
| l1: `2 -> 4` (42), l2: `5 -> 6 -> 4 -> 9` (9465) | `7 -> 0 -> 5 -> 9` (9507) |

---

### Ejercicio 4: Factorial simulando recursión con stack de nodos

Problema:

Calcular factorial(n) sin usar recursión. Debes simular la pila de llamadas usando una pila implementada con nodos enlazados.

Firma:

```cpp
long long factorialConStack(int n);
```

Ejemplos de ejecución:

| Input | Output |
|-------|--------|
| n: 0 | 1 |
| n: 5 | 120 |
| n: 10 | 3,628,800 |

---