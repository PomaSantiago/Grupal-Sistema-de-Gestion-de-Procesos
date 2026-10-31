#ifndef COLA_CPU_H
#define COLA_CPU_H
 
#include <iostream>
#include <cstring>
using namespace std;
 
struct NodoCola {
	int idProceso;
	char nombre[30];
	int prioridad; 
	NodoCola *siguiente;
};
 
struct Cola {
	NodoCola *frente;
	NodoCola *final;
};
 
void iniciarCola(Cola &c) {
	c.frente = NULL;
	c.final = NULL;
}
 
bool colaVacia(const Cola &c) {
	return c.frente == NULL;
}


void encolar(Cola &c, int idProceso, const char *nombre, int prioridad) {
	NodoCola *nuevo = new NodoCola;
	nuevo->idProceso = idProceso;
	strcpy(nuevo->nombre, nombre);
	nuevo->prioridad = prioridad;
	nuevo->siguiente = NULL;
 
	if (c.frente == NULL || prioridad < c.frente->prioridad) {
    	nuevo->siguiente = c.frente;
    	c.frente = nuevo;
    	if (c.final == NULL) {
        	c.final = nuevo;
    	}
	} else {
    	NodoCola *aux = c.frente;
    	while (aux->siguiente != NULL && aux->siguiente->prioridad <= prioridad) {
        	aux = aux->siguiente;
    	}
    	nuevo->siguiente = aux->siguiente;
    	aux->siguiente = nuevo;
    	if (nuevo->siguiente == NULL) {
        	c.final = nuevo;
    	}
	}
}
 
bool desencolar(Cola &c, NodoCola &ejecutado) {
	if (c.frente == NULL) {
    	cout << "No hay procesos en cola." << endl;
    	return false;
	}
	NodoCola *borrar = c.frente;
	ejecutado = *borrar;
	c.frente = borrar->siguiente;
	if (c.frente == NULL) {
    	c.final = NULL;
	}
	delete borrar;
	return true;
}
 
NodoCola* buscarEnCola(const Cola &c, int idProceso) {
	NodoCola *aux = c.frente;
	while (aux != NULL) {
    	if (aux->idProceso == idProceso) {
        	return aux;
    	}
    	aux = aux->siguiente;
	}
	return NULL;
}
 
int contarCola(const Cola &c) {
	int n = 0;
	NodoCola *aux = c.frente;
	while (aux != NULL) {
    	n++;
    	aux = aux->siguiente;
	}
	return n;
}
 
void mostrarCola(const Cola &c) {
	if (c.frente == NULL) {
    	cout << "No hay procesos por atender." << endl;
    	return;
	}
	cout << "Siguiente proceso: " << c.frente->nombre
     	<< " (ID " << c.frente->idProceso << ")" << endl;
	int posicion = 1;
	NodoCola *aux = c.frente;
	while (aux != NULL) {
    	cout << posicion << ". ID " << aux->idProceso << " | " << aux->nombre
         	<< " | Prioridad " << aux->prioridad << endl;
    	aux = aux->siguiente;
    	posicion++;
	}
	cout << "Procesos por atender: " << contarCola(c) << endl;
}
 
void liberarCola(Cola &c) {
	while (c.frente != NULL) {
        NodoCola *borrar = c.frente;
    	c.frente = c.frente->siguiente;
    	delete borrar;
	}
	c.final = NULL;
}
 
#endif 
