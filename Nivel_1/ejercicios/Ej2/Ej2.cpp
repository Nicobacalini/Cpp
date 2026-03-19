#include <iostream>
#include <string>
using namespace std;


class Estudiante{
    private:
        string nombre;
        int notaFinal;
        string materia;

    public:
        Estudiante(string nombre, int notaFinal, string materia) : nombre(nombre), notaFinal(notaFinal), materia(materia) {
            if (notaFinal < 0 || notaFinal > 10) {
                this->notaFinal = 0;
            }
        }

        void  mostrarEstado(){
            cout << "Nombre: " << nombre << "\nNota: "<< notaFinal << endl;
            if (notaFinal >= 6){cout<< "\nAprobo";}else{cout<< "\nDesaprobo";}

        }

        void setNota(int nuevaNota) {
            if (nuevaNota < 0 || nuevaNota > 10)
                notaFinal = 0;
            else
                notaFinal = nuevaNota;
        }

        int getNota() {
            return notaFinal;
        }
};



int main() {
    Estudiante e1("Juan", 8, "Matematica");
    Estudiante e2("Ana", 4, "Historia");
    Estudiante e3("Pedro", 15, "Fisica");

    e1.mostrarEstado();
    e2.mostrarEstado();
    e3.mostrarEstado();

    return 0;
}