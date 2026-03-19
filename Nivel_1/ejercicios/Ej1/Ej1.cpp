#include <iostream>
#include <string>
using namespace std;


class Rectangulo{
    private:
        float base;
        float altura;

    public:

    Rectangulo(float base, float altura) : base(base), altura(altura){}

    float calcularArea(){
        return altura * base;
    }

    float calcularPerimetro(){
        return (2 * base) + (2 * altura);
    }   

    bool esCuadrado(){
        return altura == base;
    }

    float verBase(){
        return base;
    }

    float verAltura(){
        return altura;
    }
};

int main(){

    Rectangulo r(5,3);
    cout << r.calcularArea() << endl;
    cout << r.esCuadrado() << endl;
    return 0;
}