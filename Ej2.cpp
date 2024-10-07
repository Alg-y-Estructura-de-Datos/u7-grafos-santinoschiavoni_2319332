/*
En una red social, los usuarios son representados como nodos, y las relaciones de amistad 
o  conexión  entre  ellos  son  aristas.  Este  grafo  es  no  dirigido,  ya  que,  si  dos  usuarios  son 
amigos, la relación es bidireccional. También puedes almacenar atributos adicionales, como 
el número de interacciones entre ellos, que podrían ser ponderaciones en las aristas. 
Descripción del problema: 
• Cada usuario de la red social es un nodo en el grafo. 
• Las amistades entre usuarios son las aristas. 
• Puedes buscar si dos usuarios son amigos. 
• Puedes agregar nuevas amistades. 
• Eliminar amistades o usuarios de la red. 
• Mostrar los amigos de un usuario específico. 

Operaciones: 
1. Insertar Usuario: Añadir un nodo al grafo representando a un nuevo usuario. 
2. Agregar Amistad: Añadir una arista entre dos nodos (usuarios) para representar una 
amistad. 
3. Eliminar Amistad: Quitar la conexión entre dos usuarios. 
4. Buscar Usuario: Ver si un usuario está en la red social. 
5. Imprimir la Red Social: Mostrar todos los usuarios y sus amigos (las conexiones en el grafo).
*/

#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

void menu(){
    cout << "1. Insertar usuario" << endl;
    cout << "2. Agregar amistad" << endl;
    cout << "3. Buscar persona" << endl;
    cout << "4. Eliminar persona" << endl;
    cout << "5. Mostrar amigos de un usuario" << endl;
    cout << "6. Salir" << endl;
}

void insertarUsuario(Grafo<string> &redSocial){
    string usuario;
    cout << "Ingrese el nombre del usuario: ";
    cin >> usuario;
    try{
        redSocial.agregarNodo(usuario);
        cout << "" << endl;
    }catch(int e){
        cout << "El usuario ya existe" << endl;
    }
}

void agregarAmistad(Grafo<string> &redSocial){
    string usuario1, usuario2;
    cout << "Ingrese el nombre del primer usuario: ";
    cin >> usuario1;
    cout << "Ingrese el nombre del segundo usuario: ";
    cin >> usuario2;
    try{
        redSocial.agregarArista(usuario1, usuario2);
    }catch(int e){
        cout << "" << endl;
        cout << "No se pudo agregar la amistad*********" << endl;
    }
}

void buscarPersona(Grafo<string> &redSocial){
    string usuario;
    cout << "Ingrese el nombre del usuario: ";
    cin >> usuario;
    try{
        redSocial.buscarNodo(usuario);
    }catch(int e){
        if(e == 600){
            cout << "El usuario: " << usuario << " no existe" << endl;
        }
        if(e == 601){
            cout << "El usuario: " << usuario << " si existe" << endl;
        }
    }
} 

void eliminarPersona(Grafo<string> &redSocial){
    string usuario;
    cout << "Ingrese el nombre del usuario: ";
    cin >> usuario;
    try{
        redSocial.eliminarNodo(usuario);
        cout << "El usuario: " << usuario << " fue eliminado" << endl;
    }catch(int e){
        cout << "El usuario: " << usuario << " no existe" << endl;
    }
}

int main() {
    Grafo<string> redSocial;
    int opcion;
    do{
        menu();
        cout << "  Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                insertarUsuario(redSocial);
                break;
            case 2:
                agregarAmistad(redSocial);
                break;
            case 3:
                buscarPersona(redSocial);
                break;
            case 4:
                eliminarPersona(redSocial);
                break;
            case 5:
                cout << "" << endl;
                redSocial.imprimir();
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                cout << "" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opcion != 6);
    return 0;
}
