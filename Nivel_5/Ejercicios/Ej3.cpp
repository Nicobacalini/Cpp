#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

using namespace std;

stack<string> historial;

void realizarAccion(string accion) {
    historial.push(accion);
}

string deshacer() {
    if (historial.empty()) {
        throw runtime_error("Historial vacio");
    }
    string ultima = historial.top();
    historial.pop();
    return ultima;
}

void verHistorial() {
    stack<string> temp = historial;
    cout << "Historial de acciones:\n";
    while (!temp.empty()) {
        cout << "- " << temp.top() << "\n";
        temp.pop();
    }
}