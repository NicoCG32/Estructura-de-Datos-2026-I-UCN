# Intensiva I: Ruta Intensiva I

Este archivo contiene solo los ejercicios de la Intensiva I, en orden.

## Ejercicios seleccionados

### Ejercicio I.3

```cpp
# include <iostream>

## Contenido

- [Ejercicios seleccionados](#ejercicios-seleccionados)
  - [Ejercicio I.3](#ejercicio-i3)
  - [Ejercicio I.5](#ejercicio-i5)
  - [Ejercicio I.7](#ejercicio-i7)
  - [Ejercicio II.10](#ejercicio-ii10)
  - [Ejercicio IV.5](#ejercicio-iv5)
  - [Ejercicio IV.10](#ejercicio-iv10)
  - [Ejercicio VI.5](#ejercicio-vi5)
  - [Ejercicio X.6](#ejercicio-x6)
  - [Ejercicio X.10](#ejercicio-x10)
  - [Ejercicio X.9](#ejercicio-x9)

using namespace std;

void proceso(int* p, int& x) {
    *p = *p + 5;
    x = x + *p;
}

int main() {
    int a = 4;
    int b = 7;

    proceso(&a, b);
    proceso(&b, a);

    cout << a << " " << b << endl;
    return 0;
}
```

### Ejercicio I.5

```cpp
# include <iostream>
using namespace std;

void mover(int* p) {
    *(p + 2) = *(p + 1) + *p;
}

int main() {
    int v[4] = {1, 3, 5, 7};
    mover(v);
    mover(v + 1);

    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    return 0;
}
```

### Ejercicio I.7

```cpp
# include <iostream>
using namespace std;

void cambio(int** pp, int* r) {
    **pp = **pp + 1;
    *pp = r;
    **pp = **pp + 4;
}

int main() {
    int a = 2;
    int b = 10;
    int* p = &a;

    cambio(&p, &b);
    *p = *p * 2;

    cout << a << " " << b << endl;
    return 0;
}
```

### Ejercicio II.10

```cpp
# include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; }
    virtual void f() { cout << "Base::f" << endl; }
    virtual ~Base() { cout << "~Base()" << endl; }
};

class Derivada : public Base {
public:
    Derivada() { cout << "Derivada()" << endl; }
    void f() override { cout << "Derivada::f" << endl; }
    ~Derivada() override { cout << "~Derivada()" << endl; }
};

int main() {
    Base* p = new Derivada();
    p->f();
    delete p;
    return 0;
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

### Ejercicio VI.5

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
"# Intensiva I: Ruta Intensiva I

Esta intensiva recopila ejercicios prácticos centrados en punteros, arreglos, herencia, complejidad y estructuras básicas —equivalente a la primera parte de la materia. El formato sigue el de `Intensiva II`: breve introducción, `## Contenido` y luego los ejercicios.

## Contenido

- [Ejercicio I.3](#ejercicio-i3)
- [Ejercicio I.5](#ejercicio-i5)
- [Ejercicio I.7](#ejercicio-i7)
- [Ejercicio II.10](#ejercicio-ii10)
- [Ejercicio IV.5](#ejercicio-iv5)
- [Ejercicio IV.10](#ejercicio-iv10)
- [Ejercicio VI.5](#ejercicio-vi5)
- [Ejercicio X.6](#ejercicio-x6)
- [Ejercicio X.10](#ejercicio-x10)
- [Ejercicio X.9](#ejercicio-x9)

---

### Ejercicio I.3

Analice el siguiente programa y determine la salida:

```cpp
#include <iostream>
using namespace std;

void proceso(int* p, int& x) {
    *p = *p + 5;
    x = x + *p;
}

int main() {
    int a = 4;
    int b = 7;

    proceso(&a, b);
    proceso(&b, a);

    cout << a << " " << b << endl;
    return 0;
}
```

### Ejercicio I.5

Completar el ruteo del siguiente programa y dar la salida final del arreglo:

```cpp
#include <iostream>
using namespace std;

void mover(int* p) {
    *(p + 2) = *(p + 1) + *p;
}

int main() {
    int v[4] = {1, 3, 5, 7};
    mover(v);
    mover(v + 1);

    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    return 0;
}
```

### Ejercicio I.7

Analice el siguiente código que manipula punteros a punteros:

```cpp
#include <iostream>
using namespace std;

void cambio(int** pp, int* r) {
    **pp = **pp + 1;
    *pp = r;
    **pp = **pp + 4;
}

int main() {
    int a = 2;
    int b = 10;
    int* p = &a;

    cambio(&p, &b);
    *p = *p * 2;

    cout << a << " " << b << endl;
    return 0;
}
```

### Ejercicio II.10

Explique la salida del siguiente fragmento con herencia y polimorfismo:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; }
    virtual void f() { cout << "Base::f" << endl; }
    virtual ~Base() { cout << "~Base()" << endl; }
};

class Derivada : public Base {
public:
    Derivada() { cout << "Derivada()" << endl; }
    void f() override { cout << "Derivada::f" << endl; }
    ~Derivada() override { cout << "~Derivada()" << endl; }
};

int main() {
    Base* p = new Derivada();
    p->f();
    delete p;
    return 0;
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

### Ejercicio IV.10

Se tiene un problema donde:

- leer un elemento cuesta `O(1)`,
- insertar al inicio es frecuente,
- insertar al final casi no se usa,
- no se requiere acceso por índice.

Indique la estructura más conveniente entre arreglo/vector, lista enlazada simple, pila o cola, y justifique.

### Ejercicio VI.5

Implemente `string decodeString(string s)` para decodificar expresiones con formato `K[text]` con anidamiento. Requisito: solución iterativa.

### Ejercicio X.6

Diseñe `double calcularPromedio(AlumnoNode* head, string nombreAlumno, string ramo)` y `void ordenarRamosPorPromedio(RamoNode*& headRamos)` según la especificación original.

### Ejercicio X.10

Implemente `hayCaminoSalidaQueue` y `hayCaminoSalidaStack` para determinar existencia de salida en un laberinto (uso de `queue` y `stack`).

### Ejercicio X.9

Problema de misioneros y caníbales: implemente `int minCrucesMisionerosCanibales()` usando `queue<Estado>` y estado visitado.
