# Intensiva I: Ruta Intensiva I

Este archivo contiene solo los ejercicios de la Ruta Intensiva I, en orden.

## Ejercicios seleccionados

### Ejercicio I.3

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

### Ejercicio II.10

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

### Ejercicio III.5

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void mostrar() { cout << "Base" << endl; }
};

class Hijo : public Base {
public:
    void mostrar() override { cout << "Hijo" << endl; }
};
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

### Ejercicio V.6

```cpp
void removePrimes(Node*& head);
```

La lista contiene enteros positivos. Elimine todos los nodos cuyo valor sea primo.

### Ejercicio VI.5

```cpp
string decodeString(string s);
```

Use pilas para decodificar cadenas del tipo `K[text]`, permitiendo anidamiento.

### Ejercicio VII.3

Si una clase base tiene métodos virtuales, entonces su destructor no necesita ser virtual.

### Ejercicio VIII.4

Si se tiene `Padre* p = new Hijo();`, ¿qué condición es importante para liberar correctamente el objeto con `delete p;`?

A. Que `Hijo` no tenga constructor.
B. Que `Padre` tenga destructor virtual.
C. Que `Padre` tenga todos sus métodos `private`.
D. Que `Hijo` no sobrescriba métodos.
E. Que `p` sea una referencia y no un puntero.

### Ejercicio IX.6

Una pila sigue la política __________________, mientras que una cola sigue la política __________________.

### Ejercicio X.6

Considere una estructura de tres niveles:

- `L1`: lista circular de alumnos;
- `L3`: por cada alumno, lista simple de ramos;
- `L2`: por cada ramo, lista simple de notas con su ponderación.

Se pide diseñar en pseudocódigo C/C++:

```cpp
double calcularPromedio(AlumnoNode* head, string nombreAlumno, string ramo);
```

La función debe retornar el promedio ponderado de un alumno en un ramo específico.

Luego diseñe:

```cpp
void ordenarRamosPorPromedio(RamoNode*& headRamos);
```

que ordene los ramos de un alumno desde mayor a menor promedio.

Este ejercicio es de dificultad alta y apunta a entrenar problemas donde una lista enlazada no almacena solo enteros, sino también **punteros a otras listas**.

### Ejercicio X.10

Considere un laberinto representado por una matriz de caracteres de tamaño máximo `MAX x MAX`, donde:

- `#` representa muro;
- `.` representa celda libre;
- `E` representa salida.

Use además:

```cpp
const int MAX = 50;

struct Pos {
    int f;
    int c;
    Pos(int f, int c) : f(f), c(c) {}
};
```

Implemente:

```cpp
int distanciaMinimaSalida(char lab[][MAX], int filas, int cols, int fIni, int cIni);
```

La función debe retornar la **cantidad mínima de movimientos** necesarios para llegar desde `(fIni, cIni)` hasta alguna salida `E`.

Si no existe camino, debe retornar `-1`.

Restricciones y requisitos:

- use explícitamente una `queue<Pos>`;
- no use recursión;
- justifique por qué una cola resulta más adecuada que una pila cuando se pide distancia mínima.

Explique además:

1. qué estado representa la cola;
2. por qué la cola permite explorar el tablero por capas;
3. complejidad temporal y espacial.

Este bloque final (`X.9`, `X.10` y `X.11`) está pensado para reforzar la idea de **guardar estados** y procesarlos con estructuras adecuadas:

- estados discretos de un problema clásico;
- recorrido por capas en una matriz;
- existencia de solución versus distancia mínima;
- comparación de frecuencias de caracteres con pila o cola.

### Ejercicio X.9

Considere el problema clásico de **misioneros y caníbales**:

- en la orilla izquierda hay `3` misioneros y `3` caníbales;
- el bote puede transportar como máximo `2` personas;
- en cualquier orilla donde haya misioneros, estos no pueden quedar en minoría frente a los caníbales.

Use la siguiente estructura:

```cpp
struct Estado {
    int mIzq;
    int cIzq;
    bool boteIzq;
    int pasos;

    Estado(int mIzq, int cIzq, bool boteIzq, int pasos)
        : mIzq(mIzq), cIzq(cIzq), boteIzq(boteIzq), pasos(pasos) {}
};
```

Implemente:

```cpp
int minCrucesMisionerosCanibales();
```

La función debe retornar la **cantidad mínima de cruces** necesarios para llevar a todos a la orilla derecha.

Si por alguna variante del problema no existiera solución, debe retornar `-1`.

Restricciones y requisitos:

- use explícitamente una `queue<Estado>`;
- modele los estados visitados para no repetir configuraciones;
- no use recursión.

Explique además:

1. qué representa un estado;
2. por qué una cola es adecuada para buscar la solución de menor cantidad de cruces;
3. cómo se valida que un estado sea seguro.

