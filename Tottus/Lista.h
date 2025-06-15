#pragma once
#include "Nodo.h"
#include <functional>
#include <iostream>

using namespace std;

typedef unsigned int uint;

template <class T>
class Lista {
private:
    Nodo<T>* nodo;
    typedef function<int(T, T)> Comp;
    Nodo<T>* ini;
    uint lon; // número de elementos en la lista
public:
    Lista() : ini(nullptr), lon(0) { nodo = new Nodo<T>(); }
    ~Lista() {
        Nodo<T>* current = ini;
        while (current != nullptr) {
            Nodo<T>* next = current->get_Sgte();
            delete current;
            current = next;
        }
        lon = 0;
    }
    Lista(Nodo<T>* pNodo) {
        nodo = pNodo;
    };
    uint longitud();
    bool esVacia();
    void agregaInicial(T elem);
    void agregaPos(T elem, uint pos);
    void agregaFinal(T elem);
    void modificarInicial(T elem);
    void modificarPos(T elem, uint pos);
    void modificarFinal(T elem);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos) const;
    T obtenerFinal();
    T buscar(T elem);

    // Métodos solicitados
    int getTam() const;
    T getValor(int pos) const;

    // Método para mostrar la lista
    void mostrar() const {
        Nodo<T>* aux = ini;
        int i = 1;
        while (aux != nullptr) {
            // Si T es Categoria, puedes usar getNombre()
            cout << "\t\t\t" << i << ". " << aux->get_Elem().getNombre() << endl;
            aux = aux->get_Sgte();
            ++i;
        }
        if (i == 1) {
            cout << "\t\t\t(No hay productos en esta categoría)" << endl;
        }
    }

    void agregar(T pNodo);
    T cabeza(void);
    Lista* resto(void);
    T suma(T i);
    int size();
    void borrar(void);
    void borrar_last();
    void concat(Lista<T>* l1);
    Lista<T>* copy(void);
    void tomar(int n);
    void addOrdenado(T d);
    bool esta(T d);
    void borrarDato(T d);
    void reemplazarPos(uint pos, T nuevoElem);
    void reemplazarPos1(uint pos, T nuevoElem);
    T buscarProducto(std::function<bool(T)> criterio);
    void vaciarLista() {
        while (!esVacia()) {
            eliminaPos(0);
        }
    }
};

template <class T>
uint Lista<T>::longitud() {
    return lon;
}
template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}
template <class T>
void Lista<T>::agregaInicial(T elem) {
    Nodo<T>* nuevo = new Nodo<T>(elem);
    if (ini == nullptr) {
        ini = nuevo;
    }
    else {
        nuevo->set_Sgte(ini);
        ini = nuevo;
    }
    lon++;
}
template <class T>
T Lista<T>::buscar(T elem) {
    Nodo<T>* aux = ini;
    while (aux != nullptr) {
        if (aux->get_Elem() == elem) {
            return aux->get_Elem();
        }
        aux = aux->get_Sgte();
    }
    return T();
}
template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo<T>* aux = ini;
        for (uint i = 1; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        Nodo<T>* nuevo = new Nodo<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        aux->set_Sgte(nuevo);
        lon++;
    }
}
template <class T>
void Lista<T>::agregaFinal(T elem) {
    agregaPos(elem, lon);
}
template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        Nodo<T>* aux = ini;
        ini = ini->get_Sgte();
        delete aux;
        lon--;
    }
}
template <class T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos >= lon) return;
    if (pos == 0) {
        eliminaInicial();
    }
    else {
        Nodo<T>* aux = ini;
        for (uint i = 0; i < pos - 1; i++) {
            aux = aux->get_Sgte();
        }
        Nodo<T>* temp = aux->get_Sgte();
        aux->set_Sgte(temp->get_Sgte());
        delete temp;
        lon--;
    }
}
template <class T>
void Lista<T>::eliminaFinal() {
    if (lon == 0) return;
    eliminaPos(lon - 1);
}
template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->set_Elem(elem);
    }
}
template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos < lon) {
        Nodo<T>* aux = ini;
        for (uint i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        aux->set_Elem(elem);
    }
}
template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificarPos(elem, lon - 1);
}
template <class T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}
template <class T>
T Lista<T>::obtenerPos(uint pos) const{
    if (pos < lon) {
        Nodo<T>* aux = ini;
        for (uint i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        return aux->get_Elem();
    }
    else {
        return T();
    }
}
template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}
template <class T>
void Lista<T>::agregar(T d) {
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_Sgte(nodo);
    nodo = nuevo;
}
template <class T>
T Lista<T>::cabeza(void) {
    return nodo->get_Elem();
}
template <class T>
Lista<T>* Lista<T>::resto(void) {
    Lista<T>* l = new Lista<T>();
    l->nodo = nodo->get_Sgte();
    return l;
}
template <class T>
T Lista<T>::suma(T i) {
    Nodo<T>* aux = nodo;
    T sum = i;
    while (aux != nullptr) {
        sum += aux->get_Elem();
        aux = aux->get_Sgte();
    }
    return sum;
}
template <class T>
int Lista<T>::size() {
    Nodo<T>* aux = nodo;
    int cont = 0;
    while (aux != nullptr) {
        cont++;
        aux = aux->get_Sgte();
    }
    return cont;
}
template <class T>
void Lista<T>::borrar(void) {
    if (nodo != nullptr) {
        Nodo<T>* temp = nodo;
        nodo = nodo->get_Sgte();
        delete temp;
    }
}
template <class T>
void Lista<T>::borrar_last() {
    if (nodo == nullptr) return;
    if (nodo->get_Sgte() == nullptr) {
        delete nodo;
        nodo = nullptr;
    }
    else {
        Nodo<T>* aux = nodo;
        while (aux->get_Sgte()->get_Sgte() != nullptr) {
            aux = aux->get_Sgte();
        }
        delete aux->get_Sgte();
        aux->set_Sgte(nullptr);
    }
}
template <class T>
void Lista<T>::concat(Lista<T>* l1) {
    Nodo<T>* aux = l1->nodo;
    while (aux != nullptr) {
        this->agregar(aux->get_Elem());
        aux = aux->get_Sgte();
    }
}
template <class T>
Lista<T>* Lista<T>::copy(void) {
    Lista<T>* nueva = new Lista<T>();
    Nodo<T>* aux = nodo;
    Nodo<T>* ant = nullptr;
    while (aux != nullptr) {
        Nodo<T>* nuevo = new Nodo<T>(aux->get_Elem());
        if (ant == nullptr) {
            nueva->nodo = nuevo;
        }
        else {
            ant->set_Sgte(nuevo);
        }
        ant = nuevo;
        aux = aux->get_Sgte();
    }
    return nueva;
}
template <class T>
void Lista<T>::tomar(int n) {
    Nodo<T>* aux = nodo;
    int cont = 1;
    while (aux != nullptr && cont < n) {
        aux = aux->get_Sgte();
        cont++;
    }
    if (aux != nullptr && aux->get_Sgte() != nullptr) {
        Nodo<T>* temp = aux->get_Sgte();
        aux->set_Sgte(nullptr);
        while (temp != nullptr) {
            Nodo<T>* borrar = temp;
            temp = temp->get_Sgte();
            delete borrar;
        }
    }
}
template <class T>
void Lista<T>::addOrdenado(T d) {
    Nodo<T>* nuevo = new Nodo<T>(d);
    if (nodo == nullptr || nodo->get_Elem() >= d) {
        nuevo->set_Sgte(nodo);
        nodo = nuevo;
    }
    else {
        Nodo<T>* aux = nodo;
        while (aux->get_Sgte() != nullptr && aux->get_Sgte()->get_Elem() < d) {
            aux = aux->get_Sgte();
        }
        nuevo->set_Sgte(aux->get_Sgte());
        aux->set_Sgte(nuevo);
    }
}
template <class T>
bool Lista<T>::esta(T d) {
    Nodo<T>* aux = nodo;
    while (aux != nullptr) {
        if (aux->get_Elem() == d) {
            return true;
        }
        aux = aux->get_Sgte();
    }
    return false;
}
template <class T>
void Lista<T>::borrarDato(T d) {
    if (nodo == nullptr) return;
    if (nodo->get_Elem() == d) {
        Nodo<T>* temp = nodo;
        nodo = nodo->get_Sgte();
        delete temp;
        return;
    }
    Nodo<T>* aux = nodo;
    while (aux->get_Sgte() != nullptr) {
        if (aux->get_Sgte()->get_Elem() == d) {
            Nodo<T>* temp = aux->get_Sgte();
            aux->set_Sgte(temp->get_Sgte());
            delete temp;
            return;
        }
        aux = aux->get_Sgte();
    }
}
template <class T>
void Lista<T>::reemplazarPos(uint pos, T nuevoElem) {
    if (pos < lon) {
        Nodo<T>* aux = ini;
        for (uint i = 0; i < pos; ++i) {
            aux = aux->get_Sgte();
        }
        aux->set_Elem(nuevoElem);
    }
}
template <class T>
void Lista<T>::reemplazarPos1(uint pos, T nuevoElem) {
    if (pos < lon) {
        Nodo<T>* aux = ini;
        for (uint i = 0; i < pos; ++i) {
            aux = aux->get_Sgte();
        }
        aux->set_Elem(nuevoElem);
    }
}
template <typename T>
T Lista<T>::buscarProducto(std::function<bool(T)> criterio) {
    Nodo<T>* aux = ini;
    while (aux != nullptr) {
        if (criterio(aux->get_Elem())) {
            return aux->get_Elem();
        }
        aux = aux->get_Sgte();
    }
    return T();
}

// Implementación de los métodos solicitados
template <class T>
int Lista<T>::getTam() const {
    return static_cast<int>(lon);
}

template <class T>
T Lista<T>::getValor(int pos) const {
    return obtenerPos(static_cast<uint>(pos));
}
