#include <iostream>
#include <vector>
#include <chrono>
#include <functional> 
#include <cstdlib>    
#include <algorithm>

using namespace std;
using namespace chrono;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

template <typename Func>
long long medirTiempo(Func f) {
    // Tomamos el tiempo de inicio
    auto inicio = high_resolution_clock::now();
    
    // Ejecutamos la funcion que entra por parametro
    f();
    
    // Tomamos el tiempo final
    auto fin = high_resolution_clock::now();
    
    // Calculamos la duracion en microsegundos y la retornamos
    auto duracion = duration_cast<microseconds>(fin - inicio);
    return duracion.count();
}

int main() {
    // Creamos el vector con numeros aleatorios
    vector<int> datosOriginales(10000);
    for (int i = 0; i < 10000; i++) {
        datosOriginales[i] = rand() % 10000; 
    }

    // Copia para no alterar el vector original
    vector<int> copiaParaBubble = datosOriginales;

    cout << "Midiendo tiempos de ordenamiento..." << endl;

    // Medimos el tiempo del bubble sort
    long long tiempoBubble = medirTiempo([&]() { bubbleSort(copiaParaBubble); });
    cout << "Tiempo de Bubble Sort: " << tiempoBubble << " microsegundos." << endl;

    // Copia y medicion del sort nativo de C++
    vector<int> copiaParaSort = datosOriginales;
    long long tiempoSortNativo = medirTiempo([&]() { sort(copiaParaSort.begin(), copiaParaSort.end()); });
    cout << "Tiempo de std::sort nativo: " << tiempoSortNativo << " microsegundos." << endl;

    return 0;
}
