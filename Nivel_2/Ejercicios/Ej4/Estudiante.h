#pragma once

#include <string>

class Estudiante{
    private:
        std::string nombre;
        int notaFinal;
        std::string materia;

    public:
        Estudiante(std::string nombre, int notaFinal, std::string materia);
        void  mostrarEstado();
        void setNota(int nuevaNota) ;
        int getNota() ;
};

