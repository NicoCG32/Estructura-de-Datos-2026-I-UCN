#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> caminoBFSMatriz(vector<vector<int> > matriz, int origen, int destino, int bloqueado) {
    // Implementar aquí.
    vector<int> camino;
    return camino;
}

void imprimirCamino(vector<int> camino) {
    char nombres[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for (int i = 0; i < camino.size(); i++) {
        cout << nombres[camino[i]] << " ";
    }

    cout << endl;
}

int main() {
    vector<vector<int> > matriz = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };

    int origen = 0;    // A
    int destino = 7;   // H
    int bloqueado = 4; // E

    vector<int> camino = caminoBFSMatriz(matriz, origen, destino, bloqueado);

    cout << "Camino:" << endl;
    imprimirCamino(camino);

    cout << "Distancia:" << endl;

    if (camino.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << camino.size() - 1 << endl;
    }

    return 0;
}