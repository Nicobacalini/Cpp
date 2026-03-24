#include <iostream>
#include <string>
using namespace std;




int main(){
    int arreglo[] = {10, 20, 30, 40, 50,60, 70, 80, 90, 100};

    // puntero inicio
    int* ptr = arreglo;

    // puntero al final
    int* fin = arreglo + 10;

    int resultado = 0;
    int max = *ptr;


    cout << "Arreglo original: ";
    for (int* p = arreglo; p < fin; p++)
    {
        if (max < *p){
            max = *p;
        }
        resultado += *p;
        cout << *p << " ";
    }
    

    cout << "Suma: " << resultado << endl;
    cout << "Maximo: " << max << endl;

    int* izq = arreglo;
    int* der = arreglo + 9;

    while (izq < der){

        // intercambiar
        int temp = *izq;

        *izq = *der;

        *der = temp;
        izq ++;
        der --;
    }


    cout << "Arreglo invertido: ";
    for (int* p = arreglo; p < fin; p++)
        cout << *p << " ";
    cout << endl;
    return 0;
}