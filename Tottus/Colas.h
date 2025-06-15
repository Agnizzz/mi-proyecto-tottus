#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;

template <class T>
class Cola
{
private:
    Nodo<T>* inicio;
    Nodo<T>* fin;

public:
    Cola()
    {
        this->inicio = nullptr;
        this->fin = nullptr;
    }
    void encolar(T v);
    T desencolar();
    bool esVacia();
};
template <class T>
bool Cola<T>::esVacia() {
    return (inicio == nullptr);
}
template <class T>
void Cola<T>::encolar(T v) {
    Nodo<T>* nodo = new Nodo<T>(v);
    if (esVacia()) {
        inicio = nodo;
        fin = inicio;
    }
    else{
        fin->set_Sgte(nodo);
        fin = nodo;
    }
}
template <class T>
T Cola<T>::desencolar() {
    if (esVacia()) {
        throw std::out_of_range("La cola está vacía");
    }
    T dato = inicio->get_Elem();
    Nodo<T>* temp = inicio;
    inicio = inicio->get_Sgte();
    delete temp;
    if (inicio == nullptr) {
        fin = nullptr;
    }
    return dato;
}


