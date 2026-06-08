# VII. Verdadero o Falso

Los enunciados de este tema se encuentran en [README.md](README.md).

## Respuestas

### Ejercicio VII.1

Verdadero. Un árbol representa jerarquía: raíz, hijos, subárboles y hojas.

### Ejercicio VII.2

Falso. DFS también se aplica a árboles. Un árbol puede verse como un grafo conexo y sin ciclos.

### Ejercicio VII.3

Verdadero. En un ABB, la subrama izquierda contiene menores y la derecha contiene mayores; por eso el recorrido inorden produce orden ascendente.

### Ejercicio VII.4

Falso. Un AVL usa factores de balance y rotaciones. Un heap usa comparación padre-hijo y no factores de balance AVL.

### Ejercicio VII.5

Verdadero. El heap solo garantiza que el padre sea mayor o menor que sus hijos, según sea max-heap o min-heap.

### Ejercicio VII.6

Verdadero. En una matriz, el arco `u -> v` se consulta directamente en `matrix[u][v]`.

### Ejercicio VII.7

Verdadero. Un grafo puede tener componentes desconectadas.

### Ejercicio VII.8

Verdadero, si la profundidad se mide como cantidad de niveles con raíz en nivel `1`.

### Ejercicio VII.9

Falso. Todo árbol lleno es completo, pero no todo árbol completo es lleno.

### Ejercicio VII.10

Verdadero. En grafos dirigidos, las aristas entrantes y salientes se cuentan por separado.

### Ejercicio VII.11

Verdadero. Las hebras suelen apuntar a predecesor o sucesor inorden.

### Ejercicio VII.12

Verdadero. También se conoce como self-loop.

### Ejercicio VII.13

Falso. HeapSort no es estable porque realiza intercambios lejanos que pueden invertir elementos iguales.

### Ejercicio VII.14

Verdadero. La cola permite procesar por capas.

### Ejercicio VII.15

Verdadero. La pila modela el comportamiento LIFO de la exploración en profundidad.

### Ejercicio VII.16

Verdadero. Si el ABB queda como una lista, la altura pasa a ser `n`.

### Ejercicio VII.17

Verdadero. El balance AVL mantiene altura `O(log n)`.

### Ejercicio VII.18

Falso. En una lista de arcos hay que recorrer los arcos para encontrar los que salen de un vértice, salvo que exista un índice auxiliar.

### Ejercicio VII.19

Verdadero. Conexo y acíclico caracteriza a los árboles no dirigidos.

### Ejercicio VII.20

Falso. En indexación `0-based`, el hijo izquierdo está en `2*i + 1`.
