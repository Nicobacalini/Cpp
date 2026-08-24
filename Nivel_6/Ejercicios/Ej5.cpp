#include <iostream>
#include <iomanip>

using namespace std;

class MatrizDinamica {
private:
    int filas, cols;
    int* datos;

public:
    MatrizDinamica(int f, int c) : filas(f), cols(c), datos(new int[f * c]()) {}

    ~MatrizDinamica() { delete[] datos; }

    MatrizDinamica(const MatrizDinamica& o) : filas(o.filas), cols(o.cols), datos(new int[o.filas * o.cols]) {
        for (int i = 0; i < filas * cols; ++i) datos[i] = o.datos[i];
    }

    MatrizDinamica& operator=(const MatrizDinamica& o) {
        if (this == &o) return *this;
        delete[] datos;
        filas = o.filas; cols = o.cols;
        datos = new int[filas * cols];
        for (int i = 0; i < filas * cols; ++i) datos[i] = o.datos[i];
        return *this;
    }

    MatrizDinamica(MatrizDinamica&& o) noexcept : filas(o.filas), cols(o.cols), datos(o.datos) {
        o.datos = nullptr;
        o.filas = 0; o.cols = 0;
    }

    MatrizDinamica& operator=(MatrizDinamica&& o) noexcept {
        if (this == &o) return *this;
        delete[] datos;
        filas = o.filas; cols = o.cols; datos = o.datos;
        o.datos = nullptr; o.filas = 0; o.cols = 0;
        return *this;
    }

    int& operator()(int i, int j) {
        return datos[i * cols + j];
    }

    void mostrar() const {
        if (!datos) { cout << "[Matriz vacia]\n"; return; }
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << setw(3) << datos[i * cols + j] << " ";
            }
            cout << "\n";
        }
    }
};

void resolverEjercicio5() {
    MatrizDinamica m1(2, 2);
    m1(0, 0) = 1; m1(0, 1) = 2; m1(1, 0) = 3; m1(1, 1) = 4;
    
    cout << "Matriz m1:\n";
    m1.mostrar();

    MatrizDinamica m2 = std::move(m1); // Movimiento
    
    cout << "\nDespues de move, m1:\n";
    m1.mostrar(); // Debe indicar vacía
    cout << "Matriz m2 (robó los recursos):\n";
    m2.mostrar();
}