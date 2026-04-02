#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

class MiExcepcion : public exception{
    private:
        string mensaje;

    public:
        MiExcepcion(string mensaje): mensaje(mensaje){}

        // sobreescribimos el metodo what() de la clase madre
        const char* what() const noexcept override{
            return mensaje.c_str();
        }
};

float dividir (float a, float b){
    if (b == 0){
        throw invalid_argument("Error: No podes dividir por cero mostro.");
    }
    return a / b;
}

int obtenerElemento(vector<int>& v, int i) {
    if (i < 0 || i >= v.size()) {
        throw out_of_range("Error: Te caiste del mapa, ese indice no existe en el vector.");
    }
    return v[i];
}

float raizCuadrada(float n) {
    if (n < 0) {
        throw MiExcepcion("Error: Los numeros imaginarios te los debo. Ingresa un positivo.");
    }
    return sqrt(n);
}


int main() {

    cout << "--- Prueba de Division ---" << endl;
    try {
        cout << "Resultado: " << dividir(10, 2) << endl; // Esta funciona bien
        cout << "Resultado: " << dividir(5, 0) << endl;  // Esta tira la bengala
    } catch (const invalid_argument& e) {
        // Atrapamos la bengala e imprimimos el mensaje
        cout << "BENGALA ATRAPADA: " << e.what() << endl;
    }

    cout << "\n--- Prueba de Vector ---" << endl;
    vector<int> misNumeros = {10, 20, 30};
    try {
        cout << "Numero: " << obtenerElemento(misNumeros, 1) << endl; // Funciona
        cout << "Numero: " << obtenerElemento(misNumeros, 99) << endl; // Tira la bengala
    } catch (const out_of_range& e) {
        cout << "BENGALA ATRAPADA: " << e.what() << endl;
    }

    cout << "\n--- Prueba de Raiz Cuadrada ---" << endl;
    try {
        cout << "Raiz: " << raizCuadrada(16) << endl;  // Funciona
        cout << "Raiz: " << raizCuadrada(-4) << endl;  // Tira la bengala de MiExcepcion
    } catch (const MiExcepcion& e) {
        cout << "BENGALA ATRAPADA: " << e.what() << endl;
    }


    return 0;
}