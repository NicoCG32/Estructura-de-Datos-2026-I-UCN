# Ayudantía 1: Soluciones
## Índice

- [Ejercicio 1: Punteros Básicos](#ejercicio-1-punteros-básicos)
- [Ejercicio 2: Modificación a través de Punteros](#ejercicio-2-modificación-a-través-de-punteros)
- [Ejercicio 3: Asignación Errónea de Puntero](#ejercicio-3-asignación-errónea-de-puntero)
- [Ejercicio 4: Aritmética de Punteros](#ejercicio-4-aritmética-de-punteros)
- [Ejercicio 5: Punteros en Funciones](#ejercicio-5-punteros-en-funciones)
- [Ejercicio 6: Punteros a Punteros](#ejercicio-6-punteros-a-punteros)
- [Ejercicio 7: Punteros a Punteros en Funciones](#ejercicio-7-punteros-a-punteros-en-funciones)


Soluciones: Introducción a C++ y Punteros

### Ejercicio 1: Punteros Básicos

### Código
```cpp
# include <iostream>
using namespace std;

int main() {
	int x = 10;                          // Línea 5
	int* p = &x;                         // Línea 6

	cout << "x = " << x << endl;         // Línea 8
	cout << "&x = " << &x << endl;       // Línea 9
	cout << "p = " << p << endl;         // Línea 10
	cout << "*p = " << *p << endl;       // Línea 11

	return 0;
}
```

### Ruteo Línea por Línea

| Línea | Operación | Estado de Variables |
|-------|-----------|------------------|
| 5 | `int x = 10;` | `x = 10` (en memoria, ej. dirección 0x1000) |
| 6 | `int* p = &x;` | `p = 0x1000` (almacena dirección de x) |
| 8 | Imprime `"x = " << x` | Accede a x directamente: `10` |
| 9 | Imprime `"&x = " << &x` | Obtiene dirección de x: `0x1000` (aprox.) |
| 10 | Imprime `"p = " << p` | Imprime valor de p (dirección): `0x1000` (aprox.) |
| 11 | Imprime `"*p = " << *p` | Desreferencia p, accede a x: `10` |

### Salida
```
x = 10
&x = 0x[dirección de x]
p = 0x[dirección de x]
*p = 10
```

---

### Ejercicio 2: Modificación a través de Punteros

### Código
```cpp
# include <iostream>
using namespace std;

int main() {
	int a = 7;                                    // Línea 5
	int b = 20;                                   // Línea 6

	int* p = &a;                                  // Línea 8

	cout << "Inicio:" << endl;                    // Línea 10
	cout << "a = " << a << ", b = " << b << ", *p = " << *p << endl;  // Línea 11

	*p = 15;                                      // Línea 13

	cout << "Luego de *p = 15:" << endl;          // Línea 15
	cout << "a = " << a << ", b = " << b << ", *p = " << *p << endl;  // Línea 16

	p = &b;                                       // Línea 18
	*p = 30;                                      // Línea 19

	cout << "Luego de p = &b y *p = 30:" << endl; // Línea 21
	cout << "a = " << a << ", b = " << b << ", *p = " << *p << endl;  // Línea 22

	return 0;
}
```

### Ruteo Línea por Línea

| Línea | Operación | Estado de Variables |
|-------|-----------|------------------|
| 5 | `int a = 7;` | `a = 7` |
| 6 | `int b = 20;` | `b = 20` |
| 8 | `int* p = &a;` | `p` apunta a `a` |
| 11 | Imprime estado inicial | `a = 7, b = 20, *p = 7` |
| 13 | `*p = 15;` | Modifica lo apuntado por p (a): `a = 15`, `*p = 15` |
| 16 | Imprime después de modificar | `a = 15, b = 20, *p = 15` |
| 18 | `p = &b;` | `p` ahora apunta a `b` |
| 19 | `*p = 30;` | Modifica lo apuntado por p (b): `b = 30`, `*p = 30` |
| 22 | Imprime estado final | `a = 15, b = 30, *p = 30` |

### Salida
```
Inicio:
a = 7, b = 20, *p = 7
Luego de *p = 15:
a = 15, b = 20, *p = 15
Luego de p = &b y *p = 30:
a = 15, b = 30, *p = 30
```

---

### Ejercicio 3: Asignación Errónea de Puntero

### Código
```cpp
# include <iostream>
using namespace std;

int main() {
    int x = 12;                    // Línea 5
    int* p = &x;                   // Línea 6
    int y = *p + 3;                // Línea 7
    int* q = y;                    // Línea 8 ❌ ERROR

    cout << "x = " << x << endl;
    cout << "*p = " << *p << endl;
    cout << "y = " << y << endl;
    cout << "*q = " << *q << endl;

    return 0;
}
```

### Ruteo Línea por Línea

| Línea | Operación | Estado de Variables | Nota |
|-------|-----------|------------------|------|
| 5 | `int x = 12;` | `x = 12` | - |
| 6 | `int* p = &x;` | `p` apunta a x | - |
| 7 | `int y = *p + 3;` | `y = 12 + 3 = 15` | - |
| 8 | `int* q = y;` | ERROR: intenta asignar `int` a `int*` | ❌ Error conceptual: y es un valor (15), no una dirección |

### Análisis del Error
- **Problema**: Línea 8 intenta asignar un valor entero (`y = 15`) a un puntero (`q`)
- **Corrección**: Debería ser `int* q = &y;` para que q apunte a y

### Salida Esperada
**El programa NO compila** debido al error de tipo en la línea 8.

---

### Ejercicio 4: Aritmética de Punteros

### Código
```cpp
# include <iostream>
using namespace std;

int main() {
    int v[5] = {8, 3, 6, 1, 9};     // Línea 5
    int* p = v;                      // Línea 6

    cout << "1) " << v[0] << endl;   // Línea 8
    cout << "2) " << *p << endl;     // Línea 9
    cout << "3) " << *(p + 2) << endl; // Línea 10
    cout << "4) " << p[3] << endl;   // Línea 11

    p = p + 1;                        // Línea 13

    cout << "5) " << *p << endl;     // Línea 15
    cout << "6) " << *(p + 2) << endl; // Línea 16

    *(p + 1) = 20;                    // Línea 18

    cout << "7) " << v[2] << endl;   // Línea 20
    cout << "8) " << *(v + 2) << endl; // Línea 21
    cout << "9) " << p[1] << endl;   // Línea 22

    return 0;
}
```

### Ruteo Línea por Línea

| Línea | Operación | Estado de Variables | Explicación |
|-------|-----------|------------------|-------------|
| 5 | `int v[5] = {8, 3, 6, 1, 9};` | `v = [8, 3, 6, 1, 9]` con índices 0-4 | - |
| 6 | `int* p = v;` | `p` apunta a `v[0]` (dirección de v) | - |
| 8 | `v[0]` | Imprime `8` | Acceso directo al índice 0 |
| 9 | `*p` | Imprime `8` | p apunta a v[0] |
| 10 | `*(p + 2)` | Imprime `6` | p+2 apunta a v[2] |
| 11 | `p[3]` | Imprime `1` | Equivalente a *(p+3), apunta a v[3] |
| 13 | `p = p + 1;` | `p` ahora apunta a `v[1]` | p se mueve una posición adelante |
| 15 | `*p` | Imprime `3` | p ahora apunta a v[1] |
| 16 | `*(p + 2)` | Imprime `9` | p+2 apunta a v[3] |
| 18 | `*(p + 1) = 20;` | `v[2] = 20` | p+1 apunta a v[2], se modifica |
| 20 | `v[2]` | Imprime `20` | v[2] fue modificado |
| 21 | `*(v + 2)` | Imprime `20` | Equivalente a v[2] |
| 22 | `p[1]` | Imprime `20` | p apunta a v[1], p[1] es v[2] |

### Salida
```
1) 8
2) 8
3) 6
4) 1
5) 3
6) 9
7) 20
8) 20
9) 20
```

---

### Ejercicio 5: Punteros en Funciones

### Código
```cpp
# include <iostream>
using namespace std;

void modificar(int* p) {                // Función definida
    *p = *p + 4;
}

int main() {
    int x = 6;                          // Línea 9
    int y = 2;                          // Línea 10
    int* q = &x;                        // Línea 11

    modificar(q);                       // Línea 13
    modificar(&y);                      // Línea 14

    q = &y;                             // Línea 16
    *q = *q + x;                        // Línea 17

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*q = " << *q << endl;

    return 0;
}
```

### Ruteo Línea por Línea

| Línea | Operación | Estado de Variables |
|-------|-----------|------------------|
| 9 | `int x = 6;` | `x = 6` |
| 10 | `int y = 2;` | `y = 2` |
| 11 | `int* q = &x;` | `q` apunta a x |
| 13 | `modificar(q);` **Llamada a función** | **Entra en modificar con p = &x** |
|  | `*p = *p + 4;` | `*p = 6 + 4 = 10` → `x = 10` |
|  | Retorna | `x = 10`, `q` sigue apuntando a x |
| 14 | `modificar(&y);` **Llamada a función** | **Entra en modificar con p = &y** |
|  | `*p = *p + 4;` | `*p = 2 + 4 = 6` → `y = 6` |
|  | Retorna | `y = 6` |
| 16 | `q = &y;` | `q` ahora apunta a y |
| 17 | `*q = *q + x;` | `*q = 6 + 10 = 16` → `y = 16` |
| 19-21 | Imprime resultado final | `x = 10, y = 16, *q = 16` |

### Salida
```
x = 10
y = 16
*q = 16
```

---

### Ejercicio 6: Punteros a Punteros

### Código
```cpp
# include <iostream>
using namespace std;

int main() {
    int x = 4;                          // Línea 5
    int y = 9;                          // Línea 6

    int* p = &x;                        // Línea 8
    int** pp = &p;                      // Línea 9

    **pp = **pp + 3;                    // Línea 11
    *p = *p * 2;                        // Línea 12

    *pp = &y;                           // Línea 14
    **pp = **pp - 4;                    // Línea 15
    *p = *p + x;                        // Línea 16

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "*p = " << *p << endl;
    cout << "**pp = " << **pp << endl;

    return 0;
}
```

### Ruteo Línea por Línea

| Línea | Operación | Estado de Variables |
|-------|-----------|------------------|
| 5 | `int x = 4;` | `x = 4` |
| 6 | `int y = 9;` | `y = 9` |
| 8 | `int* p = &x;` | `p` → x (p apunta a x) |
| 9 | `int** pp = &p;` | `pp` → p (pp apunta a p) |
| 11 | `**pp = **pp + 3;` | `**pp = 4 + 3 = 7` → `x = 7` |
| 12 | `*p = *p * 2;` | `*p = 7 * 2 = 14` → `x = 14` |
| 14 | `*pp = &y;` | Ahora `pp` → p, `p` → y (p cambia para apuntar a y) |
| 15 | `**pp = **pp - 4;` | `**pp = 9 - 4 = 5` → `y = 5` |
| 16 | `*p = *p + x;` | `*p = 5 + 14 = 19` → `y = 19` |
| 18-21 | Imprime resultados | `x = 14, y = 19, *p = 19, **pp = 19` |

### Salida
```
x = 14
y = 19
*p = 19
**pp = 19
```

---

### Ejercicio 7: Punteros a Punteros en Funciones

### Código
```cpp
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

### Ruteo Línea por Línea

#### Estado Inicial en main (líneas 29-35)
| Estado | Valor |
|--------|-------|
| `x` | 5 |
| `y` | 8 |
| `z` | 12 |
| `p` | → x |
| `pp` | → p |

#### Llamada 1: proceso1(pp, &y)
| Línea en proceso1 | Operación | Cambio |
|---|---|---|
| local = 3 | Inicializa local | local = 3 |
| q = *pp | q apunta a x | q → x |
| **pp = **pp + local | **pp = 5 + 3 = 8 | **x = 8** |
| *q = *q * 2 | *q = 8 * 2 = 16 | **x = 16** |
| q = r | q ahora apunta a y | q → y |
| *q = *q + local | *q = 8 + 3 = 11 | **y = 11** |
| local = *q | local = 11 | (variable local, no afecta) |
| local = local + 5 | local = 16 | (variable local, no afecta) |

**Después de proceso1(pp, &y):** `x = 16, y = 11`

#### Línea 37: p = &z
- Ahora `p` → z
- `**pp` = 12 (porque pp → p → z)

#### Llamada 2: proceso2(pp)
| Línea en proceso2 | Operación | Cambio |
|---|---|---|
| aux = 4 | Inicializa aux | aux = 4 |
| t = *pp | t apunta a z | t → z |
| **pp = **pp - aux | **pp = 12 - 4 = 8 | **z = 8** |
| t = &aux | t ahora apunta a aux | t → aux (variable local) |
| *t = *t + 6 | *t = 4 + 6 = 10 | aux = 10 (local) |
| aux = aux + **pp | aux = 10 + 8 = 18 | aux = 18 (no afecta z) |

**Después de proceso2(pp):** `z = 8`

#### Llamada 3: proceso1(pp, &x)
| Línea en proceso1 | Operación | Cambio |
|---|---|---|
| local = 3 | Inicializa local | local = 3 |
| q = *pp | q apunta a z | q → z |
| **pp = **pp + local | **pp = 8 + 3 = 11 | **z = 11** |
| *q = *q * 2 | *q = 11 * 2 = 22 | **z = 22** |
| q = r | q ahora apunta a x | q → x |
| *q = *q + local | *q = 16 + 3 = 19 | **x = 19** |
| local = *q | local = 19 | (local) |
| local = local + 5 | local = 24 | (local) |

**Después de proceso1(pp, &x):** `x = 19, z = 22`

#### Salida Final
```
x = 19
y = 11
z = 22
*p = 22
**pp = 22
```

---

## Desafío: Arreglos Dinámicos y Punteros Complejos

⚠️ **Nota**: Este ejercicio es más complejo y requiere seguimiento detallado de múltiples niveles de indirección y memoria dinámica.

### Código
```cpp
# include <iostream>
using namespace std;

void bloque1(int a[], int** pp) {
    int local[3] = {7, 8, 9};
    int* q = *pp;

    q[1] = q[1] + local[0];      // q[1] += 7
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

### Ruteo Línea por Línea

#### Estado Inicial
```
v = [4, 6, 8]
p → v
pp → p
```

#### Llamada 1: bloque1(v, pp)
**Parámetros recibidos:** `a = v (= [4, 6, 8])`, `pp = &p`

| Operación | Cambio |
|-----------|--------|
| `local = [7, 8, 9]` | local creado |
| `q = *pp` | q → v (q apunta al arreglo v) |
| `q[1] = q[1] + local[0]` | `q[1] = 6 + 7 = 13` → **v[1] = 13** |
| `local[2] = q[0] + q[1]` | `local[2] = 4 + 13 = 17` |
| `q = local` | q → local (q apunta a local dentro de bloque1) |
| `q[0] = q[0] + 5` | `q[0] = 7 + 5 = 12` |
| `q[1] = q[0] + a[2]` | `q[1] = 12 + 8 = 20` |
| **Fin**: local se destruye (pero q salió del scope) | **v = [4, 13, 8]** |

#### Línea: p = &z (Espera, el código dice p = &z, pero en main es p = &... verificar)

Revisando: en main no hay `p = &z`. Seguimos con lo que hay:

Después de bloque1: **v = [4, 13, 8]**

#### Llamada 2: bloque2(pp)
**Recibe:** `pp = &p` (donde p → v)

| Operación | Cambio |
|-----------|--------|
| `local = [1, 1, 1]` | local creado |
| `nuevo = new int[3]` | Reserva memoria dinámica |
| `nuevo[0] = (*pp)[0] + 1` | `nuevo[0] = v[0] + 1 = 4 + 1 = 5` |
| `nuevo[1] = (*pp)[1] + 1` | `nuevo[1] = v[1] + 1 = 13 + 1 = 14` |
| `nuevo[2] = (*pp)[0] + (*pp)[2]` | `nuevo[2] = 4 + 8 = 12` |
| `*pp = nuevo` | **p ahora apunta a nuevo (p → nuevo)** |
| `local[0] = 50` | local = [50, 1, 1] |
| `nuevo[1] = nuevo[1] + 50` | `nuevo[1] = 14 + 50 = 64` |
| **Fin**: local se destruye, nuevo persiste | **nuevo = [5, 64, 12]** |

**Importante:** Ahora `p → nuevo` (el arreglo dinámico), no a `v`

#### Llamada 3: bloque3(pp, v)
**Recibe:** `pp = &p` (donde p → nuevo), `a = v (= [4, 13, 8])`

| Operación | Cambio |
|-----------|--------|
| `temp = [2, 4, 6]` | temp creado |
| `r = a` | r → v |
| `(*pp)[2] = (*pp)[2] - temp[1]` | `(*pp)[2] = nuevo[2] - 4 = 12 - 4 = 8` → **nuevo[2] = 8** |
| `r[0] = r[0] + (*pp)[0]` | `r[0] = v[0] + nuevo[0] = 4 + 5 = 9` → **v[0] = 9** |
| `r = temp` | r → temp |
| `r[1] = r[1] + 10` | `r[1] = 4 + 10 = 14` (pero temp es local) |
| **Fin**: temp, r se destruyen | **v = [9, 13, 8]** |

### Estado Final
```
v = [9, 13, 8]           (arreglo original)
p → nuevo = [5, 64, 8]   (arreglo dinámico)
pp → p
**pp = 5 (nuevo[0])
```

### Salida
```
v[0] = 9
v[1] = 13
v[2] = 8
p[0] = 5
p[1] = 64
p[2] = 8
**pp = 5
```

---

## Resumen de Conceptos Clave

| Concepto | Ejemplo |
|----------|---------|
| **Dirección de una variable** | `&x` obtiene la dirección de x |
| **Desreferencia de puntero** | `*p` accede al valor apuntado |
| **Aritmética de punteros** | `p + 1` mueve el puntero una posición |
| **Puntero a puntero** | `int** pp` es un puntero que apunta a otro puntero |
| **Doble desreferencia** | `**pp` accede al valor final a través de dos niveles |
| **Paso por puntero** | Las funciones pueden modificar variables externas |
| **Memoria dinámica** | `new` reserva memoria, `delete[]` la libera |
