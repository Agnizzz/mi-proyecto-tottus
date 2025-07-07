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
	}
	switch (opcion) {
		case 1: { // Abarrotes
		// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasAbarrotes) / sizeof(subcategoriasAbarrotes[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[0]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloAbarrotes = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaAbarrotes = (anchoConsola - tituloAbarrotes.length()) / 2;
				SetCursorPosition(posicionCentradaAbarrotes, 2);
				cout << tituloAbarrotes << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasAbarrotes[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasAbarrotes[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
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

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasConservas) / sizeof(terciariasConservas[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[1]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloConservas = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaConservas = (anchoConsola - tituloConservas.length()) / 2;
					SetCursorPosition(posicionCentradaConservas, 2);
					cout << tituloConservas << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasConservas[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasConservas[i] << "  ";
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
				}

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
			}
			else if (subopcion == 3) { // Aceite
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasAceite) / sizeof(terciariasAceite[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[2]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloAceite = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaAceite = (anchoConsola - tituloAceite.length()) / 2;
					SetCursorPosition(posicionCentradaAceite, 2);
					cout << tituloAceite << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasAceite[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasAceite[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

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
			}
			else if (subopcion == 4) { // Pasta
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasPasta) / sizeof(terciariasPasta[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[3]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloPasta = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaPasta = (anchoConsola - tituloPasta.length()) / 2;
					SetCursorPosition(posicionCentradaPasta, 2);
					cout << tituloPasta << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasPasta[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasPasta[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

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
			}
			else if (subopcion == 5) { // Menestras
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasMenestras) / sizeof(terciariasMenestras[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[4]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloMenestras = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaMenestras = (anchoConsola - tituloMenestras.length()) / 2;
					SetCursorPosition(posicionCentradaMenestras, 2);
					cout << tituloMenestras << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasMenestras[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasMenestras[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

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
			}
			else if (subopcion == 6) { // Sal
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasSal) / sizeof(terciariasSal[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[5]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloSal = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaSal = (anchoConsola - tituloSal.length()) / 2;
					SetCursorPosition(posicionCentradaSal, 2);
					cout << tituloSal << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasSal[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasSal[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

				if (tercopcion > 0 && tercopcion <= nTer) {
					system("cls");
					string nombreTerciaria = terciariasSal[tercopcion - 1];
					cout << "\n\t\t\t-- Productos de Sal " << nombreTerciaria << " --" << endl;
					try {
						Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Sal", nombreTerciaria);

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
			else if (subopcion == 7) { // Salsas para Pasta
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasSalsasPasta) / sizeof(terciariasSalsasPasta[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[6]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloSalsasPasta = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaSalsasPasta = (anchoConsola - tituloSalsasPasta.length()) / 2;
					SetCursorPosition(posicionCentradaSalsasPasta, 2);
					cout << tituloSalsasPasta << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasSalsasPasta[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasSalsasPasta[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

				if (tercopcion > 0 && tercopcion <= nTer) {
					system("cls");
					string nombreTerciaria = terciariasSalsasPasta[tercopcion - 1];
					cout << "\n\t\t\t-- Productos de Salsas para Pasta " << nombreTerciaria << " --" << endl;
					try {
						Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Salsas para Pasta", nombreTerciaria);

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
			else if (subopcion == 8) { // Salsas/Cremas
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasSalsasCremas) / sizeof(terciariasSalsasCremas[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[7]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloSalsasCremas = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaSalsasCremas = (anchoConsola - tituloSalsasCremas.length()) / 2;
					SetCursorPosition(posicionCentradaSalsasCremas, 2);
					cout << tituloSalsasCremas << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasSalsasCremas[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasSalsasCremas[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

				if (tercopcion > 0 && tercopcion <= nTer) {
					system("cls");
					string nombreTerciaria = terciariasSalsasCremas[tercopcion - 1];
					cout << "\n\t\t\t-- Productos de Salsas/Cremas " << nombreTerciaria << " --" << endl;
					try {
						Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Salsas/Cremas", nombreTerciaria);

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
			else if (subopcion == 9) { // Condimentos
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasCondimentos) / sizeof(terciariasCondimentos[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[8]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloCondimentos = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaCondimentos = (anchoConsola - tituloCondimentos.length()) / 2;
					SetCursorPosition(posicionCentradaCondimentos, 2);
					cout << tituloCondimentos << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasCondimentos[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasCondimentos[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

				if (tercopcion > 0 && tercopcion <= nTer) {
					system("cls");
					string nombreTerciaria = terciariasCondimentos[tercopcion - 1];
					cout << "\n\t\t\t-- Productos de Condimentos " << nombreTerciaria << " --" << endl;
					try {
						Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Condimentos", nombreTerciaria);

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
			else if (subopcion == 10) { // Especias
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasEspecias) / sizeof(terciariasEspecias[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[9]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloEspecias = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaEspecias = (anchoConsola - tituloEspecias.length()) / 2;
					SetCursorPosition(posicionCentradaEspecias, 2);
					cout << tituloEspecias << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasEspecias[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasEspecias[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

				if (tercopcion > 0 && tercopcion <= nTer) {
					system("cls");
					string nombreTerciaria = terciariasEspecias[tercopcion - 1];
					cout << "\n\t\t\t-- Productos de Especias " << nombreTerciaria << " --" << endl;
					try {
						Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Especias", nombreTerciaria);

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
			else if (subopcion == 11) { // Pure, Sopas y Bases
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasPure) / sizeof(terciariasPure[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[10]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloPure = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaPure = (anchoConsola - tituloPure.length()) / 2;
					SetCursorPosition(posicionCentradaPure, 2);
					cout << tituloPure << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasPure[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasPure[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

				if (tercopcion > 0 && tercopcion <= nTer) {
					system("cls");
					string nombreTerciaria = terciariasPure[tercopcion - 1];
					cout << "\n\t\t\t-- Productos de Pure Sopas y Bases " << nombreTerciaria << " --" << endl;
					try {
						Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Pure Sopas y Bases", nombreTerciaria);

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
			else if (subopcion == 12) { // Harina
				system("cls");

				// Variables para la navegación de subcategorías terciarias
				int seleccionTerciaria = 0;
				int nTer = sizeof(terciariasHarina) / sizeof(terciariasHarina[0]);
				int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
				AccionTecla accionTerciaria = NINGUNA;
				int tercopcion = -1;

				while (true) {
					// Limpiar pantalla
					system("cls");

					// Mostrar título centrado para subcategoría
					SetForegroundColor(Green);
					// Convertir a mayúsculas
					string subcategoria = string(subcategoriasAbarrotes[11]);
					transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
					string tituloHarina = "====== " + subcategoria + " ======";
					int anchoConsola = GetConsoleWidth();
					int posicionCentradaHarina = (anchoConsola - tituloHarina.length()) / 2;
					SetCursorPosition(posicionCentradaHarina, 2);
					cout << tituloHarina << endl;

					// Mostrar las opciones terciarias con navegación
					SetForegroundColor(BrightWhite);
					for (int i = 0; i < nTer; ++i) {
						SetCursorPosition(24, 6 + i);
						if (seleccionTerciaria == i) {
							setColor(0, 15); // Fondo blanco, texto negro para la selección
							cout << "> - " << terciariasHarina[i] << " <";
							setColor(15, 0); // Volver a colores normales
						}
						else {
							cout << "  - " << terciariasHarina[i] << "  ";
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

					// Si el usuario selecciona una opción
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
				}

				if (tercopcion > 0 && tercopcion <= nTer) {
					system("cls");
					string nombreTerciaria = terciariasHarina[tercopcion - 1];
					cout << "\n\t\t\t-- Productos de Harina " << nombreTerciaria << " --" << endl;
					try {
						Lista<Categoria>& productos = catalogo.getPorCategoria(1, "Harina", nombreTerciaria);

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
		}
			break;
		}
		case 2: { // Desayunos
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasDesayunos) / sizeof(subcategoriasDesayunos[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[1]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloDesayunos = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaDesayunos = (anchoConsola - tituloDesayunos.length()) / 2;
				SetCursorPosition(posicionCentradaDesayunos, 2);
				cout << tituloDesayunos << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasDesayunos[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasDesayunos[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Panadería
					system("cls");

					// Variables para la navegación de subcategorías terciarias
					int seleccionTerciaria = 0;
					int nTer = sizeof(terciariasPan) / sizeof(terciariasPan[0]);
					int maxSeleccionTerciaria = nTer + 1; // +1 para incluir la opción "Salir"
					AccionTecla accionTerciaria = NINGUNA;
					int tercopcion = -1;

					while (true) {
						// Limpiar pantalla
						system("cls");

						// Mostrar título centrado para subcategoría
						SetForegroundColor(Green);
						// Convertir a mayúsculas
						string subcategoria = string(subcategoriasDesayunos[0]);
						transform(subcategoria.begin(), subcategoria.end(), subcategoria.begin(), ::toupper);
						string tituloPanaderia = "====== " + subcategoria + " ======";
						int anchoConsola = GetConsoleWidth();
						int posicionCentradaPanaderia = (anchoConsola - tituloPanaderia.length()) / 2;
						SetCursorPosition(posicionCentradaPanaderia, 2);
						cout << tituloPanaderia << endl;

						// Mostrar las opciones terciarias con navegación
						SetForegroundColor(BrightWhite);
						for (int i = 0; i < nTer; ++i) {
							SetCursorPosition(24, 6 + i);
							if (seleccionTerciaria == i) {
								setColor(0, 15); // Fondo blanco, texto negro para la selección
								cout << "> - " << terciariasPan[i] << " <";
								setColor(15, 0); // Volver a colores normales
							}
							else {
								cout << "  - " << terciariasPan[i] << "  ";
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
					}

					if (tercopcion > 0 && tercopcion <= nTer) {
						system("cls");
						string nombreTerciaria = terciariasPan[tercopcion - 1];
						cout << "\n\t\t\t-- Productos de Panaderia " << nombreTerciaria << " --" << endl;
						try {
							Lista<Categoria>& productos = catalogo.getPorCategoria(2, "Panaderia", nombreTerciaria);

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

									// Crear una copia para modificarla y guardar cantidad (si la clase lo permite)
									Categoria* seleccionadoConCantidad = new Categoria(seleccionado);
									seleccionadoConCantidad->setCantidad(cantidad);      // ✅ para mostrar en el carrito
									seleccionado.actualizarStock(-cantidad);             // ✅ RESTAR stock del original

									productosSeleccionados->agregaInicial(seleccionadoConCantidad);
									cout << "Producto agregado correctamente" << endl;
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
				else if (subopcion == 2) { // Azúcar y Sustitutos
					// TODO: Implementar navegación terciaria para Azúcar y Sustitutos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDesayunos[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Café e Infusiones
					// TODO: Implementar navegación terciaria para Café e Infusiones
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDesayunos[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Cereales
					// TODO: Implementar navegación terciaria para Cereales
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDesayunos[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Modificadores y Complementos
					// TODO: Implementar navegación terciaria para Modificadores y Complementos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDesayunos[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 6) { // Mermeladas, Mieles y Dulces
					// TODO: Implementar navegación terciaria para Mermeladas, Mieles y Dulces
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDesayunos[5] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 3: { // Lácteos y Quesos
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasLacteos) / sizeof(subcategoriasLacteos[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[2]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloLacteos = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaLacteos = (anchoConsola - tituloLacteos.length()) / 2;
				SetCursorPosition(posicionCentradaLacteos, 2);
				cout << tituloLacteos << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasLacteos[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasLacteos[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Leches
					// TODO: Implementar navegación terciaria para Leches
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLacteos[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Yogurt
					// TODO: Implementar navegación terciaria para Yogurt
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLacteos[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Quesos
					// TODO: Implementar navegación terciaria para Quesos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLacteos[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Quesos del Mundo
					// TODO: Implementar navegación terciaria para Quesos del Mundo
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLacteos[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Mantequillas y Margarinas
					// TODO: Implementar navegación terciaria para Mantequillas y Margarinas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLacteos[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 4: { // Huevos y Fiambres
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasHuevos) / sizeof(subcategoriasHuevos[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[3]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloHuevos = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaHuevos = (anchoConsola - tituloHuevos.length()) / 2;
				SetCursorPosition(posicionCentradaHuevos, 2);
				cout << tituloHuevos << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasHuevos[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasHuevos[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Huevos
					// TODO: Implementar navegación terciaria para Huevos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Jamones
					// TODO: Implementar navegación terciaria para Jamones
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Jamonadas
					// TODO: Implementar navegación terciaria para Jamonadas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Salchichas y Hot Dogs
					// TODO: Implementar navegación terciaria para Salchichas y Hot Dogs
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Chorizos
					// TODO: Implementar navegación terciaria para Chorizos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 6) { // Fiambres Gourmet
					// TODO: Implementar navegación terciaria para Fiambres Gourmet
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[5] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 7) { // Otros Fiambres
					// TODO: Implementar navegación terciaria para Otros Fiambres
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[6] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 8) { // Salsas y Cocktail
					// TODO: Implementar navegación terciaria para Salsas y Cocktail
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasHuevos[7] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 5: { // Frutas y Verduras
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasFrutas) / sizeof(subcategoriasFrutas[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[4]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloFrutas = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaFrutas = (anchoConsola - tituloFrutas.length()) / 2;
				SetCursorPosition(posicionCentradaFrutas, 2);
				cout << tituloFrutas << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasFrutas[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasFrutas[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Frutas
					// TODO: Implementar navegación terciaria para Frutas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasFrutas[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Verduras
					// TODO: Implementar navegación terciaria para Verduras
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasFrutas[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Orgánicos
					// TODO: Implementar navegación terciaria para Orgánicos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasFrutas[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 6: { // Carnes
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasCarnes) / sizeof(subcategoriasCarnes[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[5]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloCarnes = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaCarnes = (anchoConsola - tituloCarnes.length()) / 2;
				SetCursorPosition(posicionCentradaCarnes, 2);
				cout << tituloCarnes << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasCarnes[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasCarnes[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Pollo
					// TODO: Implementar navegación terciaria para Pollo
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCarnes[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Res
					// TODO: Implementar navegación terciaria para Res
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCarnes[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Cerdo
					// TODO: Implementar navegación terciaria para Cerdo
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCarnes[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Pavo
					// TODO: Implementar navegación terciaria para Pavo
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCarnes[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Carnes Regionales
					// TODO: Implementar navegación terciaria para Carnes Regionales
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCarnes[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 7: { // Pescados y Mariscos
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasPescados) / sizeof(subcategoriasPescados[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[6]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloPescados = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaPescados = (anchoConsola - tituloPescados.length()) / 2;
				SetCursorPosition(posicionCentradaPescados, 2);
				cout << tituloPescados << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasPescados[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasPescados[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Pescados Congelados
					// TODO: Implementar navegación terciaria para Pescados Congelados
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasPescados[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Mariscos Congelados
					// TODO: Implementar navegación terciaria para Mariscos Congelados
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasPescados[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Frescos
					// TODO: Implementar navegación terciaria para Frescos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasPescados[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 8: { // Congelados
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasCongelados) / sizeof(subcategoriasCongelados[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[7]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloCongelados = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaCongelados = (anchoConsola - tituloCongelados.length()) / 2;
				SetCursorPosition(posicionCentradaCongelados, 2);
				cout << tituloCongelados << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasCongelados[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasCongelados[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Hamburguesas
					// TODO: Implementar navegación terciaria para Hamburguesas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCongelados[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Nuggets y Empanizados
					// TODO: Implementar navegación terciaria para Nuggets y Empanizados
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCongelados[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Frutas y Verduras Congeladas
					// TODO: Implementar navegación terciaria para Frutas y Verduras Congeladas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCongelados[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Helados
					// TODO: Implementar navegación terciaria para Helados
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCongelados[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Pizzas,Pastas y Bocaditos
					// TODO: Implementar navegación terciaria para Pizzas,Pastas y Bocaditos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCongelados[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 9: { // Panadería y Pastelería
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasPanaderia) / sizeof(subcategoriasPanaderia[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[8]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloPanaderia = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaPanaderia = (anchoConsola - tituloPanaderia.length()) / 2;
				SetCursorPosition(posicionCentradaPanaderia, 2);
				cout << tituloPanaderia << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasPanaderia[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasPanaderia[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Panes
					// TODO: Implementar navegación terciaria para Panes
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasPanaderia[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Kekes y Chifones
					// TODO: Implementar navegación terciaria para Kekes y Chifones
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasPanaderia[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Tostadas y Bocaditos
					// TODO: Implementar navegación terciaria para Tostadas y Bocaditos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasPanaderia[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Postres y Tortas
					// TODO: Implementar navegación terciaria para Postres y Tortas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasPanaderia[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 10: { // Dulces y Galletas
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasDulces) / sizeof(subcategoriasDulces[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[9]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloDulces = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaDulces = (anchoConsola - tituloDulces.length()) / 2;
				SetCursorPosition(posicionCentradaDulces, 2);
				cout << tituloDulces << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasDulces[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasDulces[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Galletas
					// TODO: Implementar navegación terciaria para Galletas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDulces[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Caramelos y Chupetes
					// TODO: Implementar navegación terciaria para Caramelos y Chupetes
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDulces[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Chocolates
					// TODO: Implementar navegación terciaria para Chocolates
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDulces[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Marshmallows y Gomitas
					// TODO: Implementar navegación terciaria para Marshmallows y Gomitas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasDulces[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 11: { // Snack y Frutos Secos
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasSnack) / sizeof(subcategoriasSnack[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[10]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloSnack = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaSnack = (anchoConsola - tituloSnack.length()) / 2;
				SetCursorPosition(posicionCentradaSnack, 2);
				cout << tituloSnack << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasSnack[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasSnack[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Frutos Secos
					// TODO: Implementar navegación terciaria para Frutos Secos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasSnack[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Snacks
					// TODO: Implementar navegación terciaria para Snacks
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasSnack[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 12: { // Cervezas
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasCervezas) / sizeof(subcategoriasCervezas[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[11]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloCervezas = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaCervezas = (anchoConsola - tituloCervezas.length()) / 2;
				SetCursorPosition(posicionCentradaCervezas, 2);
				cout << tituloCervezas << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasCervezas[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasCervezas[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Cervezas Nacionales
					// TODO: Implementar navegación terciaria para Cervezas Nacionales
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCervezas[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Cervezas Importadas
					// TODO: Implementar navegación terciaria para Cervezas Importadas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCervezas[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Cervezas Artesanales
					// TODO: Implementar navegación terciaria para Cervezas Artesanales
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCervezas[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 13: { // Bebidas Alcohólicas
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasBebidas) / sizeof(subcategoriasBebidas[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[12]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloBebidas = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaBebidas = (anchoConsola - tituloBebidas.length()) / 2;
				SetCursorPosition(posicionCentradaBebidas, 2);
				cout << tituloBebidas << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasBebidas[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasBebidas[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Vinos y Espumantes
					// TODO: Implementar navegación terciaria para Vinos y Espumantes
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Whisky
					// TODO: Implementar navegación terciaria para Whisky
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Ron
					// TODO: Implementar navegación terciaria para Ron
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Pisco
					// TODO: Implementar navegación terciaria para Pisco
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Vodka
					// TODO: Implementar navegación terciaria para Vodka
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 6) { // Tequila
					// TODO: Implementar navegación terciaria para Tequila
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[5] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 7) { // Gin
					// TODO: Implementar navegación terciaria para Gin
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[6] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 8) { // Ready To Drink
					// TODO: Implementar navegación terciaria para Ready To Drink
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebidas[7] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 14: { // Gaseosas, Aguas y Jugos
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasGaseosas) / sizeof(subcategoriasGaseosas[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[13]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloGaseosas = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaGaseosas = (anchoConsola - tituloGaseosas.length()) / 2;
				SetCursorPosition(posicionCentradaGaseosas, 2);
				cout << tituloGaseosas << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasGaseosas[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasGaseosas[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Aguas
					// TODO: Implementar navegación terciaria para Aguas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasGaseosas[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Energizantes y Rehidratantes
					// TODO: Implementar navegación terciaria para Energizantes y Rehidratantes
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasGaseosas[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Gaseosas
					// TODO: Implementar navegación terciaria para Gaseosas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasGaseosas[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Ginger Ale
					// TODO: Implementar navegación terciaria para Ginger Ale
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasGaseosas[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Jugos y Tés Líquidos
					// TODO: Implementar navegación terciaria para Jugos y Tés Líquidos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasGaseosas[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 15: { // Limpieza
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasLimpieza) / sizeof(subcategoriasLimpieza[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");

				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[14]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloLimpieza = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaLimpieza = (anchoConsola - tituloLimpieza.length()) / 2;
				SetCursorPosition(posicionCentradaLimpieza, 2);
				cout << tituloLimpieza << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasLimpieza[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasLimpieza[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}

			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Accesorios de Limpieza
					// TODO: Implementar navegación terciaria para Accesorios de Limpieza
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Ambientadores
					// TODO: Implementar navegación terciaria para Ambientadores
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Bolsas y Envolturas
					// TODO: Implementar navegación terciaria para Bolsas y Envolturas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Descartables
					// TODO: Implementar navegación terciaria para Descartables
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Detergente y Cuidado de la Ropa
					// TODO: Implementar navegación terciaria para Detergente y Cuidado de la Ropa
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 6) { // Encendido de Parrilla
					// TODO: Implementar navegación terciaria para Encendido de Parrilla
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[5] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 7) { // Lavavajillas
					// TODO: Implementar navegación terciaria para Lavavajillas
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[6] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 8) { // Lejía
					// TODO: Implementar navegación terciaria para Lejía
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[7] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 9) { // Limpiadores
					// TODO: Implementar navegación terciaria para Limpiadores
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[8] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 10) { // Para Calzado
					// TODO: Implementar navegación terciaria para Para Calzado
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[9] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 11) { // Papeles Higiénicos
					// TODO: Implementar navegación terciaria para Papeles Higiénicos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[10] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 12) { // Otros Papeles
					// TODO: Implementar navegación terciaria para Otros Papeles
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasLimpieza[11] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 16: { // Cuidado Personal
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasCuidado) / sizeof(subcategoriasCuidado[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");
	
				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[15]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloCuidado = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaCuidado = (anchoConsola - tituloCuidado.length()) / 2;
				SetCursorPosition(posicionCentradaCuidado, 2);
				cout << tituloCuidado << endl;
	
				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasCuidado[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasCuidado[i] << "  ";
					}
				}
	
				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}

				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}
	
			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Cuidado Capilar
					// TODO: Implementar navegación terciaria para Cuidado Capilar
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCuidado[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Jabones
					// TODO: Implementar navegación terciaria para Jabones
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCuidado[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Higiene Bucal
					// TODO: Implementar navegación terciaria para Higiene Bucal
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCuidado[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Cuidado Mujer
					// TODO: Implementar navegación terciaria para Cuidado Mujer
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCuidado[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 5) { // Cuidado Hombre
					// TODO: Implementar navegación terciaria para Cuidado Hombre
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCuidado[4] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 6) { // Incontinencia
					// TODO: Implementar navegación terciaria para Incontinencia
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCuidado[5] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 7) { // Salud y Bienestar
					// TODO: Implementar navegación terciaria para Salud y Bienestar
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasCuidado[6] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 17: { // Belleza
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasBelleza) / sizeof(subcategoriasBelleza[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;

			while (true) {
				// Limpiar pantalla
				system("cls");
	
				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[16]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloBelleza = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaBelleza = (anchoConsola - tituloBelleza.length()) / 2;
				SetCursorPosition(posicionCentradaBelleza, 2);
				cout << tituloBelleza << endl;
	
				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasBelleza[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasBelleza[i] << "  ";
					}
				}
	
				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}
	
				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);
	
				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}
			
			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Cremas Faciales
					// TODO: Implementar navegación terciaria para Cremas Faciales
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBelleza[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Cuidado del Rostro
					// TODO: Implementar navegación terciaria para Cuidado del Rostro
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBelleza[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Protección Solar
					// TODO: Implementar navegación terciaria para Protección Solar
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBelleza[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Perfumería
					// TODO: Implementar navegación terciaria para Perfumería
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBelleza[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 18: { // Bebés y Niños
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasBebes) / sizeof(subcategoriasBebes[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;
				
			while (true) {
				// Limpiar pantalla
				system("cls");
					
				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[17]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloBebes = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaBebes = (anchoConsola - tituloBebes.length()) / 2;
				SetCursorPosition(posicionCentradaBebes, 2);
				cout << tituloBebes << endl;

				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasBebes[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasBebes[i] << "  ";
					}
				}

				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}
		
				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);

				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}
			
			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Pañales
					// TODO: Implementar navegación terciaria para Pañales
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebes[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Aseo del Bebé
					// TODO: Implementar navegación terciaria para Aseo del Bebé
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebes[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Alimentos para Bebés
					// TODO: Implementar navegación terciaria para Alimentos para Bebés
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasBebes[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
		case 19: { // Mundo Mascotas
			// Variables para la navegación de subcategorías
			int seleccionSubcategoria = 0;
			int nSub = sizeof(subcategoriasMascotas) / sizeof(subcategoriasMascotas[0]);
			int maxSeleccionSubcategoria = nSub + 1; // +1 para incluir la opción "Salir"
			AccionTecla accionSubcategoria = NINGUNA;
			int subopcion = -1;
	
			while (true) {
				// Limpiar pantalla
				system("cls");
	
				// Mostrar título centrado para la categoría principal
				SetForegroundColor(Green);
				// Convertir a mayúsculas
				string categoriaprincipal = string(categoriasPrincipales[18]);
				transform(categoriaprincipal.begin(), categoriaprincipal.end(), categoriaprincipal.begin(), ::toupper);
				string tituloMascotas = "====== " + categoriaprincipal + " ======";
				int anchoConsola = GetConsoleWidth();
				int posicionCentradaMascotas = (anchoConsola - tituloMascotas.length()) / 2;
				SetCursorPosition(posicionCentradaMascotas, 2);
				cout << tituloMascotas << endl;
				
				// Mostrar las subcategorías con navegación por flechas
				SetForegroundColor(BrightWhite);
				for (int i = 0; i < nSub; ++i) {
					SetCursorPosition(24, 6 + i);
					if (seleccionSubcategoria == i) {
						setColor(0, 15); // Fondo blanco, texto negro para la selección
						cout << "> - " << subcategoriasMascotas[i] << " <";
						setColor(15, 0); // Volver a colores normales
					}
					else {
						cout << "  - " << subcategoriasMascotas[i] << "  ";
					}
				}
	
				// Mostrar opción de salir
				SetCursorPosition(24, 6 + nSub + 2);
				if (seleccionSubcategoria == nSub) {
					setColor(0, 15);
					cout << "> - Volver al Menu Anterior <";
					setColor(15, 0);
				}
				else {
					cout << "  - Volver al Menu Anterior  ";
				}
				
				// Esperar entrada del usuario
				accionSubcategoria = navegarConFlechas(seleccionSubcategoria, maxSeleccionSubcategoria);
	
				// Si el usuario selecciona una opción
				if (accionSubcategoria == SELECCIONAR) {
					if (seleccionSubcategoria == nSub) { // Si seleccionó "Volver al Menu Anterior"
						SetCursorPosition(24, 9 + nSub + 2);
						cout << "VOLVIENDO AL MENU ANTERIOR...";
						Sleep(500);
						system("cls");
						break; // Salir del bucle de subcategorías
					}
					else {
						subopcion = seleccionSubcategoria + 1; // Las opciones van de 1 a n
						break; // Salir del bucle para procesar la opción
					}
				}
			}
	
			// Solo procesar si se seleccionó una subcategoría válida
			if (subopcion > 0 && subopcion <= nSub) {
				if (subopcion == 1) { // Perros
					// TODO: Implementar navegación terciaria para Perros
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasMascotas[0] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 2) { // Gatos
					// TODO: Implementar navegación terciaria para Gatos
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasMascotas[1] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 3) { // Higiene
					// TODO: Implementar navegación terciaria para Higiene
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasMascotas[2] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
				else if (subopcion == 4) { // Accesorios
					// TODO: Implementar navegación terciaria para Accesorios
					system("cls");
					cout << "\n\t\t\t-- Subcategoría: " << subcategoriasMascotas[3] << " --" << endl;
					cout << "\t\t\t(En desarrollo)" << endl;
					system("pause>0");
				}
			}
			break;
		}
	}
	return Categoria();
}
