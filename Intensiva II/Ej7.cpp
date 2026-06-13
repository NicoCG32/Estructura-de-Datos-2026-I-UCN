#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class EdgeNode {
public:
    int source;
    int destination;
    EdgeNode* next;

    EdgeNode(int source, int destination) {
        this->source = source;
        this->destination = destination;
        this->next = nullptr;
    }

    ~EdgeNode() {}
};

void agregarArco(EdgeNode*& head, int source, int destination) {
    EdgeNode* nuevo = new EdgeNode(source, destination);

    if (head == nullptr) {
        head = nuevo;
        return;
    }

    EdgeNode* actual = head;

    while (actual->next != nullptr) {
        actual = actual->next;
    }

    actual->next = nuevo;
}

vector<int> caminoListaArcos(EdgeNode* head, int n, int origen, int destino) {
    // Implementar aquí.
    vector<int> camino;
    return camino;
}

int main() {
    EdgeNode* head = nullptr;

    agregarArco(head, 0, 1);
    agregarArco(head, 0, 2);
    agregarArco(head, 1, 4);
    agregarArco(head, 2, 3);
    agregarArco(head, 3, 5);
    agregarArco(head, 4, 5);

    int n = 6;
    int origen = 0;
    int destino = 5;

    vector<int> camino = caminoListaArcos(head, n, origen, destino);

    if (camino.size() == 0) {
        cout << "Existe camino:" << endl;
        cout << "false" << endl;
    } else {
        cout << "Existe camino:" << endl;
        cout << "true" << endl;

        cout << "Camino:" << endl;

        for (int i = 0; i < camino.size(); i++) {
            cout << camino[i] << " ";
        }

        cout << endl;
    }

    return 0;
}