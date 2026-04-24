# Ayudantia 5: Soluciones

En esta guia se privilegia claridad conceptual:

- que estado guarda cada estructura;
- como cambia ese estado paso a paso;
- por que la solucion respeta las restricciones del enunciado;
- cual es la complejidad temporal y espacial real.

Se asume:

```cpp
using namespace std;
```

## Estructura base para listas enlazadas

```cpp
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};
```

---

## Ejercicio 1: Evaluar expresion Postfix con stack

### Idea general

En notacion Postfix, cada vez que aparece un numero se guarda como operando pendiente. Cuando aparece un operador, se consumen los dos operandos mas recientes.

Eso coincide exactamente con una pila:

- el ultimo operando que entro es el primero que debe salir;
- el resultado parcial vuelve a quedar disponible para operaciones futuras.

### Que estado guarda la pila

La pila guarda **operandos pendientes** o **resultados intermedios**.

Por ejemplo, en:

```text
2 1 + 3 *
```

la pila evoluciona asi:

1. push `2`
2. push `1`
3. leer `+` -> pop `1` y `2`, calcular `2 + 1 = 3`, push `3`
4. push `3`
5. leer `*` -> pop `3` y `3`, calcular `3 * 3 = 9`, push `9`

### Implementacion

```cpp
#include <stack>


int evaluarPostfixConStack(const string& expr) {

    stack<int> st;

    int num = 0;
    for (char c : expr){

        if (isdigit(c)){
            num = num * 10 + c - '0';
        }

        if (c == ' ') continue; // Skippear espacios

        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if (c == '+') st.push(b + a);
        else if (c == '-') st.push(b - a);
        else if (c == '*') st.push(b * a);
        else st.push(b / a);
    }

    return st.top();    
}

int evaluarPostfixConStack(const string& expr) {
    stack<int> st;
    int n = expr.size();

    for (int i = 0; i < n; ++i) {
        if (expr[i] == ' ') {
            continue;
        }

        bool esOperador =
            (expr[i] == '+' || expr[i] == '*' || expr[i] == '/');

        if (expr[i] == '-') {
            if (i + 1 < n && expr[i + 1] != ' ') {
                esOperador = false;  // '-' como signo de numero negativo.
            } else {
                esOperador = true;
            }
        }

        if (esOperador) {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();

            if (expr[i] == '+') st.push(left + right);
            else if (expr[i] == '-') st.push(left - right);
            else if (expr[i] == '*') st.push(left * right);
            else st.push(left / right);
            continue;
        }

        int sign = 1;
        if (expr[i] == '-') {
            sign = -1;
            ++i;
        }

        int value = 0;
        while (i < n && expr[i] != ' ') {
            value = value * 10 + (expr[i] - '0');
            ++i;
        }

        st.push(sign * value);
    }

    return st.top();
}
```

### Complejidad

- Tiempo: `O(n)`, donde `n` es el largo de la expresion o, equivalentemente, la cantidad total de caracteres leidos.
- Espacio adicional: `O(k)`, donde `k` es la cantidad maxima de operandos simultaneos en la pila. En el peor caso, `O(n)`.

---

## Ejercicio 2: Es anagrama usando una queue

### Idea general

Aqui el objetivo no es usar la solucion mas eficiente con conteo de frecuencias, sino modelar el estado con una estructura vista en el curso.

La cola representara los **caracteres de `p1` que aun estan disponibles**.

Para cada caracter de `p2`:

1. recorremos una vuelta completa de la cola;
2. si encontramos una coincidencia, consumimos esa ocurrencia y no la reinsertamos;
3. si no la encontramos, `p2` exige un caracter que ya no esta disponible en `p1`.

### Que estado guarda la cola

La cola guarda el multiconjunto de caracteres aun no usados de `p1`.

No importa tanto el orden original, sino el hecho de que la cola permite:

- sacar un caracter del frente;
- decidir si se consume;
- o devolverlo al final si todavia sigue disponible.

### Implementacion

```cpp
#include <queue>

bool esAnagramaConQueue(const string& p1, const string& p2) {
    if (p1.size() != p2.size()) return false;

    queue<char> q;
    for (char c : p1) {
        q.push(c);
    }

    for (char objetivo : p2) {
        bool found = false;
        queue<char> aux;

        while (!q.empty()) {
            char actual = q.front();
            q.pop();

            if (!found && actual == objetivo) {
                found = true;
            } else {
                aux.push(actual);
            }
        }

        q = aux;

        if (!found) {
            return false;
        }
    }

    return true;
}
```

### Paso a paso con un ejemplo

Para `p1 = "roma"` y `p2 = "amor"`:

1. La cola parte con `r, o, m, a`.
2. Buscamos `'a'`: rotamos hasta encontrarla y la consumimos.
3. La cola queda con `r, o, m`.
4. Buscamos `'m'`: rotamos hasta encontrarla y la consumimos.
5. Repetimos con `'o'` y `'r'`.
6. Si todas las busquedas consumen exactamente una ocurrencia, entonces las cadenas son anagramas.

### Complejidad

- Tiempo: `O(n^2)` en el peor caso, porque por cada caracter de `p2` podemos recorrer casi toda la cola.
- Espacio adicional: `O(n)`, por la cola de caracteres disponibles.

---

## Ejercicio 3: Es anagrama usando una stack

### Idea general

Ahora el estado se modela con una pila. La idea sigue siendo la misma: la estructura guarda los caracteres de `p1` que aun no han sido consumidos.

La diferencia es operacional:

- con una cola se rota;
- con una pila se desmonta el estado desde el tope y, si hace falta, se reconstruye con una pila auxiliar.

### Que estado guardan las pilas

- La pila principal guarda caracteres pendientes de `p1`.
- La pila auxiliar guarda temporalmente los caracteres que se revisaron pero no coincidieron con el objetivo actual.

Cuando aparece la coincidencia:

- esa ocurrencia se consume;
- luego se restaura la pila principal con los elementos de la auxiliar.

### Implementacion

```cpp
#include <stack>

bool esAnagramaConStack(const string& p1, const string& p2) {
    if (p1.size() != p2.size()) return false;

    stack<char> principal;
    for (char c : p1) {
        principal.push(c);
    }

    for (char objetivo : p2) {
        stack<char> aux;
        bool found = false;

        while (!principal.empty()) {
            char actual = principal.top();
            principal.pop();

            if (!found && actual == objetivo) {
                found = true;
                break;
            }

            aux.push(actual);
        }

        while (!aux.empty()) {
            principal.push(aux.top());
            aux.pop();
        }

        if (!found) {
            return false;
        }
    }

    return true;
}
```

### Paso a paso con un ejemplo

Para `p1 = "roma"` y `p2 = "amor"`:

1. La pila principal queda con tope `'a'`, luego `'m'`, luego `'o'`, luego `'r'`.
2. Buscamos `'a'`: esta en el tope, se consume de inmediato.
3. Buscamos `'m'`: vuelve a quedar en el tope, se consume.
4. Buscamos `'o'` y luego `'r'`.
5. Si en algun momento no aparece el caracter buscado, entonces no hay suficientes ocurrencias y la respuesta es `false`.

### Complejidad

- Tiempo: `O(n^2)` en el peor caso, porque para cada caracter objetivo se puede recorrer casi toda la pila.
- Espacio adicional: `O(n)`, por la pila principal y la pila auxiliar.

### Nota didactica

Esta version no es mejor que la de cola en complejidad. Su interes esta en mostrar que **la estructura elegida impone una forma distinta de recorrer y reconstruir el estado**.

---

## Ejercicio 4: Reordenar una lista intercalando extremos

### Idea general

Este es el ejercicio mas estructural de la ayudantia. La solucion correcta y eficiente requiere varias etapas:

1. encontrar el medio de la lista;
2. cortar la lista en dos mitades;
3. invertir la segunda mitad;
4. intercalar ambas mitades.

La clave es hacerlo sin crear nodos nuevos y usando solo `O(1)` espacio adicional.

### Por que esta solucion cumple la restriccion

No usamos arreglos ni pilas auxiliares. Solo:

- unos pocos punteros de trabajo;
- relinkeo de nodos existentes;
- una inversion iterativa in-place de la segunda mitad.

### Paso a paso

Supongamos:

```text
1 -> 2 -> 3 -> 4 -> 5
```

1. Buscamos el medio con `slow` y `fast`.
   Resultado: primera mitad `1 -> 2 -> 3`, segunda mitad `4 -> 5`.
2. Invertimos la segunda mitad.
   Queda `5 -> 4`.
3. Intercalamos:
   - tomamos `1`, luego `5`;
   - luego `2`, luego `4`;
   - finalmente queda `3`.
4. Resultado final:

```text
1 -> 5 -> 2 -> 4 -> 3
```

### Implementacion

```cpp
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void reorderListAlternandoExtremos(Node*& head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = nullptr;

    second = reverseList(second);

    Node* first = head;
    while (second != nullptr) {
        Node* nextFirst = first->next;
        Node* nextSecond = second->next;

        first->next = second;
        second->next = nextFirst;

        first = nextFirst;
        second = nextSecond;
    }
}
```

### Verificacion de casos borde

- Lista vacia: no hay nada que hacer.
- Lista con un nodo: no cambia.
- Lista con dos nodos: no cambia.
- Lista impar: el nodo central queda al final.
- Lista par: ambas mitades se intercalan completas.

### Complejidad

- Tiempo: `O(n)`.
  La lista se recorre un numero constante de veces: una para encontrar el medio, una para invertir y una para mezclar.
- Espacio adicional: `O(1)`.
  Solo se usan punteros auxiliares, sin estructuras extra dependientes de `n`.

---

## Ejercicio 5: Colapsar bloques estrictamente crecientes

### Idea general

La lista debe recorrerse identificando **bloques contiguos maximales estrictamente crecientes**.

Por cada bloque:

1. se detecta su inicio;
2. se avanza mientras el patron creciente se mantenga;
3. se acumula la suma del bloque;
4. se reutiliza el primer nodo del bloque como representante;
5. se eliminan los nodos sobrantes del bloque;
6. se enlaza el representante con el siguiente bloque.

La idea importante es que no estamos creando una lista nueva. Estamos **transformando la misma lista**.

### Que patron se detecta

El patron es:

```text
actual->data < actual->next->data
```

Mientras esa relacion se mantenga, seguimos dentro del mismo bloque creciente.

En cuanto deja de cumplirse, el bloque termina.

### Paso a paso

Tomemos:

```text
1 -> 3 -> 5 -> 4 -> 6 -> 2 -> 7 -> 8 -> 9 -> 1
```

1. El primer bloque es `1 -> 3 -> 5`.
   Su suma es `9`.
   Se reemplaza por un solo nodo con valor `9`.
2. El siguiente bloque es `4 -> 6`.
   Su suma es `10`.
3. El siguiente bloque es `2 -> 7 -> 8 -> 9`.
   Su suma es `26`.
4. El ultimo bloque es `1`.
   Se mantiene como `1`.

Resultado:

```text
9 -> 10 -> 26 -> 1
```

### Implementacion

```cpp
void colapsarBloquesCrecientes(Node*& head) {
    if (head == nullptr) return;

    Node* current = head;
    Node* prevCollapsed = nullptr;

    while (current != nullptr) {
        Node* blockStart = current;
        int sum = current->data;

        while (current->next != nullptr &&
               current->data < current->next->data) {
            current = current->next;
            sum += current->data;
        }

        Node* blockEnd = current;
        Node* nextBlock = blockEnd->next;

        blockStart->data = sum;

        Node* toDelete = blockStart->next;
        while (toDelete != nextBlock) {
            Node* temp = toDelete;
            toDelete = toDelete->next;
            delete temp;
        }

        blockStart->next = nextBlock;

        if (prevCollapsed != nullptr) {
            prevCollapsed->next = blockStart;
        } else {
            head = blockStart;
        }

        prevCollapsed = blockStart;
        current = nextBlock;
    }
}
```

### Por que funciona

Esta solucion funciona porque cada nodo pertenece a un unico bloque.

Para cada bloque:

- el primer nodo queda como representante;
- su valor se reemplaza por la suma del bloque;
- todos los nodos intermedios del bloque se eliminan;
- el representante se enlaza con el inicio del siguiente bloque.

Asi, al terminar, la lista queda formada exactamente por un nodo por bloque.

### Casos borde

- Lista vacia: no se hace nada.
- Un solo nodo: la lista queda igual.
- Lista completamente creciente: toda la lista se colapsa en un solo nodo.
- Lista completamente no creciente: todos los bloques tienen largo `1`, por lo que la lista queda igual.
- Valores repetidos: no extienden el bloque, porque el patron es estrictamente creciente.

### Complejidad

- Tiempo: `O(n)`.
  Cada nodo se visita una cantidad acotada de veces.
- Espacio adicional: `O(1)`.
  Solo se usan punteros y variables auxiliares.

---

## Guía algorítmica

1. una pila puede guardar operandos o caracteres pendientes segun el problema.
2. una cola o una pila pueden modelar estado pendiente, aunque eso no siempre sea la opcion mas eficiente.
3. una lista enlazada bien manipulada exige pensar en etapas, casos borde, relinkeo correcto y eliminacion segura de nodos.
4. detectar un patron dentro de una lista y transformarlo in-place es una habilidad distinta a solo recorrerla.
5. la justificacion de complejidad es parte de la solucion, no un agregado opcional.