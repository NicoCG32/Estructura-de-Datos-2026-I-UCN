# Ayudantía 2: POO en C++, Herencia y Polimorfismo

## Repaso de la Ayudantía 1: `*`, `&`, punteros y referencias

Antes de entrar en herencia y polimorfismo, repasemos una base clave de la ayudantía anterior.

### Operador `*`

- En una declaración, `*` indica que la variable es un **puntero**.
- Ejemplo: `int* p;` significa que `p` guarda una dirección de memoria de un `int`.
- En una expresión, `*` sirve para **desreferenciar**: acceder al valor apuntado.
- Ejemplo: si `p` apunta a `x`, entonces `*p` es el valor de `x`.

### Operador `&`

- En una expresión, `&` obtiene la **dirección de memoria** de una variable.
- Ejemplo: `p = &x;` guarda en `p` la dirección de `x`.

### Variables de tipo puntero (`Tipo*`)

- Una variable puntero no guarda directamente un valor como `7` o `20`, sino una dirección.
- Esto permite modificar datos indirectamente y trabajar con memoria dinámica.

Ejemplo rápido:

```cpp
int x = 10;
int* p = &x;
*p = 25;   // modifica x a través del puntero
```

### Lo que faltó ver: variable de tipo referencia (`Tipo&`)

También nos faltó dejar explícito que en C++ existe la **referencia**, escrita como `Tipo&`.

- Una referencia es un alias (otro nombre) para una variable existente.
- A diferencia del puntero, no se usa `*` para acceder al valor.
- Muy útil para pasar objetos a funciones sin copiar y sin usar punteros explícitos.

Ejemplo rápido:

```cpp
int x = 10;
int& r = x;   // r es referencia a x
r = 30;       // también modifica x
```

- Si quieres trabajar con direcciones explícitas y posible `nullptr`, usa punteros (`Tipo*`).
- Si quieres un alias seguro sin `nullptr` y sin copia, usa referencias (`Tipo&`).

#### Punteros a punteros (`Tipo**`)

Un puntero a puntero es una variable que almacena la **dirección de otra variable puntero**.

```cpp
int x = 10;
int* p = &x;        // p es puntero a int
int** pp = &p;      // pp es puntero a puntero

*pp = &x;           // redirige p a apuntar a x
**pp = 25;          // modifica x a través del doble puntero
```

**Uso común:** Pasar punteros a funciones si quieres que la función cambie dónde apunta el puntero.

#### Referencias rvalue (`Tipo&&`)

`Tipo&&` **NO es una referencia a una referencia**, sino una **referencia rvalue** (C++11 o más). Es un concepto avanzado relacionado con **move semantics** (optimización de memoria), no es relevante para el curso.

## Repaso POO

- C++ permite objetos en stack y heap; Java usa objetos en heap con recolección de basura.
- En C++, `new` exige `delete` manual; en Java no existe `delete`.
- En C++, pasar `Tipo x` copia el objeto; en Java pasar un objeto comparte la misma instancia (referencia por valor).
- En C++, `virtual` es explícito; en Java los métodos son virtuales por defecto (excepto `final`, `static`, `private`).
- En C++, destructor puede ser virtual y controla liberación; en Java no hay destructores equivalentes para liberar memoria.
- C++ permite herencia múltiple de clases; Java no (solo una clase + múltiples interfaces).
- `struct` en C++ es similar a `class`, cambiando principalmente el acceso por defecto (`public`).

### Tabla Resumen Rápido (Herencia y Polimorfismo en C++)

| Caso | Declaración | NO virtual ejecuta | Virtual ejecuta | Construcción | Destrucción | Delete por puntero base | Memoria |
|------|-------------|--------------------|-----------------|--------------|-------------|-------------------------|---------|
| Estático a clase | `Padre c;` | `Padre` | `Padre` | `Padre` | `Padre` | No aplica | Seguro |
| Estático a hijo | `Hijo h;` | `Hijo` | `Hijo` | `Padre -> Hijo` | `Hijo -> Padre` | No aplica | Seguro |
| Dinámico a clase | `Padre* p = new Padre;` | `Padre` | `Padre` | `Padre` | `Padre` | `delete p` correcto | Seguro |
| Dinámico a hijo (correcto) | `Padre* p = new Hijo;` con `virtual ~Padre()` | `Padre` (por tipo del puntero) | `Hijo` (despacho dinámico) | `Padre -> Hijo` | `Hijo -> Padre` | `delete p` correcto | Seguro |
| Dinámico a hijo (error) | `Padre* p = new Hijo;` sin `virtual ~Padre()` | `Padre` | `Hijo` | `Padre -> Hijo` | Indefinida o incompleta | `delete p` peligroso | ERROR de memoria |

- Método virtual: decide qué implementación se ejecuta en la llamada.
- Destructor virtual: decide si al hacer delete por base se destruye también el hijo.
- Si aparece `Padre* p = new Hijo`, exige `virtual ~Padre()`.

Comparación directa con Java en esta tabla:

- El caso crítico de `delete` y destructor virtual es propio de C++ (en Java no hay `delete`).
- La diferencia entre no virtual y virtual en C++ se enseña explícita; en Java normalmente ya se comporta como virtual.

#### Regla para recordar

- Método `virtual` decide **qué método se ejecuta**.
- Destructor `virtual` decide **qué destructores se ejecutan al liberar por puntero base**.
- Si hay `Padre* p = new Hijo;`, la clase base **debe** tener destructor virtual.

#### Ejemplo mínimo

```cpp
#include <iostream>
using namespace std;

class Padre {
public:
    Padre() { cout << "Construyendo Padre" << endl; }
    virtual ~Padre() { cout << "Destruyendo Padre" << endl; }  // caso correcto

    void noVirtual() { cout << "noVirtual de Padre" << endl; }
    virtual void siVirtual() { cout << "siVirtual de Padre" << endl; }
};

class Hijo : public Padre {
public:
    Hijo() { cout << "Construyendo Hijo" << endl; }
    ~Hijo() override { cout << "Destruyendo Hijo" << endl; }

    void noVirtual() { cout << "noVirtual de Hijo" << endl; }
    void siVirtual() override { cout << "siVirtual de Hijo" << endl; }
};

int main() {
    cout << "[1] Crear objeto estatico Hijo h" << endl;
    Hijo h;

    cout << "[2] Llamadas directas sobre h" << endl;
    h.noVirtual();   // Hijo
    h.siVirtual();   // Hijo

    cout << "[3] Crear puntero base a objeto hijo" << endl;
    Padre* p = new Hijo;

    cout << "[4] Llamadas por puntero base p" << endl;
    p->noVirtual();  // Padre (estatico)
    p->siVirtual();  // Hijo (dinamico)

    cout << "[5] delete p" << endl;
    delete p;        // Hijo -> Padre (porque el destructor base es virtual)

    cout << "[6] Fin de main (se destruye h automatico)" << endl;

    return 0;
}
```

Salida esperada (orden cronológico):

```text
[1] Crear objeto estatico Hijo h
Construyendo Padre
Construyendo Hijo
[2] Llamadas directas sobre h
noVirtual de Hijo
siVirtual de Hijo
[3] Crear puntero base a objeto hijo
Construyendo Padre
Construyendo Hijo
[4] Llamadas por puntero base p
noVirtual de Padre
siVirtual de Hijo
[5] delete p
Destruyendo Hijo
Destruyendo Padre
[6] Fin de main (se destruye h automatico)
Destruyendo Hijo
Destruyendo Padre
```

Nota de error de memoria:

- Si en `Padre` quitas `virtual` del destructor, entonces `delete p;` en `Padre* p = new Hijo;` queda en comportamiento indefinido (riesgo alto).

Mini-regla de estos casos:

- Si quieres polimorfismo, evita copiar por valor (`Padre c = h`) porque provoca slicing.
- En diamante, usa herencia virtual para evitar duplicar la base común.
- En Java no existe object slicing porque las variables de objetos manejan referencias, no copias implícitas del objeto al asignar.

### Casos extra importantes a considerar

| Caso extra | Ejemplo corto | Qué pasa | Riesgo |
|-----------|---------------|----------|--------|
| Referencia a base (polimorfismo sin `new`) | `Padre& r = h;` | NO virtual usa `Padre`; virtual usa `Hijo`; no hay `delete` | Seguro |
| Object slicing (copia por valor) | `Padre c = h;` | Se pierde la parte `Hijo`; desde ahí se comporta como `Padre` | Error conceptual frecuente |
| Clase abstracta | `virtual void f() = 0;` | No se puede instanciar la base; fuerza contrato de métodos | Seguro, mejora diseño |
| Diamante en herencia múltiple | `A <- B, C <- D` | Sin herencia virtual hay dos subobjetos `A` y ambigüedad | Error conceptual / diseño |

#### Mini-caso: doble herencia (`Hijo : Padre, Madre`)

```cpp
#include <iostream>
using namespace std;

class Padre {
public:
    Padre() { cout << "Construyendo Padre" << endl; }
    virtual ~Padre() { cout << "Destruyendo Padre" << endl; }

    virtual void saludo() { cout << "saludo virtual de Padre" << endl; }
    void identidad() { cout << "identidad no virtual de Padre" << endl; }
};

class Madre {
public:
    Madre() { cout << "Construyendo Madre" << endl; }
    virtual ~Madre() { cout << "Destruyendo Madre" << endl; }

    virtual void saludo() { cout << "saludo virtual de Madre" << endl; }
    void identidad() { cout << "identidad no virtual de Madre" << endl; }
};

class Hijo : public Padre, public Madre {
public:
    Hijo() { cout << "Construyendo Hijo" << endl; }
    ~Hijo() override { cout << "Destruyendo Hijo" << endl; }

    void saludo() override { cout << "saludo virtual de Hijo" << endl; }
};

int main() {
    cout << "[1] Crear Hijo" << endl;
    Hijo h;

    Padre* p = &h;
    Madre* m = &h;

    cout << "[2] Llamadas virtuales por punteros base" << endl;
    p->saludo();  // Hijo
    m->saludo();  // Hijo

    cout << "[3] Llamadas no virtuales por punteros base" << endl;
    p->identidad();  // Padre
    m->identidad();  // Madre

    cout << "[4] Fin de main" << endl;
    return 0;
}
```

Salida esperada:

```text
[1] Crear Hijo
Construyendo Padre
Construyendo Madre
Construyendo Hijo
[2] Llamadas virtuales por punteros base
saludo virtual de Hijo
saludo virtual de Hijo
[3] Llamadas no virtuales por punteros base
identidad no virtual de Padre
identidad no virtual de Madre
[4] Fin de main
Destruyendo Hijo
Destruyendo Madre
Destruyendo Padre
```

- El orden de construcción depende de la declaración de la clase derivada: `Hijo : Padre, Madre`.
- El orden de destrucción es el inverso: primero `Hijo`, luego `Madre`, luego `Padre`.
- Los métodos virtuales se resuelven por tipo real del objeto (`Hijo`), aunque el puntero sea `Padre*` o `Madre*`.

Nota sobre punteros:

- Si usas punteros (`Padre* p = new Hijo;` o `Madre* m = new Hijo;`) y haces `delete`, el orden de destrucción correcto sigue siendo `Hijo -> Madre -> Padre`, siempre que los destructores base sean virtuales.
- Si el destructor de la base NO es virtual, `delete` por puntero base puede producir comportamiento indefinido (destrucción incompleta y riesgo de memoria).

Comparación con Java:

- Java no permite herencia múltiple de clases como `Hijo : Padre, Madre`; ese patrón se resuelve con interfaces.
- En Java no se enseña orden de destrucción por destructores porque la memoria la maneja el Garbage Collector.

---

### Funciones y tipos de datos no primitivos

En POO, al pasar objetos a funciones, lo más importante es evitar copias innecesarias y dejar claro si la función puede modificar o no el objeto.

`const` significa **constante**: dentro de esa función no puedes modificar ese objeto.

Como base de comparación con Java, esta diferencia es clave:

- En C++, pasar `Tipo x` (directo) crea una **copia** del objeto.
- En Java, al pasar un objeto, se pasa una **referencia por valor** (no se copia el objeto completo).

- Si solo quieres leer: usa `const Tipo&`.
- Si quieres modificar sin punteros: usa `Tipo&`.
- Si trabajas con punteros (como en esta ayudantía): usa `Tipo*` para modificar y `const Tipo*` para solo lectura.

Ejemplo mental rápido (Java vs C++):

- C++: `void f(Alumno a)` -> copia de `Alumno`.
- C++: `void f(Alumno& a)` -> mismo objeto original.
- Java: `void f(Alumno a)` -> misma instancia, pero la referencia se pasa por valor.

Resumen rápido:

| Forma | Firma | Copia objeto | Puede modificar | Comentario |
|------|-------|--------------|-----------------|------------|
| Por valor | `void f(Tipo x)` | Sí | Solo la copia | Suele ser más caro en objetos grandes |
| Por referencia | `void f(Tipo& x)` | No | Sí | Eficiente y sin `nullptr` |
| Por referencia constante | `void f(const Tipo& x)` | No | No | Opción recomendada para lectura |
| Por puntero | `void f(Tipo* x)` | No | Sí | Puede ser `nullptr`, hay que validar |
| Por puntero constante | `void f(const Tipo* x)` | No | No | Lectura por puntero |

Traducción rápida C++ vs Java:

- Lo más parecido al comportamiento usual de Java es `Tipo&` o `Tipo*` (según estilo), no `Tipo` por valor.
- En C++, `Tipo` por valor se usa cuando **quieres** copiar.
- En Java, escribir `f(obj)` nunca copia el objeto completo; en C++ puede copiarse según la firma.

#### Ejemplo: estáticos y dinámicos enviados a funciones

```cpp
#include <iostream>
#include <string>
using namespace std;

class Alumno {
private:
    string nombre;
    int edad;

public:
    Alumno(string nombre, int edad) : nombre(nombre), edad(edad) {}

    void cumplirAño() { edad++; }
    void mostrar() const { cout << nombre << " (" << edad << ")" << endl; }
};

void verPorValor(Alumno a) {
    cout << "verPorValor: ";
    a.mostrar();
}

void verPorRefConst(const Alumno& a) {
    cout << "verPorRefConst: ";
    a.mostrar();
}

void modificarPorRef(Alumno& a) {
    a.cumplirAño();
}

void verPorPunteroConst(const Alumno* a) {
    if (a != nullptr) {
        cout << "verPorPunteroConst: ";
        a->mostrar();
    }
}

void modificarPorPuntero(Alumno* a) {
    if (a != nullptr) {
        a->cumplirAño();
    }
}

int main() {
    Alumno estatico("Ana", 20);
    Alumno* dinamico = new Alumno("Luis", 21);

    // Estatico a funciones
    verPorValor(estatico);         // copia
    verPorRefConst(estatico);      // sin copia
    modificarPorRef(estatico);     // modifica original
    verPorPunteroConst(&estatico); // lectura por puntero

    // Dinamico a funciones
    verPorRefConst(*dinamico);     // se pasa como referencia (desreferenciando)
    modificarPorRef(*dinamico);    // modifica objeto dinamico
    verPorPunteroConst(dinamico);  // lectura por puntero
    modificarPorPuntero(dinamico); // modifica por puntero

    // Siempre necesario deletear dinámicos
    delete dinamico;
    return 0;
}
```

- Aunque aquí trabajen mucho con punteros, `const Tipo&` es la forma estándar de solo lectura en C++ moderno, posiblemente lo vean mucho si ocupan inteligencia artificial.
- `&` (referencia) evita copias y evita el caso `nullptr`.
- En punteros, siempre validar `nullptr` antes de usar `->`.

---

### Inciso final: qué es `struct` y cuándo conviene

`struct` en C++ es casi igual a `class`, pero con una diferencia clave por defecto:

- En `struct`, los miembros son `public` por defecto.
- En `class`, los miembros son `private` por defecto.

Por eso, para ejercicios rápidos o modelos simples de datos, `struct` ahorra tiempo cuando no quieres gastar esfuerzo inicial en encapsulamiento (getters/setters, niveles de acceso, etc.).

Ejemplo simple:

```cpp
#include <iostream>
#include <string>
using namespace std;

struct AlumnoDTO {
    string nombre;
    int edad;
};

void imprimir(const AlumnoDTO& a) {
    cout << a.nombre << " - " << a.edad << endl;
}

int main() {
    AlumnoDTO a{"Nico", 20};
    a.edad++;          // acceso directo (public)
    imprimir(a);
    return 0;
}
```

Cuando usar `struct` en esta ayudantía:

- Para representar datos simples rápidamente.
- Para ejemplos cortos donde el foco no es encapsulamiento.

Cuando preferir `class`:

- Cuando quieres proteger invariantes del objeto.
- Cuando necesitas controlar acceso y reglas internas de negocio.

Comparación con Java:

- Java usa `class` para casi todo; C++ separa muy bien `struct` (datos simples) y `class` (encapsulamiento fuerte) por convención.


## Ejercicios de herencia

### Ejercicio 1

```cpp
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
        cout << "Construyendo Persona" << endl;
    }

    ~Persona() {
        cout << "Destruyendo Persona" << endl;
    }

    void mostrarPersona() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

class Estudiante : public Persona {
protected:
    string carrera;
    int semestre;

public:
    Estudiante(string nombre, int edad, string carrera, int semestre)
        : Persona(nombre, edad) {
        this->carrera = carrera;
        this->semestre = semestre;
        cout << "Construyendo Estudiante" << endl;
    }

    ~Estudiante() {
        cout << "Destruyendo Estudiante" << endl;
    }

    void mostrarEstudiante() {
        mostrarPersona();
        cout << "Carrera: " << carrera << endl;
        cout << "Semestre: " << semestre << endl;
    }
};

class Ayudante : public Estudiante {
private:
    string asignatura;
    int horasSemana;

public:
    Ayudante(string nombre, int edad, string carrera, int semestre,
             string asignatura, int horasSemana)
        : Estudiante(nombre, edad, carrera, semestre) {
        this->asignatura = asignatura;
        this->horasSemana = horasSemana;
        cout << "Construyendo Ayudante" << endl;
    }

    ~Ayudante() {
        cout << "Destruyendo Ayudante" << endl;
    }

    void mostrarAyudante() {
        mostrarEstudiante();
        cout << "Asignatura: " << asignatura << endl;
        cout << "Horas por semana: " << horasSemana << endl;
    }
};

int main() {
    Ayudante a1("Nicolas", 20, "Ingenieria", 4, "Estructura de Datos", 8);

    cout << "----- Datos del ayudante -----" << endl;
    a1.mostrarAyudante();

    cout << "----- Fin del main -----" << endl;

    return 0;
}
```

**Rutee claramente e indique la salida.**

---

### Ejercicio 2

```cpp
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;

public:
    Persona(string nombre) {
        this->nombre = nombre;
        cout << "Construyendo Persona: " << nombre << endl;
    }

    ~Persona() {
        cout << "Destruyendo Persona: " << nombre << endl;
    }

    void mostrarPersona() {
        cout << "Nombre: " << nombre << endl;
    }
};

class Estudiante : public Persona {
protected:
    string carrera;

public:
    Estudiante(string nombre, string carrera)
        : Persona(nombre) {
        this->carrera = carrera;
        cout << "Construyendo Estudiante" << endl;
    }

    ~Estudiante() {
        cout << "Destruyendo Estudiante" << endl;
    }

    void mostrarEstudiante() {
        mostrarPersona();
        cout << "Carrera: " << carrera << endl;
    }
};

class Trabajador : public Persona {
protected:
    string empresa;

public:
    Trabajador(string nombre, string empresa)
        : Persona(nombre) {
        this->empresa = empresa;
        cout << "Construyendo Trabajador" << endl;
    }

    ~Trabajador() {
        cout << "Destruyendo Trabajador" << endl;
    }

    void mostrarTrabajador() {
        mostrarPersona();
        cout << "Empresa: " << empresa << endl;
    }
};

class Ayudante : public Estudiante, public Trabajador {
private:
    string ramo;

public:
    Ayudante(string nombre, string carrera, string empresa, string ramo)
        : Estudiante(nombre, carrera), Trabajador(nombre, empresa) {
        this->ramo = ramo;
        cout << "Construyendo Ayudante" << endl;
    }

    ~Ayudante() {
        cout << "Destruyendo Ayudante" << endl;
    }

    void mostrarAyudante() {
        cout << "--- Parte estudiante ---" << endl;
        mostrarEstudiante();

        cout << "--- Parte trabajador ---" << endl;
        mostrarTrabajador();

        cout << "Ramo: " << ramo << endl;
    }
};

int main() {
    Ayudante a1("Nicolas", "Ingenieria", "Universidad", "Estructura de Datos");

    cout << "----- Datos del ayudante -----" << endl;
    a1.mostrarAyudante();

    cout << "----- Fin del main -----" << endl;
    return 0;
}
```

**Rutee claramente e indique la salida.**

---

### Ejercicio 3

```cpp
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;

public:
    Persona(string nombre) {
        this->nombre = nombre;
        cout << "Construyendo Persona: " << nombre << endl;
    }

    ~Persona() {
        cout << "Destruyendo Persona: " << nombre << endl;
    }

    void mostrarPersona() {
        cout << "Nombre: " << nombre << endl;
    }
};

class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(string nombre, string carrera)
        : Persona(nombre) {
        this->carrera = carrera;
        cout << "Construyendo Estudiante: " << nombre << endl;
    }

    ~Estudiante() {
        cout << "Destruyendo Estudiante: " << nombre << endl;
    }

    void mostrarEstudiante() {
        mostrarPersona();
        cout << "Carrera: " << carrera << endl;
    }
};

int main() {
    cout << "Inicio del programa" << endl;

    Persona p1("Carlos");

    cout << "-----" << endl;

    Estudiante e1("Lucia", "Ingenieria");
    e1.mostrarEstudiante();

    cout << "-----" << endl;

    Estudiante* p2 = new Estudiante("Mario", "Arquitectura");
    p2->mostrarEstudiante();

    cout << "-----" << endl;

    {
        Estudiante e2("Sofia", "Medicina");
        e2.mostrarEstudiante();
        cout << "Fin del bloque interno" << endl;
    }

    cout << "-----" << endl;

    delete p2;

    cout << "Fin del programa" << endl;
    return 0;
}
```

**Rutee claramente e indique la salida.**

---

## Ejercicios de polimorfismo

### Ejercicio 4

Comparación con Java:

- En C++ hay que marcar `virtual` para despacho dinámico; en Java eso ocurre por defecto en métodos de instancia.
- El método no virtual aquí se parece más a un método `static/final/private` en Java respecto al enlace.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;

public:
    Animal(string nombre) {
        this->nombre = nombre;
        cout << "Construyendo Animal: " << nombre << endl;
    }

    ~Animal() {
        cout << "Destruyendo Animal: " << nombre << endl;
    }

    void presentarse() {
        cout << nombre << " es un animal" << endl;
    }

    virtual void hacerSonido() {
        cout << nombre << " hace un sonido generico" << endl;
    }
};

class Perro : public Animal {
public:
    Perro(string nombre) : Animal(nombre) {
        cout << "Construyendo Perro: " << nombre << endl;
    }

    ~Perro() {
        cout << "Destruyendo Perro: " << nombre << endl;
    }

    void presentarse() {
        cout << nombre << " es un perro" << endl;
    }

    void hacerSonido() override {
        cout << nombre << " dice: guau" << endl;
    }
};

class Gato : public Animal {
public:
    Gato(string nombre) : Animal(nombre) {
        cout << "Construyendo Gato: " << nombre << endl;
    }

    ~Gato() {
        cout << "Destruyendo Gato: " << nombre << endl;
    }

    void presentarse() {
        cout << nombre << " es un gato" << endl;
    }

    void hacerSonido() override {
        cout << nombre << " dice: miau" << endl;
    }
};

int main() {
    cout << "Inicio" << endl;

    Perro p("Max");
    Gato g("Luna");

    cout << "----- Llamadas directas -----" << endl;
    p.presentarse();
    p.hacerSonido();
    g.presentarse();
    g.hacerSonido();

    cout << "----- Referencias a clase base -----" << endl;
    Animal& ref1 = p;
    Animal& ref2 = g;

    ref1.presentarse();
    ref1.hacerSonido();

    ref2.presentarse();
    ref2.hacerSonido();

    cout << "Fin" << endl;
    return 0;
}
```

**Rutee claramente e indique la salida.**

---

### Ejercicio 5

```cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;

public:
    Animal(string nombre) {
        this->nombre = nombre;
        cout << "Construyendo Animal: " << nombre << endl;
    }

    ~Animal() {
        cout << "Destruyendo Animal: " << nombre << endl;
    }

    void presentarse() {
        cout << nombre << " es un animal" << endl;
    }

    virtual void hacerSonido() {
        cout << nombre << " hace un sonido generico" << endl;
    }
};

class Perro : public Animal {
public:
    Perro(string nombre) : Animal(nombre) {
        cout << "Construyendo Perro: " << nombre << endl;
    }

    ~Perro() {
        cout << "Destruyendo Perro: " << nombre << endl;
    }

    void presentarse() {
        cout << nombre << " es un perro" << endl;
    }

    void hacerSonido() override {
        cout << nombre << " dice: guau" << endl;
    }
};

class Gato : public Animal {
public:
    Gato(string nombre) : Animal(nombre) {
        cout << "Construyendo Gato: " << nombre << endl;
    }

    ~Gato() {
        cout << "Destruyendo Gato: " << nombre << endl;
    }

    void presentarse() {
        cout << nombre << " es un gato" << endl;
    }

    void hacerSonido() override {
        cout << nombre << " dice: miau" << endl;
    }
};

int main() {
    cout << "Inicio" << endl;

    Animal* a1 = new Animal("Bicho");
    Perro* p1 = new Perro("Max");
    Gato* g1 = new Gato("Luna");

    cout << "----- Llamadas con punteros -----" << endl;
    a1->presentarse();
    a1->hacerSonido();

    p1->presentarse();
    p1->hacerSonido();

    g1->presentarse();
    g1->hacerSonido();

    cout << "----- Polimorfismo real con Animal* -----" << endl;
    Animal* ap1 = p1;
    Animal* ap2 = g1;

    ap1->presentarse();
    ap1->hacerSonido();
    ap2->presentarse();
    ap2->hacerSonido();

    cout << "----- Liberando memoria -----" << endl;
    delete a1;
    delete p1;
    delete g1;

    cout << "Fin" << endl;
    return 0;
}
```

**Rutee claramente e indique la salida.**

---

### Ejercicio 6

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void g() { cout << "g de Base" << endl; }
    virtual void f() { cout << "f de Base" << endl; }
};

class Derivada : public Base {
public:
    void g() { cout << "g de Derivada" << endl; }
    void f() override { cout << "f de Derivada" << endl; }
};

int main() {
    Derivada d;
    Base* p = &d;

    p->g();
    p->f();

    return 0;
}
```

**Prediga la salida y justifique por qué ocurre.**

---

### Ejercicio 7

```cpp
#include <iostream>
#include <string>
using namespace std;

class A {
protected:
    string nombre;

public:
    A(string nombre) {
        this->nombre = nombre;
        cout << "Construyendo A: " << nombre << endl;
    }

    virtual ~A() {
        cout << "Destruyendo A: " << nombre << endl;
    }

    void mostrarTipo() {
        cout << nombre << " es de tipo A" << endl;
    }

    virtual void accion() {
        cout << nombre << " ejecuta accion de A" << endl;
    }
};

class B : public A {
public:
    B(string nombre) : A(nombre) {
        cout << "Construyendo B: " << nombre << endl;
    }

    ~B() override {
        cout << "Destruyendo B: " << nombre << endl;
    }

    void mostrarTipo() {
        cout << nombre << " es de tipo B" << endl;
    }

    void accion() override {
        cout << nombre << " ejecuta accion de B" << endl;
    }
};

class C : public A {
public:
    C(string nombre) : A(nombre) {
        cout << "Construyendo C: " << nombre << endl;
    }

    ~C() override {
        cout << "Destruyendo C: " << nombre << endl;
    }

    void mostrarTipo() {
        cout << nombre << " es de tipo C" << endl;
    }

    void accion() override {
        cout << nombre << " ejecuta accion de C" << endl;
    }
};

int main() {
    cout << "Inicio" << endl;

    A* p1 = new A("objetoA");
    A* p2 = new B("objetoB");
    A* p3 = new C("objetoC");

    cout << "----- mostrarTipo() -----" << endl;
    p1->mostrarTipo();
    p2->mostrarTipo();
    p3->mostrarTipo();

    cout << "----- accion() -----" << endl;
    p1->accion();
    p2->accion();
    p3->accion();

    cout << "----- delete -----" << endl;
    delete p1;
    delete p2;
    delete p3;

    cout << "Fin" << endl;
    return 0;
}
```

**Rutee claramente e indique la salida.**

---

### Referencias

Fuentes de apoyo didáctico (introductorias):

- GeeksforGeeks. Object Oriented Programming in C++. https://www.geeksforgeeks.org/cpp/object-oriented-programming-in-cpp/
- W3Schools. C++ Inheritance. https://www.w3schools.com/cpp/cpp_inheritance.asp
- W3Schools. C++ Polymorphism. https://www.w3schools.com/cpp/cpp_polymorphism.asp

Fuentes principales (Documentación oficial de C++):

- cppreference. C++ language: classes. https://en.cppreference.com/w/cpp/language/classes
- cppreference. C++ language: derived classes (herencia). https://en.cppreference.com/w/cpp/language/derived_class
- cppreference. C++ language: virtual function. https://en.cppreference.com/w/cpp/language/virtual
- cppreference. C++ language: override specifier. https://en.cppreference.com/w/cpp/language/override
- cppreference. C++ language: destructor. https://en.cppreference.com/w/cpp/language/destructor
- cppreference. C++ language: this pointer. https://en.cppreference.com/w/cpp/language/this
- cppreference. C++ language: const_cast y const-correctness. https://en.cppreference.com/w/cpp/language/const_cast
- cppreference. C++ language: reference declaration (`&`). https://en.cppreference.com/w/cpp/language/reference
- cppreference. C++ language: access specifiers (public/protected/private). https://en.cppreference.com/w/cpp/language/access

Puente rápido C++ vs Java (para toda la ayudantía):