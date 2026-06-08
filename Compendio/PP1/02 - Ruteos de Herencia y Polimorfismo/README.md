# II. Ruteos de Herencia y Polimorfismo

La pauta de este tema se encuentra en [SOLUCION.md](SOLUCION.md).

Este bloque conviene estudiarlo después de punteros y arreglos. Aquí el objetivo no es solo leer una salida, sino entender qué versión de un método se ejecuta, por qué ocurre eso y cómo influye el tipo estático frente al tipo real del objeto.

## Índice para estudiar

Primera pasada sugerida:

- [II.2](#ejercicio-ii2) | [II.4](#ejercicio-ii4) | [II.6](#ejercicio-ii6) | [II.10](#ejercicio-ii10)

Segunda pasada sugerida:

- [II.8](#ejercicio-ii8) | [II.9](#ejercicio-ii9) | [II.11](#ejercicio-ii11) | [II.16](#ejercicio-ii16)

Banco completo:

- [II.1](#ejercicio-ii1) | [II.2](#ejercicio-ii2) | [II.3](#ejercicio-ii3) | [II.4](#ejercicio-ii4) | [II.5](#ejercicio-ii5)
- [II.6](#ejercicio-ii6) | [II.7](#ejercicio-ii7) | [II.8](#ejercicio-ii8) | [II.9](#ejercicio-ii9) | [II.10](#ejercicio-ii10)
- [II.11](#ejercicio-ii11) | [II.12](#ejercicio-ii12) | [II.13](#ejercicio-ii13) | [II.14](#ejercicio-ii14) | [II.15](#ejercicio-ii15)
- [II.16](#ejercicio-ii16) | [II.17](#ejercicio-ii17) | [II.18](#ejercicio-ii18) | [II.19](#ejercicio-ii19) | [II.20](#ejercicio-ii20)

## Como estudiar este tema

Antes de revisar la solución:

- identifique el tipo estático de cada variable, puntero o referencia;
- anote el tipo real del objeto cuando haya herencia;
- marque si el método es `virtual` o no, porque eso cambia completamente la resolución;
- cuando corresponda, escriba el orden exacto de construcción y destrucción.

### Ejercicio II.1

```cpp
# include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};

class B : public A {
public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
};

int main() {
    B obj;
    return 0;
}
```

### Ejercicio II.2

```cpp
# include <iostream>
using namespace std;

class Base {
public:
    void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
};

class Derivada : public Base {
public:
    void f() { cout << "Derivada::f" << endl; }
    void g() override { cout << "Derivada::g" << endl; }
};

int main() {
    Derivada d;
    Base* p = &d;

    p->f();
    p->g();
    return 0;
}
```

### Ejercicio II.3

```cpp
# include <iostream>
using namespace std;

class Animal {
public:
    virtual void sonido() { cout << "Generico" << endl; }
};

class Perro : public Animal {
public:
    void sonido() override { cout << "Guau" << endl; }
};

void probar(Animal& a) {
    a.sonido();
}

int main() {
    Perro p;
    probar(p);
    return 0;
}
```

### Ejercicio II.4

```cpp
# include <iostream>
using namespace std;

class Padre {
public:
    Padre() { cout << "Padre()" << endl; }
    virtual ~Padre() { cout << "~Padre()" << endl; }
};

class Hijo : public Padre {
public:
    Hijo() { cout << "Hijo()" << endl; }
    ~Hijo() override { cout << "~Hijo()" << endl; }
};

int main() {
    Padre* p = new Hijo();
    delete p;
    return 0;
}
```

### Ejercicio II.5

```cpp
# include <iostream>
using namespace std;

class X {
public:
    virtual void ver() { cout << "X" << endl; }
};

class Y : public X {
public:
    void ver() override { cout << "Y" << endl; }
};

int main() {
    X a;
    Y b;
    X* p = &a;
    p->ver();
    p = &b;
    p->ver();
    return 0;
}
```

### Ejercicio II.6

```cpp
# include <iostream>
using namespace std;

class Base {
public:
    virtual void mostrar() { cout << "Base" << endl; }
};

class Derivada : public Base {
public:
    void mostrar() override { cout << "Derivada" << endl; }
};

int main() {
    Derivada d;
    Base b = d;

    b.mostrar();
    d.mostrar();
    return 0;
}
```

### Ejercicio II.7

```cpp
# include <iostream>
using namespace std;

class Persona {
public:
    Persona() { cout << "Persona()" << endl; }
};

class Estudiante : public Persona {
public:
    Estudiante() { cout << "Estudiante()" << endl; }
};

class Ayudante : public Estudiante {
public:
    Ayudante() { cout << "Ayudante()" << endl; }
};

int main() {
    Ayudante a;
    return 0;
}
```

### Ejercicio II.8

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual void f() { cout << "A::f" << endl; }
};

class B : public A {
public:
    void f() override { cout << "B::f" << endl; }
};

void ejecutar(A a) {
    a.f();
}

int main() {
    B b;
    ejecutar(b);
    return 0;
}
```

### Ejercicio II.9

```cpp
# include <iostream>
using namespace std;

class Figura {
public:
    virtual void dibujar() { cout << "Figura" << endl; }
    void nombre() { cout << "Nombre Figura" << endl; }
};

class Circulo : public Figura {
public:
    void dibujar() override { cout << "Circulo" << endl; }
    void nombre() { cout << "Nombre Circulo" << endl; }
};

int main() {
    Circulo c;
    Figura& r = c;

    r.dibujar();
    r.nombre();
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

### Ejercicio II.11

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual void f() { cout << "A::f" << endl; }
    void g() { cout << "A::g" << endl; }
};

class B : public A {
public:
    void f() override { cout << "B::f" << endl; }
    void g() { cout << "B::g" << endl; }
};

int main() {
    B b;
    A& r = b;

    r.f();
    r.g();
    return 0;
}
```

### Ejercicio II.12

```cpp
# include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};

class B : public A {
public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
};

class C : public B {
public:
    C() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
};

int main() {
    C obj;
    return 0;
}
```

### Ejercicio II.13

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual void f() { cout << "A" << endl; }
};

class B : public A {
public:
    void f() override { cout << "B" << endl; }
};

int main() {
    B b;
    A a = b;
    A* p = &b;

    a.f();
    p->f();
    return 0;
}
```

### Ejercicio II.14

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual void mostrar() { cout << "A" << endl; }
    virtual ~A() {}
};

class B : public A {
public:
    void mostrar() override { cout << "B" << endl; }
};

int main() {
    A* p1 = new A();
    A* p2 = new B();

    p1->mostrar();
    p2->mostrar();

    delete p1;
    delete p2;
    return 0;
}
```

### Ejercicio II.15

```cpp
# include <iostream>
using namespace std;

class A {
public:
    void x() { cout << "A::x" << endl; }
    virtual void y() { cout << "A::y" << endl; }
};

class B : public A {
public:
    void x() { cout << "B::x" << endl; }
    void y() override { cout << "B::y" << endl; }
};

int main() {
    B b;
    A* p = &b;
    B* q = &b;

    p->x();
    q->x();
    p->y();
    q->y();
    return 0;
}
```

### Ejercicio II.16

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual void f() { cout << "A" << endl; }
};

class B : public A {
public:
    void f() override { cout << "B" << endl; }
};

void mostrar(A a) {
    a.f();
}

void mostrarRef(A& a) {
    a.f();
}

int main() {
    B b;
    mostrar(b);
    mostrarRef(b);
    return 0;
}
```

### Ejercicio II.17

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual void f() { cout << "A" << endl; }
};

class B {
public:
    virtual void f() { cout << "B" << endl; }
};

class C : public A, public B {
public:
    void f() override { cout << "C" << endl; }
};

int main() {
    C c;
    A* pa = &c;
    B* pb = &c;

    pa->f();
    pb->f();
    return 0;
}
```

### Ejercicio II.18

```cpp
# include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A()" << endl; }
    virtual ~A() { cout << "~A()" << endl; }
};

class B : public A {
public:
    B() { cout << "B()" << endl; }
    ~B() override { cout << "~B()" << endl; }
};

int main() {
    A* p = new B();
    delete p;
    return 0;
}
```

### Ejercicio II.19

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual void f(int x) { cout << "A " << x << endl; }
};

class B : public A {
public:
    void f() { cout << "B" << endl; }
};

int main() {
    B b;
    A* p = &b;

    p->f(3);
    b.f();
    return 0;
}
```

### Ejercicio II.20

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual int f() { return 1; }
    virtual ~A() {}
};

class B : public A {
public:
    int f() override { return 2; }
};

class C : public B {
public:
    int f() override { return B::f() + 3; }
};

int main() {
    A* p = new C();
    cout << p->f() << endl;
    delete p;
    return 0;
}
```

---
