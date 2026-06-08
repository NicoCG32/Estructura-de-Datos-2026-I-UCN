# V. BFS y DFS en Grafos

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [V.1](#ejercicio-v1) | [V.2](#ejercicio-v2) | [V.3](#ejercicio-v3) | [V.4](#ejercicio-v4)
- [V.5](#ejercicio-v5) | [V.6](#ejercicio-v6) | [V.7](#ejercicio-v7) | [V.8](#ejercicio-v8)

## Ejercicio V.1

BFS desde `A`:

```text
A, B, C, D, E, F
```

DFS desde `A`, visitando vecinos en orden alfabetico:

```text
A, B, D, F, C, E
```

Existe camino desde `C` hasta `F`:

```text
true, por ejemplo C -> D -> F
```

Existe camino desde `E` hasta `B`:

```text
false
```

## Ejercicio V.2

```cpp
# include <queue>
# include <vector>
using namespace std;

vector<int> bfsTraversal(vector<vector<int>>& adj, int start) {
    vector<int> order;
    int n = adj.size();

    if (start < 0 || start >= n) return order;

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return order;
}
```

Complejidad:

- Tiempo: `O(V + E)`;
- Espacio adicional: `O(V)`.

## Ejercicio V.3

```cpp
# include <stack>
# include <vector>
using namespace std;

vector<int> dfsIterTraversal(vector<vector<int>>& adj, int start) {
    vector<int> order;
    int n = adj.size();

    if (start < 0 || start >= n) return order;

    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (visited[u]) continue;

        visited[u] = true;
        order.push_back(u);

        for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
            int v = adj[u][i];
            if (!visited[v]) {
                st.push(v);
            }
        }
    }

    return order;
}
```

Se apilan los vecinos en orden inverso para que al desapilar se respete el orden ascendente.

Complejidad:

- Tiempo: `O(V + E)`;
- Espacio adicional: `O(V)`.

## Ejercicio V.4

```cpp
# include <queue>
# include <vector>
using namespace std;

bool pathExists(vector<vector<int>>& adj, int src, int dst) {
    int n = adj.size();
    if (src < 0 || src >= n || dst < 0 || dst >= n) return false;

    vector<bool> visited(n, false);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == dst) return true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return false;
}
```

Se usa BFS porque basta con explorar alcanzabilidad. DFS tambien seria correcto para existencia de camino; BFS ademas permitiria recuperar distancia minima si se almacenan distancias.

## Ejercicio V.5

```cpp
# include <queue>
# include <vector>
using namespace std;

int countComponents(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int components = 0;

    for (int start = 0; start < n; start++) {
        if (visited[start]) continue;

        components++;
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return components;
}
```

Complejidad:

- Tiempo: `O(V + E)`;
- Espacio adicional: `O(V)`.

## Ejercicio V.6

```cpp
# include <queue>
# include <vector>
using namespace std;

int shortestDistanceUnweighted(vector<vector<int>>& adj, int src, int dst) {
    int n = adj.size();
    if (src < 0 || src >= n || dst < 0 || dst >= n) return -1;

    vector<int> dist(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == dst) return dist[u];

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return -1;
}
```

BFS explora primero distancia `0`, luego distancia `1`, luego distancia `2`, etc. Por eso la primera vez que llega a `dst`, la distancia es minima.

## Ejercicio V.7

BFS es adecuado para distancia minima en grafos no ponderados porque procesa por capas. Todos los vértices que están a distancia `d` se procesan antes que los vértices a distancia `d + 1`.

DFS no garantiza distancia minima porque puede profundizar por un camino largo antes de revisar un camino más corto que estaba disponible desde el inicio.

## Ejercicio V.8

1. Un árbol es un grafo conexo y sin ciclos.
2. Un grafo no dirigido y conexo es árbol si no tiene ciclos. Equivalentemente, con `V` vértices debe tener `V - 1` aristas.
3. Un vértice visitado es un vértice que ya fue descubierto por el recorrido y no debe tratarse como nuevo.
4. Si no se marca visitado en un grafo con ciclos, el algoritmo puede repetir vértices indefinidamente o crecer de forma explosiva.

