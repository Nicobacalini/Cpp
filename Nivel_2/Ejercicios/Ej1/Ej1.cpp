#include <iostream>
#include <string>
using namespace std;


class Libro
{
private:
    string titulo;
    string autor;
    int paginas;
public:
    Libro (string ti, string au, int pag){
        this->autor = au;
        this->paginas = pag;
        this->titulo = ti;
    } 

    void mostrarInfo(){
        cout << "Autor: "<< this->autor<< " Titulo: "<< this->titulo<< " Paginas: "<< this->paginas<< endl;
    }
};



int main() {
    
    Libro a("C++", "Nicolas", 5);
    a.mostrarInfo();

    return 0;
}