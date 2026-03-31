#include <iostream>
#include <string>

using namespace std;





int main (){
    int resultado = 0;
    int numero;
    do
    {
        cout<< "Ingrese numero:";
        cin >> numero;
        resultado = resultado + numero;
        cout << "La suma es: " << resultado << ", 0 para salir"<< endl;
    } while ( numero != 0 ) ;
    cout << "La suma total es: " << resultado << endl;
    return 0;
}