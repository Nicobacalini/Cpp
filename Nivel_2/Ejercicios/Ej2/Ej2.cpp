#include <iostream>
#include <string>
using namespace std;

class Procesador
{
private:
    float frecuencia;

public:
    Procesador(float frec) : frecuencia(frec) {};

    void pocesarDatos()
    {
        cout << "Procesando datos a " << frecuencia << " Ghz..." << endl;
    }
};

class Ram
{
private:
    int capacidad;

public:
    Ram(int capacidad) : capacidad(capacidad) {}
    void cargarDatos()
    {
        cout << "Cargando datos en " << capacidad << " GB de ram..." << endl;
    }
};

class Computadora
{

private:
    string modelo;
    Procesador procesador;
    Ram ram;

public:
    Computadora(string modelo, float frecuencia, int capacidad) : modelo(modelo), procesador(frecuencia), ram(capacidad) {}

    void encender()
    {
        cout << "Encendiendo " << modelo << "..." << endl;
        procesador.pocesarDatos();
        ram.cargarDatos();
    }
};

int main()
{
    Computadora a("Asus", 4.5, 1000);

    a.encender();

    return 0;
}
