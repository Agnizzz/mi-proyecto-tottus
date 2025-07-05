#pragma once
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include "GestionCategorias.h"
using namespace std;

// Tabla hash con encadenamiento para almacenar boletas
template <typename T>
class HashTable {
private:
    list<T*>* tabla;  // Array de listas din�mico
    int currentSize;
    int tableSize;

    // Funci�n hash mejorada
    int hash(const string& dni) const {
        int suma = 0;
        for (char c : dni) {
            suma = suma * 31 + c;  // Mejor distribuci�n que solo sumar
        }
        return abs(suma) % tableSize;
    }

    // Verificar si un n�mero es primo
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    // Encontrar el siguiente primo
    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

    // Rehashing cuando la tabla crece mucho
    void rehash() {
        int oldSize = tableSize;
        list<T*>* oldTabla = tabla;

        // Crear nueva tabla con tama�o primo
        tableSize = nextPrime(2 * oldSize);
        tabla = new list<T*>[tableSize];
        currentSize = 0;

        // Reinsertar todos los elementos
        for (int i = 0; i < oldSize; i++) {
            for (T* elemento : oldTabla[i]) {
                insertar(elemento);
            }
        }

        delete[] oldTabla;
    }

public:
    // Constructor
    explicit HashTable(int size = 101) : currentSize(0) {
        tableSize = nextPrime(size);
        tabla = new list<T*>[tableSize];
    }

    // Destructor
    ~HashTable() {
        delete[] tabla;
    }

    // Insertar elemento
    void insertar(T* elemento) {
        if (elemento == nullptr) return;

        int indice = hash(elemento->getDNI());

        // Verificar si ya existe (evitar duplicados)
        for (T* existente : tabla[indice]) {
            if (existente->getNumeroBoleta() == elemento->getNumeroBoleta()) {
                return; // Ya existe
            }
        }

        tabla[indice].push_back(elemento);
        currentSize++;

        // Rehash si el factor de carga es muy alto
        if (currentSize > tableSize) {
            rehash();
        }
    }

    // Buscar por DNI y n�mero de boleta
    T* buscar(const string& dni, int numeroBoleta) {
        int indice = hash(dni);
        for (T* elemento : tabla[indice]) {
            if (elemento->getDNI() == dni && elemento->getNumeroBoleta() == numeroBoleta) {
                return elemento;
            }
        }
        return nullptr;
    }

    // Verificar si contiene un elemento
    bool contains(const string& dni, int numeroBoleta) {
        return buscar(dni, numeroBoleta) != nullptr;
    }

    // Eliminar elemento
    bool remove(const string& dni, int numeroBoleta) {
        int indice = hash(dni);
        auto& lista = tabla[indice];

        auto it = find_if(lista.begin(), lista.end(),
            [dni, numeroBoleta](T* elemento) {
                return elemento->getDNI() == dni && elemento->getNumeroBoleta() == numeroBoleta;
            });

        if (it != lista.end()) {
            lista.erase(it);
            currentSize--;
            return true;
        }
        return false;
    }

    // Mostrar todas las boletas
    void mostrarTodas() {
        cout << "=== TABLA HASH COMPLETA ===" << endl;
        bool hayElementos = false;

        for (int i = 0; i < tableSize; i++) {
            if (!tabla[i].empty()) {
                cout << "\n--- Indice " << i << " (Hash: " << i << ") ---" << endl;
                for (T* elemento : tabla[i]) {
                    elemento->mostrarBoleta();
                    hayElementos = true;
                }
            }
        }

        if (!hayElementos) {
            cout << "La tabla hash esta vacia." << endl;
        }

        cout << "\nEstad�sticas:" << endl;
        cout << "Elementos totales: " << currentSize << endl;
        cout << "Tama�o de tabla: " << tableSize << endl;
        cout << "Factor de carga: " << (double)currentSize / tableSize << endl;
    }

    // Buscar todas las boletas por DNI
    void buscarPorDNI(const string& dni) {
        int indice = hash(dni);
        bool encontrado = false;

        cout << "=== BOLETAS PARA DNI: " << dni << " ===" << endl;

        for (T* elemento : tabla[indice]) {
            if (elemento->getDNI() == dni) {
                elemento->mostrarBoleta();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron boletas con DNI: " << dni << endl;
        }
    }

    // Vaciar la tabla
    void makeEmpty() {
        for (int i = 0; i < tableSize; i++) {
            tabla[i].clear();
        }
        currentSize = 0;
    }

    // Obtener tama�o actual
    int size() const {
        return currentSize;
    }

    // Verificar si est� vac�a
    bool empty() const {
        return currentSize == 0;
    }

    // Mostrar estad�sticas de distribuci�n
    void mostrarEstadisticas() {
        cout << "\n=== ESTAD�STICAS DE LA TABLA HASH ===" << endl;
        cout << "Tama�o de tabla: " << tableSize << endl;
        cout << "Elementos totales: " << currentSize << endl;
        cout << "Factor de carga: " << (double)currentSize / tableSize << endl;

        int buckets_usados = 0;
        int max_colisiones = 0;

        for (int i = 0; i < tableSize; i++) {
            if (!tabla[i].empty()) {
                buckets_usados++;
                max_colisiones = max(max_colisiones, (int)tabla[i].size());
            }
        }

        cout << "Buckets utilizados: " << buckets_usados << "/" << tableSize << endl;
        cout << "M�ximas colisiones en un bucket: " << max_colisiones << endl;
        cout << "Eficiencia: " << (double)buckets_usados / tableSize * 100 << "%" << endl;
    }
};