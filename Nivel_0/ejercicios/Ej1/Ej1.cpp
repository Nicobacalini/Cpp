#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombreCompleto;
    int anio_nacimiento; // Cambié el nombre para que sea más claro
    int edad;
    int anio_actual = 2026;
    string lenguaje_fav;


    cout << "Ingrese su nombre: ";
    getline (cin, nombreCompleto); // Leer el nombre completo con espacios

    cout << "Ingrese anio de nacimiento: ";
    cin>> anio_nacimiento;


    cin.ignore();


    cout << "Ingrese su lenguaje Fav: ";
    cin >> lenguaje_fav;

    edad = anio_actual - anio_nacimiento;

    // Imprima: "Hola [Nombre], tenés [Edad] años y tu lenguaje favorito es [Lenguaje]"

    cout << "Hola " << nombreCompleto << " , tenes " << edad << " años y tu lenguaje favorito es " << lenguaje_fav<< endl;
    return 0;
}