#include <iostream>
#include <string>


using namespace std;

int main(){

    float saldo = 10000.50;
    float cantidad;
    cout <<"Ingrese la cantidad que quiere retirar: ";
    cin>> cantidad;

    if (saldo < cantidad){
        cout<< "Saldo insuficiente";

    }else if (cantidad <= 0){
        cout << "Monto inválido";
    }
    
    else{
        saldo = saldo - cantidad;
        cout << "Retiro: " << cantidad << " le quedan " << saldo<< endl ; 
    }
    return 0;
}