#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<string> colaBanco;

void agregarCliente(string nombre) {
    colaBanco.push(nombre);
}

void atenderSiguiente() {
    if (!colaBanco.empty()) {
        cout << "Atendiendo a: " << colaBanco.front() << "\n";
        colaBanco.pop();
    }
}

void verCola() {
    cout << "Clientes en espera: " << colaBanco.size() << "\n";
}