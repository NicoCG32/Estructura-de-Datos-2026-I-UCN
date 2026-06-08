# IV. Complejidad Algoritmica

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene estudiarlo antes de listas, pilas y colas. La razón es simple: en PP1 no basta con "hacer que funcione"; también debes justificar por qué una solución cuesta `O(n)`, `O(log n)` u otra complejidad.

## Índice para estudiar

Primera pasada sugerida:

- [IV.1](#ejercicio-iv1) | [IV.3](#ejercicio-iv3) | [IV.5](#ejercicio-iv5) | [IV.10](#ejercicio-iv10)

Segunda pasada sugerida:

- [IV.2](#ejercicio-iv2) | [IV.4](#ejercicio-iv4) | [IV.7](#ejercicio-iv7) | [IV.8](#ejercicio-iv8)

Banco completo:

- [IV.1](#ejercicio-iv1) | [IV.2](#ejercicio-iv2) | [IV.3](#ejercicio-iv3) | [IV.4](#ejercicio-iv4) | [IV.5](#ejercicio-iv5)
- [IV.6](#ejercicio-iv6) | [IV.7](#ejercicio-iv7) | [IV.8](#ejercicio-iv8) | [IV.9](#ejercicio-iv9) | [IV.10](#ejercicio-iv10)
- [IV.11](#ejercicio-iv11) | [IV.12](#ejercicio-iv12) | [IV.13](#ejercicio-iv13) | [IV.14](#ejercicio-iv14) | [IV.15](#ejercicio-iv15)
- [IV.16](#ejercicio-iv16) | [IV.17](#ejercicio-iv17) | [IV.18](#ejercicio-iv18) | [IV.19](#ejercicio-iv19) | [IV.20](#ejercicio-iv20)

## Como estudiar este tema

Antes de comparar con la pauta:

- cuente cuántas veces ocurre la operación dominante;
- no se quede solo con el resultado final: explique el crecimiento;
- distinga mejor caso, peor caso y caso único cuando realmente corresponda;
- si el ejercicio compara estructuras, justifique en función de operaciones y no por intuición.

### Ejercicio IV.1

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 0; i < n; i++) {
    cout << i << endl;
}
```

### Ejercicio IV.2

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << i + j << endl;
    }
}
```

### Ejercicio IV.3

Analice la complejidad del siguiente algoritmo:

```cpp
int i = n;
while (i > 1) {
    i = i / 2;
}
```

### Ejercicio IV.4

Analice la complejidad del siguiente algoritmo:

```cpp
int i = 1;
while (i < n) {
    i = i * 2;
}
```

### Ejercicio IV.5

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j = j * 2) {
        cout << i * j << endl;
    }
}
```

### Ejercicio IV.6

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        cout << i + j << endl;
    }
}
```

### Ejercicio IV.7

Suponga una lista enlazada simple de `n` nodos. Analice la complejidad temporal de:

- obtener el primer nodo;
- obtener el último nodo sin puntero `tail`;
- buscar un valor cualquiera;
- insertar al inicio;
- insertar al final sin puntero `tail`.

### Ejercicio IV.8

Suponga una pila de `n` elementos implementada correctamente. Analice la complejidad temporal de:

- `push`;
- `pop`;
- `top`;
- vaciar completamente la pila;
- copiar todos los elementos a otra pila.

### Ejercicio IV.9

Se proponen dos algoritmos para resolver el mismo problema:

- Algoritmo A: `O(n)`
- Algoritmo B: `O(n log n)`

Responda:

1. ¿Cuál conviene para entradas muy grandes?
2. ¿Puede haber un caso práctico donde igualmente se prefiera B?
3. ¿Por qué la notación asintótica no cuenta toda la historia del rendimiento?

### Ejercicio IV.10

Se tiene un problema donde:

- leer un elemento cuesta `O(1)`,
- insertar al inicio es frecuente,
- insertar al final casi no se usa,
- no se requiere acceso por índice.

Responda cuál estructura conviene más entre:

- arreglo/vector;
- lista enlazada simple;
- pila;
- cola.

Justifique en términos de operaciones y complejidad.

### Ejercicio IV.11

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 0; i < n; i += 2) {
    cout << i << endl;
}
```

### Ejercicio IV.12

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 1; i < n; i *= 3) {
    cout << i << endl;
}
```

### Ejercicio IV.13

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j += 2) {
        cout << i + j << endl;
    }
}
```

### Ejercicio IV.14

Analice la complejidad del siguiente algoritmo:

```cpp
int x = n;
while (x > 0) {
    x -= 5;
}
```

### Ejercicio IV.15

Suponga una cola con `n` elementos. Analice la complejidad temporal de vaciarla completamente usando operaciones estándar de cola.

### Ejercicio IV.16

En una lista enlazada simple con puntero `head` y puntero `tail`, ¿cuál es la complejidad temporal de insertar al final? Justifique.

### Ejercicio IV.17

Analice la complejidad del siguiente algoritmo:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = n; j > 0; j /= 2) {
        cout << i + j << endl;
    }
}
```

### Ejercicio IV.18

Se desea buscar un elemento en una colección **no ordenada**. Compare cuál estrategia conviene entre:

- búsqueda lineal;
- búsqueda binaria.

Justifique formalmente.

### Ejercicio IV.19

Si un algoritmo copia todos los elementos de una lista enlazada a una pila auxiliar, ¿cuál es su complejidad espacial adicional?

### Ejercicio IV.20

Analice la complejidad temporal y espacial del siguiente algoritmo:

```cpp
int a = 0;
int b = 0;
for (int i = 0; i < n; i++) {
    if (i % 2 == 0) a++;
    else b++;
}
```

---
