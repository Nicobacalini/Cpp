#include <iostream>
#include <memory>
#include <stdexcept> // Para los errores
#include <string>
using namespace std;

/*
Ejercicio 7: Contenedor Genérico (Template + Smart Pointer)
• Creá una clase template Pila<T> usando unique_ptr internamente para gestionar la memoria.
• Métodos: push(T valor), pop() que retorne T con excepción si está vacía, peek(), estaVacia(), tamanio().
• Probá Pila<int>, Pila<string> y Pila<float> en el main.
• Verificá que el manejo de memoria es automático (sin delete manual).
*/

template <typename T>
class Pila {
private:
    // La cajita interna (esto va escondido en la parte privada)
    struct Nodo {
        T valor;
        unique_ptr<Nodo> siguiente;
        // Constructor del nodo
        Nodo(T v) : valor(v) {} 
    };

    unique_ptr<Nodo> tope; // El control remoto del plato de más arriba
    int cantidad = 0;      // Para llevar la cuenta fácil

public:
    void push(T valor) {
        unique_ptr<Nodo> nuevo = make_unique<Nodo>(valor);
        
        nuevo->siguiente = std::move(tope);
        
        tope = std::move(nuevo);
        
        cantidad++;
    }

    int tamanio() {
        return cantidad;
    }

    bool estaVacia() {
        return cantidad == 0;
    }

    T peek() {
        if (estaVacia()){
            throw runtime_error("La pila esta vacia");
        }
        else{
            return tope->valor;
        }
    }

    // Saca el plato de arriba y devuelve su valor
    T pop() {
        if (estaVacia()){
            throw runtime_error("La pila esta vacia");
        }
        T temp = tope->valor;
        tope = std::move(tope->siguiente);;
        cantidad--;
        return temp;
    }
};

int main() {

    cout << "--- PILA DE NUMEROS ---" << endl;
    Pila<int> pilaNumeros;
    
    cout << "Metemos 10, 20 y 30..." << endl;
    pilaNumeros.push(10);
    pilaNumeros.push(20);
    pilaNumeros.push(30);
    
    cout << "Tamanio actual: " << pilaNumeros.tamanio() << " platos." << endl;
    cout << "Miramos el tope sin sacarlo (peek): " << pilaNumeros.peek() << endl;
    
    cout << "\nVaciar la pila:" << endl;
    cout << "Saco el: " << pilaNumeros.pop() << endl;
    cout << "Saco el: " << pilaNumeros.pop() << endl;
    cout << "Saco el: " << pilaNumeros.pop() << endl;
    
    try {
        cout << "\nIntentando sacar un plato fantasma..." << endl;
        pilaNumeros.pop(); 
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n--- PILA DE STRINGS ---" << endl;
    Pila<string> pilaTextos;
    
    pilaTextos.push("Ejercicio");
    pilaTextos.push("en C++");
    pilaTextos.push("terminado");
    
    cout << pilaTextos.pop() << " ";
    cout << pilaTextos.pop() << " ";
    cout << pilaTextos.pop() << endl;

    return 0;
}