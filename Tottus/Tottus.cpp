#include <iostream>
#include <cstdlib> // <--- A�ADE ESTA L�NEA NUEVA
#include <ctime>   // <--- A�ADE ESTA L�NEA NUEVA
#include "Utilidades.h"
#include "Interfaz.h"


using namespace std;

int main() {
	srand(time(0)); // <--- A�ADE ESTA L�NEA PARA SEMBRAR EL RANDOM NUEVA
	cargarBoletasDesdeArchivo();
	cargarPromociones();          //NUEVO
	//inicializarOfertasDeProductos(); //NUEVO
	SetConsoleSize(160, 41);
	SetCursorVisible(false);

	Logo_UPC();
	Pantalla_carga();

	while (Menu()) {}

	return 0;
}
