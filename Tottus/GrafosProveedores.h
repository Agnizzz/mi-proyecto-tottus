#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Grafos.h"
// Aseg�rate de incluir la definici�n de tu clase CGrafoString
// #include "CGrafoString.h" 

using namespace std;

class ProveedoresGrafo {
private:
    CGrafoString* grafo;
    // Nombres cortos para la matriz de adyacencia
    string nombres[5] = { "Gloria", "San Fernando", "Coste�o", "Alicorp", "Backus" };

public:
    // Constructor
    ProveedoresGrafo() {
        grafo = new CGrafoString();
        inicializarGrafo();
    }

    // Destructor
    ~ProveedoresGrafo() {
        delete grafo;
    }

    // Funci�n para inicializar el grafo con proveedores y sus relaciones
    void inicializarGrafo() {
        // === V�rtices: Nuestros Proveedores ===
        int gloria = grafo->adicionarVertice("Gloria S.A.");           // 0
        int sanFernando = grafo->adicionarVertice("San Fernando S.A.");  // 1
        int costeno = grafo->adicionarVertice("Coste�o Alimentos");     // 2
        int alicorp = grafo->adicionarVertice("Alicorp S.A.A.");         // 3
        int backus = grafo->adicionarVertice("Backus y Johnston");      // 4

        // === Arcos: Las relaciones comerciales entre ellos ===
        // Gloria (0)
        grafo->adicionarArco(gloria, sanFernando);
        grafo->modificarArco(gloria, 0, "Acuerdo Logistico");

        // San Fernando (1)
        grafo->adicionarArco(sanFernando, alicorp);
        grafo->modificarArco(sanFernando, 0, "Socio Mayorista");

        // Coste�o (2)
        grafo->adicionarArco(costeno, alicorp);
        grafo->modificarArco(costeno, 0, "Competencia Directa");

        // Alicorp (3)
        grafo->adicionarArco(alicorp, gloria);
        grafo->modificarArco(alicorp, 0, "Alianza Estrategica");

        grafo->adicionarArco(alicorp, backus);
        grafo->modificarArco(alicorp, 1, "Acuerdo Logistico");

        // Backus (4)
        // No tiene arcos de salida en este ejemplo
    }

    // Funci�n para mostrar el encabezado
    void mostrarEncabezado() {
        cout << "==================================================" << endl;
        cout << "         RED DE PROVEEDORES TOTTUS - GRAFOS" << endl;
        cout << "==================================================" << endl << endl;
        cout << "Total de proveedores principales: " << grafo->cantidadVertices() << endl;
        cout << "Relaciones comerciales establecidas." << endl << endl;
    }

    // Funci�n para mostrar la red de relaciones
    void mostrarRedDeRelaciones() {
        cout << "==================================================" << endl;
        cout << "           RED DE RELACIONES COMERCIALES" << endl;
        cout << "==================================================" << endl << endl;

        for (int i = 0; i < grafo->cantidadVertices(); i++) {
            cout << "===================================================" << endl;
            cout << " PROVEEDOR: " << grafo->obtenerVertice(i) << endl;
            cout << "===================================================" << endl;

            if (grafo->cantidadArcos(i) == 0) {
                cout << " Sin relaciones salientes registradas." << endl;
            }
            else {
                cout << " Relaciones con:" << endl;
                for (int j = 0; j < grafo->cantidadArcos(i); j++) {
                    int destinoIdx = grafo->obtenerVerticeLlegada(i, j);
                    string tipoRelacion = grafo->obtenerArco(i, j);
                    string nombreDestino = grafo->obtenerVertice(destinoIdx);

                    cout << "    -> " << left << setw(25) << nombreDestino
                        << " [" << tipoRelacion << "]" << endl;
                }
            }
            cout << "===================================================\n" << endl;
        }
    }

    // Funci�n para mostrar la matriz de adyacencia
    void mostrarMatrizAdyacencia() {
        cout << "==================================================" << endl;
        cout << "              MATRIZ DE ADYACENCIA" << endl;
        cout << "==================================================" << endl << endl;

        cout << setw(15) << " ";
        for (int i = 0; i < grafo->cantidadVertices(); i++) {
            cout << setw(15) << nombres[i];
        }
        cout << endl;

        for (int i = 0; i < grafo->cantidadVertices(); i++) {
            cout << setw(15) << nombres[i];
            for (int j = 0; j < grafo->cantidadVertices(); j++) {
                string relacion = "-";
                for (int k = 0; k < grafo->cantidadArcos(i); k++) {
                    if (grafo->obtenerVerticeLlegada(i, k) == j) {
                        relacion = "SI"; // Simplificado para la matriz
                        break;
                    }
                }
                if (i == j) {
                    cout << setw(15) << "SELF";
                }
                else {
                    cout << setw(15) << relacion;
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    // Funci�n principal que ejecuta la demo de proveedores
    void ejecutarDemo() {
        system("cls");
        mostrarEncabezado();
        mostrarRedDeRelaciones();
        //mostrarMatrizAdyacencia();
        cout << "==================================================" << endl;
        cout << "   Red de proveedores representada exitosamente" << endl;
        cout << "==================================================" << endl;
        system("pause");
    }
};