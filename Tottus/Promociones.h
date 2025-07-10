#pragma once
#include <string>
#include <cstdlib>
#include "CategoriaGeneral.h"
#include "Lista.h"

using namespace std;

// Clase para almacenar las ofertas posibles
class OfertaDescuento {
private:
	double porcentaje;   // Porcentaje de descuento como decimal (0.10, 0.20, 0.30, 0.40)
	string texto;        // Formato "X% Dcto."

public:
	// Constructor por defecto
	OfertaDescuento() : porcentaje(0.0), texto("") {}

	// Constructor con parámetros
	OfertaDescuento(const string& txt, double porc) : texto(txt), porcentaje(porc) {}

	// Getters
	string getTexto() const { return texto; }
	double getPorcentaje() const { return porcentaje; }

	// Para mostrar el objeto como string
	string toString() const { return texto; }

	// Sobrecarga del operador de flujo
	friend ostream& operator<<(ostream& os, const OfertaDescuento& oferta) {
		os << oferta.texto;
		return os;
	}
};

// Lista de ofertas disponibles
Lista<OfertaDescuento> ofertasPosibles;

// Inicializa las ofertas con los porcentajes especificados
void inicializarOfertas() {
	if (!ofertasPosibles.esVacia())
		return; // Ya está inicializada

	// Crear las ofertas con los porcentajes correctos
	ofertasPosibles.agregaFinal(OfertaDescuento("10% Dcto.", 0.10));
	ofertasPosibles.agregaFinal(OfertaDescuento("20% Dcto.", 0.20));
	ofertasPosibles.agregaFinal(OfertaDescuento("30% Dcto.", 0.30));
	ofertasPosibles.agregaFinal(OfertaDescuento("40% Dcto.", 0.40));
}

// Función para asignar ofertas aleatorias con descuentos
inline void asignarOfertaAleatoria(Categoria& producto) {
	inicializarOfertas(); // Asegurar que las ofertas estén inicializadas

	// Solo el 30% de los productos tendrán descuento
	if (rand() % 100 >= 30) {
		producto.setOferta("");
		producto.setPrecioDescuento(0.0);
		return;
	}

	// Selección del descuento
	int indice = rand() % ofertasPosibles.longitud();
	OfertaDescuento oferta = ofertasPosibles.getValor(indice);

	// Aplicar el descuento
	double precioOriginal = producto.getPrecioUnitario();
	double precioConDescuento = precioOriginal * (1.0 - oferta.getPorcentaje());

	// Formatear el precio con descuento como string (S/.XX.XX)
	stringstream ss;
	ss << "S/." << fixed << setprecision(2) << precioConDescuento;

	// Mostrar el precio con descuento en lugar del porcentaje
	producto.setOferta(ss.str());
	producto.setPrecioDescuento(precioConDescuento);
}