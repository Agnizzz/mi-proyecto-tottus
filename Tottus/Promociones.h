#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "CategoriaGeneral.h"

using namespace std;

// Ahora el vector se declara vac�o. Se llenar� con los datos del archivo .txt
vector<string> ofertasPosibles;

// La funci�n para asignar ofertas no cambia, pero la dejamos aqu�.
inline void asignarOfertaAleatoria(Categoria& producto) {
    if (ofertasPosibles.empty()) return; // No hacer nada si no hay ofertas cargadas

    if (rand() % 4 != 0) {
        producto.setOferta("");
        producto.setPrecioDescuento(0.0);
        return;
    }

    int indiceOferta = rand() % ofertasPosibles.size();
    string ofertaElegida = ofertasPosibles[indiceOferta];
    producto.setOferta(ofertaElegida);

    if (ofertaElegida == "20% Dcto. directo") {
        producto.setPrecioDescuento(0.20);
    }
    else if (ofertaElegida == "Lleva 2 y paga 1") {
        producto.setPrecioDescuento(0.50);
    }
    else {
        producto.setPrecioDescuento(0.0);
    }
}
