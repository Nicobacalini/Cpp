#include <iostream>
#include <string>
using namespace std;

class Alien
{
    private:

    public:
        Alien() { cout << "Grito alienigena!" << endl; }
        ~Alien() { cout << "Alien explotando en pedazos!" << endl; }
        void atacar() { cout << "El alien ataca!" << endl; }
};




int main(){

    Alien* escuadron[5];

    for (int i = 0; i < 5; i++) {
        escuadron[i] = new Alien();
    }

    for (int i = 0; i < 5; i++) {
        escuadron[i]->atacar();
    }

    for (int i = 0; i < 5; i++) {
        delete escuadron[i];
    }


}


