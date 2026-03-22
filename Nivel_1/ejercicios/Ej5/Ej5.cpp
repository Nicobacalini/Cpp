#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Punto2D
{
private:
    float x, y;
    
public:
    // construccion inicial
    Punto2D(float x, float y): x(x), y(y){};

    // sobrecarga de suma
    Punto2D operator+ (const Punto2D& punto) const{
        return Punto2D(x + punto.x, y + punto.y);
    }

    // sobrecarga de resta
    Punto2D operator- (const Punto2D& punto) const{
        return Punto2D(x - punto.x, y - punto.y);
    }

    // comparacion
    bool operator== (const Punto2D& punto)const{
        return (x == punto.x && y == punto.y);
    }

    // calculo de distacia Euclidiana
    float distanciaA(const Punto2D& otro) const { 
        float dx = x - otro.x;
        float dy = y - otro.y;
        return sqrt(dx * dx + dy * dy);
    }

    void mostrar() {
    cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() {
    Punto2D a(4, 4);
    Punto2D b(5, 5);

    Punto2D suma = a + b;
    Punto2D resta = b - a;

    cout << "Suma: ";      
    suma.mostrar();
    cout << "Resta: ";     
    resta.mostrar();

    // comparacion (==)
    if (a == b) {
        cout << "Los puntos son iguales." << endl;
    } else {
        cout << "Los puntos son distintos." << endl;
    }

    // distancia euclidiana
    float dist = a.distanciaA(b);
    cout << "La distancia entre a y b es: " << dist << endl;

    if (a == a) {
        cout << "'a' es igual a 'a'." << endl;
    }

    return 0;
}
