#include <iostream>

using namespace std;

constexpr int fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

constexpr bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void resolverEjercicio3() {
    constexpr int f10 = fibonacci(10);
    static_assert(fibonacci(10) == 55, "Error en fibonacci");
    static_assert(esPrimo(17), "Error: 17 es primo");
    static_assert(!esPrimo(10), "Error: 10 no es primo");

    cout << "Fibonacci(10) en compilacion: " << f10 << "\n";

    constexpr int tam = fibonacci(7); // fibonacci(7) = 13
    int arreglo[tam]; // Tamaño fijo decidido al compilar
    
    cout << "Arreglo creado con tamano: " << sizeof(arreglo) / sizeof(arreglo[0]) << "\n";
}