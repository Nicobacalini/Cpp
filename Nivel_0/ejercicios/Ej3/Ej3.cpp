#include <iostream>
#include <string>

using namespace std;

int main (){
    int opcion;
    int numero;


    cout << "1. Cuadrado\n2. Cubo\n3. Par/Impar\n4. Salir\nElija: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1: {
        
        cout << "Ingrese un numero: ";
        cin >> numero;
        int resultado = numero * numero;
        cout << "El cuadrado del numero es: " << resultado<< endl;
        break;
        }
    case 2: 
    {
        cout << "Ingrese Numero: ";
        cin >> numero;
        int  resultado = numero * numero * numero;
        cout << "El cubo del numero es: " << resultado<< endl;
        break;
        }
    case 3:
    {
        cout << "Ingrese Numero: ";
        cin >> numero;
        string resultado = (numero % 2 == 0) ? "Es par" : "Es impar";
        cout << resultado << endl;
        break;
        }
    case 4:
    {
        return 0;
        }
        
    default:{
        cout << "Opcion invalida" << endl;
    }
    return 0;
}
}