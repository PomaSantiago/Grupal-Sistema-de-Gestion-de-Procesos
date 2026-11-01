#ifndef PROCESO_LISTA_H
#define PROCESO_LISTA_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Proceso {
    int id;
    char nombre[30];
    int prioridad;
    int memoria;
    char estado[15];
};

struct NodoLista {
    Proceso dato;
    NodoLista *siguiente;
};

NodoLista* buscarPorID(NodoLista *cabeza, int id) {
    NodoLista *aux = cabeza;
    while (aux != NULL) {
        if (aux->dato.id == id) {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

NodoLista* buscarPorNombre(NodoLista *cabeza, const char *nombre) {
    NodoLista *aux = cabeza;
    while (aux != NULL) {
        if (strcmp(aux->dato.nombre, nombre) == 0) {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

bool insertarProceso(NodoLista *&cabeza, Proceso p) {
    if (buscarPorID(cabeza, p.id) != NULL) {
        cout << "Error: el ID ya existe." << endl;
        return false;
    }
    NodoLista *nuevo = new NodoLista;
    nuevo->dato = p;
    nuevo->siguiente = NULL;
    if (cabeza == NULL) {
        cabeza = nuevo;
    } else {
        NodoLista *aux = cabeza;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    return true;
}

bool eliminarProceso(NodoLista *&cabeza, int id) {
    if (cabeza == NULL) {
        cout << "La lista esta vacia." << endl;
        return false;
    }
    if (cabeza->dato.id == id) {
        NodoLista *borrar = cabeza;
        cabeza = cabeza->siguiente;
        delete borrar;
        return true;
    }
    NodoLista *anterior = cabeza;
    NodoLista *actual = cabeza->siguiente;
    while (actual != NULL && actual->dato.id != id) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        cout << "Proceso no encontrado." << endl;
        return false;
    }
    anterior->siguiente = actual->siguiente;
    delete actual;
    return true;
}

bool modificarPrioridad(NodoLista *cabeza, int id, int nuevaPrioridad) {
    NodoLista *nodo = buscarPorID(cabeza, id);
    if (nodo == NULL) {
        cout << "Proceso no encontrado." << endl;
        return false;
    }
    nodo->dato.prioridad = nuevaPrioridad;
    return true;
}

bool estadoValido(const char *estado) {
    return strcmp(estado, "Listo") == 0 ||
           strcmp(estado, "Ejecutando") == 0 ||
           strcmp(estado, "Terminado") == 0;
}

bool cambiarEstado(NodoLista *cabeza, int id, const char *nuevoEstado) {
    NodoLista *nodo = buscarPorID(cabeza, id);
    if (nodo == NULL) {
        cout << "Proceso no encontrado." << endl;
        return false;
    }
    if (!estadoValido(nuevoEstado)) {
        cout << "Estado invalido (use Listo, Ejecutando o Terminado)." << endl;
        return false;
    }
    strcpy(nodo->dato.estado, nuevoEstado);
    return true;
}

void mostrarProceso(const Proceso &p) {
    cout << "ID: " << p.id << " | Nombre: " << p.nombre
         << " | Prioridad: " << p.prioridad
         << " | Memoria: " << p.memoria << " MB"
         << " | Estado: " << p.estado << endl;
}

void mostrarProcesos(NodoLista *cabeza) {
    if (cabeza == NULL) {
        cout << "No hay procesos registrados." << endl;
        return;
    }
    NodoLista *aux = cabeza;
    while (aux != NULL) {
        mostrarProceso(aux->dato);
        aux = aux->siguiente;
    }
}

void liberarLista(NodoLista *&cabeza) {
    while (cabeza != NULL) {
        NodoLista *borrar = cabeza;
        cabeza = cabeza->siguiente;
        delete borrar;
    }
}

#endif
