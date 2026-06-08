# I. Recorridos de Árboles

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque refuerza los conceptos de árbol, árbol binario y recorridos que aparecen en la parte teórica de PP2: raíz, grado, hojas, nivel, altura, profundidad, camino, preorden, inorden, postorden y recorrido por niveles.

## Índice para estudiar

Primera pasada sugerida:

- [I.1](#ejercicio-i1) | [I.2](#ejercicio-i2) | [I.4](#ejercicio-i4) | [I.6](#ejercicio-i6)

Segunda pasada sugerida:

- [I.3](#ejercicio-i3) | [I.5](#ejercicio-i5) | [I.7](#ejercicio-i7) | [I.9](#ejercicio-i9)

Banco completo:

- [I.1](#ejercicio-i1) | [I.2](#ejercicio-i2) | [I.3](#ejercicio-i3) | [I.4](#ejercicio-i4) | [I.5](#ejercicio-i5)
- [I.6](#ejercicio-i6) | [I.7](#ejercicio-i7) | [I.8](#ejercicio-i8) | [I.9](#ejercicio-i9) | [I.10](#ejercicio-i10)

## Estructura base para árbol binario

```cpp
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data) : data(data), left(nullptr), right(nullptr) {}
};
```

## Cómo estudiar este tema

Antes de programar:

- dibuja el árbol y marca raíz, hojas y niveles;
- separa claramente profundidad de altura;
- identifica si el árbol es general, binario o ABB;
- si el enunciado pide orden ascendente en un ABB, piensa en inorden;
- si el enunciado pide distancia mínima por niveles, piensa en cola.

### Ejercicio I.1

Considere el siguiente árbol general:

```text
              A
        /     |      \
       B      C       D
     /   \          / | \
    E     F        G  H  I
         /|\       |    / \
        J K L      M   N   O
                  / \
                 P   Q
```

Determine:

1. grado de `D`;
2. hojas del árbol;
3. hermanos de `B`;
4. camino de `A` a `J`;
5. longitud del camino de `A` a `J`;
6. nivel de `A` y de `H`, considerando raíz en nivel `1`;
7. altura del árbol;
8. altura y profundidad de `G`;
9. recorrido preorden;
10. recorrido postorden.

### Ejercicio I.2

Considere el siguiente árbol binario:

```text
          A
       /     \
      B       C
     / \     / \
    D   E   F   G
       / \
      H   I
```

Escriba:

1. preorden;
2. inorden;
3. postorden;
4. recorrido por niveles.

### Ejercicio I.3

Dado un árbol binario cuyos recorridos son:

```text
preorden = 8, 3, 1, 6, 4, 7, 10, 14, 13
inorden  = 1, 3, 4, 6, 7, 8, 10, 13, 14
```

Reconstruya el árbol y escriba su postorden.

### Ejercicio I.4

Implemente iterativamente:

```cpp
void printLevels(TreeNode* root);
```

La función debe imprimir el árbol por niveles, de izquierda a derecha. Debe usar `queue<TreeNode*>`.

### Ejercicio I.5

Implemente iterativamente:

```cpp
int countLeaves(TreeNode* root);
```

La función debe retornar la cantidad de hojas del árbol binario.

### Ejercicio I.6

Implemente iterativamente:

```cpp
int heightByLevels(TreeNode* root);
```

La función debe retornar la altura del árbol medida como cantidad de niveles. Si el árbol esta vacio, retorna `0`.

### Ejercicio I.7

El siguiente arreglo usa representacion por niveles con indexacion `1-based`:

```text
indice:  1   2   3   4   5   6
valor:  20  12  61  33  48  81
```

1. Dibuje el árbol representado.
2. Indique padre, hijo izquierdo e hijo derecho de cada índice cuando existan.
3. Explique por qué las formulas `left(i)=2i`, `right(i)=2i+1` y `parent(i)=i/2` funcionan solo bajo indexacion `1-based`.

### Ejercicio I.8

Para cada árbol, indique si es lleno, completo, ambos o ninguno:

```text
A)        1
        /   \
       2     3
      / \   / \
     4  5  6  7

B)        1
        /   \
       2     3
      / \
     4   5

C)        1
        /   \
       2     3
          \
           6
```

### Ejercicio I.9

Considere este ABB:

```text
          8
       /     \
      3       10
     / \        \
    1   6        14
       / \      /
      4   7    13
```

Complete una tabla con el predecesor y sucesor inorden de cada nodo. Use `nullptr` cuando no exista.

### Ejercicio I.10

Implemente el recorrido inorden iterativo:

```cpp
void inorderIter(TreeNode* root);
```

Debe usar `stack<TreeNode*>` y no recursión.

