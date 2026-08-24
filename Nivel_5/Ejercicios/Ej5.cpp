#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void resolverEjercicio5() {
    vector<string> nombres = {"Ana", "Carlos", "Alberto", "Zoe", "Beatriz", "Carlos", "Ximena", "Adrian", "Luis", "Zoe"};

    sort(nombres.begin(), nombres.end());

    sort(nombres.begin(), nombres.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    auto itFind = find(nombres.begin(), nombres.end(), "Luis");

    vector<int> longitudes(nombres.size());
    transform(nombres.begin(), nombres.end(), longitudes.begin(), [](const string& s) {
        return s.length();
    });

    nombres.erase(remove_if(nombres.begin(), nombres.end(), [](const string& s) {
        return !s.empty() && s[0] == 'A';
    }), nombres.end());

    sort(nombres.begin(), nombres.end());
    nombres.erase(unique(nombres.begin(), nombres.end()), nombres.end());
}