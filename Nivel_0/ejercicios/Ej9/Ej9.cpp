#include <iostream>
#include <string>

using namespace std;

void pedirNom(string& nom) {
    cin.clear();
    do {
        cout << "Ingrese el nombre: ";
        getline(cin, nom);

        if (nom.empty()) {
            cin.clear(); 
        }
    } while (nom.empty() || nom == " ");
}

void pedirEdad(int& edad) {
    while (edad <= 0) {
        cout << "Ingrese edad: ";
        cin >> edad;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            edad = 0;
        }
    }
}

void pedirNota(float& nota) {
    while (nota < 0 || nota > 10) {
        cout << "Ingrese nota: ";
        cin >> nota;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            nota = -1;
        }
    }
}

int main (){
    string nom = "";
    int edad = 0;
    float nota= -1;

    pedirNom(nom);
    pedirEdad(edad);
    pedirNota(nota);


    cout << "nombre: " << nom << " Edad: " << edad << "Nota: "<< nota<< endl;

    if (nota >= 6 ){
        cout<< "Aprobo";
    }
    else{
        cout<< "Desaprobado";
    }

    
    return 0;
}