#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){

    vector<int>  desordenados = {30, 50, 70, 10, 20};
    // mayor a menor
    sort(desordenados.begin(), desordenados.end(), [](int a, int b) { return a > b; });
    // menor a mayor
    sort(desordenados.begin(), desordenados.end(), [](int a, int b) { return a < b; });

    vector <int> numeros = {7,8,4,3,2,10,80};
    // mayores que 5
    int mayores5 = count_if(numeros.begin(), numeros.end(), [](int a){return a> 5;});
    cout << "Mayores a 5: " << mayores5 << endl;
    // primer par
    auto it = find_if(numeros.begin(), numeros.end(), [](int n) {
        return n % 2 == 0;
    });
    cout << "Primer par: " << *it << endl;

    vector<int> cuadrados;
    transform(numeros.begin(), numeros.end(),back_inserter(cuadrados), [](int a){return a*a;});
    cout << "\nVector original: ";
    for(auto n : numeros) cout << n << " ";
    cout << "\nVector al cuadrado: ";
    for(auto c : cuadrados) cout << c << " ";
    cout << endl;
    return 0;
}