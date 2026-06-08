# VI. Algoritmos en Grafos

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [VI.1](#ejercicio-vi1) | [VI.2](#ejercicio-vi2) | [VI.3](#ejercicio-vi3) | [VI.4](#ejercicio-vi4)
- [VI.5](#ejercicio-vi5) | [VI.6](#ejercicio-vi6) | [VI.7](#ejercicio-vi7) | [VI.8](#ejercicio-vi8)

## Ejercicio VI.1

```cpp
# include <vector>
using namespace std;

vector<int> outDegrees(EdgeNode* edges, int n) {
    vector<int> degree(n, 0);

    EdgeNode* current = edges;
    while (current != nullptr) {
        int u = current->source->id;
        if (0 <= u && u < n) {
            degree[u]++;
        }
        current = current->next;
    }

    return degree;
}
```

Complejidad:

- Tiempo: `O(M + N)`, por inicializar el vector y recorrer los `M` arcos;
- Espacio adicional: `O(N)` por el vector de salida.

## Ejercicio VI.2

```cpp
# include <vector>
# include <utility>
using namespace std;

int findIndex(vector<pair<char, int>>& degree, char id) {
    for (int i = 0; i < (int)degree.size(); i++) {
        if (degree[i].first == id) return i;
    }

    degree.push_back({id, 0});
    return degree.size() - 1;
}

bool checkGraph(NodeLink* list, vector<char>& socialV, vector<char>& aloneV) {
    vector<pair<char, int>> degree;
    bool valid = true;

    NodeLink* current = list;
    while (current != nullptr) {
        char a = current->src->id;
        char b = current->dest->id;

        int ia = findIndex(degree, a);
        int ib = findIndex(degree, b);

        if (a == b) {
            valid = false;
        } else {
            degree[ia].second++;
            degree[ib].second++;
        }

        current = current->next;
    }

    for (auto item : degree) {
        if (item.second >= 3) socialV.push_back(item.first);
        if (item.second == 1) aloneV.push_back(item.first);
    }

    return valid;
}
```

Complejidad:

- Tiempo: `O(MV)` con esta representacion simple por busqueda lineal;
- Puede mejorarse a `O(M)` promedio usando `unordered_map<char, int>`.

## Ejercicio VI.3

```cpp
# include <vector>
using namespace std;

int outDegreeMatrix(vector<vector<int>>& matrix, int v) {
    int n = matrix.size();
    if (v < 0 || v >= n) return 0;

    int degree = 0;
    for (int j = 0; j < n; j++) {
        if (matrix[v][j] != 0) degree++;
    }

    return degree;
}

int inDegreeMatrix(vector<vector<int>>& matrix, int v) {
    int n = matrix.size();
    if (v < 0 || v >= n) return 0;

    int degree = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[i][v] != 0) degree++;
    }

    return degree;
}
```

Complejidad:

- Cada función cuesta `O(V)`;
- Consultar si existe el arco `u -> v` cuesta `O(1)`.

## Ejercicio VI.4

```cpp
# include <climits>
# include <functional>
# include <queue>
# include <vector>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```

Complejidad:

- Tiempo: `O((V + E) log V)`;
- Espacio adicional: `O(V)`.

## Ejercicio VI.5

```cpp
# include <vector>
using namespace std;

void dfsPaths(vector<vector<int>>& adj, int u, int dst,
              vector<bool>& used, vector<int>& path,
              vector<vector<int>>& result) {
    if (u == dst) {
        result.push_back(path);
        return;
    }

    for (int v : adj[u]) {
        if (!used[v]) {
            used[v] = true;
            path.push_back(v);

            dfsPaths(adj, v, dst, used, path, result);

            path.pop_back();
            used[v] = false;
        }
    }
}

vector<vector<int>> allSimplePaths(vector<vector<int>>& adj, int src, int dst) {
    vector<vector<int>> result;
    int n = adj.size();
    if (src < 0 || src >= n || dst < 0 || dst >= n) return result;

    vector<bool> used(n, false);
    vector<int> path;

    used[src] = true;
    path.push_back(src);

    dfsPaths(adj, src, dst, used, path, result);
    return result;
}
```

Complejidad:

- En el peor caso puede ser exponencial, porque la cantidad de caminos simples puede ser exponencial.

## Ejercicio VI.6

```cpp
# include <algorithm>
# include <climits>
# include <queue>
# include <vector>
using namespace std;

int bfsAugmenting(vector<vector<int>>& residual, int s, int t, vector<int>& parent) {
    int n = residual.size();
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v = 0; v < n; v++) {
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                int newFlow = min(flow, residual[u][v]);
                if (v == t) return newFlow;
                q.push({v, newFlow});
            }
        }
    }

    return 0;
}

int maxFlow(vector<vector<int>> capacity, int s, int t) {
    int n = capacity.size();
    vector<vector<int>> residual = capacity;
    vector<int> parent(n);
    int flow = 0;

    while (true) {
        int newFlow = bfsAugmenting(residual, s, t, parent);
        if (newFlow == 0) break;

        flow += newFlow;
        int current = t;

        while (current != s) {
            int previous = parent[current];
            residual[previous][current] -= newFlow;
            residual[current][previous] += newFlow;
            current = previous;
        }
    }

    return flow;
}
```

Idea:

Edmonds-Karp usa BFS para encontrar caminos aumentantes de menor cantidad de arcos en la red residual.

## Ejercicio VI.7

Como `compras.size() <= 10`, se puede resolver con programacion dinamica sobre subconjuntos. Primero se calcula la menor distancia entre todos los puntos relevantes mediante Dijkstra.

```cpp
# include <algorithm>
# include <climits>
# include <vector>
using namespace std;

int mejorRutaConCompras(vector<vector<pair<int, int>>>& adj,
                        int entrada, int caja,
                        vector<int> compras) {
    vector<int> points;
    points.push_back(entrada);
    for (int x : compras) points.push_back(x);
    points.push_back(caja);

    int p = points.size();
    vector<vector<int>> d(p, vector<int>(p, INT_MAX));

    for (int i = 0; i < p; i++) {
        vector<int> dist = dijkstra(adj, points[i]);
        for (int j = 0; j < p; j++) {
            d[i][j] = dist[points[j]];
        }
    }

    int k = compras.size();
    int full = (1 << k) - 1;
    vector<vector<int>> dp(1 << k, vector<int>(k, INT_MAX));

    for (int i = 0; i < k; i++) {
        if (d[0][i + 1] != INT_MAX) {
            dp[1 << i][i] = d[0][i + 1];
        }
    }

    for (int mask = 0; mask <= full; mask++) {
        for (int last = 0; last < k; last++) {
            if (dp[mask][last] == INT_MAX) continue;

            for (int nxt = 0; nxt < k; nxt++) {
                if (mask & (1 << nxt)) continue;
                if (d[last + 1][nxt + 1] == INT_MAX) continue;

                int nextMask = mask | (1 << nxt);
                dp[nextMask][nxt] = min(dp[nextMask][nxt],
                                        dp[mask][last] + d[last + 1][nxt + 1]);
            }
        }
    }

    if (k == 0) return d[0][p - 1] == INT_MAX ? -1 : d[0][p - 1];

    int ans = INT_MAX;
    for (int last = 0; last < k; last++) {
        if (dp[full][last] == INT_MAX || d[last + 1][p - 1] == INT_MAX) continue;
        ans = min(ans, dp[full][last] + d[last + 1][p - 1]);
    }

    return ans == INT_MAX ? -1 : ans;
}
```

Complejidad:

- Dijkstra para puntos relevantes: `O(k * (V + E) log V)`;
- DP de subconjuntos: `O(2^k * k^2)`.

## Ejercicio VI.8

| Representacion | Ventaja | Desventaja | Conviene cuando |
| --- | --- | --- | --- |
| Lista de arcos | simple para recorrer aristas | buscar vecinos de un nodo cuesta caro | el enunciado entrega arcos secuenciales |
| Lista de adyacencia | eficiente en grafos dispersos | verificar arco especifico puede costar grado del nodo | se recorren vecinos con frecuencia |
| Matriz de adyacencia | consultar `u -> v` cuesta `O(1)` | ocupa `O(V^2)` memoria | el grafo es denso o se consultan arcos puntuales |
