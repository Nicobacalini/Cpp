#include <iostream>
#include <string>
using namespace std;


class Sensor {
private:
    string tipo;
    bool activo;
public:
    Sensor(string t, bool a) : tipo(t), activo(a) {}

    
    // SETTERS
    void setTipo(string t) { tipo = t; }
    // GETTERS
    string getTipo() { return tipo; }
    bool isActivo() { return activo; }
    void setActivo(bool a) { activo = a; }

    void escanear() { 
        activo = true;
        cout << "Sensor " << tipo << " escaneando..." << endl; 
    }
};

class Bateria {
private:
    float carga;
public:
    Bateria(float c) { setCarga(c); }

    // SETTER
    void setCarga(float c) {
        if (c < 0) carga = 0;
        else if (c > 100) carga = 100;
        else carga = c;
    }
    // GETTER
    float getCarga() { return carga; }

    bool tieneEnergia() { return carga > 0; }
};

class Robot {
private:
    Motor motor;
    Sensor sensores;
    Bateria bateria;
public:
    Robot(int v, string t, bool a, float c) : motor(v), sensores(t, a), bateria(c) {}

    void activar() {
        if (bateria.tieneEnergia()) {
            sensores.escanear();
            motor.encender();
        } else {
            cout << "Error: Bateria agotada." << endl;
        }
    }

    void mostrarEstado() {
        cout << "ESTADO DEL ROBOT:" << endl;
        cout << "- Motor Velocidad: " << motor.getVelocidad() << endl;
        cout << "- Sensor Tipo: " << sensores.getTipo() << " | Activo: " << (sensores.isActivo() ? "SI" : "NO") << endl;
        cout << "- Bateria: " << bateria.getCarga() << "%" << endl;
    }
};

class Motor {
private:
    int velocidad;
public:
    Motor(int v) { setVelocidad(v); }

    // SETTER
    void setVelocidad(int v) {
        if (v < 0) velocidad = 0;
        else velocidad = v;
    }
    // GETTER
    int getVelocidad() { return velocidad; }

    void encender() { cout << "Motor encendido a " << velocidad << " RPM." << endl; }
};

int main() {
    Robot r1(120, "Laser", false, 90.0);
    r1.activar();
    r1.mostrarEstado();

    return 0;
}