#include <iostream>
#include <map>
using namespace std;

void agregar(map<string, string>& miAgenda, string nombre, string tel) {
    if (miAgenda.count(nombre) == 0){
        miAgenda[nombre] = tel;
        cout<< "COntacto guardado.."<<endl;
    }
    else{cout<< "COntato existente.."<<endl;}
}

string buscar(map<string, string>& miAgenda, string nombre){
    if (miAgenda.count(nombre)==1){
        return miAgenda[nombre];
    }else{ return "Usuario no encontrado";}
}

void eliminar(map<string, string>& miAgenda, string nombre) {
    
    if (miAgenda.count(nombre)== 1){
        miAgenda.erase(nombre);
        cout<<"contacto: "<< nombre<< " Elimininado."<<endl;
    }
    else{
        cout<< "El contacto no existe."<< endl;
    }

    
}

void listarTodos(map<string, string>& miAgenda){

    for(auto& par : miAgenda){
        cout << "- " << par.first << ": " << par.second << endl;
    }
}


int main(){
    map <string, string> contactos;
    agregar(contactos, "nicolas", "12312312312");
    agregar(contactos, "julio", "12312312312");
    agregar(contactos, "mario", "12321324444");
    
    cout << "Buscando a nicolas: " << buscar(contactos, "nicolas") << endl;
    cout << "Buscando a juliana: " << buscar(contactos, "juliana") << endl;

    listarTodos(contactos);

    eliminar(contactos, "julio");


    listarTodos(contactos);
    return 0;
}