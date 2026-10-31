#include <iostream>
#include "utilidades.h"
#include "proceso_lista.h"
#include "cola_cpu.h"
#include "pila_memoria.h"
#include "menu_procesos.h"
#include "menu_cpu_memoria.h"
#include "persistencia.h"
using namespace std;

const char *ARCHIVO_ESTADO = "estado.txt";
const int RAM_TOTAL = 1024;  

int main() {
    NodoLista *lista = NULL;
    Cola cola;
    Pila pila;
    iniciarCola(cola);
    iniciarPila(pila, RAM_TOTAL);

    int opcion;
    do {
        cout << "\n===== SISTEMA DE GESTION DE PROCESOS =====" << endl;
        cout << "1. Gestor de procesos" << endl;
        cout << "2. Planificador de CPU" << endl;
        cout << "3. Gestor de memoria" << endl;
        cout << "4. Guardar estado" << endl;
        cout << "5. Cargar estado" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1:
                submenuProcesos(lista, cola);
                break;
            case 2:
                submenuCPU(lista, cola);
                break;
            case 3:
                submenuMemoria(lista, pila);
                break;
            case 4:
                if (guardarEstado(lista, cola, pila, ARCHIVO_ESTADO)) {
                    cout << "Estado guardado en " << ARCHIVO_ESTADO << "." << endl;
                }
                break;
            case 5:
                if (cargarEstado(lista, cola, pila, ARCHIVO_ESTADO)) {
                    cout << "Estado cargado desde " << ARCHIVO_ESTADO << "." << endl;
                }
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    liberarLista(lista);
    liberarCola(cola);
    liberarPila(pila);
    return 0;
}
