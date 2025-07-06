#pragma once

#include <iostream>
#include <string>
#include <limits>      // <-- AÑADE ESTA LÍNEA PARA CORREGIR EL ERROR
#include <fstream>  // <--- NECESARIO PARA MANEJAR ARCHIVOS
#include <sstream>  // <--- NECESARIO PARA PARSEAR LÍNEAS
#include <chrono>   // Para obtener la fecha y hora
#include <ctime>    // Para formatear la fecha y hora
#include <iomanip>  // Para dar formato a la tabla (setw)
#include "Pilas.h" 
#include "Utilidades.h" // Para funciones de interfaz como SetCursorPosition
#include "Usuario.h"    // Para obtener información del usuario actual

using namespace std;

// Declaración para que Soporte sepa que sistemaUsuarios existe en alguna parte
extern SistemaUsuarios* sistemaUsuarios;

struct Ticket {
	int id;
	string tipo;
	string descripcion;
	string estado;
	string usuarioDNI;
	string fecha;
};
class SistemaUsuarios;

class Soporte {
private:

	Pila<Ticket> pilaTickets;
	int proximoIdTicket = 1;
	string archivoDeTickets = "tickets.txt"; // Nombre del archivo de guardado
	SistemaUsuarios* sistemaUsuarios;
	// Estructura para preguntas y respuestas
	struct PreguntaRespuesta {
		string pregunta;
		string respuesta;
	};

	// Arreglo estático para preguntas frecuentes
	PreguntaRespuesta preguntasFrecuentes[5];
	int numPreguntas;

	void guardarTickets() {
		ofstream archivo(archivoDeTickets);
		if (!archivo.is_open()) {
			cout << "ERROR: No se pudo abrir el archivo para guardar." << endl;
			return;
		}

		Pila<Ticket> pilaInvertida;

		// --- PASO 1: VACIAR LA PILA ORIGINAL EN UNA PILA TEMPORAL ---
		// Esto invierte el orden de los tickets. Ahora el más antiguo está en el tope.
		while (!pilaTickets.esVacia()) {
			pilaInvertida.apilar(pilaTickets.desapilar());
		}

		// En este punto, 'pilaTickets' está vacía y 'pilaInvertida' tiene todo.

		// --- PASO 2: ESCRIBIR Y RESTAURAR ---
		// Ahora recorremos la pila invertida. Esto nos da los tickets en el orden
		// correcto (del más antiguo al más nuevo) para escribirlos en el archivo.
		while (!pilaInvertida.esVacia()) {
			// Obtenemos el ticket del tope.
			Ticket ticketActual = pilaInvertida.desapilar();

			// Escribimos sus datos en el archivo.
			archivo << ticketActual.id << "|"
				<< ticketActual.tipo << "|"
				<< ticketActual.estado << "|"
				<< ticketActual.usuarioDNI << "|"
				<< ticketActual.fecha << "|"
				<< ticketActual.descripcion << endl;

			// Inmediatamente, restauramos el ticket en la pila original.
			pilaTickets.apilar(ticketActual);
		}

		// Al final, 'pilaInvertida' está vacía y 'pilaTickets' ha sido
		// restaurada a su estado original, ¡pero de forma segura!

		archivo.close();
	}


	// --- NUEVO MÉTODO PRIVADO PARA CARGAR ---
	void cargarTickets() {
		ifstream archivo(archivoDeTickets);
		//cout << "Intentando cargar tickets desde '" << archivoDeTickets << "'..." << endl; // <-- Mensaje de depuración

		if (!archivo.is_open()) {

			return;
		}

		string linea;
		Pila<Ticket> pilaTemporal;
		int contador = 0;

		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string id_str, tipo, estado, dni, fecha, descripcion; // <-- Añadir fecha aquí

			if (getline(ss, id_str, '|') &&
				getline(ss, tipo, '|') &&
				getline(ss, estado, '|') &&
				getline(ss, dni, '|') &&
				getline(ss, fecha, '|') && // <-- Añadir esta línea para leer la fecha
				getline(ss, descripcion))
			{
				Ticket t;
				t.id = stoi(id_str);
				t.tipo = tipo;
				t.estado = estado;
				t.usuarioDNI = dni;
				t.fecha = fecha; // <-- Añadir esta línea para asignar la fecha
				t.descripcion = descripcion;

				pilaTemporal.apilar(t);
				contador++;

				if (t.id >= proximoIdTicket) {
					proximoIdTicket = t.id + 1;
				}
			}
		}

		while (!pilaTemporal.esVacia()) {
			pilaTickets.apilar(pilaTemporal.desapilar());
		}


		archivo.close();
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
		cargarTickets(); // <-- CARGAMOS LOS TICKETS GUARDADOS
	}
	// DESTRUCTOR: Guarda los tickets al cerrar el programa
	~Soporte() {
		guardarTickets(); // <-- GUARDAMOS LOS TICKETS ANTES DE TERMINAR
	}
	//nuevo
	string getNombreClientePorDNI(string dni) {
		// Verificamos que el puntero al sistema de usuarios es válido
		if (sistemaUsuarios != nullptr) {
			// --- ¡Llamamos a la nueva función que acabamos de crear! ---
			// Usamos la flecha -> porque sistemaUsuarios es un puntero.
			User usuarioEncontrado = sistemaUsuarios->buscarPorDNI(dni);

			// Si el usuario fue encontrado (su nombre no está vacío)...
			if (!usuarioEncontrado.nombre.empty()) {
				// ...devolvemos su nombre y apellido.
				return usuarioEncontrado.nombre + " " + usuarioEncontrado.apellido_paterno;
			}
		}

		// Si algo falla, devolvemos un texto por defecto.
		return "Cliente Desconocido";
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
	// Constructor que recibe un puntero a SistemaUsuarios
	Soporte(SistemaUsuarios* sysUsers) {
		this->sistemaUsuarios = sysUsers; // Guardamos el puntero
		cargarTickets(); // Cargamos los tickets guardados
		// Aquí puedes cargar tus preguntas frecuentes si lo haces en el constructor
	}
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

	void enviarNuevaSolicitud() {
		system("cls");

		string titulo = "=== ENVIAR NUEVA SOLICITUD ===";
		int anchoConsola = 80;
		int posX = (anchoConsola - titulo.length()) / 2;
		int posY = 5;

		SetCursorPosition(posX, posY++);
		cout << titulo << endl;

		Ticket nuevoTicket;
		nuevoTicket.id = proximoIdTicket++;
		nuevoTicket.estado = "Nuevo";

		// --- CAMBIO CLAVE: HACERLO ANÓNIMO ---
		// En lugar de buscar al usuario, simplemente asignamos un valor genérico.
		nuevoTicket.usuarioDNI = "Anonimo";

		// --- Selección del tipo de solicitud (sin cambios) ---
		string tipos[] = { "Reclamo", "Consulta", "Sugerencia" };
		int seleccionTipo = 0;
		AccionTecla accion = NINGUNA;

		SetCursorPosition(posX, ++posY);
		cout << "Seleccione el tipo de solicitud:" << endl;
		posY++;

		while (accion != SELECCIONAR) {
			for (int i = 0; i < 3; ++i) {
				SetCursorPosition(posX, posY + i);
				if (i == seleccionTipo) {
					setColor(0, 15);
					cout << "> " << tipos[i] << " <";
					setColor(15, 0);
				}
				else {
					cout << "  " << tipos[i] << "  ";
				}
			}
			accion = navegarConFlechas(seleccionTipo, 3);
		}
		nuevoTicket.tipo = tipos[seleccionTipo];

		// Limpiamos el buffer de entrada para que getline funcione correctamente
		cin.ignore(10000, '\n');
		posY += 4;

		// --- Descripción del caso (sin cambios) ---
		SetCursorPosition(posX, posY++);
		cout << "Describa su caso (max 200 caracteres):" << endl;
		SetCursorPosition(posX, posY);
		getline(cin, nuevoTicket.descripcion);

		// --- Añadir fecha (sin cambios) ---
		time_t now = time(0);
		tm ltm;
		localtime_s(&ltm, &now);
		stringstream ss;
		ss << (1900 + ltm.tm_year) << "-" << setfill('0') << setw(2) << (1 + ltm.tm_mon) << "-" << setfill('0') << setw(2) << ltm.tm_mday;
		nuevoTicket.fecha = ss.str();

		// Apilar el nuevo ticket
		pilaTickets.apilar(nuevoTicket);
		guardarTickets(); // Guardamos el estado

		// --- Mensaje de confirmación (sin cambios) ---
		posY += 2;
		SetCursorPosition(posX, posY++);
		cout << "¡Solicitud enviada con exito!" << endl;
		SetCursorPosition(posX, posY);
		cout << "Su numero de ticket es: " << nuevoTicket.id << endl;

		posY += 2;
		SetCursorPosition(posX, posY);
		system("pause");
	}

	void consultarMisSolicitudes() {
		system("cls");
		string titulo = "=== MIS SOLICITUDES DE SOPORTE ===";
		int anchoConsola = 80;
		int posX = (anchoConsola - titulo.length()) / 2;
		int posY = 5;

		SetCursorPosition(posX, posY++);
		cout << titulo << endl << endl;

		Pila<Ticket> pilaAuxiliar;
		bool encontrados = false;

		// NOTA: Necesitamos el DNI del usuario actual. 
		// Por ahora, lo simularemos con una variable.
		// En la implementación final, lo obtendrías del sistema de usuarios.
		//string dniUsuarioActual = "12345678"; // <--- DATO DE EJEMPLO

		// Pasamos los tickets de la pila principal a la auxiliar para revisarlos
		while (!pilaTickets.esVacia()) {
			Ticket ticketActual = pilaTickets.desapilar();

			// Comparamos el DNI del ticket con el del usuario actual
			// if (ticketActual.usuarioDNI == dniUsuarioActual) { // <--- ESTA SERÍA LA LÍNEA CORRECTA

			// Como aún no asignamos el DNI, mostraremos todos por ahora para probar
			encontrados = true;
			cout << "----------------------------------------" << endl;
			cout << "  Ticket ID: " << ticketActual.id << endl;
			cout << "  Tipo:      " << ticketActual.tipo << endl;
			cout << "  Estado:    " << ticketActual.estado << endl;
			cout << "  Descripcion: " << ticketActual.descripcion << endl;
			cout << "----------------------------------------" << endl << endl;
			// }

			pilaAuxiliar.apilar(ticketActual);
		}

		// Restauramos la pila principal a su estado original
		while (!pilaAuxiliar.esVacia()) {
			pilaTickets.apilar(pilaAuxiliar.desapilar());
		}

		if (!encontrados) {
			cout << "No tienes ninguna solicitud de soporte registrada." << endl << endl;
		}

		system("pause");
	}


	void gestionarTicketEspecifico(int ticketId) {
		// 1. Buscamos el ticket de forma segura
		Ticket ticketEncontrado;
		bool idValido = false;

		// Usamos el método de vaciar y restaurar para no corromper la pila
		Pila<Ticket> pilaAuxiliar;
		while (!pilaTickets.esVacia()) {
			pilaAuxiliar.apilar(pilaTickets.desapilar());
		}

		while (!pilaAuxiliar.esVacia()) {
			Ticket ticketActual = pilaAuxiliar.desapilar();
			if (ticketActual.id == ticketId) {
				ticketEncontrado = ticketActual; // Guardamos una copia del ticket
				idValido = true;
			}
			pilaTickets.apilar(ticketActual); // Restauramos la pila principal
		}

		// Si no encontramos el ID, mostramos un error
		if (!idValido) {
			cout << "\n\nError: No se encontro ningun ticket con el ID " << ticketId << "." << endl;
			system("pause");
			return;
		}

		// 2. Bucle de la pantalla de detalles del ticket
		char opcion = ' ';
		while (opcion != '0') {
			system("cls");
			cout << "== Detalle del Ticket T-" << ticketEncontrado.id << " ==" << endl;
			cout << "-----------------------------------" << endl;
			cout << "Cliente:     Anónimo" << endl;
			cout << "Fecha:       " << ticketEncontrado.fecha << endl;
			cout << "Asunto:      " << ticketEncontrado.tipo << endl;
			cout << "Estado:      " << ticketEncontrado.estado << endl;
			cout << "Descripcion: \"" << ticketEncontrado.descripcion << "\"" << endl;
			cout << "-----------------------------------" << endl << endl;

			cout << "-- Historial de Comunicaciones --" << endl;
			cout << "[" << ticketEncontrado.fecha << "] Cliente: \"" << ticketEncontrado.descripcion << "\"" << endl;
			cout << "-----------------------------------" << endl << endl;

			cout << "Acciones Disponibles:" << endl;
			cout << " 1. Cambiar Estado del Ticket" << endl;
			cout << " 0. Volver al Dashboard" << endl << endl;
			cout << "Opcion: ";

			opcion = _getch();

			if (opcion == '1') {
				//vamos a implementar el cambio de estado del ticket
				system("cls");
				cout << "== Cambiar Estado del Ticket T-" << ticketEncontrado.id << " ==" << endl;
				cout << "Seleccione el nuevo estado:" << endl;
				cout << " 1. Nuevo" << endl;
				cout << " 2. En Proceso" << endl;
				cout << " 3. Resuelto" << endl;
				cout << " 0. Cancelar" << endl << endl;
				cout << "Opcion: ";
				char opcionEstado = _getch();
				if (opcionEstado == '1') {
					ticketEncontrado.estado = "Nuevo";
				}
				else if (opcionEstado == '2') {
					ticketEncontrado.estado = "En Proceso";
				}
				else if (opcionEstado == '3') {
					ticketEncontrado.estado = "Resuelto";
				}
				else if (opcionEstado == '0') {
					continue; // Volver al menú sin hacer cambios
				}
				else {
					cout << "Opción no válida. Volviendo al menú..." << endl;
					system("pause");
					continue; // Volver al menú sin hacer cambios
				}
				// Actualizamos el ticket en la pila
				Pila<Ticket> pilaTemporal;
				while (!pilaTickets.esVacia()) {
					Ticket ticketActual = pilaTickets.desapilar();
					if (ticketActual.id == ticketEncontrado.id) {
						ticketActual.estado = ticketEncontrado.estado; // Actualizamos el estado
					}
					pilaTemporal.apilar(ticketActual); // Guardamos en la pila temporal
				}
				// Ahora restauramos la pila original
				while (!pilaTemporal.esVacia()) {
					pilaTickets.apilar(pilaTemporal.desapilar());
				}
				// Guardamos los cambios en el archivo
				guardarTickets(); // <-- Guardamos los tickets actualizados
				cout << "Estado del ticket actualizado a: " << ticketEncontrado.estado << endl;
				cout << "Presione Enter para continuar..." << endl;
				cin.ignore(10000, '\n'); // Limpiamos el buffer
				cin.get(); // Esperamos a que el usuario presione Enter
				// Volvemos al menú de detalles del ticket
				opcion = '0'; // Forzamos salir del bucle para volver al dashboard
			}
		}
		system("cls");
		cout << "Volviendo al Dashboard de Tickets..." << endl;
		return;


	}

	void dashboardDeTickets() {
		// --- 1. PREPARACIÓN ULTRA-SEGURA (Sin cambios) ---
		const int MAX_TICKETS_A_MOSTRAR = 100;
		Ticket arrayDeTickets[MAX_TICKETS_A_MOSTRAR];
		int numTickets = 0;
		Pila<Ticket> pilaAuxiliar;
		while (!pilaTickets.esVacia()) {
			pilaAuxiliar.apilar(pilaTickets.desapilar());
		}
		while (!pilaAuxiliar.esVacia()) {
			Ticket ticketActual = pilaAuxiliar.desapilar();
			pilaTickets.apilar(ticketActual);
			if (numTickets < MAX_TICKETS_A_MOSTRAR) {
				arrayDeTickets[numTickets] = ticketActual;
				numTickets++;
			}
		}

		// --- 2. BUCLE PRINCIPAL DEL DASHBOARD ---
		char opcion = ' ';
		string filtroActual = "Nuevos";

		while (opcion != '0') {
			system("cls");
			cout << "--- Dashboard de Tickets ---" << endl;
			cout << "Filtro Actual: [" << filtroActual << "]" << endl << endl;

			// --- MOSTRAR TABLA (Sin cambios) ---
			cout << left << setw(12) << "ID Ticket" << setw(22) << "Cliente"
				<< setw(20) << "Asunto" << setw(15) << "Estado"
				<< setw(15) << "Fecha" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			int contadorMostrados = 0;
			for (int i = 0; i < numTickets; ++i) {
				Ticket& ticket = arrayDeTickets[i];
				bool mostrar = (filtroActual == "Todos" || (filtroActual == "Nuevos" && ticket.estado == "Nuevo") || (filtroActual == "En Procesos" && ticket.estado == "En Proceso") || (filtroActual == "Resueltos" && ticket.estado == "Resuelto"));
				if (mostrar) {
					string nombreCliente = (ticket.usuarioDNI == "Anonimo") ? "Anonimo" : getNombreClientePorDNI(ticket.usuarioDNI);
					cout << setw(12) << ("T-" + to_string(ticket.id))
						<< setw(22) << nombreCliente
						<< setw(20) << ticket.tipo
						<< setw(15) << ticket.estado
						<< setw(15) << ticket.fecha << endl;
					contadorMostrados++;
				}
			}
			if (contadorMostrados == 0) {
				cout << "No hay tickets que coincidan con el filtro actual." << endl;
			}
			cout << "--------------------------------------------------------------------------------" << endl;

			// --- 4. MENÚ DE OPCIONES (ACTUALIZADO) ---
			cout << "\nOpciones:" << endl;
			cout << " a. Filtrar por Estado" << endl;
			cout << " b. Ver detalle de un Ticket" << endl; // <-- Opción añadida
			cout << " 0. Volver" << endl << endl;
			cout << "Opcion: ";

			opcion = _getch();

			// --- LÓGICA DE OPCIONES (ACTUALIZADA) ---
			if (opcion == 'a' || opcion == 'A') {
				system("cls");
				cout << "--- Filtrar Tickets por Estado ---" << endl;
				cout << " 1. Ver Todos" << endl;
				cout << " 2. Ver Nuevos" << endl;
				cout << " 3. Ver En Proceso" << endl;
				cout << " 3. Ver Resueltos" << endl;
				cout << " 0. Cancelar" << endl << endl;
				cout << "Seleccione un filtro: ";
				char opcionFiltro = _getch();
				switch (opcionFiltro) {
				case '1': filtroActual = "Todos"; break;
				case '2': filtroActual = "Nuevos"; break;
				case '3': filtroActual = "En Procesos"; break;
				case '4': filtroActual = "Resueltos"; break;
				}
			}
			else if (opcion == 'b' || opcion == 'B') { // <-- Lógica añadida
				string idStr;
				cout << "\n\nPara ver el detalle, ingrese el ID del ticket (solo el numero): ";
				cin >> idStr;

				try {
					int id = stoi(idStr);
					gestionarTicketEspecifico(id); // Llamamos a la nueva función
					// --- RECONSTRUIR arrayDeTickets DESDE PILA ---
					numTickets = 0;
					Pila<Ticket> pilaTemporal;
					while (!pilaTickets.esVacia()) {
						Ticket temp = pilaTickets.desapilar();
						pilaTemporal.apilar(temp);
						if (numTickets < MAX_TICKETS_A_MOSTRAR) {
							arrayDeTickets[numTickets++] = temp;
						}
					}
					while (!pilaTemporal.esVacia()) {
						pilaTickets.apilar(pilaTemporal.desapilar());
					}
				}
				catch (const exception& e) {
					cout << "Error: El ID ingresado no es un numero valido." << endl;
					system("pause");
				}
			}
		}
	}


	void mostrarEstadisticasSoporte() {
		system("cls");

		// Obtener fecha actual
		time_t now = time(0);
		tm fechaActual;
		localtime_s(&fechaActual, &now);

		// Contadores por estado
		int nuevos = 0, abiertos = 0, enProceso = 0, esperandoRespuesta = 0, resueltos7dias = 0;
		int totalAbiertos = 0;

		// Contadores por tipo (últimos 30 días)
		int reclamos30dias = 0, consultas30dias = 0, sugerencias30dias = 0;

		Pila<Ticket> pilaTemporal;

		while (!pilaTickets.esVacia()) {
			Ticket t = pilaTickets.desapilar();
			pilaTemporal.apilar(t);

			// Contar por estado
			if (t.estado == "Nuevo") nuevos++;
			else if (t.estado == "Abierto") abiertos++;
			else if (t.estado == "En Proceso") enProceso++;
			else if (t.estado == "Esperando Respuesta") esperandoRespuesta++;
			else if (t.estado == "Resuelto") {
				// Calcular si fue en los últimos 7 días
				tm fechaTicket{};
				istringstream ss(t.fecha);
				ss >> get_time(&fechaTicket, "%Y-%m-%d");

				time_t fechaTicket_t = mktime(&fechaTicket);
				double dias = difftime(now, fechaTicket_t) / (60 * 60 * 24);

				if (dias <= 7) resueltos7dias++;
			}

			// Contar como "abierto" todos los que no están resueltos
			if (t.estado != "Resuelto") totalAbiertos++;

			// Contar por tipo en últimos 30 días
			tm fechaTicket{};
			istringstream ss2(t.fecha);
			ss2 >> get_time(&fechaTicket, "%Y-%m-%d");
			time_t fechaTicket_t = mktime(&fechaTicket);
			double diasDesde = difftime(now, fechaTicket_t) / (60 * 60 * 24);

			if (diasDesde <= 30) {
				if (t.tipo == "Reclamo") reclamos30dias++;
				else if (t.tipo == "Consulta") consultas30dias++;
				else if (t.tipo == "Sugerencia") sugerencias30dias++;
			}
		}

		// Restaurar la pila original
		while (!pilaTemporal.esVacia()) {
			pilaTickets.apilar(pilaTemporal.desapilar());
		}

		// Mostrar reporte
		cout << "== Estadísticas del Módulo de Soporte ==" << endl;
		cout << "Fecha del Reporte: " << (1900 + fechaActual.tm_year) << "-"
			<< setw(2) << setfill('0') << (1 + fechaActual.tm_mon) << "-"
			<< setw(2) << setfill('0') << fechaActual.tm_mday << endl << endl;

		cout << "-- Tickets por Estado --" << endl;
		cout << "Nuevos:                  " << nuevos << endl;
		cout << "Abiertos:                " << abiertos << endl;
		cout << "En Proceso:              " << enProceso << endl;
		cout << "Esperando Respuesta:     " << esperandoRespuesta << endl;
		cout << "Resueltos (últimos 7 días): " << resueltos7dias << endl;
		cout << "Total Abiertos:          " << totalAbiertos << endl;
		cout << endl;

		cout << "-- Solicitudes por Tipo (últimos 30 días) --" << endl;
		cout << "Reclamos:                " << reclamos30dias << endl;
		cout << "Consultas:               " << consultas30dias << endl;
		cout << "Sugerencias:             " << sugerencias30dias << endl;
		cout << "-------------------------------------------------" << endl;

		cout << "(0) Volver";
		char op = _getch();
	}

};