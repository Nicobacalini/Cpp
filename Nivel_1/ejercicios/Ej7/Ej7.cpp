#include <iostream>
#include <string>
using namespace std;


class Matriz2x2
{
private:
    int tam = 2;
    float matriz[2][2];
public:
    Matriz2x2 (float a, float b, float c, float d){
        matriz[0][0] = a;
        matriz[0][1] = b;
        matriz[1][0] = c;
        matriz[1][1] = d;
    }

    Matriz2x2() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            matriz[i][j] = 0;
    }
    Matriz2x2(const Matriz2x2& otra) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            matriz[i][j] = otra.matriz[i][j];
    }


    Matriz2x2 operator+ (const Matriz2x2& otra)const{
        Matriz2x2 resultado;

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam; j++){
                resultado.matriz[i][j] = matriz[i][j] + otra.matriz[i][j];
            }
        }
        return resultado;
    }


    Matriz2x2 operator* (const Matriz2x2& otra) const{

        Matriz2x2 resultado;

        for (int i = 0; i < tam; i++){
            for (int j = 0; j < tam ; j++){
                for (int k = 0; k < tam; k++)
                {
                    resultado.matriz[i][j] += matriz[i][k] * otra.matriz[k][j];
                }
            }
        }
        return resultado;
    }
    

    void mostrar(){
        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                cout<< matriz [i] [j]; 
                cout<< " ";
            }
            cout<<endl;
        }
        
    }
};

int main() {
    Matriz2x2 a(1, 2, 3, 4);
    Matriz2x2 b(5, 6, 7, 8);

    cout << "Matriz A:" << endl;
    a.mostrar();

    cout << "Matriz B:" << endl;
    b.mostrar();

    cout << "Suma:" << endl;
    Matriz2x2 suma = a + b;
    suma.mostrar();

    cout << "Multiplicacion:" << endl;
    Matriz2x2 mult = a * b;
    mult.mostrar();

    cout << "Copia de A:" << endl;
    Matriz2x2 copia = a;
    copia.mostrar();

    return 0;
}