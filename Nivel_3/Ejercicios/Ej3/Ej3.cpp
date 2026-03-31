#include <iostream>
#include <string>
using namespace std;


class Empleado{
    protected:
        string nombre;
        int sueldoBase; // va a estar en sentavos
        
    public:
        Empleado(string nombre, int sueldoBase): nombre(nombre), sueldoBase(sueldoBase){}
        virtual int calcularSueldo() {
            return sueldoBase;
        }

        virtual string imprimirCargo() = 0;
        virtual ~Empleado() {}
};


class Gerente: public Empleado{
    protected: 
        int bono;
    
    public:

        Gerente(string nombre, int sueldoBase, int bono): Empleado(nombre, sueldoBase), bono(bono){}

        string imprimirCargo() override {
            return "Gerente";
        }

        int calcularSueldo() override {
            return sueldoBase + bono;
        }

};

class Vendedor: public Empleado{
    protected:
        int comision;
    
    public:
        Vendedor(string nombre, int sueldoBase, int comision): Empleado(nombre, sueldoBase), comision(comision){}

        string imprimirCargo() override {
            return "Vendedor";
        }

        int calcularSueldo() override {
            return sueldoBase + comision;
        }

};

class Consultor: public Empleado{
    protected:
        int horasTrabajadas;
        int tarifaPorHora;
    public:
        Consultor(string nombre, int horas, int tarifa) : Empleado(nombre, 0), horasTrabajadas(horas), tarifaPorHora(tarifa) {}

        string imprimirCargo() override {
            return "Consultor";
        }
        
        int calcularSueldo() override {
            return horasTrabajadas * tarifaPorHora;
        }
};


int main (){

    Empleado* empresa[3];

    // Creamos generente
    empresa[0] = new Gerente("Ana", 100000, 50000);

    // Creamos Vendedor
    empresa[1] = new Vendedor("Juan", 80000, 20000);
    
    // Creamos Consultor
    empresa[2]= new Consultor ("Pedro", 40, 2500);


    cout<< "-- Liquidacion de sueldos --"<< endl;

    for (int i = 0; i<3; i++){
        cout<< "Empleado "<< i + 1 << " con cargo: " << empresa[i]->imprimirCargo()  << " cobra $"<< empresa[i]->calcularSueldo()<< endl;
    }

    for (int i = 0; i<3; i++ ){
        delete empresa[i];
    }

    return 0;
}