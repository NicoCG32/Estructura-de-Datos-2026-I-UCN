# I. Recorridos de Árboles

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rápido

- [I.1](#ejercicio-i1) | [I.2](#ejercicio-i2) | [I.3](#ejercicio-i3) | [I.4](#ejercicio-i4) | [I.5](#ejercicio-i5)
- [I.6](#ejercicio-i6) | [I.7](#ejercicio-i7) | [I.8](#ejercicio-i8) | [I.9](#ejercicio-i9) | [I.10](#ejercicio-i10)

## Ejercicio I.1

Resultados:

- grado de `D`: `3`;
- hojas: `E, J, K, L, C, P, Q, H, N, O`;
- hermanos de `B`: `C` y `D`;
- camino de `A` a `J`: `A -> B -> F -> J`;
- longitud del camino: `3` arcos;
- nivel de `A`: `1`;
- nivel de `H`: `3`;
- altura del árbol: `5` niveles;
- altura de `G`: `3` niveles contando `G -> M -> P/Q`;
- profundidad de `G`: `2` arcos desde la raíz.

Preorden:

```text
A, B, E, F, J, K, L, C, D, G, M, P, Q, H, I, N, O
```

Postorden:

```text
E, J, K, L, F, B, C, P, Q, M, G, H, N, O, I, D, A
```

## Ejercicio I.2

Preorden:

```text
A, B, D, E, H, I, C, F, G
```

Inorden:

```text
D, B, H, E, I, A, F, C, G
```

Postorden:

```text
D, H, I, E, B, F, G, C, A
```

Por niveles:

```text
A, B, C, D, E, F, G, H, I
```

## Ejercicio I.3

La raíz es el primer elemento del preorden: `8`.

En el inorden, los valores a la izquierda de `8` forman el subarbol izquierdo y los valores a la derecha forman el subarbol derecho:

```text
izquierda: 1, 3, 4, 6, 7
raiz:      8
derecha:  10, 13, 14
```

El árbol reconstruido es:

```text
          8
       /     \
      3       10
     / \        \
    1   6        14
       / \      /
      4   7    13
```

Postorden:

```text
1, 4, 7, 6, 3, 13, 14, 10, 8
```

## Ejercicio I.4

```cpp
# include <iostream>
# include <queue>
using namespace std;

void printLevels(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}
```

Complejidad:

- Tiempo: `O(n)`;
- Espacio adicional: `O(w)`, donde `w` es el máximo ancho del árbol.

## Ejercicio I.5

```cpp
# include <stack>
using namespace std;

int countLeaves(TreeNode* root) {
    if (root == nullptr) return 0;

    int count = 0;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* current = st.top();
        st.pop();

        if (current->left == nullptr && current->right == nullptr) {
            count++;
        }

        if (current->right != nullptr) st.push(current->right);
        if (current->left != nullptr) st.push(current->left);
    }

    return count;
}
```

Complejidad:

- Tiempo: `O(n)`;
- Espacio adicional: `O(h)` en un árbol balanceado durante DFS, pero puede llegar a `O(n)` segun la forma del árbol y el orden de apilado.

## Ejercicio I.6

```cpp
# include <queue>
using namespace std;

int heightByLevels(TreeNode* root) {
    if (root == nullptr) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int height = 0;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }

        height++;
    }

    return height;
}
```

Complejidad:

- Tiempo: `O(n)`;
- Espacio adicional: `O(w)`.

## Ejercicio I.7

Árbol:

```text
          20
       /      \
      12       61
     /  \     /
    33  48   81
```

Tabla:

| Índice | Valor | Padre | Izquierdo | Derecho |
| --- | --- | --- | --- | --- |
| `1` | `20` | no tiene | `2` | `3` |
| `2` | `12` | `1` | `4` | `5` |
| `3` | `61` | `1` | `6` | no tiene |
| `4` | `33` | `2` | no tiene | no tiene |
| `5` | `48` | `2` | no tiene | no tiene |
| `6` | `81` | `3` | no tiene | no tiene |

Las fórmulas funcionan bajo indexación `1-based` porque la raíz se ubica en `1`. Si el arreglo empieza en `0`, las fórmulas cambian a:

```text
left(i) = 2i + 1
right(i) = 2i + 2
parent(i) = (i - 1) / 2
```

## Ejercicio I.8

```text
A) lleno y completo.
B) no lleno, pero completo.
C) no lleno y no completo.
```

Justificacion:

- lleno: todos los niveles tienen la cantidad maxima de nodos;
- completo: las hojas del ultimo nivel están lo más a la izquierda posible;
- en `C`, el nodo `6` aparece como hijo derecho sin ocupar primero la posicion izquierda correspondiente.

## Ejercicio I.9

El inorden del ABB es:

```text
1, 3, 4, 6, 7, 8, 10, 13, 14
```

Tabla:

| Nodo | Predecesor | Sucesor |
| --- | --- | --- |
| `1` | `nullptr` | `3` |
| `3` | `1` | `4` |
| `4` | `3` | `6` |
| `6` | `4` | `7` |
| `7` | `6` | `8` |
| `8` | `7` | `10` |
| `10` | `8` | `13` |
| `13` | `10` | `14` |
| `14` | `13` | `nullptr` |

## Ejercicio I.10

```cpp
# include <iostream>
# include <stack>
using namespace std;

void inorderIter(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        cout << current->data << " ";
        current = current->right;
    }
}
```

Idea:

La pila guarda el camino de ancestros cuyo subarbol izquierdo ya se esta explorando. Cuando ya no se puede bajar más a la izquierda, se procesa el ultimo nodo pendiente y luego se avanza a su subarbol derecho.

Complejidad:

- Tiempo: `O(n)`;
- Espacio adicional: `O(h)`, donde `h` es la altura del árbol.

