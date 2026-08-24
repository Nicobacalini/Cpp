#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class Logger {
private:
    string nombreArchivo;

public:
    Logger(string archivo) : nombreArchivo(archivo) {}

    void limpiarArchivo() {
        ofstream archivo(nombreArchivo, ios::trunc);
        archivo.close();
    }

    void log(string nivel, string mensaje) {
        auto ahora = chrono::system_clock::now();
        time_t tiempo_c = chrono::system_clock::to_time_t(ahora);
        
        char buffer[30]; 
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&tiempo_c));

        ofstream archivo(nombreArchivo, ios::app);

        if (archivo.is_open()) {
            archivo << "[" << buffer << "] [" << nivel << "] " << mensaje << endl;
            archivo.close();
        } else {
            cerr << "No se pudo abrir el archivo para escribir." << endl;
        }
    }
};

int main() {
    Logger miLogger("sistema.log");

    miLogger.limpiarArchivo();

    miLogger.log("INFO", "El sistema ha iniciado correctamente.");
    miLogger.log("WARNING", "Uso de CPU al 80%.");
    miLogger.log("ERROR", "Fallo al conectar con la base de datos.");
    miLogger.log("INFO", "Usuario 'admin' hizo login.");
    miLogger.log("ERROR", "No se encontró el archivo de configuración.");
    miLogger.log("INFO", "Actualización descargada.");
    miLogger.log("WARNING", "Poca memoria RAM disponible.");
    miLogger.log("ERROR", "Crash inesperado en el módulo de red.");
    miLogger.log("INFO", "Reiniciando servicios.");
    miLogger.log("INFO", "Servicios en línea.");

    cout << "--- LEYENDO LOGS (SOLO ERRORES) ---" << endl;

    ifstream archivoLectura("sistema.log");
    string linea;
    
    if (archivoLectura.is_open()) {
        while (getline(archivoLectura, linea)) {
            if (linea.find("[ERROR]") != string::npos) {
                cout << linea << endl;
            }
        }
        archivoLectura.close();
    } else {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}
