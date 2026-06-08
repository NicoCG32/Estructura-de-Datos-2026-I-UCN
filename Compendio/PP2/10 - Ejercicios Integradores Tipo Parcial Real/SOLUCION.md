# X. Ejercicios Integradores Tipo Parcial Real

Los enunciados de este tema se encuentran en [README.md](README.md).

## Índice rapido

- [X.1](#ejercicio-x1) | [X.2](#ejercicio-x2) | [X.3](#ejercicio-x3) | [X.4](#ejercicio-x4)
- [X.5](#ejercicio-x5) | [X.6](#ejercicio-x6) | [X.7](#ejercicio-x7) | [X.8](#ejercicio-x8)

## Ejercicio X.1

Inserciones AVL:

```text
87, 65, 70, 67, 66, 100, 90, 101, 50, 40, 77, 30, 20
```

Rotaciones:

```text
+70: LR en 87
+66: RL en 65
+90: RL en 87
+40: LL en 65
+30: LL en 66
+20: LL en 40
```

AVL despues de insertar todo:

```text
              70
          /        \
        50          90
      /    \      /    \
     30     66   87     100
    / \    / \   /        \
   20 40  65 67 77        101
```

Eliminando `90` y `65` con menor de los mayores, el árbol queda:

```text
              70
          /        \
        50          100
      /    \       /   \
     30     66    87    101
    / \      \    /
   20 40     67  77
```

HeapSort con los valores originales:

```text
max-heap inicial:
101, 87, 100, 67, 77, 70, 90, 65, 50, 40, 66, 30, 20

arreglo final:
20, 30, 40, 50, 65, 66, 67, 70, 77, 87, 90, 100, 101
```

Comparacion:

- AVL: estructura dinamica para insertar, eliminar y buscar en `O(log n)`;
- HeapSort: algoritmo de ordenamiento `O(n log n)` basado en heap;
- Heap: util para extraer prioridad maxima/minima, pero buscar un valor arbitrario cuesta `O(n)`.

## Ejercicio X.2

Árbol:

```text
          1
       /     \
      2       3
     / \     / \
    4   5   6   7
```

Preorden:

```text
1, 2, 4, 5, 3, 6, 7
```

Implementación:

```cpp
# include <unordered_map>
# include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node* buildRec(vector<int>& inorder, int inL, int inR,
               vector<int>& postorder, int postL, int postR,
               unordered_map<int, int>& pos) {
    if (inL > inR) return nullptr;

    int rootValue = postorder[postR];
    Node* root = new Node(rootValue);
    int mid = pos[rootValue];
    int leftSize = mid - inL;

    root->left = buildRec(inorder, inL, mid - 1,
                          postorder, postL, postL + leftSize - 1, pos);

    root->right = buildRec(inorder, mid + 1, inR,
                           postorder, postL + leftSize, postR - 1, pos);

    return root;
}

Node* buildFromInPost(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size()) return nullptr;
    if (inorder.empty()) return nullptr;

    unordered_map<int, int> pos;
    for (int i = 0; i < (int)inorder.size(); i++) {
        pos[inorder[i]] = i;
    }

    return buildRec(inorder, 0, inorder.size() - 1,
                    postorder, 0, postorder.size() - 1, pos);
}
```

En postorden se visita izquierda, derecha y raíz. Por eso el ultimo valor del segmento postorden siempre es la raíz del subarbol que se esta reconstruyendo.

## Ejercicio X.3

```cpp
# include <algorithm>
# include <stack>
# include <vector>
using namespace std;

void recolectarRango(Node* root, int K1, int K2, vector<int>& values) {
    stack<Node*> st;
    Node* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            if (current->value < K1) {
                current = current->right;
            } else {
                st.push(current);
                current = current->left;
            }
        }

        if (st.empty()) break;
        current = st.top();
        st.pop();

        if (current->value > K2) break;

        values.push_back(current->value);
        current = current->right;
    }
}

vector<int> calcularSumas(Node* root, int K1, int K2, int K3) {
    vector<int> values;
    vector<int> sums;
    if (K1 > K2 || K3 <= 0) return sums;

    recolectarRango(root, K1, K2, values);
    int n = values.size();
    if (K3 > n) return sums;

    vector<int> idx(K3);
    for (int i = 0; i < K3; i++) idx[i] = i;

    while (true) {
        int total = 0;
        for (int i = 0; i < K3; i++) total += values[idx[i]];
        sums.push_back(total);

        int p = K3 - 1;
        while (p >= 0 && idx[p] == n - K3 + p) p--;
        if (p < 0) break;

        idx[p]++;
        for (int j = p + 1; j < K3; j++) {
            idx[j] = idx[j - 1] + 1;
        }
    }

    sort(sums.begin(), sums.end());
    sums.erase(unique(sums.begin(), sums.end()), sums.end());
    return sums;
}
```

Para el ejemplo:

```text
valores = [2, 4, 8, 10], K3 = 2
sumas = [6, 10, 12, 14, 18]
```

## Ejercicio X.4

```cpp
# include <vector>
# include <utility>
using namespace std;

class CharNode {
public:
    char id;
    CharNode(char id) : id(id) {}
};

class NodeLink {
public:
    CharNode* src;
    CharNode* dest;
    NodeLink* next;
};

int posOrCreate(vector<pair<char, int>>& degree, char id) {
    for (int i = 0; i < (int)degree.size(); i++) {
        if (degree[i].first == id) return i;
    }
    degree.push_back({id, 0});
    return degree.size() - 1;
}

bool checkGraph(NodeLink* list, vector<char>& socialV, vector<char>& aloneV) {
    vector<pair<char, int>> degree;
    bool ok = true;

    for (NodeLink* cur = list; cur != nullptr; cur = cur->next) {
        char a = cur->src->id;
        char b = cur->dest->id;

        int ia = posOrCreate(degree, a);
        int ib = posOrCreate(degree, b);

        if (a == b) {
            ok = false;
        } else {
            degree[ia].second++;
            degree[ib].second++;
        }
    }

    for (auto item : degree) {
        if (item.second >= 3) socialV.push_back(item.first);
        if (item.second == 1) aloneV.push_back(item.first);
    }

    return ok;
}
```

En grafo no dirigido, el grado de un vértice es la cantidad de aristas incidentes sobre el. Cada arista normal incrementa el grado de ambos extremos.

## Ejercicio X.5

```cpp
# include <vector>
using namespace std;

class GNode {
public:
    int id;
    GNode(int id) : id(id) {}
};

class EdgeNode {
public:
    GNode* source;
    GNode* destination;
    EdgeNode* next;
};

vector<int> outDegrees(EdgeNode* edges, int n) {
    vector<int> degree(n, 0);

    for (EdgeNode* cur = edges; cur != nullptr; cur = cur->next) {
        int u = cur->source->id;
        if (0 <= u && u < n) {
            degree[u]++;
        }
    }

    return degree;
}
```

Complejidad:

- Tiempo: `O(M + N)`;
- Espacio adicional: `O(N)`.

## Ejercicio X.6

La solución correcta para una lista pequena de compras combina:

1. Dijkstra entre puntos relevantes;
2. DP con mascara de bits para probar ordenes de visita.

```cpp
# include <algorithm>
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

        for (auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int mejorRutaConCompras(vector<vector<pair<int, int>>>& adj,
                        int entrada, int caja,
                        vector<int> compras) {
    int k = compras.size();
    vector<int> p;
    p.push_back(entrada);
    for (int x : compras) p.push_back(x);
    p.push_back(caja);

    int totalP = p.size();
    vector<vector<int>> d(totalP, vector<int>(totalP, INT_MAX));

    for (int i = 0; i < totalP; i++) {
        vector<int> dist = dijkstra(adj, p[i]);
        for (int j = 0; j < totalP; j++) {
            d[i][j] = dist[p[j]];
        }
    }

    if (k == 0) return d[0][totalP - 1] == INT_MAX ? -1 : d[0][totalP - 1];

    int full = (1 << k) - 1;
    vector<vector<int>> dp(1 << k, vector<int>(k, INT_MAX));

    for (int i = 0; i < k; i++) {
        if (d[0][i + 1] != INT_MAX) dp[1 << i][i] = d[0][i + 1];
    }

    for (int mask = 0; mask <= full; mask++) {
        for (int last = 0; last < k; last++) {
            if (dp[mask][last] == INT_MAX) continue;
            for (int nxt = 0; nxt < k; nxt++) {
                if (mask & (1 << nxt)) continue;
                int nd = d[last + 1][nxt + 1];
                if (nd == INT_MAX) continue;
                int nextMask = mask | (1 << nxt);
                dp[nextMask][nxt] = min(dp[nextMask][nxt], dp[mask][last] + nd);
            }
        }
    }

    int ans = INT_MAX;
    for (int last = 0; last < k; last++) {
        if (dp[full][last] == INT_MAX) continue;
        int toCashier = d[last + 1][totalP - 1];
        if (toCashier == INT_MAX) continue;
        ans = min(ans, dp[full][last] + toCashier);
    }

    return ans == INT_MAX ? -1 : ans;
}
```

Complejidad:

- Dijkstra entre puntos relevantes: `O((k + 2)(V + E) log V)`;
- DP: `O(2^k k^2)`.

## Ejercicio X.7

```cpp
# include <cmath>
# include <cstdlib>
using namespace std;

struct Info {
    bool avl;
    int height;
    int count;
};

Info inspect(Node* root) {
    if (root == nullptr) return {true, 0, 0};

    Info L = inspect(root->left);
    Info R = inspect(root->right);

    int h = 1 + max(L.height, R.height);
    int n = 1 + L.count + R.count;
    bool ok = L.avl && R.avl && abs(L.height - R.height) <= 1;

    return {ok, h, n};
}

bool isAvlMinimo(Node* root) {
    Info info = inspect(root);
    int minH = (int)ceil(log2(info.count + 1));
    return info.avl && info.height == minH;
}
```

Esta función puede retornar `false` para un AVL valido si ese AVL no tiene altura minima teorica.

## Ejercicio X.8

```cpp
# include <algorithm>
# include <climits>
# include <queue>
# include <vector>
using namespace std;

int bfsFlow(vector<vector<int>>& residual, int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v = 0; v < (int)residual.size(); v++) {
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
    vector<vector<int>> residual = capacity;
    vector<int> parent(capacity.size());
    int answer = 0;

    while (true) {
        int flow = bfsFlow(residual, s, t, parent);
        if (flow == 0) break;

        answer += flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            residual[prev][cur] -= flow;
            residual[cur][prev] += flow;
            cur = prev;
        }
    }

    return answer;
}
```

Idea:

Mientras exista un camino con capacidad residual positiva desde `s` hasta `t`, se envia por ese camino la minima capacidad disponible. Luego se actualiza la red residual.
