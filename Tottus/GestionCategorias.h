#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "Catalogo.h"
#include "CategoriasEstructura.h"
#include "Tabla.h"
#include "Colas.h"
#include "Boleta.h"

using namespace std;

Catalogo catalogo;

//accedemos a  la lista.h para agregar un producto
Lista<Categoria*>* productosSeleccionados = new Lista<Categoria*>();
Cola<Boleta*> colaDePedidos;

Categoria gestionarCategorias(bool modoSeleccion = false) {
	SetBackgroundColor(Black);
	system("cls");

	// Variables para la navegación
	int seleccion = 0;
	int nCat = numCategoriasPrincipales; // Usar la constante definida
	int maxSeleccion = nCat + 1; // ✅ CAMBIO: +1 para incluir la opción "Salir"
	AccionTecla accion = NINGUNA;
	int opcion = -1; // Inicializamos a -1 para indicar que no se ha seleccionado nada

	while (true) {
		// Limpiar pantalla para evitar parpadeos
		system("cls");

		// Mostrar título centrado
		SetForegroundColor(Green);
		string titulo = "====== LISTA DE PRODUCTOS ======";
		int anchoConsola = GetConsoleWidth();
		int posicionCentrada = (anchoConsola - titulo.length()) / 2;
		SetCursorPosition(posicionCentrada, 2);
		cout << titulo << endl;

		// Mostrar las opciones de categorías con la selección actual resaltada
		SetForegroundColor(BrightWhite);
		for (int i = 0; i < nCat; ++i) {
			SetCursorPosition(24, 6 + i);
			if (seleccion == i) {
				setColor(0, 15); // Fondo blanco, texto negro para la selección
				cout << "> - " << categoriasPrincipales[i] << " <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - " << categoriasPrincipales[i] << "  ";
			}
		}

		// Mostrar opción de salir
		SetCursorPosition(24, 6 + nCat + 2);
		if (seleccion == nCat) {
			setColor(0, 15);
			cout << "> - Volver al Menu Anterior <";
			setColor(15, 0);
		}
		else {
			cout << "  - Volver al Menu Anterior  ";
		}

		// Esperar entrada del usuario
		accion = navegarConFlechas(seleccion, maxSeleccion);

		// Si el usuario selecciona una opción o cancela
		if (accion == SELECCIONAR) {
			if (seleccion == nCat) { // Si seleccionó "Volver al Menu Anterior"
				SetCursorPosition(24, 9 + nCat + 2);
				cout << "VOLVIENDO AL MENU ANTERIOR...";
				Sleep(500);
				system("cls");
				return Categoria(); // Salir inmediatamente sin procesar nada más
			}
			else {
				opcion = seleccion + 1; // Las opciones van de 1 a n
				break; // Salir del bucle para procesar la opción
			}
		}
		else if (accion == CANCELAR) {
			SetCursorPosition(24, 9 + nCat + 2);
			cout << "VOLVIENDO AL MENU ANTERIOR...";
			Sleep(500);
			system("cls");
			return Categoria(); // Si cancela, también salir inmediatamente
		}
	}
	switch (opcion) {
	case 1: { // Abarrotes
		system("cls");
		int nSub = sizeof(subcategoriasAbarrotes) / sizeof(subcategoriasAbarrotes[0]);
		cout << "\n\t\t\t-- " << categoriasPrincipales[0] << " --" << endl;
		for (int i = 0; i < nSub; ++i) {
			cout << "\t\t\t" << (i + 1) << ". " << subcategoriasAbarrotes[i] << endl;
		}
		cout << "\n\t\t\t0. Salir\n";
		cout << "\n\t\t\tSeleccione una opcion: ";
		int subopcion;
		cin >> subopcion;
		if (subopcion == 1) { // Arroz
			system("cls");

			// Variables para la navegación de subcategorías terciarias
			int seleccionTerciaria = 0;
			int nTer = sizeof(terciariasArroz) / sizeof(terciariasArroz[0]);
			int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionTerciaria = NINGUNA;
			int tercopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para subcategoría
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string subcategoria = string(subcategoriasAbarrotes[0]);
				transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
				string tituloArroz = "====== " + subcategoria + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaArroz = (anchoConsola - tituloArroz.length()) / 2;
				SetCursorPosition(posicionCentradaArroz, 2);
				cout << tituloArroz << endl;

				// Mostrar las opciones terciarias con navegación
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nTer; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionTerciaria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << terciariasArroz[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << terciariasArroz[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nTer + 2);
				if (seleccionTerciaria == nTer) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionTerciaria = navegarConFlechas(seleccionTerciaria, maxSeleccionTerciaria);

				// Si el usuario selecciona una opción o cancela
				if (accionTerciaria == SELECCIONAR) {
					if (seleccionTerciaria == nTer) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nTer + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						tercopcion = seleccionTerciaria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
				else if (accionTerciaria == CANCELAR) {
					SetCursorPosition(24, 9 + nTer + 2);
					cout << "VOLVIENDO AL MENU ANTERIOR...";
					Sleep(500);
					system("cls");
					break; // Si cancela, también salir
				}
			}

			if (tercopcion > 0 && tercopcion <= nTer) {
				system("cls");
				string nombreTerciaria = terciariasArroz[tercopcion - 1];
				cout << "\n\t\t\t-- Productos de Arroz " << nombreTerciaria << " --" << endl;
				try {
					Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Arroz", nombreTerciaria);

					if (modoSeleccion) {
						int idx = seleccionarProductoEnTabla(productos);

						if (idx != -1) {
							Categoria& seleccionado = productos.getValor(idx); // ✅ referencia modificable
							// Pedir cantidad al usuario
							int cantidad;
							cout << "\nIngrese la cantidad que desea comprar: ";
							cin >> cantidad;

							//validar si hay suficiente stock antes de agregar
							if (cantidad <= 0 || cantidad > seleccionado.getStock()) {
								cout << "Cantidad no válida. Stock disponible: " << seleccionado.getStock() << endl;
								system("pause>0");
								return Categoria();
							}
							// Asegurarse de que la cantidad sea positiva
							if (cantidad <= 0) {
								cout << "Cantidad debe ser mayor a 0." << endl;
								system("pause>0");
								return Categoria(); // Retorna un objeto vacío si la cantidad es inválida
							}

							// Crear una copia para modificarla y guardar cantidad (si la clase lo permite)
							Categoria* seleccionadoConCantidad = new Categoria(seleccionado);
							seleccionadoConCantidad->setCantidad(cantidad);      // ✅ para mostrar en el carrito
							seleccionado.actualizarStock(-cantidad);             // ✅ RESTAR stock del original

							productosSeleccionados->agregaInicial(seleccionadoConCantidad);
							cout << "Producto agregado correctamente" << endl;
							////ahora restar stock de categoria original
							//seleccionadoConCantidad->actualizarStock(-cantidad); // Asegúrate de que este método exista
							////comprobando si resta stock
							cout << "Stock actualizado. Stock restante: " << seleccionado.getStock() << endl;

							system("pause>0");
						}
					}
					else {
						mostrarTablaProductos(productos);
						system("pause>0");
					}
				}
				catch (const out_of_range&) {
					cout << "\t\t\tNo hay productos en esta categoría." << endl;
					system("pause>0");
				}
			}
		}
		else if (subopcion == 2) { // Conservas
			system("cls");
			int nTer = sizeof(terciariasConservas) / sizeof(terciariasConservas[0]);
			cout << "\n\t\t\t-- " << subcategoriasAbarrotes[1] << " --" << endl;
			for (int i = 0; i < nTer; ++i) {
				cout << "\t\t\t" << (i + 1) << ". " << terciariasConservas[i] << endl;
			}
			cout << "\n\t\t\t0. Salir\n";
			cout << "\n\t\t\tSeleccione una opcion: ";
			int tercopcion;
			cin >> tercopcion;
			if (tercopcion > 0 && tercopcion <= nTer) {
				system("cls");
				string nombreTerciaria = terciariasConservas[tercopcion - 1];
				cout << "\n\t\t\t-- Productos de Conservas " << nombreTerciaria << " --" << endl;
				try {
					 Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Conservas", nombreTerciaria);
					if (modoSeleccion) {
						int idx = seleccionarProductoEnTabla(productos);
						if (idx != -1) {
							Categoria& seleccionado = productos.getValor(idx); // ✅ referencia modificable
							// Pedir cantidad al usuario
							int cantidad;
							cout << "\nIngrese la cantidad que desea comprar: ";
							cin >> cantidad;

							//validar si hay suficiente stock antes de agregar
							if (cantidad <= 0 || cantidad > seleccionado.getStock()) {
								cout << "Cantidad no válida. Stock disponible: " << seleccionado.getStock() << endl;
								system("pause>0");
								return Categoria();
							}
							// Asegurarse de que la cantidad sea positiva
							if (cantidad <= 0) {
								cout << "Cantidad debe ser mayor a 0." << endl;
								system("pause>0");
								return Categoria(); // Retorna un objeto vacío si la cantidad es inválida
							}

							// Crear una copia para modificarla y guardar cantidad (si la clase lo permite)
							Categoria* seleccionadoConCantidad = new Categoria(seleccionado);
							seleccionadoConCantidad->setCantidad(cantidad);      // ✅ para mostrar en el carrito
							seleccionado.actualizarStock(-cantidad);             // ✅ RESTAR stock del original

							productosSeleccionados->agregaInicial(seleccionadoConCantidad);
							cout << "Producto agregado correctamente" << endl;
							////ahora restar stock de categoria original
							//seleccionadoConCantidad->actualizarStock(-cantidad); // Asegúrate de que este método exista
							////comprobando si resta stock
							cout << "Stock actualizado. Stock restante: " << seleccionado.getStock() << endl;
							system("pause>0");
						}
					}
					else {
						mostrarTablaProductos(productos);
						system("pause>0");
					}
				}
				catch (const out_of_range&) {
					cout << "\t\t\tNo hay productos en esta categoría." << endl;
					system("pause>0");
				}
			}
			else if (tercopcion == 0) {
				system("cls");
			}
		}
		else if (subopcion == 3) { // Aceite
			system("cls");
			int nTer = sizeof(terciariasAceite) / sizeof(terciariasAceite[0]);
			cout << "\n\t\t\t-- " << subcategoriasAbarrotes[2] << " --" << endl;
			for (int i = 0; i < nTer; ++i) {
				cout << "\t\t\t" << (i + 1) << ". " << terciariasAceite[i] << endl;
			}
			cout << "\n\t\t\t0. Salir\n";
			cout << "\n\t\t\tSeleccione una opcion: ";
			int tercopcion;
			cin >> tercopcion;
			if (tercopcion > 0 && tercopcion <= nTer) {
				system("cls");
				string nombreTerciaria = terciariasAceite[tercopcion - 1];
				cout << "\n\t\t\t-- Productos de Aceite " << nombreTerciaria << " --" << endl;
				try {
					 Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Aceite", nombreTerciaria);
					if (modoSeleccion) {
						int idx = seleccionarProductoEnTabla(productos);
						if (idx != -1) {
							Categoria& seleccionado = productos.getValor(idx); // ✅ referencia modificable
							// Pedir cantidad al usuario
							int cantidad;
							cout << "\nIngrese la cantidad que desea comprar: ";
							cin >> cantidad;

							//validar si hay suficiente stock antes de agregar
							if (cantidad <= 0 || cantidad > seleccionado.getStock()) {
								cout << "Cantidad no válida. Stock disponible: " << seleccionado.getStock() << endl;
								system("pause>0");
								return Categoria();
							}
							// Asegurarse de que la cantidad sea positiva
							if (cantidad <= 0) {
								cout << "Cantidad debe ser mayor a 0." << endl;
								system("pause>0");
								return Categoria(); // Retorna un objeto vacío si la cantidad es inválida
							}

							// Crear una copia para modificarla y guardar cantidad (si la clase lo permite)
							Categoria* seleccionadoConCantidad = new Categoria(seleccionado);
							seleccionadoConCantidad->setCantidad(cantidad);      // ✅ para mostrar en el carrito
							seleccionado.actualizarStock(-cantidad);             // ✅ RESTAR stock del original

							productosSeleccionados->agregaInicial(seleccionadoConCantidad);
							cout << "Producto agregado correctamente" << endl;
							////ahora restar stock de categoria original
							//seleccionadoConCantidad->actualizarStock(-cantidad); // Asegúrate de que este método exista
							////comprobando si resta stock
							cout << "Stock actualizado. Stock restante: " << seleccionado.getStock() << endl;

							system("pause>0");
						}
					}
					else {
						mostrarTablaProductos(productos);
						system("pause>0");
					}
				}
				catch (const out_of_range&) {
					cout << "\t\t\tNo hay productos en esta categoría." << endl;
					system("pause>0");
				}
			}
			else if (tercopcion == 0) {
				system("cls");
			}
		}
		else if (subopcion == 4) { // Pasta
			system("cls");
			int nTer = sizeof(terciariasPasta) / sizeof(terciariasPasta[0]);
			cout << "\n\t\t\t-- " << subcategoriasAbarrotes[3] << " --" << endl;
			for (int i = 0; i < nTer; ++i) {
				cout << "\t\t\t" << (i + 1) << ". " << terciariasPasta[i] << endl;
			}
			cout << "\n\t\t\t0. Salir\n";
			cout << "\n\t\t\tSeleccione una opcion: ";
			int tercopcion;
			cin >> tercopcion;
			if (tercopcion > 0 && tercopcion <= nTer) {
				system("cls");
				string nombreTerciaria = terciariasPasta[tercopcion - 1];
				cout << "\n\t\t\t-- Productos de Pasta " << nombreTerciaria << " --" << endl;
				try {
					 Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Pasta", nombreTerciaria);
					if (modoSeleccion) {
						int idx = seleccionarProductoEnTabla(productos);
						if (idx != -1) {
							Categoria& seleccionado = productos.getValor(idx); // ✅ referencia modificable
							// Pedir cantidad al usuario
							int cantidad;
							cout << "\nIngrese la cantidad que desea comprar: ";
							cin >> cantidad;

							//validar si hay suficiente stock antes de agregar
							if (cantidad <= 0 || cantidad > seleccionado.getStock()) {
								cout << "Cantidad no válida. Stock disponible: " << seleccionado.getStock() << endl;
								system("pause>0");
								return Categoria();
							}
							// Asegurarse de que la cantidad sea positiva
							if (cantidad <= 0) {
								cout << "Cantidad debe ser mayor a 0." << endl;
								system("pause>0");
								return Categoria(); // Retorna un objeto vacío si la cantidad es inválida
							}

							// Crear una copia para modificarla y guardar cantidad (si la clase lo permite)
							Categoria* seleccionadoConCantidad = new Categoria(seleccionado);
							seleccionadoConCantidad->setCantidad(cantidad);      // ✅ para mostrar en el carrito
							seleccionado.actualizarStock(-cantidad);             // ✅ RESTAR stock del original

							productosSeleccionados->agregaInicial(seleccionadoConCantidad);
							cout << "Producto agregado correctamente" << endl;
							////ahora restar stock de categoria original
							//seleccionadoConCantidad->actualizarStock(-cantidad); // Asegúrate de que este método exista
							////comprobando si resta stock
							cout << "Stock actualizado. Stock restante: " << seleccionado.getStock() << endl;

							system("pause>0");
						}
					}
					else {
						mostrarTablaProductos(productos);
						system("pause>0");
					}
				}
				catch (const out_of_range&) {
					cout << "\t\t\tNo hay productos en esta categoría." << endl;
					system("pause>0");
				}
			}
			else if (tercopcion == 0) {
				system("cls");
			}
		}
		else if (subopcion == 5) { // Menestras
			system("cls");
			int nTer = sizeof(terciariasMenestras) / sizeof(terciariasMenestras[0]);
			cout << "\n\t\t\t-- " << subcategoriasAbarrotes[4] << " --" << endl;
			for (int i = 0; i < nTer; ++i) {
				cout << "\t\t\t" << (i + 1) << ". " << terciariasMenestras[i] << endl;
			}
			cout << "\n\t\t\t0. Salir\n";
			cout << "\n\t\t\tSeleccione una opcion: ";
			int tercopcion;
			cin >> tercopcion;
			if (tercopcion > 0 && tercopcion <= nTer) {
				system("cls");
				string nombreTerciaria = terciariasMenestras[tercopcion - 1];
				cout << "\n\t\t\t-- Productos de Menestras " << nombreTerciaria << " --" << endl;
				try {
					 Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Menestras", nombreTerciaria);
					if (modoSeleccion) {
						int idx = seleccionarProductoEnTabla(productos);
						if (idx != -1) {
							Categoria& seleccionado = productos.getValor(idx); // ✅ referencia modificable
							// Pedir cantidad al usuario
							int cantidad;
							cout << "\nIngrese la cantidad que desea comprar: ";
							cin >> cantidad;

							//validar si hay suficiente stock antes de agregar
							if (cantidad <= 0 || cantidad > seleccionado.getStock()) {
								cout << "Cantidad no válida. Stock disponible: " << seleccionado.getStock() << endl;
								system("pause>0");
								return Categoria();
							}
							// Asegurarse de que la cantidad sea positiva
							if (cantidad <= 0) {
								cout << "Cantidad debe ser mayor a 0." << endl;
								system("pause>0");
								return Categoria(); // Retorna un objeto vacío si la cantidad es inválida
							}

							// Crear una copia para modificarla y guardar cantidad (si la clase lo permite)
							Categoria* seleccionadoConCantidad = new Categoria(seleccionado);
							seleccionadoConCantidad->setCantidad(cantidad);      // ✅ para mostrar en el carrito
							seleccionado.actualizarStock(-cantidad);             // ✅ RESTAR stock del original

							productosSeleccionados->agregaInicial(seleccionadoConCantidad);
							cout << "Producto agregado correctamente" << endl;
							////ahora restar stock de categoria original
							//seleccionadoConCantidad->actualizarStock(-cantidad); // Asegúrate de que este método exista
							////comprobando si resta stock
							cout << "Stock actualizado. Stock restante: " << seleccionado.getStock() << endl;

							system("pause>0");
						}
					}
					else {
						mostrarTablaProductos(productos);
						system("pause>0");
					}
				}
				catch (const out_of_range&) {
					cout << "\t\t\tNo hay productos en esta categoría." << endl;
					system("pause>0");
				}
			}
			else if (tercopcion == 0) {
				system("cls");
			}
		}
		else if (subopcion == 0) {
			system("cls");
			break;
		}
		break;
	}
	case 2:
		cout << "\t\t\tDESAYUNOS" << endl;
		break;
	case 3:
		cout << "\t\t\tLACTEOS Y QUESOS" << endl;
		break;
	case 4:
		cout << "\t\t\tHUEVOS Y FIAMBRES" << endl;
		break;
	case 5:
		cout << "\t\t\tFRUTAS Y VERDURAS" << endl;
		break;
	case 6:
		cout << "\t\t\tCARNES" << endl;
		break;
	case 7:
		cout << "\t\t\tPESCADOS Y MARISCOS" << endl;
		break;
	case 8:
		cout << "\t\t\tCONGELADOS" << endl;
		break;
	case 9:
		cout << "\t\t\tPANADERIA Y PASTELERIA" << endl;
		break;
	case 10:
		cout << "\t\t\tDULCES Y GALLETAS" << endl;
		break;
	case 11:
		cout << "\t\t\tSNACK Y FRUTOS SECOS" << endl;
		break;
	case 12:
		cout << "\t\t\tCERVEZAS" << endl;
		break;
	case 13:
		cout << "\t\t\tBEBIDAS ALCOHOLICAS" << endl;
		break;
	case 14:
		cout << "\t\t\tGASEOSAS, AGUAS Y JUGOS" << endl;
		break;
	case 15:
		cout << "\t\t\tLIMPIEZA" << endl;
		break;
	case 16:
		cout << "\t\t\tCUIDADO PERSONAL" << endl;
		break;
	case 17:
		cout << "\t\t\tBELLEZA" << endl;
		break;
	case 18:
		cout << "\t\t\tBEBES Y NINOS" << endl;
		break;
	case 19:
		cout << "\t\t\tMUNDO MASCOTAS" << endl;
		break;
	default:
		cout << "\t\tOpción invalida\n";
		system("pause");
	}

	return Categoria();
	//char pausa = _getch(); // Captura el valor devuelto
}
