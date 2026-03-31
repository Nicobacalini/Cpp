#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Figura{
    protected:
        string nombre;
        
    public:
        Figura(string nombre): nombre(nombre){}
        
        virtual float calcularArea() = 0;
        
        virtual float calcularPerimetro() = 0;
        
        virtual string mostrarNombre() = 0;

        void mostrarTodo() {
            cout << "Figura: " << mostrarNombre() << endl;
            cout << "Area: " << calcularArea() << endl;
            cout << "Perimetro: " << calcularPerimetro() << endl;
            cout << "------------------------" << endl;
        }

        virtual ~Figura() {}


};

class Circulo: public Figura{
    protected:
        float radio;

    public:
        Circulo (float rad): Figura("Circulo"), radio(rad){}

        string mostrarNombre() override {
            return nombre;
        }

        float calcularArea() override {
             return  3.14 * (radio * radio);
        }

        float calcularPerimetro() override {
            return  2 * radio * 3.14;
        }
};

class Rectangulo: public Figura{
    protected:
        float base;
        float altura;
    public:
        Rectangulo (float base, float altura): Figura("Rectangulo"), base(base), altura(altura){}

        string mostrarNombre() override {
            return nombre;
        }

        float calcularArea() override {
             return base* altura;
        }

        float calcularPerimetro() override {
            return  (base * 2 ) + (altura * 2);
        }
};

class Triangulo: public Figura{
    protected:
        float lado1;
        float lado2;
        float lado3;

    public:
        Triangulo (float lado1, float lado2, float lado3): Figura("Triangulo"), lado1(lado1), lado2(lado2),lado3(lado3){}

        string mostrarNombre() override {
            return nombre;
        }

        float calcularArea() override {
            float s = (lado1 + lado2 + lado3) / 2; 
            return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
        }

        float calcularPerimetro() override {
            return  lado1 + lado2 + lado3;
        }
};

class Trapecio: public Figura {
    protected:
        float base_mayor;
        float base_menor;
        float altura;

    public:
        Trapecio(float b_Mayor, float b_menor, float alt): Figura("Trapecio"), base_mayor(b_Mayor), base_menor(b_menor), altura(alt) {}

        string mostrarNombre() override {
            return nombre;
        }

        float calcularArea() override {
            return ((base_mayor + base_menor) / 2.0) * altura;
        }

        float calcularPerimetro() override {
            return 0;
        }
};


int main() {
    Figura* formas[4];

    // Instanciamos las figuras
    formas[0] = new Circulo(5.0);
    formas[1] = new Rectangulo(4.0, 6.0);
    formas[2] = new Triangulo(3.0, 4.0, 5.0);
    formas[3] = new Trapecio(10.0, 6.0, 4.0);

    cout << "--- Figuras Geometricas ---" << endl;

    for (int i = 0; i < 4; i++) {
        formas[i]->mostrarTodo();
    }

    // Liberamos memoria
    for (int i = 0; i < 4; i++) {
        delete formas[i];
    }

    return 0;
}