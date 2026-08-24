#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Boton {
private:
    string etiqueta;
    function<void()> accionClick;

public:
    Boton(string e) : etiqueta(e) {}

    void setAccion(function<void()> f) {
        accionClick = f;
    }

    void clickear() {
        cout << "Boton '" << etiqueta << "' presionado.\n";
        if (accionClick) {
            accionClick();
        }
    }
};

void resolverEjercicio2() {
    Boton b1("Guardar");
    Boton b2("Cerrar");
    Boton b3("Incrementar");

    b1.setAccion([]() { cout << "-> Guardando archivo...\n"; });
    b2.setAccion([]() { cout << "-> Cerrando aplicacion...\n"; });

    int contador = 0;
    b3.setAccion([&contador]() { 
        contador++; 
        cout << "-> Contador actual: " << contador << "\n"; 
    });

    b1.clickear();
    b2.clickear();
    b3.clickear();
    b3.clickear();
}