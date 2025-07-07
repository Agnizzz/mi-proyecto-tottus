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

// Función para crear efecto marquee en texto largo con velocidad más controlada
string crearTextoMarquee(const string& texto, int anchoDisponible, int& offsetGlobal, int velocidad = 3) {
	if (texto.length() <= anchoDisponible) {
		// Si el texto cabe, devolverlo tal como está
		return texto.substr(0, anchoDisponible);
	}

	// Configuración del marquee
	const int espaciosEntreCiclos = 8; // Más espacios entre repeticiones
	const string textoConEspacios = texto + string(espaciosEntreCiclos, ' ');
	const int longitudTotal = textoConEspacios.length();

	// Calcular la posición actual basada en el offset (con velocidad reducida)
	int posicionInicio = (offsetGlobal / velocidad) % longitudTotal;

	string resultado = "";
	int caracteresRestantes = anchoDisponible;
	int posicionActual = posicionInicio;

	// Llenar el ancho disponible con el texto desplazado
	while (caracteresRestantes > 0) {
		if (posicionActual >= longitudTotal) {
			posicionActual = 0;
		}

		resultado += textoConEspacios[posicionActual];
		posicionActual++;
		caracteresRestantes--;
	}

	return resultado;
}

// Variable global para controlar el offset del marquee
static int marqueeOffset = 0;
static int contadorFrames = 0;

// Función para incrementar el offset del marquee más suavemente
void actualizarMarquee() {
	contadorFrames++;
	// Solo actualizar el marquee cada 5 frames para hacerlo más suave
	if (contadorFrames >= 5) {
		marqueeOffset++;
		contadorFrames = 0;
		if (marqueeOffset > 10000) { // Resetear para evitar overflow
			marqueeOffset = 0;
		}
	}
}

//ACA SE AGREGO CAMBIOS - Tabla centrada SIN NAVEGACIÓN
void mostrarTablaProductos(const Lista<Categoria>& productos) {
	const int productosPorPagina = 10;
	int pagina = 0;
	int totalProductos = productos.getTam();
	int totalPaginas = (totalProductos + productosPorPagina - 1) / productosPorPagina;
	bool primeraVez = true;
	bool cambiarPagina = false;

	// Ocultar cursor para evitar parpadeo
	SetCursorVisible(false);

	while (true) {
		// Solo limpiar pantalla si es la primera vez o si cambió de página
		if (primeraVez || cambiarPagina) {
			system("cls");
			printHeader(); // Encabezado bonito y centrado
			primeraVez = false;
			cambiarPagina = false;
		}

		int inicio = pagina * productosPorPagina;
		int fin = min(inicio + productosPorPagina, totalProductos);

		// Calcular margen para centrar la tabla
		int anchoConsola = GetConsoleWidth();
		const int anchoTabla = 105;
		int margen = (anchoConsola - anchoTabla) / 2;
		string espaciado = string(margen, ' ');

		// Posicionar cursor al inicio del área de datos (después del header)
		SetCursorPosition(0, 3);

		// Mostrar todos los productos con el mismo estilo (sin resaltado)
		setColor(15, 0); // Color normal para todos los productos

		for (int i = inicio; i < fin; ++i) {
			const Categoria& prod = productos.getValor(i);

			// Formatear precio con ancho fijo
			stringstream precioStr;
			precioStr << "S/." << fixed << setprecision(2) << prod.getPrecioUnitario();

			// Aplicar efecto marquee al nombre del producto con velocidad reducida
			string nombreMostrar = crearTextoMarquee(prod.getNombre(), 44, marqueeOffset, 1);

			cout << espaciado << left
				<< setw(15) << prod.getID().substr(0, 14)
				<< setw(45) << nombreMostrar
				<< setw(12) << prod.getUnidadMedida().substr(0, 11)
				<< setw(12) << precioStr.str()
				<< setw(12) << ""  // Columna Oferta vacía
				<< setw(9) << prod.getStock();

			// Rellenar el resto de la línea con el color de fondo actual
			rellenarLineaCompleta(anchoConsola - anchoTabla - margen);
			cout << endl;
		}

		// Llenar las líneas vacías si hay menos productos que el máximo por página
		for (int i = fin; i < inicio + productosPorPagina; ++i) {
			cout << string(anchoConsola, ' ') << endl;
		}

		setColor(15, 0); // Restaurar color normal
		cout << "\n" << centrarTexto("[<-] Anterior  [->] Siguiente  [ESC] Salir", anchoConsola) << "\n";

		// Actualizar el offset del marquee para el siguiente frame
		actualizarMarquee();

		// Verificar si hay tecla presionada (sin bloquear)
		if (_kbhit()) {
			int key = _getch();
			if (key == 27) break; // ESC
			if (key == 224) {
				key = _getch();
				if (key == 75 && pagina > 0) {
					pagina--;
					cambiarPagina = true;
				}
				else if (key == 77 && pagina < totalPaginas - 1) {
					pagina++;
					cambiarPagina = true;
				}
			}
		}

		// Pausa más corta para menos parpadeo pero marquee fluido
		Sleep(80); // Reducido de 150ms a 80ms
	}

	// Restaurar cursor al salir
	SetCursorVisible(true);
}

//SE AGREGO CAMBIOS - Selección centrada CON NAVEGACIÓN
int seleccionarProductoEnTabla(const Lista<Categoria>& productos) {
	const int productosPorPagina = 10;
	int pagina = 0;
	int totalProductos = productos.getTam();
	int totalPaginas = (totalProductos + productosPorPagina - 1) / productosPorPagina; // Corregido el error tipográfico
	int seleccion = 0;
	bool primeraVez = true;
	bool cambiarPantalla = false;

	// Ocultar cursor para evitar parpadeo
	SetCursorVisible(false);

	while (true) {
		// Solo limpiar pantalla cuando sea necesario
		if (primeraVez || cambiarPantalla) {
			system("cls");
			printHeader();
			primeraVez = false;
			cambiarPantalla = false;
		}

		int inicio = pagina * productosPorPagina;
		int fin = min(inicio + productosPorPagina, totalProductos);

		// Calcular margen para centrar la tabla
		int anchoConsola = GetConsoleWidth();
		const int anchoTabla = 105;
		int margen = (anchoConsola - anchoTabla) / 2;
		string espaciado = string(margen, ' ');

		// Posicionar cursor al inicio del área de datos
		SetCursorPosition(0, 3);

		for (int i = inicio; i < fin; ++i) {
			const Categoria& prod = productos.getValor(i);
			if (i == seleccion) setColor(0, 15); // Resalta la fila seleccionada
			else setColor(15, 0);

			// Formatear precio con ancho fijo
			stringstream precioStr;
			precioStr << "S/." << fixed << setprecision(2) << prod.getPrecioUnitario();

			// Aplicar efecto marquee al nombre del producto con velocidad reducida
			string nombreMostrar = crearTextoMarquee(prod.getNombre(), 44, marqueeOffset, 1);

			cout << espaciado << left
				<< setw(15) << prod.getID().substr(0, 14)
				<< setw(45) << nombreMostrar
				<< setw(12) << prod.getUnidadMedida().substr(0, 11)
				<< setw(12) << precioStr.str()
				<< setw(12) << ""  // Columna Oferta vacía
				<< setw(9) << prod.getStock();

			// Rellenar el resto de la línea con el color de fondo actual
			rellenarLineaCompleta(anchoConsola - anchoTabla - margen);
			cout << endl;
		}

		// Llenar las líneas vacías si hay menos productos
		for (int i = fin; i < inicio + productosPorPagina; ++i) {
			setColor(15, 0);
			cout << string(anchoConsola, ' ') << endl;
		}

		setColor(15, 0);
		cout << "\n" << centrarTexto("[] Mover  [<-] Anterior  [->] Siguiente  [Enter] Seleccionar  [ESC] Cancelar", anchoConsola);

		// Actualizar el offset del marquee
		actualizarMarquee();

		// Verificar si hay tecla presionada (sin bloquear)
		if (_kbhit()) {
			int key = _getch();
			if (key == 27) {
				SetCursorVisible(true);
				cout << "\n" << centrarTexto("Cancelado por el usuario con ESC", anchoConsola) << endl;
				system("pause");
				return -1;
			}
			if (key == 13) {
				SetCursorVisible(true);
				return seleccion; // Enter
			}
			if (key == 224) {
				key = _getch();
				if (key == 72 && seleccion > 0) {
					seleccion--;
					// Solo cambiar pantalla si la selección requiere mostrar diferente área
					if (seleccion < pagina * productosPorPagina) {
						cambiarPantalla = true;
					}
				}
				else if (key == 80 && seleccion < totalProductos - 1) {
					seleccion++;
					// Solo cambiar pantalla si la selección requiere mostrar diferente área
					if (seleccion >= (pagina + 1) * productosPorPagina) {
						cambiarPantalla = true;
					}
				}
				else if (key == 75 && pagina > 0) {
					pagina--;
					seleccion = pagina * productosPorPagina;
					cambiarPantalla = true;
				}
				else if (key == 77 && pagina < totalPaginas - 1) {
					pagina++;
					seleccion = pagina * productosPorPagina;
					cambiarPantalla = true;
				}
			}
		}

		// Ajustar selección si se sale de rango
		if (seleccion < pagina * productosPorPagina)
			seleccion = pagina * productosPorPagina;
		if (seleccion >= min((pagina + 1) * productosPorPagina, totalProductos))
			seleccion = min((pagina + 1) * productosPorPagina, totalProductos) - 1;

		// Pausa más corta para menos parpadeo
		Sleep(80); // Reducido de 150ms a 80ms
	}

	// Restaurar cursor al salir
	SetCursorVisible(true);
}