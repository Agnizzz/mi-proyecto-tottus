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

<<<<<<< HEAD:Tottus/Interfaz.h
void Tienda() {
	SetBackgroundColor(Black);
	system("cls");

	while (true) {
		const int FILAS = 8;
		const int COLUMNAS = 63;
		int tienda[FILAS][COLUMNAS] = {
		{1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0},
		{1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0},
		{1,0,0,1,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1},
		{0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1},
		};

		// Centrar el logo en la pantalla
		int ancho = GetConsoleWidth();
		int alto = GetConsoleHeight();
		int posicionX = (ancho - COLUMNAS) / 2;
		int posicionY = 2;

		// Dibujar el logo
		for (int f = 0; f < FILAS; f++) {
			SetCursorPosition(posicionX, posicionY + f);
			for (int c = 0; c < COLUMNAS; c++) {
				if (tienda[f][c] == 1) {
					SetForegroundColor(Green);
					cout << (char)219;
				}
				else {
					cout << ' ';
				}
			}
		}
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 4; // 4 opciones, de 0 a 3
		AccionTecla accion = NINGUNA;
		// Ciclo de navegaci�n del men�
		while (true) {
			// Reiniciar acci�n
			accion = NINGUNA;
			// Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
			for (int i = 0; i < 10; i++) {
				SetCursorPosition(0, posicionY + FILAS + i);
				cout << string(ancho, ' ');
			}
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Opci�n 1: Ver Catalogo por Categor�as
			SetCursorPosition(35, posicionY + FILAS + 2);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo blanco, texto negro para opci�n seleccionada
				cout << "> - Ver Catalogo por Categorias <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Ver Catalogo por Categorias  ";
			}
			// Opci�n 2: Buscar un Producto
			SetCursorPosition(35, posicionY + FILAS + 4);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Buscar un Producto <";
				setColor(15, 0);
			}
			else {
				cout << "  - Buscar un Producto  ";
			}
			// Opci�n 3: Ver Promociones Vigentes
			SetCursorPosition(35, posicionY + FILAS + 6);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Ver Promociones Vigentes <";
				setColor(15, 0);
			}
			else {
				cout << "  - Ver Promociones Vigentes  ";
			}
			// Opci�n 0: Volver al Menu Principal
			SetCursorPosition(35, posicionY + FILAS + 8);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Volver al Menu Principal <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Menu Principal  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
		}

		// Procesar la selecci�n
		switch (seleccion) {
			case 0: { // Ver Catalogo por Categor�as
				// Muestra una lista de las categor�as de productos para que el cliente elija
				// Tu c�digo aqu�
			break;
			}
			case 1: { // Buscar un Producto
				// a. Buscar producto por ID // b. Buscar producto por nombre // c. Buscar producto por rango de precio // 0. Volver al men� anterior
				// Tu c�digo aqu�
			break;
			}
			case 2: { // Ver Promociones Vigentes
				// Muestra una lista de las ofertas activas. Al seleccionar una, puede que se listen los productos participantes, permitiendo al cliente agregarlos al carrito desde all�.
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Volver al Menu Principal
				SetCursorPosition(35, posicionY + FILAS + 10);
				cout << "VOLVIENDO AL MENU PRINCIPAL..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
			}
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
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 6; // 6 opciones, de 0 a 5
		AccionTecla accion = NINGUNA;
        /*== Mi Carrito de Compras ==
			
			-----------------------------------------------------------------------
			ID  | Producto                  | Cant. | P. Unit. | Subtotal
			-----------------------------------------------------------------------
			P001| Leche Fresca UHT 1L       |   2   | S/ 5.50  | S/ 11.00
			P005| Yogurt de Fresa 1L        |   1   | S/ 8.20  | S/  8.20
			-----------------------------------------------------------------------
			(Se podr�an mostrar promociones aplicadas aqu�)
																Total Estimado: S/ 19.20

			Opciones:
			1. Modificar Cantidad de un producto
			2. Eliminar un producto del carrito
			3. Proceder al Pago / Finalizar Compra
			4. Vaciar Carrito por completo
			5. Seguir Comprando (Volver a la Tienda)
			0. Volver al Men� Principal

			Seleccione una opci�n:*/
		// Ciclo de navegaci�n del men�
        while (true) {
            // Reiniciar acci�n
            accion = NINGUNA;
            // Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
            for (int i = 0; i < 10; i++) {
                SetCursorPosition(0, posicionY + FILAS + i);
                cout << string(ancho, ' ');
            }
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Opci�n 1: Modificar Cantidad de un producto
			SetCursorPosition(35, posicionY + FILAS + 17);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo amarillo, texto negro para opci�n seleccionada
				cout << "> - Modificar Cantidad de un producto <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Modificar Cantidad de un producto  ";
			}
			// Opci�n 2: Eliminar un producto del carrito
			SetCursorPosition(35, posicionY + FILAS + 19);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Eliminar un producto del carrito <";
				setColor(15, 0);
			}
			else {
				cout << "  - Eliminar un producto del carrito  ";
			}
			// Opci�n 3: Proceder al Pago / Finalizar Compra
			SetCursorPosition(35, posicionY + FILAS + 21);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Proceder al Pago / Finalizar Compra <";
				setColor(15, 0);
			}
			else {
				cout << "  - Proceder al Pago / Finalizar Compra  ";
			}
			// Opci�n 4: Vaciar Carrito
			SetCursorPosition(35, posicionY + FILAS + 23);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Vaciar Carrito <";
				setColor(15, 0);
			}
			else {
				cout << "  - Vaciar Carrito  ";
			}
			// Opci�n 5: Seguir Comprando
			SetCursorPosition(35, posicionY + FILAS + 25);
			if (seleccion == 4) {
				setColor(0, 15);
				cout << "> - Seguir Comprando <";
				setColor(15, 0);
			}
			else {
				cout << "  - Seguir Comprando  ";
			}
			// Opci�n 0: Volver al Menu Principal
			SetCursorPosition(35, posicionY + FILAS + 27);
			if (seleccion == 5) {
				setColor(0, 15);
				cout << "> - Volver al Menu Principal <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Menu Principal  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
        }

		// Procesar la selecci�n
		switch (seleccion) {
			case 0: { // Modificar Cantidad de un producto
				// Pide el ID del producto y la nueva cantidad deseada
				// Tu c�digo aqu�
				break;
			}
			case 1: { // Eliminar un producto del carrito
				// Pide el ID del producto a retirar del carrito
				// Tu c�digo aqu�
				break;
			}
			case 2: { // Proceder al Pago / Finalizar Compra
				// Se muestra un resumen final y se pide confirmaci�n
				// Se simula la elecci�n de un m�todo de pago
				// Al confirmar, el sistema procesa la compra : se genera la boleta, se actualiza el stock de los productos, y se vac�a el carrito
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Vaciar Carrito
				//Al seleccionarla, pide una confirmaci�n para evitar acciones accidentales :
				//�Est� seguro de que desea eliminar todos los productos de su carrito ? (S / N) :
				//Si se confirma, el carrito se vac�a y se muestra el mensaje : "Su carrito de compras ha sido vaciado."
				// Tu c�digo aqu�
				break;
			}
			case 4: { // Seguir Comprando
				// Al seleccionar esa opci�n, la aplicaci�n lo saca de la vista del carrito y lo lleva directamente al men� principal del m�dulo TIENDA
				// Tu c�digo aqu�
				break;
			}
			case 5: { // Volver al Menu Principal
				SetCursorPosition(35, posicionY + FILAS + 29);
				cout << "VOLVIENDO AL MENU PRINCIPAL..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
			}
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
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 4; // 4 opciones, de 0 a 3
		AccionTecla accion = NINGUNA;
		// Ciclo de navegaci�n del men�
		while (true) {
			// Reiniciar acci�n
			accion = NINGUNA;
			// Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
			for (int i = 0; i < 10; i++) {
				SetCursorPosition(0, posicionY + FILAS + i);
				cout << string(ancho, ' ');
			}
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Opci�n 1: Ver mi Ultima Boleta Generada
			SetCursorPosition(35, posicionY + FILAS + 2);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo blanco, texto negro para opci�n seleccionada
				cout << "> - Ver mi Ultima Boleta Generada <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Ver mi Ultima Boleta Generada  ";
			}
			// Opci�n 2: Ver Lista Completa de Mis Boletas
			SetCursorPosition(35, posicionY + FILAS + 4);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Ver Lista Completa de Mis Boletas <";
				setColor(15, 0);
			}
			else {
				cout << "  - Ver Lista Completa de Mis Boletas  ";
			}
			// Opci�n 3: Buscar una Boleta Especifica
			SetCursorPosition(35, posicionY + FILAS + 6);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Buscar una Boleta Especifica <";
				setColor(15, 0);
			}
			else {
				cout << "  - Buscar una Boleta Especifica  ";
			}
			// Opci�n 0: Volver al Menu Principal
			SetCursorPosition(35, posicionY + FILAS + 8);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Volver al Menu Principal <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Menu Principal  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
		}

    	// Procesar la selecci�n
    	switch (seleccion) {
			case 0: { // Ver Catalogo por Categor�as
			    // Muestra la �ltima boleta generada por el usuario, con detalles de los productos comprados, cantidades y precios
				// Tu c�digo aqu�
				break;
			}
			case 1: { // Ver Lista Completa de Mis Boletas
				// Al seleccionar esta opci�n, el sistema muestra un listado paginado de todas las boletas del cliente, ordenadas por fecha
				//Desde esta lista, el cliente puede ingresar el ID de una boleta para ver su detalle completo(productos, montos, fecha, etc.)
				// Tu c�digo aqu�
				break;
			}
			case 2: { // Buscar una Boleta Especifica
				// a. Buscar por N�mero de Boleta // b. Buscar por Rango de Fechas // 0. Volver
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Volver al Menu Principal
				SetCursorPosition(35, posicionY + FILAS + 10);
				cout << "VOLVIENDO AL MENU PRINCIPAL..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
			}
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
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 4; // 4 opciones, de 0 a 3
		AccionTecla accion = NINGUNA;
		// Ciclo de navegaci�n del men�
		while (true) {
			// Reiniciar acci�n
			accion = NINGUNA;
			// Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
			for (int i = 0; i < 10; i++) {
				SetCursorPosition(0, posicionY + FILAS + i);
				cout << string(ancho, ' ');
			}
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Mensaje de bienvenida
			SetCursorPosition(35, posicionY + FILAS + 2);
			// Verificar si hay un usuario con sesi�n iniciada
			if (sistemaUsuarios->estaSesionIniciada()) {
                cout << "�En que podemos ayudarle, " << sistemaUsuarios->getUsuarioActual().nombre << " " << sistemaUsuarios->getUsuarioActual().apellido_paterno << "?";
			}
			// Opci�n 1: Enviar Nueva Solicitud (Reclamo, Consulta, etc.)
			SetCursorPosition(35, posicionY + FILAS + 4);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo blanco, texto negro para opci�n seleccionada
				cout << "> - Enviar Nueva Solicitud <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Enviar Nueva Solicitud  ";
			}
			// Opci�n 2: Consultar el Estado de Mis Solicitudes
			SetCursorPosition(35, posicionY + FILAS + 6);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Consultar el Estado de Mis Solicitudes <";
				setColor(15, 0);
			}
			else {
				cout << "  - Consultar el Estado de Mis Solicitudes  ";
			}
			// Opci�n 3: Ver Preguntas Frecuentes (FAQ)
			SetCursorPosition(35, posicionY + FILAS + 8);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Ver Preguntas Frecuentes <";
				setColor(15, 0);
			}
			else {
				cout << "  - Ver Preguntas Frecuentes  ";
			}
			// Opci�n 0: Volver al Menu Principal
			SetCursorPosition(35, posicionY + FILAS + 10);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Volver al Menu Principal <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Menu Principal  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
		}

		// Procesar la selecci�n
		switch (seleccion) {
			case 0: { // Enviar Nueva Solicitud
				// Inicia el proceso para crear un nuevo ticket de soporte. Le pedir� que seleccione el tipo de solicitud (Reclamo, Consulta, Sugerencia) y que describa su caso. Al finalizar, le entregar� un n�mero de ticket
				// Tu c�digo aqu�
				break;
			}
			case 1: { // Consultar el Estado de Mis Solicitudes
				// Muestra una lista de todos los tickets de soporte que el cliente ha creado, indicando su estado actual ("Nuevo", "En Proceso", "Resuelto", etc.)
				// Desde esta lista, el cliente puede seleccionar un ticket para ver el historial completo de la conversaci�n y, si el ticket est� abierto, a�adir un nuevo mensaje
				// Tu c�digo aqu�
				break;
			}
			case 2: { // Ver Preguntas Frecuentes
			    // Le da acceso a la base de conocimiento para que pueda resolver dudas comunes por su cuenta, consultando una lista de preguntas y respuestas predefinidas por el administrador
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Volver al Menu Principal
				SetCursorPosition(35, posicionY + FILAS + 12);
				cout << "VOLVIENDO AL MENU PRINCIPAL..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
			}
		}
	}
}

=======
>>>>>>> parent of f43bb3d (Interfaz terminada):Tottus/Matrices.h
void Producto() {
    SetBackgroundColor(Black);
    system("cls");
    while (true) {
        const int FILAS = 8;
        const int COLUMNAS = 97;
        int producto[FILAS][COLUMNAS] = {
        {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0},
        {1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,0},
        {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1},
        {1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0},
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
<<<<<<< HEAD:Tottus/Interfaz.h
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 5; // 5 opciones, de 0 a 4
		AccionTecla accion = NINGUNA;
		// Ciclo de navegaci�n del men�
		while (true) {
			// Reiniciar acci�n
			accion = NINGUNA;
			// Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
			for (int i = 0; i < 10; i++) {
				SetCursorPosition(0, posicionY + FILAS + i);
				cout << string(ancho, ' ');
			}
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Opci�n 1: Gestion de Productos
			SetCursorPosition(35, posicionY + FILAS + 2);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo blanco, texto negro para opci�n seleccionada
				cout << "> - Gestion de Productos <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Gestion de Productos  ";
			}
			// Opci�n 2: Gestion de Categorias
			SetCursorPosition(35, posicionY + FILAS + 4);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Gestion de Categorias <";
				setColor(15, 0);
			}
			else {
				cout << "  - Gestion de Categorias  ";
			}
			// Opci�n 3: Gestion de Proveedores
			SetCursorPosition(35, posicionY + FILAS + 6);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Gestion de Proveedores <";
				setColor(15, 0);
			}
			else {
				cout << "  - Gestion de Proveedores  ";
			}
			// Opci�n 4: Consultar Inventario General
			SetCursorPosition(35, posicionY + FILAS + 8);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Consultar Inventario General <";
				setColor(15, 0);
			}
			else {
				cout << "  - Consultar Inventario General  ";
			}
			// Opci�n 0: Volver al Panel de Administracion
			SetCursorPosition(35, posicionY + FILAS + 10);
			if (seleccion == 4) {
				setColor(0, 15);
				cout << "> - Volver al Panel de Administracion <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Panel de Administracion  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
		}

		// Procesar la selecci�n
		switch (seleccion) {
			case 0: { // Gestion de Productos
			    // a. Agregar Nuevo Producto // b. Buscar y Modificar Producto // c. Eliminar Producto // d. Ordenar Producto // e. Listar Todos los Productos // 0. Volver al men� anterior
				// Tu c�digo aqu�
				break;
			}
			case 1: { // Gestion de Categorias
			    // a. Agregar Nueva Categor�a // b. Modificar Nombre de Categor�a // c. Eliminar Categor�a // d. Listar Todas las Categor�as // 0. Volver al men� anterior
				// Tu c�digo aqu�
				break;
			}
			case 2: { // Gestion de Proveedores
			    // a. Agregar Nuevo Proveedor // b. Modificar Datos de Proveedor // c. Eliminar Proveedor // d. Listar Todos los Proveedores // 0. Volver al men� anterior
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Consultar Inventario General
			    // a. Ver Inventario Completo (Listar todos los productos con su stock) // b. Ver Productos con Bajo Stock (ej. menos de 10 unidades) // c. Ver Productos sin Stock (Agotados) // 0. Volver al men� anterior
				// Tu c�digo aqu�
				break;
			}
			case 4: { // Volver al Panel de Administracion
				SetCursorPosition(35, posicionY + FILAS + 12);
				cout << "VOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
			}
		}
	}
=======
        int opcion;
        SetForegroundColor(BrightWhite);
        cout << "\n\n\n\n\t\t\t1. Categorias\n";
        cout << "\n\t\t\t2. Funciones Producto\n"; //Agregar, eliminar y editar prodcuto
        cout << "\n\t\t\t3. Buscar Productos\n"; //Buscar por ID, nombre y precio
        cout << "\n\t\t\t4. Ordenar Productos\n"; //Por precio y por nombre
        cout << "\n\t\t\t5. Funciones Oferta\n"; //Agregar, eliminar y editar oferta
        cout << "\n\t\t\t0. Salir\n";
        cout << "\n\t\t\tSeleccione una opcion: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 5) {
            cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            system("pause>0");
            system("cls");
            continue;
        }
        if (opcion == 0) {
            cout << "\n\t\t\tSALIENDO DEL SISTEMA..." << endl;
            break;
        }
        if (opcion == 1) {
			categorias();
        }
        if (opcion == 2) {
            funcionesProducto();
        }
        if (opcion == 3) {
            buscarProductos();
        }
        if (opcion == 4) {
            ordenarProductos();
        }
        if (opcion == 5) {
            funcionesOferta();
        }
    }
    system("pause>0");
>>>>>>> parent of f43bb3d (Interfaz terminada):Tottus/Matrices.h
}

void Cliente() {
    SetBackgroundColor(Black);
    system("cls");
    while (true) {
        const int FILAS = 8;
        const int COLUMNAS = 75;
        int cliente[FILAS][COLUMNAS] = {
        {0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0},
        {1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0},
        {1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
        };
        int ancho = GetConsoleWidth();
        int alto = GetConsoleHeight();
        int posicionX = (ancho - COLUMNAS) / 2;
        int posicionY = 2;
        for (int f = 0; f < FILAS; f++) {
            SetCursorPosition(posicionX, posicionY + f);
            for (int c = 0; c < COLUMNAS; c++) {
                if (cliente[f][c] == 1) {
                    SetForegroundColor(Blue);
                    cout << (char)219;
                }
                else {
                    cout << ' ';
                }
            }
        }
<<<<<<< HEAD:Tottus/Interfaz.h
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 4; // 4 opciones, de 0 a 3
		AccionTecla accion = NINGUNA;
		// Ciclo de navegaci�n del men�
		while (true) {
			// Reiniciar acci�n
			accion = NINGUNA;
			// Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
			for (int i = 0; i < 10; i++) {
				SetCursorPosition(0, posicionY + FILAS + i);
				cout << string(ancho, ' ');
			}
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Opci�n 1: Gestion de Cuentas de Usuario
			SetCursorPosition(35, posicionY + FILAS + 2);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo blanco, texto negro para opci�n seleccionada
				cout << "> - Gestion de Cuentas de Usuario <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Gestion de Cuentas de Usuario  ";
			}
			// Opci�n 2: Gestion de Promociones
			SetCursorPosition(35, posicionY + FILAS + 4);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Gestion de Promociones <";
				setColor(15, 0);
			}
			else {
				cout << "  - Gestion de Promociones  ";
			}
			// Opci�n 3: Generar Reportes del Sistema
			SetCursorPosition(35, posicionY + FILAS + 6);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Generar Reportes del Sistema <";
				setColor(15, 0);
			}
			else {
				cout << "  - Generar Reportes del Sistema  ";
			}
			// Opci�n 0: Volver al Panel de Administracion
			SetCursorPosition(35, posicionY + FILAS + 8);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Volver al Panel de Administracion <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Panel de Administracion  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
		}

		// Procesar la selecci�n
		switch (seleccion) {
			case 0: { // Gestion de Cuentas de Usuario
			    // a.Buscar y Modificar Cuenta // b.Eliminar Cuenta // c.Listar Todas las Cuentas // 0. Volver al men� anterior
				// Tu c�digo aqu�
				break;
			}
			case 1: { // Gestion de Promociones
			    // a. Crear Nueva Promoci�n // b. Modificar Promoci�n Existente // c. Activar / Desactivar Promoci�n // d. Listar Todas las Promociones // 0. Volver al men� anterior
				// Tu c�digo aqu�
				break;
			}
			case 2: { // Generar Reportes del Sistema
			    // a. Reporte de Usuarios // b. Reporte de Actividad de Promociones // c. Reporte Resumido de Inventario // 0. Volver al men� anterior
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Volver al Panel de Administracion
				SetCursorPosition(35, posicionY + FILAS + 10);
				cout << "VOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
			}
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
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 5; // 5 opciones, de 0 a 4
		AccionTecla accion = NINGUNA;
		// Ciclo de navegaci�n del men�
		while (true) {
			// Reiniciar acci�n
			accion = NINGUNA;
			// Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
			for (int i = 0; i < 10; i++) {
				SetCursorPosition(0, posicionY + FILAS + i);
				cout << string(ancho, ' ');
			}
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Opci�n 1: Busqueda Avanzada de Boletas
			SetCursorPosition(35, posicionY + FILAS + 2);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo blanco, texto negro para opci�n seleccionada
				cout << "> - Busqueda Avanzada de Boletas <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Busqueda Avanzada de Boletas  ";
			}
			// Opci�n 2: Listar Ultimas Boletas Generadas
			SetCursorPosition(35, posicionY + FILAS + 4);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Listar Ultimas Boletas Generadas <";
				setColor(15, 0);
			}
			else {
				cout << "  - Listar Ultimas Boletas Generadas  ";
			}
			// Opci�n 3: Gestion de Boletas Pendientes
			SetCursorPosition(35, posicionY + FILAS + 6);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Gestion de Boletas Pendientes <";
				setColor(15, 0);
			}
			else {
				cout << "  - Gestion de Boletas Pendientes  ";
			}
			// Opci�n 4: Generar Reportes de Ventas
			SetCursorPosition(35, posicionY + FILAS + 8);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Generar Reportes de Ventas <";
				setColor(15, 0);
			}
			else {
				cout << "  - Generar Reportes de Ventas  ";
			}
			// Opci�n 0: Volver al Panel de Administracion
			SetCursorPosition(35, posicionY + FILAS + 10);
			if (seleccion == 4) {
				setColor(0, 15);
				cout << "> - Volver al Panel de Administracion <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Panel de Administracion  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
		}

		// Procesar la selecci�n
		switch (seleccion) {
			case 0: { // Busqueda Avanzada de Boletas
				// �Por qu� criterio desea buscar ?
				// a. Por N�mero de Boleta exacto
				// b. Por Rango de Fechas
				// c. Por DNI o Usuario del Cliente
				// d. Por Rango de Monto Total
				// e. Por Estado de la Boleta(Ej : Pagada, Anulada, Pendiente)
				// 0. Volver
				// Tu c�digo aqu�
				break;
			}
			case 1: { // Listar Ultimas Boletas Generadas
				// Al seleccionar esta opci�n, el sistema muestra una lista paginada de las �ltimas N transacciones
				// Tu c�digo aqu�
				break;
			}
			case 2: { // Gestion de Boletas Pendientes
				// Al entrar, se listan todas las boletas que requieren una acci�n administrativa para continuar su ciclo de vida.
				// El administrador puede seleccionar una boleta y actualizar su estado, lo que mover�a la boleta fuera de esta lista de pendientes.
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Generar Reportes de Ventas
				// a. Reporte de Ventas Totales por Per�odo // b. Reporte de Productos M�s Vendidos(Top N) // c.Reporte de Ventas por Categor�a de Producto // d. Reporte de Rendimiento de Clientes // 0. Volver
				// Tu c�digo aqu�
				break;
			}
			case 4: { // Volver al Panel de Administracion
				SetCursorPosition(35, posicionY + FILAS + 12);
				cout << "VOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
			}
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
		// Variables para la navegaci�n del men�
		int seleccion = 0;
		int maxSeleccion = 5; // 5 opciones, de 0 a 4
		AccionTecla accion = NINGUNA;
		// Ciclo de navegaci�n del men�
		while (true) {
			// Reiniciar acci�n
			accion = NINGUNA;
			// Limpiar �rea de men� (opcional, dependiendo de la implementaci�n)
			for (int i = 0; i < 10; i++) {
				SetCursorPosition(0, posicionY + FILAS + i);
				cout << string(ancho, ' ');
			}
			// Mostrar opciones de men�
			SetForegroundColor(BrightWhite);
			// Opci�n 1: Dashboard de Tickets
			SetCursorPosition(35, posicionY + FILAS + 2);
			if (seleccion == 0) {
				setColor(0, 15); // Fondo blanco, texto negro para opci�n seleccionada
				cout << "> - Dashboard de Tickets <";
				setColor(15, 0); // Volver a colores normales
			}
			else {
				cout << "  - Dashboard de Tickets  ";
			}
			// Opci�n 2: Gestionar un Ticket Especifico
			SetCursorPosition(35, posicionY + FILAS + 4);
			if (seleccion == 1) {
				setColor(0, 15);
				cout << "> - Gestionar un Ticket Especifico <";
				setColor(15, 0);
			}
			else {
				cout << "  - Gestionar un Ticket Especifico  ";
			}
			// Opci�n 3: Gestion de la Base de Conocimiento
			SetCursorPosition(35, posicionY + FILAS + 6);
			if (seleccion == 2) {
				setColor(0, 15);
				cout << "> - Gestion de la Base de Conocimiento <";
				setColor(15, 0);
			}
			else {
				cout << "  - Gestion de la Base de Conocimiento  ";
			}
			// Opci�n 4: Ver Estadisticas de Soporte
			SetCursorPosition(35, posicionY + FILAS + 8);
			if (seleccion == 3) {
				setColor(0, 15);
				cout << "> - Ver Estadisticas de Soporte <";
				setColor(15, 0);
			}
			else {
				cout << "  - Ver Estadisticas de Soporte  ";
			}
			// Opci�n 0: Volver al Panel de Administracion
			SetCursorPosition(35, posicionY + FILAS + 10);
			if (seleccion == 4) {
				setColor(0, 15);
				cout << "> - Volver al Panel de Administracion <";
				setColor(15, 0);
			}
			else {
				cout << "  - Volver al Panel de Administracion  ";
			}
			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);
			// Si el usuario selecciona una opci�n
			if (accion == SELECCIONAR || accion == CANCELAR) {
				break;
			}
		}

		// Procesar la selecci�n
		switch (seleccion) {
			case 0: { // Dashboard de Tickets
				// Ver y Filtrar
				/* --Dashboard de Tickets --
				Filtro Actual : [Tickets Nuevos y Abiertos]
				
				ID Ticket | Cliente | Asunto | Estado | Fecha
				------------------------------------------------------------------------------ -
				T - 0015 | Ana Torres | Producto defectuoso | Nuevo | 2025 - 07 - 04
				T - 0014 | Luis Rojas | Duda sobre devoluci�n | Abierto | 2025 - 07 - 03
				T - 0012 | Carlos Vera | No lleg� mi pedido | Abierto | 2025 - 07 - 02
				------------------------------------------------------------------------------ -
				[P�g. 1 de 2]
				
				Opciones:
				a.Filtrar por Estado(Nuevos, Abiertos, En Proceso, Resueltos, etc.)
				b.Buscar por ID de Ticket o DNI de Cliente
				c.Ver detalle de un Ticket(ingresando su ID)
				0. Volver
				
				Opci�n :*/
				// Tu c�digo aqu�
				break;
			}
			case 1: { // Gestionar un Ticket Especifico
				// Primero, el sistema pide el ID del ticket a gestionar
				// Una vez encontrado el ticket, se muestra toda su informaci�n detallada y un men� de acciones.
				/* == Detalle del Ticket T-0015 ==
				Cliente: Ana Torres (DNI: 87654321)
				Fecha: 2025-07-04
				Asunto: Producto defectuoso
				Descripci�n: "Compr� una licuadora ayer y no enciende..."
				Estado Actual: Nuevo
				
				-- Historial de Comunicaciones --
				[2025-07-04 10:30] Cliente: "Compr� una licuadora ayer y no enciende..."
				-----------------------------------
				
				Acciones Disponibles:
				1. Enviar Respuesta al Cliente
				2. Agregar Nota Interna (no visible para el cliente)
				3. Cambiar Estado del Ticket
				4. Asignar Ticket a un Responsable (si aplica)
				0. Volver al Dashboard
				
				Opci�n:*/
				// Tu c�digo aqu�
				break;
			}
			case 2: { // Gestion de la Base de Conocimiento
				// FAQ
				// a. Agregar Nuevo Art�culo de FAQ // b. Modificar Art�culo Existente // c. Eliminar Art�culo // d. Listar Todos los Art�culos //0. Volver
				// Tu c�digo aqu�
				break;
			}
			case 3: { // Ver Estadisticas de Soporte
				// Al seleccionar esta opci�n, se muestra un reporte consolidado
				/* == Estad�sticas del M�dulo de Soporte ==
				Fecha del Reporte: 2025-07-04
				
				-- Tickets por Estado --
				Nuevos:                  5
				Abiertos:                12
				En Proceso:              8
				Esperando Respuesta:     2
				Resueltos (�ltimos 7 d�as): 25
				Total Abiertos:          27
				
				-- Rendimiento (Datos de ejemplo) --
				Tiempo Promedio de Primera Respuesta: 4 horas
				Tiempo Promedio de Resoluci�n:        28 horas
				
				-- Solicitudes por Tipo (�ltimos 30 d�as) --
				Reclamos:                45%
				Consultas:               35%
				Sugerencias:             15%
				Problemas T�cnicos:      5%
				-------------------------------------------------
				(0) Volver*/
				// Tu c�digo aqu�
				break;
			}
			case 4: { // Volver al Panel de Administracion
				SetCursorPosition(35, posicionY + FILAS + 12);
				cout << "VOLVIENDO AL PANEL DE ADMINISTRACION..." << endl;
				Sleep(500);
				return; // Salir de la funci�n
=======
        int opcion;
        SetForegroundColor(BrightWhite);
        SetConsoleOutputUtf8(true);
		cout << "\n\n\n\n\t\t\t1. Comprar\n";
		cout << "\n\t\t\t2. Ver carrito\n";
		cout << "\n\t\t\t3. Eliminar producto\n";
		cout << "\n\t\t\t4. Ver ofertas\n";
		cout << "\n\t\t\t5. Procesar compra\n";
        cout << "\n\t\t\t0. Salir\n";
        cout << "\n\t\t\tSeleccione una opcion: ";
        cin >> opcion;
        if (opcion < 0 || opcion > 5) {
            cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
            system("pause>0");
            system("cls");
            continue;
        }
        if (opcion == 0) {
            SetConsoleOutputUtf8(false);
            cout << "\n\t\t\tSALIENDO DEL SISTEMA..." << endl;
            break;
        }
		if (opcion == 1) {
			comprar();
		}
		if (opcion == 2) {
			verCarrito();
		}
		if (opcion == 3) {
			eliminarProducto();
		}
		if (opcion == 4) {
			verOfertas();
		}
		if (opcion == 5) {
			procesarCompra();
		}
        SetConsoleOutputUtf8(false);
    }
    system("pause>0");
}

void Registro() {
    SetBackgroundColor(Black);
    system("cls");
    const int FILAS = 8;
    const int COLUMNAS = 86;
    int registro[FILAS][COLUMNAS] = {
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
            if (registro[f][c] == 1) {
                SetForegroundColor(Red);
                cout << (char)219;
            }
            else {
                cout << ' ';
            }
        }
    }
    system("pause>0");
}

void SoporteAdminUser() {
	SetBackgroundColor(Black);
	system("cls");
	const int FILAS = 8;
	const int COLUMNAS = 76;
	int texto[FILAS][COLUMNAS] = {
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
			if (texto[f][c] == 1) {
				SetForegroundColor(Magenta);
				cout << (char)219;
			}
			else {
				cout << ' ';
>>>>>>> parent of f43bb3d (Interfaz terminada):Tottus/Matrices.h
			}
		}
	}

	// Crear una instancia de la clase Soporte
	Soporte soporteSystem;

	// Llamar al m�todo mostrarMenuSoporte de la clase Soporte
    SetForegroundColor(BrightWhite);
	soporteSystem.mostrarMenuSoporte();
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
                    //Producto();
                    return true;
                }
                else if (posicionX == 37) {
                    //Cliente();
                    return true;
                }
                else if (posicionX == 66) {
                    //Registro();
                    return true;
                }
                else if (posicionX == 95) {
                    SoporteAdminUser();
                    return true;
                }
				else if (posicionX == 124) {
					// Para el men� de Usuario
					SetBackgroundColor(Black);
					SetForegroundColor(BrightWhite);

					// Centrar el mensaje en la fila 39
					int ancho = GetConsoleWidth();
					string mensaje = "�Esta seguro que desea cerrar sesion? (s/n): ";
					int posX = (ancho - mensaje.length()) / 2;

					SetCursorPosition(posX, 39);
					cout << mensaje;

					char respuesta;
					cin >> respuesta;

					if (respuesta == 's' || respuesta == 'S') {
						sistemaUsuarios->cerrarSesion();
						system("cls");
						if (sistemaUsuarios->SubMenuUsuario()) {
							Usuario(); // Solo ejecuta la funci�n Usuario() si la autenticaci�n fue exitosa
						}
						return true;
					}
					// Si responde "n", simplemente contin�a en la sesi�n actual
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
                    continue;
                }
                else if (posicionX == 37) {
                    Cliente();
                    continue;
                }
                else if (posicionX == 66) {
                    Registro();
                    continue;
                }
                else if (posicionX == 95) {
                    SoporteAdminUser();
                    continue;
                }
				else if (posicionX == 124) {
					// Para el men� de Administrador
					SetBackgroundColor(Black);
					SetForegroundColor(BrightWhite);

					// Centrar el mensaje en la fila 39
					int ancho = GetConsoleWidth();
                    string mensaje = "�Esta seguro que desea cerrar sesion? (s/n): ";
					int posX = (ancho - mensaje.length()) / 2;

					SetCursorPosition(posX, 39);
					cout << mensaje;

					char respuesta;
					cin >> respuesta;

					if (respuesta == 's' || respuesta == 'S') {
						sistemaAdmins->cerrarSesion();
						system("cls");
						if (sistemaAdmins->iniciarSesion()) {
							Administrador(); // Solo ejecuta la funci�n si la autenticaci�n fue exitosa
						}
						return true;
					}
					// Si responde "n", simplemente contin�a en la sesi�n actual
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
                        Administrador(); // Solo ejecuta la funci�n si la autenticaci�n fue exitosa
                    }
                    else {
                        Menu(); // Vuelve al men� principal en caso de fallo de autenticaci�n
                    }
                    return true;
                }
				else if (posicionX == POS_USUARIO) {
					if (sistemaUsuarios->SubMenuUsuario()) {
						Usuario(); // Ejecuta la funci�n Usuario() solo si la autenticaci�n fue exitosa
					}
					return true;
				}
            }
			else if (key == 27) { // 27 es el c�digo ASCII para la tecla ESC
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