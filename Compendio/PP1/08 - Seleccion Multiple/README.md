# VIII. Seleccion Multiple

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene usarlo como control de teoría una vez que ya practicaste ejercicios largos. No estudies estas preguntas como trivia: la meta es que puedas justificar por qué una opción es correcta y por qué las demás no lo son.

## Índice para estudiar

Primera pasada sugerida:

- [VIII.1](#ejercicio-viii1) | [VIII.3](#ejercicio-viii3) | [VIII.4](#ejercicio-viii4) | [VIII.5](#ejercicio-viii5)

Segunda pasada sugerida:

- [VIII.2](#ejercicio-viii2) | [VIII.6](#ejercicio-viii6) | [VIII.7](#ejercicio-viii7) | [VIII.9](#ejercicio-viii9)

Banco completo:

- [VIII.1](#ejercicio-viii1) | [VIII.2](#ejercicio-viii2) | [VIII.3](#ejercicio-viii3) | [VIII.4](#ejercicio-viii4) | [VIII.5](#ejercicio-viii5)
- [VIII.6](#ejercicio-viii6) | [VIII.7](#ejercicio-viii7) | [VIII.8](#ejercicio-viii8) | [VIII.9](#ejercicio-viii9) | [VIII.10](#ejercicio-viii10)
- [VIII.11](#ejercicio-viii11) | [VIII.12](#ejercicio-viii12) | [VIII.13](#ejercicio-viii13) | [VIII.14](#ejercicio-viii14) | [VIII.15](#ejercicio-viii15)
- [VIII.16](#ejercicio-viii16) | [VIII.17](#ejercicio-viii17) | [VIII.18](#ejercicio-viii18) | [VIII.19](#ejercicio-viii19) | [VIII.20](#ejercicio-viii20)

## Como estudiar este tema

En cada pregunta, marque la alternativa correcta y luego justifíquela en una frase. Si puede explicar por qué al menos dos distractores son incorrectos, entonces ya está usando la pregunta como estudio y no solo como chequeo rápido.

### Ejercicio VIII.1

¿Qué almacena una variable de tipo `int*`?

A. Un entero.
B. La dirección de memoria de un entero.
C. Un arreglo completo de enteros.
D. Un valor booleano.
E. Un objeto de tipo referencia.

### Ejercicio VIII.2

Si `int v[5];` y `int* p = v;`, ¿cuál expresión accede al tercer elemento del arreglo?

A. `*p + 2`
B. `*(p + 2)`
C. `&p[2]`
D. `p + 2`
E. `**p`

### Ejercicio VIII.3

¿Cuál es la principal diferencia entre un método `virtual` y uno no `virtual` en herencia?

A. El método `virtual` solo puede usarse con objetos estáticos.
B. El método no `virtual` siempre ejecuta la versión de la clase derivada.
C. El método `virtual` permite despacho dinámico según el tipo real del objeto.
D. El método `virtual` no puede redefinirse.
E. El método no `virtual` obliga a usar `new`.

### Ejercicio VIII.4

Si se tiene `Padre* p = new Hijo();`, ¿qué condición es importante para liberar correctamente el objeto con `delete p;`?

A. Que `Hijo` no tenga constructor.
B. Que `Padre` tenga destructor virtual.
C. Que `Padre` tenga todos sus métodos `private`.
D. Que `Hijo` no sobrescriba métodos.
E. Que `p` sea una referencia y no un puntero.

### Ejercicio VIII.5

¿Cuál de las siguientes estructuras implementa naturalmente una política LIFO?

A. `queue`
B. `list`
C. `stack`
D. `vector`
E. `pair`

### Ejercicio VIII.6

En una cola (`queue`), ¿qué operación permite consultar el primer elemento sin eliminarlo?

A. `top()`
B. `back()`
C. `peek()`
D. `front()`
E. `head()`

### Ejercicio VIII.7

En una lista enlazada simple sin puntero al último nodo, ¿cuál es la complejidad de insertar al final?

A. `O(1)`
B. `O(log n)`
C. `O(n)`
D. `O(n log n)`
E. `O(n^2)`

### Ejercicio VIII.8

¿Cuál es la complejidad temporal de un doble `for` anidado que recorre `n` elementos en ambos ciclos?

A. `O(1)`
B. `O(log n)`
C. `O(n)`
D. `O(n^2)`
E. `O(2^n)`

### Ejercicio VIII.9

¿Qué ocurre en C++ cuando una función recibe un objeto por valor?

A. Siempre trabaja sobre el objeto original.
B. Se crea una copia del objeto.
C. El objeto pasa automáticamente por puntero.
D. El objeto se mueve al heap.
E. La función no puede modificar nada.

### Ejercicio VIII.10

Si un algoritmo procesa cada elemento de una lista una sola vez y en cada paso realiza trabajo constante, su complejidad temporal es:

A. `O(1)`
B. `O(log n)`
C. `O(n)`
D. `O(n^2)`
E. `O(n!)`

### Ejercicio VIII.11

¿Qué operador permite obtener la dirección de memoria de una variable?

A. `*`
B. `&`
C. `->`
D. `::`
E. `%`

### Ejercicio VIII.12

¿Cuál estructura es más natural para modelar una política FIFO?

A. `stack`
B. `queue`
C. `pair`
D. `set`
E. `map`

### Ejercicio VIII.13

Si una clase derivada redefine correctamente un método virtual de la base, se habla de:

A. sobrecarga
B. encapsulamiento
C. `override`
D. slicing
E. casting

### Ejercicio VIII.14

¿Cuál es la complejidad de recorrer completamente una lista enlazada de `n` nodos?

A. `O(1)`
B. `O(log n)`
C. `O(n)`
D. `O(n^2)`
E. `O(2^n)`

### Ejercicio VIII.15

¿Qué operación consulta el tope de una pila sin eliminarlo?

A. `peek()`
B. `front()`
C. `top()`
D. `back()`
E. `head()`

### Ejercicio VIII.16

¿Cuál afirmación es correcta sobre `delete[]`?

A. Libera memoria reservada con `new`.
B. Libera memoria reservada con `new[]`.
C. Solo puede usarse con objetos automáticos.
D. Reemplaza a `free`.
E. No existe en C++.

### Ejercicio VIII.17

¿Cuál es la complejidad temporal de insertar al inicio de una lista enlazada simple?

A. `O(1)`
B. `O(log n)`
C. `O(n)`
D. `O(n log n)`
E. `O(n^2)`

### Ejercicio VIII.18

Si un método no es virtual, una llamada a través de un puntero base se resuelve según:

A. el tipo real del objeto
B. el último objeto creado
C. el tipo estático del puntero
D. el constructor más reciente
E. el destructor base

### Ejercicio VIII.19

¿Qué estructura es más adecuada para validar paréntesis balanceados?

A. `queue`
B. `stack`
C. `vector`
D. `pair`
E. `map`

### Ejercicio VIII.20

Si un ciclo divide el problema por `2` en cada iteración, la complejidad temporal típica es:

A. `O(1)`
B. `O(log n)`
C. `O(n)`
D. `O(n^2)`
E. `O(n!)`

---
