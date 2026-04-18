# Ayudantía 4: Soluciones

Estas soluciones están alineadas con los ejercicios del README.

Se asume:

```cpp
using namespace std;
```

## Estructura base para listas enlazadas

```cpp
struct Node {
    int data;
    Node* next;
    Node(int n) : data(n), next(nullptr) {}
};
```

---

## Ejercicio 1: Suma de dos listas de dígitos

```cpp
Node* sumarListas(Node* l1, Node* l2) {
	Node* head = nullptr;
	Node* tail = nullptr;

	int resto = 0;
	while (l1 != nullptr || l2 != nullptr || resto > 0) {
		
		int a = 0;
		if (l1 != nullptr) {
			a = l1->data;
		}

		int b = 0;
		if (l2 != nullptr) {
			b = l2->data;
		}

		int sum = a + b + resto;
		
		resto = sum / 10;
		int value = sum % 10;

        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    return head;
}
```

Complejidad:

- Tiempo: O(max(n, m))
- Espacio adicional: O(max(n, m)) por la lista resultado

---

## Ejercicio 2: filtrar_patron_multiple

Nota: para que los cambios se reflejen fuera de la función, las estructuras se pasan por referencia.

```cpp
#include <queue>
#include <stack>

int filtrar_patron_multiple(queue<int>& Q_datos, stack<int>& P_frecuencia,
                            queue<int>& Q_filtrada, int U, int F) {
    if (F <= 0) return 0; // evita divisiones/modulos invalidos

    int reemplazos_exitosos = 0;
    int indice = 1; // se considera indice 1-based: 1, 2, 3, ...

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

    // Invertimos la pila remanente usando la cola como estructura auxiliar.
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

Desglose lógico:

1. Si la posición actual es múltiplo de `F`, el elemento va a `P_frecuencia`.
2. Si no es múltiplo de `F` y cumple `elemento >= U`, el elemento pasa directo a `Q_filtrada`.
3. Si no cumple el umbral, se intenta reemplazar por el tope de `P_frecuencia`.
4. Al final, los elementos sobrantes de `P_frecuencia` se invierten y se agregan al final de `Q_filtrada`.

Complejidad:

- Tiempo: O(n), porque cada elemento se mueve una cantidad acotada de veces.
- Espacio adicional auxiliar: O(1), reutilizando las estructuras entregadas por el problema.

---

## Ejercicio 3: estadoLineaEnsamblaje

```cpp
#include <stack>
#include <string>

bool estadoLineaEnsamblaje(const string& linea) {
    stack<char> pendientes;

    for (char c : linea) {
        if (c == 'A') {
            pendientes.push(c);
        } else if (c == 'B') {
            if (pendientes.empty()) return false;
            pendientes.pop();
        } else {
            return false; // caracter invalido
        }
    }

    return pendientes.empty();
}
```

Complejidad:

- Tiempo: O(n)
- Espacio adicional con `stack`: O(n) en el peor caso

---

## Ejercicio 4: Generar binarios con queue STL

```cpp
#include <queue>
#include <string>
#include <vector>

vector<string> generarBinarios(int n) {
	vector<string> salida;
	if (n <= 0) return salida;

	queue<string> q;
	q.push("1");

	for (int i = 0; i < n; ++i) {
		string actual = q.front();
		q.pop();

		salida.push_back(actual);
		q.push(actual + "0");
		q.push(actual + "1");
	}

	return salida;
}
```

Complejidad:

- Tiempo: O(n log n) si contamos el costo real de construir/copiar strings
- Espacio adicional: O(n log n) considerando el vector de salida y la cola

Inciso: versión recursiva para comparar enfoques

```cpp
#include <cctype>
#include <string>
using namespace std;

string decodificarRec(const string& s, int& i) {
    string resultado;

    while (i < s.size() && s[i] != ']') {
        if (isalpha(s[i])) {
            resultado += s[i];
            i++;
        } else if (isdigit(s[i])) {
            int k = 0;
            while (i < s.size() && isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
                i++;
            }

            i++; // salta '['
            string bloque = decodificarRec(s, i);
            i++; // salta ']'

            for (int j = 0; j < k; j++) {
                resultado += bloque;
            }
        }
    }

    return resultado;
}

string decodeString_recursivo(string s) {
    int i = 0;
    return decodificarRec(s, i);
}
```

Complejidad (recursion):

- Tiempo: O(n + |resultado|), porque repetir bloques domina el costo real
- Espacio adicional: O(n + |resultado|), considerando pila de recursion y cadenas intermedias
Nota: Esto jamás entra como contenido, es sólo referencial

---

## Ejercicio 5: Guardando estados

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString_stack(string s) {
    stack<int> nums;
    stack<string> textos;

    string actual = "";
    int num = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Transformar carácter a número
        }
        else if (c == '[') {
            nums.push(num);
            textos.push(actual);
            num = 0;
            actual = "";
        }
        else if (c == ']') {
            int k = nums.top(); nums.pop();
            string previo = textos.top(); textos.pop();

            string repetido = "";
            for (int j = 0; j < k; j++) {
                repetido += actual;
            }

            actual = previo + repetido;
        }
        else {
            actual += c;
        }
    }

    return actual;
}
```

Desglose lógico:

1. `nums` guarda los multiplicadores pendientes.
2. `textos` guarda el texto construido antes de cada `[` .
3. Al leer `]`, se cierra el bloque actual, se repite `k` veces y se concatena con el contexto anterior.

Complejidad:

- Tiempo: O(n + |resultado|)
- Espacio adicional: O(n + |resultado|)

---

## Ejercicio 6: Más estados

En el contexto de este curso, aquí sí tiene sentido usar una estructura de datos explícita aunque exista una solución más eficiente con conteo de frecuencias. La meta pedagógica es modelar el **estado de los caracteres aún disponibles** de `p1`.

### Versión con `queue`

Usaremos una `queue<char>` para guardar los caracteres de `p1` que todavía no han sido emparejados. Para cada carácter de `p2`, recorremos una vez la cola buscando una coincidencia:

- Si la encontramos, consumimos esa ocurrencia y no la volvemos a encolar.
- Si no la encontramos, entonces `p2` exige un carácter que `p1` ya no puede aportar.

La cola representa el **estado restante** del problema: en cada paso contiene exactamente los caracteres de `p1` que siguen disponibles.

```cpp
#include <queue>
#include <string>

bool esAnagramaQueue(string p1, string p2) {
    if (p1.length() != p2.length()) {
        return false;
    }

    queue<char> disponibles;

    for (char c : p1) {
        disponibles.push(c);
    }

    for (char objetivo : p2) {
        bool encontrado = false;
        int cantidad = disponibles.size();

        for (int i = 0; i < cantidad; i++) {
            char frente = disponibles.front();
            disponibles.pop();

            if (!encontrado && frente == objetivo) {
                encontrado = true; // se consume esta ocurrencia
            } else {
                disponibles.push(frente);
            }
        }

        if (!encontrado) {
            return false;
        }
    }

    return disponibles.empty();
}
```

Cómo se usa la estructura en esta versión:

1. La cola comienza con todos los caracteres de `p1`.
2. Cada vez que procesamos un carácter de `p2`, buscamos una ocurrencia en la cola.
3. Si aparece, esa ocurrencia no se vuelve a encolar: queda gastada.
4. Los demás caracteres vuelven a la cola y siguen disponibles para pasos futuros.
5. Al final, si ambas cadenas son anagramas, no debe sobrar ningún carácter en la estructura.

Complejidad de la versión con `queue`:

- Tiempo: O(n^2)
- Espacio adicional: O(n)

### Versión con `stack`

También puede resolverse con `stack`. En este caso, la pila representa los caracteres aún disponibles de `p1`, pero como solo permite acceder al tope, al buscar una coincidencia hay que desapilar temporalmente y luego reconstruir el estado con una pila auxiliar.

```cpp
#include <stack>
#include <string>

bool esAnagramaStack(string p1, string p2) {
    if (p1.length() != p2.length()) {
        return false;
    }

    stack<char> disponibles;

    for (char c : p1) {
        disponibles.push(c);
    }

    for (char objetivo : p2) {
        bool encontrado = false;
        stack<char> auxiliar;

        while (!disponibles.empty()) {
            char tope = disponibles.top();
            disponibles.pop();

            if (!encontrado && tope == objetivo) {
                encontrado = true; // se consume esta ocurrencia
            } else {
                auxiliar.push(tope);
            }
        }

        if (!encontrado) {
            return false;
        }

        while (!auxiliar.empty()) {
            disponibles.push(auxiliar.top());
            auxiliar.pop();
        }
    }

    return disponibles.empty();
}
```

Cómo se usa la estructura en esta versión:

1. La pila `disponibles` guarda los caracteres de `p1` que siguen sin usarse.
2. Para buscar un carácter de `p2`, desapilamos elementos uno por uno.
3. Cuando encontramos la coincidencia, esa ocurrencia se consume y no vuelve a la estructura.
4. Los demás caracteres se guardan en una pila auxiliar.
5. Al terminar la búsqueda, reconstruimos `disponibles` con los caracteres que siguen pendientes.

Complejidad de la versión con `stack`:

- Tiempo: O(n^2)
- Espacio adicional: O(n)

Comparación didáctica:

- Con `queue`, el estado pendiente se recorre rotando elementos.
- Con `stack`, el estado pendiente se recorre desmontando y reconstruyendo.
- Ambas soluciones son válidas en este curso porque hacen visible cómo la estructura elegida condiciona la forma de resolver el problema.