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
        int limaCentro = grafo->adicionarVertice("Tottus Lima Centro");    // 5
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
        cout << "==================================================" << endl;
        cout << "        MAPA DE TIENDAS TOTTUS - GRAFOS" << endl;
        cout << "==================================================" << endl;
        cout << endl;
        cout << "Total de tiendas: " << grafo->cantidadVertices() << endl;
        cout << "Conexiones establecidas exitosamente" << endl;
        cout << endl;
    }

    // Función para mostrar el mapa visual
    void mostrarMapaVisual() {
        cout << "==================================================" << endl;
        cout << "           MAPA DE DISTANCIAS VISUAL" << endl;
        cout << "==================================================" << endl;
        cout << endl;

        for (int i = 0; i < grafo->cantidadVertices(); i++) {
            cout << "===================================================" << endl;
            cout << setw(47) << left << grafo->obtenerVertice(i) << endl;
            cout << "===================================================" << endl;

            if (grafo->cantidadArcos(i) == 0) {
                cout << " Sin conexiones directas                         " << endl;
            }
            else {
                cout << " Conexiones:                                     " << endl;
                for (int j = 0; j < grafo->cantidadArcos(i); j++) {
                    int destino = grafo->obtenerVerticeLlegada(i, j);
                    string distancia = grafo->obtenerArco(i, j);
                    string nombreDestino = grafo->obtenerVertice(destino);

                    cout << "   -> " << setw(30) << left << nombreDestino
                        << " [" << distancia << "]" << setw(6) << endl;
                }
            }//=========================================================
            cout << "===================================================" << endl;
            cout << endl;
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
        cout << "==================================================" << endl;
        cout << "                  ESTADISTICAS" << endl;
        cout << "==================================================" << endl;
        cout << endl;

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

        system("pause");
    }

    // Función para obtener el grafo (si necesitas acceso directo)
    CGrafoString* obtenerGrafo() {
        return grafo;
    }
};



#endif // TOTTUS_GRAFO_H