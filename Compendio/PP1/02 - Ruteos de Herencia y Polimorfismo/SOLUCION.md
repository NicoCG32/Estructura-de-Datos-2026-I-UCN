# II. Ruteos de Herencia y Polimorfismo

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [II.1](#ejercicio-ii1) | [II.2](#ejercicio-ii2) | [II.3](#ejercicio-ii3) | [II.4](#ejercicio-ii4) | [II.5](#ejercicio-ii5)
- [II.6](#ejercicio-ii6) | [II.7](#ejercicio-ii7) | [II.8](#ejercicio-ii8) | [II.9](#ejercicio-ii9) | [II.10](#ejercicio-ii10)
- [II.11](#ejercicio-ii11) | [II.12](#ejercicio-ii12) | [II.13](#ejercicio-ii13) | [II.14](#ejercicio-ii14) | [II.15](#ejercicio-ii15)
- [II.16](#ejercicio-ii16) | [II.17](#ejercicio-ii17) | [II.18](#ejercicio-ii18) | [II.19](#ejercicio-ii19) | [II.20](#ejercicio-ii20)


## Cobertura actual

- Ejercicios con pauta desarrollada: `II.1`, `II.2`, `II.3`, `II.4`, `II.5`, `II.6`, `II.7`, `II.8`, `II.9`, `II.10`, `II.11`, `II.12`, `II.13`, `II.14`, `II.15`, `II.16`, `II.17`, `II.18`, `II.19`, `II.20`.
- Ejercicios aun sin desarrollar en esta pauta: `ninguno`.

## Pauta desarrollada

## Ejercicio II.1
Orden de construccion y destruccion:

1. Al crear `B obj`, primero se construye la parte base `A`.
2. Luego se construye `B`.
3. Al finalizar `main`, se destruye primero `B` y luego `A`.

Salida:

```text
A()
B()
~B()
~A()
```

## Ejercicio II.2
Código relevante:

```cpp
Base* p = &d;
p->f();
p->g();
```

Análisis:

- `f()` no es virtual, por tanto se resuelve por el tipo del puntero: `Base*`.
- `g()` sí es virtual, por tanto se resuelve por el tipo real del objeto: `Derivada`.

Salida:

```text
Base::f
Derivada::g
```

## Ejercicio II.3
Análisis:

- `sonido()` es virtual.
- `probar` recibe un `Animal&`, por lo que no hay copia ni slicing.
- El objeto real es `Perro`, así que el despacho es dinámico.

Salida:

```text
Guau
```

## Ejercicio II.4
Orden de ejecución:

1. `new Hijo()` construye primero `Padre()` y luego `Hijo()`.
2. `delete p;` usa el destructor virtual de `Padre`, por lo que destruye primero `Hijo` y luego `Padre`.

Salida:

```text
Padre()
Hijo()
~Hijo()
~Padre()
```

## Ejercicio II.5
Análisis:

- Cuando `p -> a`, el objeto real es `X`.
- Cuando `p -> b`, el objeto real es `Y`.
- Como `ver()` es virtual, en ambos casos se ejecuta según el tipo real del objeto.

Salida:

```text
X
Y
```

## Ejercicio II.6
Análisis:

- `Base b = d;` copia solo la parte base del objeto derivado. Eso produce slicing.
- Luego `b.mostrar()` se ejecuta sobre un objeto `Base` real.
- `d.mostrar()` se ejecuta sobre el objeto derivado.

Salida:

```text
Base
Derivada
```

## Ejercicio II.7
Orden de construcción:

Una herencia en cadena construye desde la clase más base hacia la más derivada.

Salida:

```text
Persona()
Estudiante()
Ayudante()
```

## Ejercicio II.8
Análisis:

- `ejecutar(A a)` recibe el objeto por valor.
- Al pasar un `B`, ocurre slicing y dentro de la función existe un objeto `A`.
- Por eso `a.f()` ejecuta la versión de `A`.

Salida:

```text
A::f
```

## Ejercicio II.9
Análisis:

- `r.dibujar()` llama a un método virtual, por lo que se ejecuta `Circulo::dibujar`.
- `r.nombre()` no es virtual, por lo que se resuelve usando el tipo estático `Figura&`.

Salida:

```text
Circulo
Nombre Figura
```

## Ejercicio II.10
Orden de ejecución:

1. `Base* p = new Derivada();`
   Construcción: `Base()` y luego `Derivada()`.
2. `p->f();`
   Como `f()` es virtual, se ejecuta `Derivada::f`.
3. `delete p;`
   Como el destructor base es virtual, se destruye primero `Derivada` y luego `Base`.

Salida:

```text
Base()
Derivada()
Derivada::f
~Derivada()
~Base()
```

## Ejercicio II.11
Salida:

```text
B::f
A::g
```

Explicación:

- `f()` es virtual, por lo que se ejecuta la versión de `B`.
- `g()` no es virtual, por lo que se ejecuta según el tipo estático `A&`.

## Ejercicio II.12
Salida:

```text
A()
B()
C()
~C()
~B()
~A()
```

## Ejercicio II.13
Salida:

```text
A
B
```

Explicación:

- `A a = b;` produce slicing.
- `A* p = &b;` conserva el objeto real `B`, por eso `p->f()` ejecuta `B::f`.

## Ejercicio II.14
Salida:

```text
A
B
```

## Ejercicio II.15
Salida:

```text
A::x
B::x
B::y
B::y
```

## Ejercicio II.16
Salida:

```text
A
B
```

Explicación:

- `mostrar(A a)` copia por valor y ocurre slicing.
- `mostrarRef(A& a)` preserva el tipo real del objeto.

## Ejercicio II.17
Salida:

```text
C
C
```

## Ejercicio II.18
Salida:

```text
A()
B()
~B()
~A()
```

## Ejercicio II.19
Salida:

```text
A 3
B
```

Explicación:

`B::f()` no sobrescribe `A::f(int)` porque la firma no coincide.

## Ejercicio II.20
Salida:

```text
5
```
