#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

map<int, set<int>> grafo;

void agregarArista(int u, int v) {
    grafo[u].insert(v);
    grafo[v].insert(u);
}

void eliminarArista(int u, int v) {
    grafo[u].erase(v);
    grafo[v].erase(u);
}

bool existeArista(int u, int v) {
    return grafo[u].count(v) > 0;
}

set<int> vecinos(int u) {
    return grafo[u];
}

int gradoNodo(int u) {
    return grafo[u].size();
}

void bfs(int inicio) {
    set<int> visitados;
    queue<int> q;
    
    q.push(inicio);
    visitados.insert(inicio);

    while (!q.empty()) {
        int actual = q.front();
        q.pop();
        cout << actual << " ";

        for (int vecino : grafo[actual]) {
            if (visitados.find(vecino) == visitados.end()) {
                visitados.insert(vecino);
                q.push(vecino);
            }
        }
    }
    cout << "\n";
}