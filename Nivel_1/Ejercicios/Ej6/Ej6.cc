#include <iostream>
#include <string>
using namespace std;

class Pila
{
    private:
        int datos[10];
        int tope;
    public:
        Pila() : tope (-1){}

        bool estaVacia(){
            return tope == -1;
        }

        bool estaLlena(){
            return tope == 9;
        }

        void push(int valor) {
            if (!estaLlena()) {
                tope++;
                datos[tope] = valor;
            } 
            else {
                cout << "Error: la pila esta llena" << endl;
            }
        }

        int pop() {
            if (!estaVacia()) {
                int valor = datos[tope];
                tope--;
                return valor;
            }
            return -1; 
        }

        int peak(){
            return datos[tope];
        }

        void mostrar(){
            for (int i = 0; i < tope; i++)
            {
                cout << datos[i] << " ";
            }
            cout << endl;
        }
};


int main() {
    Pila p;

    // push
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    p.push(50);
    p.mostrar();

    // probar peek
    cout << "Tope: " << p.peak() << endl;

    // probar pop
    cout << "Saco: " << p.pop() << endl;
    cout << "Saco: " << p.pop() << endl;
    p.mostrar();

    // pila llena
    Pila p2;
    for (int i = 0; i < 12; i++) {
        p2.push(i);
    }

    // pila vacia
    Pila p3;
    cout << p3.pop() << endl;
    cout << p3.peak() << endl; // basura

    return 0;
}