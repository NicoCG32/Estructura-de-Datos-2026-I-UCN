# Intensiva I: Guia de Estudio para PP1

Esta carpeta ya no concentra todo el banco en dos archivos grandes. Desde ahora, la intensiva esta organizada **por temas**, de modo que cada bloque tenga sus propios enunciados y su propia pauta.

El indice general de pautas se encuentra en [SOLUCION.md](SOLUCION.md).

## Indice general

| Tema | Enfoque principal | Enunciados | Pauta |
| --- | --- | --- | --- |
| I. Ruteos de Punteros y Arreglos | Memoria, indirecciones y ruteo | [README](<01 - Ruteos de Punteros y Arreglos/README.md>) | [SOLUCION](<01 - Ruteos de Punteros y Arreglos/SOLUCION.md>) |
| II. Ruteos de Herencia y Polimorfismo | Despacho dinamico, slicing y destruccion | [README](<02 - Ruteos de Herencia y Polimorfismo/README.md>) | [SOLUCION](<02 - Ruteos de Herencia y Polimorfismo/SOLUCION.md>) |
| III. Deteccion y Correccion de Errores | Sintaxis, memoria y errores de diseno | [README](<03 - Deteccion y Correccion de Errores/README.md>) | [SOLUCION](<03 - Deteccion y Correccion de Errores/SOLUCION.md>) |
| IV. Complejidad Algoritmica | Analisis temporal y espacial | [README](<04 - Complejidad Algoritmica/README.md>) | [SOLUCION](<04 - Complejidad Algoritmica/SOLUCION.md>) |
| V. Algoritmos con Listas Enlazadas | Recorridos, insercion, borrado y modelamiento | [README](<05 - Algoritmos con Listas Enlazadas/README.md>) | [SOLUCION](<05 - Algoritmos con Listas Enlazadas/SOLUCION.md>) |
| VI. Algoritmos con Pilas y Colas | Estado LIFO/FIFO y simulacion de procesos | [README](<06 - Algoritmos con Pilas y Colas/README.md>) | [SOLUCION](<06 - Algoritmos con Pilas y Colas/SOLUCION.md>) |
| VII. Verdadero o Falso | Teoria conceptual corta | [README](<07 - Verdadero o Falso/README.md>) | [SOLUCION](<07 - Verdadero o Falso/SOLUCION.md>) |
| VIII. Seleccion Multiple | Teoria y criterio de eleccion | [README](<08 - Seleccion Multiple/README.md>) | [SOLUCION](<08 - Seleccion Multiple/SOLUCION.md>) |
| IX. Completar Conceptos | Lenguaje tecnico y definiciones | [README](<09 - Completar Conceptos/README.md>) | [SOLUCION](<09 - Completar Conceptos/SOLUCION.md>) |
| X. Ejercicios Integradores Tipo Parcial Real | Problemas largos y mezcla de contenidos | [README](<10 - Ejercicios Integradores Tipo Parcial Real/README.md>) | [SOLUCION](<10 - Ejercicios Integradores Tipo Parcial Real/SOLUCION.md>) |

## Cobertura

Esta intensiva cubre los contenidos que con mas frecuencia aparecen en la primera prueba:

- punteros, arreglos y ruteo de codigo en C++;
- herencia y polimorfismo;
- deteccion y correccion de errores de compilacion o de diseno;
- complejidad algoritmica basica;
- algoritmos con listas enlazadas;
- algoritmos con pilas y colas;
- refuerzo teorico mediante verdadero o falso, seleccion multiple y completar conceptos;
- ejercicios integradores construidos con patron de parcial real.

No se incluye `SparseMatrix`, porque el criterio actual del curso indica que **no entra en la PP1**.

## Como usar esta intensiva

Se recomienda trabajar cada tema con la misma disciplina:

1. leer primero el `README.md` del tema;
2. intentar resolver los ejercicios sin mirar la pauta;
3. contrastar el razonamiento con `SOLUCION.md`;
4. reescribir la idea de solucion con tus propias palabras;
5. volver a resolver, especialmente los ejercicios de ruteo y los algoritmicos, sin apoyo externo.

En listas, pilas y colas, el foco no debe ser solo obtener un codigo que funcione. Tambien debe quedar claro:

- que estado guarda la estructura;
- por que esa estructura representa bien el problema;
- como evoluciona ese estado a lo largo del algoritmo;
- cual es el costo temporal y espacial de la solucion.

## Ruta de estudio recomendada

Una ruta razonable para preparar PP1 es la siguiente:

1. Comenzar por [I. Ruteos de Punteros y Arreglos](<01 - Ruteos de Punteros y Arreglos/README.md>) para reforzar memoria, indirecciones y seguimiento de estado.
2. Continuar con [II. Ruteos de Herencia y Polimorfismo](<02 - Ruteos de Herencia y Polimorfismo/README.md>) y [III. Deteccion y Correccion de Errores](<03 - Deteccion y Correccion de Errores/README.md>) para distinguir bien despacho dinamico, slicing, destructores virtuales y errores tipicos de firma o diseno.
3. Estudiar [IV. Complejidad Algoritmica](<04 - Complejidad Algoritmica/README.md>) antes de pasar a implementaciones, porque muchas restricciones de parcial exigen justificar costo o trabajar en una sola pasada.
4. Resolver despues [V. Algoritmos con Listas Enlazadas](<05 - Algoritmos con Listas Enlazadas/README.md>) y [VI. Algoritmos con Pilas y Colas](<06 - Algoritmos con Pilas y Colas/README.md>), poniendo especial atencion a la representacion del estado.
5. Usar [VII. Verdadero o Falso](<07 - Verdadero o Falso/README.md>), [VIII. Seleccion Multiple](<08 - Seleccion Multiple/README.md>) y [IX. Completar Conceptos](<09 - Completar Conceptos/README.md>) para consolidar teoria y lenguaje tecnico.
6. Cerrar con [X. Ejercicios Integradores Tipo Parcial Real](<10 - Ejercicios Integradores Tipo Parcial Real/README.md>) para aproximarse al nivel real de la evaluacion.

## Ruta Intensiva I

Ruta breve y ordenada por tema, con cada ejercicio separado:

| Tema | Ejercicio | Descripcion breve | Enunciado | Pauta |
| --- | --- | --- | --- | --- |
| I. Ruteos de Punteros y Arreglos | [I.3](<01 - Ruteos de Punteros y Arreglos/README.md#ejercicio-i3>) | paso por puntero y referencia con efectos cruzados | [Ver](<01 - Ruteos de Punteros y Arreglos/README.md#ejercicio-i3>) | [Ver](<01 - Ruteos de Punteros y Arreglos/SOLUCION.md#ejercicio-i3>) |
| I. Ruteos de Punteros y Arreglos | [I.5](<01 - Ruteos de Punteros y Arreglos/README.md#ejercicio-i5>) | aritmetica de punteros y actualizacion sobre arreglo | [Ver](<01 - Ruteos de Punteros y Arreglos/README.md#ejercicio-i5>) | [Ver](<01 - Ruteos de Punteros y Arreglos/SOLUCION.md#ejercicio-i5>) |
| II. Ruteos de Herencia y Polimorfismo | [II.10](<02 - Ruteos de Herencia y Polimorfismo/README.md#ejercicio-ii10>) | orden de construccion y despacho dinamico | [Ver](<02 - Ruteos de Herencia y Polimorfismo/README.md#ejercicio-ii10>) | [Ver](<02 - Ruteos de Herencia y Polimorfismo/SOLUCION.md#ejercicio-ii10>) |
| III. Deteccion y Correccion de Errores | [III.5](<03 - Deteccion y Correccion de Errores/README.md#ejercicio-iii5>) | relacion entre virtual en base y override en derivada | [Ver](<03 - Deteccion y Correccion de Errores/README.md#ejercicio-iii5>) | [Ver](<03 - Deteccion y Correccion de Errores/SOLUCION.md#ejercicio-iii5>) |
| IV. Complejidad Algoritmica | [IV.5](<04 - Complejidad Algoritmica/README.md#ejercicio-iv5>) | lectura de ciclos anidados con crecimiento logaritmico | [Ver](<04 - Complejidad Algoritmica/README.md#ejercicio-iv5>) | [Ver](<04 - Complejidad Algoritmica/SOLUCION.md#ejercicio-iv5>) |
| IV. Complejidad Algoritmica | [IV.10](<04 - Complejidad Algoritmica/README.md#ejercicio-iv10>) | eleccion de estructura segun operaciones dominantes | [Ver](<04 - Complejidad Algoritmica/README.md#ejercicio-iv10>) | [Ver](<04 - Complejidad Algoritmica/SOLUCION.md#ejercicio-iv10>) |
| V. Algoritmos con Listas Enlazadas | [V.6](<05 - Algoritmos con Listas Enlazadas/README.md#ejercicio-v6>) | eliminacion de nodos manteniendo enlaces correctos | [Ver](<05 - Algoritmos con Listas Enlazadas/README.md#ejercicio-v6>) | [Ver](<05 - Algoritmos con Listas Enlazadas/SOLUCION.md#ejercicio-v6>) |
| VI. Algoritmos con Pilas y Colas | [VI.5](<06 - Algoritmos con Pilas y Colas/README.md#ejercicio-vi5>) | simulacion de atencion con cola y control de estado | [Ver](<06 - Algoritmos con Pilas y Colas/README.md#ejercicio-vi5>) | [Ver](<06 - Algoritmos con Pilas y Colas/SOLUCION.md#ejercicio-vi5>) |
| VII. Verdadero o Falso | [VII.3](<07 - Verdadero o Falso/README.md#ejercicio-vii3>) | importancia del destructor virtual en herencia | [Ver](<07 - Verdadero o Falso/README.md#ejercicio-vii3>) | [Ver](<07 - Verdadero o Falso/SOLUCION.md#ejercicio-vii3>) |
| VIII. Seleccion Multiple | [VIII.4](<08 - Seleccion Multiple/README.md#ejercicio-viii4>) | condicion para destruir correctamente por puntero base | [Ver](<08 - Seleccion Multiple/README.md#ejercicio-viii4>) | [Ver](<08 - Seleccion Multiple/SOLUCION.md>) |
| IX. Completar Conceptos | [IX.6](<09 - Completar Conceptos/README.md#ejercicio-ix6>) | diferencia formal entre LIFO y FIFO | [Ver](<09 - Completar Conceptos/README.md#ejercicio-ix6>) | [Ver](<09 - Completar Conceptos/SOLUCION.md>) |
| X. Ejercicios Integradores Tipo Parcial Real | [X.6](<10 - Ejercicios Integradores Tipo Parcial Real/README.md#ejercicio-x6>) | transformacion de estado en estructura enlazada con recorrido cuidadoso | [Ver](<10 - Ejercicios Integradores Tipo Parcial Real/README.md#ejercicio-x6>) | [Ver](<10 - Ejercicios Integradores Tipo Parcial Real/SOLUCION.md#ejercicio-x6>) |
| X. Ejercicios Integradores Tipo Parcial Real | [X.10](<10 - Ejercicios Integradores Tipo Parcial Real/README.md#ejercicio-x10>) | ejercicio integrador largo con analisis de estructura y costo | [Ver](<10 - Ejercicios Integradores Tipo Parcial Real/README.md#ejercicio-x10>) | [Ver](<10 - Ejercicios Integradores Tipo Parcial Real/SOLUCION.md#ejercicio-x10>) |
| X. Ejercicios Integradores Tipo Parcial Real | [X.9](<10 - Ejercicios Integradores Tipo Parcial Real/README.md#ejercicio-x9>) | busqueda por capas con cola y estados visitados | [Ver](<10 - Ejercicios Integradores Tipo Parcial Real/README.md#ejercicio-x9>) | [Ver](<10 - Ejercicios Integradores Tipo Parcial Real/SOLUCION.md#ejercicio-x9>) |


## Patrones en parciales (2022-2025)

Al revisar modelos de prueba y pautas de distintos semestres, se repiten varios patrones:

- suele existir una seccion teorica conceptual al inicio, a veces en formato de completar, relacionar definiciones o corregir afirmaciones;
- los ruteos no se reducen a leer salida, porque mezclan punteros, arreglos, ciclos, aritmetica de punteros y reasignacion indirecta;
- en herencia y polimorfismo es comun que aparezcan errores de sintaxis, firmas inconsistentes o usos incorrectos de punteros base;
- en listas enlazadas y pilas/colas aparecen problemas de transformacion de estado, no solo operaciones aisladas;
- la complejidad algoritmica puede pedirse de forma directa o quedar impuesta como restriccion del enunciado.

## Formato sugerido de una PP1

Una selección alineada con el curso, seria:

1. un ruteo de punteros;
2. un ruteo de herencia/polimorfismo o un ejercicio de correccion de errores;
3. un ejercicio de listas enlazadas;
4. un ejercicio de pilas/colas;
5. una seccion breve de teoria y, eventualmente, una pregunta de complejidad.

## Indicaciones generales

- En los ejercicios de ruteo, se debe seguir el estado de las variables y justificar la salida final.
- En herencia y polimorfismo, no basta con decir que metodo se ejecuta: hay que explicar por que se resuelve esa version.
- En correccion de errores, no basta con etiquetar un fragmento como incorrecto: hay que identificar la causa y proponer una version coherente.
- En ejercicios algoritmicos, la respuesta debe incluir idea general, estructura utilizada, estado representado y complejidades.