# Ayudantía 3: Soluciones
## Índice

- [Ejercicio 1: Insertar por índice](#ejercicio-1-insertar-por-índice)
- [Ejercicio 2: Eliminar por índice](#ejercicio-2-eliminar-por-índice)
- [Ejercicio 3: Add Two Numbers](#ejercicio-3-add-two-numbers)
- [Ejercicio 4: Factorial simulando recursión con stack de nodos](#ejercicio-4-factorial-simulando-recursión-con-stack-de-nodos)


Ayudantía 3 - Soluciones

Estas soluciones están ajustadas a los ejercicios actuales del README.

En todas se asume: `using namespace std;`.

## Estructura base para versiones sin STL

```cpp
struct Node {
    int data;
    Node* next;
    Node(int n) : data(n), next(nullptr) {}
};
```

---

### Ejercicio 1: Insertar por índice

```cpp
void insertAtIndex(Node*& head, int index, int value) {
    if (index < 0) return;

    if (index == 0) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) return; // Esto es si queremos omitir el valor ya que el índice está por sobre lo esperado

    Node* newNode = new Node(value);
    newNode->next = current->next;  // next de Current es el nodo de la derecha
    current->next = newNode; // Current es el nodo de la izquierda
}
```

// Solución vista en clases (Considerando que si el índice es mayor al tamaño de la lista, se inserta igual)

```cpp
void insertAtIndex(Node*& head, int index, int value) {
    if (index < 0) return; // Caso índice negativo

    if (head == nullptr) { // Si la lista está vacía y el índice > 0, Se inserta como cabeza
        Node* newNode = new Node(value);
        head = newNode;
        return;
    } // Este caso nos faltó ver, pero tenía que ver con los casos de las listas
    // Caso 1: Lista vacía
    // Caso 2: Lista con un elemento
    // Caso 3: Lista con n elementos

    if (index == 0) { // Caso índice = 0
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* cursorLeft = head; // Apunta al que va antes de la inserción
    Node* cursorRight = head->next; // Apunta al que va después de la inserción

    for (int i = 0; i < index - 1; ++i) {

        if (cursorRight == nullptr) break;

        cursorLeft = cursorLeft->next;
        cursorRight = cursorRight->next;
    }

    Node* newNode = new Node(value); // Creamos el nodo

    if (cursorRight == nullptr) { // Si el índice es mayor, lo ponemos al final
        cursorLeft->next = newNode;
        return;
    }

    cursorLeft->next = newNode;
    newNode->next = cursorRight;
}
```

---

### Ejercicio 2: Eliminar por índice

```cpp
void eraseAtIndex(Node*& head, int index) {
    if (head == nullptr || index < 0) return;

    if (index == 0) {
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        return;
    }

    Node* current = head;
    for (int i = 0; current->next != nullptr && i < index - 1; ++i) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    Node* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
}
```

---

### Ejercicio 3: Add Two Numbers

```cpp
Node* addTwoNumbers(Node* l1, Node* l2) {
    // Reservado para la ayudantía 4
}
```

---

### Ejercicio 4: Factorial simulando recursión con stack de nodos

### Sin STL (Directo con nodos)

```cpp
long long factorialConStack(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;

    Node* stack = nullptr;
    for (int i = n; i >= 2; --i) {
        Node* newNode = new Node(i);
        newNode->next = stack;
        stack = newNode;
    }

    long long result = 1;
    while (stack != nullptr) {
        result *= stack->data;
        Node* temp = stack;
        stack = stack->next;
        delete temp;
    }

    return result;
}
```

### Con STL

```cpp
# include <stack>

long long factorialConStackSTL(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;

    stack<int> st;
    for (int i = n; i >= 2; --i) {
        st.push(i);
    }

    long long result = 1;
    while (!st.empty()) {
        result *= st.top();
        st.pop();
    }

    return result;
}
```
