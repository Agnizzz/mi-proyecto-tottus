#pragma once
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <windows.h>
#include "CategoriaGeneral.h"
#include "Utilidades.h"
#include "Lista.h"

using namespace std;

//colocar variables globales seleccion y cantidad de que se muestre en la tabla
const int seleccionado = 0;
const int cantidad = 10;

// Función auxiliar para centrar texto
string centrarTexto(const string& texto, int anchoConsola) {
	int espacios = (anchoConsola - texto.length()) / 2;
	return string(espacios, ' ') + texto;
}

// Función para rellenar línea completa con color de fondo
void rellenarLineaCompleta(int espaciosRestantes) {
	if (espaciosRestantes > 0) {
		cout << string(espaciosRestantes, ' ');
	}
}

//encabezado centrado
void printHeader() {
	// system("cls");
	int anchoConsola = GetConsoleWidth();
	const int anchoTabla = 105; // Ancho total de la tabla ajustado
	int margen = (anchoConsola - anchoTabla) / 2;
	string espaciado = string(margen, ' ');

	setColor(15, 4);
	string titulo1 = "SUPERMERCADO VIRTUAL";
	cout << centrarTexto(titulo1, anchoConsola);
	rellenarLineaCompleta(anchoConsola - centrarTexto(titulo1, anchoConsola).length());
	cout << "\n";

	setColor(0, 6);
	string titulo2 = "LISTA DE PRODUCTOS";
	cout << centrarTexto(titulo2, anchoConsola);
	rellenarLineaCompleta(anchoConsola - centrarTexto(titulo2, anchoConsola).length());
	cout << "\n";

	setColor(0, 7);
	cout << espaciado << left
		<< setw(15) << "ID"
		<< setw(45) << "Producto"
		<< setw(12) << "Unidad"
		<< setw(12) << "Precio"
		<< setw(12) << "Oferta"
		<< setw(9) << "Stock";
	// Rellenar el resto de la línea con el color de fondo
	rellenarLineaCompleta(anchoConsola - anchoTabla - margen);
	cout << endl;

	setColor(15, 0);
}

//ACA SE AGREGO CAMBIOS - Tabla centrada SIN NAVEGACIÓN
void mostrarTablaProductos(const Lista<Categoria>& productos) {

	const int productosPorPagina = 10;
	int pagina = 0;
	int totalProductos = productos.getTam();
	int totalPaginas = (totalProductos + productosPorPagina - 1) / productosPorPagina;

	while (true) {
		system("cls");
		printHeader(); // Encabezado bonito y centrado

		int inicio = pagina * productosPorPagina;
		int fin = min(inicio + productosPorPagina, totalProductos);

		// Calcular margen para centrar la tabla
		int anchoConsola = GetConsoleWidth();
		const int anchoTabla = 105;
		int margen = (anchoConsola - anchoTabla) / 2;
		string espaciado = string(margen, ' ');

		// Mostrar todos los productos con el mismo estilo (sin resaltado)
		setColor(15, 0); // Color normal para todos los productos

		for (int i = inicio; i < fin; ++i) {
			const Categoria& prod = productos.getValor(i);

			// Formatear precio con ancho fijo
			stringstream precioStr;
			precioStr << "S/." << fixed << setprecision(2) << prod.getPrecioUnitario();

			cout << espaciado << left
				<< setw(15) << prod.getID().substr(0, 14)
				<< setw(45) << prod.getNombre().substr(0, 44)
				<< setw(12) << prod.getUnidadMedida().substr(0, 11)
				<< setw(12) << precioStr.str()
				<< setw(12) << ""  // Columna Oferta vacía
				<< setw(9) << prod.getStock();

			// Rellenar el resto de la línea con el color de fondo actual
			rellenarLineaCompleta(anchoConsola - anchoTabla - margen);
			cout << endl;
		}

		setColor(15, 0); // Restaurar color normal
		cout << "\n\n" << centrarTexto("[<-] Anterior  [->] Siguiente  [ESC] Salir", anchoConsola) << "\n\n";

		int key = _getch();
		if (key == 27) break; // ESC
		if (key == 224) {
			key = _getch();
			if (key == 75 && pagina > 0) pagina--; // Flecha izquierda - página anterior
			else if (key == 77 && pagina < totalPaginas - 1) pagina++; // Flecha derecha - página siguiente
		}
	}
}

//SE AGREGO CAMBIOS - Selección centrada CON NAVEGACIÓN
int seleccionarProductoEnTabla(const Lista<Categoria>& productos) {
	const int productosPorPagina = 10;
	int pagina = 0;
	int totalProductos = productos.getTam();
	int totalPaginas = (totalProductos + productosPorPagina - 1) / productosPorPagina;
	int seleccion = 0;

	while (true) {
		system("cls");
		printHeader();

		int inicio = pagina * productosPorPagina;
		int fin = min(inicio + productosPorPagina, totalProductos);

		// Calcular margen para centrar la tabla
		int anchoConsola = GetConsoleWidth();
		const int anchoTabla = 105;
		int margen = (anchoConsola - anchoTabla) / 2;
		string espaciado = string(margen, ' ');

		for (int i = inicio; i < fin; ++i) {
			const Categoria& prod = productos.getValor(i);
			if (i == seleccion) setColor(0, 15); // Resalta la fila seleccionada
			else setColor(15, 0);

			// Formatear precio con ancho fijo
			stringstream precioStr;
			precioStr << "S/." << fixed << setprecision(2) << prod.getPrecioUnitario();

			cout << espaciado << left
				<< setw(15) << prod.getID().substr(0, 14)
				<< setw(45) << prod.getNombre().substr(0, 44)
				<< setw(12) << prod.getUnidadMedida().substr(0, 11)
				<< setw(12) << precioStr.str()
				<< setw(12) << ""  // Columna Oferta vacía
				<< setw(9) << prod.getStock();

			// Rellenar el resto de la línea con el color de fondo actual
			rellenarLineaCompleta(anchoConsola - anchoTabla - margen);
			cout << endl;
		}

		setColor(15, 0);
		cout << "\n" << centrarTexto("[] Mover  [<-] Anterior  [->] Siguiente  [Enter] Seleccionar  [ESC] Cancelar", anchoConsola);

		int key = _getch();
		if (key == 27) {
			cout << "\n" << centrarTexto("Cancelado por el usuario con ESC", anchoConsola) << endl;
			system("pause");
			return -1;
		}
		if (key == 13) return seleccion; // Enter
		if (key == 224) {
			key = _getch();
			if (key == 72 && seleccion > 0) seleccion--; // Flecha arriba
			else if (key == 80 && seleccion < totalProductos - 1) seleccion++; // Flecha abajo
			else if (key == 75 && pagina > 0) {
				pagina--;
				seleccion = pagina * productosPorPagina;
			}
			else if (key == 77 && pagina < totalPaginas - 1) {
				pagina++;
				seleccion = pagina * productosPorPagina;
			}
		}

		// Ajustar selección si se sale de rango
		if (seleccion < pagina * productosPorPagina)
			seleccion = pagina * productosPorPagina;
		if (seleccion >= min((pagina + 1) * productosPorPagina, totalProductos))
			seleccion = min((pagina + 1) * productosPorPagina, totalProductos) - 1;
	}
}