#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
using namespace chrono;

// El mutex sigue siendo global para coordinar el acceso de los hilos
std::mutex mtx;

long long sumaSecuencial(const vector<int>& v) {
    long long sum = 0;
    for (int num : v) {
        sum += num;
    }
    return sum;
}

// Pasamos 'sumaTotal' por referencia para evitar usar una variable global
void trabajador(const vector<int>& v, int inicio, int fin, long long& sumaTotal) {
    long long sumaLocal = 0;

    // 1. Calculo local sin bloqueos (maxima eficiencia)
    for (int i = inicio; i < fin; ++i) {
        sumaLocal += v[i];
    }

    // 2. Bloqueo seguro usando RAII
    std::lock_guard<mutex> guard(mtx); 
    
    // 3. Actualizacion de la variable compartida
    sumaTotal += sumaLocal; 
}

// Modificada para retornar el resultado final directamente
long long sumaParalela(const vector<int>& v, int numHilos) {
    long long sumaTotal = 0; // Variable local en lugar de global
    vector<thread> hilos;
    int n = v.size();
    int tamanoBloque = n / numHilos;

    for (int i = 0; i < numHilos; i++) {
        int inicio = i * tamanoBloque;
        int fin = (i + 1) * tamanoBloque;

        if (i == numHilos - 1) {
            fin = n;
        }

        // Pasamos 'ref(sumaTotal)' como nuevo argumento al trabajador
        hilos.push_back(thread(trabajador, ref(v), inicio, fin, ref(sumaTotal)));
    }

    // Esperar a que todos los hilos terminen
    for (size_t i = 0; i < hilos.size(); i++) {
        hilos[i].join(); 
    }

    return sumaTotal; // Retornamos el resultado final
}

int main() {
    cout << "Creando vector de 10 millones de elementos..." << endl;
    vector<int> datos(10000000, 1); // Vector de 10 millones de '1's

    // Medicion Secuencial
    auto inicioSec = high_resolution_clock::now();
    long long totalSec = sumaSecuencial(datos);
    auto finSec = high_resolution_clock::now();
    cout << "Suma Secuencial: " << totalSec 
         << " | Tiempo: " << duration_cast<milliseconds>(finSec - inicioSec).count() << " ms" << endl;

    // Medicion Paralela
    int hilosAUsar = 32;
    auto inicioPar = high_resolution_clock::now();
    long long totalPar = sumaParalela(datos, hilosAUsar); // Ahora captura el retorno de la funcion
    auto finPar = high_resolution_clock::now();
    cout << "Suma Paralela (" << hilosAUsar << " hilos): " << totalPar 
         << " | Tiempo: " << duration_cast<milliseconds>(finPar - inicioPar).count() << " ms" << endl;

    return 0;
}
