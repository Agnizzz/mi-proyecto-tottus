#pragma once
#include <iostream>
#include <conio.h>
#include "Utilidades.h"
#include "Soporte.h"
#include "Producto.h"
#include "Cliente.h"
#include "Administrador.h"
#include "Usuario.h"

using namespace std;

SistemaAdministradores* sistemaAdmins = new SistemaAdministradores();

SistemaUsuarios* sistemaUsuarios = new SistemaUsuarios();

void Tienda() {
	SetBackgroundColor(Black);
	system("cls");
	while (true) {
		const int FILAS = 8;
		const int COLUMNAS = 63;
		int producto[FILAS][COLUMNAS] = {
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
		{1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1},
		};
		int ancho = GetConsoleWidth();
		int alto = GetConsoleHeight();
		int posicionX = (ancho - COLUMNAS) / 2;
		int posicionY = 2;
		for (int f = 0; f < FILAS; f++) {
			SetCursorPosition(posicionX, posicionY + f);
			for (int c = 0; c < COLUMNAS; c++) {
				if (producto[f][c] == 1) {
					SetForegroundColor(Green);
					cout << (char)219;
				}
				else {
					cout << ' ';
				}
			}
		}
		int opcion;
		SetForegroundColor(BrightWhite);
		cout << "\n\n\n\n\t\t\t1. Ver Catalogo por Categorias\n";
		// Muestra una lista de las categorías de productos para que el cliente elija
		cout << "\n\t\t\t2. Buscar un Producto\n";
		// a. Buscar producto por ID // b. Buscar producto por nombre // c. Buscar producto por rango de precio // 0. Volver al menú anterior
		cout << "\n\t\t\t3. Ver Promociones Vigentes\n";
		// Muestra una lista de las ofertas activas. Al seleccionar una, puede que se listen los productos participantes, permitiendo al cliente agregarlos al carrito desde allí.
		cout << "\n\t\t\t0. Volver al Menu Principal\n";
		cout << "\n\t\t\tSeleccione una opcion: ";
		cin >> opcion;
		if (opcion < 0 || opcion > 3) {
			cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            _getch();
			system("cls");
			continue;
		}
		if (opcion == 0) {
			cout << "\n\t\t\tVOLVIENDO AL MENU PRINCIPAL..." << endl;
            Sleep(500);
			break;
		}
		if (opcion == 1) {
		}
		if (opcion == 2) {
		}
		if (opcion == 3) {
		}
	}
}

void Carrito() {
	SetBackgroundColor(Black);
	system("cls");
	while (true) {
		const int FILAS = 8;
		const int COLUMNAS = 74;
		int carrito[FILAS][COLUMNAS] = {
		{0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0},
        {1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
        {1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0},
		};
		int ancho = GetConsoleWidth();
		int alto = GetConsoleHeight();
		int posicionX = (ancho - COLUMNAS) / 2;
		int posicionY = 2;
		for (int f = 0; f < FILAS; f++) {
			SetCursorPosition(posicionX, posicionY + f);
			for (int c = 0; c < COLUMNAS; c++) {
				if (carrito[f][c] == 1) {
                    SetForegroundColor(Blue);
					cout << (char)219;
				}
				else {
					cout << ' ';
				}
			}
		}
		int opcion;
		SetForegroundColor(BrightWhite);
		/*== Mi Carrito de Compras ==

			-----------------------------------------------------------------------
			ID  | Producto                  | Cant. | P. Unit. | Subtotal
			-----------------------------------------------------------------------
			P001| Leche Fresca UHT 1L       |   2   | S/ 5.50  | S/ 11.00
			P005| Yogurt de Fresa 1L        |   1   | S/ 8.20  | S/  8.20
			-----------------------------------------------------------------------
			(Se podrían mostrar promociones aplicadas aquí)
																Total Estimado: S/ 19.20

			Opciones:
			1. Modificar Cantidad de un producto
			2. Eliminar un producto del carrito
			3. Proceder al Pago / Finalizar Compra
			4. Vaciar Carrito por completo
			5. Seguir Comprando (Volver a la Tienda)
			0. Volver al Menú Principal

			Seleccione una opción:*/
		cout << "\n\n\n\n\t\t\t1. Modificar Cantidad de un producto\n";
		// Pide el ID del producto y la nueva cantidad deseada
		cout << "\n\t\t\t2. Eliminar un producto del carrito\n";
		// Pide el ID del producto a retirar del carrito
		cout << "\n\t\t\t3. Proceder al Pago / Finalizar Compra\n";
		// Se muestra un resumen final y se pide confirmación
		// Se simula la elección de un método de pago
		// Al confirmar, el sistema procesa la compra : se genera la boleta, se actualiza el stock de los productos, y se vacía el carrito
		cout << "\n\t\t\t4. Vaciar Carrito\n";
		//Al seleccionarla, pide una confirmación para evitar acciones accidentales :

		//¿Está seguro de que desea eliminar todos los productos de su carrito ? (S / N) :

		//Si se confirma, el carrito se vacía y se muestra el mensaje : "Su carrito de compras ha sido vaciado."
		cout << "\n\t\t\t5. Seguir Comprando\n";
		// Al seleccionar esa opción, la aplicación lo saca de la vista del carrito y lo lleva directamente al menú principal del módulo TIENDA
		cout << "\n\t\t\t0. Volver al Menu Principal\n";
		cout << "\n\t\t\tSeleccione una opcion: ";
		cin >> opcion;
		if (opcion < 0 || opcion > 5) {
			cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
			_getch();
			system("cls");
			continue;
		}
		if (opcion == 0) {
			cout << "\n\t\t\tVOLVIENDO AL MENU PRINCIPAL..." << endl;
            Sleep(500);
			break;
		}
		if (opcion == 1) {
		}
		if (opcion == 2) {
		}
		if (opcion == 3) {
		}
        if (opcion == 4) {
		}
        if (opcion == 5) {
		}
	}
}

void RegistroUsuario() {
    SetBackgroundColor(Black);
    system("cls");
    while (true) {
        const int FILAS = 8;
        const int COLUMNAS = 86;
        int registrouser[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1},
        {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0},
        };
        int ancho = GetConsoleWidth();
        int alto = GetConsoleHeight();
        int posicionX = (ancho - COLUMNAS) / 2;
        int posicionY = 2;
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, posicionY + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (registrouser[f][c] == 1) {
                    SetForegroundColor(Red);
                    cout << (char)219;
                }
                else {
                    cout << ' ';
                }
            }
        }
        int opcion;
        SetForegroundColor(BrightWhite);
        cout << "\n\n\n\n\t\t\t1. Ver mi Ultima Boleta Generada\n";
		// Muestra la última boleta generada por el usuario, con detalles de los productos comprados, cantidades y precios.
        cout << "\n\t\t\t2. Ver Lista Completa de Mis Boletas\n";
		// Al seleccionar esta opción, el sistema muestra un listado paginado de todas las boletas del cliente, ordenadas por fecha.
		//Desde esta lista, el cliente puede ingresar el ID de una boleta para ver su detalle completo(productos, montos, fecha, etc.).
        cout << "\n\t\t\t3. Buscar una Boleta Especifica\n";
		// a. Buscar por Número de Boleta // b. Buscar por Rango de Fechas // 0. Volver
        cout << "\n\t\t\t0. Volver al Menu Principal\n";
        cout << "\n\t\t\tSeleccione una opcion: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 3) {
            cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
			_getch();
			system("cls");
            continue;
        }
        if (opcion == 0) {
            cout << "\n\t\t\tVOLVIENDO AL MENU PRINCIPAL..." << endl;
            Sleep(500);
            break;
        }
        if (opcion == 1) {
        }
        if (opcion == 2) {
        }
		if (opcion == 3) {
		}
    }
}

void SoporteUsuario() {
	SetBackgroundColor(Black);
	system("cls");
    while (true) {
        const int FILAS = 8;
        const int COLUMNAS = 76;
        int soporteuser[FILAS][COLUMNAS] = {
            {0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0},
            {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0},
            {1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
            {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
            {0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
            {0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
        };
        int ancho = GetConsoleWidth();
        int alto = GetConsoleHeight();
        int posicionX = (ancho - COLUMNAS) / 2;
        int posicionY = 2;
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, posicionY + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (soporteuser[f][c] == 1) {
                    SetForegroundColor(Magenta);
                    cout << (char)219;
                }
                else {
                    cout << ' ';
                }
            }
        }
        int opcion;
        SetForegroundColor(BrightWhite);
        /*== Módulo de Soporte y Ayuda ==
            ¿En qué podemos ayudarle, [Nombre del Cliente]?

            1. Enviar Nueva Solicitud (Reclamo, Consulta, etc.)
            2. Consultar el Estado de Mis Solicitudes
            3. Ver Preguntas Frecuentes (FAQ)
            0. Volver al Menú Principal

            Seleccione una opción:*/
        cout << "\n\n\n\n\t\t\t1. Enviar Nueva Solicitud\n";
        // Inicia el proceso para crear un nuevo ticket de soporte. Le pedirá que seleccione el tipo de solicitud (Reclamo, Consulta, Sugerencia) y que describa su caso. Al finalizar, le entregará un número de ticket.
        cout << "\n\t\t\t2. Consultar el Estado de Mis Solicitudes\n";
        // Muestra una lista de todos los tickets de soporte que el cliente ha creado, indicando su estado actual ("Nuevo", "En Proceso", "Resuelto", etc.).
        // Desde esta lista, el cliente puede seleccionar un ticket para ver el historial completo de la conversación y, si el ticket está abierto, añadir un nuevo mensaje.
        cout << "\n\t\t\t3. Ver Preguntas Frecuentes\n";
        // Le da acceso a la base de conocimiento para que pueda resolver dudas comunes por su cuenta, consultando una lista de preguntas y respuestas predefinidas por el administrador.
        cout << "\n\t\t\t0. Volver al Menu Principal\n";
        cout << "\n\t\t\tSeleccione una opcion: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 3) {
            cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            _getch();
            system("cls");
            continue;
        }
        if (opcion == 0) {
            cout << "\n\t\t\tVOLVIENDO AL MENU PRINCIPAL..." << endl;
            Sleep(500);
            break;
        }
        if (opcion == 1) {
        }
        if (opcion == 2) {
        }
        if (opcion == 3) {
        }
    }
}

void Producto() {
    SetBackgroundColor(Black);
    system("cls");
    while (true) {
        const int FILAS = 8;
        const int COLUMNAS = 86;
        int producto[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
        {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0},
        };
        int ancho = GetConsoleWidth();
        int alto = GetConsoleHeight();
        int posicionX = (ancho - COLUMNAS) / 2;
        int posicionY = 2;
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, posicionY + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (producto[f][c] == 1) {
                    SetForegroundColor(Green);
                    cout << (char)219;
                }
                else {
                    cout << ' ';
                }
            }
        }
        int opcion;
        SetForegroundColor(BrightWhite);
		cout << "\n\n\n\n\t\t\t1. Gestion de Productos\n";
    	// a. Agregar Nuevo Producto // b. Buscar y Modificar Producto // c. Eliminar Producto // d. Ordenar Producto // e. Listar Todos los Productos // 0. Volver al menú anterior
		cout << "\n\t\t\t2. Gestion de Categorias\n";
        // a. Agregar Nueva Categoría // b. Modificar Nombre de Categoría // c. Eliminar Categoría // d. Listar Todas las Categorías // 0. Volver al menú anterior
        cout << "\n\t\t\t3. Gestion de Proveedores\n";
		// a. Agregar Nuevo Proveedor // b. Modificar Datos de Proveedor // c. Eliminar Proveedor // d. Listar Todos los Proveedores // 0. Volver al menú anterior
        cout << "\n\t\t\t4. Consultar Inventario General\n";
		// a. Ver Inventario Completo (Listar todos los productos con su stock) // b. Ver Productos con Bajo Stock (ej. menos de 10 unidades) // c. Ver Productos sin Stock (Agotados) // 0. Volver al menú anterior
		cout << "\n\t\t\t0. Volver al Panel de Administracion\n";
        cout << "\n\t\t\tSeleccione una opcion: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 4) {
            cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            _getch();
            system("cls");
            continue;
        }
        if (opcion == 0) {
            cout << "\n\t\t\tVOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
            Sleep(500);
            break;
        }
        if (opcion == 1) {
			//categorias();
        }
        if (opcion == 2) {
            //funcionesProducto();
        }
        if (opcion == 3) {
            //buscarProductos();
        }
        if (opcion == 4) {
            //ordenarProductos();
        }
    }
}

void Gestion() {
    SetBackgroundColor(Black);
    system("cls");
    while (true) {
        const int FILAS = 8;
        const int COLUMNAS = 75;
        int gestion[FILAS][COLUMNAS] = {
        {0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1},
        {1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,1,1},
        {1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,1,1,1,1,1},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,1,1,1},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1},
        };
        int ancho = GetConsoleWidth();
        int alto = GetConsoleHeight();
        int posicionX = (ancho - COLUMNAS) / 2;
        int posicionY = 2;
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, posicionY + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (gestion[f][c] == 1) {
                    SetForegroundColor(Blue);
                    cout << (char)219;
                }
                else {
                    cout << ' ';
                }
            }
        }
        int opcion;
        SetForegroundColor(BrightWhite);
		cout << "\n\n\n\n\t\t\t1. Gestion de Cuentas de Usuario\n";
		// a.Buscar y Modificar Cuenta // b.Eliminar Cuenta // c.Listar Todas las Cuentas // 0. Volver al menú anterior
		cout << "\n\t\t\t2. Gestion de Promociones\n";
		// a. Crear Nueva Promoción // b. Modificar Promoción Existente // c. Activar / Desactivar Promoción // d. Listar Todas las Promociones // 0. Volver al menú anterior
		cout << "\n\t\t\t3. Generar Reportes del Sistema\n";
		// a. Reporte de Usuarios // b. Reporte de Actividad de Promociones // c. Reporte Resumido de Inventario // 0. Volver al menú anterior
        cout << "\n\t\t\t0. Volver al Panel de Administracion\n";
        cout << "\n\t\t\tSeleccione una opcion: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 3) {
            cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            _getch();
            system("cls");
            continue;
        }
        if (opcion == 0) {
            cout << "\n\t\t\tVOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
            Sleep(500);
            break;
        }
		if (opcion == 1) {
			//comprar();
		}
		if (opcion == 2) {
			//verCarrito();
		}
		if (opcion == 3) {
			//eliminarProducto();
		}
    }
}

void RegistroAdministrador() {
	SetBackgroundColor(Black);
	system("cls");
    while (true) {
		const int FILAS = 8;
		const int COLUMNAS = 86;
		int registroadmin[FILAS][COLUMNAS] = {
		{1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
		{1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1},
		{1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1},
		{1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0},
		};
		int ancho = GetConsoleWidth();
		int alto = GetConsoleHeight();
		int posicionX = (ancho - COLUMNAS) / 2;
		int posicionY = 2;
		for (int f = 0; f < FILAS; f++) {
			SetCursorPosition(posicionX, posicionY + f);
			for (int c = 0; c < COLUMNAS; c++) {
				if (registroadmin[f][c] == 1) {
					SetForegroundColor(Red);
					cout << (char)219;
				}
				else {
					cout << ' ';
				}
			}
		}
		int opcion;
		SetForegroundColor(BrightWhite);;
		cout << "\n\n\n\n\t\t\t1. Busqueda Avanzada de Boletas\n";
		// ¿Por qué criterio desea buscar ?
			// a. Por Número de Boleta exacto
			// b. Por Rango de Fechas
			// c. Por DNI o Usuario del Cliente
			// d. Por Rango de Monto Total
			// e. Por Estado de la Boleta(Ej : Pagada, Anulada, Pendiente)
			// 0. Volver
		cout << "\n\t\t\t2. Listar Ultimas Boletas Generadas\n";
        // Al seleccionar esta opción, el sistema muestra una lista paginada de las últimas N transacciones
		cout << "\n\t\t\t3. Gestion de Boletas Pendientes\n";
		// Al entrar, se listan todas las boletas que requieren una acción administrativa para continuar su ciclo de vida.
        // El administrador puede seleccionar una boleta y actualizar su estado, lo que movería la boleta fuera de esta lista de pendientes.
		cout << "\n\t\t\t4. Generar Reportes de Ventas\n";
		// a. Reporte de Ventas Totales por Período // b. Reporte de Productos Más Vendidos(Top N) // c.Reporte de Ventas por Categoría de Producto // d. Reporte de Rendimiento de Clientes // 0. Volver
		cout << "\n\t\t\t0. Volver al Panel de Administracion\n";
		cout << "\n\t\t\tSeleccione una opcion: ";
		cin >> opcion;
		if (opcion < 0 || opcion > 4) {
			cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            _getch();
			system("cls");
			continue;
		}
		if (opcion == 0) {
			cout << "\n\t\t\tVOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
            Sleep(500);
			break;
		}
		if (opcion == 1) {
		}
		if (opcion == 2) {
		}
		if (opcion == 3) {
		}
        if (opcion == 4) {
        }
	}
}

void SoporteAdministrador() {
	SetBackgroundColor(Black);
	system("cls");
    while (true) {
        const int FILAS = 8;
        const int COLUMNAS = 76;
        int soporteadmin[FILAS][COLUMNAS] = {
            {0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0},
            {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0},
            {1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
            {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
            {0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
            {0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
            {1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0},
        };
        int ancho = GetConsoleWidth();
        int alto = GetConsoleHeight();
        int posicionX = (ancho - COLUMNAS) / 2;
        int posicionY = 2;
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, posicionY + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (soporteadmin[f][c] == 1) {
                    SetForegroundColor(Magenta);
                    cout << (char)219;
                }
                else {
                    cout << ' ';
                }
            }
        }
		int opcion;
		SetForegroundColor(BrightWhite);
		cout << "\n\n\n\n\t\t\t1. Dashboard de Tickets\n"; // Ver y Filtrar
		/* --Dashboard de Tickets --
			Filtro Actual : [Tickets Nuevos y Abiertos]

			ID Ticket | Cliente | Asunto | Estado | Fecha
			------------------------------------------------------------------------------ -
			T - 0015 | Ana Torres | Producto defectuoso | Nuevo | 2025 - 07 - 04
			T - 0014 | Luis Rojas | Duda sobre devolución | Abierto | 2025 - 07 - 03
			T - 0012 | Carlos Vera | No llegó mi pedido | Abierto | 2025 - 07 - 02
			------------------------------------------------------------------------------ -
			[Pág. 1 de 2]

			Opciones:
			a.Filtrar por Estado(Nuevos, Abiertos, En Proceso, Resueltos, etc.)
			b.Buscar por ID de Ticket o DNI de Cliente
			c.Ver detalle de un Ticket(ingresando su ID)
			0. Volver

			Opción :*/
		cout << "\n\t\t\t2. Gestionar un Ticket Especifico\n";
		// Primero, el sistema pide el ID del ticket a gestionar
        // Una vez encontrado el ticket, se muestra toda su información detallada y un menú de acciones.
		/* == Detalle del Ticket T-0015 ==
			Cliente: Ana Torres (DNI: 87654321)
			Fecha: 2025-07-04
			Asunto: Producto defectuoso
			Descripción: "Compré una licuadora ayer y no enciende..."
			Estado Actual: Nuevo

			-- Historial de Comunicaciones --
			[2025-07-04 10:30] Cliente: "Compré una licuadora ayer y no enciende..."
			-----------------------------------

			Acciones Disponibles:
			1. Enviar Respuesta al Cliente
			2. Agregar Nota Interna (no visible para el cliente)
			3. Cambiar Estado del Ticket
			4. Asignar Ticket a un Responsable (si aplica)
			0. Volver al Dashboard

			Opción:*/
		cout << "\n\t\t\t3. Gestion de la Base de Conocimiento\n"; // FAQ
		// a. Agregar Nuevo Artículo de FAQ // b. Modificar Artículo Existente // c. Eliminar Artículo // d. Listar Todos los Artículos //0. Volver
		cout << "\n\t\t\t4. Ver Estadisticas de Soporte\n";
		// Al seleccionar esta opción, se muestra un reporte consolidado
		/* == Estadísticas del Módulo de Soporte ==
			Fecha del Reporte: 2025-07-04

			-- Tickets por Estado --
			Nuevos:                  5
			Abiertos:                12
			En Proceso:              8
			Esperando Respuesta:     2
			Resueltos (últimos 7 días): 25
			Total Abiertos:          27

			-- Rendimiento (Datos de ejemplo) --
			Tiempo Promedio de Primera Respuesta: 4 horas
			Tiempo Promedio de Resolución:        28 horas

			-- Solicitudes por Tipo (últimos 30 días) --
			Reclamos:                45%
			Consultas:               35%
			Sugerencias:             15%
			Problemas Técnicos:      5%
			-------------------------------------------------
			(0) Volver*/
		cout << "\n\t\t\t0. Volver al Panel de Administracion\n";
		cout << "\n\t\t\tSeleccione una opcion: ";
		cin >> opcion;
		if (opcion < 0 || opcion > 4) {
			cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            _getch();
			system("cls");
			continue;
		}
		if (opcion == 0) {
			cout << "\n\t\t\tVOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
            Sleep(500);
			break;
		}
		if (opcion == 1) {
		}
		if (opcion == 2) {
		}
		if (opcion == 3) {
		}
		if (opcion == 4) {
		}
	}
}

void Salir() {
    SetBackgroundColor(Black);
    system("cls");
    const int FILAS = 18;
    const int COLUMNAS = 74;
    int salir[FILAS][COLUMNAS] = {
		{0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0},
        {1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0},
        {1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0},
    };
    int ancho = GetConsoleWidth();
    int alto = GetConsoleHeight();
    int posicionX = (ancho - COLUMNAS) / 2;
    int posicionY = (alto - FILAS) / 2;
    for (int f = 0; f < FILAS; f++) {
        SetCursorPosition(posicionX, posicionY + f);
        for (int c = 0; c < COLUMNAS; c++) {
            if (salir[f][c] == 1) {
                SetForegroundColor(LightCyan);
                cout << (char)219;
            }
            else {
                cout << ' ';
            }
        }
    }
    Sleep(2000);
    exit(0);
}

bool Usuario() {
    SetBackgroundColor(Black);
    system("cls");
    const int FILAS = 40;
    const int COLUMNAS = 160;
    int usuario[FILAS][COLUMNAS] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,6,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0},
        {0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0},
        {0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,7,2,2,2,2,2,2,2,2,2,2,7,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    const int FILAS_OPCION = 9;
    const int COLUMNAS_OPCION = 29;
    int opcion[FILAS_OPCION][COLUMNAS_OPCION] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    static int posicionX = 8;
    const int posicionY = 29;
    static int prevPosX = posicionX;
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            if (usuario[f][c] == 4) {
                SetForegroundColor(LightYellow);
                SetCursorPosition(c, f);
                cout << (char)220;
                continue;
            }
            if (usuario[f][c] == 6) {
                SetForegroundColor(Green);
                SetCursorPosition(c, f);
                cout << (char)220;
                continue;
            }
            if (usuario[f][c] == 8) {
                SetForegroundColor(LightGreen);
                SetCursorPosition(c, f);
                cout << (char)220;
                continue;
            }
            if (usuario[f][c] == 5) {
                SetForegroundColor(LightYellow);
                SetCursorPosition(c, f);
                cout << (char)223;
                continue;
            }
            if (usuario[f][c] == 7) {
                SetForegroundColor(Green);
                SetCursorPosition(c, f);
                cout << (char)223;
                continue;
            }
            if (usuario[f][c] == 9) {
                SetForegroundColor(LightGreen);
                SetCursorPosition(c, f);
                cout << (char)223;
                continue;
            }
            if (usuario[f][c] == 0) SetForegroundColor(Black);
            else if (usuario[f][c] == 1) SetForegroundColor(LightGreen);
            else if (usuario[f][c] == 2) SetForegroundColor(Green);
            else if (usuario[f][c] == 3) SetForegroundColor(LightYellow);
            else SetForegroundColor(Black);

            SetCursorPosition(c, f);
            cout << (char)219;
        }
    }
    for (int f = 0; f < FILAS_OPCION; f++) {
        for (int c = 0; c < COLUMNAS_OPCION; c++) {
            if (opcion[f][c] == 5) {
                SetForegroundColor(Green);
                SetCursorPosition(posicionX + c, posicionY + f);
                cout << (char)219;
            }
        }
    }
    bool running = true;
    while (running) {
        if (_kbhit()) {
            int key = _getch();

            if (key == 224) {
                key = _getch();
                int limite_derecho = COLUMNAS - COLUMNAS_OPCION - 7;

                if (key == 75) {
                    prevPosX = posicionX;
                    posicionX -= 29;
                    if (posicionX < 8) {
                        posicionX = limite_derecho;
                    }
                }
                else if (key == 77) {
                    prevPosX = posicionX;
                    posicionX += 29;
                    if (posicionX > limite_derecho) {
                        posicionX = 8;
                    }
                }
            }
            else if (key == '\r') {
                if (posicionX == 8) {
                    Tienda();
                    system("cls");
                    Usuario();
                    return true;
                }
                else if (posicionX == 37) {
                    Carrito();
					system("cls");
					Usuario();
                    return true;
                }
                else if (posicionX == 66) {
                    RegistroUsuario();
					system("cls");
					Usuario();
                    return true;
                }
                else if (posicionX == 95) {
                    SoporteUsuario();
					system("cls");
					Usuario();
                    return true;
                }
				else if (posicionX == 124) {
					// Para el menú de Usuario
					SetBackgroundColor(Black);
					SetForegroundColor(BrightWhite);

					// Centrar el mensaje en la fila 39
					int ancho = GetConsoleWidth();
					string mensaje = "­Esta seguro que desea cerrar sesion? (s/n): ";
					int posX = (ancho - mensaje.length()) / 2;

					SetCursorPosition(posX, 39);
					cout << mensaje;

					char respuesta;
					cin >> respuesta;

					if (respuesta == 's' || respuesta == 'S') {
						sistemaUsuarios->cerrarSesion();
						system("cls");
						if (sistemaUsuarios->SubMenuUsuario()) {
							Usuario(); // Solo ejecuta la función Usuario() si la autenticación fue exitosa
						}
						return true;
					}
					// Si responde "n", simplemente continúa en la sesión actual
					system("cls");
					Usuario();
					return true;
				}
            }
            if (prevPosX != posicionX) {
                for (int f = 0; f < FILAS_OPCION; f++) {
                    for (int c = 0; c < COLUMNAS_OPCION; c++) {
                        if (opcion[f][c] == 5) {
                            int x = prevPosX + c;
                            int y = posicionY + f;
                            if (usuario[y][x] == 0) SetForegroundColor(Black);
                            else if (usuario[f][c] == 1) SetForegroundColor(LightYellow);
                            else SetForegroundColor(LightYellow);

                            SetCursorPosition(x, y);
                            cout << (char)219;
                        }
                    }
                }
                for (int f = 0; f < FILAS_OPCION; f++) {
                    for (int c = 0; c < COLUMNAS_OPCION; c++) {
                        if (opcion[f][c] == 5) {
                            SetForegroundColor(Green);
                            SetCursorPosition(posicionX + c, posicionY + f);
                            cout << (char)219;
                        }
                    }
                }
            }
        }
        SetBackgroundColor(LightYellow);
        SetForegroundColor(Black);
        SetCursorPosition(20, 33); cout << "TIENDA";
        SetCursorPosition(48, 33); cout << "CARRITO";
        SetCursorPosition(77, 33); cout << "REGISTRO";
        SetCursorPosition(106, 33); cout << "SOPORTE";
        SetCursorPosition(132, 33); cout << "CERRAR SESION";
        Sleep(50);
    }
}

bool Administrador() {
    const int FILAS = 40;
    const int COLUMNAS = 160;
    int administrador[FILAS][COLUMNAS] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,6,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,8,1,1,1,1,1,1,8,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,4,0,0,0,0,0,0},
        {0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,0,0},
        {0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,5,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,7,2,2,2,2,2,2,2,2,2,2,7,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,9,1,1,1,1,1,1,9,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    const int FILAS_OPCION = 9;
    const int COLUMNAS_OPCION = 29;
    int opcion[FILAS_OPCION][COLUMNAS_OPCION] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    static int posicionX = 8;
    const int posicionY = 29;
    static int prevPosX = posicionX;
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            if (administrador[f][c] == 4) {
                SetForegroundColor(LightYellow);
                SetCursorPosition(c, f);
                cout << (char)220;
                continue;
            }
            if (administrador[f][c] == 6) {
                SetForegroundColor(Green);
                SetCursorPosition(c, f);
                cout << (char)220;
                continue;
            }
            if (administrador[f][c] == 8) {
                SetForegroundColor(LightGreen);
                SetCursorPosition(c, f);
                cout << (char)220;
                continue;
            }
            if (administrador[f][c] == 5) {
                SetForegroundColor(LightYellow);
                SetCursorPosition(c, f);
                cout << (char)223;
                continue;
            }
            if (administrador[f][c] == 7) {
                SetForegroundColor(Green);
                SetCursorPosition(c, f);
                cout << (char)223;
                continue;
            }
            if (administrador[f][c] == 9) {
                SetForegroundColor(LightGreen);
                SetCursorPosition(c, f);
                cout << (char)223;
                continue;
            }
            if (administrador[f][c] == 0) SetForegroundColor(Black);
            else if (administrador[f][c] == 1) SetForegroundColor(LightGreen);
            else if (administrador[f][c] == 2) SetForegroundColor(Green);
            else if (administrador[f][c] == 3) SetForegroundColor(LightYellow);
            else SetForegroundColor(Black);

            SetCursorPosition(c, f);
            cout << (char)219;
        }
    }
    for (int f = 0; f < FILAS_OPCION; f++) {
        for (int c = 0; c < COLUMNAS_OPCION; c++) {
            if (opcion[f][c] == 5) {
                SetForegroundColor(Green);
                SetCursorPosition(posicionX + c, posicionY + f);
                cout << (char)219;
            }
        }
    }
    bool running = true;
    while (running) {
        if (_kbhit()) {
            int key = _getch();

            if (key == 224) {
                key = _getch();
                int limite_derecho = COLUMNAS - COLUMNAS_OPCION - 7;

                if (key == 75) {
                    prevPosX = posicionX;
                    posicionX -= 29;
                    if (posicionX < 8) {
                        posicionX = limite_derecho;
                    }
                }
                else if (key == 77) {
                    prevPosX = posicionX;
                    posicionX += 29;
                    if (posicionX > limite_derecho) {
                        posicionX = 8;
                    }
                }
            }
            else if (key == '\r') {
                if (posicionX == 8) {
                    Producto();
                    system("cls");
					Administrador();
                    return true;
                }
                else if (posicionX == 37) {
                    Gestion();
					system("cls");
					Administrador();
                    return true;
                }
                else if (posicionX == 66) {
                    RegistroAdministrador();
					system("cls");
					Administrador();
                    return true;
                }
                else if (posicionX == 95) {
                    SoporteAdministrador();
					system("cls");
					Administrador();
                    return true;
                }
				else if (posicionX == 124) {
					// Para el menú de Administrador
					SetBackgroundColor(Black);
					SetForegroundColor(BrightWhite);

					// Centrar el mensaje en la fila 39
					int ancho = GetConsoleWidth();
                    string mensaje = "­Esta seguro que desea cerrar sesion? (s/n): ";
					int posX = (ancho - mensaje.length()) / 2;

					SetCursorPosition(posX, 39);
					cout << mensaje;

					char respuesta;
					cin >> respuesta;

					if (respuesta == 's' || respuesta == 'S') {
						sistemaAdmins->cerrarSesion();
						system("cls");
						if (sistemaAdmins->iniciarSesion()) {
							Administrador(); // Solo ejecuta la función si la autenticación fue exitosa
						}
						return true;
					}
					// Si responde "n", simplemente continúa en la sesión actual
					system("cls");
					Administrador();
					return true;
				}
            }
            if (prevPosX != posicionX) {
                for (int f = 0; f < FILAS_OPCION; f++) {
                    for (int c = 0; c < COLUMNAS_OPCION; c++) {
                        if (opcion[f][c] == 5) {
                            int x = prevPosX + c;
                            int y = posicionY + f;
                            if (administrador[y][x] == 0) SetForegroundColor(Black);
                            else if (administrador[f][c] == 1) SetForegroundColor(LightYellow);
                            else SetForegroundColor(LightYellow);

                            SetCursorPosition(x, y);
                            cout << (char)219;
                        }
                    }
                }
                for (int f = 0; f < FILAS_OPCION; f++) {
                    for (int c = 0; c < COLUMNAS_OPCION; c++) {
                        if (opcion[f][c] == 5) {
                            SetForegroundColor(Green);
                            SetCursorPosition(posicionX + c, posicionY + f);
                            cout << (char)219;
                        }
                    }
                }
            }
        }
        SetBackgroundColor(LightYellow);
        SetForegroundColor(Black);
        SetCursorPosition(17, 33); cout << "PRODUCTOS";
        SetCursorPosition(48, 33); cout << "GESTION";
        SetCursorPosition(77, 33); cout << "REGISTRO";
        SetCursorPosition(106, 33); cout << "SOPORTE";
        SetCursorPosition(132, 33); cout << "CERRAR SESION";
        Sleep(50);
    }
}

bool Menu() {
    SetBackgroundColor(Black);
    system("cls");
    const int FILAS = 40;
    const int COLUMNAS = 160;
    int menu[FILAS][COLUMNAS] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    const int FILAS_OPCION = 9;
    const int COLUMNAS_OPCION = 29;
    int opcion[FILAS_OPCION][COLUMNAS_OPCION] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    static int posicionX = 37;
    const int posicionY = 29;
    static int prevPosX = posicionX;
    const int POS_ADMINISTRADOR = 37;
    const int POS_USUARIO = 95;
    for (int f = 0; f < FILAS; f++) {
        for (int c = 0; c < COLUMNAS; c++) {
            if (menu[f][c] == 0) SetForegroundColor(Black);
            else if (menu[f][c] == 1) SetForegroundColor(BrightWhite);
            else if (menu[f][c] == 3) SetForegroundColor(LightGreen);
            else SetForegroundColor(Black);

            SetCursorPosition(c, f);
            cout << (char)219;
        }
    }
    for (int f = 0; f < FILAS_OPCION; f++) {
        for (int c = 0; c < COLUMNAS_OPCION; c++) {
            if (opcion[f][c] == 5) {
                SetForegroundColor(Magenta);
                SetCursorPosition(posicionX + c, posicionY + f);
                cout << (char)219;
            }
        }
    }
    bool running = true;
    while (running) {
        if (_kbhit()) {
            int key = _getch();

            if (key == 224) {
                key = _getch();
                int limite_derecho = COLUMNAS - COLUMNAS_OPCION - 7;

                if (key == 75) { // Flecha izquierda
                    prevPosX = posicionX;
                    if (posicionX == POS_USUARIO) {
                        posicionX = POS_ADMINISTRADOR;
                    }
                    else {
                        posicionX = POS_USUARIO;
                    }
                }
                else if (key == 77) { // Flecha derecha
                    prevPosX = posicionX;
                    if (posicionX == POS_ADMINISTRADOR) {
                        posicionX = POS_USUARIO;
                    }
                    else {
                        posicionX = POS_ADMINISTRADOR;
                    }
                }
            }
            else if (key == '\r') {
                if (posicionX == POS_ADMINISTRADOR) {
                    if (sistemaAdmins->iniciarSesion()) {
                        Administrador(); // Solo ejecuta la función si la autenticación fue exitosa
                    }
                    else {
                        Menu(); // Vuelve al menú principal en caso de fallo de autenticación
                    }
                    return true;
                }
				else if (posicionX == POS_USUARIO) {
					if (sistemaUsuarios->SubMenuUsuario()) {
						Usuario(); // Ejecuta la función Usuario() solo si la autenticación fue exitosa
					}
					return true;
				}
            }
			else if (key == 27) { // 27 es el código ASCII para la tecla ESC
				Salir();
				return true;
			}
            if (prevPosX != posicionX) {
                for (int f = 0; f < FILAS_OPCION; f++) {
                    for (int c = 0; c < COLUMNAS_OPCION; c++) {
                        if (opcion[f][c] == 5) {
                            int x = prevPosX + c;
                            int y = posicionY + f;
                            if (menu[y][x] == 0) SetForegroundColor(Black);
                            else if (menu[f][c] == 1) SetForegroundColor(BrightWhite);
                            else SetForegroundColor(LightGreen);

                            SetCursorPosition(x, y);
                            cout << (char)219;
                        }
                    }
                }
                for (int f = 0; f < FILAS_OPCION; f++) {
                    for (int c = 0; c < COLUMNAS_OPCION; c++) {
                        if (opcion[f][c] == 5) {
                            SetForegroundColor(Magenta);
                            SetCursorPosition(posicionX + c, posicionY + f);
                            cout << (char)219;
                        }
                    }
                }
            }
        }
        SetBackgroundColor(LightGreen);
        SetForegroundColor(Black);
        SetCursorPosition(45, 33); cout << "ADMINISTRADOR";
        SetCursorPosition(106, 33); cout << "USUARIO";
        Sleep(50);
    }
}

void Pantalla_carga() {
    SetBackgroundColor(Black);
    const int FILAS = 8;
    const int COLUMNAS = 106;
    int carga[FILAS][COLUMNAS] = {
        {0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    int punto0[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    int punto1[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    int punto2[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
    };
    int punto3[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,1},
    };
    int ancho = GetConsoleWidth();
    int alto = GetConsoleHeight();
    int posicionX = (ancho - COLUMNAS) / 2;
    int posicionY = (alto - FILAS) / 2;
    for (int f = 0; f < FILAS; f++) {
        SetCursorPosition(posicionX, posicionY + f);
        for (int c = 0; c < COLUMNAS; c++) {
            if (carga[f][c] == 1) {
                SetForegroundColor(BrightWhite);
                cout << (char)219;
            }
            else {
                cout << ' ';
            }
        }
    }
    bool cargar = true;
    while (cargar) {
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, 22 + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (punto0[f][c] == 1) {
                    SetForegroundColor(BrightWhite);
                    cout << (char)219;
                }
                else {
                    cout << ' ';
                }
            }
        }
        Sleep(500);
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, 22 + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (punto1[f][c] == 1) {
                    SetForegroundColor(BrightWhite);
                    cout << (char)219;
                }
                else {
                    SetForegroundColor(Black);
                    cout << ' ';
                }
            }
        }
        Sleep(500);
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, 22 + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (punto2[f][c] == 1) {
                    SetForegroundColor(BrightWhite);
                    cout << (char)219;
                }
                else {
                    SetForegroundColor(Black);
                    cout << ' ';
                }
            }
        }
        Sleep(500);
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, 22 + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (punto3[f][c] == 1) {
                    SetForegroundColor(BrightWhite);
                    cout << (char)219;
                }
                else {
                    SetForegroundColor(Black);
                    cout << ' ';
                }
            }
            if (_kbhit()) {
                cargar = false;
            }
        }
        Sleep(500);
    }
    system("cls");
}

void Logo_UPC() {
    SetBackgroundColor(Black);
    const int FILAS = 20;
    const int COLUMNAS = 98;
    int logo[FILAS][COLUMNAS] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
        {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1},
        {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1},
        {0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

    };
    int ancho = GetConsoleWidth();
    int alto = GetConsoleHeight();
    int posX = (ancho - COLUMNAS) / 2;
    int posY = (alto - FILAS) / 2;
    for (int f = 0; f < FILAS; ++f) {
        SetCursorPosition(posX, posY + f);
        for (int c = 0; c < COLUMNAS; ++c) {
            if (logo[f][c]) {
                SetTextColor(Red);
                std::cout << char(219);
            }
            else {
                SetTextColor(Black);
                std::cout << ' ';
            }
        }
    }
    system("pause>0");
    system("cls");
}

