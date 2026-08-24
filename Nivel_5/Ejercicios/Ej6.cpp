#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

void resolverEjercicio6() {
    vector<float> notas = {4.5, 7.0, 9.5, 2.0, 6.0, 5.5, 8.0, 3.5, 10.0, 1.5};

    float suma = accumulate(notas.begin(), notas.end(), 0.0f);
    float promedio = suma / notas.size();
    float minimo = *min_element(notas.begin(), notas.end());
    float maximo = *max_element(notas.begin(), notas.end());

    vector<float> diffCuadrados(notas.size());
    transform(notas.begin(), notas.end(), diffCuadrados.begin(), [promedio](float x) {
        return std::pow(x - promedio, 2);
    });
    float varianza = accumulate(diffCuadrados.begin(), diffCuadrados.end(), 0.0f) / notas.size();
    float desvio = std::sqrt(varianza);

    int aprobados = count_if(notas.begin(), notas.end(), [](float x) { return x >= 6.0; });
    int repiten = count_if(notas.begin(), notas.end(), [](float x) { return x >= 4.0 && x < 6.0; });
    int desaprobados = count_if(notas.begin(), notas.end(), [](float x) { return x < 4.0; });

    cout << "Aprobados: " << aprobados << " Repiten: " << repiten << " Desaprobados: " << desaprobados << "\n";
}