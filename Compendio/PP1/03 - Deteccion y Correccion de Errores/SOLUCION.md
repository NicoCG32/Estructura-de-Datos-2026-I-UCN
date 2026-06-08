# III. Deteccion y Correccion de Errores

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [III.1](#ejercicio-iii1) | [III.2](#ejercicio-iii2) | [III.3](#ejercicio-iii3) | [III.4](#ejercicio-iii4) | [III.5](#ejercicio-iii5)
- [III.6](#ejercicio-iii6) | [III.7](#ejercicio-iii7) | [III.8](#ejercicio-iii8) | [III.9](#ejercicio-iii9) | [III.10](#ejercicio-iii10)
- [III.11](#ejercicio-iii11) | [III.12](#ejercicio-iii12) | [III.13](#ejercicio-iii13) | [III.14](#ejercicio-iii14) | [III.15](#ejercicio-iii15)
- [III.16](#ejercicio-iii16) | [III.17](#ejercicio-iii17) | [III.18](#ejercicio-iii18) | [III.19](#ejercicio-iii19) | [III.20](#ejercicio-iii20)


## Cobertura actual

- Ejercicios con pauta desarrollada: `III.1`, `III.2`, `III.3`, `III.4`, `III.5`, `III.6`, `III.7`, `III.8`, `III.9`, `III.10`, `III.11`, `III.12`, `III.13`, `III.14`, `III.15`, `III.16`, `III.17`, `III.18`, `III.19`, `III.20`.
- Ejercicios aun sin desarrollar en esta pauta: `ninguno`.

## Pauta desarrollada

## Ejercicio III.1
Error:

`x` es un entero, pero `p` es un puntero a entero. Un puntero debe almacenar una direccion, no un valor entero comun.

Versión corregida:

```cpp
int main() {
    int x = 5;
    int* p = &x;
    return 0;
}
```

## Ejercicio III.2
Código original:

```cpp
int* p = new int[5];
delete p;
```

Error:

La memoria fue reservada con `new[]`, por lo tanto debe liberarse con `delete[]`.
Nota: este error es "soportado" por algunas versiones de c++, y no se considera como tal.

Versión corregida:

```cpp
int* p = new int[5];
p[0] = 10;
delete[] p;
```

## Ejercicio III.3
Errores:

1. `a` es un puntero, por lo que `a.edad` es incorrecto.
2. Para acceder a un miembro a través de un puntero se debe usar `->`.

Versión corregida:

```cpp
# include <iostream>
using namespace std;

class Alumno {
public:
    int edad;
};

int main() {
    Alumno* a = new Alumno();
    a->edad = 20;
    cout << a->edad << endl;
    delete a;
    return 0;
}
```

## Ejercicio III.4
Errores:

1. La clase usa el atributo `nombre`, pero no lo declara.
2. Conviene declarar el atributo dentro de la clase.

Versión corregida:

```cpp
# include <iostream>
# include <string>
using namespace std;

class Persona {
private:
    string nombre;

public:
    Persona(string nombre) {
        this->nombre = nombre;
    }
};
```

## Ejercicio III.5
Error:

`override` solo puede usarse si el método de la clase base es `virtual`. En el código original, `Base::mostrar()` no es virtual.

Versión corregida:

```cpp
# include <iostream>
using namespace std;

class Base {
public:
    virtual void mostrar() { cout << "Base" << endl; }
};

class Hijo : public Base {
public:
    void mostrar() override { cout << "Hijo" << endl; }
};
```

## Ejercicio III.6
Error:

La función retorna la direccion de una variable local. Esa variable deja de existir al salir de la función, por lo que el puntero queda colgando.

Versión corregida:

```cpp
int* crear() {
    int* p = new int(10);
    return p;
}
```

## Ejercicio III.7
Errores:

1. `stack` no tiene operación `front()`. La operación correcta es `top()`.
2. Falta incluir `<iostream>` si se usa `cout`.

Versión corregida:

```cpp
# include <stack>
# include <iostream>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    cout << s.top() << endl;
    return 0;
}
```

## Ejercicio III.8
Errores:

1. `queue` no tiene operación `top()`.
2. Para consultar el primer elemento se usa `front()`.
3. Falta incluir `<iostream>`.

Versión corregida:

```cpp
# include <queue>
# include <iostream>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << endl;
    return 0;
}
```

## Ejercicio III.9
Código original:

```cpp
Padre* p = new Hijo();
delete p;
```

Problema:

La clase base `Padre` no tiene destructor virtual. Eliminar un objeto derivado por un puntero base en esas condiciones produce comportamiento indefinido.

Versión corregida:

```cpp
class Padre {
public:
    virtual ~Padre() { cout << "~Padre()" << endl; }
};

class Hijo : public Padre {
public:
    ~Hijo() override { cout << "~Hijo()" << endl; }
};
```

Con eso, `delete p;` destruye correctamente primero `Hijo` y luego `Padre`.

## Ejercicio III.10
Problema:

`&v[3]` apunta una posición despues del último elemento valido del arreglo. Formar ese puntero es valido, pero desreferenciarlo con `*p` produce acceso fuera de rango.

Versión corregida:

```cpp
# include <iostream>
using namespace std;

int main() {
    int v[3] = {1, 2, 3};
    int* p = &v[2];
    cout << *p << endl;
    return 0;
}
```

---

## Ejercicio III.11
Error:

Una referencia debe inicializarse al momento de declararse.

Corrección:

```cpp
int x = 5;
int& r = x;
```

## Ejercicio III.12
Error:

`v[5]` está fuera de rango en un arreglo de tamaño `5`.

Corrección:

Usar un índice entre `0` y `4`.

## Ejercicio III.13
Error:

La clase `A` no tiene constructor por defecto.

Corrección:

```cpp
A obj(10);
```

o agregar un constructor sin parámetros.

## Ejercicio III.14
Error:

Se llama `top()` sobre una pila vacía.

Corrección:

Validar primero:

```cpp
if (!s.empty()) cout << s.top() << endl;
```

## Ejercicio III.15
Error:

Se llama `front()` sobre una cola vacía.

Corrección:

```cpp
if (!q.empty()) cout << q.front() << endl;
```

## Ejercicio III.16
Error:

Memoria reservada con `new` se libera con `delete`, no con `delete[]`.

Corrección:

```cpp
int* p = new int;
delete p;
```

## Ejercicio III.17
Error:

La firma `void f()` no coincide con `virtual void f(int x)`; por eso `override` es inválido.

Corrección:

```cpp
void f(int x) override {}
```

## Ejercicio III.18
Error:

`p` apunta a memoria automática (`x`), por lo que no debe liberarse con `delete`.

Corrección:

Eliminar la línea `delete p;`.

## Ejercicio III.19
Error:

`x` es miembro `private` y no puede accederse directamente desde `main`.

Corrección:

Usar métodos públicos (`setter/getter`) o cambiar el nivel de acceso si fuese necesario.

## Ejercicio III.20
Error:

Se desreferencia un puntero nulo.

Corrección:

Asignar una dirección válida antes de usar `*p`.
