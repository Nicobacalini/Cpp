#include <iostream>
#include <string>
using namespace std;

/*
Ejercicio 5: El Destructor Virtual en Acción
Demostrá el problema del destructor no virtual:
1. Creá clase Base con destructor NO virtual y clase Hija con destructor propio. Hacé
delete a través de un puntero Base* y comprobá que el destructor de Hija no se llama.
2. Repetí el experimento con destructor virtual en Base. Comprobá que ahora sí se llaman
ambos destructores.
3. Explicá en un comentario en el código por qué esto importa cuando hay recursos
(memoria, archivos) que liberar.
*/

class Base{
    public:
        ~Base() { cout << "Destructor Base" << endl; } // SIN virtual: PELIGROSO
};

class Hija : public Base{
    public:
        ~Hija() { cout << "Destructor Hija" << endl; }
};

class BaseSegura{
    public:
        virtual ~BaseSegura() { cout << "Destructor BaseSegura" << endl; }
};

class HijaSegura : public BaseSegura{
    public:
        ~HijaSegura() override { cout << "Destructor HijaSegura" << endl; }
};

int main(){

    Base *obj1 = new Hija();
    delete obj1; // SOLO llama a ~Base(). ~Hija() NUNCA se llama

    
    BaseSegura *obj2 = new HijaSegura();
    delete obj2; // Llama ~HijaSegura() Y ~BaseSegura(). Correcto
}



/*
3. EXPLICACION DEL PELIGRO:
Si la clase 'Hija' hubiera reservado memoria dinamica (con 'new' para un arreglo, por ejemplo) 
o hubiera abierto un archivo, la unica forma de liberar esa memoria o cerrar el archivo 
es adentro de su propio destructor ~Hija(). 

Al usar un puntero de la clase Base sin destructor virtual, C++ solo destruye la parte "Base" 
del objeto y nunca llama al destructor de la Hija. Esto genera una "fuga de memoria" (memory leak): 
los recursos de la Hija quedan bloqueados e inutilizables hasta que se cierre el programa.
Por eso, la regla de oro en C++ es: si una clase tiene metodos virtuales, su destructor 
SIEMPRE debe ser virtual.
*/