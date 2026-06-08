# IV. Complejidad Algoritmica

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [IV.1](#ejercicio-iv1) | [IV.2](#ejercicio-iv2) | [IV.3](#ejercicio-iv3) | [IV.4](#ejercicio-iv4) | [IV.5](#ejercicio-iv5)
- [IV.6](#ejercicio-iv6) | [IV.7](#ejercicio-iv7) | [IV.8](#ejercicio-iv8) | [IV.9](#ejercicio-iv9) | [IV.10](#ejercicio-iv10)
- [IV.11](#ejercicio-iv11) | [IV.12](#ejercicio-iv12) | [IV.13](#ejercicio-iv13) | [IV.14](#ejercicio-iv14) | [IV.15](#ejercicio-iv15)
- [IV.16](#ejercicio-iv16) | [IV.17](#ejercicio-iv17) | [IV.18](#ejercicio-iv18) | [IV.19](#ejercicio-iv19) | [IV.20](#ejercicio-iv20)


## Cobertura actual

- Ejercicios con pauta desarrollada: `IV.1`, `IV.2`, `IV.3`, `IV.4`, `IV.5`, `IV.6`, `IV.7`, `IV.8`, `IV.9`, `IV.10`, `IV.11`, `IV.12`, `IV.13`, `IV.14`, `IV.15`, `IV.16`, `IV.17`, `IV.18`, `IV.19`, `IV.20`.
- Ejercicios aun sin desarrollar en esta pauta: `ninguno`.

## Pauta desarrollada

## Ejercicio IV.1
Código:

```cpp
for (int i = 0; i < n; i++) {
    cout << i << endl;
}
```

Análisis:

- El ciclo recorre `n` iteraciones.
- En cada iteración realiza una operación de costo constante.

Complejidad:

- Mejor caso: `O(n)`
- Peor caso: `O(n)`
- Complejidad temporal general: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio IV.2
Código:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << i + j << endl;
    }
}
```

Análisis:

- El ciclo externo corre `n` veces.
- Para cada una, el ciclo interno también corre `n` veces.
- La operación dominante se ejecuta `n * n` veces.

Complejidad:

- Mejor caso: `O(n^2)`
- Peor caso: `O(n^2)`
- Complejidad temporal general: `O(n^2)`
- Espacio adicional: `O(1)`

## Ejercicio IV.3
Código:

```cpp
int i = n;
while (i > 1) {
    i = i / 2;
}
```

Análisis:

- En cada iteración el tamaño del problema se divide por `2`.
- El número de iteraciones es aproximadamente `log2(n)`.

Complejidad:

- Mejor caso: `O(1)` si `n <= 1`
- Peor caso: `O(log n)`
- Complejidad temporal general: `O(log n)`
- Espacio adicional: `O(1)`

## Ejercicio IV.4
Código:

```cpp
int i = 1;
while (i < n) {
    i = i * 2;
}
```

Análisis:

- `i` se duplica en cada iteración.
- El número de duplicaciones necesarias para alcanzar `n` es del orden de `log2(n)`.

Complejidad:

- Mejor caso: `O(1)` si `n <= 1`
- Peor caso: `O(log n)`
- Complejidad temporal general: `O(log n)`
- Espacio adicional: `O(1)`

## Ejercicio IV.5
Código:

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j = j * 2) {
        cout << i * j << endl;
    }
}
```

Análisis:

- El ciclo externo recorre `n` veces.
- El ciclo interno duplica `j`, por tanto recorre `O(log n)` veces.

Complejidad:

- Mejor caso: `O(n log n)`
- Peor caso: `O(n log n)`
- Complejidad temporal general: `O(n log n)`
- Espacio adicional: `O(1)`

## Ejercicio IV.6
Código:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        cout << i + j << endl;
    }
}
```

Análisis:

- Para cada `i`, el ciclo interno se ejecuta `i` veces.
- El total de iteraciones es:
  `0 + 1 + 2 + ... + (n - 1) = n(n - 1) / 2`

Complejidad:

- Mejor caso: `O(n^2)`
- Peor caso: `O(n^2)`
- Complejidad temporal general: `O(n^2)`
- Espacio adicional: `O(1)`

## Ejercicio IV.7
Lista enlazada simple sin `tail`:

1. Obtener el primer nodo: `O(1)`
2. Obtener el último nodo: `O(n)`
3. Buscar un valor cualquiera: `O(n)`
4. Insertar al inicio: `O(1)`
5. Insertar al final sin `tail`: `O(n)`

Justificación:

La lista solo da acceso directo al `head`. Todo lo que implique llegar al final requiere recorrido completo.

## Ejercicio IV.8
Pila implementada correctamente:

1. `push`: `O(1)`
2. `pop`: `O(1)`
3. `top`: `O(1)`
4. Vaciar completamente la pila: `O(n)`
5. Copiar todos los elementos a otra pila: `O(n)`

Justificación:

Las operaciones básicas sobre el tope son constantes. En cambio, vaciar o copiar todos los elementos obliga a procesar los `n` elementos.

## Ejercicio IV.9
Respuestas:

1. Para entradas muy grandes conviene el algoritmo `A`, porque `O(n)` crece más lentamente que `O(n log n)`.
2. Sí. En la práctica podría preferirse `B` si tiene constantes menores, mejor implementación, mejor uso de memoria caché o si los tamaños reales de entrada son pequeños.
3. La notación asintótica ignora constantes multiplicativas, costos de memoria, distribución de datos, optimizaciones del compilador y detalles de implementación.

## Ejercicio IV.10
Estructura más conveniente:

```text
Lista enlazada simple
```

Justificación:

- Insertar al inicio es la operación dominante y cuesta `O(1)`.
- No se necesita acceso por índice, por lo que el arreglo/vector no aporta una ventaja clave.
- Insertar al final casi no se usa, así que su costo `O(n)` no es el factor principal.
- Una pila o cola imponen políticas de acceso más restrictivas que una lista simple.

---

## Ejercicio IV.11
- Tiempo: `O(n)`
- Espacio: `O(1)`

## Ejercicio IV.12
- Tiempo: `O(log n)`
- Espacio: `O(1)`

## Ejercicio IV.13
- Tiempo: `O(n^2)`
- Espacio: `O(1)`

## Ejercicio IV.14
- Tiempo: `O(n)`
- Espacio: `O(1)`

## Ejercicio IV.15
Vaciar una cola de `n` elementos cuesta:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio IV.16
Con puntero `tail`, insertar al final cuesta:

- Tiempo: `O(1)`

## Ejercicio IV.17
- Tiempo: `O(n log n)`
- Espacio: `O(1)`

## Ejercicio IV.18
Respuesta:

Conviene búsqueda lineal, porque la búsqueda binaria requiere datos ordenados.

Complejidades:

- lineal: `O(n)`
- binaria: `O(log n)` solo si los datos ya están ordenados

## Ejercicio IV.19
Copiar todos los elementos de una lista enlazada a una pila auxiliar requiere:

- Espacio adicional: `O(n)`

## Ejercicio IV.20
- Tiempo: `O(n)`
- Espacio: `O(1)`
