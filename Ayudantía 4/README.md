# Ayudantía 4: Complejidad en algoritmos

## Ejercicio 1: Suma de dos listas de dígitos

Problema de repaso:

Se entregan dos listas simplemente enlazadas, donde cada nodo almacena un dígito de un número entero no negativo. Los dígitos están en orden inverso, es decir, la cabeza de la lista representa la unidad. Debes retornar una nueva lista enlazada con la suma de ambos números.

```cpp
Node* sumarListas(Node* l1, Node* l2);
```

Ejemplos de ejecución:

| Input | Output |
|-------|--------|
| l1: `2 -> 4 -> 3` (342), l2: `5 -> 6 -> 4` (465) | `7 -> 0 -> 8` (807) |
| l1: `9 -> 9 -> 9` (999), l2: `1` (1) | `0 -> 0 -> 0 -> 1` (1000) |
| l1: `0`, l2: `0` | `0` |

---

## Complejidad

La complejidad algorítmica es el análisis que nos permite estimar qué tan eficiente es un algoritmo en términos de dos dimensiones:

- Tiempo: cuánto crece la cantidad de operaciones cuando aumenta el tamaño de la entrada.
- Espacio: cuánta memoria adicional necesita el algoritmo.

Si llamamos n al tamaño de la entrada, solemos expresar:

- T(n): complejidad temporal.
- S(n): complejidad espacial.

Ambas funciones, generalmente de formas polinómicas en términos de n.

En análisis asintótico nos interesa el comportamiento para n grande (tendiendo a infinito), por eso se omiten constantes y términos menores.

Ejemplos:

- O(20) = O(1)
- O(20n) = O(n)
- O(n + 5) = O(n)

Órdenes comunes:

- Constante: O(1)
- Logarítmica: O(log n)
- Lineal: O(n)
- Cuadrática: O(n^2)

### Complejidad en espacio

- O(1): memoria adicional constante.
    Ejemplo explicado: para verificar si una cadena de parentesis es valida usando un contador simple para un caso restringido, solo ocupas variables como `abiertos` y `cerrados`. Aunque la entrada tenga 10 o 10.000 caracteres, la memoria extra no crece con n.

- O(n): memoria proporcional a la entrada.
    Ejemplo explicado: si copias todos los elementos de una lista enlazada a un `vector<int>`, al duplicarse la cantidad de datos de entrada, tambien se duplica la memoria adicional del vector.

- O(n^2): memoria cuadratica.
    Ejemplo explicado: una matriz de adyacencia para un grafo de n nodos usa n filas y n columnas. Si n pasa de 100 a 200, la memoria no se duplica: se multiplica aproximadamente por 4.

### Complejidad en tiempo

Para medir tiempo, definimos una operación activa y contamos cuántas veces se ejecuta.

- O(1): numero fijo de operaciones.
    Ejemplo explicado: leer el primer elemento de una cola (`front`) cuesta lo mismo con 5 o con 5.000 elementos, porque no depende de n.

- O(n): una pasada completa sobre la estructura.
    Ejemplo explicado: para contar cuantas piezas `A` y `B` hay en una linea, revisas cada caracter una vez. Si la linea duplica su largo, el trabajo tambien se duplica.

- O(log n): se reduce el problema por factores constantes en cada paso.
    Ejemplo explicado: en busqueda binaria, cada comparacion descarta la mitad del arreglo. Con 1.024 elementos se requieren cerca de 10 pasos, no 1.024.

- O(n^2): doble recorrido anidado.
    Ejemplo explicado: comparar todos contra todos con dos `for` anidados en un arreglo de n elementos hace aproximadamente n * n comparaciones.

- O(k^n): crecimiento exponencial.
    Ejemplo explicado: si en cada paso tienes k decisiones posibles y haces n pasos, el arbol de posibilidades tiene k^n caminos. Con k = 2 y n = 20 ya son 1.048.576 casos.

- O(n!): crecimiento factorial.
    Ejemplo explicado: en problemas de permutaciones (como probar todos los ordenes posibles de n tareas), para 5 elementos hay 120 casos, para 10 hay 3.628.800. Crece mas rapido que cualquier polinomio.

---

## Ejercicio 2: Lectura de algoritmos, Listas, Pilas y Colas

Implemente la función `filtrar_patron_multiple` que gestiona y reordena una secuencia de valores enteros basándose en dos patrones:

- Factor de frecuencia (**F**)
- Umbral de valor (**U**)

La función debe procesar la cola Q_datos (que contiene los valores enteros) en una única pasada (sin volver a recorrer). Los elementos que caen en un índice múltiplo de F deben ser apilados en la pila P_frecuencia. Los elementos restantes se deben encolar en la cola Q_filtrada, pero solo si su valor es mayor o igual que U. Si un elemento es menor que U, el valor a agregar en Q_filtrada debe ser reemplazado por un elemento de la pila P_frecuencia (si esta no está vacía); si la pila está vacía, el elemento se descarta. Finalmente, todos los elementos restantes en la pila P_frecuencia deben ser invertidos en su orden y transferidos al final de la cola Q_filtrada. La función debe devolver el número total de veces que se realizó un reemplazo exitoso y debe ejecutarse en tiempo lineal O(n) utilizando espacio constante O(1).

```cpp
int filtrar_patron_multiple(queue<int> Q_datos, stack<int> P_frecuencia,
                            queue<int> Q_filtrada, int U, int F);
```

| Caso | Q_datos                      | P_frecuencia | Q_filtrada | U | F | Salida |
| ---- | ---------------------------- | ------------ | ---------- | - | - | ------ |
| 1    | `[10, 3, 5, 8, 2, 12, 4, 9]` | `[]`         | `[]`       | 7 | 3 | `2`    |
| 2    | `[1, 20, 3, 40, 5, 6, 7]`    | `[]`         | `[]`       | 5 | 2 | `1`    |

---

## Ejercicio 3: Interpretación de algoritmos

En una línea de ensamblaje se reciben 2 tipos de piezas (**A** y **B**). Para poder armar un objeto se debe recibir una pieza **A** y luego una pieza **B** (no necesariamente de manera consecutiva pero sí en ese orden).

Si llegan varias piezas **A** de manera consecutiva, estas pueden almacenarse de manera temporal en una caja a la espera de la llegada de piezas **B**. Si llega una pieza **B** y no existen piezas **A** almacenadas debe arrojarse un error. Si al terminar de procesar las piezas sobra alguna pieza **A** también debe arrojarse un error.

Se sabe de antemano el orden en que llegarán todas las piezas. Debes implementar un algoritmo en **C++** que reciba el orden en que llegarán las piezas e indique si ocurrirá un error en la línea de ensamblaje o no.

```cpp
bool estadoLineaEnsamblaje(string linea);
```

| Entrada     | Salida | Explicación |
|------------|--------|------------|
| ABAABAABBB | true   | Siempre que llega una pieza B existe una pieza A almacenada para ensamblar y todas las piezas son utilizadas |
| AAABB      | false  | Queda una pieza A almacenada sin utilizar |
| ABBA       | false  | Al llegar la segunda pieza B no hay ninguna pieza A almacenada |

---

## Ejercicio 4: Generar números binarios

Problema:

Dado un entero positivo `n`, genera los primeros `n` números binarios en orden creciente. El resultado debe quedar almacenado en una lista o vector de salida.

Firma:
```cpp
vector<string> generarBinarios(int n);
```

Ejemplos de ejecución:

| Input | Output |
|-------|--------|
| `1` | `1` |
| `3` | `1, 10, 11` |
| `7` | `1, 10, 11, 100, 101, 110, 111` |

---

## Ejercicio 5: Guardar estados

Implemente una función que decodifique cadenas con el formato:
```text
K[text]
```
Donde `K` es un entero positivo y `text` se repite `K` veces.  
La cadena puede contener **anidamiento**
```text
Ej: K1[text1K2[text2K3...[...]]].
```

Firma:
```cpp
string decodeString(string s);
```

Ejemplos de ejecución:

| Entrada | Salida |
|--------|--------|
| `5[abcd]` | `abcdabcdabcdabcdabcd` |
| `3[ab2[cd]]` | `abcdcdabcdcdabcdcd` |

Consideraciones:

- Solución **iterativa (sin recursión)**
- `text` contiene solo letras (`a-z`, `A-Z`)
- Si aparece un número, siempre precede a `[`
- Puedes usar `isdigit(c)` para detectar números

---

## Ejercicio 6: Más estados

Implemente una función que determine si una cadena `p2` puede obtenerse reordenando los caracteres de `p1`, es decir, si ambas son **anagramas**.

Firma:
```cpp
bool esAnagrama(string p1, string p2);
```

Consideraciones:

- Solución **iterativa (sin recursión)**
- Debes considerar la **frecuencia** de cada carácter

Ejemplos de salida:

| Entrada | Salida |
|--------|--------|
| `("roma", "amor")` | `true` |
| `("listen", "silent")` | `true` |
| `("hola", "halo")` | `true` |
| `("aabb", "abbb")` | `false` |
| `("abc", "abcc")` | `false` |