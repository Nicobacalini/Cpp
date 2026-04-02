#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Volador {
protected:
    float velocidadVuelo;
public:
    Volador(float v) : velocidadVuelo(v) {}
    virtual void volar() = 0;
    virtual ~Volador() {}
};


class Nadador {
protected:
    float velocidadNado;
public:
    Nadador(float v) : velocidadNado(v) {}
    virtual void nadar() = 0;
    virtual ~Nadador() {}
};

class Corredor {
protected:
    float velocidadCarrera;
public:
    Corredor(float v) : velocidadCarrera(v) {}
    virtual void correr() = 0;
    virtual ~Corredor() {}
};


class Pato : public Volador, public Nadador, public Corredor{
    public:
        Pato(float vVuelo, float vNado, float vCarrera): Volador(vVuelo), Nadador(vNado), Corredor(vCarrera){};
        void volar() override {
        cout << "Pato volando medio torpe a " << velocidadVuelo << " km/h." << endl;
        }
        void nadar() override {
            cout << "Pato nadando tranquilo a " << velocidadNado << " km/h." << endl;
        }
        void correr() override {
            cout << "Pato corriendo graciosamente a " << velocidadCarrera << " km/h." << endl;
        }
};

class Pinguino : public Nadador, public Corredor{
    public:
        Pinguino(float vNado, float vCarrera):  Nadador(vNado), Corredor(vCarrera){};
        void nadar() override {
            cout << "Pinguino nadando tranquilo a " << velocidadNado << " km/h." << endl;
        }
        void correr() override {
            cout << "Pinguino corriendo graciosamente a " << velocidadCarrera << " km/h." << endl;
        }
};


class Aguila : public Volador, public Corredor{
    public:
        Aguila(float vVuelo, float vCarrera): Volador(vVuelo), Corredor(vCarrera){};
        void volar() override {
        cout << "Aguila volando medio torpe a " << velocidadVuelo << " km/h." << endl;
        }
        void correr() override {
            cout << "Aguila corriendo graciosamente a " << velocidadCarrera << " km/h." << endl;
        }
};


int main(){

    // Creamos animales
    Pato donald(15.5, 5.0, 3.2);
    Pinguino skipper(35.0, 4.0);
    Aguila fawkes(120.0, 2.5);

    cout << "\n--- Demostrando Polimorfismo ---" << endl;
    
    //Voladores

    Volador* aveVoladora1 = &donald;
    Volador* aveVoladora2 = &fawkes;
    
    cout << "> Probando Voladores:" << endl;
    aveVoladora1->volar();
    aveVoladora2->volar();

    // Nadadores
    Nadador* aveNadadora1 = &donald;
    Nadador* aveNadadora2 = &skipper;

    cout << "\n> Probando Nadadores:" << endl;
    aveNadadora1->nadar();
    aveNadadora2->nadar();

    // Corredores
    Corredor* aveCorredora1 = &donald;
    Corredor* aveCorredora2 = &skipper;
    Corredor* aveCorredora3 = &fawkes;

    cout << "\n> Probando Corredores:" << endl;
    aveCorredora1->correr();
    aveCorredora2->correr();
    aveCorredora3->correr();

    return 0;
}