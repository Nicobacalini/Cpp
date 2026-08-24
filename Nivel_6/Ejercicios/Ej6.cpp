#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Pipeline {
private:
    vector<function<int(int)>> transformaciones;

public:
    void agregar(function<int(int)> f) {
        transformaciones.push_back(f);
    }

    int ejecutar(int valor) {
        int resultado = valor;
        for (const auto& f : transformaciones) {
            resultado = f(resultado);
        }
        return resultado;
    }

    vector<int> aplicarATodos(const vector<int>& datos) {
        vector<int> resultado;
        resultado.reserve(datos.size());
        for (int x : datos) {
            resultado.push_back(ejecutar(x));
        }
        return resultado;
    }
};

void resolverEjercicio6() {
    Pipeline p;
    p.agregar([](int x) { return x * 2; });        // Duplicar
    p.agregar([](int x) { return x + 10; });       // Sumar 10
    p.agregar([](int x) { return x * x; });        // Cuadrado

    vector<int> iniciales = {1, 2, 3, 4, 5};
    vector<int> finales = p.aplicarATodos(iniciales);

    cout << "Resultados del pipeline: ";
    for (int x : finales) cout << x << " ";
    cout << "\n";
}