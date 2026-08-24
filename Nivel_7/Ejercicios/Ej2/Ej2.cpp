#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

struct Alumno {
    string nombre;
    int legajo;
    float nota;
};

class alumnos {
private:
    vector<Alumno> vectorAlumnos;

public:
    alumnos(string ruta) {
        ifstream archivo(ruta);
        
        if (archivo.is_open()) {
            string linea;
            string datos_texto;

            // Saltear la primera linea
            getline(archivo, linea);

            while (getline(archivo, linea)) {
                stringstream ss(linea); 
                Alumno temp;

                // Extraemos los datos
                getline(ss, temp.nombre, ','); 
                getline(ss, datos_texto, ',');
                temp.legajo = stoi(datos_texto); 
                getline(ss, datos_texto);
                temp.nota = stof(datos_texto); 

                // Guardamos el alumno completo
                vectorAlumnos.push_back(temp);
            }
            
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo en la ruta especificada." << endl;
        }
    }

    void calcularEstadisticasYFiltrar() {
        if (vectorAlumnos.empty()) {
            cout << "No hay alumnos cargados para calcular estadísticas." << endl;
            return;
        }

        // inicializamos la nota minima y maxima con el primer alumno del vector
        float nota_minima = vectorAlumnos[0].nota;
        float nota_maxima = vectorAlumnos[0].nota;
        float sumaNotas = 0.0f;

        cout << "--- LISTA DE EVALUACIÓN ---" << endl;

        for (const auto& [nom, leg, nt] : vectorAlumnos) {
            cout << "Legajo: " << leg << " | Alumno: " << nom << " | Nota: " << nt << endl;

            // Sumamos para el promedio
            sumaNotas += nt;

            // Sacamos el minimo y maximo
            nota_minima = min(nota_minima, nt);
            nota_maxima = max(nota_maxima, nt);
        }

        // calculamos el promedio final
        float promedio = sumaNotas / vectorAlumnos.size();

        cout << "\n--- ESTADÍSTICAS ---" << endl;
        cout << "Promedio general: " << promedio << endl;
        cout << "Nota mínima: " << nota_minima << endl;
        cout << "Nota máxima: " << nota_maxima << endl;

        // ESCRITURA Y FILTRADO CON ofstream
        ofstream archivoSalida("alumnos_aprobados.txt");

        if (archivoSalida.is_open()) {
            archivoSalida << "Nombre,Legajo,Nota\n";

            for (const auto& [nombre, legajo, nota] : vectorAlumnos) {
                if (nota >= 6.0f) { // Filtro: Notas mayores o iguales a 6
                    archivoSalida << nombre << "," << legajo << "," << nota << "\n";
                }
            }

            archivoSalida.close();
            cout << "\n[Archivo 'alumnos_aprobados.txt' generated with success]" << endl;
        } else {
            cout << "Error al crear el archivo de salida." << endl;
        }
    }
};

int main() {
    alumnos a("info.csv");
    a.calcularEstadisticasYFiltrar();
    return 0;
}
