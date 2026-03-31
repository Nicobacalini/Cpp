#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class MetodoPago{
    public:
        virtual int procesarPago(int monto) = 0;
        virtual string getNombre() = 0;
        virtual ~MetodoPago() {}
    };

class PagoEfectivo : public MetodoPago{
    public:
        PagoEfectivo() {};
        int procesarPago(int monto) override{
            cout << "Pagando $" << monto << " en efectivo" << endl;
            return monto;
        }

        string getNombre() override{
            return "Efectivo";
        }
};

class PagoTarjeta : public MetodoPago{
    protected:
        string numeroTarjeta;

    public:
        PagoTarjeta(string numero) : numeroTarjeta(numero) {};

        int procesarPago(int monto) override{
            int res = ((monto * 3) / 100) + monto;
            cout << "Pagando $" << res << " con Tarjeta: " << numeroTarjeta << endl;
            return res;
        }

        string getNombre() override {
                return "Tarjeta";
            }
};

class PagoTransferencia : public MetodoPago{
    protected:
        string cbu;

    public:
        PagoTransferencia(string miCbu) : cbu(miCbu) {}

        int procesarPago(int monto) override{
            cout << "Pagando $" << monto << " al CBU: " << cbu << endl;
            return monto;
        }

        string getNombre() override{
            return "Transferencia";
        }
};

int main(){
    MetodoPago *caja[3];

    caja[0] = new PagoEfectivo();
    caja[1] = new PagoTarjeta("4545123456789012");
    caja[2] = new PagoTransferencia("0000003100012345678901");

    // Acumuladores
    int totalEfectivo = 0;
    int totalTarjeta = 0;
    int totalTransferencia = 0;

    // Arreglo con los montos a cobrar
    int montos[3] = {1000, 500, 2500};

    cout << "--- Procesando Ventas ---" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "\nCobrando la venta de $" << montos[i] << ":" << endl;

        totalEfectivo += caja[0]->procesarPago(montos[i]);
        totalTarjeta += caja[1]->procesarPago(montos[i]);
        totalTransferencia += caja[2]->procesarPago(montos[i]);
    }

    cout << "\n===============================" << endl;
    cout << "--- REPORTE DE RECAUDACION ---" << endl;
    cout << "Total Efectivo: $" << totalEfectivo << endl;
    cout << "Total Tarjeta: $" << totalTarjeta << endl;
    cout << "Total Transferencia: $" << totalTransferencia << endl;
    cout << "===============================" << endl;

    // Liberamos memoria
    for (int i = 0; i < 3; i++)
    {
        delete caja[i];
    }

    return 0;
}