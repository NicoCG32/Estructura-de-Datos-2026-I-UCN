# II. AVL

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [II.1](#ejercicio-ii1) | [II.2](#ejercicio-ii2) | [II.3](#ejercicio-ii3) | [II.4](#ejercicio-ii4) | [II.5](#ejercicio-ii5)
- [II.6](#ejercicio-ii6) | [II.7](#ejercicio-ii7)

## Ejercicio II.1

Inserciones:

```text
10, 20, 30, 25, 5, 35, 40, 15, 27
```

La rotacion relevante durante la insercion es:

```text
+30: caso RR en 10
```

Despues de todas las inserciones, el AVL queda:

```text
          20
       /      \
      10       30
     /  \     /  \
    5   15   25   35
              \     \
              27     40
```

Eliminaciones con menor de los mayores:

```text
10, 35, 20
```

No aparece una rotacion obligatoria en esta secuencia bajo la convencion indicada. El árbol final queda:

```text
          25
       /      \
      15       30
     /        /  \
    5        27   40
```

Inorden final:

```text
5, 15, 25, 27, 30, 40
```

## Ejercicio II.2

Inserciones:

```text
68, 45, 29, 75, 90, 70, 34
```

Rotaciones:

```text
+29: LL en 68
+90: RR en 68
+70: RL en 45
+34: LR en 45
```

Árbol despues de insertar todo:

```text
          68
       /      \
      34       75
     /  \     /  \
    29  45   70   90
```

Eliminaciones usando mayor de los menores:

```text
68, 45, 34, 90
```

Rotaciones durante eliminacion:

```text
-34: RR en 29
-90: LR en 75
```

Árbol final:

```text
       70
      /  \
     29   75
```

## Ejercicio II.3

```text
30, 20, 10 -> LL, rotacion simple a la derecha.
10, 20, 30 -> RR, rotacion simple a la izquierda.
30, 10, 20 -> LR, izquierda en el hijo izquierdo y derecha en la raiz.
10, 30, 20 -> RL, derecha en el hijo derecho e izquierda en la raiz.
```

En los cuatro casos, el árbol queda:

```text
     20
    /  \
   10   30
```

## Ejercicio II.4

```cpp
# include <algorithm>
using namespace std;

int height(Node* root) {
    if (root == nullptr) return 0;
    return root->height;
}

void updateHeight(Node* root) {
    if (root != nullptr) {
        root->height = 1 + max(height(root->left), height(root->right));
    }
}

int balance(Node* root) {
    if (root == nullptr) return 0;
    return height(root->left) - height(root->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    updateHeight(x);
    updateHeight(y);

    return y;
}
```

## Ejercicio II.5

```cpp
Node* insertAvl(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insertAvl(root->left, value);
    } else if (value > root->value) {
        root->right = insertAvl(root->right, value);
    } else {
        return root;
    }

    updateHeight(root);
    int fb = balance(root);

    if (fb > 1 && value < root->left->value) {
        return rotateRight(root);
    }

    if (fb < -1 && value > root->right->value) {
        return rotateLeft(root);
    }

    if (fb > 1 && value > root->left->value) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (fb < -1 && value < root->right->value) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
```

Complejidad:

- Tiempo: `O(log n)` si el AVL esta correctamente mantenido;
- Espacio adicional: `O(log n)` por recursión.

## Ejercicio II.6

```cpp
# include <cstdlib>
# include <utility>
using namespace std;

pair<bool, int> checkAvl(Node* root) {
    if (root == nullptr) {
        return {true, 0};
    }

    pair<bool, int> left = checkAvl(root->left);
    pair<bool, int> right = checkAvl(root->right);

    bool balanced = left.first &&
                    right.first &&
                    abs(left.second - right.second) <= 1;

    int h = 1 + max(left.second, right.second);
    return {balanced, h};
}

bool isAvl(Node* root) {
    return checkAvl(root).first;
}
```

Esta solución calcula altura y validez en la misma pasada. No recalcula alturas desde cero en cada nodo.

Complejidad:

- Tiempo: `O(n)`;
- Espacio adicional: `O(h)` por recursión.

## Ejercicio II.7

Comparacion:

| Criterio | AVL | Heap |
| --- | --- | --- |
| Busqueda arbitraria | `O(log n)` | `O(n)` |
| Insertar | `O(log n)` | `O(log n)` |
| Eliminar valor arbitrario | `O(log n)` si se busca por propiedad ABB | normalmente `O(n)` para encontrarlo |
| Extraer máximo/mínimo | `O(log n)` si se busca extremo | `O(log n)` en heap apropiado |
| Orden interno | orden total por propiedad ABB | orden parcial padre-hijo |
| Uso tipico | diccionarios ordenados, indices dinamicos | colas de prioridad, HeapSort |

Idea clave:

Un AVL sirve cuando se necesita buscar, insertar y eliminar manteniendo orden total. Un heap sirve cuando importa acceder repetidamente al máximo o mínimo, no cuando se necesita buscar cualquier valor.

