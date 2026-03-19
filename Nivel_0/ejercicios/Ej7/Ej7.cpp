#include <iostream>
#include <string>

using namespace std;

void cambiar(int& a, int& b){

    int his = b;
    
    b = a;
    a = his;

}

int main (){
    int A= 10;
    int B= 20;
    cout << "el numero A es: " << A << " ,El numero B es: "<< B<< endl;
    cambiar(A,B);
    cout << "el numero A es: " << A << " ,El numero B es: "<< B<< endl;
    return 0;
}