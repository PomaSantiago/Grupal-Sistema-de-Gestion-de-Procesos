#ifndef MENU_PROCESOS_H
#define MENU_PROCESOS_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "utilidades.h"
#include "proceso_lista.h"
#include "cola_cpu.h"
using namespace std;

void submenuProcesos(NodoLista *&lista, Cola &cola) {
    int opcion;
    do {
        cout << "\n--- GESTOR DE PROCESOS ---" << endl;
        cout << "1. Registrar proceso" << endl;
        cout << "2. Eliminar proceso" << endl;
        cout << "3. Buscar por ID" << endl;
        cout << "4. Buscar por nombre" << endl;
        cout << "5. Modificar prioridad" << endl;
        cout << "6. Cambiar estado" << endl;
        cout << "7. Listar procesos" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1: {
                Proceso p;
                p.id = leerEntero("ID: ");
                cout << "Nombre (sin espacios): ";
                cin >> setw(30) >> p.nombre;
                cin.ignore(10000, '\n');
                do {
                    p.prioridad = leerEntero("Prioridad (1 = mas alta): ");
                } while (p.prioridad < 1);
                do {
                    p.memoria = leerEntero("Memoria requerida (MB): ");
                } while (p.memoria < 1);
                strcpy(p.estado, "Listo");
                if (insertarProceso(lista, p)) {
                    cout << "Proceso registrado." << endl;
                }
                break;
            }
            case 2: {
                int id = leerEntero("ID a eliminar: ");
                if (buscarEnCola(cola, id) != NULL) {
                    cout << "El proceso esta en la cola de CPU. Ejecutelo primero." << endl;
                } else if (eliminarProceso(lista, id)) {
                    cout << "Proceso eliminado." << endl;
                }
                break;
            }
            case 3: {
                int id = leerEntero("ID a buscar: ");
                NodoLista *nodo = buscarPorID(lista, id);
                if (nodo != NULL) {
                    mostrarProceso(nodo->dato);
                } else {
                    cout << "Proceso no encontrado." << endl;
                }
                break;
            }
            case 4: {
                char nombre[30];
                cout << "Nombre a buscar: ";
                cin >> setw(30) >> nombre;
                cin.ignore(10000, '\n');
                NodoLista *nodo = buscarPorNombre(lista, nombre);
                if (nodo != NULL) {
                    mostrarProceso(nodo->dato);
                } else {
                    cout << "Proceso no encontrado." << endl;
                }
                break;
            }
            case 5: {
                int id = leerEntero("ID del proceso: ");
                if (buscarEnCola(cola, id) != NULL) {
                    cout << "El proceso esta en la cola de CPU. No se puede cambiar su prioridad." << endl;
                    break;
                }
                int nueva = leerEntero("Nueva prioridad (1 = mas alta): ");
                if (nueva < 1) {
                    cout << "Prioridad invalida." << endl;
                } else if (modificarPrioridad(lista, id, nueva)) {
                    cout << "Prioridad actualizada." << endl;
                }
                break;
            }
            case 6: {
                int id = leerEntero("ID del proceso: ");
                char estado[15];
                cout << "Nuevo estado (Listo, Ejecutando, Terminado): ";
                cin >> setw(15) >> estado;
                cin.ignore(10000, '\n');
                if (cambiarEstado(lista, id, estado)) {
                    cout << "Estado actualizado." << endl;
                }
                break;
            }
            case 7:
                mostrarProcesos(lista);
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

#endif
