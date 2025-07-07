#include <iostream>
#include <cstdlib> // <--- AÑADE ESTA LÍNEA NUEVA
#include <ctime>   // <--- AÑADE ESTA LÍNEA NUEVA
#include "Utilidades.h"
#include "Interfaz.h"


using namespace std;

int main() {
	srand(time(0)); // <--- AÑADE ESTA LÍNEA PARA SEMBRAR EL RANDOM NUEVA
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
