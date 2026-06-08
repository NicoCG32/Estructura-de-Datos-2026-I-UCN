# I. Ruteos de Punteros y Arreglos

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene estudiarlo al inicio de la ruta. Si todavía te cuesta distinguir entre valor, dirección, aliasing y aritmética de punteros, parte aquí antes de pasar a herencia, polimorfismo o algoritmos.

## Índice para estudiar

Primera pasada sugerida:

- [I.1](#ejercicio-i1) | [I.4](#ejercicio-i4) | [I.9](#ejercicio-i9) | [I.16](#ejercicio-i16)

Segunda pasada sugerida:

- [I.3](#ejercicio-i3) | [I.7](#ejercicio-i7) | [I.13](#ejercicio-i13) | [I.18](#ejercicio-i18)

Banco completo:

- [I.1](#ejercicio-i1) | [I.2](#ejercicio-i2) | [I.3](#ejercicio-i3) | [I.4](#ejercicio-i4) | [I.5](#ejercicio-i5)
- [I.6](#ejercicio-i6) | [I.7](#ejercicio-i7) | [I.8](#ejercicio-i8) | [I.9](#ejercicio-i9) | [I.10](#ejercicio-i10)
- [I.11](#ejercicio-i11) | [I.12](#ejercicio-i12) | [I.13](#ejercicio-i13) | [I.14](#ejercicio-i14) | [I.15](#ejercicio-i15)
- [I.16](#ejercicio-i16) | [I.17](#ejercicio-i17) | [I.18](#ejercicio-i18) | [I.19](#ejercicio-i19) | [I.20](#ejercicio-i20)

## Como estudiar este tema

Antes de mirar la pauta:

- dibuje las variables y escriba con claridad qué dirección guarda cada puntero;
- rutee línea por línea, sin saltarse reasignaciones ni efectos laterales;
- separe siempre "cambio de valor" de "cambio de alias";
- verifique al final tanto el estado de memoria como la salida por pantalla.

### Ejercicio I.1

```cpp
# include <iostream>
using namespace std;

int main() {
    int x = 8;
    int y = 3;
    int* p = &x;

    *p = *p + y;
    p = &y;
    *p = *p * 2;

    cout << x << " " << y << endl;
    return 0;
}
```

### Ejercicio I.2

```cpp
# include <iostream>
using namespace std;

int main() {
    int v[5] = {2, 4, 6, 8, 10};
    int* p = v;

    *(p + 1) = *p + 3;
    p = p + 2;
    *p = *(p - 1) + *(p + 2);

    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << endl;
    return 0;
}
```

### Ejercicio I.3

```cpp
# include <iostream>
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

### Ejercicio I.4

```cpp
# include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 12;
    int* p = &x;
    int** pp = &p;

    **pp = **pp + 2;
    *pp = &y;
    **pp = **pp - x;

    cout << x << " " << y << " " << *p << endl;
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

### Ejercicio I.6

```cpp
# include <iostream>
using namespace std;

int main() {
    int* p = new int[4];

    for (int i = 0; i < 4; i++) {
        p[i] = i + 1;
    }

    int* q = p + 1;
    q[1] = q[0] + p[3];
    p[0] = q[1] - p[1];

    cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;

    delete[] p;
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

### Ejercicio I.8

```cpp
# include <iostream>
using namespace std;

int main() {
    int a[3] = {2, 4, 6};
    int b[3] = {1, 3, 5};

    int* p = a;
    int* q = b;

    *(p + 1) = *q + *(q + 2);
    *(q + 2) = *(p + 1) - *p;

    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    cout << b[0] << " " << b[1] << " " << b[2] << endl;
    return 0;
}
```

### Ejercicio I.9

```cpp
# include <iostream>
using namespace std;

void actualizar(int* p, int n) {
    for (int i = 1; i < n; i++) {
        p[i] = p[i] + p[i - 1];
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    actualizar(v, 5);

    for (int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### Ejercicio I.10

```cpp
# include <iostream>
using namespace std;

int main() {
    int x = 9;
    int y = 4;
    int z = 1;

    int* p = &x;
    int** pp = &p;

    **pp = y + z;
    p = &y;
    *p = x - z;
    p = &z;
    *p = x + y;

    cout << x << " " << y << " " << z << endl;
    return 0;
}
```

### Ejercicio I.11

```cpp
# include <iostream>
using namespace std;

void ajustar(int* p, int* q) {
    *p = *p + 2;
    *q = *q + *p;
}

int main() {
    int x = 1;
    int y = 4;

    ajustar(&x, &y);
    ajustar(&y, &x);

    cout << x << " " << y << endl;
    return 0;
}
```

### Ejercicio I.12

```cpp
# include <iostream>
using namespace std;

int main() {
    int v[6] = {1, 2, 3, 4, 5, 6};
    int* p = v + 2;

    *(p - 1) = *p + v[5];
    p[1] = *(p - 1) - v[0];

    for (int i = 0; i < 6; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### Ejercicio I.13

```cpp
# include <iostream>
using namespace std;

int main() {
    int x = 6;
    int y = 15;
    int* p = &x;
    int** pp = &p;

    **pp = **pp + 3;
    *pp = &y;
    **pp = **pp + x;

    cout << x << " " << y << " " << *p << endl;
    return 0;
}
```

### Ejercicio I.14

```cpp
# include <iostream>
using namespace std;

int main() {
    int v[4] = {2, 5, 8, 11};
    int* p = v;

    for (int i = 1; i < 4; i++) {
        p[i] = p[i] - p[i - 1];
    }

    for (int i = 0; i < 4; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
```

### Ejercicio I.15

```cpp
# include <iostream>
using namespace std;

int main() {
    int* p = new int[5];

    for (int i = 0; i < 5; i++) {
        p[i] = i * 2;
    }

    int* q = p + 1;
    q[2] = q[0] + q[1];
    p[4] = q[2] - p[0];

    for (int i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    delete[] p;
    return 0;
}
```

### Ejercicio I.16

```cpp
# include <iostream>
using namespace std;

void mover(int* p) {
    *(p + 2) = *(p + 1) + 1;
    *p = *(p + 2) - *(p + 1);
}

int main() {
    int v[3] = {4, 7, 2};
    mover(v);

    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    return 0;
}
```

### Ejercicio I.17

```cpp
# include <iostream>
using namespace std;

void cambio(int*& p, int& x) {
    *p = *p + 1;
    p = &x;
    *p = *p + 2;
}

int main() {
    int a = 5;
    int b = 9;
    int* p = &a;

    cambio(p, b);
    *p = *p + a;

    cout << a << " " << b << endl;
    return 0;
}
```

### Ejercicio I.18

```cpp
# include <iostream>
using namespace std;

int main() {
    int a[3] = {1, 4, 7};
    int b[3] = {2, 5, 8};

    int* p = a;
    int* q = b;

    *(p + 2) = *(q + 1) - *p;
    *q = *(p + 2) + *(q + 2);

    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    cout << b[0] << " " << b[1] << " " << b[2] << endl;
    return 0;
}
```

### Ejercicio I.19

```cpp
# include <iostream>
using namespace std;

int main() {
    int x = 2;
    int y = 3;
    int z = 4;

    int* p = &x;
    int* q = &y;

    q = p;
    *q = *q + z;
    p = &z;
    *p = *q + y;

    cout << x << " " << y << " " << z << endl;
    return 0;
}
```

### Ejercicio I.20

```cpp
# include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 10;
    int c = 15;

    int* v[3] = {&a, &b, &c};

    *v[1] = *v[0] + *v[2];
    v[2] = v[0];
    *v[2] = *v[1] - *v[0];

    cout << a << " " << b << " " << c << endl;
    return 0;
}
```

---
