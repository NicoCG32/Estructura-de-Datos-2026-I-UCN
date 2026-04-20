# Ayudantía 5: Repaso final antes de la PP1

Esta es la ultima ayudantia antes de la prueba. El foco ya no es introducir estructuras nuevas, sino reforzar problemas que obligan a modelar estado, manipular punteros con cuidado y justificar complejidad.

## Instrucciones de trabajo

1. Antes de escribir codigo, describe con palabras que estado guardara la estructura principal.
2. Cuando uses punteros, dibuja la estructura antes y despues de cada paso importante.
3. Al terminar, responde siempre:
   - que hace el algoritmo;
   - que estructura usa y por que;
   - cual es su complejidad temporal;
   - cual es su complejidad espacial.

## Restricciones generales

- Trabaja con nodos y punteros en los ejercicios de lista enlazada.
- No uses contenedores STL como `vector`, `list`, `map` o similares, a menos que el enunciado lo permita.
- En los ejercicios de pila y cola se permite usar `std::stack` y `std::queue`.
- No uses recursion, salvo que el enunciado lo permita expresamente.
- Si creas memoria dinamica auxiliar, debes dejar claro cuando se libera.
- Si el ejercicio pide una complejidad especifica, esa restriccion forma parte del problema.

## Estructura base para listas enlazadas

Para los ejercicios de lista enlazada puedes asumir la siguiente estructura:

```cpp
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};
```

Para estados auxiliares puedes usar `std::stack` y `std::queue` cuando el enunciado lo permita.

---

## Ejercicio 1: Evaluar expresion Postfix con stack

Problema:

Implementa una calculadora que evalua una expresion en notacion Postfix usando una pila.

Firma sugerida:

```cpp
int evaluarPostfixConStack(const string& expr);
```

Restricciones y consideraciones:

- La expresion llega separada por espacios.
- Los operandos son enteros y los operadores posibles son `+`, `-`, `*`, `/`.
- La division es entera.
- Puedes usar `stack<>`.
- Puedes asumir que la expresion es valida.

Ejemplos de entrada y salida:

| Input | Output |
| --- | --- |
| `expr = "2 1 + 3 *"` | `9` |
| `expr = "4 13 5 / +"` | `6` |
| `expr = "10 2 8 * + 3 -"` | `23` |
| `expr = "7 2 3 * -"` | `1` |

---

## Ejercicio 2: Es anagrama usando una queue

Problema:

Implementa una funcion que determine si dos cadenas son anagramas, pero obligatoriamente usando una cola.

Firma sugerida:

```cpp
bool esAnagrama(const string& p1, const string& p2);
```

Restricciones y consideraciones:

- No uses arreglos de frecuencia, `map` ni tablas hash.
- Debes usar la cola para representar los caracteres de `p1` que aun estan disponibles.
- Puedes usar `queue<>`.
- La solucion debe ser iterativa.

Ejemplos de entrada y salida:

| Input | Output |
| --- | --- |
| `("roma", "amor")` | `true` |
| `("listen", "silent")` | `true` |
| `("aabb", "baba")` | `true` |
| `("aabb", "abbb")` | `false` |
| `("abc", "abcc")` | `false` |

---

## Ejercicio 3: Reordenar una lista intercalando extremos

Problema:

Dada una lista enlazada simple:

```text
L0 -> L1 -> L2 -> ... -> Ln
```

debes reordenarla para que quede:

```text
L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
```

Firma sugerida:

```cpp
void reorderListAlternandoExtremos(Node*& head);
```

Restricciones y consideraciones:

- Debe ejecutarse en O(n) tiempo.
- Debe usar O(1) espacio adicional.
- No puedes crear nuevos nodos para la solucion final.
- No puedes usar arreglos, vectores, pilas, colas ni recursion.

Ejemplos de entrada y salida:

| Input | Output |
| --- | --- |
| `1 -> 2 -> 3 -> 4 -> 5` | `1 -> 5 -> 2 -> 4 -> 3` |
| `10 -> 20 -> 30 -> 40` | `10 -> 40 -> 20 -> 30` |
| `7 -> 8 -> 9` | `7 -> 9 -> 8` |
| `5` | `5` |

---

## Ejercicio 4: Colapsar bloques estrictamente crecientes

Problema:

Dada una lista enlazada simple, debes identificar cada bloque contiguo maximal estrictamente creciente y reemplazarlo por un solo nodo cuyo valor sea la suma de todos los elementos del bloque.

Si un bloque tiene un solo nodo, ese nodo se mantiene con su mismo valor.

Firma sugerida:

```cpp
void colapsarBloquesCrecientes(Node*& head);
```

Restricciones y consideraciones:

- Debe ejecutarse en O(n) tiempo.
- Debe usar O(1) espacio adicional.
- No puedes usar arreglos, vectores, pilas, colas ni recursion.
- Los nodos sobrantes del bloque deben eliminarse correctamente.

Ejemplos de entrada y salida:

| Input | Output |
| --- | --- |
| `1 -> 3 -> 5 -> 4 -> 6 -> 2 -> 7 -> 8 -> 9 -> 1` | `9 -> 10 -> 26 -> 1` |
| `2 -> 4 -> 6 -> 8` | `20` |
| `9 -> 7 -> 5 -> 3` | `9 -> 7 -> 5 -> 3` |
| `4 -> 4 -> 5 -> 1 -> 2` | `4 -> 9 -> 3` |

Observacion sobre el ultimo ejemplo:

- `4` forma un bloque solo, porque `4 -> 4` no es estrictamente creciente;
- `4 -> 5` si forma un bloque creciente y se reemplaza por `9`;
- `1 -> 2` se reemplaza por `3`.