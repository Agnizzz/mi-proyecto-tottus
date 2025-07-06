#pragma once
#include <functional>
#include <iostream>

// Estructura del Nodo para el �rbol
template <typename T>
struct NodoArbol {
    T dato;
    NodoArbol* izq;
    NodoArbol* der;

    NodoArbol(T d) : dato(d), izq(nullptr), der(nullptr) {}
};

// Clase del �rbol Binario de B�squeda
template <typename T>
class ArbolBinarioBusqueda {
private:
    NodoArbol<T>* raiz;

    // M�todo auxiliar privado para insertar un nodo recursivamente
    void insertar(NodoArbol<T>*& nodo, T dato, const std::function<int(T, T)>& comparador) {
        if (nodo == nullptr) {
            nodo = new NodoArbol<T>(dato);
        }
        else {
            int cmp = comparador(dato, nodo->dato);
            if (cmp < 0) {
                insertar(nodo->izq, dato, comparador);
            }
            else if (cmp > 0) {
                insertar(nodo->der, dato, comparador);
            }
            // Si cmp es 0, el �tem est� duplicado, as� que no lo insertamos.
        }
    }

    //NUEVO
    NodoArbol<T>* _insertar_con_operador(NodoArbol<T>* nodo, T dato) {
        if (nodo == nullptr) {
            return new NodoArbol<T>(dato);
        }
        if (dato < nodo->dato) {
            nodo->izq = _insertar_con_operador(nodo->izq, dato);
        }
        else if (dato > nodo->dato) {
            nodo->der = _insertar_con_operador(nodo->der, dato);
        }
        return nodo;
    }

    // M�todo auxiliar privado para buscar un nodo recursivamente
    NodoArbol<T>* buscar(NodoArbol<T>* nodo, T clave, const std::function<int(T, T)>& comparador) {
        if (nodo == nullptr) {
            return nullptr;
        }

        int cmp = comparador(clave, nodo->dato);
        if (cmp == 0) {
            return nodo; // Encontrado
        }
        else if (cmp < 0) {
            return buscar(nodo->izq, clave, comparador);
        }
        else {
            return buscar(nodo->der, clave, comparador);
        }
    }

    // M�todo auxiliar privado para limpiar el �rbol y liberar memoria
    void destruir(NodoArbol<T>* nodo) {
        if (nodo) {
            destruir(nodo->izq);
            destruir(nodo->der);
            // Si T es un puntero, el objeto al que apunta debe ser eliminado por separado.
            delete nodo;
        }
    }

    // La funci�n recursiva privada
    void _inOrden(NodoArbol<T>* nodo, function<void(T)> procesar) {
        if (nodo == nullptr) return;
        _inOrden(nodo->izq, procesar);
        procesar(nodo->dato); // Procesa el nodo actual
        _inOrden(nodo->der, procesar);
    }

public:
    ArbolBinarioBusqueda() : raiz(nullptr) {}

    ~ArbolBinarioBusqueda() {
        destruir(raiz);
    }

    // M�todo p�blico para insertar datos
    // La funci�n de comparaci�n debe devolver:
    // -1 si a < b
    //  0 si a == b
    //  1 si a > b
    void insertar(T dato, const std::function<int(T, T)>& comparador) {
        insertar(raiz, dato, comparador);
    }
    //nuevo
    void insertar(T dato) {
        raiz = _insertar_con_operador(raiz, dato);
    }

    // M�todo p�blico para buscar datos
    NodoArbol<T>* buscar(T clave, const std::function<int(T, T)>& comparador) {
        return buscar(raiz, clave, comparador);
    }
    // Permite ejecutar una acci�n en cada nodo del �rbol en orden
    void inOrden(function<void(T)> procesar) {
        _inOrden(raiz, procesar); // Llama a una funci�n auxiliar recursiva
    }
};