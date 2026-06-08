# V. Algoritmos con Listas Enlazadas

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [V.1](#ejercicio-v1) | [V.2](#ejercicio-v2) | [V.3](#ejercicio-v3) | [V.4](#ejercicio-v4) | [V.5](#ejercicio-v5)
- [V.6](#ejercicio-v6) | [V.7](#ejercicio-v7) | [V.8](#ejercicio-v8) | [V.9](#ejercicio-v9) | [V.10](#ejercicio-v10)
- [V.11](#ejercicio-v11) | [V.12](#ejercicio-v12) | [V.13](#ejercicio-v13) | [V.14](#ejercicio-v14) | [V.15](#ejercicio-v15)
- [V.16](#ejercicio-v16) | [V.17](#ejercicio-v17) | [V.18](#ejercicio-v18) | [V.19](#ejercicio-v19) | [V.20](#ejercicio-v20)


## Cobertura actual

- Ejercicios con pauta desarrollada: `V.1`, `V.2`, `V.3`, `V.4`, `V.5`, `V.6`, `V.7`, `V.8`, `V.9`, `V.10`, `V.11`, `V.12`, `V.13`, `V.14`, `V.15`, `V.16`, `V.17`, `V.18`, `V.19`, `V.20`.
- Ejercicios aun sin desarrollar en esta pauta: `ninguno`.

## Supuesto de trabajo

En los ejercicios de este tema se asume la siguiente estructura base cuando el enunciado no indique otra variante.

```cpp
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};
```

## Pauta desarrollada

## Ejercicio V.1
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
    for (int i = 0; current != nullptr && i < index - 1; i++) {
        current = current->next;
    }

    if (current == nullptr) return;

    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}
```

Idea:

Se avanza hasta el nodo anterior a la posición de inserción y luego se reconectan los punteros.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio V.2
```cpp
void eraseAtIndex(Node*& head, int index) {
    if (head == nullptr || index < 0) return;

    if (index == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index - 1; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) return;

    Node* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
}
```

Idea:

Se avanza hasta el nodo anterior a la posicion a eliminar. Luego se salta el nodo objetivo y se libera su memoria.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio V.3
```cpp
void removeAll(Node*& head, int value) {
    while (head != nullptr && head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == value) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        } else {
            current = current->next;
        }
    }
}
```

Idea:

Primero se limpian todas las apariciones al inicio. Luego se recorre la lista borrando cada coincidencia encontrada en `current->next`.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio V.4
```cpp
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
```

Idea:

Se recorre la lista una vez y en cada paso se invierte el puntero `next` del nodo actual.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio V.5
```cpp
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* head = nullptr;
    Node* tail = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry > 0) {
        int a = 0;
        int b = 0;

        if (l1 != nullptr) a = l1->data;
        if (l2 != nullptr) b = l2->data;

        int sum = a + b + carry;
        carry = sum / 10;
        int digit = sum % 10;

        Node* newNode = new Node(digit);
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

Idea:

Cada nodo representa un dígito. Se avanza en paralelo sumando posición a posición, manteniendo un acarreo.

Complejidad:

- Tiempo: `O(max(n, m))`
- Espacio adicional: `O(max(n, m))` por la lista resultado

## Ejercicio V.6
```cpp
bool isPrime(int value) {
    if (value < 2) return false;
    for (int d = 2; d * d <= value; d++) {
        if (value % d == 0) return false;
    }
    return true;
}

void removePrimes(Node*& head) {
    while (head != nullptr && isPrime(head->data)) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (isPrime(current->next->data)) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        } else {
            current = current->next;
        }
    }
}
```

Idea:

Se recorre la lista y se elimina todo nodo cuyo valor sea primo. La primalidad se decide con un chequeo hasta la raíz cuadrada del valor.

Complejidad:

- Tiempo: `O(n * sqrt(M))`, donde `M` es el mayor valor de la lista
- Espacio adicional: `O(1)`

## Ejercicio V.7
Interpretación adoptada:

Se elimina un patrón cuando los valores forman una secuencia consecutiva creciente del tipo:

```text
x, x+1, x+2, ...
```

manteniendo solo el primer nodo del patrón.

```cpp
void compressIncreasingRuns(Node*& head) {
    Node* current = head;

    while (current != nullptr) {
        while (current->next != nullptr &&
               current->next->data == current->data + 1) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        }

        current = current->next;
    }
}
```

Ejemplo:

```text
[1,2,3,4,5,6,7,100,2] -> [1,100,2]
```

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio V.8
```cpp
Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```

Idea:

Se usan dos punteros: `slow` avanza de uno en uno y `fast` de dos en dos. Cuando `fast` llega al final, `slow` queda en el medio.

Criterio adoptado:

Si hay dos nodos medios, esta implementación retorna el **segundo** de ellos.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

## Ejercicio V.9
```cpp
Node* mergeSorted(Node* a, Node* b) {
    Node* head = nullptr;
    Node* tail = nullptr;

    auto append = [&](int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    };

    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            append(a->data);
            a = a->next;
        } else {
            append(b->data);
            b = b->next;
        }
    }

    while (a != nullptr) {
        append(a->data);
        a = a->next;
    }

    while (b != nullptr) {
        append(b->data);
        b = b->next;
    }

    return head;
}
```

Idea:

Se recorren ambas listas en paralelo, agregando siempre el menor elemento disponible a la lista resultado.

Complejidad:

- Tiempo: `O(n + m)`
- Espacio adicional: `O(n + m)` por la nueva lista

## Ejercicio V.10
Supuesto adicional:

```cpp
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};
```

```cpp
bool isPalindromeCircular(DNode* head) {
    if (head == nullptr) return true;

    int n = 1;
    DNode* current = head->next;
    while (current != head) {
        n++;
        current = current->next;
    }

    DNode* left = head;
    DNode* right = head->prev;

    for (int i = 0; i < n / 2; i++) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}
```

Idea:

Como la lista es doblemente enlazada y circular, se puede comparar simultaneamente desde ambos extremos avanzando hacia el centro.

Complejidad:

- Tiempo: `O(n)`
- Espacio adicional: `O(1)`

---

## Ejercicio V.11
```cpp
void pushBack(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}
```

## Ejercicio V.12
```cpp
int length(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}
```

## Ejercicio V.13
```cpp
bool contains(Node* head, int value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) return true;
        current = current->next;
    }

    return false;
}
```

## Ejercicio V.14
```cpp
void removeFirst(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}
```

## Ejercicio V.15
```cpp
int maxValue(Node* head) {
    int maximo = head->data;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data > maximo) {
            maximo = current->data;
        }
        current = current->next;
    }

    return maximo;
}
```

## Ejercicio V.16
```cpp
void removeConsecutiveDuplicates(Node*& head) {
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}
```

## Ejercicio V.17
```cpp
void insertSorted(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr || value <= head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
```

## Ejercicio V.18
```cpp
Node* interleave(Node* a, Node* b) {
    Node* head = nullptr;
    Node* tail = nullptr;

    auto append = [&](int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    };

    while (a != nullptr || b != nullptr) {
        if (a != nullptr) {
            append(a->data);
            a = a->next;
        }
        if (b != nullptr) {
            append(b->data);
            b = b->next;
        }
    }

    return head;
}
```

## Ejercicio V.19
```cpp
int sumList(Node* head) {
    int suma = 0;
    Node* current = head;

    while (current != nullptr) {
        suma += current->data;
        current = current->next;
    }

    return suma;
}
```

## Ejercicio V.20
```cpp
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}
```
