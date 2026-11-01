#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <iostream>
#include <fstream>
#include "proceso_lista.h"
#include "cola_cpu.h"
#include "pila_memoria.h"
using namespace std;


void guardarBloques(ofstream &f, NodoPila *nodo) {
    if (nodo == NULL) {
        return;
    }
    guardarBloques(f, nodo->siguiente);
    f << nodo->idProceso << " " << nodo->tamano << endl;
}

int contarProcesos(NodoLista *cabeza) {
    int n = 0;
    while (cabeza != NULL) {
        n++;
        cabeza = cabeza->siguiente;
    }
    return n;
}

int contarBloques(const Pila &p) {
    int n = 0;
    NodoPila *aux = p.tope;
    while (aux != NULL) {
        n++;
        aux = aux->siguiente;
    }
    return n;
}

bool guardarEstado(NodoLista *lista, const Cola &cola, const Pila &pila, const char *archivo) {
    ofstream f(archivo);
    if (!f) {
        cout << "No se pudo crear el archivo " << archivo << endl;
        return false;
    }
    f << "PROCESOS " << contarProcesos(lista) << endl;
    NodoLista *p = lista;
    while (p != NULL) {
        f << p->dato.id << " " << p->dato.nombre << " " << p->dato.prioridad << " "
          << p->dato.memoria << " " << p->dato.estado << endl;
        p = p->siguiente;
    }
    f << "COLA " << contarCola(cola) << endl;
    NodoCola *c = cola.frente;
    while (c != NULL) {
        f << c->idProceso << " " << c->nombre << " " << c->prioridad << endl;
        c = c->siguiente;
    }
    f << "MEMORIA " << pila.ramTotal << " " << contarBloques(pila) << endl;
    guardarBloques(f, pila.tope);
    f.close();
    return true;
}

bool cargarEstado(NodoLista *&lista, Cola &cola, Pila &pila, const char *archivo) {
    ifstream f(archivo);
    if (!f) {
        cout << "No se encontro el archivo " << archivo << endl;
        return false;
    }
    liberarLista(lista);
    liberarCola(cola);
    liberarPila(pila);

    char etiqueta[20];
    int n, i;

    f >> etiqueta >> n;
    for (i = 0; i < n; i++) {
        Proceso p;
        f >> p.id >> p.nombre >> p.prioridad >> p.memoria >> p.estado;
        insertarProceso(lista, p);
    }

    f >> etiqueta >> n;
    for (i = 0; i < n; i++) {
        int id, prioridad;
        char nombre[30];
        f >> id >> nombre >> prioridad;
        encolar(cola, id, nombre, prioridad);
    }

    int ramTotal;
    f >> etiqueta >> ramTotal >> n;
    iniciarPila(pila, ramTotal);
    for (i = 0; i < n; i++) {
        int id, tamano;
        f >> id >> tamano;
        push(pila, id, tamano);
    }
    f.close();
    return true;
}

#endif
