# X. Ejercicios Integradores Tipo Parcial Real

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene dejarlo para el final de la ruta. Aquí ya no basta con dominar un tema aislado: debes leer con calma, separar restricciones del enunciado y justificar cada decisión como si estuvieras en una prueba real.

## Como estudiar este tema

Esta sección reúne ejercicios de dificultad más cercana a modelos de prueba reales. Aquí el foco no es solo “saber la estructura”, sino también:

- leer firmas con cuidado;
- detectar restricciones escondidas en el enunciado;
- justificar la elección de la estructura;
- corregir código defectuoso cuando corresponda.

### Ejercicio X.1

```cpp
# include <iostream>

## Contenido

- [Como estudiar este tema](#como-estudiar-este-tema)
  - [Ejercicio X.1](#ejercicio-x1)
  - [Ejercicio X.2](#ejercicio-x2)
  - [Ejercicio X.3](#ejercicio-x3)
  - [Ejercicio X.4](#ejercicio-x4)
  - [Ejercicio X.5](#ejercicio-x5)
  - [Ejercicio X.6](#ejercicio-x6)
  - [Ejercicio X.7](#ejercicio-x7)
  - [Ejercicio X.8](#ejercicio-x8)
  - [Ejercicio X.9](#ejercicio-x9)
  - [Ejercicio X.10](#ejercicio-x10)
  - [Ejercicio X.11](#ejercicio-x11)

using namespace std;

int main() {
    int nL[7];
    nL[0] = 5;
    int* ptr = nL;

    for (int i = 1; i < 7; i++) {
        int xyz = 0;

        if (i % 3 == 0) {
            xyz = *ptr * 2;
        }
        if (i % 3 == 1) {
            xyz = i * 4 / *ptr;
        }
        if (i % 3 == 2) {
            *(ptr + i / 2) = i * 3;
        }

        *(ptr + i) = xyz;
    }

    for (int i = 0; i < 7; i++) {
        cout << nL[i] << " ";
    }
    cout << endl;
    return 0;
}
```

Se pide:

1. Rutar completamente el arreglo.
2. Indicar el contenido final de `nL`.
3. Explicar qué ocurre en las iteraciones donde `i % 3 == 2`.

### Ejercicio X.2

Considere el siguiente código:

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual int fun(int* ptr) {
        return ptr + 5;
    }
};

class B : public A {
public:
    int fun(int* ptr) {
        return *ptr + 2;
    }
};

class C : public A {
public:
    int* fun(int* ptr) {
        return ptr;
    }
};

int main() {
    int* ptr;

    for (int i = 0; i < 6; i++) {
        if (i % 2) {
            A* obj = new C();
            cout << obj->fun() << endl;
            delete obj;
        } else {
            B* obj = new C();
            cout << obj->fun() << endl;
            delete obj;
        }
    }

    return 0;
}
```

Se pide:

1. Encontrar todas las líneas que contienen errores.
2. Explicar con precisión el tipo de error.
3. Proponer una versión corregida.
4. Una vez corregido, indicar qué implementación se ejecuta en cada rama del `if`.

### Ejercicio X.3

Considere las siguientes estructuras:

```cpp
class Node {
public:
    char value;
    Node* next;
    Node() : value('\0'), next(nullptr) {}
};

class LNode {
public:
    Node* str;
    LNode* next;
    LNode() : str(nullptr), next(nullptr) {}
};
```

Implemente:

```cpp
LNode* stringToList(string t);
```

La función recibe un `string` compuesto por palabras separadas por espacios y debe construir una lista simple de palabras, donde:

- cada nodo de tipo `LNode` representa una palabra;
- el campo `str` apunta a una lista simple de caracteres de esa palabra.

Ejemplo:

```text
"sol luna mar"
```

debe transformarse conceptualmente en:

```text
[s->o->l] -> [l->u->n->a] -> [m->a->r]
```

Se pide además explicar:

1. qué representa cada nivel de lista;
2. cómo se detecta el fin de una palabra;
3. cuál es la complejidad temporal de construir la estructura.

### Ejercicio X.4

Implemente:

```cpp
bool canBeObtainable(int* pushed, int* popped, int size);
```

Dados dos arreglos `pushed` y `popped` de largo `size`, determine si la secuencia `popped` puede obtenerse a partir de una pila inicialmente vacía, insertando los elementos en el orden dado por `pushed`.

Ejemplo:

```text
pushed = [1,2,3,4,5]
popped = [4,5,3,2,1] -> true

pushed = [1,2,3,4,5]
popped = [4,3,5,1,2] -> false
```

Se debe justificar por qué la pila modela correctamente el estado del problema.

### Ejercicio X.5

Considere una lista circular simple donde cada nodo almacena una nota de un alumno.

Implemente una función que:

```cpp
void insertarNotaOrdenadaCircular(Node*& head, double nota);
```

inserte una nota en la lista manteniendo el orden de menor a mayor.

Luego implemente:

```cpp
void mostrarResumenNotas(Node* head);
```

que imprima:

- todas las notas en orden;
- el promedio;
- la cantidad total de notas.

En caso de lista vacía, debe indicarse explícitamente.

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

### Ejercicio X.7

Suponga un sistema donde los elementos llegan en una pila `src`, pero deben salir en una cola `salida` según prioridad.

Implemente una estrategia que use:

- una pila fuente `src`;
- dos pilas auxiliares `S1` y `S2`;
- una cola final `salida`.

El objetivo es reorganizar los elementos para que la cola quede ordenada según una prioridad definida por un campo del elemento.

No se pide necesariamente código compilable completo, pero sí:

1. estructura general del algoritmo;
2. rol de cada pila auxiliar;
3. por qué la cola es adecuada como estructura de salida.

### Ejercicio X.8

Considere la siguiente firma:

```cpp
int filtrar_patron_multiple(queue<int>& Q_datos, stack<int>& P_frecuencia,
                            queue<int>& Q_filtrada, int U, int F);
```

Se pide:

1. implementar la función;
2. explicar qué estado representa `P_frecuencia`;
3. justificar el uso conjunto de pila y cola;
4. indicar complejidad temporal y espacial.

Este ejercicio es **muy representativo** del nivel actual de parciales porque obliga a:

- procesar una secuencia en una sola pasada;
- reutilizar estructuras;
- decidir cuándo apilar, cuándo reemplazar y cuándo encolar.

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

### Ejercicio X.11

**Más estados**

Implemente una función que determine si una cadena `p2` puede obtenerse reordenando los caracteres de `p1`, es decir, si ambas son **anagramas**.

Firma:

```cpp
bool esAnagrama(string p1, string p2);
```

Consideraciones:

- solución **iterativa** (sin recursión);
- debes considerar la **frecuencia** de cada carácter.

Ejemplos de salida:

| Entrada | Salida |
| --- | --- |
| `("roma", "amor")` | `true` |
| `("listen", "silent")` | `true` |
| `("hola", "halo")` | `true` |
| `("aabb", "abbb")` | `false` |
| `("abc", "abcc")` | `false` |

En la pauta, resolver este ejercicio con una versión usando `stack` y otra usando `queue`.

---
