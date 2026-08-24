#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, vector<string>> directorio;

void agregarContacto(string nombre, string tel) {
    directorio[nombre].push_back(tel);
}

void buscarContacto(string nombre) {
    auto it = directorio.find(nombre);
    if (it != directorio.end()) {
        cout << nombre << ": ";
        for (const auto& t : it->second) cout << t << " ";
        cout << "\n";
    } else {
        cout << "Contacto no encontrado\n";
    }
}

void eliminarContacto(string nombre) {
    directorio.erase(nombre);
}

void buscarPorTelefono(string tel) {
    for (const auto& par : directorio) {
        for (const auto& t : par.second) {
            if (t == tel) {
                cout << "El telefono pertenece a: " << par.first << "\n";
                return;
            }
        }
    }
    cout << "Telefono no registrado\n";
}