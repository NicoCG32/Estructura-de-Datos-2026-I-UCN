# Intensiva II - Estructuras de Datos PP2

Material de práctica enfocado exclusivamente en los cuatro pilares solicitados:

1. HeapSort, tratado como algoritmo manual.
2. AVL, tratado como algoritmo manual mediante dibujo, factores de balance y rotaciones.
3. Algoritmos de árboles.
4. Algoritmos de grafos usando las tres representaciones vistas en el curso:
   - matriz de adyacencia,
   - lista de adyacencia,
   - lista de arcos / edges.

---

## Ejercicio 1 - HeapSort manual

Dado el siguiente arreglo:

```txt
[16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
```

Ordene los datos de menor a mayor utilizando **HeapSort**.

### Se pide

1. Construir el Max-Heap paso a paso.
2. Mostrar cada intercambio realizado en la construcción del heap.
3. Mostrar cada extracción del máximo.
4. Mostrar el arreglo resultante después de cada `heapify`.
5. Indicar la complejidad temporal.

### Ejemplo de entrada

```txt
10
16 4 10 14 7 9 3 2 8 1
```

### Ejemplo de salida esperada

```txt
Arreglo ordenado:
1 2 3 4 7 8 9 10 14 16
```

### Consideraciones mínimas

- Se trabaja con arreglo indexado desde 1 para facilitar el dibujo.
- El primer `heapify` se aplica desde `n/2` hasta `1`.
- No se pide implementar código, sino dibujar y explicar el proceso.

---

## Ejercicio 2 - AVL manual con inserción y eliminación

Dado un árbol AVL inicialmente vacío, inserte los siguientes valores:

```txt
50, 30, 70, 20, 40, 35, 45, 80, 75
```

Luego elimine, en este orden:

```txt
20, 70, 30
```

### Se pide

1. Dibujar el AVL después de cada inserción.
2. Indicar el factor de balance de los nodos relevantes.
3. Identificar el primer nodo desbalanceado cuando corresponda.
4. Aplicar y nombrar la rotación necesaria.
5. Dibujar el AVL después de cada eliminación.
6. En eliminación, si el nodo posee dos hijos, reemplazar por el **menor de los mayores**.

### Ejemplo de entrada

```txt
Insercion:
50 30 70 20 40 35 45 80 75

Eliminacion:
20 70 30
```

### Ejemplo de salida esperada

```txt
Árbol AVL final:
        50
       /  \
     40    75
    /  \     \
  35   45     80
```

### Consideraciones mínimas

- Use `FB(nodo) = altura(izquierdo) - altura(derecho)`.
- Se deben reconocer e incicar los casos LL, RR, LR y RL.
- No se pide implementar código.

---

## Ejercicio 3 - Árbol ABB: suma condicionada en rango

Dado el siguiente árbol binario de búsqueda:

```txt
          10
        /    \
       5      15
      / \    /  \
     3   7  13   18
        /     \
       6       14
```

Calcule la suma de los nodos que cumplen simultáneamente:

1. El valor está dentro del rango `[6, 15]`.
2. El valor **no** es múltiplo de 5.

Debe implementar:

```cpp
int sumaRangoABB(TreeNode* root, int low, int high);
```

### Ejemplo de entrada

```txt
low = 6
high = 15
```

### Ejemplo de salida esperada

```txt
40
```

### Explicación breve

Los valores dentro del rango son:

```txt
6, 7, 10, 13, 14, 15
```

Se excluyen los múltiplos de 5:

```txt
10, 15
```

Entonces:

```txt
6 + 7 + 13 + 14 = 40
```

### Consideraciones mínimas

- Debe aprovechar la propiedad del ABB.
- La solución principal debe ser iterativa.
- Puede adjuntar una solución recursiva alternativa.
- No usar estructuras avanzadas no vistas.

---

## Ejercicio 4 - Árbol binario: recorrido zigzag con suma por nivel

Dado el siguiente árbol binario:

```txt
          8
        /   \
       3     10
      / \      \
     1   6      14
        / \    /
       4   7  13
```

Realice un recorrido por niveles en formato **zigzag**:

- Nivel 1: izquierda a derecha.
- Nivel 2: derecha a izquierda.
- Nivel 3: izquierda a derecha.
- Nivel 4: derecha a izquierda.
- Y así sucesivamente.

Además, calcule la suma de cada nivel e indique cuál nivel posee la mayor suma.

Debe implementar:

```cpp
void zigzagConSuma(TreeNode* root);
```

### Ejemplo de salida esperada

```txt
Nivel 1: 8 | suma = 8
Nivel 2: 10 3 | suma = 13
Nivel 3: 1 6 14 | suma = 21
Nivel 4: 13 7 4 | suma = 24

Nivel con mayor suma: 4
Mayor suma: 24
```

### Consideraciones mínimas

- No usar recursión como solución principal.
- No usar `deque`.
- Se debe respetar el orden zigzag al imprimir.
---

## Ejercicio 5 - Grafo con matriz de adyacencia

Ejercicio basado en recorridos BFS, usando **matriz de adyacencia**.

Considere los vértices:

```txt
A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7
```

Y la siguiente matriz de adyacencia no dirigida:

```txt
    A B C D E F G H
A [ 0 1 1 0 0 0 0 0 ]
B [ 1 0 0 1 0 0 0 0 ]
C [ 1 0 0 1 1 0 0 0 ]
D [ 0 1 1 0 0 1 0 0 ]
E [ 0 0 1 0 0 1 0 1 ]
F [ 0 0 0 1 1 0 1 0 ]
G [ 0 0 0 0 0 1 0 1 ]
H [ 0 0 0 0 1 0 1 0 ]
```

Se desea encontrar el camino con menor cantidad de arcos desde `A` hasta `H`, pero el vértice `E` está bloqueado y no puede ser visitado.

Debe implementar:

```cpp
vector<int> caminoBFSMatriz(vector<vector<int> > matriz, int origen, int destino, int bloqueado);
```

### Ejemplo de entrada

```txt
origen = A
destino = H
bloqueado = E
```

### Ejemplo de salida esperada

```txt
Camino:
A B D F G H

Distancia:
5
```

### Consideraciones mínimas

- Usar BFS con `queue`.
- Usar arreglo/vector de visitados.
- Usar arreglo/vector de padres para reconstruir el camino.
- No visitar el vértice bloqueado.

---

## Ejercicio 6 - Grafo con lista de adyacencia

Ejercicio inspirado en **Keys and Rooms**.

Existen 6 salas numeradas del `0` al `5`. Cada sala contiene llaves para abrir otras salas. La información se entrega como lista de adyacencia:

```txt
sala 0: 1, 2
sala 1: 3
sala 2: 4
sala 3: 5
sala 4:
sala 5:
```

Desde la sala `0`, determine si es posible visitar todas las salas.

Debe implementar:

```cpp
bool puedeVisitarTodas(vector<vector<int> > rooms);
```

### Ejemplo de entrada

```txt
rooms = {
  {1, 2},
  {3},
  {4},
  {5},
  {},
  {}
}
```

### Ejemplo de salida esperada

```txt
true
```

### Consideraciones mínimas

- No usar recursión como solución principal.
- Marcar una sala como visitada apenas se descubre.
- La lista de adyacencia representa las llaves encontradas en cada sala.

---

## Ejercicio 7 - Grafo con lista de arcos: existencia de camino

Ejercicio inspirado en **Find if Path Exists in Graph**.

Se entrega un grafo no dirigido mediante una lista enlazada de arcos:

```cpp
class EdgeNode {
public:
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination) {
        this->source = source;
        this->destination = destination;
        this->next = nullptr;
    }
};
```

Los arcos son:

```txt
0 - 1
0 - 2
1 - 4
2 - 3
3 - 5
4 - 5
```

Determine si existe camino desde `0` hasta `5`. Además, reconstruya un camino válido.

Debe implementar:

```cpp
vector<int> caminoListaArcos(EdgeNode* head, int n, int origen, int destino);
```

### Ejemplo de entrada

```txt
n = 6
origen = 0
destino = 5
```

### Ejemplo de salida esperada

```txt
Existe camino:
true

Camino:
0 1 4 5
```

### Consideraciones mínimas

- La estructura base debe ser lista de arcos.
- Para conocer los vecinos de un nodo, se recorre la lista de arcos.
- Como el grafo es no dirigido, un arco `a-b` sirve tanto desde `a` hacia `b` como desde `b` hacia `a`.

---

## Ejercicio 8 - Grafo mixto: orden de cursos con dependencias

Ejercicio inspirado en **Course Schedule** y ordenamiento topológico.

Se tienen cursos numerados del `0` al `5`. Cada arco dirigido `u -> v` significa:

```txt
Para tomar el curso v, primero se debe aprobar el curso u.
```

Arcos:

```txt
0 -> 1
0 -> 2
1 -> 3
2 -> 3
3 -> 4
4 -> 5
```

Determine si es posible completar todos los cursos. Si es posible, entregue un orden válido.

Debe implementar:

```cpp
bool ordenCursos(EdgeNode* head, int numCursos, vector<int>& orden);
```

### Ejemplo de entrada

```txt
numCursos = 6
arcos = {
  0->1,
  0->2,
  1->3,
  2->3,
  3->4,
  4->5
}
```

### Ejemplo de salida esperada

```txt
true

Orden posible:
0 1 2 3 4 5
```

### Consideraciones mínimas

- Usar lista de arcos como entrada.
- Calcular grado de entrada de cada curso.
- Si no se procesan todos los cursos, existe ciclo.

---

## Resumen de cobertura

| Ejercicio | Tema | Representación / enfoque |
|---|---|---|
| 1 | HeapSort | Manual, Max-Heap |
| 2 | AVL | Manual, inserción y eliminación |
| 3 | ABB | Stack + poda por propiedad ABB |
| 4 | Árbol binario | Queue + zigzag + suma por nivel |
| 5 | Grafo | Matriz de adyacencia + BFS |
| 6 | Grafo | Lista de adyacencia + DFS iterativo |
| 7 | Grafo | Lista de arcos + BFS |
| 8 | Grafo | Lista de arcos + lista de adyacencia + BFS topológico |