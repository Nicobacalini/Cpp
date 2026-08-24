#include <iostream>
#include <map>
#include <string>
#include <optional>
#include <sstream>

using namespace std;

class Config {
private:
    map<string, string> valores;

public:
    void set(string clave, string valor) {
        valores[clave] = valor;
    }

    optional<string> obtener(string clave) {
        if (auto it = valores.find(clave); it != valores.end()) {
            return it->second;
        }
        return nullopt;
    }

    template<typename T>
    optional<T> obtenerComo(string clave) {
        auto val = obtener(clave);
        if (val) {
            T resultado;
            stringstream ss(val.value());
            if (ss >> resultado) return resultado;
        }
        return nullopt;
    }

    template<typename T>
    T obtenerODefecto(string clave, T defecto) {
        auto val = obtenerComo<T>(clave);
        return val.value_or(defecto);
    }
};

void resolverEjercicio7() {
    Config cfg;
    cfg.set("host", "localhost");
    cfg.set("puerto", "8080");
    cfg.set("debug", "1");

    cout << "Host: " << cfg.obtener("host").value_or("desconocido") << "\n";
    cout << "Puerto: " << cfg.obtenerODefecto<int>("puerto", 80) << "\n";
    cout << "Timeout: " << cfg.obtenerODefecto<int>("timeout", 3000) << " (defecto)\n";
    cout << "Debug on: " << cfg.obtenerComo<bool>("debug").value_or(false) << "\n";
}