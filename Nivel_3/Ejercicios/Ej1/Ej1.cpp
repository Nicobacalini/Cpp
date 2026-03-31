#include <iostream>
#include <string>
using namespace std;

class Vehiculo
{
protected:
    string marca;
    float velocidadMaxima;
public:
    Vehiculo(string n , float v): marca(n), velocidadMaxima(v){}
    void mostrarInfo(){
        cout<< "Marca: "<< marca<< " Velocidad Maxima"<< velocidadMaxima<< endl;
    }
};


class Moto : public Vehiculo {
public:
    bool tieneCasco;

    Moto(string n, float v, bool casco) : Vehiculo(n, v), tieneCasco(casco) {}

    void hacerWilly(){
        cout << "Esta haciendo willy" << endl;
    }
};

class Camion : public Vehiculo{
    public:
        float toneladas;

        Camion(string n , float v, float toneladas): Vehiculo(n,v), toneladas(toneladas){}

        void cargar(){
            cout<< "El camion se esta cargando";
        }

};

int main()
{
    Moto moto("Motomel", 100.5, true);
    Camion camion("Mercedes", 80, 4000);

    cout << "--- Info de la Moto ---" << endl;
    moto.mostrarInfo();
    
    cout << "\n--- Info del Camion ---" << endl;
    camion.mostrarInfo();

    cout << "\n--- Acciones ---" << endl;
    moto.hacerWilly();
    camion.cargar();

    return 0;
}