#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> precios;
map<string, int> stock;
vector<pair<string, int>> historialVentas;

void vender(string producto, int cantidad) {
    if (stock[producto] >= cantidad) {
        stock[producto] -= cantidad;
        historialVentas.push_back({producto, cantidad});
    } else {
        cout << "Stock insuficiente para " << producto << "\n";
    }
}

void restock(string producto, int cantidad) {
    stock[producto] += cantidad;
}

void productosAgotados() {
    vector<pair<string, int>> agotados;
    copy_if(stock.begin(), stock.end(), back_inserter(agotados), [](const auto& p) {
        return p.second == 0;
    });
    
    cout << "Agotados:\n";
    for (const auto& p : agotados) cout << "- " << p.first << "\n";
}

void top3Vendidos() {
    sort(historialVentas.begin(), historialVentas.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    cout << "Top 3 Ventas:\n";
    for (size_t i = 0; i < min(historialVentas.size(), size_t(3)); ++i) {
        cout << historialVentas[i].first << ": " << historialVentas[i].second << " unidades\n";
    }
}

void reporteCompleto() {
    for_each(stock.begin(), stock.end(), [](const auto& p) {
        cout << "Producto: " << p.first << ", Precio: $" << precios[p.first] << ", Stock: " << p.second << "\n";
    });
}