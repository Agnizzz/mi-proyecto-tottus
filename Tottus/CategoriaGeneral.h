#pragma once
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Categoria {
private:
    string id;
    string nombre;
    string unidadMedida;
    double precioUnitario;
    double precioDescuento;
    double precioFinal;
    int cantidad;

    void calcularPrecioFinal() {
        double precioAplicado = (precioDescuento > 0.0) ? precioDescuento : precioUnitario;
        precioFinal = precioAplicado * cantidad;
    }

public:
    Categoria()
        : id(""), nombre(""), unidadMedida(""), precioUnitario(0.0), precioDescuento(0.0), precioFinal(0.0), cantidad(1) {
    }

    Categoria(const string& pId, const string& pNombre, const string& punidadMedida, int pCantidad = 1)
        : id(pId), nombre(pNombre), unidadMedida(punidadMedida), precioUnitario(0.0), precioDescuento(0.0), precioFinal(0.0), cantidad(pCantidad) {
    }

    // Setters y getters (igual que antes)
    void setID(const string& pId) { id = pId; }
    const string& getID() const { return id; }
    void setNombre(const string& pNombre) { nombre = pNombre; }
    const string& getNombre() const { return nombre; }
    void setUnidadMedida(const string& punidadMedida) { unidadMedida = punidadMedida; }
    const string& getUnidadMedida() const { return unidadMedida; }
    void setPrecioUnitario(double pPrecio) { precioUnitario = pPrecio; calcularPrecioFinal(); }
    double getPrecioUnitario() const { return precioUnitario; }
    void setPrecioDescuento(double pPrecio) { precioDescuento = pPrecio; calcularPrecioFinal(); }
    double getPrecioDescuento() const { return precioDescuento; }
    void setCantidad(int pCantidad) { cantidad = pCantidad; calcularPrecioFinal(); }
    int getCantidad() const { return cantidad; }
    void setPrecioFinal(double) { calcularPrecioFinal(); }
    double getPrecioFinal() const { return precioFinal; }

    // Fila para la boleta (dos líneas)
    string toTicketRow(int width = 40) const {
        ostringstream oss;
        double precioAplicado = (precioDescuento > 0.0) ? precioDescuento : precioUnitario;
        // Línea 1: ID a la izquierda, precio a la derecha
        oss << left << setw(width - 10) << id
            << "S/. " << right << setw(6) << fixed << setprecision(2) << precioAplicado << "\n";
        // Línea 2: Nombre - unidad xCantidad
        oss << nombre << " - " << unidadMedida << " x" << cantidad;
        return oss.str();
    }
};
