#include <iostream>
#include <string>

using namespace std;


float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a*b;
}

bool dividir(float a, float b, float& resultado) {
    if (b == 0) {
        return false; 
    }
    resultado = a / b;
    return true;
}



int main (){

    int N;
    float a;
    float b;

    cout << "1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n5. salir\nElija: ";
    cin >> N;


    switch (N)
    {
    case 1:{
        cout<< "Ingrese A: ";
        cin >> a;
        cout<< "ingrese B:";
        cin >> b;
        float resultado = suma(a,b);
        cout<< "El resultado es: " << resultado<< endl;
        break;
    }
    case 2:{
        cout<< "Ingrese A: ";
        cin >> a;
        cout<< "ingrese B:";
        cin >> b;
        float resultado = resta(a,b);
        cout<< "El resultado es: " << resultado<< endl;
        break;
    }
    case 3:{
        cout<< "Ingrese A: ";
        cin >> a;
        cout<< "ingrese B:";
        cin >> b;
        float resultado = multiplicar(a,b);
        cout<< "El resultado es: " << resultado<< endl;
        break;
    }
    case 4:{
        float resultados = 0;
        cout<< "Ingrese A: ";
        cin >> a;
        cout<< "ingrese B:";
        cin >> b;
        dividir(a,b, resultados);
        cout<< "El resultado es: " << resultados<< endl;
        break;
    }
    case 5:{
            cout << "Saliendo..." << endl;
            break;  
    }


    default:{
        cout << "Opción no válida." << endl;
        break;

    }
    return 0;
}}