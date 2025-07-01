#pragma once

#include <iostream>
#include <string>

using namespace std;

class Soporte {
private:
	// Estructura para preguntas y respuestas
	struct PreguntaRespuesta {
		string pregunta;
		string respuesta;
	};

	// Arreglo estático para preguntas frecuentes
	PreguntaRespuesta preguntasFrecuentes[5];
	int numPreguntas;

	// Método para mostrar las preguntas frecuentes
	void mostrarPreguntasFrecuentes() {
		cout << "\n=== PREGUNTAS FRECUENTES ===\n";

		if (numPreguntas == 0) {
			cout << "No hay preguntas frecuentes disponibles.\n";
			return;
		}

		for (int i = 0; i < numPreguntas; ++i) {
			cout << "\nPregunta " << (i + 1) << ": " << preguntasFrecuentes[i].pregunta << "\n";
			cout << "Respuesta: " << preguntasFrecuentes[i].respuesta << "\n";
		}

		cout << "\nPresione Enter para continuar...";
		cin.ignore();
		cin.get();
	}

	// Método para contactar al equipo de soporte
	void contactarSoporte() {
		cout << "\n=== CONTACTO CON SOPORTE ===\n";
		cout << "Email: soporte@tottus.com\n";
		cout << "Teléfono: 0800-12345\n";
		cout << "Horario de atención: Lunes a Viernes 9:00 - 18:00\n\n";

		cout << "Presione Enter para continuar...";
		cin.ignore();
		cin.get();
	}

public:
	// Constructor que inicializa las preguntas frecuentes
	Soporte() {
		// Inicializar con algunas preguntas frecuentes de ejemplo
		preguntasFrecuentes[0] = { "¿Cómo puedo cambiar mi contraseña?",
								 "Para cambiar su contraseña, vaya a Configuración > Seguridad > Cambiar contraseña." };
		preguntasFrecuentes[1] = { "¿Cómo puedo ver mi historial de compras?",
								 "Para ver su historial de compras, vaya a Mi Cuenta > Historial de Compras." };
		preguntasFrecuentes[2] = { "¿Cómo puedo cancelar un pedido?",
								 "Para cancelar un pedido, vaya a Mi Cuenta > Mis Pedidos, seleccione el pedido y haga clic en 'Cancelar Pedido'." };
		preguntasFrecuentes[3] = { "¿Cuáles son los métodos de pago aceptados?",
								 "Aceptamos tarjetas de crédito/débito, transferencia bancaria y efectivo en tiendas." };
		preguntasFrecuentes[4] = { "¿Cómo puedo obtener ayuda con un producto defectuoso?",
								 "Por favor contacte a nuestro equipo de soporte con el número de pedido y una descripción del problema." };
		numPreguntas = 5;
	}

	// Método principal para mostrar el menú de soporte
	void mostrarMenuSoporte() {
		int opcion = -1;

		while (opcion != 0) {
			cout << "\n\n\n\n\t\t\t1. Preguntas Frecuentes\n";
			cout << "\t\t\t2. Contactar al Equipo de Soporte\n";
			cout << "\t\t\t0. Salir\n";
			cout << "\t\t\tSeleccione una opción: ";

			cin >> opcion;

			switch (opcion) {
			case 1:
				mostrarPreguntasFrecuentes();
				break;
			case 2:
				contactarSoporte();
				break;
			case 0:
				cout << "Volviendo al menú principal...\n";
				break;
			default:
				cout << "Opción inválida. Presione Enter para continuar...";
				cin.ignore();
				cin.get();
				break;
			}
		}
	}
};