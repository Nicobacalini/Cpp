#include <iostream>
#include <string>
using namespace std;


class ListaEnteros{
    private:
        int* datos;
        int capacidad;
        int cantidad;
        
    public:
        ListaEnteros(int tam){
            capacidad = tam;
            cantidad = 0;
            datos = new int[capacidad];
        }

        ~ListaEnteros(){
            delete[] datos;
            cout << "Memoria liberada" << endl;
        }

        ListaEnteros(const ListaEnteros& otro) {
            capacidad = otro.capacidad;
            cantidad = otro.cantidad;
            datos = new int[capacidad];
    
            // copiamos
            for (int i = 0; i < cantidad; i++) {
                datos[i] = otro.datos[i];
            }
        }

        ListaEnteros& operator=(const ListaEnteros& otro) {
            if (this == &otro) return *this;
            delete[] datos;

            // Copiar los tamaños
            capacidad = otro.capacidad;
            cantidad = otro.cantidad;

            // Pedir nueva memoria y copiar valores
            datos = new int[capacidad];
            for (int i = 0; i < cantidad; i++) {
                datos[i] = otro.datos[i];
            }

            return *this;
        }

        void agregar(int valor){
            if ( this-> capacidad > this->cantidad){
                datos[cantidad] = valor;
                cantidad ++; 
            }
            else {
                cout << "Memoria llena" << endl;
            }
        }

        void mostrar(){
            for (int i = 0; i < cantidad; i++)
            {
                cout<< datos[i]<< endl;
            }            
        }

        int obtener(int indice) {
            if (indice >= 0 && indice < cantidad) { 
                return datos[indice];
            }
            cout << "Índice fuera de rango" << endl;
            return -1; 
        }

    };


int main() {
    ListaEnteros original(5);
    original.agregar(10);
    original.agregar(20);

    ListaEnteros copia = original;
    copia.agregar(30);

    cout << "Original: "; original.mostrar();
    cout << "Copia: "; copia.mostrar();

    ListaEnteros asignada(5);
    asignada = original;
    asignada.agregar(40);

    cout << "Asignada: "; asignada.mostrar();


    int n = original.obtener(0);
    cout << "Elemento en 0: " << n << endl;


    return 0;
}