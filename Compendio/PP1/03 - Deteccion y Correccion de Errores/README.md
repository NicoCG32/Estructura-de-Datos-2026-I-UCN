# III. Deteccion y Correccion de Errores

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene estudiarlo junto con herencia y polimorfismo. La meta aquí no es "adivinar qué falla", sino aprender a clasificar el error: sintaxis, acceso a memoria, firma incoherente, mal uso de una estructura o problema de diseño.

## Índice para estudiar

Primera pasada sugerida:

- [III.1](#ejercicio-iii1) | [III.2](#ejercicio-iii2) | [III.5](#ejercicio-iii5) | [III.9](#ejercicio-iii9)

Segunda pasada sugerida:

- [III.6](#ejercicio-iii6) | [III.7](#ejercicio-iii7) | [III.8](#ejercicio-iii8) | [III.10](#ejercicio-iii10)

Banco completo:

- [III.1](#ejercicio-iii1) | [III.2](#ejercicio-iii2) | [III.3](#ejercicio-iii3) | [III.4](#ejercicio-iii4) | [III.5](#ejercicio-iii5)
- [III.6](#ejercicio-iii6) | [III.7](#ejercicio-iii7) | [III.8](#ejercicio-iii8) | [III.9](#ejercicio-iii9) | [III.10](#ejercicio-iii10)
- [III.11](#ejercicio-iii11) | [III.12](#ejercicio-iii12) | [III.13](#ejercicio-iii13) | [III.14](#ejercicio-iii14) | [III.15](#ejercicio-iii15)
- [III.16](#ejercicio-iii16) | [III.17](#ejercicio-iii17) | [III.18](#ejercicio-iii18) | [III.19](#ejercicio-iii19) | [III.20](#ejercicio-iii20)

## Como estudiar este tema

Cuando resuelva un ejercicio:

- señale primero la línea exacta donde aparece el problema;
- explique por qué falla usando lenguaje técnico, no solo "está malo";
- distinga si el problema impide compilar, genera comportamiento indefinido o rompe el diseño;
- proponga una corrección coherente con el contexto del código.

### Ejercicio III.1

```cpp
int main() {
    int x = 5;
    int* p = x;
    return 0;
}
```

### Ejercicio III.2

```cpp
# include <iostream>
using namespace std;

int main() {
    int* p = new int[5];
    p[0] = 10;
    delete p;
    return 0;
}
```

### Ejercicio III.3

```cpp
# include <iostream>
using namespace std;

class Alumno {
public:
    int edad;
};

int main() {
    Alumno* a = new Alumno();
    a.edad = 20;
    cout << a->edad << endl;
    delete a;
    return 0;
}
```

### Ejercicio III.4

```cpp
# include <iostream>
using namespace std;

class Persona {
public:
    Persona(string nombre) {
        this->nombre = nombre;
    }
};
```

### Ejercicio III.5

```cpp
# include <iostream>
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

### Ejercicio III.6

```cpp
int* crear() {
    int x = 10;
    return &x;
}
```

### Ejercicio III.7

```cpp
# include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    cout << s.front() << endl;
    return 0;
}
```

### Ejercicio III.8

```cpp
# include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.top() << endl;
    return 0;
}
```

### Ejercicio III.9

```cpp
# include <iostream>
using namespace std;

class Padre {
public:
    ~Padre() { cout << "~Padre()" << endl; }
};

class Hijo : public Padre {
public:
    ~Hijo() { cout << "~Hijo()" << endl; }
};

int main() {
    Padre* p = new Hijo();
    delete p;
    return 0;
}
```

### Ejercicio III.10

```cpp
# include <iostream>
using namespace std;

int main() {
    int v[3] = {1, 2, 3};
    int* p = &v[3];
    cout << *p << endl;
    return 0;
}
```

### Ejercicio III.11

```cpp
int main() {
    int x = 5;
    int& r;
    r = x;
    return 0;
}
```

### Ejercicio III.12

```cpp
# include <iostream>
using namespace std;

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    cout << v[5] << endl;
    return 0;
}
```

### Ejercicio III.13

```cpp
class A {
public:
    A(int x) {}
};

int main() {
    A obj;
    return 0;
}
```

### Ejercicio III.14

```cpp
# include <stack>
# include <iostream>
using namespace std;

int main() {
    stack<int> s;
    cout << s.top() << endl;
    return 0;
}
```

### Ejercicio III.15

```cpp
# include <queue>
# include <iostream>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.pop();
    cout << q.front() << endl;
    return 0;
}
```

### Ejercicio III.16

```cpp
int main() {
    int* p = new int;
    delete[] p;
    return 0;
}
```

### Ejercicio III.17

```cpp
class Base {
public:
    virtual void f(int x) {}
};

class Derivada : public Base {
public:
    void f() override {}
};
```

### Ejercicio III.18

```cpp
int main() {
    int x = 10;
    int* p = &x;
    delete p;
    return 0;
}
```

### Ejercicio III.19

```cpp
class A {
private:
    int x;
};

int main() {
    A a;
    a.x = 5;
    return 0;
}
```

### Ejercicio III.20

```cpp
# include <iostream>
using namespace std;

int main() {
    int* p = nullptr;
    cout << *p << endl;
    return 0;
}
```

---
