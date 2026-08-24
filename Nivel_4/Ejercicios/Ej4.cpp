#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <memory>
using namespace std;

/*
Ejercicio 3: El Guardián de Memoria (Smart Pointers)
• Creá clase Archivo con constructor que imprima "Abriendo..." y destructor "Cerrando...".
Tiene void escribir(string texto).
• En main, en un bloque {} creá un unique_ptr<Archivo>. Usá escribir() y comprobá que el
destructor se llama al salir del bloque.
• Creá una función que retorne un shared_ptr<Archivo>. En main, guardá ese shared_ptr
en dos variables y mostrá use_count(). Eliminá una y mostrá use_count() otra vez.
*/


class Archivo{
    public:
        Archivo(){
            cout<< "Abriendo..."<<endl;
        }
        ~Archivo(){
            cout<< "Cerrando..."<< endl;
        }

        void escribir(string texto){
            cout << texto<< endl;
        }

};


shared_ptr<Archivo> crearCompartido() {
    return make_shared<Archivo>();
}


int main(){
    cout << "--- PRUEBA UNIQUE_PTR ---" << endl;
    {
        unique_ptr<Archivo> miPuntero = make_unique<Archivo>();
        miPuntero->escribir("Mi primer archivo seguro");
    }

    cout << "\n--- PRUEBA SHARED_PTR ---" << endl;
    shared_ptr<Archivo> ptr1 = crearCompartido();
    cout << "Duenos al inicio: " << ptr1.use_count() << endl;

    {
        shared_ptr<Archivo> ptr2 = ptr1; 
        cout << "Duenos adentro del bloque: " << ptr1.use_count() << endl;
    } // ptr2 muere, NO dice "Cerrando..." porque ptr1 sigue vivo

    cout << "Duenos al salir del bloque: " << ptr1.use_count() << endl;

    return 0; 
}