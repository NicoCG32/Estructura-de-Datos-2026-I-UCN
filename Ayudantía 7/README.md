# Ayudantía 7: Heaps y HeapSort

Esta ayudantía se centra en entender el heap como arreglo y en simular `HeapSort` paso a paso. La idea es separar este bloque de los recorridos de árboles binarios de la `Ayudantía 6`, porque aunque ambos usan árboles, resuelven problemas distintos.

## Objetivo del bloque

- entender qué es un `max-heap` y un `min-heap`;
- leer un heap como si fuera un árbol completo guardado en un arreglo;
- usar correctamente las fórmulas de índices `0-based` y `1-based`;
- comprender el algoritmo `HeapSort`;
- practicar la construcción y el ordenamiento paso a paso.

## Repaso teórico breve

Un heap es un árbol binario completo que cumple una propiedad de orden:

- en un `max-heap`, cada padre es mayor o igual que sus hijos;
- en un `min-heap`, cada padre es menor o igual que sus hijos.

Como el árbol es completo, puede guardarse de forma compacta en un arreglo sin usar punteros. Esa es la razón por la que heaps y arreglos trabajan tan bien juntos.

## Cómo leer un heap como arreglo

Si usamos indexación `0-based`, el arreglo se interpreta así:

```text
indice:   0   1   2   3   4   5   6
valor:   [20, 15, 18,  8, 10, 17, 16]
```

Ese arreglo representa este árbol:

```text
						20
					15      18
				8   10      17   16
```

La idea importante es esta: el índice marca la posición en el arreglo, y las fórmulas permiten saltar de un nodo a su padre o a sus hijos sin construir la estructura en memoria.

## Fórmulas de índices

### Caso `0-based`

Si el arreglo empieza en índice `0`:

- `parent(i) = (i - 1) / 2` para `i > 0`.
- `left(i) = 2 * i + 1`.
- `right(i) = 2 * i + 2`.

### Caso `1-based`

Si el arreglo empieza en índice `1`:

- `parent(i) = i / 2`.
- `left(i) = 2 * i`.
- `right(i) = 2 * i + 1`.

### Observación práctica

La diferencia entre `0-based` y `1-based` cambia solo las fórmulas, no la lógica del árbol. Lo importante es no mezclar ambos sistemas dentro del mismo ejercicio.

## Algoritmo HeapSort

`HeapSort` ordena un arreglo usando un heap, normalmente un `max-heap` si queremos obtener el arreglo en orden ascendente.

La idea general es:

1. construir un `max-heap` a partir del arreglo inicial;
2. intercambiar la raíz con el último elemento del heap;
3. reducir el tamaño efectivo del heap en `1`;
4. aplicar `heapify-down` desde la raíz para recuperar la propiedad de heap;
5. repetir hasta que no queden elementos por extraer.

### Complejidad

- construcción del heap: `O(n)`;
- ordenamiento total: `O(n log n)`;
- espacio adicional: `O(1)`.

`HeapSort` no es estable, pero es muy útil cuando se quiere ordenar sin usar espacio extra significativo.

## Implementación de referencia en Python

La siguiente versión es solo una referencia para entender el flujo del algoritmo. Trabaja con un `max-heap` y ordena el arreglo en forma ascendente.

```python
def heapify(arr, n, i):
    # Inicializa el nodo actual como el más grande
    largest = i  
    left = 2 * i + 1     # Hijo izquierdo
    right = 2 * i + 2    # Hijo derecho

    # Verifica si el hijo izquierdo existe y es mayor que la raíz
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Verifica si el hijo derecho existe y es mayor que el más grande hasta ahora
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Si el más grande no es la raíz, intercambia y continúa aplicando heapify
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Intercambio
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # 1. Construye el Max-Heap (reorganiza el arreglo)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # 2. Extrae elementos uno a uno del montículo
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Mueve la raíz actual al final
        heapify(arr, i, 0)               # Llama a heapify en el montículo reducido
```

## Ejercicio 1: leer un heap con indexación 0-based

Considera el siguiente arreglo:

```python
a = [19, 11, 17, 8, 10, 13, 15]
```

### Tareas

1. Dibujar el árbol correspondiente.
2. Indicar el padre de cada índice.
3. Indicar los hijos izquierdo y derecho de cada índice.
4. Verificar si el arreglo cumple la propiedad de `max-heap`.

### Consideraciones

- usa las fórmulas de `0-based` para identificar padres e hijos;
- dibuja el árbol antes de responder si cumple o no la propiedad de heap;
- revisa cada nodo interno, no solo la raíz.

## Ejercicio 2: leer un heap con indexación 1-based

Considera el siguiente arreglo donde la posición `0` se deja vacía:

```python
b = [0, 20, 14, 18, 9, 12, 16, 17]
```

### Tareas

1. Dibujar el árbol usando indexación `1-based`.
2. Calcular `parent`, `left` y `right` para los índices `1` a `7`.
3. Verificar si el arreglo cumple la propiedad de `max-heap`.

### Consideraciones

- en `1-based`, la posición `0` no se usa;
- verifica que las fórmulas cambien respecto del caso anterior;
- compara cada padre con sus hijos para validar la propiedad de heap.

## Ejercicio 3: HeapSort paso a paso con indexación 0-based

Ordena en forma ascendente el siguiente arreglo usando `HeapSort`:

```python
a = [4, 10, 3, 5, 1]
```

### Consideraciones

- primero debes construir el `max-heap` completo;
- después de cada intercambio, el último elemento ya queda fijo;
- en cada paso solo se reordena la parte activa del arreglo.

## Ejercicio 4: HeapSort paso a paso con indexación 1-based

Ordena en forma ascendente el siguiente arreglo:

```python
b = [0, 8, 3, 7, 1, 6, 4]
```

### Consideraciones

- aplica la versión `1-based` de las fórmulas durante toda la resolución;
- el arreglo usa una posición vacía al inicio solo para facilitar la indexación;
- trata el último segmento como el heap activo en cada iteración.

Resultado final en orden ascendente:

```text
[1, 3, 4, 6, 7, 8]
```

## Ejercicio 5: HeapSort paso a paso con un arreglo un poco más grande

Ordena el siguiente arreglo en forma ascendente:

```python
c = [12, 11, 13, 5, 6, 7, 9, 25, 31, 26, 17, 14]
```

### Consideraciones

- este ejercicio te pide varias iteraciones seguidas para consolidar el proceso;
- conviene anotar el heap activo en cada extracción;
- revisa bien el orden de los intercambios y del `heapify-down`.