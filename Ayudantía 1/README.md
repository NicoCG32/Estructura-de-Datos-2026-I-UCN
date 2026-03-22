# Ayudantía 1: Introducción a C++ y Punteros

## Ejercicios de Punteros

### Ejercicio 1

```cpp
#include <iostream>
using namespace std;

int main() {
	int x = 10;
	int* p = &x;

	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;

	return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `x` | `int` | Valor base almacenado en memoria |
| `p` | `int*` | Puntero que guarda la dirección de `x` |

---

### Ejercicio 2

```cpp
#include <iostream>
using namespace std;

int main() {
	int a = 7;
	int b = 20;

	int* p = &a;

	cout << "Inicio:" << endl;
	cout << "a = " << a << ", b = " << b << ", *p = " << *p << endl;

	*p = 15;

	cout << "Luego de *p = 15:" << endl;
	cout << "a = " << a << ", b = " << b << ", *p = " << *p << endl;

	p = &b;
	*p = 30;

	cout << "Luego de p = &b y *p = 30:" << endl;
	cout << "a = " << a << ", b = " << b << ", *p = " << *p << endl;

	return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `a` | `int` | Primer valor entero |
| `b` | `int` | Segundo valor entero |
| `p` | `int*` | Puntero que primero referencia `a` y luego `b` |

---

### Ejercicio 3

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 12;
    int* p = &x;
    int y = *p + 3;
    int* q = y;

    cout << "x = " << x << endl;
    cout << "*p = " << *p << endl;
    cout << "y = " << y << endl;
    cout << "*q = " << *q << endl;

    return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `x` | `int` | Valor inicial usado para construir `y` |
| `p` | `int*` | Puntero válido a `x` |
| `y` | `int` | Resultado de `*p + 3` |
| `q` | `int*` | Puntero mal inicializado (error conceptual/compilación) |

---

### Ejercicio 4

```cpp
#include <iostream>
using namespace std;

int main() {
    int v[5] = {8, 3, 6, 1, 9};
    int* p = v;

    cout << "1) " << v[0] << endl;
    cout << "2) " << *p << endl;
    cout << "3) " << *(p + 2) << endl;
    cout << "4) " << p[3] << endl;

    p = p + 1;

    cout << "5) " << *p << endl;
    cout << "6) " << *(p + 2) << endl;

    *(p + 1) = 20;

    cout << "7) " << v[2] << endl;
    cout << "8) " << *(v + 2) << endl;
    cout << "9) " << p[1] << endl;

    return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `v` | `int[5]` | Arreglo base de datos |
| `p` | `int*` | Puntero para recorrer/modificar posiciones de `v` |

---

### Ejercicio 5

```cpp
#include <iostream>
using namespace std;

void modificar(int* p) {
    *p = *p + 4;
}

int main() {
    int x = 6;
    int y = 2;
    int* q = &x;

    modificar(q);
    modificar(&y);

    q = &y;
    *q = *q + x;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*q = " << *q << endl;

    return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `x` | `int` | Valor modificado por `modificar(q)` |
| `y` | `int` | Valor modificado por `modificar(&y)` y luego por `*q = *q + x` |
| `q` | `int*` | Puntero que cambia de `x` a `y` |
| `p` (en `modificar`) | `int*` | Parámetro puntero usado para alterar el valor apuntado |

---

### Ejercicio 6

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 4;
    int y = 9;

    int* p = &x;
    int** pp = &p;

    **pp = **pp + 3;
    *p = *p * 2;

    *pp = &y;
    **pp = **pp - 4;
    *p = *p + x;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p = " << *p << endl;
    cout << "**pp = " << **pp << endl;

    return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `x` | `int` | Primer entero modificado vía doble indirección |
| `y` | `int` | Segundo entero que pasa a ser apuntado por `p` |
| `p` | `int*` | Puntero a entero (primero `x`, luego `y`) |
| `pp` | `int**` | Puntero a puntero para redirección de `p` |

---

### Ejercicio 7

```cpp
#include <iostream>
using namespace std;

void proceso1(int** pp, int* r) {
    int local = 3;
    int* q = *pp;

    **pp = **pp + local;
    *q = *q * 2;

    q = r;
    *q = *q + local;

    local = *q;
    local = local + 5;
}

void proceso2(int** pp) {
    int aux = 4;
    int* t = *pp;

    **pp = **pp - aux;
    t = &aux;
    *t = *t + 6;

    aux = aux + **pp;
}

int main() {
    int x = 5;
    int y = 8;
    int z = 12;

    int* p = &x;
    int** pp = &p;

    proceso1(pp, &y);
    p = &z;
    proceso2(pp);
    proceso1(pp, &x);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "*p = " << *p << endl;
    cout << "**pp = " << **pp << endl;

    return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `x` | `int` | Valor base de `main` |
| `y` | `int` | Valor base de `main` |
| `z` | `int` | Valor base de `main` |
| `p` | `int*` | Puntero que cambia entre `x` y `z` |
| `pp` | `int**` | Puntero a puntero que se pasa a funciones |
| `local` (en `proceso1`) | `int` | Variable local temporal |
| `q` (en `proceso1`) | `int*` | Alias local del puntero recibido por `pp` y luego redirigido a `r` |
| `r` (en `proceso1`) | `int*` | Puntero recibido como argumento adicional |
| `aux` (en `proceso2`) | `int` | Variable local temporal |
| `t` (en `proceso2`) | `int*` | Alias local del puntero recibido por `pp` |

---

### Desafío

```cpp
#include <iostream>
using namespace std;

void bloque1(int a[], int** pp) {
    int local[3] = {7, 8, 9};
    int* q = *pp;

    q[1] = q[1] + local[0];
    local[2] = q[0] + q[1];

    q = local;
    q[0] = q[0] + 5;
    q[1] = q[0] + a[2];
}

void bloque2(int** pp) {
    int local[3] = {1, 1, 1};
    int* nuevo = new int[3];

    nuevo[0] = (*pp)[0] + local[0];
    nuevo[1] = (*pp)[1] + local[1];
    nuevo[2] = (*pp)[0] + (*pp)[2];

    *pp = nuevo;

    local[0] = 50;
    nuevo[1] = nuevo[1] + local[0];
}

void bloque3(int** pp, int a[]) {
    int temp[3] = {2, 4, 6};
    int* r = a;

    (*pp)[2] = (*pp)[2] - temp[1];
    r[0] = r[0] + (*pp)[0];

    r = temp;
    r[1] = r[1] + 10;
}

int main() {
    int v[3] = {4, 6, 8};

    int* p = v;
    int** pp = &p;

    bloque1(v, pp);
    bloque2(pp);
    bloque3(pp, v);

    cout << "v[0] = " << v[0] << endl;
    cout << "v[1] = " << v[1] << endl;
    cout << "v[2] = " << v[2] << endl;
    cout << "p[0] = " << p[0] << endl;
    cout << "p[1] = " << p[1] << endl;
    cout << "p[2] = " << p[2] << endl;
    cout << "**pp = " << **pp << endl;

    delete[] p;
    return 0;
}
```

**Rutee claramente e indique la salida.**

| Variable | Tipo | Rol en el ejercicio |
|---|---|---|
| `v` | `int[3]` | Arreglo principal de `main` |
| `p` | `int*` | Puntero que inicialmente apunta a `v` y luego puede redirigirse |
| `pp` | `int**` | Puntero a puntero compartido entre bloques |
| `a` (en `bloque1`/`bloque3`) | `int[]` | Parámetro arreglo enlazado a `v` |
| `q` (en `bloque1`) | `int*` | Alias local de `*pp`, luego redirigido a `local` |
| `local` (en `bloque1`) | `int[3]` | Arreglo local temporal |
| `local` (en `bloque2`) | `int[3]` | Arreglo local temporal |
| `nuevo` (en `bloque2`) | `int*` | Arreglo dinámico reservado con `new[]` y asignado a `*pp` |
| `temp` (en `bloque3`) | `int[3]` | Arreglo local temporal |
| `r` (en `bloque3`) | `int*` | Puntero local primero a `a` y luego a `temp` |

---