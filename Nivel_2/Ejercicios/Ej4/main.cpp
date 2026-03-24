#include "Estudiante.h"
#include <iostream>
using namespace std;

int main() {
    Estudiante e1("Juan", 8, "Matematica");
    Estudiante e2("Ana", 4, "Historia");
    Estudiante e3("Pedro", 15, "Fisica");  // debe quedar en 0

    e1.mostrarEstado();
    e2.mostrarEstado();
    e3.mostrarEstado();

    // probar setter
    e1.setNota(11);  // invalida, debe quedar en 0
    cout << "Nota de Juan after set: " << e1.getNota() << endl;

    e2.setNota(7);   // valida
    cout << "Nota de Ana after set: " << e2.getNota() << endl;

    return 0;
}
