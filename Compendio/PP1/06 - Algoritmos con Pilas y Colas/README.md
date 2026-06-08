# VI. Algoritmos con Pilas y Colas

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene estudiarlo después de listas enlazadas o en paralelo con ellas. La clave aquí es que no uses la estructura "porque sí": debes explicar qué estado guarda una pila o una cola y por qué esa política de acceso representa bien el problema.

## Índice para estudiar

Primera pasada sugerida:

- [VI.1](#ejercicio-vi1) | [VI.2](#ejercicio-vi2) | [VI.4](#ejercicio-vi4) | [VI.6](#ejercicio-vi6)

Segunda pasada sugerida:

- [VI.5](#ejercicio-vi5) | [VI.7](#ejercicio-vi7) | [VI.8](#ejercicio-vi8) | [VI.9](#ejercicio-vi9)

Banco completo:

- [VI.1](#ejercicio-vi1) | [VI.2](#ejercicio-vi2) | [VI.3](#ejercicio-vi3) | [VI.4](#ejercicio-vi4) | [VI.5](#ejercicio-vi5)
- [VI.6](#ejercicio-vi6) | [VI.7](#ejercicio-vi7) | [VI.8](#ejercicio-vi8) | [VI.9](#ejercicio-vi9) | [VI.10](#ejercicio-vi10)
- [VI.11](#ejercicio-vi11) | [VI.12](#ejercicio-vi12) | [VI.13](#ejercicio-vi13) | [VI.14](#ejercicio-vi14) | [VI.15](#ejercicio-vi15)
- [VI.16](#ejercicio-vi16) | [VI.17](#ejercicio-vi17) | [VI.18](#ejercicio-vi18) | [VI.19](#ejercicio-vi19) | [VI.20](#ejercicio-vi20)

## Como estudiar este tema

Antes de pasar a la pauta:

- describa con una frase qué representa la estructura en ese problema;
- simule el algoritmo con un ejemplo pequeño y anote cada `push`, `pop`, `enqueue` o `dequeue`;
- justifique por qué una pila o una cola modela mejor el estado que otra estructura;
- cierre siempre con complejidad temporal y espacial.

### Ejercicio VI.1

```cpp
string invertirCadena(string texto);
```

Use una `stack<char>` para invertir una cadena de texto.

### Ejercicio VI.2

```cpp
bool parentesisBalanceados(string expr);
```

Use una pila para verificar si una expresión tiene paréntesis correctamente balanceados.

### Ejercicio VI.3

```cpp
bool esPalindromo(string s);
```

Use una pila para determinar si una cadena es palíndroma.

### Ejercicio VI.4

```cpp
vector<string> generarBinarios(int n);
```

Use una `queue<string>` para generar los primeros `n` números binarios en orden creciente.

### Ejercicio VI.5

```cpp
string decodeString(string s);
```

Use pilas para decodificar cadenas del tipo `K[text]`, permitiendo anidamiento.

### Ejercicio VI.6

```cpp
bool estadoLineaEnsamblaje(string linea);
```

En una línea llegan piezas `A` y `B`. Para armar un objeto debe aparecer una `A` antes que una `B`. Use una estructura adecuada para modelar el estado y determine si ocurre error.

### Ejercicio VI.7

```cpp
int filtrar_patron_multiple(queue<int>& Q_datos, stack<int>& P_frecuencia,
                            queue<int>& Q_filtrada, int U, int F);
```

Procese `Q_datos` en una sola pasada:

- los índices múltiplos de `F` van a `P_frecuencia`;
- si un valor no supera el umbral `U`, intente reemplazarlo usando la pila;
- al final, transfiera los elementos restantes de la pila a la cola filtrada respetando lo pedido por el enunciado.

### Ejercicio VI.8

```cpp
void intercalarMitades(queue<int>& q);
```

Dada una cola de tamaño par, intercale la primera mitad con la segunda mitad.

Ejemplo:

```text
[1,2,3,4,5,6] -> [1,4,2,5,3,6]
```

### Ejercicio VI.9

Diseñe una estructura que permita:

- visitar una página;
- volver atrás;
- avanzar;
- mostrar la página actual.

La solución debe usar **dos pilas** y explicar qué representa cada una.

### Ejercicio VI.10

```cpp
int evaluarRPN(vector<string> tokens);
```

Evalúe una expresión en notación polaca inversa usando una pila.

Ejemplo:

```text
["2","1","+","3","*"] -> 9
```

### Ejercicio VI.11

```cpp
void reverseQueue(queue<int>& q);
```

Use una pila auxiliar para invertir completamente una cola.

### Ejercicio VI.12

```cpp
string decimalABinario(int n);
```

Convierta un entero positivo a su representación binaria usando una pila.

### Ejercicio VI.13

```cpp
bool balanceadoGeneral(string s);
```

Use una pila para validar `()`, `[]` y `{}` correctamente anidados.

### Ejercicio VI.14

```cpp
stack<int> copyStack(stack<int> s);
```

Construya una copia de una pila manteniendo intacta la original al finalizar.

### Ejercicio VI.15

```cpp
queue<int> intercalarColas(queue<int> a, queue<int> b);
```

Construya una nueva cola intercalando los elementos de `a` y `b`.

### Ejercicio VI.16

```cpp
void duplicarCola(queue<int>& q);
```

Transforme una cola de manera que cada elemento aparezca dos veces seguidas.

Ejemplo:

```text
[3,5,2] -> [3,3,5,5,2,2]
```

### Ejercicio VI.17

```cpp
bool esPalindromoEstructuras(string s);
```

Use simultáneamente una pila y una cola para verificar si una cadena es palíndroma.

### Ejercicio VI.18

```cpp
void invertirPrimerosK(queue<int>& q, int k);
```

Use una pila para invertir únicamente los primeros `k` elementos.

### Ejercicio VI.19

```cpp
int josephus(int n, int k);
```

Simule con una cola el problema de Josephus y retorne el sobreviviente final.

### Ejercicio VI.20

```cpp
void ordenarPila(stack<int>& s);
```

Ordene la pila de menor a mayor usando una sola pila auxiliar.

---
