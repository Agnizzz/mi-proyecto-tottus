#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <limits>

#include "Administrador.h"
#include "Utilidades.h"

using namespace std;

// Estructura para almacenar los datos de cada usuario
struct User {
	string correo;
	string nombre;
	string apellido_paterno;
	string apellido_materno;
	string usuario;
	string DNI;
	string celular;
	string contrasena;
};

// Clase para gestionar la autenticación de usuarios
class SistemaUsuarios {
private:
	static const int MAX_USERS = 100; // Máximo de usuarios en el sistema
	User usuarios[MAX_USERS];
	int cantidadUsuarios;
	User userActual;
	bool sesionIniciada;

	// Método para cargar los usuarios desde un archivo
	void cargarUsuarios() {
		ifstream archivo("Usuarios.txt");
		if (!archivo) {
			cout << "Error al abrir el archivo de usuarios" << endl;
			return;
		}

		cantidadUsuarios = 0;
		string linea;

		// Saltar líneas de comentario
		while (getline(archivo, linea)) {
			if (linea.empty() || linea[0] == '#') continue;

			// Primera línea de datos (correo)
			usuarios[cantidadUsuarios].correo = linea;

			// Leer el resto de campos
			if (!getline(archivo, usuarios[cantidadUsuarios].nombre)) break;
			if (!getline(archivo, usuarios[cantidadUsuarios].apellido_paterno)) break;
			if (!getline(archivo, usuarios[cantidadUsuarios].apellido_materno)) break;
			if (!getline(archivo, usuarios[cantidadUsuarios].DNI)) break;
			if (!getline(archivo, usuarios[cantidadUsuarios].celular)) break;
			if (!getline(archivo, usuarios[cantidadUsuarios].usuario)) break;
			if (!getline(archivo, usuarios[cantidadUsuarios].contrasena)) break;

			cantidadUsuarios++;

			if (cantidadUsuarios >= MAX_USERS) break;
		}

		archivo.close();
	}

public:
	SistemaUsuarios() {
		cantidadUsuarios = 0;
		sesionIniciada = false;
		cargarUsuarios();
	}

	bool IniciarSesion() {
		SetBackgroundColor(Black);
		system("cls");
		const int FILAS = 27;
		const int COLUMNAS = 160;
		int interfaz[FILAS][COLUMNAS] = {
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
		};
		int ancho = GetConsoleWidth();
		int alto = GetConsoleHeight();
		int posicionX = (ancho - COLUMNAS) / 2;
		int posicionY = 2;
		static int prevPosX = posicionX;
		for (int f = 0; f < FILAS; f++) {
			for (int c = 0; c < COLUMNAS; c++) {
				if (interfaz[f][c] == 4) {
					SetForegroundColor(LightYellow);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (interfaz[f][c] == 6) {
					SetForegroundColor(Green);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (interfaz[f][c] == 8) {
					SetForegroundColor(LightGreen);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (interfaz[f][c] == 5) {
					SetForegroundColor(LightYellow);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (interfaz[f][c] == 7) {
					SetForegroundColor(Green);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (interfaz[f][c] == 9) {
					SetForegroundColor(LightGreen);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (interfaz[f][c] == 0) SetForegroundColor(Black);
				else if (interfaz[f][c] == 1) SetForegroundColor(LightGreen);
				else if (interfaz[f][c] == 2) SetForegroundColor(Green);
				else if (interfaz[f][c] == 3) SetForegroundColor(LightYellow);
				else SetForegroundColor(Black);

				SetCursorPosition(c, f);
				cout << (char)219;
			}
		}
		SetForegroundColor(BrightWhite);

		// Calcular la posición para el formulario justo debajo del logo
		int formularioY = posicionY + FILAS + 3;

		// Centrar el título del formulario
		string titulo = "=== INICIO DE SESION ===";
		int tituloX = posicionX + (COLUMNAS - titulo.length()) / 2;

		string usuario, contrasena;
		int intentos = 0;
		const int MAX_INTENTOS = 3;

		while (intentos < MAX_INTENTOS) {
			SetCursorPosition(tituloX, formularioY);
			cout << titulo;

			// Centrar los campos de entrada
			int camposX = posicionX + (COLUMNAS / 2) - 15;

			SetCursorPosition(camposX, formularioY + 2);
			cout << "Usuario: ";
			// Leer usuario con soporte para ESC
			usuario = "";
			char ch;
			while (true) {
				ch = _getch();
				if (ch == 27) { // 27 es el código ASCII para ESC
					system("cls");
					return false; // Volver al menú principal
				}
				if (ch == 13) { // 13 es Enter
					break;
				}
				if (ch == 8) { // Backspace
					if (!usuario.empty()) {
						usuario.pop_back();
						cout << "\b \b";
					}
				}
				else if (ch >= 32 && ch <= 126) { // Caracteres imprimibles
					usuario.push_back(ch);
					cout << ch;
				}
			}

			SetCursorPosition(camposX, formularioY + 4);
			cout << "Contrase\xA4" << "a: ";

			// Ocultar la contraseña con asteriscos
			contrasena = "";
			while (true) {
				ch = _getch();
				if (ch == 27) { // ESC
					return false; // Volver al menú principal
				}
				if (ch == 13) { // Enter
					break;
				}
				if (ch == 8) { // Backspace
					if (!contrasena.empty()) {
						contrasena.pop_back();
						cout << "\b \b";
					}
				}
				else if (ch >= 32 && ch <= 126) {
					contrasena.push_back(ch);
					cout << "*";
				}
			}

			// Buscar el usuario y verificar la contraseña
			bool encontrado = false;
			for (int i = 0; i < cantidadUsuarios; i++) {
				if (usuarios[i].usuario == usuario && usuarios[i].contrasena == contrasena) {
					userActual = usuarios[i];
					sesionIniciada = true;
					encontrado = true;

					SetCursorPosition(camposX, formularioY + 6);
					cout << "\xAD" << "Bienvenido " << userActual.nombre << " " << userActual.apellido_paterno << "!";
					//system("Pause>0");
					Sleep(1500);
					return true;
				}
			}

			if (!encontrado) {
				intentos++;
				SetCursorPosition(camposX, formularioY + 6);
				cout << "Usuario o contrase\xA4" << "a incorrectos. Intento " << intentos << " de " << MAX_INTENTOS;
				system("Pause>0");
				//Sleep(1500);

				// Limpiar solo el área del formulario, no todo
				for (int i = 0; i < 8; i++) {
					SetCursorPosition(posicionX, formularioY + i);
					for (int j = 0; j < COLUMNAS; j++) {
						cout << " ";
					}
				}
			}
		}

		SetCursorPosition(tituloX - 10, formularioY + 6);
		cout << "Demasiados intentos fallidos. El sistema se cerrara.";
		Sleep(2000);
		return false;
	}

	User getUsuarioActual() const {
		return userActual;
	}

	bool estaSesionIniciada() const {
		return sesionIniciada;
	}

	void cerrarSesion() {
		sesionIniciada = false;
	}

	bool Registrarse() {
		SetBackgroundColor(Black);
		system("cls");
		const int FILAS = 27;
		const int COLUMNAS = 160;
		int interfaz[FILAS][COLUMNAS] = {
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
		};
		int ancho = GetConsoleWidth();
		int alto = GetConsoleHeight();
		int posicionX = (ancho - COLUMNAS) / 2;
		int posicionY = 2;
		static int prevPosX = posicionX;
		for (int f = 0; f < FILAS; f++) {
			for (int c = 0; c < COLUMNAS; c++) {
				if (interfaz[f][c] == 4) {
					SetForegroundColor(LightYellow);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (interfaz[f][c] == 6) {
					SetForegroundColor(Green);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (interfaz[f][c] == 8) {
					SetForegroundColor(LightGreen);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (interfaz[f][c] == 5) {
					SetForegroundColor(LightYellow);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (interfaz[f][c] == 7) {
					SetForegroundColor(Green);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (interfaz[f][c] == 9) {
					SetForegroundColor(LightGreen);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (interfaz[f][c] == 0) SetForegroundColor(Black);
				else if (interfaz[f][c] == 1) SetForegroundColor(LightGreen);
				else if (interfaz[f][c] == 2) SetForegroundColor(Green);
				else if (interfaz[f][c] == 3) SetForegroundColor(LightYellow);
				else SetForegroundColor(Black);

				SetCursorPosition(c, f);
				cout << (char)219;
			}
		}
		SetForegroundColor(BrightWhite);

		if (cantidadUsuarios >= MAX_USERS) {
			cout << "\n\t\tNo se pueden registrar más usuarios. El sistema está lleno.\n";
			system("pause>0");
			return false;
		}

		User nuevoUsuario;

		int centroX = ancho / 2;

		string titulo = "===== REGISTRO DE NUEVO USUARIO =====";
		SetCursorPosition(centroX - (titulo.length() / 2), 28);
		cout << titulo;

		// Configurar posiciones de las columnas
		int columnaIzquierdaX = 40;
		int columnaDerechaX = 90;
		int posY = 30;
		int espacioVertical = 2;

		// Función auxiliar para dibujar los campos
		auto dibujarCampo = [](int x, int y, const string& etiqueta) {
			SetCursorPosition(x, y);
			cout << etiqueta;

			SetCursorPosition(x + 16, y);
			cout << ": ";
			};

		// Dibujar campos de la columna izquierda
		dibujarCampo(columnaIzquierdaX, posY, "Nombre");
		dibujarCampo(columnaIzquierdaX, posY + espacioVertical, "Apellido Paterno");
		dibujarCampo(columnaIzquierdaX, posY + espacioVertical * 2, "Apellido Materno");
		dibujarCampo(columnaIzquierdaX, posY + espacioVertical * 3, "Usuario");

		// Dibujar campos de la columna derecha
		dibujarCampo(columnaDerechaX, posY, "DNI");
		dibujarCampo(columnaDerechaX, posY + espacioVertical, "Correo");
		dibujarCampo(columnaDerechaX, posY + espacioVertical * 2, "Celular");
		dibujarCampo(columnaDerechaX, posY + espacioVertical * 3, "Contrase¤a");

		// Recopilar datos de la columna izquierda
		bool nombreValido = false;
		while (!nombreValido) {
			SetCursorPosition(columnaIzquierdaX + 18, posY);
			// Limpiar la linea anterior si hubo error
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaIzquierdaX + 18, posY);

			nuevoUsuario.nombre = "";
			char chn;
			while (true) {
				chn = _getch();
				if (chn == 13) break;  // Enter
				if (chn == 27) return false;  // ESC
				if (chn == 224 || chn == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (chn == 8) {  // Backspace
					if (!nuevoUsuario.nombre.empty()) {
						nuevoUsuario.nombre.pop_back();
						cout << "\b \b";
					}
				}
				else if (chn == 32) {  // Permitir espacios para nombres compuestos
					nuevoUsuario.nombre.push_back(chn);
					cout << chn;
				}
				// Verificar si es una letra (mayuscula o minuscula)
				else if ((chn >= 'A' && chn <= 'Z') || (chn >= 'a' && chn <= 'z')) {
					nuevoUsuario.nombre.push_back(chn);
					cout << chn;
				}
			}

			// Eliminar espacios al final
			while (!nuevoUsuario.nombre.empty() && nuevoUsuario.nombre.back() == ' ') {
				nuevoUsuario.nombre.pop_back();
			}

			// Validar que no este vacio después de eliminar espacios
			if (nuevoUsuario.nombre.empty()) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "El nombre no puede estar vacio o consistir solo de espacios.";
				_getch();  // Esperar tecla
				// Limpiar mensaje de error
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				SetForegroundColor(BrightWhite);
			}
			else {
				nombreValido = true;
			}
		}

		bool apellidoPaternoValido = false;
		while (!apellidoPaternoValido) {
			SetCursorPosition(columnaIzquierdaX + 18, posY + espacioVertical);
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaIzquierdaX + 18, posY + espacioVertical);

			nuevoUsuario.apellido_paterno = "";
			char chap;
			while (true) {
				chap = _getch();
				if (chap == 13) break;  // Enter
				if (chap == 27) return false;  // ESC
				if (chap == 224 || chap == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (chap == 8) {  // Backspace
					if (!nuevoUsuario.apellido_paterno.empty()) {
						nuevoUsuario.apellido_paterno.pop_back();
						cout << "\b \b";
					}
				}
				else if (chap == 32) {  // Permitir espacios para apellido compuestos compuestos
					nuevoUsuario.apellido_paterno.push_back(chap);
					cout << chap;
				}
				// Verificar si es una letra (mayuscula o minuscula)
				else if ((chap >= 'A' && chap <= 'Z') || (chap >= 'a' && chap <= 'z')) {
					nuevoUsuario.apellido_paterno.push_back(chap);
					cout << chap;
				}
			}

			// Eliminar espacios al final
			while (!nuevoUsuario.apellido_paterno.empty() && nuevoUsuario.apellido_paterno.back() == ' ') {
				nuevoUsuario.apellido_paterno.pop_back();
			}

			// Validar que no este vacio después de eliminar espacios
			if (nuevoUsuario.apellido_paterno.empty()) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "El apellido paterno no puede estar vacio o consistir solo de espacios.";
				_getch();  // Esperar tecla
				// Limpiar mensaje de error
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				SetForegroundColor(BrightWhite);
			}
			else {
				apellidoPaternoValido = true;
			}
		}

		bool apellidoMaternoValido = false;
		while (!apellidoMaternoValido) {
			SetCursorPosition(columnaIzquierdaX + 18, posY + espacioVertical * 2);
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaIzquierdaX + 18, posY + espacioVertical * 2);
			nuevoUsuario.apellido_materno = "";
			char cham;
			while (true) {
				cham = _getch();
				if (cham == 13) break;  // Enter
				if (cham == 27) return false;  // ESC
				if (cham == 224 || cham == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (cham == 8) {  // Backspace
					if (!nuevoUsuario.apellido_materno.empty()) {
						nuevoUsuario.apellido_materno.pop_back();
						cout << "\b \b";
					}
				}
				else if (cham == 32) {  // Permitir espacios para apellido compuestos compuestos
					nuevoUsuario.apellido_materno.push_back(cham);
					cout << cham;
				}
				// Verificar si es una letra (mayuscula o minuscula)
				else if ((cham >= 'A' && cham <= 'Z') || (cham >= 'a' && cham <= 'z')) {
					nuevoUsuario.apellido_materno.push_back(cham);
					cout << cham;
				}
			}

			// Eliminar espacios al final
			while (!nuevoUsuario.apellido_materno.empty() && nuevoUsuario.apellido_materno.back() == ' ') {
				nuevoUsuario.apellido_materno.pop_back();
			}

			// Validar que no este vacio después de eliminar espacios
			if (nuevoUsuario.apellido_materno.empty()) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "El apellido materno no puede estar vacio o consistir solo de espacios.";
				_getch();  // Esperar tecla
				// Limpiar mensaje de error
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				SetForegroundColor(BrightWhite);
			}
			else {
				apellidoMaternoValido = true;
			}
		}

		bool usuarioValido = false;
		while (!usuarioValido) {
			SetCursorPosition(columnaIzquierdaX + 18, posY + espacioVertical * 3);
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaIzquierdaX + 18, posY + espacioVertical * 3);

			string tempUsuario = "";
			char chu;
			while (true) {
				chu = _getch();
				if (chu == 13) break;  // Enter
				if (chu == 27) return false;  // ESC
				if (chu == 224 || chu == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (chu == 8) {  // Backspace
					if (!tempUsuario.empty()) {
						tempUsuario.pop_back();
						cout << "\b \b";
					}
				}
				else if (chu >= 33 && chu <= 126) {
					tempUsuario.push_back(chu);
					cout << chu;
				}
			}

			// Validar que no este vacio
			if (tempUsuario.empty()) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "El nombre de usuario no puede estar vacio";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Verificar si el usuario ya existe
			bool usuarioExistente = false;
			for (int i = 0; i < cantidadUsuarios; i++) {
				if (usuarios[i].usuario == tempUsuario) {
					SetForegroundColor(Red);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					cout << "El nombre de usuario ya existe. Intente con otro nombre";
					_getch();
					SetForegroundColor(BrightWhite);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					for (int i = 0; i < 80; i++) cout << " ";
					usuarioExistente = true;
					break;
				}
			}

			if (!usuarioExistente) {
				nuevoUsuario.usuario = tempUsuario;
				usuarioValido = true;
			}
		}

		// Recopilar datos de la columna derecha
		bool dniValido = false;
		while (!dniValido) {
			SetCursorPosition(columnaDerechaX + 18, posY);
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaDerechaX + 18, posY);

			string tempDNI = "";
			char chd;
			while (true) {
				chd = _getch();
				if (chd == 13) break;  // Enter
				if (chd == 27) return false;  // ESC
				if (chd == 224 || chd == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (chd == 8) {  // Backspace
					if (!tempDNI.empty()) {
						tempDNI.pop_back();
						cout << "\b \b";
					}
				}
				// Solo permitir digitos y limitar a 8 caracteres
				else if (chd >= '0' && chd <= '9' && tempDNI.length() < 8) {
					tempDNI.push_back(chd);
					cout << chd;
				}
			}

			// Validar que tenga exactamente 8 dígitos
			if (tempDNI.length() != 8) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "El DNI debe tener exactamente 8 digitos numericos";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Verificar si el DNI ya existe
			bool dniExistente = false;
			for (int i = 0; i < cantidadUsuarios; i++) {
				if (usuarios[i].DNI == tempDNI) {
					SetForegroundColor(Red);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					cout << "Este DNI ya esta registrado en el sistema";
					_getch();
					SetForegroundColor(BrightWhite);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					for (int i = 0; i < 80; i++) cout << " ";
					dniExistente = true;
					break;
				}
			}

			if (!dniExistente) {
				nuevoUsuario.DNI = tempDNI;
				dniValido = true;
			}
		}

		bool correoValido = false;
		while (!correoValido) {
			SetCursorPosition(columnaDerechaX + 18, posY + espacioVertical);
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaDerechaX + 18, posY + espacioVertical);

			string tempCorreo = "";
			char chco;
			while (true) {
				chco = _getch();
				if (chco == 13) break;  // Enter
				if (chco == 27) return false;  // ESC
				if (chco == 224 || chco == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (chco == 8) {  // Backspace
					if (!tempCorreo.empty()) {
						tempCorreo.pop_back();
						cout << "\b \b";
					}
				}
				// Permitir caracteres validos para un correo electronico
				else if ((chco >= 'a' && chco <= 'z') ||
					(chco >= 'A' && chco <= 'Z') ||
					(chco >= '0' && chco <= '9') ||
					chco == '@' || chco == '.' ||
					chco == '_' || chco == '-') {
					tempCorreo.push_back(chco);
					cout << chco;
				}
			}

			// Validar que no este vacio
			if (tempCorreo.empty()) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "El correo electronico no puede estar vacio";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Validacion basica del formato de correo (debe contener @ y .)
			if (tempCorreo.find('@') == string::npos || tempCorreo.find('.') == string::npos) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "Formato de correo electronico invalido";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Verificar si el correo ya existe
			bool correoExistente = false;
			for (int i = 0; i < cantidadUsuarios; i++) {
				if (usuarios[i].correo == tempCorreo) {
					SetForegroundColor(Red);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					cout << "Este correo electronico ya esta registrado en el sistema";
					_getch();
					SetForegroundColor(BrightWhite);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					for (int i = 0; i < 80; i++) cout << " ";
					correoExistente = true;
					break;
				}
			}

			if (!correoExistente) {
				nuevoUsuario.correo = tempCorreo;
				correoValido = true;
			}
		}

		bool celularValido = false;
		while (!celularValido) {
			SetCursorPosition(columnaDerechaX + 18, posY + espacioVertical * 2);
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaDerechaX + 18, posY + espacioVertical * 2);

			// Mostrar el prefijo +51 automaticamente
			cout << "+51 ";

			string tempCelular = "";
			char chc;
			while (true) {
				chc = _getch();
				if (chc == 13) break;  // Enter
				if (chc == 27) return false;  // ESC
				if (chc == 224 || chc == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (chc == 8) {  // Backspace
					if (!tempCelular.empty()) {
						tempCelular.pop_back();
						cout << "\b \b";
					}
				}
				// Solo permitir digitos y limitar a 9 caracteres
				else if (chc >= '0' && chc <= '9' && tempCelular.length() < 9) {
					tempCelular.push_back(chc);
					cout << chc;
				}
			}

			// Validar que tenga exactamente 9 digitos
			if (tempCelular.length() != 9) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "El celular debe tener exactamente 9 digitos numericos";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Verificar si el celular ya existe
			bool celularExistente = false;
			for (int i = 0; i < cantidadUsuarios; i++) {
				if (usuarios[i].celular == tempCelular) {
					SetForegroundColor(Red);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					cout << "Este numero de celular ya esta registrado en el sistema";
					_getch();
					SetForegroundColor(BrightWhite);
					SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
					for (int i = 0; i < 80; i++) cout << " ";
					celularExistente = true;
					break;
				}
			}

			if (!celularExistente) {
				nuevoUsuario.celular = tempCelular;
				celularValido = true;
			}
		}

		bool contrasenaValida = false;
		while (!contrasenaValida) {
			SetCursorPosition(columnaDerechaX + 18, posY + espacioVertical * 3);
			for (int i = 0; i < 30; i++) cout << " ";
			SetCursorPosition(columnaDerechaX + 18, posY + espacioVertical * 3);

			string tempContrasena = "";
			char chp;
			while (true) {
				chp = _getch();
				if (chp == 13) break;  // Enter
				if (chp == 27) return false;  // ESC
				if (chp == 224 || chp == 0) {  // Tecla especial
					_getch();  // Consumir el siguiente byte sin hacer nada
					continue;  // Ignorar la secuencia completa
				}
				if (chp == 8) {  // Backspace
					if (!tempContrasena.empty()) {
						tempContrasena.pop_back();
						cout << "\b \b";
					}
				}
				// Permitir caracteres válidos para una contraseña, EXCEPTO espacios
				else if (chp >= 33 && chp <= 126) {  // Caracteres imprimibles ASCII sin espacios (32)
					tempContrasena.push_back(chp);
					cout << chp;  // Mostrar asterisco para ocultar la contraseña
				}
			}

			// Validar que no este vacia
			if (tempContrasena.empty()) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "La contrasena no puede estar vacia";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Validar longitud minima
			if (tempContrasena.length() < 6) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				cout << "La contrasena debe tener al menos 6 caracteres";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 25, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Validación integrada de todos los requisitos de contraseña
			bool tieneNumero = false, tieneMayuscula = false, tieneCaracterEspecial = false;

			for (char c : tempContrasena) {
				if (c >= '0' && c <= '9')
					tieneNumero = true;
				else if (c >= 'A' && c <= 'Z')
					tieneMayuscula = true;
				else if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))
					tieneCaracterEspecial = true;
			}

			if (!tieneNumero || !tieneMayuscula || !tieneCaracterEspecial) {
				SetForegroundColor(Red);
				SetCursorPosition(centroX - 35, posY + espacioVertical * 4);
				cout << "La contrasena debe tener al menos un numero, una mayuscula y un caracter especial";
				_getch();
				SetForegroundColor(BrightWhite);
				SetCursorPosition(centroX - 35, posY + espacioVertical * 4);
				for (int i = 0; i < 80; i++) cout << " ";
				continue;
			}

			// Si pasa todas las validaciones
			nuevoUsuario.contrasena = tempContrasena;
			contrasenaValida = true;
		}

		// Guardar el nuevo usuario
		usuarios[cantidadUsuarios++] = nuevoUsuario;

		// Guardar en archivo
		ofstream archivo("Usuarios.txt", ios::app);
		if (archivo) {
			archivo << nuevoUsuario.correo << endl;
			archivo << nuevoUsuario.nombre << endl;
			archivo << nuevoUsuario.apellido_paterno << endl;
			archivo << nuevoUsuario.apellido_materno << endl;
			archivo << nuevoUsuario.DNI << endl;
			archivo << nuevoUsuario.celular << endl;
			archivo << nuevoUsuario.usuario << endl;
			archivo << nuevoUsuario.contrasena << endl;
			archivo << endl; // Añadir una línea vacía entre usuarios
			archivo.close();
		}

		// Mensaje de éxito
		SetForegroundColor(Green);
		SetCursorPosition(centroX - 20, posY + espacioVertical * 4);
		cout << "­Registro exitoso! Bienvenido " << nuevoUsuario.nombre << " " << nuevoUsuario.apellido_paterno << " a Tottus.";
		system("pause>0");
		return true;
	}

	bool SubMenuUsuario() {
		SetBackgroundColor(Black);
		system("cls");
		const int FILAS = 40;
		const int COLUMNAS = 160;
		int SubMenu[FILAS][COLUMNAS] = {
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
		const int POS_SESION = 37;
		const int POS_REGISTRARSE = 95;
		for (int f = 0; f < FILAS; f++) {
			for (int c = 0; c < COLUMNAS; c++) {
				if (SubMenu[f][c] == 4) {
					SetForegroundColor(LightYellow);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (SubMenu[f][c] == 6) {
					SetForegroundColor(Green);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (SubMenu[f][c] == 8) {
					SetForegroundColor(LightGreen);
					SetCursorPosition(c, f);
					cout << (char)220;
					continue;
				}
				if (SubMenu[f][c] == 5) {
					SetForegroundColor(LightYellow);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (SubMenu[f][c] == 7) {
					SetForegroundColor(Green);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (SubMenu[f][c] == 9) {
					SetForegroundColor(LightGreen);
					SetCursorPosition(c, f);
					cout << (char)223;
					continue;
				}
				if (SubMenu[f][c] == 0) SetForegroundColor(Black);
				else if (SubMenu[f][c] == 1) SetForegroundColor(LightGreen);
				else if (SubMenu[f][c] == 2) SetForegroundColor(Green);
				else if (SubMenu[f][c] == 3) SetForegroundColor(LightYellow);
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

				if (key == 27) {
					return false;
				}

				if (key == 224) {
					key = _getch();
					int limite_derecho = COLUMNAS - COLUMNAS_OPCION - 7;

					if (key == 75) { // Flecha izquierda
						prevPosX = posicionX;
						if (posicionX == POS_REGISTRARSE) {
							posicionX = POS_SESION;
						}
						else {
							posicionX = POS_REGISTRARSE;
						}
					}
					else if (key == 77) { // Flecha derecha
						prevPosX = posicionX;
						if (posicionX == POS_SESION) {
							posicionX = POS_REGISTRARSE;
						}
						else {
							posicionX = POS_SESION;
						}
					}
				}
				else if (key == '\r') {
					if (posicionX == POS_SESION) {
						if (IniciarSesion()) { // Si el login es exitoso
							return true;
						}
						else {
							// Si falló o presionó ESC, vuelve a mostrar el menú desde cero
							return SubMenuUsuario();
						}
					}
					else if (posicionX == POS_REGISTRARSE) {
						Registrarse();
						// Después de registrarse, vuelve a mostrar el menú desde cero 
						return SubMenuUsuario();
					}
				}
				if (prevPosX != posicionX) {
					for (int f = 0; f < FILAS_OPCION; f++) {
						for (int c = 0; c < COLUMNAS_OPCION; c++) {
							if (opcion[f][c] == 5) {
								int x = prevPosX + c;
								int y = posicionY + f;
								if (SubMenu[y][x] == 0) SetForegroundColor(Black);
								else if (SubMenu[f][c] == 3) SetForegroundColor(LightYellow);
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
			SetCursorPosition(44, 33); cout << "INICIAR  SESION";
			SetCursorPosition(104, 33); cout << "REGISTRARSE";
			Sleep(50);
		}
	}
};

// Variable global para acceder desde cualquier parte del programa
extern SistemaUsuarios* sistemaUsuarios;