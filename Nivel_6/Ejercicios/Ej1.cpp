#include <iostream>
#include <utility>

using namespace std;

class Vector3D {
private:
    float x, y, z;
    float* historial;
    int tam;

public:
    // Constructor
    Vector3D(float x, float y, float z, int tam_historial) 
        : x(x), y(y), z(z), tam(tam_historial), historial(new float[tam_historial]()) {
        cout << "Constructor normal\n";
    }

    // 1. Destructor
    ~Vector3D() {
        delete[] historial;
    }

    // 2. Constructor de copia
    Vector3D(const Vector3D& o) : x(o.x), y(o.y), z(o.z), tam(o.tam), historial(new float[o.tam]) {
        for (int i = 0; i < tam; ++i) historial[i] = o.historial[i];
        cout << "Constructor de COPIA\n";
    }

    // 3. Operador de asignacion de copia
    Vector3D& operator=(const Vector3D& o) {
        if (this == &o) return *this;
        delete[] historial;
        x = o.x; y = o.y; z = o.z; tam = o.tam;
        historial = new float[tam];
        for (int i = 0; i < tam; ++i) historial[i] = o.historial[i];
        cout << "Asignacion de COPIA\n";
        return *this;
    }

    // 4. Constructor de movimiento
    Vector3D(Vector3D&& o) noexcept : x(o.x), y(o.y), z(o.z), tam(o.tam), historial(o.historial) {
        o.historial = nullptr;
        o.tam = 0;
        cout << "Constructor de MOVIMIENTO\n";
    }

    // 5. Operador de asignacion de movimiento
    Vector3D& operator=(Vector3D&& o) noexcept {
        if (this == &o) return *this;
        delete[] historial;
        x = o.x; y = o.y; z = o.z; tam = o.tam; historial = o.historial;
        o.historial = nullptr;
        o.tam = 0;
        cout << "Asignacion de MOVIMIENTO\n";
        return *this;
    }

    void estado() const {
        cout << "Historial size: " << tam << ", Puntero: " << historial << "\n";
    }
};

void resolverEjercicio1() {
    Vector3D v1(1.0, 2.0, 3.0, 100);
    v1.estado();
    
    Vector3D v2 = std::move(v1); // Mueve v1 a v2
    
    cout << "Estado de v1 tras move:\n";
    v1.estado(); // Debe estar vacío
    cout << "Estado de v2:\n";
    v2.estado();
}