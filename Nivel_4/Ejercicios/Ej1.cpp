#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main(){
    vector<string> inventario;

    inventario.push_back("Bermuda");
    inventario.push_back("Remera");
    inventario.push_back("Pantalon");
    inventario.push_back("Boxer");
    inventario.push_back("Musculosa");


    int i =0;

    // Imprimir el inventario con auto
    for (auto prenda: inventario)
    {
        cout<< i<<" "<< prenda<< ", ";
        i++;
    }
    
    // Modificar con referencia: auto&
    for (auto& prenda: inventario){
        for (char& c : prenda) {
        c = toupper(c);
        }
    }
    cout<< endl;

    // Imprimir el inventario con auto
    for (auto prenda: inventario)
    {
        cout<< prenda<< " ";
    }

    cout<< endl;
    // imprimir tamanio
    cout<<"Tiene un tamanio de: " <<inventario.size()<< endl;

    // imprimir ultimo
    cout<< "Ultimo elemento: "<< inventario.back()<< endl;
    return 0;
}