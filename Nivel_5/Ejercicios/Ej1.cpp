#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>

using namespace std;

void resolverEjercicio1() {
    srand(time(0));
    vector<int> v(15);
    for (int& x : v) x = rand() % 100 + 1;

    auto minIt = min_element(v.begin(), v.end());
    auto maxIt = max_element(v.begin(), v.end());
    cout << "Minimo: " << *minIt << ", Maximo: " << *maxIt << "\n";

    int suma = accumulate(v.begin(), v.end(), 0);
    double promedio = static_cast<double>(suma) / v.size();
    cout << "Suma: " << suma << ", Promedio: " << promedio << "\n";

    int mayores = count_if(v.begin(), v.end(), [promedio](int x) { return x > promedio; });
    cout << "Mayores al promedio: " << mayores << "\n";

    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());

    cout << "Vector ordenado sin duplicados: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}