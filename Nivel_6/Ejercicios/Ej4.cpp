#include <iostream>
#include <vector>
#include <optional>
#include <map>
#include <string>

using namespace std;

optional<pair<int, int>> encontrarIndices(const vector<int>& v, int objetivo) {
    int primera = -1, segunda = -1;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == objetivo) {
            if (primera == -1) primera = i;
            else if (segunda == -1) {
                segunda = i;
                return make_pair(primera, segunda);
            }
        }
    }
    return nullopt;
}

void resolverEjercicio4() {
    vector<int> nums = {4, 1, 9, 3, 9, 5};
    auto resultado = encontrarIndices(nums, 9);
    
    if (resultado.has_value()) {
        auto [idx1, idx2] = resultado.value();
        cout << "Indices encontrados: " << idx1 << " y " << idx2 << "\n";
    }

    map<string, pair<int, double>> estudiantes = {
        {"Nico", {22, 8.5}},
        {"Lia", {21, 9.2}},
        {"Pedro", {23, 7.8}},
        {"Ana", {20, 9.5}},
        {"Juan", {24, 6.5}}
    };

    cout << "\nLista de Estudiantes:\n";
    for (const auto& [nombre, datos] : estudiantes) {
        auto [edad, promedio] = datos; // Structured binding anidado simulado
        cout << nombre << " - Edad: " << edad << ", Promedio: " << promedio << "\n";
    }
}