#ifndef TOTTUS_GRAFO_H
#define TOTTUS_GRAFO_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Grafos.h"
using namespace std;

class TottusGrafo {
private:
	CGrafoString* grafo;
	string nombres[7] = { "S.Miguel", "Miraflores", "S.Isidro", "L.Molina", "Surco", "L.Centro", "S.Borja" };

public:
	// Constructor
	TottusGrafo() {
		grafo = new CGrafoString();
		inicializarGrafo();
	}

	// Destructor
	~TottusGrafo() {
		delete grafo;
	}

	// Función para inicializar el grafo con tiendas y conexiones
	void inicializarGrafo() {
		// Agregar tiendas como vertices
		int sanMiguel = grafo->adicionarVertice("Tottus San Miguel");      // 0
		int miraflores = grafo->adicionarVertice("Tottus Miraflores");     // 1
		int sanIsidro = grafo->adicionarVertice("Tottus San Isidro");      // 2
		int laMolina = grafo->adicionarVertice("Tottus La Molina");        // 3
		int surco = grafo->adicionarVertice("Tottus Surco");               // 4
		int limaCentro = grafo->adicionarVertice("Tottus LimaCentro");    // 5
		int sanBorja = grafo->adicionarVertice("Tottus San Borja");        // 6

		// Agregar conexiones con distancias
		// San Miguel (0)
		grafo->adicionarArco(sanMiguel, miraflores);
		grafo->modificarArco(sanMiguel, 0, "8.5 km");

		grafo->adicionarArco(sanMiguel, limaCentro);
		grafo->modificarArco(sanMiguel, 1, "12.3 km");

		// Miraflores (1)
		grafo->adicionarArco(miraflores, sanIsidro);
		grafo->modificarArco(miraflores, 0, "4.7 km");

		grafo->adicionarArco(miraflores, surco);
		grafo->modificarArco(miraflores, 1, "7.8 km");

		// San Isidro (2)
		grafo->adicionarArco(sanIsidro, laMolina);
		grafo->modificarArco(sanIsidro, 0, "15.2 km");

		grafo->adicionarArco(sanIsidro, sanBorja);
		grafo->modificarArco(sanIsidro, 1, "5.1 km");

		// La Molina (3)
		grafo->adicionarArco(laMolina, surco);
		grafo->modificarArco(laMolina, 0, "9.4 km");

		// Surco (4)
		grafo->adicionarArco(surco, sanBorja);
		grafo->modificarArco(surco, 0, "3.8 km");

		// Lima Centro (5)
		grafo->adicionarArco(limaCentro, sanBorja);
		grafo->modificarArco(limaCentro, 0, "8.9 km");
	}

	// Función para mostrar el encabezado
	void mostrarEncabezado() {
		SetForegroundColor(LightMagenta);
		cout << "==================================================" << endl;
		cout << "        MAPA DE TIENDAS TOTTUS - GRAFOS" << endl;
		cout << "==================================================" << endl;
		cout << endl;
		SetForegroundColor(BrightWhite);
		cout << "Total de tiendas: " << grafo->cantidadVertices() << endl;
		cout << "Conexiones establecidas exitosamente" << endl;
		cout << endl;
	}

	// Función para mostrar el mapa visual en formato de cuadrícula
	void mostrarMapaVisual() {
		SetForegroundColor(Cyan);
		cout << "==================================================" << endl;
		cout << "           MAPA DE DISTANCIAS VISUAL" << endl;
		cout << "==================================================" << endl;
		cout << endl;

		const int TIENDAS_POR_FILA = 4;  // Número de tiendas a mostrar por fila
		const int ANCHO_TIENDA = 38;     // Ancho de cada columna de tienda
		SetForegroundColor(Green);
		for (int i = 0; i < grafo->cantidadVertices(); i += TIENDAS_POR_FILA) {
			// Imprimir encabezados de tiendas en esta fila
			for (int j = 0; j < TIENDAS_POR_FILA && i + j < grafo->cantidadVertices(); j++) {
				cout << setw(ANCHO_TIENDA) << left << "=================================";
				cout << "  ";
			}
			cout << endl;

			for (int j = 0; j < TIENDAS_POR_FILA && i + j < grafo->cantidadVertices(); j++) {
				cout << setw(ANCHO_TIENDA) << left << grafo->obtenerVertice(i + j);
				cout << "  ";
			}
			cout << endl;

			for (int j = 0; j < TIENDAS_POR_FILA && i + j < grafo->cantidadVertices(); j++) {
				cout << setw(ANCHO_TIENDA) << left << "=================================";
				cout << "  ";
			}
			cout << endl;
			SetForegroundColor(BrightWhite);
			// Determinar la cantidad máxima de conexiones para establecer altura uniforme
			int maxConexiones = 0;
			for (int j = 0; j < TIENDAS_POR_FILA && i + j < grafo->cantidadVertices(); j++) {
				int numConexiones = grafo->cantidadArcos(i + j);
				if (numConexiones > maxConexiones)
					maxConexiones = numConexiones;
			}
			maxConexiones = (maxConexiones == 0) ? 1 : maxConexiones; // Al menos mostrar una línea

			// Mostrar conexiones para todas las tiendas en esta fila
			for (int j = 0; j < TIENDAS_POR_FILA && i + j < grafo->cantidadVertices(); j++) {
				int tiendaIdx = i + j;
				if (grafo->cantidadArcos(tiendaIdx) == 0) {
					cout << setw(ANCHO_TIENDA) << left << " Sin conexiones directas";
				}
				else {
					cout << setw(ANCHO_TIENDA) << left << " Conexiones:";
				}
				cout << "  ";
			}
			cout << endl;

			// Imprimir cada conexión línea por línea
			for (int k = 0; k < maxConexiones; k++) {
				for (int j = 0; j < TIENDAS_POR_FILA && i + j < grafo->cantidadVertices(); j++) {
					int tiendaIdx = i + j;
					if (k < grafo->cantidadArcos(tiendaIdx)) {
						int destino = grafo->obtenerVerticeLlegada(tiendaIdx, k);
						string distancia = grafo->obtenerArco(tiendaIdx, k);
						string nombreDestino = grafo->obtenerVertice(destino);
						ostringstream conexionInfo;
						conexionInfo << "   -> " << nombreDestino << " [" << distancia << "]";
						cout << setw(ANCHO_TIENDA) << left << conexionInfo.str();
					}
					else {
						cout << setw(ANCHO_TIENDA) << " ";
					}
					cout << "  ";
				}
				cout << endl;
			}
			SetForegroundColor(Green);
			// Línea de separación entre grupos de tiendas
			for (int j = 0; j < TIENDAS_POR_FILA && i + j < grafo->cantidadVertices(); j++) {
				cout << setw(ANCHO_TIENDA) << left << "=================================";
				cout << "  ";
			}
			cout << endl << endl;
		}
	}

	// Función para mostrar la matriz de adyacencia
	void mostrarMatrizAdyacencia() {
		cout << "==================================================" << endl;
		cout << "              MATRIZ DE ADYACENCIA" << endl;
		cout << "==================================================" << endl;
		cout << endl;

		cout << setw(12) << " ";
		for (int i = 0; i < grafo->cantidadVertices(); i++) {
			cout << setw(12) << nombres[i];
		}
		cout << endl;

		for (int i = 0; i < grafo->cantidadVertices(); i++) {
			cout << setw(12) << nombres[i];
			for (int j = 0; j < grafo->cantidadVertices(); j++) {
				bool hayConexion = false;
				string distancia = "     -";

				// Buscar si hay conexión de i a j
				for (int k = 0; k < grafo->cantidadArcos(i); k++) {
					if (grafo->obtenerVerticeLlegada(i, k) == j) {
						hayConexion = true;
						distancia = grafo->obtenerArco(i, k);
						break;
					}
				}

				if (i == j) {
					cout << setw(12) << "  SELF";
				}
				else if (hayConexion) {
					cout << setw(12) << distancia;
				}
				else {
					cout << setw(12) << "     -";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	// Función para mostrar estadísticas
	void mostrarEstadisticas() {
		SetForegroundColor(Yellow);
		cout << "==================================================" << endl;
		cout << "                  ESTADISTICAS" << endl;
		cout << "==================================================" << endl;
		cout << endl;
		SetForegroundColor(BrightWhite);
		int totalConexiones = 0;
		for (int i = 0; i < grafo->cantidadVertices(); i++) {
			totalConexiones += grafo->cantidadArcos(i);
		}

		cout << "Total de tiendas: " << grafo->cantidadVertices() << endl;
		cout << "Total de conexiones: " << totalConexiones << endl;
		cout << "Promedio de conexiones por tienda: " << fixed << setprecision(1)
			<< (double)totalConexiones / grafo->cantidadVertices() << endl;

		cout << endl;
		cout << "Tienda con mas conexiones: ";
		int maxConexiones = 0;
		int tiendaMaxConexiones = 0;
		for (int i = 0; i < grafo->cantidadVertices(); i++) {
			if (grafo->cantidadArcos(i) > maxConexiones) {
				maxConexiones = grafo->cantidadArcos(i);
				tiendaMaxConexiones = i;
			}
		}
		cout << grafo->obtenerVertice(tiendaMaxConexiones)
			<< " (" << maxConexiones << " conexiones)" << endl;
		cout << endl;
	}

	// Función para mostrar el pie de página
	void mostrarPie() {
		SetForegroundColor(Red);
		cout << "==================================================" << endl;
		cout << "Grafo de tiendas Tottus creado exitosamente" << endl;
		cout << "==================================================" << endl;
	}

	// Función principal que ejecuta todo
	void ejecutarDemo() {
		system("cls");
		mostrarEncabezado();
		mostrarMapaVisual();
		//mostrarMatrizAdyacencia();
		mostrarEstadisticas();
		mostrarPie();

		system("pause>0");
		system("cls");
	}

	// Función para obtener el grafo (si necesitas acceso directo)
	CGrafoString* obtenerGrafo() {
		return grafo;
	}
};



#endif // TOTTUS_GRAFO_H