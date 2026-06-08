# Ayudantía 2: Soluciones
## Índice

- [Ejercicio 1: Herencia en Cadena (Persona -> Estudiante -> Ayudante)](#ejercicio-1-herencia-en-cadena-persona--estudiante--ayudante)
- [Ejercicio 2: Herencia Múltiple (Diamante sin herencia virtual)](#ejercicio-2-herencia-múltiple-diamante-sin-herencia-virtual)
- [Ejercicio 3: Constructores/Destructores en Stack, Heap y Bloques](#ejercicio-3-constructoresdestructores-en-stack-heap-y-bloques)
- [Ejercicio 4: Polimorfismo Parcial (virtual y no virtual)](#ejercicio-4-polimorfismo-parcial-virtual-y-no-virtual)
- [Ejercicio 5: Punteros a Objetos y Liberación de Memoria](#ejercicio-5-punteros-a-objetos-y-liberación-de-memoria)
- [Ejercicio 6: Ágil](#ejercicio-6-ágil)
- [Ejercicio 7: Despacho Estático vs Dinámico + Destructor Virtual](#ejercicio-7-despacho-estático-vs-dinámico--destructor-virtual)


Soluciones: POO en C++, Herencia y Polimorfismo

### Ejercicio 1: Herencia en Cadena (Persona -> Estudiante -> Ayudante)

### Ruteo de Construcción

Al crear:
```cpp
Ayudante a1("Nicolas", 20, "Ingenieria", 4, "Estructura de Datos", 8);
```

El orden de construcción en herencia es de base a derivada:

1. `Persona`
2. `Estudiante`
3. `Ayudante`

### Ruteo de `mostrarAyudante()`

`mostrarAyudante()` llama a `mostrarEstudiante()`, y este a `mostrarPersona()`:

1. `mostrarPersona()` imprime nombre y edad.
2. `mostrarEstudiante()` imprime carrera y semestre.
3. `mostrarAyudante()` imprime asignatura y horas.

### Ruteo de Destrucción

Al terminar `main`, el orden es inverso:

1. `~Ayudante()`
2. `~Estudiante()`
3. `~Persona()`

### Salida
```
Construyendo Persona
Construyendo Estudiante
Construyendo Ayudante
----- Datos del ayudante -----
Nombre: Nicolas
Edad: 20
Carrera: Ingenieria
Semestre: 4
Asignatura: Estructura de Datos
Horas por semana: 8
----- Fin del main -----
Destruyendo Ayudante
Destruyendo Estudiante
Destruyendo Persona
```

---

### Ejercicio 2: Herencia Múltiple (Diamante sin herencia virtual)

### Idea Clave

`Ayudante` hereda de `Estudiante` y `Trabajador`, y ambos heredan de `Persona`.

Eso crea **dos subobjetos Persona** distintos dentro de `Ayudante` (uno por cada rama).

### Ruteo de Construcción

Orden de bases según declaración en `Ayudante : public Estudiante, public Trabajador`:

1. Rama `Estudiante`:
	- `Persona(nombre)`
	- `Estudiante(...)`
2. Rama `Trabajador`:
	- `Persona(nombre)`
	- `Trabajador(...)`
3. `Ayudante(...)`

### Ruteo de `mostrarAyudante()`

1. Parte estudiante:
	- `Nombre: Nicolas` (desde la `Persona` de la rama `Estudiante`)
	- `Carrera: Ingenieria`
2. Parte trabajador:
	- `Nombre: Nicolas` (desde la `Persona` de la rama `Trabajador`)
	- `Empresa: Universidad`
3. `Ramo: Estructura de Datos`

### Ruteo de Destrucción

Orden inverso:

1. `~Ayudante()`
2. Rama `Trabajador`:
	- `~Trabajador()`
	- `~Persona()` (de esa rama)
3. Rama `Estudiante`:
	- `~Estudiante()`
	- `~Persona()` (de esa rama)

### Salida
```
Construyendo Persona: Nicolas
Construyendo Estudiante
Construyendo Persona: Nicolas
Construyendo Trabajador
Construyendo Ayudante
----- Datos del ayudante -----
--- Parte estudiante ---
Nombre: Nicolas
Carrera: Ingenieria
--- Parte trabajador ---
Nombre: Nicolas
Empresa: Universidad
Ramo: Estructura de Datos
----- Fin del main -----
Destruyendo Ayudante
Destruyendo Trabajador
Destruyendo Persona: Nicolas
Destruyendo Estudiante
Destruyendo Persona: Nicolas
```

---

### Ejercicio 3: Constructores/Destructores en Stack, Heap y Bloques

### Ruteo Paso a Paso

1. `Inicio del programa`.
2. Se crea `p1` (`Persona("Carlos")`).
3. Se crea `e1` (`Estudiante("Lucia", "Ingenieria")`): primero `Persona`, luego `Estudiante`.
4. Se crea `p2` en heap (`new Estudiante("Mario", "Arquitectura")`).
5. En bloque interno se crea `e2` (`Sofia`) y al salir del bloque se destruye inmediatamente.
6. `delete p2` destruye el objeto dinámico `Mario`.
7. `Fin del programa`.
8. Al salir de `main`, se destruyen locales en orden inverso de creación: `e1` y luego `p1`.

### Como funciona el bloque interno

Un bloque interno es un alcance delimitado por llaves dentro de otro bloque (por ejemplo, dentro de `main`).

Aunque se parece a una función porque usa llaves, no es una función: no tiene nombre, no recibe parametros y no se puede invocar desde otro lugar. Solo se ejecuta cuando el flujo del programa llega a ese punto.

En este ejercicio, al entrar al bloque se construye `e2` (`Sofia`). Mientras la ejecución esta dentro de ese bloque, `e2` existe y puede usarse normalmente. Al llegar a la llave de cierre, `e2` sale de alcance y su destructor se ejecuta de inmediato, por eso se imprime:

1. `Destruyendo Estudiante: Sofia`
2. `Destruyendo Persona: Sofia`

Esto ocurre antes de `delete p2` y antes de terminar `main`, porque los objetos locales de un bloque se destruyen al salir de ese bloque, no al final de toda la función.

### Usos comunes de bloques internos

1. Limitar el alcance de variables temporales.
2. Ordenar el codigo por etapas para hacerlo más legible.
3. Evitar conflictos de nombres entre variables locales.

### Salida
```
Inicio del programa
Construyendo Persona: Carlos
-----
Construyendo Persona: Lucia
Construyendo Estudiante: Lucia
Nombre: Lucia
Carrera: Ingenieria
-----
Construyendo Persona: Mario
Construyendo Estudiante: Mario
Nombre: Mario
Carrera: Arquitectura
-----
Construyendo Persona: Sofia
Construyendo Estudiante: Sofia
Nombre: Sofia
Carrera: Medicina
Fin del bloque interno
Destruyendo Estudiante: Sofia
Destruyendo Persona: Sofia
-----
Destruyendo Estudiante: Mario
Destruyendo Persona: Mario
Fin del programa
Destruyendo Estudiante: Lucia
Destruyendo Persona: Lucia
Destruyendo Persona: Carlos
```

---

### Ejercicio 4: Polimorfismo Parcial (virtual y no virtual)

### Idea Clave

- `hacerSonido()` es `virtual` -> se resuelve dinámicamente.
- `presentarse()` **no** es virtual -> se resuelve por tipo estático.

### Ruteo Importante

Con llamadas directas (`p.presentarse()`, `g.presentarse()`), se usa versión derivada porque el tipo estático es `Perro`/`Gato`.

Con referencias a base:
```cpp
Animal& ref1 = p;
Animal& ref2 = g;
```

- `ref1.presentarse()` y `ref2.presentarse()` llaman a `Animal::presentarse()` (no virtual).
- `ref1.hacerSonido()` y `ref2.hacerSonido()` llaman a `Perro::hacerSonido()` y `Gato::hacerSonido()` (virtual).

### Salida
```
Inicio
Construyendo Animal: Max
Construyendo Perro: Max
Construyendo Animal: Luna
Construyendo Gato: Luna
----- Llamadas directas -----
Max es un perro
Max dice: guau
Luna es un gato
Luna dice: miau
----- Referencias a clase base -----
Max es un animal
Max dice: guau
Luna es un animal
Luna dice: miau
Fin
Destruyendo Gato: Luna
Destruyendo Animal: Luna
Destruyendo Perro: Max
Destruyendo Animal: Max
```

---

### Ejercicio 5: Punteros a Objetos y Liberación de Memoria

### Ruteo de Construcción

1. `new Animal("Bicho")`.
2. `new Perro("Max")`: construye `Animal` y luego `Perro`.
3. `new Gato("Luna")`: construye `Animal` y luego `Gato`.

### Ruteo de Llamadas

- `a1` es `Animal*` -> usa métodos de `Animal`.
- `p1` es `Perro*` -> usa métodos de `Perro`.
- `g1` es `Gato*` -> usa métodos de `Gato`.
- En el bloque de polimorfismo real:
	- `ap1` y `ap2` son `Animal*` apuntando a objetos `Perro` y `Gato`.
	- `presentarse()` no es virtual -> se llama `Animal::presentarse()`.
	- `hacerSonido()` sí es virtual -> se llaman `Perro::hacerSonido()` y `Gato::hacerSonido()`.

### Ruteo de `delete`

- `delete a1` -> `~Animal()`.
- `delete p1` -> `~Perro()` y luego `~Animal()`.
- `delete g1` -> `~Gato()` y luego `~Animal()`.

### Salida
```
Inicio
Construyendo Animal: Bicho
Construyendo Animal: Max
Construyendo Perro: Max
Construyendo Animal: Luna
Construyendo Gato: Luna
----- Llamadas con punteros -----
Bicho es un animal
Bicho hace un sonido generico
Max es un perro
Max dice: guau
Luna es un gato
Luna dice: miau
----- Polimorfismo real con Animal* -----
Max es un animal
Max dice: guau
Luna es un animal
Luna dice: miau
----- Liberando memoria -----
Destruyendo Animal: Bicho
Destruyendo Perro: Max
Destruyendo Animal: Max
Destruyendo Gato: Luna
Destruyendo Animal: Luna
Fin
```

---

### Ejercicio 6: Ágil

### Idea Clave

- `g()` no es virtual -> enlace estático por tipo del puntero (`Base*`).
- `f()` es virtual -> enlace dinámico por tipo real del objeto (`Derivada`).

### Ruteo

1. `Derivada d;` crea un objeto derivado.
2. `Base* p = &d;` el puntero base apunta al objeto derivado.
3. `p->g();` llama `Base::g()` (no virtual).
4. `p->f();` llama `Derivada::f()` (virtual).

### Salida
```
g de Base
f de Derivada
```

---

### Ejercicio 7: Despacho Estático vs Dinámico + Destructor Virtual

### Idea Clave

- `mostrarTipo()` no es virtual -> se decide por tipo estático (`A*`).
- `accion()` sí es virtual -> usa el tipo real del objeto (`A`, `B`, `C`).
- Destructor de `A` es virtual -> `delete` desde `A*` destruye correctamente objetos derivados.

### Ruteo de `mostrarTipo()`

Como `p1`, `p2`, `p3` son `A*`, las 3 llamadas usan `A::mostrarTipo()`.

### Ruteo de `accion()`

- `p1->accion()` -> `A::accion()`.
- `p2->accion()` -> `B::accion()`.
- `p3->accion()` -> `C::accion()`.

### Ruteo de `delete`

- `delete p1` -> `~A()`.
- `delete p2` -> `~B()` y luego `~A()`.
- `delete p3` -> `~C()` y luego `~A()`.

### Salida
```
Inicio
Construyendo A: objetoA
Construyendo A: objetoB
Construyendo B: objetoB
Construyendo A: objetoC
Construyendo C: objetoC
----- mostrarTipo() -----
objetoA es de tipo A
objetoB es de tipo A
objetoC es de tipo A
----- accion() -----
objetoA ejecuta accion de A
objetoB ejecuta accion de B
objetoC ejecuta accion de C
----- delete -----
Destruyendo A: objetoA
Destruyendo B: objetoB
Destruyendo A: objetoB
Destruyendo C: objetoC
Destruyendo A: objetoC
Fin
```

---

## Resumen

| Concepto | Qué se observa en la ayudantía |
|----------|--------------------------------|
| Orden de construcción | Base -> derivada |
| Orden de destrucción | Derivada -> base |
| Herencia múltiple sin virtual | Duplicación del subobjeto base (`Persona`) |
| Método no virtual | Enlace estático (depende del tipo del puntero/referencia) |
| Método virtual | Enlace dinámico (depende del tipo real del objeto) |
| Destructor virtual | Necesario para borrar derivados desde punteros a base |
