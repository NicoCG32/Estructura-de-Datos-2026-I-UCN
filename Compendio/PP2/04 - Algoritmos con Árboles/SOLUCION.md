# IV. Algoritmos con Árboles

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [IV.1](#ejercicio-iv1) | [IV.2](#ejercicio-iv2) | [IV.3](#ejercicio-iv3) | [IV.4](#ejercicio-iv4)
- [IV.5](#ejercicio-iv5) | [IV.6](#ejercicio-iv6) | [IV.7](#ejercicio-iv7) | [IV.8](#ejercicio-iv8)

## Ejercicio IV.1

```cpp
int sumaEnRangoABB(Node* root, int L, int R) {
    if (root == nullptr || L > R) return 0;

    if (root->value < L) {
        return sumaEnRangoABB(root->right, L, R);
    }

    if (root->value > R) {
        return sumaEnRangoABB(root->left, L, R);
    }

    return root->value +
           sumaEnRangoABB(root->left, L, R) +
           sumaEnRangoABB(root->right, L, R);
}
```

Correctitud:

- si `root->value < L`, todo el subarbol izquierdo tambien es menor que `L`;
- si `root->value > R`, todo el subarbol derecho tambien es mayor que `R`;
- si el nodo esta dentro del rango, puede aportar y ambos subarboles aun pueden contener valores validos.

Complejidad:

- Esperada en ABB balanceado: `O(log n + m)`, donde `m` es la cantidad de nodos en rango;
- Peor caso: `O(n)`.

## Ejercicio IV.2

```cpp
# include <algorithm>
# include <stack>
# include <vector>
using namespace std;

void valoresEnRango(Node* root, int K1, int K2, vector<int>& values) {
    stack<Node*> st;
    Node* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            if (current->value < K1) {
                current = current->right;
            } else {
                st.push(current);
                current = current->left;
            }
        }

        if (st.empty()) break;

        current = st.top();
        st.pop();

        if (current->value > K2) break;

        values.push_back(current->value);
        current = current->right;
    }
}

vector<int> calcularSumas(Node* root, int K1, int K2, int K3) {
    vector<int> values;
    vector<int> result;

    if (K1 > K2 || K3 <= 0) return result;

    valoresEnRango(root, K1, K2, values);
    int n = values.size();
    if (K3 > n) return result;

    vector<int> idx(K3);
    for (int i = 0; i < K3; i++) idx[i] = i;

    while (true) {
        int sum = 0;
        for (int i = 0; i < K3; i++) {
            sum += values[idx[i]];
        }
        result.push_back(sum);

        int pos = K3 - 1;
        while (pos >= 0 && idx[pos] == n - K3 + pos) {
            pos--;
        }

        if (pos < 0) break;

        idx[pos]++;
        for (int j = pos + 1; j < K3; j++) {
            idx[j] = idx[j - 1] + 1;
        }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}
```

Complejidad:

- Extraer valores en rango: `O(h + m)`;
- Generar combinaciones: `O(C(m, K3) * K3)`;
- Ordenar sumas: `O(s log s)`, donde `s` es la cantidad de sumas generadas.

## Ejercicio IV.3

```cpp
# include <unordered_map>
# include <vector>
using namespace std;

Node* buildRec(vector<int>& inorder, int inL, int inR,
               vector<int>& postorder, int postL, int postR,
               unordered_map<int, int>& pos) {
    if (inL > inR) return nullptr;

    int rootValue = postorder[postR];
    Node* root = new Node(rootValue);

    int rootIndex = pos[rootValue];
    int leftSize = rootIndex - inL;

    root->left = buildRec(inorder, inL, rootIndex - 1,
                          postorder, postL, postL + leftSize - 1,
                          pos);

    root->right = buildRec(inorder, rootIndex + 1, inR,
                           postorder, postL + leftSize, postR - 1,
                           pos);

    return root;
}

Node* buildFromInPost(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size()) return nullptr;
    if (inorder.empty()) return nullptr;

    unordered_map<int, int> pos;
    for (int i = 0; i < (int)inorder.size(); i++) {
        pos[inorder[i]] = i;
    }

    return buildRec(inorder, 0, inorder.size() - 1,
                    postorder, 0, postorder.size() - 1,
                    pos);
}
```

Idea:

En postorden, el ultimo elemento siempre es la raíz del subarbol. En inorden, esa raíz separa subarbol izquierdo y derecho.

Complejidad:

- Tiempo: `O(n)`;
- Espacio adicional: `O(n)`.

## Ejercicio IV.4

```cpp
# include <algorithm>
# include <cmath>
# include <cstdlib>
# include <tuple>
using namespace std;

struct InfoAvl {
    bool balanced;
    int height;
    int count;
};

InfoAvl inspect(Node* root) {
    if (root == nullptr) {
        return {true, 0, 0};
    }

    InfoAvl left = inspect(root->left);
    InfoAvl right = inspect(root->right);

    int h = 1 + max(left.height, right.height);
    int n = 1 + left.count + right.count;
    bool ok = left.balanced &&
              right.balanced &&
              abs(left.height - right.height) <= 1;

    return {ok, h, n};
}

bool isAvlMinimo(Node* root) {
    InfoAvl info = inspect(root);
    int minHeight = (int)ceil(log2(info.count + 1));
    return info.balanced && info.height == minHeight;
}
```

Advertencia:

Esta función no solo pregunta si el árbol es AVL. Tambien exige que tenga altura minima teorica. Por eso un árbol AVL valido puede retornar `false`.

## Ejercicio IV.5

```cpp
# include <stack>
using namespace std;

int kthSmallest(Node* root, int k) {
    if (k <= 0) return -1;

    stack<Node*> st;
    Node* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        k--;
        if (k == 0) {
            return current->value;
        }

        current = current->right;
    }

    return -1;
}
```

Complejidad:

- Tiempo: `O(h + k)`;
- Espacio adicional: `O(h)`.

## Ejercicio IV.6

```cpp
int lowestCommonAncestor(Node* root, int a, int b) {
    Node* current = root;

    while (current != nullptr) {
        if (a < current->value && b < current->value) {
            current = current->left;
        } else if (a > current->value && b > current->value) {
            current = current->right;
        } else {
            return current->value;
        }
    }

    return -1;
}
```

Idea:

En un ABB, si ambos valores son menores que el nodo actual, el ancestro comun esta a la izquierda. Si ambos son mayores, esta a la derecha. El primer punto donde se separan es el ancestro comun más bajo.

Complejidad:

- Tiempo: `O(h)`;
- Espacio adicional: `O(1)`.

## Ejercicio IV.7

```cpp
int sumarTodosLosElementos(BNode* root) {
    if (root == nullptr) return 0;

    int sum = 0;

    for (int i = 0; i < root->keysUsed; i++) {
        sum += root->keys[i];
    }

    for (int i = 0; i <= root->keysUsed; i++) {
        sum += sumarTodosLosElementos(root->children[i]);
    }

    return sum;
}
```

Complejidad:

- Tiempo: `O(n)`, considerando `n` como cantidad total de claves;
- Espacio adicional: `O(h)` por recursión.

## Ejercicio IV.8

```cpp
# include <algorithm>
# include <queue>
# include <vector>
using namespace std;

vector<vector<int>> nivelesZigZag(Node* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            level.push_back(current->value);

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }

        if (!leftToRight) {
            reverse(level.begin(), level.end());
        }

        result.push_back(level);
        leftToRight = !leftToRight;
    }

    return result;
}
```

Complejidad:

- Tiempo: `O(n)`;
- Espacio adicional: `O(w)`, más el vector de salida.
