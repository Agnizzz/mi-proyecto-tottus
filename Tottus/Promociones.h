#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "CategoriaGeneral.h"

using namespace std;

// Ahora el vector se declara vacío. Se llenará con los datos del archivo .txt
vector<string> ofertasPosibles;

// La función para asignar ofertas no cambia, pero la dejamos aquí.
inline void asignarOfertaAleatoria(Categoria& producto) {

    if (ofertasPosibles.empty()) return;

    int indiceOferta = rand() % ofertasPosibles.size();
    string ofertaElegida = ofertasPosibles[indiceOferta];
    producto.setOferta(ofertaElegida);

    // Si empieza con "S/ ", es un descuento fijo
    if (ofertaElegida.rfind("S/ ", 0) == 0) {
        try {
            float descuento = stof(ofertaElegida.substr(3));
            producto.setPrecioDescuento(-descuento);
        }
        catch (...) {
            producto.setPrecioDescuento(0.0); // Si falla al convertir, no aplica descuento
        }
    }
    // Si termina con "% Dcto.", es descuento porcentual
    else if (ofertaElegida.find("% Dcto.") != string::npos) {
        try {
            size_t pos = ofertaElegida.find('%');
            float porcentaje = stof(ofertaElegida.substr(0, pos));
            producto.setPrecioDescuento(porcentaje / 100.0f);
        }
        catch (...) {
            producto.setPrecioDescuento(0.0);
        }
    }
    // Si es una promoción tipo "2x1", lo simulas como 50 % de descuento
    else if (ofertaElegida == "Lleva 2 y paga 1" || ofertaElegida == "2x1") {
        producto.setPrecioDescuento(0.5); // Simulación del 50%
    }
    else {
        producto.setPrecioDescuento(0.0); // No reconocida
    }
}