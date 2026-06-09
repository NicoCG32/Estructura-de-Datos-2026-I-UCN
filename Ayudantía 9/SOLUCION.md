# Ayudantía 9: Soluciones

Este archivo contiene soluciones para los ejercicios de árboles propuestos en `README.md`.

Se incluyen versiones recursivas e iterativas cuando ambas son razonables. La solución iterativa no es necesariamente más corta, pero permite ver con claridad qué información normalmente guarda la pila de llamadas de la recursión.

## Código base común

```cpp
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <stdexcept>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

TreeNode* crearArbolReferencia() {
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    return root;
}
```

---

# Problema 1: valores en rango dentro de un BST

## Idea

En un BST, el recorrido inorden visita los valores en orden ascendente. Por eso no se debe usar `sort`.

Además, se puede podar:

- si `node->data < low`, entonces el nodo y todo su subárbol izquierdo son menores que `low`;
- si durante inorden aparece `node->data > high`, se puede terminar, porque lo que queda será aún mayor.

## Solución iterativa

```cpp
vector<int> valoresEnRangoBST(TreeNode* root, int low, int high) {
    vector<int> result;

    if (root == nullptr || low > high) {
        return result;
    }

    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            if (current->data < low) {
                current = current->right;
            } else {
                st.push(current);
                current = current->left;
            }
        }

        if (st.empty()) {
            break;
        }

        current = st.top();
        st.pop();

        if (current->data > high) {
            break;
        }

        result.push_back(current->data);
        current = current->right;
    }

    return result;
}
```

## Solución recursiva

```cpp
void recolectarEnRango(TreeNode* root, int low, int high, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    if (root->data > low) {
        recolectarEnRango(root->left, low, high, result);
    }

    if (root->data >= low && root->data <= high) {
        result.push_back(root->data);
    }

    if (root->data < high) {
        recolectarEnRango(root->right, low, high, result);
    }
}

vector<int> valoresEnRangoBSTRec(TreeNode* root, int low, int high) {
    vector<int> result;

    if (low > high) {
        return result;
    }

    recolectarEnRango(root, low, high, result);
    return result;
}
```

## Correctitud

La poda inferior es correcta porque, si `root->data < low`, entonces todo valor del subárbol izquierdo es menor que `root->data`, y por tanto también es menor que `low`.

La detención superior es correcta porque el recorrido inorden de un BST es ascendente. Si se procesa un valor mayor que `high`, ningún valor posterior puede pertenecer al rango.

Como el algoritmo agrega exactamente los valores que cumplen `low <= x <= high` y los visita en inorden, el resultado contiene todos los valores válidos en orden ascendente.

## Complejidad

Sea `h` la altura del árbol y `m` la cantidad de valores retornados.

- Tiempo esperado en BST balanceado: `O(log n + m)`.
- Tiempo general: `O(h + m)`.
- Peor caso con árbol desbalanceado: `O(n)`.
- Espacio auxiliar: `O(h)`, sin contar la salida.

---

# Problema 2: validar si un árbol binario es BST

## Idea

No basta con verificar que cada nodo cumpla:

```text
left < root < right
```

Eso solo valida una condición local. Para validar correctamente un BST, cada nodo debe respetar los límites impuestos por todos sus ancestros.

## Solución recursiva

```cpp
bool validarConLimites(TreeNode* root, long long inferior, long long superior) {
    if (root == nullptr) {
        return true;
    }

    if (root->data <= inferior || root->data >= superior) {
        return false;
    }

    return validarConLimites(root->left, inferior, root->data) &&
           validarConLimites(root->right, root->data, superior);
}

bool esBSTRec(TreeNode* root) {
    return validarConLimites(root, LLONG_MIN, LLONG_MAX);
}
```

## Solución iterativa

```cpp
bool esBST(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    stack<tuple<TreeNode*, long long, long long>> st;
    st.push({root, LLONG_MIN, LLONG_MAX});

    while (!st.empty()) {
        auto [current, inferior, superior] = st.top();
        st.pop();

        if (current->data <= inferior || current->data >= superior) {
            return false;
        }

        if (current->right != nullptr) {
            st.push({current->right, current->data, superior});
        }

        if (current->left != nullptr) {
            st.push({current->left, inferior, current->data});
        }
    }

    return true;
}
```

## Correctitud

Cada nodo se procesa con un intervalo abierto `(inferior, superior)` que representa todos los límites heredados desde sus ancestros.

- Al bajar a la izquierda, el límite superior pasa a ser el valor del nodo actual.
- Al bajar a la derecha, el límite inferior pasa a ser el valor del nodo actual.

Si todos los nodos respetan su intervalo, entonces cada subárbol respeta la propiedad global del BST. Si algún nodo viola su intervalo, el árbol no puede ser BST.

## Complejidad

- Tiempo: `O(n)`, porque en el peor caso se revisan todos los nodos.
- Espacio: `O(h)` en la versión recursiva y `O(h)` esperado en la iterativa si el árbol es balanceado.
- Peor caso de espacio: `O(n)` si el árbol está muy desbalanceado o si la pila llega a guardar muchos nodos.

---

# Problema 3: k-ésimo menor elemento en un BST

## Idea

El inorden de un BST produce los valores en orden ascendente. Por lo tanto, basta hacer inorden y contar cuántos nodos se han visitado.

No es necesario guardar todos los valores en un vector: se puede detener el recorrido cuando se encuentra el k-ésimo.

## Solución iterativa

```cpp
int kEsimoMenorBST(TreeNode* root, int k) {
    if (root == nullptr || k <= 0) {
        throw invalid_argument("Entrada invalida: root nulo o k no positivo.");
    }

    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        k--;

        if (k == 0) {
            return current->data;
        }

        current = current->right;
    }

    throw out_of_range("Entrada invalida: k supera la cantidad de nodos.");
}
```

## Solución recursiva

```cpp
void buscarKesimo(TreeNode* root, int& k, int& answer, bool& found) {
    if (root == nullptr || found) {
        return;
    }

    buscarKesimo(root->left, k, answer, found);

    if (found) {
        return;
    }

    k--;

    if (k == 0) {
        answer = root->data;
        found = true;
        return;
    }

    buscarKesimo(root->right, k, answer, found);
}

int kEsimoMenorBSTRec(TreeNode* root, int k) {
    if (root == nullptr || k <= 0) {
        throw invalid_argument("Entrada invalida: root nulo o k no positivo.");
    }

    int answer = 0;
    bool found = false;

    buscarKesimo(root, k, answer, found);

    if (!found) {
        throw out_of_range("Entrada invalida: k supera la cantidad de nodos.");
    }

    return answer;
}
```

## Correctitud

El recorrido inorden entrega los valores del BST en orden ascendente. El algoritmo decrementa `k` exactamente cuando visita un nodo en ese orden. Cuando `k` llega a cero, el nodo actual es precisamente el k-ésimo valor menor.

## Complejidad

Sea `h` la altura del árbol.

- Tiempo: `O(h + k)` si se detiene al encontrar el k-ésimo elemento.
- Peor caso: `O(n)`.
- Espacio auxiliar: `O(h)`.

---

# Problema 4: ancestro común más bajo en un BST

## Idea

En un BST, desde la raíz se puede decidir hacia dónde avanzar:

- si `p` y `q` son menores que el nodo actual, la respuesta está a la izquierda;
- si `p` y `q` son mayores que el nodo actual, la respuesta está a la derecha;
- en otro caso, el nodo actual separa a `p` y `q`, o coincide con uno de ellos. Por tanto, es el LCA.

## Solución iterativa

```cpp
TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || p == nullptr || q == nullptr) {
        return nullptr;
    }

    int a = p->data;
    int b = q->data;

    TreeNode* current = root;

    while (current != nullptr) {
        if (a < current->data && b < current->data) {
            current = current->left;
        } else if (a > current->data && b > current->data) {
            current = current->right;
        } else {
            return current;
        }
    }

    return nullptr;
}
```

## Solución recursiva

```cpp
TreeNode* lcaBSTRec(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || p == nullptr || q == nullptr) {
        return nullptr;
    }

    if (p->data < root->data && q->data < root->data) {
        return lcaBSTRec(root->left, p, q);
    }

    if (p->data > root->data && q->data > root->data) {
        return lcaBSTRec(root->right, p, q);
    }

    return root;
}
```

## Correctitud

Si ambos nodos son menores que el nodo actual, por la propiedad BST ambos pertenecen al subárbol izquierdo. Ningún nodo del subárbol derecho puede ser ancestro de ellos.

Análogamente, si ambos son mayores, ambos pertenecen al subárbol derecho.

Cuando los valores quedan separados por el nodo actual, o cuando uno coincide con él, el nodo actual es el primer punto donde los caminos hacia `p` y `q` se separan. Por definición, ese nodo es el ancestro común más bajo.

## Complejidad

- Tiempo: `O(h)`.
- Espacio iterativo: `O(1)`.
- Espacio recursivo: `O(h)` por la pila de llamadas.

---

# Problema 5: recorrido por niveles de un árbol binario

## Idea

El recorrido por niveles se resuelve naturalmente con BFS. La estructura adecuada es una cola, porque se deben procesar primero los nodos que llegaron antes, es decir, los del nivel actual.

## Solución iterativa con BFS

```cpp
vector<vector<int>> recorridoPorNiveles(TreeNode* root) {
    vector<vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        vector<int> level;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();

            level.push_back(current->data);

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        result.push_back(level);
    }

    return result;
}
```

## Solución recursiva por profundidad

```cpp
void recorrerNivelRec(TreeNode* root, int depth, vector<vector<int>>& result) {
    if (root == nullptr) {
        return;
    }

    if (depth == static_cast<int>(result.size())) {
        result.push_back(vector<int>());
    }

    result[depth].push_back(root->data);

    recorrerNivelRec(root->left, depth + 1, result);
    recorrerNivelRec(root->right, depth + 1, result);
}

vector<vector<int>> recorridoPorNivelesRec(TreeNode* root) {
    vector<vector<int>> result;
    recorrerNivelRec(root, 0, result);
    return result;
}
```

## Correctitud

En la versión BFS, al inicio de cada iteración externa, la cola contiene exactamente los nodos del nivel actual. `levelSize` fija cuántos nodos pertenecen a ese nivel antes de insertar los hijos. Por tanto, cada subvector contiene un nivel completo y en orden de izquierda a derecha.

En la versión recursiva, el parámetro `depth` indica el nivel del nodo actual. Cada valor se inserta en `result[depth]`. Como se visita primero el hijo izquierdo y luego el derecho, el orden dentro de cada nivel queda de izquierda a derecha.

## Complejidad

- Tiempo: `O(n)`.
- Espacio BFS: `O(w)`, donde `w` es el ancho máximo del árbol.
- Espacio recursivo: `O(h)` por pila de llamadas, más `O(n)` por la salida.

---

# Problema 6: diámetro de un árbol binario

## Idea

El diámetro es el mayor número de aristas en un camino entre dos nodos.

Para cada nodo, el camino más largo que pasa por él tiene longitud:

```text
altura izquierda + altura derecha
```

Si la altura se mide como cantidad de nodos desde el nodo actual hacia abajo, entonces un hijo nulo tiene altura `0`. Con esa convención, `alturaIzquierda + alturaDerecha` da directamente la cantidad de aristas del camino que pasa por el nodo actual.

## Solución recursiva

```cpp
int alturaYDiametro(TreeNode* root, int& best) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = alturaYDiametro(root->left, best);
    int rightHeight = alturaYDiametro(root->right, best);

    best = max(best, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diametroArbolBinarioRec(TreeNode* root) {
    int best = 0;
    alturaYDiametro(root, best);
    return best;
}
```

## Solución iterativa simulando postorden

```cpp
int diametroArbolBinario(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int best = 0;

    unordered_map<TreeNode*, int> height;
    stack<pair<TreeNode*, bool>> st;

    st.push({root, false});

    while (!st.empty()) {
        auto [current, visited] = st.top();
        st.pop();

        if (current == nullptr) {
            continue;
        }

        if (visited) {
            int leftHeight = current->left == nullptr ? 0 : height[current->left];
            int rightHeight = current->right == nullptr ? 0 : height[current->right];

            best = max(best, leftHeight + rightHeight);
            height[current] = 1 + max(leftHeight, rightHeight);
        } else {
            st.push({current, true});
            st.push({current->right, false});
            st.push({current->left, false});
        }
    }

    return best;
}
```

## Correctitud

La altura de un nodo depende de la altura de sus hijos. Por eso se requiere postorden: primero se resuelven los subárboles y luego el nodo actual.

Para cada nodo, el mejor camino que pasa por él se obtiene bajando hasta la hoja más profunda del subárbol izquierdo y hasta la hoja más profunda del subárbol derecho. Su longitud es `leftHeight + rightHeight`.

El algoritmo calcula esa cantidad en todos los nodos y guarda el máximo. Por tanto, retorna el diámetro del árbol.

## Complejidad

- Tiempo: `O(n)`, porque cada nodo se procesa una vez.
- Espacio recursivo: `O(h)` por pila de llamadas.
- Espacio iterativo: `O(n)` por el mapa de alturas y la pila.
- Si se cuenta solo la salida, el problema retorna un entero, por lo que no hay costo adicional de salida.

---

# Resumen comparativo

| Problema | Tipo de árbol | Recorrido principal | Estructura auxiliar | Complejidad temporal |
| --- | --- | --- | --- | --- |
| Valores en rango | BST | Inorden con poda | `stack` o pila recursiva | `O(h + m)` |
| Validar BST | Binario | DFS con límites | `stack`/recursión | `O(n)` |
| K-ésimo menor | BST | Inorden | `stack`/recursión | `O(h + k)` |
| LCA en BST | BST | Búsqueda dirigida | ninguna/recursión | `O(h)` |
| Niveles | Binario | BFS | `queue` | `O(n)` |
| Diámetro | Binario | Postorden | recursión o mapa | `O(n)` |

# Errores frecuentes

- Usar `sort` para compensar un recorrido mal elegido.
- Validar BST comparando solo padre con hijos.
- Confundir el diámetro medido en nodos con el diámetro medido en aristas.
- Usar BFS cuando se necesita inorden ascendente.
- Recorrer todo el árbol cuando la propiedad BST permite podar.
- No manejar `root == nullptr`.
- Olvidar que un árbol desbalanceado puede degradar la complejidad espacial de la recursión a `O(n)`.
