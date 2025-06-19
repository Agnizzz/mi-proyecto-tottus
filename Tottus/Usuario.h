#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Utilidades.h"

using namespace std;

// Estructura para almacenar los datos de cada usuario
struct Usuario {
	string correo;
	string nombre;
	string apellido;
	string DNI;
	string celular;
	string contrasena;
};