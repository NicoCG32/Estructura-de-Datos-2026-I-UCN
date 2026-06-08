# Ayudantía 8: Soluciones
## Índice

- [Ejercicio 1](#ejercicio-1)
- [Ejercicio 2](#ejercicio-2)
- [Ejercicio 3](#ejercicio-3)
- [Ejercicio 4](#ejercicio-4)


Esta carpeta contiene las soluciones de los ejercicios propuestos en la [Ayudantía 8](README.md).

La lógica general es la misma en todos los ejercicios:

- insertar como BST;
- actualizar alturas;
- revisar el factor de balance;
- aplicar la rotacion necesaria si aparece un desbalance.

## Ejemplo 1: inserta `30, 20, 10`

Despues de insertar `30` y `20`:

```text
  30
 /
20
```

Al insertar `10` aparece un caso `LL` en `30`.

Rotacion a la derecha:

```text
   20
  /  \
10   30
```

## Ejemplo 2: inserta `10, 20, 30`

Despues de insertar los tres valores aparece un caso `RR` en `10`.

Rotacion a la izquierda:

```text
   20
  /  \
10   30
```

## Ejemplo 3: inserta `30, 10, 20`

Primero se forma este desbalance:

```text
   30
  /
10
  \
   20
```

Es un caso `LR`.

Primero se rota a la izquierda en `10` y luego a la derecha en `30`.

Resultado final:

```text
   20
  /  \
10   30
```

## Ejemplo 4: inserta `10, 30, 20`

Primero se forma este desbalance:

```text
10
  \
   30
  /
20
```

Es un caso `RL`.

Primero se rota a la derecha en `30` y luego a la izquierda en `10`.

Resultado final:

```text
   20
  /  \
10   30
```

### Ejercicio 1

Vector:

```cpp
vector<int> v = {30, 20, 10, 25, 27};
```

### Paso a paso

1. `30` es la raíz.
2. `20` queda a la izquierda de `30`.
3. `10` produce un caso `LL` en `30`, entonces se rota a la derecha.

Árbol intermedio:

```text
   20
  /  \
10   30
```

4. `25` entra como hijo izquierdo de `30`.
5. `27` entra como hijo derecho de `25` y produce un caso `LR` en el nodo `30`.

Primero rotacion izquierda en `25`:

```text
   20
  /  \
10   30
     /
    27
   /
  25
```

Luego rotacion derecha en `30`.

### Árbol final

```text
    20
   /  \
 10    27
      /  \
     25   30
```

### Ejercicio 2

Vector:

```cpp
vector<int> v = {10, 20, 30, 40, 50, 25};
```

### Paso a paso

1. `10`, `20`, `30` producen un caso `RR` en `10`.

Árbol tras esa rotacion:

```text
   20
  /  \
10   30
```

2. `40` queda como hijo derecho de `30`.
3. `50` produce un caso `RR` en `30`, y el subarbol derecho pasa a ser:

```text
   40
  /  \
30   50
```

4. `25` entra como hijo izquierdo de `30`.
5. Con `25`, el nodo `20` queda desbalanceado en forma `RL`.

Primero rotacion derecha en `40`:

```text
   20
  /  \
10   30
     /  \
    25   40
          \
          50
```

Luego rotacion izquierda en `20`.

### Árbol final

```text
    30
   /  \
 20    40
 / \     \
10 25    50
```

### Ejercicio 3

Vector:

```cpp
vector<int> v = {50, 30, 70, 20, 40, 60, 80, 10, 25, 65}
```

### Observacion

En esta secuencia no aparece ninguna rotacion. Cada insercion mantiene el balance en `-1`, `0` o `1`.

### Árbol final

```text
        50
      /    \
    30      70
   /  \    /  \
 20   40  60   80
 / \         \
10 25        65
```

### Ejercicio 4

Vector:

```cpp
vector<int> v = {15, 10, 20, 8, 12, 17, 25, 19, 18}
```

### Paso a paso

1. Hasta `25`, el árbol queda perfectamente balanceado.
2. `19` entra como hijo derecho de `17`.
3. `18` entra como hijo izquierdo de `19`.

El primer nodo desbalanceado es `17`, y el caso es `RL`.

Primero rotacion derecha en `19`:

```text
        15
      /    \
    10      20
   /  \    /  \
  8   12  17   25
            \
            18
             \
             19
```

Luego rotacion izquierda en `17`.

### Árbol final

```text
        15
      /    \
    10      20
   /  \    /  \
  8   12  18   25
          /  \
         17  19
```

### Factores de balance finales

- `15`: equilibrado;
- `10`: equilibrado;
- `20`: equilibrado;
- `18`: equilibrado;
- `17` y `19`: hojas.

### Eliminaciones

Se elimina la secuencia `[12, 20, 15]`.

#### 1. Eliminar `12`

`12` es una hoja, asi que se borra directamente. El árbol queda:

```text
        15
      /
    10      20
   /       /  \
  8       18   25
          /  \
         17  19
```

No aparece desbalance.

#### 2. Eliminar `20`

`20` tiene dos hijos, asi que se reemplaza por su sucesor inorden, que es `25`. Luego se elimina el `25` original.

El subarbol derecho queda desbalanceado en `25` con caso `LL`, por lo que se rota a la derecha:

```text
        15
      /
    10      25
   /       /  \
  8       18
         /  \
        17  19
```

La rotacion deja el subarbol derecho así:

```text
        15
      /
    10      18
   /       /  \
  8       17   25
               /
              19
```

#### 3. Eliminar `15`

`15` tiene dos hijos, asi que se reemplaza por su sucesor inorden, que es `17`. Luego se elimina el `17` original del subarbol izquierdo de `18`.

El nodo `18` queda con desbalance `RL`, asi que se hace una rotacion doble: primero derecha en `25`, luego izquierda en `18`.

Resultado final:

```text
        17
      /    \
    10      19
   /       /  \
  8       18   25
```
