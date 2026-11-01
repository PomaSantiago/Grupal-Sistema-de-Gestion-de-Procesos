// menu_cpu_memoria.h - Submenus del planificador de CPU y del gestor de memoria (Alumno B)
#ifndef MENU_CPU_MEMORIA_H
#define MENU_CPU_MEMORIA_H

#include <iostream>
#include <cstring>
#include "utilidades.h"
#include "proceso_lista.h"
#include "cola_cpu.h"
#include "pila_memoria.h"
using namespace std;

void submenuCPU(NodoLista *lista, Cola &cola) {
    int opcion;
    do {
        cout << "\n--- PLANIFICADOR DE CPU ---" << endl;
        cout << "1. Encolar proceso" << endl;
        cout << "2. Ejecutar siguiente proceso" << endl;
        cout << "3. Ver cola actual" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1: {
                int id = leerEntero("ID del proceso a encolar: ");
                NodoLista *nodo = buscarPorID(lista, id);
                if (nodo == NULL) {
                    cout << "Proceso no encontrado." << endl;
                } else if (strcmp(nodo->dato.estado, "Terminado") == 0) {
                    cout << "Ese proceso ya termino." << endl;
                } else if (buscarEnCola(cola, id) != NULL) {
                    cout << "Ese proceso ya esta en la cola." << endl;
                } else {
                    encolar(cola, nodo->dato.id, nodo->dato.nombre, nodo->dato.prioridad);
                    cambiarEstado(lista, id, "Listo");
                    cout << "Proceso encolado. Estado de la cola:" << endl;
                    mostrarCola(cola);
                }
                break;
            }
            case 2: {
                NodoCola ejecutado;
                if (desencolar(cola, ejecutado)) {
                    cambiarEstado(lista, ejecutado.idProceso, "Ejecutando");
                    cout << "Ejecutando proceso " << ejecutado.nombre
                         << " (ID " << ejecutado.idProceso << ", prioridad "
                         << ejecutado.prioridad << ")..." << endl;
                    cambiarEstado(lista, ejecutado.idProceso, "Terminado");
                    cout << "Proceso terminado. Estado de la cola:" << endl;
                    mostrarCola(cola);
                }
                break;
            }
            case 3:
                mostrarCola(cola);
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

void submenuMemoria(NodoLista *lista, Pila &pila) {
    int opcion;
    do {
        cout << "\n--- GESTOR DE MEMORIA ---" << endl;
        cout << "1. Asignar memoria a un proceso" << endl;
        cout << "2. Liberar ultimo bloque" << endl;
        cout << "3. Ver estado de la memoria" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1: {
                int id = leerEntero("ID del proceso: ");
                NodoLista *nodo = buscarPorID(lista, id);
                if (nodo == NULL) {
                    cout << "Proceso no encontrado." << endl;
                } else if (buscarBloque(pila, id) != NULL) {
                    cout << "Ese proceso ya tiene memoria asignada." << endl;
                } else if (push(pila, id, nodo->dato.memoria)) {
                    cout << "Se asignaron " << nodo->dato.memoria
                         << " MB al proceso " << id << "." << endl;
                    mostrarEstadoMemoria(pila);
                }
                break;
            }
            case 2: {
                NodoPila liberado;
                if (pop(pila, liberado)) {
                    cout << "Se liberaron " << liberado.tamano
                         << " MB del proceso " << liberado.idProceso << "." << endl;
                    mostrarEstadoMemoria(pila);
                }
                break;
            }
            case 3:
                mostrarEstadoMemoria(pila);
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

#endif
