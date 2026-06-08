# IV. Algoritmos con Árboles

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque contiene problemas con firma dada, similares a los que aparecen en pruebas: ABB con rango, reconstruccion desde recorridos, verificacion de AVL en una pasada, árbol B y recorridos iterativos.

## Índice para estudiar

Primera pasada sugerida:

- [IV.1](#ejercicio-iv1) | [IV.2](#ejercicio-iv2) | [IV.3](#ejercicio-iv3) | [IV.6](#ejercicio-iv6)

Segunda pasada sugerida:

- [IV.4](#ejercicio-iv4) | [IV.5](#ejercicio-iv5) | [IV.7](#ejercicio-iv7) | [IV.8](#ejercicio-iv8)

## Estructura base

```cpp
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};
```

### Ejercicio IV.1

Dado un ABB y un rango `[L, R]`, implemente:

```cpp
int sumaEnRangoABB(Node* root, int L, int R);
```

Debe sumar solo los valores dentro del rango. Use la propiedad ABB para podar subarboles.

### Ejercicio IV.2

Dado un AVL y tres enteros `K1`, `K2`, `K3`, implemente:

```cpp
vector<int> calcularSumas(Node* root, int K1, int K2, int K3);
```

Debe:

- obtener los valores del AVL dentro del rango `[K1, K2]`;
- generar todas las sumas posibles usando exactamente `K3` valores distintos;
- retornar las sumas ordenadas y sin duplicados.

### Ejercicio IV.3

Reconstruya un árbol binario a partir de sus recorridos:

```cpp
Node* buildFromInPost(vector<int>& inorder, vector<int>& postorder);
```

Puede usar recursión.

### Ejercicio IV.4

Implemente:

```cpp
bool isAvlMinimo(Node* root);
```

La función debe verificar en una sola pasada:

1. que el árbol cumple `abs(FB) <= 1`;
2. que la altura actual sea `ceil(log2(n + 1))`.

### Ejercicio IV.5

Implemente:

```cpp
int kthSmallest(Node* root, int k);
```

El árbol es un ABB. Si `k` es invalido, retorne `-1`.

### Ejercicio IV.6

Implemente:

```cpp
int lowestCommonAncestor(Node* root, int a, int b);
```

El árbol es un ABB y ambos valores existen. Retorne el valor del ancestro comun más bajo.

### Ejercicio IV.7

Para un árbol B representado como:

```cpp
class BNode {
public:
    int keysUsed;
    int* keys;
    BNode** children;
};
```

Implemente:

```cpp
int sumarTodosLosElementos(BNode* root);
```

### Ejercicio IV.8

Implemente:

```cpp
vector<vector<int>> nivelesZigZag(Node* root);
```

Debe retornar los niveles alternando izquierda-derecha y derecha-izquierda.

