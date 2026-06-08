# Intensiva I: Soluciones

Breve: soluciones y explicaciones para los ejercicios listados en `README.md`.

---

## Ejercicio I.3
Código:

```cpp
void proceso(int* p, int& x) {
    *p = *p + 5;
    x = x + *p;
}
```

Ruteo:

1. Estado inicial: `a = 4`, `b = 7`.
2. `proceso(&a, b)`:
   `a = 4 + 5 = 9`
   `b = 7 + 9 = 16`
3. `proceso(&b, a)`:
   `b = 16 + 5 = 21`
   `a = 9 + 21 = 30`

Salida:

```text
30 21
```

## Ejercicio I.5
Ruteo:

1. Estado inicial:
   `v = [1, 3, 5, 7]`
2. `mover(v)`:
   `v[2] = v[1] + v[0] = 3 + 1 = 4`
   queda `v = [1, 3, 4, 7]`
3. `mover(v + 1)`:
   ahora `p` apunta a `v[1]`
   `v[3] = v[2] + v[1] = 4 + 3 = 7`

Contenido final de `v`:

```text
1 3 4 7
```

## Ejercicio II.10
Orden de ejecución:

1. `Base* p = new Derivada();`
   Construcción: `Base()` y luego `Derivada()`.
2. `p->f();`
   Como `f()` es virtual, se ejecuta `Derivada::f`.
3. `delete p;`
   Como el destructor base es virtual, se destruye primero `Derivada` y luego `Base`.

Salida:

```text
Base()
Derivada()
Derivada::f
~Derivada()
~Base()
```

## Ejercicio IV.5
Código:

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j = j * 2) {
        cout << i * j << endl;
    }
}
```

Análisis:

- El ciclo externo recorre `n` veces.
- El ciclo interno duplica `j`, por tanto recorre `O(log n)` veces.

Complejidad:

- Mejor caso: `O(n log n)`
- Peor caso: `O(n log n)`
- Complejidad temporal general: `O(n log n)`
- Espacio adicional: `O(1)`

## Ejercicio IV.10
Estructura más conveniente:

```text
Lista enlazada simple
```

Justificación:

- Insertar al inicio es la operación dominante y cuesta `O(1)`.
- No se necesita acceso por índice, por lo que el arreglo/vector no aporta una ventaja clave.
- Insertar al final casi no se usa, así que su costo `O(n)` no es el factor principal.
- Una pila o cola imponen políticas de acceso más restrictivas que una lista simple.

---

## Ejercicio VI.5
```cpp
# include <stack>
# include <string>
# include <cctype>

string decodeString(string s) {
    stack<int> nums;
    stack<string> textos;

    string actual = "";
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            nums.push(num);
            textos.push(actual);
            num = 0;
            actual = "";
        } else if (c == ']') {
            int k = nums.top();
            nums.pop();

            string previo = textos.top();
            textos.pop();

            string repetido = "";
            for (int i = 0; i < k; i++) {
                repetido += actual;
            }

            actual = previo + repetido;
        } else {
            actual += c;
        }
    }

    return actual;
}
```

Estado que guardan las pilas:

- `nums`: multiplicadores pendientes.
- `textos`: el contexto previo a cada bloque abierto.

Complejidad:

- Tiempo: `O(n + |resultado|)`
- Espacio adicional: `O(n + |resultado|)`

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

double calcularPromedio(AlumnoNode* head, string nombreAlumno, string nombreRamo) {
    if (head == nullptr) return -1.0;

    // Buscar alumno en lista circular
    AlumnoNode* nodoAlumno = head;
    while (nodoAlumno->nombre != nombreAlumno) {
        nodoAlumno = nodoAlumno->next;
        if (nodoAlumno == head) return -1.0; // no se encontró
    }

    // Buscar ramo en lista simple
    RamoNode* nodoRamo = nodoAlumno->ramos;
    while (nodoRamo != nullptr && nodoRamo->nombre != nombreRamo) {
        nodoRamo = nodoRamo->next;
    }

    if (nodoRamo == nullptr) return -1.0; // no se encontró el ramo

    // Calcular promedio ponderado
    double suma = 0.0;
    double sumaPonderaciones = 0.0;

    NotaNode* nodoNota = nodoRamo->notas;
    while (nodoNota != nullptr) {
        suma += nodoNota->nota * nodoNota->ponderacion;
        sumaPonderaciones += nodoNota->ponderacion;
        nodoNota = nodoNota->next;
    }

    if (sumaPonderaciones == 0.0) return -1.0; // evitar división por cero

    return suma / sumaPonderaciones;
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

- Primero se busca el alumno.
- Luego se busca el ramo dentro de ese alumno.
- Finalmente se recorre la lista de notas y se calcula el promedio ponderado.

Complejidad:

- `calcularPromedio`: `O(a + r + n)` en el peor caso
- `ordenarRamosPorPromedio`: `O(r^2 * n)` si se recalcula el promedio en cada comparacion

## Ejercicio X.10
Implementación posible:

```cpp
# include <queue>
# include <stack>

const int n = 50;

struct Pos {
    int f;
    int c;
    Pos(int f, int c) : f(f), c(c) {}
};

bool hayCaminoSalidaQueue(char lab[][n], int filas, int cols, int fIni, int cIni) {
    if (fIni < 0 || fIni >= filas || cIni < 0 || cIni >= cols) return false;
    if (lab[fIni][cIni] == '#') return false;

    bool visitado[n][n];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            visitado[i][j] = false;
        }
    }

    int df[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<Pos> q;
    q.push(Pos(fIni, cIni));
    visitado[fIni][cIni] = true;

    while (!q.empty()) {
        Pos actual = q.front();
        q.pop();

        if (lab[actual.f][actual.c] == 'E') return true;

        for (int k = 0; k < 4; k++) {
            int nf = actual.f + df[k];
            int nc = actual.c + dc[k];

            if (nf >= 0 && nf < filas &&
                nc >= 0 && nc < cols &&
                !visitado[nf][nc] &&
                lab[nf][nc] != '#') {
                visitado[nf][nc] = true;
                q.push(Pos(nf, nc));
            }
        }
    }

    return false;
}

bool hayCaminoSalidaStack(char lab[][n], int filas, int cols, int fIni, int cIni) {
    if (fIni < 0 || fIni >= filas || cIni < 0 || cIni >= cols) return false;
    if (lab[fIni][cIni] == '#') return false;

    bool visitado[n][n];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            visitado[i][j] = false;
        }
    }

    int df[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    stack<Pos> st;
    st.push(Pos(fIni, cIni));
    visitado[fIni][cIni] = true;

    while (!st.empty()) {
        Pos actual = st.top();
        st.pop();

        if (lab[actual.f][actual.c] == 'E') return true;

        for (int k = 0; k < 4; k++) {
            int nf = actual.f + df[k];
            int nc = actual.c + dc[k];

            if (nf >= 0 && nf < filas &&
                nc >= 0 && nc < cols &&
                !visitado[nf][nc] &&
                lab[nf][nc] != '#') {
                visitado[nf][nc] = true;
                st.push(Pos(nf, nc));
            }
        }
    }

    return false;
}
```

Que estado guardan la cola y la pila:

Ambas guardan posiciones pendientes por explorar en el laberinto.

- `queue<Pos>`: procesa por orden de llegada (FIFO).
- `stack<Pos>`: procesa el ultimo agregado primero (LIFO).

Por qué ambas sirven para existencia de camino:

Para responder solo si existe camino, no importa explorar por capas o por profundidad: basta con recorrer las celdas alcanzables sin repetirlas. Si en algun momento aparece una celda `E`, se retorna `true`.

Diferencia clave:

- Con cola (BFS) se explora por capas.
- Con pila (DFS iterativo) se avanza por profundidad.

En este ejercicio ambas son validas porque la pregunta es de existencia, no de distancia minima.

Complejidad:

- Tiempo: `O(filas * cols)`
- Espacio adicional: `O(filas * cols)` entre estructura auxiliar y matriz de visitados

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
