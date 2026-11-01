#ifndef PILA_MEMORIA_H
#define PILA_MEMORIA_H

#include <iostream>
using namespace std;

struct NodoPila {
    int idProceso;
    int tamano;             
    int direccionInicio;    
    NodoPila *siguiente;
};

struct Pila {
    NodoPila *tope;
    int ramTotal;
    int ramUsada;
};

void iniciarPila(Pila &p, int ramTotal) {
    p.tope = NULL;
    p.ramTotal = ramTotal;
    p.ramUsada = 0;
}

bool push(Pila &p, int idProceso, int tamano) {
    if (p.ramUsada + tamano > p.ramTotal) {
        cout << "Memoria insuficiente. Libre: " << (p.ramTotal - p.ramUsada)
             << " MB, requerido: " << tamano << " MB." << endl;
        return false;
    }
    NodoPila *nuevo = new NodoPila;
    nuevo->idProceso = idProceso;
    nuevo->tamano = tamano;
    nuevo->direccionInicio = p.ramUsada;
    nuevo->siguiente = p.tope;
    p.tope = nuevo;
    p.ramUsada = p.ramUsada + tamano;
    return true;
}

bool pop(Pila &p, NodoPila &liberado) {
    if (p.tope == NULL) {
        cout << "No hay bloques de memoria asignados." << endl;
        return false;
    }
    NodoPila *borrar = p.tope;
    liberado = *borrar;
    p.tope = borrar->siguiente;
    p.ramUsada = p.ramUsada - borrar->tamano;
    delete borrar;
    return true;
}

NodoPila* buscarBloque(const Pila &p, int idProceso) {
    NodoPila *aux = p.tope;
    while (aux != NULL) {
        if (aux->idProceso == idProceso) {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

void mostrarEstadoMemoria(const Pila &p) {
    cout << "RAM total: " << p.ramTotal << " MB | Usada: " << p.ramUsada
         << " MB | Libre: " << (p.ramTotal - p.ramUsada) << " MB" << endl;
    if (p.tope == NULL) {
        cout << "No hay bloques asignados." << endl;
        return;
    }
    cout << "Bloques (del tope hacia la base):" << endl;
    NodoPila *aux = p.tope;
    while (aux != NULL) {
        cout << "  Proceso " << aux->idProceso << " | " << aux->tamano
             << " MB | inicio en " << aux->direccionInicio << endl;
        aux = aux->siguiente;
    }
}

void liberarPila(Pila &p) {
    while (p.tope != NULL) {
        NodoPila *borrar = p.tope;
        p.tope = p.tope->siguiente;
        delete borrar;
    }
    p.ramUsada = 0;
}

#endif
