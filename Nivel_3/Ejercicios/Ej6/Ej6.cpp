#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Forma3d {
    public:
        Forma3d (){}
        virtual float calcularVolumen() = 0;
        virtual float calcularSuperficie() = 0;
        virtual ~Forma3d() {}

        void mostrarTodo() {
            cout << "Superficie: " << calcularSuperficie() << endl;
            cout << "Volumen: " << calcularVolumen() << endl;
            cout << "------------------------" << endl;
        }
};

class Esfera : public Forma3d {
    protected:
        float radio;
    public:
        Esfera (float radio): radio(radio){};

        float calcularVolumen() override {
            return (4.0 / 3.0) * M_PI * (radio * radio * radio);
        }

        float calcularSuperficie() override{
            return 4.0 * M_PI * (radio * radio);
        }
};  

class Cubo: public Forma3d{
    protected:
        float lado;
    public:
        Cubo (float lado):lado(lado){};

        float calcularVolumen() override{
            return lado * lado * lado;
        }

        float calcularSuperficie() override{
            return 6.0 * (lado * lado);
        }
};      

class Cilindro: public Forma3d{
    protected:
        float radio;
        float altura;
    public:
        Cilindro(float radio, float altura): radio(radio),altura(altura){}

        float calcularVolumen()override{
            return M_PI * (radio * radio) * altura;        
        }
        
        float calcularSuperficie() override{
            return (2.0 * M_PI * radio * altura) + (2.0 * M_PI * (radio * radio));
        }
};

class Cono: public Forma3d{
    protected:
        float radio; 
        float altura;
    public:
        Cono(float radio, float altura):radio(radio), altura(altura){}

        float calcularVolumen()override{
            return (1.0 / 3.0) * M_PI * (radio * radio) * altura;        
        }
        
        float calcularSuperficie() override{

            float generatriz = sqrt((radio * radio) + (altura * altura));
            return M_PI * radio * (radio + generatriz);
        }
};


int main(){

    Forma3d* figuras[4];

    figuras[0] = new Esfera(4.0);
    figuras[1] = new Cubo(4.0);
    figuras[2] = new Cilindro(4.0, 5.0);
    figuras[3] = new Cono(4.0, 5.0);


    cout << "--- Figuras Geometricas ---" << endl;

    for (int i = 0; i < 4; i++)
    {
        figuras[i]->mostrarTodo();
    }

    // Liberamos memoria
    for (int i = 0; i < 4; i++) {
        delete figuras[i];
    }

    return 1;
}