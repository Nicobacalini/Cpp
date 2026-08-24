#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include <optional>
#include <utility>

using namespace std;

class Evento {
public:
    string tipo;
    map<string, string> datos;

    Evento(string t, map<string, string> d) : tipo(std::move(t)), datos(std::move(d)) {}
};

class Dispatcher {
private:
    map<string, vector<function<void(const Evento&)>>> listeners;

public:
    void on(string tipo, function<void(const Evento&)> callback) {
        listeners[tipo].push_back(std::move(callback));
    }

    void emit(Evento e) {
        if (auto it = listeners.find(e.tipo); it != listeners.end()) {
            for (const auto& cb : it->second) {
                cb(e); 
            }
        }
    }
};

void resolverEjercicio8() {
    Dispatcher dispatcher;

    dispatcher.on("usuario_login", [](const Evento& e) {
        cout << "Evento de Login disparado:\n";
        for (const auto& [clave, valor] : e.datos) {
            cout << "  " << clave << ": " << valor << "\n";
        }
        
        // Uso de optional para chequear existencia de datos específicos
        auto it = e.datos.find("ip");
        optional<string> ipOpt = (it != e.datos.end()) ? std::make_optional(it->second) : nullopt;
        
        if (ipOpt) {
            cout << "  [ALERTA] Login registrado desde IP: " << ipOpt.value() << "\n";
        }
    });

    map<string, string> datosLogin = {
        {"usuario", "admin"},
        {"ip", "192.168.1.100"},
        {"rol", "superadmin"}
    };

    dispatcher.emit(Evento("usuario_login", std::move(datosLogin)));
}