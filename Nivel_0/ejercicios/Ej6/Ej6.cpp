#include <iostream>
#include <string>

using namespace std;


int main (){
    int N;
    cout<< "ingrese N: ";
    cin>> N;

    for (size_t x = 0; x < N; x++)
    {
        for (size_t y = 0; y < N; y++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}