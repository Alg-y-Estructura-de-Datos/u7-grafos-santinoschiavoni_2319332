/*
En una ciudad, se está implementando un sistema de gestión de rutas de transporte entre distintas 
estaciones. Cada estación se representa como un nodo, y las rutas directas entre estaciones se 
representan como aristas. Tu tarea es diseñar este sistema de rutas utilizando grafos, donde los 
ciudadanos puedan interactuar con el sistema para realizar varias operaciones. 
1. Agregar estaciones: 
o El sistema debe permitir agregar nuevas estaciones al mapa. Cada estación tiene un 
nombre único. 
2. Conexión de rutas entre estaciones: 
o Las estaciones pueden estar conectadas mediante rutas directas. El sistema debe 
permitir agregar una conexión entre dos estaciones, indicando que existe una ruta 
entre ellas. 
3. Eliminar estaciones: 
o Si una estación deja de funcionar, debe ser posible eliminarla del sistema. Al 
eliminar una estación, también deben eliminarse todas las rutas que conectan a dicha 
estación. 
4. Eliminar rutas: 
o En caso de que una ruta deje de ser operativa entre dos estaciones, el sistema debe 
poder eliminar esa conexión sin afectar al resto de las estaciones. 
5. Consulta de conectividad: 
o Los ciudadanos podrán consultar si existe una ruta directa entre dos estaciones 
específicas. El sistema debe devolver si esas estaciones están conectadas por una 
ruta. 
6. Verificar si una estación existe: 
o El sistema debe proporcionar una función para verificar si una estación específica 
existe en el mapa. 
7. Visualización de estaciones conectadas: 
o Los usuarios del sistema podrán consultar qué otras estaciones están directamente 
conectadas a una estación en particular. 
8. Imprimir el mapa completo: 
o Finalmente, el sistema debe poder imprimir un listado de todas las estaciones y sus 
conexiones directas, mostrando el estado actual de todas las rutas en la ciudad. 
*/

#include <iostream>
#include "Grafos/Grafo.h"
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

void menu(){
    cout << "1. Agregar estaciones" << endl;
    cout << "2. Conexion de rutas entre estaciones" << endl;
    cout << "3. Eliminar estaciones" << endl;
    cout << "4. Eliminar rutas" << endl;
    cout << "5. Consulta de conectividad" << endl;
    cout << "6. Verificar si una estacion existe" << endl;
    cout << "7. Visualizacion de estaciones conectadas" << endl;
    cout << "8. Imprimir el mapa completo" << endl;
    cout << "9. Salir" << endl;
}

// 1. Agregar estaciones
void agregarEstaciones(Grafo<string> &sistemaRutas){
    string estacion;
    cout << "Ingrese el nombre de la estación: ";
    cin >> estacion;
    try{
        sistemaRutas.agregarNodo(estacion);
        cout << "" << endl;
    }catch(int e){
        cout << "La estación ya existe" << endl;
    }
}

// 2. Conexión de rutas entre estaciones
void agregarRutas(Grafo<string> &sistemaRutas){
    string estacion1, estacion2;
    cout << "Ingrese el nombre de la primera estación: ";
    cin >> estacion1;
    cout << "Ingrese el nombre de la segunda estación: ";
    cin >> estacion2;
    try{
        sistemaRutas.agregarArista(estacion1, estacion2);
        cout << "Conexión entre estaciones agregada*****" << endl;
        cout << "" << endl;
    }catch(int e){
        cout << "" << endl;
        cout << "No se pudo agregar la conexion entre estaciones*****" << endl;
    }
}

// 3. Eliminar estaciones
void eliminarEstaciones(Grafo<string> &sistemaRutas){
    string estacion;
    cout << "Ingrese el nombre de la estación a eliminar: ";
    cin >> estacion;
    try{
        sistemaRutas.eliminarNodo(estacion);
        cout << "Estación eliminada*****" << endl;
        cout << "" << endl;
    }catch(int e){
        cout << "La estación no existe" << endl;
    }
}

// 4. Eliminar rutas
void eliminarRutas(Grafo<string> &sistemaRutas){
    string estacion1, estacion2;
    cout << "Ingrese el nombre de la primera estación: ";
    cin >> estacion1;
    cout << "Ingrese el nombre de la segunda estación: ";
    cin >> estacion2;
    try{
        sistemaRutas.eliminarArista(estacion1, estacion2);
        cout << "Ruta eliminada*****" << endl;
        cout << "" << endl;
    }catch(int e){
        cout << "No se pudo eliminar la ruta*****" << endl;
    }
}

// 5. Consulta de conectividad
void consultaConectividad(Grafo<string> &sistemaRutas){
    string estacion1, estacion2;
    cout << "Ingrese el nombre de la primera estación: ";
    cin >> estacion1;
    cout << "Ingrese el nombre de la segunda estación: ";
    cin >> estacion2;
    try{
        sistemaRutas.estanConectados(estacion1, estacion2);
        cout << "Las estaciones están conectadas*****" << endl;
        cout << "" << endl;
    }catch(int e){
        cout << "Las estaciones no están conectadas*****" << endl;
    }
}

// 6. Verificar si una estación existe
void verificarEstacion(Grafo<string> &sistemaRutas){
    string estacion;
    cout << "Ingrese el nombre de la estación: ";
    cin >> estacion;
    try{
        sistemaRutas.buscarNodo(estacion);
    }catch(int e){
        if(e==600){
            cout << "La estación no existe*****" << endl;
            cout << "" << endl;
        }
        if(e==601){
            cout << "La estación si existe*****" << endl;
            cout << "" << endl;
        }
    }
}

// 7. Visualización de estaciones conectadas
void estacionesConectadas(Grafo<string> &sistemaRutas){
    string estacion;
    cout << "Ingrese el nombre de la estación: ";
    cin >> estacion;
    try{
        sistemaRutas.imprimirConectados(estacion);
    } catch(int e){
        cout << "No se pueden mostrar conexiones" << endl;
    }
}


int main() {
    Grafo<string> sistemaRutas;
    int opcion;
    do{
        menu();
        cout << "  Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                agregarEstaciones(sistemaRutas);
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 2:
                agregarRutas(sistemaRutas);
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 3:
                eliminarEstaciones(sistemaRutas);
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 4:
                eliminarRutas(sistemaRutas);
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 5:
                consultaConectividad(sistemaRutas);
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 6:
                verificarEstacion(sistemaRutas);
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 7:
                estacionesConectadas(sistemaRutas);
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 8:
                sistemaRutas.imprimir();
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 9:
                cout << "Saliendo..." << endl;
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            default:
                cout << "Opción no válida" << endl;
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            break;
        }
    }while(opcion != 9);
    return 0;
}
