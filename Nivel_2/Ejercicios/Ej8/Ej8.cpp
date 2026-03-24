#include <iostream>
#include <string>
using namespace std;


class MiString{
    private:
        char* buffer;
        int longitud;

    public:
        // constructor
        MiString(const char* palabra){
            const char* p = palabra;
            this->longitud= 0;

            while (*p != '\0'){
                this->longitud++;
                p++;
            }
            buffer = new char[longitud+1];
             for (int i = 0; i <= longitud; i++)
                buffer[i] = palabra[i];
        }

        // contructor vacio
        MiString() {
            buffer = nullptr;
            longitud = 0;
        }

        //constructor copia
        MiString (const MiString& otro){
            longitud = otro.longitud;
            buffer = new char [longitud+ 1];

            for (int i = 0; i < longitud; i++)
            {
                buffer[i] = otro.buffer[i];
            }
            buffer[longitud] = '\0';
        }

        // liberar memoria
        ~MiString(){
            delete[] buffer;
            cout << "Memoria liberada" << endl;
        }

        

        int getLongitud(){
            return this->longitud;
        }
        
        void mostrar(){
            for (int i = 0; i < longitud; i++)
            {
                cout<< this->buffer[i]<<endl;
            }
        }

        MiString& operator=(const MiString& otro){
            if (this == &otro) return *this;
            delete [] buffer; // liberar memoria anterior

            longitud = otro.longitud;
            buffer = new char[longitud+1];

            for (int i = 0; i < longitud; i++)
            {
                buffer[i] = otro.buffer[i];
            }
            return *this;
        }

        MiString operator+ (const MiString& otro) const{
            MiString a;
            a.longitud = this->longitud + otro.longitud;

            a.buffer = new char[a.longitud + 1];

            
            int i = 0;
            for (; i < this->longitud; i++)
            {
                a.buffer[i]= this->buffer[i];
            }
            
            for (int j = 0; i < a.longitud; i++, j++)
            {
                a.buffer[i] = otro.buffer[j];
            }

            a.buffer[a.longitud] = '\0';
            return a;
        }
};



int main() {
    MiString s1("Hola");
    MiString s2(" Mundo");

    s1.mostrar();
    s2.mostrar();

    // concatenar
    MiString s3 = s1 + s2;
    s3.mostrar();

    // constructor de copia
    MiString s4 = s1;
    s4.mostrar();

    // operador de asignacion
    MiString s5("Chau");
    s5 = s1;
    s5.mostrar();

    // longitud
    cout << "Longitud s3: " << s3.getLongitud() << endl;

    return 0;
}