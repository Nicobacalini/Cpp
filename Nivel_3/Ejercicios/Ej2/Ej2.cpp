#include <iostream>
#include <string>
using namespace std;

class Animal{
    public:
        virtual void comer() = 0; 
        virtual void emitirSonido() = 0;
        virtual ~Animal() {}
};

class Leon : public Animal{
    public:
        void comer() override {
            cout<< "Comiendo carne"<< endl;
        }
        void emitirSonido() override{
            cout<< "HRRRAAAAA"<< endl;
        }
};

class Mono : public Animal{

    public:
        void comer() override{
            cout<< "Comiendo banana"<< endl;
        }
    void emitirSonido() override{
            cout<< "UH UH UH"<< endl;
        }
};

class Pinguino : public Animal{
    public:
        void comer() override{
            cout << "Comiendo peces"<< endl;
        }
        void emitirSonido() override{
            cout<< "Hraaa-hraaa"<< endl;
        }
};

class Serpiente: public Animal {
    public:
        void comer() override{
            cout<< "Comiendo huevos"<< endl;
        }
        void emitirSonido() override{
            cout<< "shhhh"<< endl;
        }
};

int main(){
    Animal* zoologico[4];

    zoologico[0] = new Leon();
    zoologico[1] = new Mono();
    zoologico[2] = new Pinguino();
    zoologico[3] = new Serpiente();

    cout<< "--- Recorriendo zoologico ---"<<endl;
    for (int i = 0; i < 4; i++)
    {
        zoologico[i]->comer();
        zoologico[i]->emitirSonido();
        cout << "------------------" << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete zoologico[i];
    }
    return 0;
}