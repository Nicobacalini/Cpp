#include <iostream>
#include <string>
using namespace std;

class Termostato
{
private:
    int temp;
public:
    Termostato(){
        temp = 20;}

    void subirTemperatura(){
        if (temp <30){
            temp = temp + 1;
        }
        else{
            cout << "temperatura maxima alcanzada" << endl;
        }

    }

    void bajarTemperatura(){
        if (temp > 10){
            temp = temp - 1;
            
        }
        else{
            cout << "temperatura minima alcanzada"<< endl;;
        }
    }

    void VerTemp(){
        cout<< "La temperatura actual es: "<< temp <<endl;
    }
};


int main (){

    Termostato T;

    for (int i = 0; i < 15; i++)
    {
        T.subirTemperatura();
    }

    T.VerTemp();
    for (int i = 0; i <  25; i++)
    {
        T.bajarTemperatura();
    }

    T.VerTemp();

    return 0;
}






