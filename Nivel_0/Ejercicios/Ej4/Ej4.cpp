#include <iostream>
#include <string>

using namespace std;


int main (){

    string contra = "cpp2026";
    int contador= 0;
    string s;

    while (contra != s)

    {
        cout << "Ingrese contraseña: ";
        cin >> s;
        contador += 1;
        cout << (s != contra ? "Clave incorrecta.\n" : "");
    }
    cout << "Bienvenido al sistema. Tardaste " << contador << " intentos." << endl;
    return 0;
}