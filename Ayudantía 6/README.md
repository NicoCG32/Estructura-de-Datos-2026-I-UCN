# Ayudantía 6: Recorridos de árboles binarios

En esta ayudantía veremos solo recorridos de árboles binarios.

## Repaso teórico breve

Antes de implementar recorridos, conviene fijar algunos conceptos básicos:

- Un árbol es una estructura jerárquica formada por nodos conectados por enlaces.
- La raíz es el nodo inicial del árbol.
- Cada nodo puede tener padre y hijos. Si dos nodos comparten padre, son hermanos.
- Un nodo sin hijos es una hoja.
- Un subárbol es cualquier nodo junto con todos sus descendientes.
- En un árbol binario, cada nodo puede tener a lo más dos hijos: `left` y `right`.
- El nivel o profundidad indica qué tan lejos está un nodo respecto de la raíz.
- La altura de un árbol indica la longitud del camino más largo desde la raíz hasta una hoja.

En recorridos hay dos ideas principales:

- DFS (`Depth-First Search`): explora primero en profundidad. Aquí aparecen inorden, preorden y postorden.
- BFS (`Breadth-First Search`): explora por niveles, de izquierda a derecha dentro de cada nivel.

La recursión encaja naturalmente con los árboles porque cada hijo puede verse como la raíz de un subárbol más pequeño.

## Objetivo

- Implementar recorridos recursivos e iterativos.
- Usar `stack` en recorridos iterativos.
- Usar `queue` en recorridos iterativos.

## Estructura base sugerida

```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};
```

## Instrucciones generales

- Todas las funciones reciben la raíz del árbol.
- Todas las funciones deben solo imprimir los valores separados por espacio o saltos de línea.
- Debes implementar cada recorrido en versión recursiva e iterativa.
- Para los DFS iterativos usa `stack<TreeNode*>`.
- Para BFS usa `queue<TreeNode*>`.

Puedes utilizar la siguiente función auxiliar:
```cpp
void visitar(TreeNode* node) {
    cout << node->data << " ";
}
```

## Árbol de referencia para probar recorridos

Usa este árbol como referencia para verificar tus funciones:

![Árbol Binario](Árbol%20Binario.png)

## Árbol implementado

```cpp
TreeNode* crearArbol() {
    TreeNode* raiz = new TreeNode(2);

    raiz->left = new TreeNode(7);
    raiz->right = new TreeNode(5);

    raiz->left->left = new TreeNode(2);
    raiz->left->right = new TreeNode(6);

    raiz->left->right->left = new TreeNode(5);
    raiz->left->right->right = new TreeNode(11);

    raiz->right->right = new TreeNode(9);
    raiz->right->right->left = new TreeNode(4);

    return raiz;
}

```

## Ejercicio único: implementar los recorridos

Debes implementar los siguientes recorridos sobre el árbol dado por `root`.

### DFS directos

```cpp
void inordenRec(TreeNode* root);
void inordenIter(TreeNode* root);

void preordenRec(TreeNode* root);
void preordenIter(TreeNode* root);

void postordenRec(TreeNode* root);
void postordenIter(TreeNode* root);
```

### BFS o recorrido por niveles

```cpp
void bfsIter(TreeNode* root);
```

### Extra: BFS inverso

Como extra, implementa el recorrido por niveles inverso:

- Se imprimen primero los niveles más profundos.
- Dentro de cada nivel, se mantiene el orden de izquierda a derecha.

```cpp
void bfsInversoIter(TreeNode* root);
```

## Salidas esperadas sobre el árbol de referencia

| Recorrido | Salida esperada |
| --- | --- |
| Inorden | `2 7 5 6 11 2 5 4 9` |
| Preorden | `2 7 2 6 5 11 5 9 4` |
| Postorden | `2 5 11 6 7 4 9 5 2` |
| BFS | `2 7 5 2 6 9 5 11 4` |
| BFS inverso | `5 11 4 2 6 9 7 5 2` |

## Cierre

Si puedes implementar y explicar bien estos recorridos, ya tendrás una base muy sólida para trabajar después con árboles binarios de búsqueda, heaps y estructuras jerárquicas en general.