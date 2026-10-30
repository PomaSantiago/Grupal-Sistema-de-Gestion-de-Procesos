#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <iostream>
using namespace std;

int leerEntero(const char *mensaje) {
    int valor;
    cout << mensaje;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. " << mensaje;
    }
    cin.ignore(10000, '\n');
    return valor;
}

#endif
