#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

/*
Ejercicio 2: El Comparador Mágico (Templates)
6. Creá una función template obtenerMayor(T a, T b) que retorne el mayor.
7. Creá una función template obtenerMenor(T a, T b).
8. Creá una clase template Tripla<T> con tres valores del mismo tipo, métodos suma() y mayor().
9. Probá todo con int, double y string.
*/

template <typename T>
T obtenerMayor(T a, T b){
    return (a > b) ? a : b;
}


template <typename T>
T obtenerMenor(T a, T b){
    return (a < b) ? a : b;
}

template <typename T>
class Tripla {
    private:
        T a;
        T b;
        T c;
    public:
        Tripla(T a, T b, T c) : a(a), b(b), c(c) {}
        T suma(){
            return a + b + c;
        }
        T mayor(){
            T ganador = obtenerMayor(a, b);
            return obtenerMayor(ganador, c);
        }
};

int main(){
    Tripla<int> miTriplaInt(10, 5, 20);
    cout<< miTriplaInt.suma()<<endl;

    Tripla<double> miTriplaDouble(3.14, 2.71, 9.81);
    cout<< miTriplaDouble.suma()<<endl;

    Tripla<string> miTriplaString("Zebra", "Avion", "Perro");
    cout<< miTriplaString.suma()<<endl;
    return 1;
}