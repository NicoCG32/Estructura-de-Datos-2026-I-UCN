#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool puedeVisitarTodas(vector<vector<int> > rooms) {
    // Implementar aquí.
    return false;
}

int main() {
    vector<vector<int> > rooms = {
        {1, 2},
        {3},
        {4},
        {5},
        {},
        {}
    };

    bool respuesta = puedeVisitarTodas(rooms);

    if (respuesta) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}