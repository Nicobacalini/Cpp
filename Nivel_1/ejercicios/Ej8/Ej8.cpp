#include <iostream>
#include <string>
using namespace std;



class Producto
{
private:
    string nombre;
    float precio;
    int stock;

public:
    Producto (string nombre, float precio, int stock): nombre(nombre), precio(precio), stock(stock){
        if (precio <= 0) this->precio = 0;
        if (stock < 0) this->stock = 0;
    }

    bool vender(int cantidad){
        if (stock < cantidad){
            return false;
        }
        else{
            stock -= cantidad;
            return true;
        }
    }

    void aplicarDescuento(float porcentaje) {
        if (porcentaje >= 0 && porcentaje <= 100) {
            precio = precio - ((precio * porcentaje) / 100);
        } 
        else {
            cout << "Porcentaje invalido" << endl;
        }
    }

    bool operator<(const Producto& otro)const{

        return (precio < otro.precio);
    } 
    void mostrarInfo(){
        cout << "Nombre: "<< nombre<< endl;
        cout << "Precio: "<< precio<< endl;
        cout << "Stock: " << stock<< endl;
    }
};


int main() {
    Producto p1("Zapatillas", 50000, 10);
    Producto p2("Remera", 15000, 5);
    Producto p3("Gorra", 8000, 20);

    // mostrar info
    p1.mostrarInfo();
    p2.mostrarInfo();
    p3.mostrarInfo();

    // vender
    if (p1.vender(3))
        cout << "Venta exitosa" << endl;
    else
        cout << "Stock insuficiente" << endl;

    // vender
    if (p2.vender(99))
        cout << "Venta exitosa" << endl;
    else
        cout << "Stock insuficiente" << endl;

    // descuento
    p3.aplicarDescuento(25);
    cout << "Gorra con descuento:" << endl;
    p3.mostrarInfo();

    // descuento invalido
    p1.aplicarDescuento(150);

    // comparar precios con operator
    if (p2 < p1)
        cout << "Remera es mas barata que Zapatillas" << endl;

    // validacion constructor
    Producto invalido("Raro", -100, -5);
    invalido.mostrarInfo();  // precio y stock deben ser 0

    return 0;
}