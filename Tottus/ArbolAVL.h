#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// Estructura del Nodo para el �rbol AVL
template<class T>
class NodoAVL {
public:
    T elemento;
    NodoAVL* izq;
    NodoAVL* der;
    int altura;

    NodoAVL() {
        izq = nullptr;
        der = nullptr;
        altura = 1;
    }

    NodoAVL(T dato) {
        elemento = dato;
        izq = nullptr;
        der = nullptr;
        altura = 1;
    }
};

// Clase ArbolAVL adaptada para tu proyecto
template<class T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;
    function<int(T, T)> comparador; // Funci�n de comparaci�n personalizable
    void(*procesar)(T); // Puntero a funci�n para recorridos

    // Operaciones privadas
    int _altura(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return 0;
        return nodo->altura;
    }

    int _factorBalance(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return 0;
        return _altura(nodo->der) - _altura(nodo->izq);
    }

    void _actualizarAltura(NodoAVL<T>* nodo) {
        if (nodo != nullptr) {
            nodo->altura = 1 + max(_altura(nodo->izq), _altura(nodo->der));
        }
    }

    void _rotarDerecha(NodoAVL<T>*& nodo) {
        NodoAVL<T>* p = nodo->izq;
        nodo->izq = p->der;
        p->der = nodo;

        // Actualizar alturas
        _actualizarAltura(nodo);
        _actualizarAltura(p);

        nodo = p;
    }

    void _rotarIzquierda(NodoAVL<T>*& nodo) {
        NodoAVL<T>* p = nodo->der;
        nodo->der = p->izq;
        p->izq = nodo;

        // Actualizar alturas
        _actualizarAltura(nodo);
        _actualizarAltura(p);

        nodo = p;
    }

    void _balancear(NodoAVL<T>*& nodo) {
        if (nodo == nullptr) return;

        // Actualizar altura del nodo actual
        _actualizarAltura(nodo);

        // Obtener factor de balance
        int fb = _factorBalance(nodo);

        // Caso Left Left
        if (fb < -1 && _factorBalance(nodo->izq) <= 0) {
            _rotarDerecha(nodo);
        }
        // Caso Right Right
        else if (fb > 1 && _factorBalance(nodo->der) >= 0) {
            _rotarIzquierda(nodo);
        }
        // Caso Left Right
        else if (fb < -1 && _factorBalance(nodo->izq) > 0) {
            _rotarIzquierda(nodo->izq);
            _rotarDerecha(nodo);
        }
        // Caso Right Left
        else if (fb > 1 && _factorBalance(nodo->der) < 0) {
            _rotarDerecha(nodo->der);
            _rotarIzquierda(nodo);
        }
    }

    bool _insertar(NodoAVL<T>*& nodo, T elemento) {
        if (nodo == nullptr) {
            nodo = new NodoAVL<T>(elemento);
            return true;
        }

        int cmp = comparador(elemento, nodo->elemento);

        if (cmp < 0) {
            if (_insertar(nodo->izq, elemento)) {
                _balancear(nodo);
                return true;
            }
        }
        else if (cmp > 0) {
            if (_insertar(nodo->der, elemento)) {
                _balancear(nodo);
                return true;
            }
        }
        else {
            // Elemento duplicado
            return false;
        }

        return false;
    }

    NodoAVL<T>* _buscar(NodoAVL<T>* nodo, T clave) {
        if (nodo == nullptr) return nullptr;

        int cmp = comparador(clave, nodo->elemento);

        if (cmp == 0) {
            return nodo;
        }
        else if (cmp < 0) {
            return _buscar(nodo->izq, clave);
        }
        else {
            return _buscar(nodo->der, clave);
        }
    }

    void _inOrden(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return;
        _inOrden(nodo->izq);
        if (procesar != nullptr) {
            procesar(nodo->elemento);
        }
        _inOrden(nodo->der);
    }

    void _preOrden(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return;
        if (procesar != nullptr) {
            procesar(nodo->elemento);
        }
        _preOrden(nodo->izq);
        _preOrden(nodo->der);
    }

    void _postOrden(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return;
        _postOrden(nodo->izq);
        _postOrden(nodo->der);
        if (procesar != nullptr) {
            procesar(nodo->elemento);
        }
    }

    int _contarNodos(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + _contarNodos(nodo->izq) + _contarNodos(nodo->der);
    }

    void _mostrarAlturas(NodoAVL<T>* nodo) {
        if (nodo == nullptr) return;
        _mostrarAlturas(nodo->izq);
        cout << "Altura: " << nodo->altura << " ";
        _mostrarAlturas(nodo->der);
    }

    void _destruir(NodoAVL<T>* nodo) {
        if (nodo != nullptr) {
            _destruir(nodo->izq);
            _destruir(nodo->der);
            delete nodo;
        }
    }

    // AHORA (LA CORRECCI�N):
  // Aseg�rate de que el tipo del par�metro 'nodo' sea 'Nodo<T>*', igual que tu 'raiz'.
    void _buscarYProcesarCoincidencias(NodoAVL<T>* nodo, const string& termino, function<void(T)> procesador) {
        if (nodo == nullptr) return;

        // El resto de la funci�n no cambia
        _buscarYProcesarCoincidencias(nodo->izq, termino, procesador);

        // Aqu� tambi�n debes asegurarte de que nodo->elemento.nombre exista.
        // En tu struct User, el campo es 'nombre'.
        if (nodo->elemento.nombre.find(termino) != string::npos) {
            procesador(nodo->elemento);
        }

        _buscarYProcesarCoincidencias(nodo->der, termino, procesador);
    }

public:
    // Constructor con funci�n de comparaci�n personalizable
    ArbolAVL(const function<int(T, T)>& comp, void(*nuevaFuncion)(T) = nullptr) {
        this->comparador = comp;
        this->procesar = nuevaFuncion;
        this->raiz = nullptr;
    }

    // Constructor con funci�n de procesamiento (compatible con c�digo del profesor)
    ArbolAVL(void(*nuevaFuncion)(T)) {
        this->procesar = nuevaFuncion;
        this->raiz = nullptr;

        // Comparador por defecto (requiere operadores <, >, ==)
        this->comparador = [](T a, T b) -> int {
            if (a < b) return -1;
            if (a > b) return 1;
            return 0;
            };
    }

    ~ArbolAVL() {
        _destruir(raiz);
    }

    // M�todos p�blicos
    bool insertar(T elemento) {
        return _insertar(raiz, elemento);
    }

    bool buscar(T clave) {
        return _buscar(raiz, clave) != nullptr;
    }

    T* obtenerElemento(T clave) {
        NodoAVL<T>* nodo = _buscar(raiz, clave);
        if (nodo != nullptr) {
            return &(nodo->elemento);
        }
        return nullptr;
    }

    NodoAVL<T>* obtenerNodo(T clave) {
        return _buscar(raiz, clave);
    }

    void inOrden() {
        _inOrden(raiz);
    }

    void preOrden() {
        _preOrden(raiz);
    }

    void postOrden() {
        _postOrden(raiz);
    }

    int contarNodos() {
        return _contarNodos(raiz);
    }

    void mostrarAlturas() {
        cout << "Alturas de los nodos: ";
        _mostrarAlturas(raiz);
        cout << endl;
    }

    bool estaVacio() {
        return raiz == nullptr;
    }

    int obtenerAltura() {
        return _altura(raiz);
    }

    // M�todo para cambiar la funci�n de procesamiento
    void establecerProcesador(void(*nuevaFuncion)(T)) {
        this->procesar = nuevaFuncion;
    }

    // M�todo para obtener estad�sticas del �rbol
    void mostrarEstadisticas() {
        cout << "=== ESTADISTICAS DEL ARBOL AVL ===" << endl;
        cout << "N�mero de nodos: " << contarNodos() << endl;
        cout << "Altura del arbol: " << obtenerAltura() << endl;
        cout << "Esta vacio: " << (estaVacio() ? "Si" : "No") << endl;
        cout << "Factor de balance de la raiz: " << _factorBalance(raiz) << endl;
    }

    // Y REEMPL�ZALA POR ESTA:
  // Ahora recibe una funci�n para procesar cada coincidencia que encuentre
    void buscarYProcesarCoincidencias(const string& termino, function<void(T)> procesadorCoincidencia) {
        _buscarYProcesarCoincidencias(raiz, termino, procesadorCoincidencia);
    }

    // Nuevo m�todo "obtener" para recuperar un elemento espec�fico
    T obtener(T clave) {
        NodoAVL<T>* nodoEncontrado = _buscar(raiz, clave);
        if (nodoEncontrado != nullptr) {
            return nodoEncontrado->elemento; // Retorna el elemento encontrado
        }
        else {
            throw std::runtime_error("Elemento no encontrado en el �rbol AVL");
        }
    }

};