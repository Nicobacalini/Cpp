#include "Estudiante.h"
#include <iostream>
using namespace std;


Estudiante::Estudiante(string nombre, int notaFinal, string materia) 
    : nombre(nombre), notaFinal(notaFinal), materia(materia) {
    if (notaFinal < 0 || notaFinal > 10)
        this->notaFinal = 0;
}


void Estudiante::mostrarEstado(){
    cout << "Nombre: " << nombre << "\nNota: " << notaFinal << endl;
    if (notaFinal >= 6){
        cout<< "\nAprobo";
    }
    else{
        cout<< "\nDesaprobo";
    }
}



void Estudiante::setNota(int nuevaNota) {
    if (nuevaNota < 0 || nuevaNota > 10)
        notaFinal = 0;
    else
        notaFinal = nuevaNota;
}

int Estudiante::getNota(){
    return notaFinal;
        }