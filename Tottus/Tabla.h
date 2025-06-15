#pragma once
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <windows.h>
#include "CategoriaGeneral.h"
#include "Utilidades.h"
#include "Lista.h"

using namespace std;

void mostrarTablaProductos(const Lista<Categoria>& productos) {
    const int productosPorPagina = 10;
    int pagina = 0;
    int totalProductos = productos.getTam();
    int totalPaginas = (totalProductos + productosPorPagina - 1) / productosPorPagina;

    // | ID(15) | Producto(50) | Unidad(8) | Precio(8) | Oferta(8) |
    // Bordes: 1 + 15 + 1 + 50 + 1 + 8 + 1 + 8 + 1 + 8 + 1 = 102
    const int anchoTabla = 1 + 15 + 1 + 50 + 1 + 8 + 1 + 8 + 1 + 8 + 1; // = 102

    while (true) {
        system("cls");
        int anchoConsola = GetConsoleWidth();
        int posX = (anchoConsola - anchoTabla) / 2;
        int y = 2;

        // Encabezado alineado con setw y alineación
        SetCursorPosition(posX, y++);
        cout << "+---------------+--------------------------------------------------+--------+--------+--------+";
        SetCursorPosition(posX, y++);
        cout << "| " << setw(13) << left << "ID"
            << " | " << setw(48) << left << "Producto"
            << " | " << setw(6) << left << "Unidad"
            << " | " << setw(6) << right << "Precio"
            << " | " << setw(6) << right << "Oferta"
            << " |";
        SetCursorPosition(posX, y++);
        cout << "+---------------+--------------------------------------------------+--------+--------+--------+";

        int inicio = pagina * productosPorPagina;
        int fin = min(inicio + productosPorPagina, totalProductos);
        for (int i = inicio; i < fin; ++i) {
            const Categoria& prod = productos.getValor(i);
            SetCursorPosition(posX, y++);
            cout << "| " << setw(13) << left << prod.getID().substr(0, 13)
                << " | " << setw(48) << left << prod.getNombre().substr(0, 48)
                << " | " << setw(6) << left << prod.getUnidadMedida().substr(0, 6)
                << " | " << setw(6) << right << fixed << setprecision(2) << prod.getPrecioUnitario()
                << " | ";
            if (prod.getPrecioDescuento() > 0.0)
                cout << setw(6) << right << fixed << setprecision(2) << prod.getPrecioDescuento();
            else
                cout << "      ";
            cout << " |";
        }
        // Rellena filas vacías si hay menos de 10 productos en la página
        for (int i = fin; i < inicio + productosPorPagina; ++i) {
            SetCursorPosition(posX, y++);
            cout << "| " << setw(13) << left << ""
                << " | " << setw(48) << left << ""
                << " | " << setw(6) << left << ""
                << " | " << setw(6) << right << ""
                << " | " << setw(6) << right << ""
                << " |";
        }

        SetCursorPosition(posX, y++);
        cout << "+---------------+--------------------------------------------------+--------+--------+--------+";

        // Paginación y controles
        SetCursorPosition(posX, y++);
        cout << "Página " << (pagina + 1) << " de " << totalPaginas;
        SetCursorPosition(posX, y++);
        cout << "[<-] Anterior   [->] Siguiente   [ESC] Salir";

        int key = _getch();
        if (key == 27) {
            system("cls"); // Limpia la consola antes de salir
            break; // ESC
        }
        if (key == 224) {
            key = _getch();
            if (key == 75 && pagina > 0) pagina--;
            else if (key == 77 && pagina < totalPaginas - 1) pagina++;
        }
    }
}

int seleccionarProductoEnTabla(const Lista<Categoria>& productos) {
    const int productosPorPagina = 10;
    int pagina = 0;
    int totalProductos = productos.getTam();
    int totalPaginas = (totalProductos + productosPorPagina - 1) / productosPorPagina;
    int seleccion = 0;

    // | ID(15) | Producto(50) | Unidad(8) | Precio(8) | Oferta(8) |
    const int anchoTabla = 1 + 15 + 1 + 50 + 1 + 8 + 1 + 8 + 1 + 8 + 1; // = 102

    while (true) {
        system("cls");
        int anchoConsola = GetConsoleWidth();
        int posX = (anchoConsola - anchoTabla) / 2;
        int y = 2;

        // Encabezado
        SetCursorPosition(posX, y++);
        cout << "+---------------+--------------------------------------------------+--------+--------+--------+";
        SetCursorPosition(posX, y++);
        cout << "| " << setw(13) << left << "ID"
            << " | " << setw(48) << left << "Producto"
            << " | " << setw(6) << left << "Unidad"
            << " | " << setw(6) << right << "Precio"
            << " | " << setw(6) << right << "Oferta"
            << " |";
        SetCursorPosition(posX, y++);
        cout << "+---------------+--------------------------------------------------+--------+--------+--------+";

        int inicio = pagina * productosPorPagina;
        int fin = min(inicio + productosPorPagina, totalProductos);
        for (int i = inicio; i < fin; ++i) {
            SetCursorPosition(posX, y++);
            if (i == seleccion)
                cout << "->";
            else
                cout << "  ";
            const Categoria& prod = productos.getValor(i);
            cout << "| " << setw(13) << left << prod.getID().substr(0, 13)
                << " | " << setw(48) << left << prod.getNombre().substr(0, 48)
                << " | " << setw(6) << left << prod.getUnidadMedida().substr(0, 6)
                << " | " << setw(6) << right << fixed << setprecision(2) << prod.getPrecioUnitario()
                << " | ";
            if (prod.getPrecioDescuento() > 0.0)
                cout << setw(6) << right << fixed << setprecision(2) << prod.getPrecioDescuento();
            else
                cout << "      ";
            cout << " |";
        }
        // Rellenar filas vacías
        for (int i = fin; i < inicio + productosPorPagina; ++i) {
            SetCursorPosition(posX, y++);
            cout << "  | " << setw(13) << left << ""
                << " | " << setw(48) << left << ""
                << " | " << setw(6) << left << ""
                << " | " << setw(6) << right << ""
                << " | " << setw(6) << right << ""
                << " |";
        }

        SetCursorPosition(posX, y++);
        cout << "+---------------+--------------------------------------------------+--------+--------+--------+";

        // Paginación y controles
        SetCursorPosition(posX, y++);
        cout << "Página " << (pagina + 1) << " de " << totalPaginas;
        SetCursorPosition(posX, y++);
        cout << "[↑/↓] Mover  [<-] Anterior  [->] Siguiente  [Enter] Seleccionar  [ESC] Cancelar";

        int key = _getch();
        if (key == 27) { // ESC
            system("cls");
            return -1;
        }
        if (key == 13) { // Enter
            system("cls");
            return seleccion;
        }
        if (key == 224) {
            key = _getch();
            if (key == 72 && seleccion > 0) seleccion--; // Flecha arriba
            else if (key == 80 && seleccion < totalProductos - 1) seleccion++; // Flecha abajo
            else if (key == 75 && pagina > 0) { // Flecha izquierda
                pagina--;
                seleccion = pagina * productosPorPagina;
            }
            else if (key == 77 && pagina < totalPaginas - 1) { // Flecha derecha
                pagina++;
                seleccion = pagina * productosPorPagina;
            }
        }
        // Ajustar selección si cambia de página
        if (seleccion < pagina * productosPorPagina)
            seleccion = pagina * productosPorPagina;
        if (seleccion >= min((pagina + 1) * productosPorPagina, totalProductos))
            seleccion = min((pagina + 1) * productosPorPagina, totalProductos) - 1;
    }
}


