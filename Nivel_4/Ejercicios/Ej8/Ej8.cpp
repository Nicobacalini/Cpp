#include <iostream>
#include <numeric>
#include <stdexcept> // Para los errores
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <numeric>
#include <map>
using namespace std;

class Alumno
{
private:
    string nombre;
    int legajo;
    vector<float> notas;
public:


    bool validadNota(float n){
        return (n > 10 || n < 0);
    }

    Alumno(string nombre,int legajo,vector<float> n): nombre(nombre), legajo(legajo){
        for(float nota: n){
            if (validadNota(nota))
            {
                throw invalid_argument ("Error: nota no compatible");
            }
            
        }
        notas = n;
    };
    void agregarNota(float n){
        if (validadNota (n)){
            throw invalid_argument ("Error: nota no compatible");
        }
        else{
            notas.push_back(n);
        }
    }

    float promedio(){
        if (notas.empty()) return 0.0;

        float suma = accumulate(notas.begin(), notas.end(), 0.0f, [](float accumulador, float nota){
            return accumulador + nota;
        });

        return suma / notas.size();
    }

    bool aprueba(){
        return all_of(notas.begin(),notas.end(), [](float nota){
            return nota>= 6.0;
        });
    }

    ~Alumno(){};

    string getNombre() const{return nombre;}
    int getLegajo() const{return legajo;}

};


int main() {

    // Vector de unique_ptr
    vector<unique_ptr<Alumno>> curso;

    // 5 alumnos con make_unique
    try {
        curso.push_back(make_unique<Alumno>("Nico", 101, vector<float>{8.5, 9.0, 10.0}));
        curso.push_back(make_unique<Alumno>("Julio", 102, vector<float>{4.0, 5.5, 6.0}));
        curso.push_back(make_unique<Alumno>("Mario", 103, vector<float>{10.0, 10.0, 9.5}));
        curso.push_back(make_unique<Alumno>("Ana", 104, vector<float>{7.0, 6.0, 8.0}));
        curso.push_back(make_unique<Alumno>("Luis", 105, vector<float>{2.0, 4.0, 5.0}));
        
        
    } catch (const invalid_argument& e) {
        cout << "Error al cargar alumnos: " << e.what() << endl;
        return 1;
    }

    map<string, float> registroPromedios;
    
    for (const auto& alumno : curso) {
        string legajoStr = to_string(alumno->getLegajo());
        registroPromedios[legajoStr] = alumno->promedio();
    }

    // Ordenamos el vector de alumnos por promedio
    sort(curso.begin(), curso.end(), [](const unique_ptr<Alumno>& a, const unique_ptr<Alumno>& b) {
        return a->promedio() > b->promedio(); 
    });

    
    cout << "\n--- RANKING DEL CURSO ---" << endl;
    for (const auto& alumno : curso) {
        cout << "- " << alumno->getNombre() << " (Leg: " << alumno->getLegajo() << ")" << endl;
        cout << "  Promedio: " << alumno->promedio();
        
        // Usamos el metodo aprueba()
        if (alumno->aprueba()) {
            cout << " -> ESTADO: PROMOCIONA" << endl;
        } else {
            cout << " -> ESTADO: A FINAL / RECURSA" << endl;
        }
    }

    cout << "\n--- DICCIONARIO DE PROMEDIOS (MAP) ---" << endl;
    for (auto& par : registroPromedios) {
        cout << "Legajo " << par.first << ": " << par.second << endl;
    }
    return 0;
}
