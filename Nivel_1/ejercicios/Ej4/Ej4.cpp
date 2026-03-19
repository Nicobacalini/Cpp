#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria
{
    private:
        string titular;
        float saldo;
        int numeroCuenta;

    public:
        CuentaBancaria(string titular, float saldo, int numeroCuenta) 
        : titular(titular), saldo(saldo), numeroCuenta(numeroCuenta) {}

        void depositar(float m) {
            if (m > 0) {
                saldo += m;
                cout << "Deposito exitoso. Monto: $" << m << " | Saldo actual: $" << saldo << endl;
            } 
            else {
                cout << "Monto invalido: $" << m << endl;
            }
        }

        bool verificar(float m){
            if (saldo >= m){
                return true;
            }
            else{
                return false;
            }

        }

        void retirar(float m) {
            if (verificar(m)) {
                saldo -= m;
                cout << "Retiro exitoso. $" << m << " | Saldo actual: $" << saldo << endl;
            } 
            else {
                cout << "Saldo insuficiente. Saldo: $" << saldo << " | Intento retirar: $" << m << endl;
            }
        }

        void transferir(CuentaBancaria& destino, float m) {
            if (verificar(m)) {
                saldo -= m;
                destino.saldo += m;
                cout << "Transferencia exitosa a cuenta: " << destino.numeroCuenta 
                    << " | Titular: " << destino.titular 
                    << " | Saldo actual: $" << saldo << endl;
            } 
            else {
                cout << "Transferencia fallida. Saldo insuficiente: $" << saldo << endl;
            }
        }

        void mostrarEstado(){
            cout<< "titular: "<< titular<< "Numero de cuenta: "<< numeroCuenta<< ". Saldo disponible: "<< saldo<< endl;
        }
};

int main() {
    CuentaBancaria c1("Juan", 5000, 1001);
    CuentaBancaria c2("Ana", 2000, 1002);

    c1.mostrarEstado();
    c2.mostrarEstado();

    c1.depositar(1000);
    c1.mostrarEstado();

    c1.retirar(500);
    c1.mostrarEstado();

    c1.retirar(99999);  // debe fallar

    c1.transferir(c2, 1000);
    c1.mostrarEstado();
    c2.mostrarEstado();

    c1.transferir(c2, 99999);  // debe fallar

    return 0;
}