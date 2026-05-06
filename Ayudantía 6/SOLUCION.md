# Ayudantia 6: Soluciones

Estas soluciones se concentran solo en recorridos de arboles binarios.

Se asume:

```cpp
using namespace std;
```

## Estructura base

```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};
```

Auxiliar visitar(Nodo):

```cpp
void visitar(TreeNode* node) {
    cout << node->data << " ";
}
```

---

## 1. DFS recursivos

### Idea general

En los recorridos DFS recursivos, la pila de llamadas del lenguaje ya modela el camino actual en el arbol.

La diferencia entre variantes esta solo en **cuando** se visita la raiz:

- inorden: izquierda, raiz, derecha;
- preorden: raiz, izquierda, derecha;
- postorden: izquierda, derecha, raiz.

### Implementacion

```cpp
void inordenRec(TreeNode* root) {
    if (root == nullptr) return;
    inordenRec(root->left);
    visitar(root);
    inordenRec(root->right);
}

void preordenRec(TreeNode* root) {
    if (root == nullptr) return;
    visitar(root);
    preordenRec(root->left);
    preordenRec(root->right);
}

void postordenRec(TreeNode* root) {
    if (root == nullptr) return;
    postordenRec(root->left);
    postordenRec(root->right);
    visitar(root);
}
```

### Complejidad

- Tiempo: `O(n)` en todos los casos.
- Espacio adicional: `O(h)` por la profundidad de recursion, donde `h` es la altura del arbol.

---

## 2. DFS iterativos

### Idea general

Aqui reemplazamos la recursion por una `stack<TreeNode*>`.

- en inorden se baja por un lado del arbol, apilando el camino;
- en preorden se procesa la raiz antes de apilar hijos;
- en postorden conviene usar dos pilas por claridad;

### Implementacion

```cpp
#include <stack>

void inordenIter(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        visitar(current);
        current = current->right;
    }
}

void preordenIter(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* current = st.top();
        st.pop();
        visitar(current);

        if (current->right != nullptr) st.push(current->right);
        if (current->left != nullptr) st.push(current->left);
    }
}

void postordenIter(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != nullptr) s1.push(current->left);
        if (current->right != nullptr) s1.push(current->right);
    }

    while (!s2.empty()) {
        visitar(s2.top());
        s2.pop();
    }
}
```

### Complejidad

- Tiempo: `O(n)` en todos los casos.
- Espacio adicional: `O(h)` en recorridos lineales por camino y hasta `O(n)` en las variantes con dos pilas.

---

## 3. BFS recursivo y BFS iterativo

### Idea general

En BFS se recorre por niveles.

La version iterativa natural usa `queue<TreeNode*>`.

La version recursiva no usa cola: primero calcula la altura y luego imprime nodo por nodo cada nivel, desde el nivel `1` hasta el nivel `h`.

### Helpers para la version recursiva

```cpp
int altura(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftHeight = altura(root->left);
    int rightHeight = altura(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void imprimirNivel(TreeNode* root, int nivel) {
    if (root == nullptr) return;

    if (nivel == 1) {
        visitar(root);
        return;
    }

    imprimirNivel(root->left, nivel - 1);
    imprimirNivel(root->right, nivel - 1);
}
```

### Implementacion

```cpp
#include <queue>

void bfsRec(TreeNode* root) {
    int h = altura(root);
    for (int nivel = 1; nivel <= h; ++nivel) {
        imprimirNivel(root, nivel);
    }
}

void bfsIter(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        visitar(current);

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}
```

### Complejidad

- BFS recursivo:
  - Tiempo: `O(n * h)` en esta implementacion por niveles.
  - Espacio adicional: `O(h)` por recursion.
- BFS iterativo:
  - Tiempo: `O(n)`.
  - Espacio adicional: `O(w)`, donde `w` es el maximo ancho del arbol.

---

## 4. Extra: BFS inverso

### Definicion

En este material, BFS inverso significa:

- imprimir primero el nivel mas profundo;
- mantener izquierda a derecha dentro de cada nivel.

### Version recursiva

Como ya tenemos `altura` e `imprimirNivel`, basta recorrer los niveles en orden inverso.

```cpp
void bfsInversoRec(TreeNode* root) {
    int h = altura(root);
    for (int nivel = h; nivel >= 1; --nivel) {
        imprimirNivel(root, nivel);
    }
}
```

### Version iterativa

Para mantener izquierda a derecha al imprimir desde abajo hacia arriba:

1. recorremos el arbol con cola;
2. apilamos cada nodo visitado;
3. encolamos primero `right` y luego `left`;
4. al desapilar, aparece el orden final correcto.

```cpp
void bfsInversoIter(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    stack<TreeNode*> st;

    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        st.push(current);

        if (current->right != nullptr) q.push(current->right);
        if (current->left != nullptr) q.push(current->left);
    }

    while (!st.empty()) {
        visitar(st.top());
        st.pop();
    }
}
```

### Complejidad

- BFS inverso recursivo:
  - Tiempo: `O(n * h)` con este enfoque por niveles.
  - Espacio adicional: `O(h)`.
- BFS inverso iterativo:
  - Tiempo: `O(n)`.
  - Espacio adicional: `O(n)`.

---