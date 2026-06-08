# I. Ruteos de Punteros y Arreglos

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [I.1](#ejercicio-i1) | [I.2](#ejercicio-i2) | [I.3](#ejercicio-i3) | [I.4](#ejercicio-i4) | [I.5](#ejercicio-i5)
- [I.6](#ejercicio-i6) | [I.7](#ejercicio-i7) | [I.8](#ejercicio-i8) | [I.9](#ejercicio-i9) | [I.10](#ejercicio-i10)
- [I.11](#ejercicio-i11) | [I.12](#ejercicio-i12) | [I.13](#ejercicio-i13) | [I.14](#ejercicio-i14) | [I.15](#ejercicio-i15)
- [I.16](#ejercicio-i16) | [I.17](#ejercicio-i17) | [I.18](#ejercicio-i18) | [I.19](#ejercicio-i19) | [I.20](#ejercicio-i20)


## Cobertura actual

- Ejercicios con pauta desarrollada: `I.1`, `I.2`, `I.3`, `I.4`, `I.5`, `I.6`, `I.7`, `I.8`, `I.9`, `I.10`, `I.11`, `I.12`, `I.13`, `I.14`, `I.15`, `I.16`, `I.17`, `I.18`, `I.19`, `I.20`.
- Ejercicios aun sin desarrollar en esta pauta: `ninguno`.

## Pauta desarrollada

## Ejercicio I.1
Ruteo:

1. Estado inicial: `x = 8`, `y = 3`, `p -> x`.
2. `*p = *p + y`:
   `x = 8 + 3 = 11`
3. `p = &y`:
   ahora `p -> y`
4. `*p = *p * 2`:
   `y = 3 * 2 = 6`

Salida:

```text
11 6
```

## Ejercicio I.2
Ruteo:

1. Estado inicial:
   `v = [2, 4, 6, 8, 10]`
   `p -> v[0]`
2. `*(p + 1) = *p + 3`:
   `v[1] = 2 + 3 = 5`
3. `p = p + 2`:
   ahora `p -> v[2]`
4. `*p = *(p - 1) + *(p + 2)`:
   `v[2] = v[1] + v[4] = 5 + 10 = 15`

Contenido final de `v`:

```text
2 5 15 8 10
```

## Ejercicio I.3
Código:

```cpp
void proceso(int* p, int& x) {
    *p = *p + 5;
    x = x + *p;
}
```

Ruteo:

1. Estado inicial: `a = 4`, `b = 7`.
2. `proceso(&a, b)`:
   `a = 4 + 5 = 9`
   `b = 7 + 9 = 16`
3. `proceso(&b, a)`:
   `b = 16 + 5 = 21`
   `a = 9 + 21 = 30`

Salida:

```text
30 21
```

## Ejercicio I.4
Ruteo:

1. Estado inicial: `x = 5`, `y = 12`, `p -> x`, `pp -> p`.
2. `**pp = **pp + 2`:
   `x = 7`
3. `*pp = &y`:
   ahora `p -> y`
4. `**pp = **pp - x`:
   `y = 12 - 7 = 5`

Salida:

```text
7 5 5
```

## Ejercicio I.5
Ruteo:

1. Estado inicial:
   `v = [1, 3, 5, 7]`
2. `mover(v)`:
   `v[2] = v[1] + v[0] = 3 + 1 = 4`
   queda `v = [1, 3, 4, 7]`
3. `mover(v + 1)`:
   ahora `p` apunta a `v[1]`
   `v[3] = v[2] + v[1] = 4 + 3 = 7`

Contenido final de `v`:

```text
1 3 4 7
```

## Ejercicio I.6
Ruteo:

1. Después del `for`:
   `p = [1, 2, 3, 4]`
2. `q = p + 1`:
   `q -> p[1]`
3. `q[1] = q[0] + p[3]`:
   `p[2] = 2 + 4 = 6`
4. `p[0] = q[1] - p[1]`:
   `p[0] = 6 - 2 = 4`

Salida:

```text
4 2 6 4
```

## Ejercicio I.7
Ruteo:

1. Estado inicial: `a = 2`, `b = 10`, `p -> a`.
2. Dentro de `cambio(&p, &b)`:
   `**pp = **pp + 1`:
   `a = 3`
3. `*pp = r`:
   ahora `p -> b`
4. `**pp = **pp + 4`:
   `b = 14`
5. De vuelta en `main`, `*p = *p * 2`:
   como `p -> b`, `b = 28`

Salida:

```text
3 28
```

## Ejercicio I.8
Ruteo:

1. Estado inicial:
   `a = [2, 4, 6]`
   `b = [1, 3, 5]`
2. `*(p + 1) = *q + *(q + 2)`:
   `a[1] = 1 + 5 = 6`
3. `*(q + 2) = *(p + 1) - *p`:
   `b[2] = 6 - 2 = 4`

Salida:

```text
2 6 6
1 3 4
```

## Ejercicio I.9
Ruteo por iteración:

1. Estado inicial:
   `v = [1, 2, 3, 4, 5]`
2. `i = 1`:
   `v[1] = 2 + 1 = 3`
3. `i = 2`:
   `v[2] = 3 + 3 = 6`
4. `i = 3`:
   `v[3] = 4 + 6 = 10`
5. `i = 4`:
   `v[4] = 5 + 10 = 15`

Contenido final de `v`:

```text
1 3 6 10 15
```

## Ejercicio I.10
Ruteo:

1. Estado inicial: `x = 9`, `y = 4`, `z = 1`, `p -> x`, `pp -> p`.
2. `**pp = y + z`:
   `x = 4 + 1 = 5`
3. `p = &y`
4. `*p = x - z`:
   `y = 5 - 1 = 4`
5. `p = &z`
6. `*p = x + y`:
   `z = 5 + 4 = 9`

Salida:

```text
5 4 9
```

## Ejercicio I.11
Salida:

```text
12 9
```

## Ejercicio I.12
Contenido final de `v`:

```text
1 9 3 8 5 6
```

## Ejercicio I.13
Salida:

```text
9 24 24
```

## Ejercicio I.14
Contenido final de `v`:

```text
2 3 5 6
```

## Ejercicio I.15
Contenido final de `p`:

```text
0 2 4 6 6
```

## Ejercicio I.16
Salida:

```text
1 7 8
```

## Ejercicio I.17
Salida:

```text
6 17
```

## Ejercicio I.18
Salida:

```text
1 4 4
12 5 8
```

## Ejercicio I.19
Salida:

```text
6 3 9
```

## Ejercicio I.20
Salida:

```text
15 20 15
```
