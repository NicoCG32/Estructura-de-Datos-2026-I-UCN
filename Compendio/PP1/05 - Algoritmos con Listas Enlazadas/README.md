# V. Algoritmos con Listas Enlazadas

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene estudiarlo después de complejidad. Aquí debes aprender a leer la lista como una estructura dinámica: qué puntero cambia, cuándo cambia `head`, si conviene crear nodos nuevos o solo reconectar enlaces y qué costo tiene cada decisión.

## Índice para estudiar

Primera pasada sugerida:

- [V.1](#ejercicio-v1) | [V.2](#ejercicio-v2) | [V.4](#ejercicio-v4) | [V.8](#ejercicio-v8)

Segunda pasada sugerida:

- [V.5](#ejercicio-v5) | [V.7](#ejercicio-v7) | [V.9](#ejercicio-v9) | [V.10](#ejercicio-v10)

Banco completo:

- [V.1](#ejercicio-v1) | [V.2](#ejercicio-v2) | [V.3](#ejercicio-v3) | [V.4](#ejercicio-v4) | [V.5](#ejercicio-v5)
- [V.6](#ejercicio-v6) | [V.7](#ejercicio-v7) | [V.8](#ejercicio-v8) | [V.9](#ejercicio-v9) | [V.10](#ejercicio-v10)
- [V.11](#ejercicio-v11) | [V.12](#ejercicio-v12) | [V.13](#ejercicio-v13) | [V.14](#ejercicio-v14) | [V.15](#ejercicio-v15)
- [V.16](#ejercicio-v16) | [V.17](#ejercicio-v17) | [V.18](#ejercicio-v18) | [V.19](#ejercicio-v19) | [V.20](#ejercicio-v20)

En esta sección se asume la siguiente estructura base, salvo que se indique otra cosa:

```cpp
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};
```

## Como estudiar este tema

Antes de escribir código:

- dibuje la lista antes y después de cada operación importante;
- aclare si el algoritmo modifica la estructura original o construye otra;
- vigile especialmente los casos borde: lista vacía, un nodo, inserción al inicio o al final;
- termine siempre con la complejidad temporal y espacial de su propuesta.

### Ejercicio V.1

```cpp
void insertAtIndex(Node*& head, int index, int value);
```

Inserte un nuevo nodo con valor `value` en la posición `index`. Si el índice es inválido, no modifique la lista.

### Ejercicio V.2

```cpp
void eraseAtIndex(Node*& head, int index);
```

Elimine el nodo ubicado en la posición `index`. Si el índice es inválido, no haga cambios.

### Ejercicio V.3

```cpp
void removeAll(Node*& head, int value);
```

Elimine todos los nodos cuyo dato sea igual a `value`.

### Ejercicio V.4

```cpp
void reverseList(Node*& head);
```

Invierta completamente una lista enlazada simple sin crear una segunda lista.

### Ejercicio V.5

```cpp
Node* addTwoNumbers(Node* l1, Node* l2);
```

Cada lista representa un número entero no negativo en orden inverso. Retorne una nueva lista con la suma.

### Ejercicio V.6

```cpp
void removePrimes(Node*& head);
```

La lista contiene enteros positivos. Elimine todos los nodos cuyo valor sea primo.

### Ejercicio V.7

```cpp
void compressIncreasingRuns(Node*& head);
```

Si hay una subsecuencia estrictamente creciente consecutiva, conserve solo el primer nodo del patrón.

Ejemplo:

```text
[1,2,3,4,5,6,7,100,2] -> [1,100,2]
```

### Ejercicio V.8

```cpp
Node* middleNode(Node* head);
```

Retorne un puntero al nodo medio de la lista. Si hay dos medios, puede retornar cualquiera de los dos, pero debe explicitar su criterio.

### Ejercicio V.9

```cpp
Node* mergeSorted(Node* a, Node* b);
```

Dadas dos listas simples ordenadas de menor a mayor, retorne una nueva lista ordenada que mezcle ambas.

### Ejercicio V.10

Ahora use la siguiente estructura:

```cpp
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};
```

Implemente:

```cpp
bool isPalindromeCircular(DNode* head);
```

La lista es doblemente enlazada y circular. Determine si sus valores forman un palíndromo.

### Ejercicio V.11

```cpp
void pushBack(Node*& head, int value);
```

Inserte un nuevo nodo al final de la lista.

### Ejercicio V.12

```cpp
int length(Node* head);
```

Retorne la cantidad de nodos de la lista.

### Ejercicio V.13

```cpp
bool contains(Node* head, int value);
```

Determine si un valor aparece en la lista.

### Ejercicio V.14

```cpp
void removeFirst(Node*& head, int value);
```

Elimine solo la primera aparición del valor indicado.

### Ejercicio V.15

```cpp
int maxValue(Node* head);
```

Retorne el mayor valor almacenado en la lista. Suponga que la lista no está vacía.

### Ejercicio V.16

```cpp
void removeConsecutiveDuplicates(Node*& head);
```

Si una lista tiene nodos consecutivos con el mismo valor, conserve solo uno.

Ejemplo:

```text
[2,2,2,5,5,7,7,7,7,9] -> [2,5,7,9]
```

### Ejercicio V.17

```cpp
void insertSorted(Node*& head, int value);
```

Inserte un nuevo valor manteniendo la lista ordenada de menor a mayor.

### Ejercicio V.18

```cpp
Node* interleave(Node* a, Node* b);
```

Construya una nueva lista alternando nodos de `a` y `b`. Si una lista se termina antes, agregue el resto de la otra.

### Ejercicio V.19

```cpp
int sumList(Node* head);
```

Retorne la suma de todos los valores de la lista.

### Ejercicio V.20

```cpp
bool hasCycle(Node* head);
```

Determine si una lista enlazada simple tiene ciclo.

---
