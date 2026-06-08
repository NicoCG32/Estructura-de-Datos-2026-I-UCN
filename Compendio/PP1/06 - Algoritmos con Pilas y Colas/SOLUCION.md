# VI. Algoritmos con Pilas y Colas

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [VI.1](#ejercicio-vi1) | [VI.2](#ejercicio-vi2) | [VI.3](#ejercicio-vi3) | [VI.4](#ejercicio-vi4) | [VI.5](#ejercicio-vi5)
- [VI.6](#ejercicio-vi6) | [VI.7](#ejercicio-vi7) | [VI.8](#ejercicio-vi8) | [VI.9](#ejercicio-vi9) | [VI.10](#ejercicio-vi10)
- [VI.11](#ejercicio-vi11) | [VI.12](#ejercicio-vi12) | [VI.13](#ejercicio-vi13) | [VI.14](#ejercicio-vi14) | [VI.15](#ejercicio-vi15)
- [VI.16](#ejercicio-vi16) | [VI.17](#ejercicio-vi17) | [VI.18](#ejercicio-vi18) | [VI.19](#ejercicio-vi19) | [VI.20](#ejercicio-vi20)


## Cobertura actual

- Ejercicios con pauta desarrollada: `VI.1`, `VI.2`, `VI.3`, `VI.4`, `VI.5`, `VI.6`, `VI.7`, `VI.8`, `VI.9`, `VI.10`, `VI.11`, `VI.12`, `VI.13`, `VI.14`, `VI.15`, `VI.16`, `VI.17`, `VI.18`, `VI.19`, `VI.20`.
- Ejercicios aun sin desarrollar en esta pauta: `ninguno`.

## Pauta desarrollada

## Ejercicio VI.1
```cpp
# include <stack>
# include <string>

string invertirCadena(string texto) {
    stack<char> st;

    for (char c : texto) {
        st.push(c);
    }

    string invertida = "";
    while (!st.empty()) {
        invertida += st.top();
        st.pop();
    }

    return invertida;
}
```

Qué estado guarda la pila:

La pila guarda los caracteres en el mismo orden en que llegan. Al desapilarlos se recuperan en orden inverso.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(n)`

## Ejercicio VI.2
```cpp
# include <stack>
# include <string>

bool parentesisBalanceados(string expr) {
    stack<char> st;

    for (char c : expr) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }

    return st.empty();
}
```

Por qué funciona:

La pila guarda los paréntesis abiertos pendientes de cierre. Cada `)` debe cerrar al último `(` aún no cerrado.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(n)`

## Ejercicio VI.3
```cpp
# include <stack>
# include <string>

bool esPalindromo(string s) {
    stack<char> st;

    for (char c : s) {
        st.push(c);
    }

    for (char c : s) {
        if (st.top() != c) return false;
        st.pop();
    }

    return true;
}
```

Qué estado guarda la pila:

La pila conserva la cadena en orden LIFO. Comparar la cadena original con la versión desapilada equivale a compararla con su inversa.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(n)`

## Ejercicio VI.4
```cpp
# include <queue>
# include <string>
# include <vector>

vector<string> generarBinarios(int n) {
    vector<string> salida;
    if (n <= 0) return salida;

    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        string actual = q.front();
        q.pop();

        salida.push_back(actual);
        q.push(actual + "0");
        q.push(actual + "1");
    }

    return salida;
}
```

Estado que guarda la cola:

La cola almacena los binarios “pendientes de expandir”. Desde cada cadena salen dos nuevas: una agregando `0` y otra agregando `1`.

Complejidad:

- Tiempo: `O(n log n)` considerando el costo de manipular `string`
- Espacio adicional: `O(n log n)`

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

## Ejercicio VI.6
```cpp
# include <stack>
# include <string>

bool estadoLineaEnsamblaje(string linea) {
    stack<char> piezasA;

    for (char c : linea) {
        if (c == 'A') {
            piezasA.push(c);
        } else if (c == 'B') {
            if (piezasA.empty()) return false;
            piezasA.pop();
        }
    }

    return true;
}
```

Qué estado guarda la estructura:

La pila representa las piezas `A` que ya aparecieron y que están disponibles para emparejar una futura `B`.

Por qué una pila es razonable:

No interesa distinguir identidades complejas, sino mantener un conjunto de aperturas pendientes. Cada `B` consume una `A` pendiente.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(n)` en el peor caso

## Ejercicio VI.7
```cpp
# include <queue>
# include <stack>

int filtrar_patron_multiple(queue<int>& Q_datos, stack<int>& P_frecuencia,
                            queue<int>& Q_filtrada, int U, int F) {
    if (F <= 0) return 0;

    int reemplazos_exitosos = 0;
    int indice = 1;

    while (!Q_datos.empty()) {
        int elemento = Q_datos.front();
        Q_datos.pop();

        if (indice % F == 0) {
            P_frecuencia.push(elemento);
        } else if (elemento >= U) {
            Q_filtrada.push(elemento);
        } else {
            if (!P_frecuencia.empty()) {
                Q_filtrada.push(P_frecuencia.top());
                P_frecuencia.pop();
                reemplazos_exitosos++;
            }
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

    return reemplazos_exitosos;
}
```

Qué estado representa `P_frecuencia`:

La pila almacena los elementos ubicados en posiciones múltiplos de `F` que quedan disponibles para reemplazar valores que no alcanzan el umbral `U`.

Por qué se usan ambas estructuras:

- La `queue` modela el flujo de procesamiento en orden de llegada.
- La `stack` modela una reserva LIFO de reemplazos disponibles.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional auxiliar: `O(1)` si se considera que solo se reutilizan las estructuras entregadas

## Ejercicio VI.8
```cpp
# include <queue>

void intercalarMitades(queue<int>& q) {
    if (q.size() % 2 != 0) return;

    queue<int> primeraMitad;
    queue<int> resultado;
    int mitad = q.size() / 2;

    for (int i = 0; i < mitad; i++) {
        primeraMitad.push(q.front());
        q.pop();
    }

    while (!primeraMitad.empty()) {
        resultado.push(primeraMitad.front());
        primeraMitad.pop();

        resultado.push(q.front());
        q.pop();
    }

    q = resultado;
}
```

Qué estado guardan las colas:

- `primeraMitad` conserva la mitad inicial.
- `q` queda temporalmente con la mitad final.
- `resultado` reconstruye la secuencia intercalada.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(n)`

## Ejercicio VI.9
Una implementación posible es la siguiente:

```cpp
# include <stack>
# include <string>
using namespace std;

class Historial {
private:
    stack<string> atras;
    stack<string> adelante;
    string actual;

public:
    void visitar(string pagina) {
        if (!actual.empty()) {
            atras.push(actual);
        }
        actual = pagina;

        while (!adelante.empty()) {
            adelante.pop();
        }
    }

    bool volverAtras() {
        if (atras.empty()) return false;
        adelante.push(actual);
        actual = atras.top();
        atras.pop();
        return true;
    }

    bool avanzar() {
        if (adelante.empty()) return false;
        atras.push(actual);
        actual = adelante.top();
        adelante.pop();
        return true;
    }

    string paginaActual() const {
        return actual;
    }
};
```

Qué representa cada pila:

- `atras`: paginas visitadas antes de la actual.
- `adelante`: paginas que quedaron disponibles al retroceder.

Complejidad:

- `visitar`: `O(n)` en esta version por el vaciado de `adelante`
- `volverAtras`: `O(1)`
- `avanzar`: `O(1)`
- `paginaActual`: `O(1)`

## Ejercicio VI.10
```cpp
# include <stack>
# include <string>
# include <vector>

int evaluarRPN(vector<string> tokens) {
    stack<int> st;

    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }

    return st.top();
}
```

Qué estado guarda la pila:

La pila mantiene operandos parciales pendientes. Cada operador consume los dos más recientes y apila el resultado.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(n)`

---

## Ejercicio VI.11
```cpp
# include <queue>
# include <stack>

void reverseQueue(queue<int>& q) {
    stack<int> st;

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}
```

## Ejercicio VI.12
```cpp
# include <stack>
# include <string>

string decimalABinario(int n) {
    if (n == 0) return "0";

    stack<int> st;
    while (n > 0) {
        st.push(n % 2);
        n /= 2;
    }

    string resultado = "";
    while (!st.empty()) {
        resultado += char('0' + st.top());
        st.pop();
    }

    return resultado;
}
```

## Ejercicio VI.13
```cpp
# include <stack>
# include <string>

bool balanceadoGeneral(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;

            char t = st.top();
            st.pop();

            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}
```

## Ejercicio VI.14
```cpp
# include <stack>

stack<int> copyStack(stack<int> s) {
    stack<int> aux;
    stack<int> copia;

    while (!s.empty()) {
        aux.push(s.top());
        s.pop();
    }

    while (!aux.empty()) {
        s.push(aux.top());
        copia.push(aux.top());
        aux.pop();
    }

    return copia;
}
```

## Ejercicio VI.15
```cpp
# include <queue>

queue<int> intercalarColas(queue<int> a, queue<int> b) {
    queue<int> resultado;

    while (!a.empty() || !b.empty()) {
        if (!a.empty()) {
            resultado.push(a.front());
            a.pop();
        }
        if (!b.empty()) {
            resultado.push(b.front());
            b.pop();
        }
    }

    return resultado;
}
```

## Ejercicio VI.16
```cpp
# include <queue>

void duplicarCola(queue<int>& q) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        q.push(x);
        q.push(x);
    }
}
```

## Ejercicio VI.17
```cpp
# include <stack>
# include <queue>
# include <string>

bool esPalindromoEstructuras(string s) {
    stack<char> st;
    queue<char> q;

    for (char c : s) {
        st.push(c);
        q.push(c);
    }

    while (!st.empty()) {
        if (st.top() != q.front()) return false;
        st.pop();
        q.pop();
    }

    return true;
}
```

## Ejercicio VI.18
```cpp
# include <queue>
# include <stack>

void invertirPrimerosK(queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) return;

    stack<int> st;
    int n = q.size();

    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}
```

## Ejercicio VI.19
```cpp
# include <queue>

int josephus(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    return q.front();
}
```

## Ejercicio VI.20
```cpp
# include <stack>

void ordenarPila(stack<int>& s) {
    stack<int> aux;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!aux.empty() && aux.top() > temp) {
            s.push(aux.top());
            aux.pop();
        }

        aux.push(temp);
    }

    while (!aux.empty()) {
        s.push(aux.top());
        aux.pop();
    }
}
```

Observación:

Con esta implementación, al desapilar `s` al final se obtienen los elementos de menor a mayor.
