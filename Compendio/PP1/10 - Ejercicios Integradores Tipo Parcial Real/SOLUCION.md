# X. Ejercicios Integradores Tipo Parcial Real

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [X.1](#ejercicio-x1) | [X.2](#ejercicio-x2) | [X.3](#ejercicio-x3) | [X.4](#ejercicio-x4) | [X.5](#ejercicio-x5)
- [X.6](#ejercicio-x6) | [X.7](#ejercicio-x7) | [X.8](#ejercicio-x8) | [X.9](#ejercicio-x9) | [X.10](#ejercicio-x10)
- [X.11](#ejercicio-x11)


## Cobertura actual

- Ejercicios con pauta desarrollada: `X.1`, `X.2`, `X.3`, `X.4`, `X.5`, `X.6`, `X.7`, `X.8`, `X.9`, `X.10`, `X.11`.
- Ejercicios aun sin desarrollar en esta pauta: `ninguno`.

## Pauta desarrollada

## Ejercicio X.1
Arreglo inicial:

```text
nL = [5, ?, ?, ?, ?, ?, ?]
```

Ruteo por iteración:

1. `i = 1`
   `i % 3 == 1`
   `xyz = 1 * 4 / 5 = 0`
   `nL[1] = 0`

2. `i = 2`
   `i % 3 == 2`
   `nL[1] = 2 * 3 = 6`
   luego `nL[2] = xyz = 0`

3. `i = 3`
   `i % 3 == 0`
   `xyz = 5 * 2 = 10`
   `nL[3] = 10`

4. `i = 4`
   `i % 3 == 1`
   `xyz = 4 * 4 / 5 = 3`
   `nL[4] = 3`

5. `i = 5`
   `i % 3 == 2`
   `nL[2] = 5 * 3 = 15`
   luego `nL[5] = 0`

6. `i = 6`
   `i % 3 == 0`
   `xyz = 5 * 2 = 10`
   `nL[6] = 10`

Contenido final:

```text
[5, 6, 15, 10, 3, 0, 10]
```

Salida:

```text
5 6 15 10 3 0 10
```

Observación conceptual:

En las iteraciones donde `i % 3 == 2`, el programa primero modifica una posición intermedia del arreglo usando aritmética de punteros, y después escribe `xyz` en la posición `i`. Como `xyz` sigue valiendo `0`, en esas iteraciones una celda se actualiza con `i * 3` y otra queda en `0`.

## Ejercicio X.2
Errores del código original:

1. En `A::fun(int* ptr)`, el retorno declarado es `int`, pero se retorna `ptr + 5`, que es un `int*`.
2. En `C::fun(int* ptr)`, el retorno declarado es `int*`, pero la firma de la clase base usa `int`.
3. En ambas llamadas `obj->fun()`, falta el argumento `int*`.
4. `B* obj = new C();` es inválido, porque `C` no deriva de `B` en el código dado.
5. `ptr` se declara pero nunca se inicializa.
6. Si se va a eliminar por puntero base (`A*`), la clase base debería tener destructor virtual.

Versión corregida posible:

```cpp
# include <iostream>
using namespace std;

class A {
public:
    virtual int fun(int* ptr) {
        return *ptr + 5;
    }

    virtual ~A() {}
};

class B : public A {
public:
    int fun(int* ptr) override {
        return *ptr + 2;
    }
};

class C : public A {
public:
    int fun(int* ptr) override {
        return *ptr;
    }
};

int main() {
    int value = 10;
    int* ptr = &value;

    for (int i = 0; i < 6; i++) {
        if (i % 2) {
            A* obj = new C();
            cout << obj->fun(ptr) << endl;
            delete obj;
        } else {
            A* obj = new B();
            cout << obj->fun(ptr) << endl;
            delete obj;
        }
    }

    return 0;
}
```

Qué implementación se ejecuta en cada rama:

- Rama impar: `C::fun`, porque el objeto real es `C`.
- Rama par: `B::fun`, porque el objeto real es `B`.

Si `value = 10`, las salidas serían:

```text
12
10
12
10
12
10
```

## Ejercicio X.3
Implementación posible:

```cpp
# include <string>
using namespace std;

LNode* stringToList(string t) {
    LNode* headWords = nullptr;
    LNode* tailWords = nullptr;
    int i = 0;

    while (i < t.size()) {
        while (i < t.size() && t[i] == ' ') {
            i++;
        }

        if (i >= t.size()) break;

        LNode* wordNode = new LNode();
        Node* headChars = nullptr;
        Node* tailChars = nullptr;

        while (i < t.size() && t[i] != ' ') {
            Node* newChar = new Node();
            newChar->value = t[i];

            if (headChars == nullptr) {
                headChars = newChar;
                tailChars = newChar;
            } else {
                tailChars->next = newChar;
                tailChars = newChar;
            }

            i++;
        }

        wordNode->str = headChars;

        if (headWords == nullptr) {
            headWords = wordNode;
            tailWords = wordNode;
        } else {
            tailWords->next = wordNode;
            tailWords = wordNode;
        }
    }

    return headWords;
}
```

Qué representa cada nivel:

- La lista de `LNode` representa la secuencia de palabras.
- La lista de `Node` enlazada desde `str` representa los caracteres de una palabra.

Cómo se detecta el fin de una palabra:

Se recorre el `string` caracter a caracter. Una palabra termina al encontrar un espacio o al llegar al fin del texto.

Complejidad:

- Tiempo: `O(n)`, donde `n` es la cantidad de caracteres de `t`
- Espacio adicional: `O(n)` por los nodos creados

## Ejercicio X.4
```cpp
# include <stack>

bool canBeObtainable(int* pushed, int* popped, int size) {
    stack<int> st;
    int j = 0;

    for (int i = 0; i < size; i++) {
        st.push(pushed[i]);

        while (!st.empty() && j < size && st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }

    return j == size;
}
```

Por qué la pila modela correctamente el problema:

Porque la secuencia `popped` solo puede obtenerse a través de operaciones LIFO. Cada elemento insertado queda pendiente en la pila hasta que le corresponda salir.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(n)`

## Ejercicio X.5
Supuesto de trabajo:

```cpp
struct Node {
    double nota;
    Node* next;
    Node(double nota) : nota(nota), next(nullptr) {}
};
```

```cpp
# include <iostream>
using namespace std;

void insertarNotaOrdenadaCircular(Node*& head, double nota) {
    Node* newNode = new Node(nota);

    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }

    if (nota <= head->nota) {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != head && current->next->nota < nota) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void mostrarResumenNotas(Node* head) {
    if (head == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }

    Node* current = head;
    double suma = 0.0;
    int cantidad = 0;

    do {
        cout << current->nota << " ";
        suma += current->nota;
        cantidad++;
        current = current->next;
    } while (current != head);

    cout << endl;
    cout << "Promedio: " << (suma / cantidad) << endl;
    cout << "Cantidad: " << cantidad << endl;
}
```

Idea:

- La insercion debe respetar el orden, pero sin perder la circularidad.
- El resumen recorre exactamente una vuelta completa de la lista.

Complejidad:

- `insertarNotaOrdenadaCircular`: `O(n)`
- `mostrarResumenNotas`: `O(n)`

## Ejercicio X.6
Pseudocodigo propuesto:

```cpp
struct NotaNode {
    double nota;
    double ponderacion;
    NotaNode* next;
};

struct RamoNode {
    string nombre;
    NotaNode* notas;
    RamoNode* next;
};

struct AlumnoNode {
    string nombre;
    RamoNode* ramos;
    AlumnoNode* next; // lista circular
};

double promedioRamo(RamoNode* ramo) {
    double suma = 0.0;
    double sumaPonderaciones = 0.0;
    NotaNode* nota = ramo->notas;

    while (nota != nullptr) {
        suma += nota->nota * nota->ponderacion;
        sumaPonderaciones += nota->ponderacion;
        nota = nota->next;
    }

    if (sumaPonderaciones == 0.0) return -1.0;
    return suma / sumaPonderaciones;
}

double calcularPromedio(AlumnoNode* head, string nombreAlumno, string ramo) {
    if (head == nullptr) return -1.0;

    AlumnoNode* alumno = head;
    do {
        if (alumno->nombre == nombreAlumno) {
            RamoNode* actualRamo = alumno->ramos;
            while (actualRamo != nullptr) {
                if (actualRamo->nombre == ramo) {
                    return promedioRamo(actualRamo);
                }
                actualRamo = actualRamo->next;
            }
            return -1.0;
        }
        alumno = alumno->next;
    } while (alumno != head);

    return -1.0;
}

void ordenarRamosPorPromedio(RamoNode*& headRamos) {
    RamoNode* ordenada = nullptr;

    while (headRamos != nullptr) {
        RamoNode* actual = headRamos;
        headRamos = headRamos->next;

        if (ordenada == nullptr ||
            promedioRamo(actual) > promedioRamo(ordenada)) {
            actual->next = ordenada;
            ordenada = actual;
        } else {
            RamoNode* cursor = ordenada;
            while (cursor->next != nullptr &&
                   promedioRamo(cursor->next) >= promedioRamo(actual)) {
                cursor = cursor->next;
            }

            actual->next = cursor->next;
            cursor->next = actual;
        }
    }

    headRamos = ordenada;
}
```

Idea estructural:

- La lista circular de alumnos permite recorrer el curso completo sin perder el inicio.
- Cada alumno apunta a su lista de ramos.
- Cada ramo apunta a su lista de evaluaciones con ponderacion.

Complejidad:

- `calcularPromedio`: `O(a + r + n)` en el peor caso
- `ordenarRamosPorPromedio`: `O(r^2 * n)` si se recalcula el promedio en cada comparacion

Observacion:

Si se quisiera optimizar, convendria calcular una vez el promedio de cada ramo y almacenarlo temporalmente.

## Ejercicio X.7
Una estrategia valida es la siguiente:

```cpp
// Se asume que cada elemento tiene un campo priority.
while (!src.empty()) {
    int mejor = -INF;

    while (!src.empty()) {
        Elemento e = src.top();
        src.pop();
        if (e.priority > mejor) {
            mejor = e.priority;
        }
        S1.push(e);
    }

    bool enviado = false;
    while (!S1.empty()) {
        Elemento e = S1.top();
        S1.pop();

        if (!enviado && e.priority == mejor) {
            salida.push(e);
            enviado = true;
        } else {
            S2.push(e);
        }
    }

    while (!S2.empty()) {
        src.push(S2.top());
        S2.pop();
    }
}
```

Rol de cada estructura:

- `src`: contiene los elementos aun no despachados.
- `S1`: permite revisar todos los elementos para detectar la mejor prioridad de la ronda.
- `S2`: conserva los elementos que no fueron enviados, para reconstruir `src`.
- `salida`: almacena el despacho final en orden de prioridad.

Por qué la cola es adecuada como salida:

Porque modela naturalmente una secuencia final de despacho donde los elementos salen en el mismo orden en que fueron priorizados por el algoritmo.

Complejidad:

- Tiempo: `O(n^2)`
- Espacio adicional: `O(n)`

## Ejercicio X.8
```cpp
# include <queue>
# include <stack>

int filtrar_patron_multiple(queue<int>& Q_datos, stack<int>& P_frecuencia,
                            queue<int>& Q_filtrada, int U, int F) {
    if (F <= 0) return 0;

    int reemplazos = 0;
    int indice = 1;

    while (!Q_datos.empty()) {
        int actual = Q_datos.front();
        Q_datos.pop();

        if (indice % F == 0) {
            P_frecuencia.push(actual);
        } else if (actual >= U) {
            Q_filtrada.push(actual);
        } else if (!P_frecuencia.empty()) {
            Q_filtrada.push(P_frecuencia.top());
            P_frecuencia.pop();
            reemplazos++;
        }

        indice++;
    }

    while (!P_frecuencia.empty()) {
        Q_datos.push(P_frecuencia.top());
        P_frecuencia.pop();
    }

    while (!Q_datos.empty()) {
        P_frecuencia.push(Q_datos.front());
        Q_datos.pop();
    }

    while (!P_frecuencia.empty()) {
        Q_filtrada.push(P_frecuencia.top());
        P_frecuencia.pop();
    }

    return reemplazos;
}
```

Qué estado representa `P_frecuencia`:

La pila almacena los elementos que llegaron en posiciones multiplos de `F` y que quedan disponibles como reserva para reemplazos.

Justificacion del uso conjunto:

- `Q_datos` representa el flujo original en orden de llegada.
- `P_frecuencia` representa una reserva LIFO de candidatos.
- `Q_filtrada` construye el resultado final en el orden en que los elementos sobreviven al filtrado.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional auxiliar: `O(1)` si solo se consideran estructuras auxiliares externas a las entregadas en los parametros

## Ejercicio X.9
Implementación posible:

```cpp
# include <queue>

struct Estado {
    int mIzq;
    int cIzq;
    bool boteIzq;
    int pasos;

    Estado(int mIzq, int cIzq, bool boteIzq, int pasos)
        : mIzq(mIzq), cIzq(cIzq), boteIzq(boteIzq), pasos(pasos) {}
};

bool estadoSeguro(int mIzq, int cIzq) {
    int mDer = 3 - mIzq;
    int cDer = 3 - cIzq;

    if (mIzq < 0 || mIzq > 3 || cIzq < 0 || cIzq > 3) return false;
    if (mIzq > 0 && cIzq > mIzq) return false;
    if (mDer > 0 && cDer > mDer) return false;

    return true;
}

int minCrucesMisionerosCanibales() {
    bool visitado[4][4][2] = {false};
    int movs[5][2] = {
        {1, 0},
        {2, 0},
        {0, 1},
        {0, 2},
        {1, 1}
    };

    queue<Estado> q;
    q.push(Estado(3, 3, true, 0));
    visitado[3][3][1] = true;

    while (!q.empty()) {
        Estado actual = q.front();
        q.pop();

        if (actual.mIzq == 0 && actual.cIzq == 0 && !actual.boteIzq) {
            return actual.pasos;
        }

        for (int i = 0; i < 5; i++) {
            int m = movs[i][0];
            int c = movs[i][1];

            int nuevoMIzq = actual.mIzq;
            int nuevoCIzq = actual.cIzq;
            bool nuevoBoteIzq = !actual.boteIzq;

            if (actual.boteIzq) {
                nuevoMIzq -= m;
                nuevoCIzq -= c;
            } else {
                nuevoMIzq += m;
                nuevoCIzq += c;
            }

            if (!estadoSeguro(nuevoMIzq, nuevoCIzq)) continue;

            int lado = nuevoBoteIzq ? 1 : 0;
            if (!visitado[nuevoMIzq][nuevoCIzq][lado]) {
                visitado[nuevoMIzq][nuevoCIzq][lado] = true;
                q.push(Estado(nuevoMIzq, nuevoCIzq, nuevoBoteIzq, actual.pasos + 1));
            }
        }
    }

    return -1;
}
```

Qué representa un estado:

Cada `Estado` resume completamente una configuración del problema:

- cuántos misioneros quedan a la izquierda;
- cuántos caníbales quedan a la izquierda;
- en qué orilla está el bote;
- cuántos cruces se han realizado hasta llegar a esa configuración.

Por qué una cola es adecuada:

La cola permite explorar primero todos los estados alcanzables en `k` cruces antes de pasar a los de `k + 1`. Por eso, la primera solución encontrada garantiza cantidad mínima de cruces.

Cómo se valida que un estado sea seguro:

Un estado es válido si:

- las cantidades quedan entre `0` y `3`;
- en la orilla izquierda, si hay misioneros, no quedan menos que caníbales;
- en la orilla derecha ocurre exactamente la misma condición.

Complejidad:

- Tiempo: `O(1)` respecto del tamaño fijo del problema `3-3`, o más generalmente `O(E)` si se piensa en el espacio de estados
- Espacio adicional: `O(E)` para la cola y la tabla de visitados

## Ejercicio X.10
Implementación posible:

```cpp
# include <queue>

const int MAX = 50;

struct Pos {
    int f;
    int c;
    Pos(int f, int c) : f(f), c(c) {}
};

int distanciaMinimaSalida(char lab[][MAX], int filas, int cols, int fIni, int cIni) {
    if (fIni < 0 || fIni >= filas || cIni < 0 || cIni >= cols) return -1;
    if (lab[fIni][cIni] == '#') return -1;

    int dist[MAX][MAX];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            dist[i][j] = -1;
        }
    }

    int df[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<Pos> q;
    q.push(Pos(fIni, cIni));
    dist[fIni][cIni] = 0;

    while (!q.empty()) {
        Pos actual = q.front();
        q.pop();

        if (lab[actual.f][actual.c] == 'E') {
            return dist[actual.f][actual.c];
        }

        for (int k = 0; k < 4; k++) {
            int nf = actual.f + df[k];
            int nc = actual.c + dc[k];

            if (nf >= 0 && nf < filas &&
                nc >= 0 && nc < cols &&
                dist[nf][nc] == -1 &&
                lab[nf][nc] != '#') {
                dist[nf][nc] = dist[actual.f][actual.c] + 1;
                q.push(Pos(nf, nc));
            }
        }
    }

    return -1;
}
```

Qué estado representa la cola:

La cola guarda la frontera actual de exploración. Cada posición encolada ya tiene asociada su distancia mínima conocida desde el punto inicial.

Por qué la cola es adecuada cuando se pide distancia mínima:

Porque una cola FIFO expande primero todas las posiciones a distancia `d` antes de pasar a las de distancia `d + 1`. Eso garantiza que la primera vez que se alcanza una salida, la distancia obtenida es mínima.

Contraste con la pila:

Una pila sirve para explorar caminos y responder existencia, pero no garantiza encontrar primero el camino más corto.

Complejidad:

- Tiempo: `O(filas * cols)`
- Espacio adicional: `O(filas * cols)` entre cola y matriz de distancias

## Ejercicio X.11
Se pide verificar anagramas de forma iterativa, considerando frecuencia de caracteres.

Firma solicitada:

```cpp
bool esAnagrama(string p1, string p2);
```

### Solución con stack

```cpp
# include <stack>
# include <string>
using namespace std;

bool esAnagramaConStack(string p1, string p2) {
    if (p1.size() != p2.size()) return false;

    int freq[256] = {0};
    stack<unsigned char> s1;
    stack<unsigned char> s2;

    for (char c : p1) s1.push((unsigned char)c);
    for (char c : p2) s2.push((unsigned char)c);

    while (!s1.empty()) {
        freq[s1.top()]++;
        s1.pop();
    }

    while (!s2.empty()) {
        freq[s2.top()]--;
        s2.pop();
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}
```

### Solución con queue

```cpp
# include <queue>
# include <string>
using namespace std;

bool esAnagramaConQueue(string p1, string p2) {
    if (p1.size() != p2.size()) return false;

    int freq[256] = {0};
    queue<unsigned char> q1;
    queue<unsigned char> q2;

    for (char c : p1) q1.push((unsigned char)c);
    for (char c : p2) q2.push((unsigned char)c);

    while (!q1.empty()) {
        freq[q1.front()]++;
        q1.pop();
    }

    while (!q2.empty()) {
        freq[q2.front()]--;
        q2.pop();
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}
```

### Firma final pedida

Puedes dejar la firma requerida delegando en cualquiera de las dos implementaciones:

```cpp
bool esAnagrama(string p1, string p2) {
    return esAnagramaConStack(p1, p2);
}
```

### Verificacion con ejemplos

- `("roma", "amor") -> true`
- `("listen", "silent") -> true`
- `("hola", "halo") -> true`
- `("aabb", "abbb") -> false`
- `("abc", "abcc") -> false`
