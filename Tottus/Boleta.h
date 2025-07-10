#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <string>
#include "Lista.h"
#include"Usuario.h"
#include "CategoriaGeneral.h" // Asegúrate de que esta clase tenga getNombre, getPrecioUnitario, getCantidad
//SE HIZOOOOOOO CAMBIOOOOOOOOOS
using namespace std;
//crear una variante de class usuario para usar su metodo usuarioactual
//SistemaUsuarios* sistUser = new SistemaUsuarios(); // Instancia global para acceder al usuario actual
extern SistemaUsuarios* sisUsuarios;
//variable global boleta

class Boleta {
private:
    string nombreCliente;
    string dniCliente;
    string fecha;
    Lista<Categoria*> productos;
    double total;
    int numeroBoleta;

    string obtenerFechaActual() {
        auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        struct tm timeinfo;
        localtime_s(&timeinfo, &now);
        string fecha = to_string(timeinfo.tm_mday) + "/" +
            to_string(timeinfo.tm_mon + 1) + "/" +
            to_string(timeinfo.tm_year + 1900);
        return fecha;
    }

public:
    Boleta() : total(0.0), numeroBoleta(0) {
        fecha = obtenerFechaActual();
    }

    Boleta(string nombre, string dni, int numBoleta)
        : nombreCliente(nombre), dniCliente(dni), total(0.0), numeroBoleta(numBoleta) {
        fecha = obtenerFechaActual();
    }
    Lista<Categoria*>& getProductos() { return productos; } // <-- AÑADE ESTA LÍNEA NUEVAAAAAAAAAAAAAAAAAAAAA
    void agregarProducto(Categoria* producto) {
        //  Validar que el producto no sea nulo antes de agregarlo
        if (producto == nullptr) {
            cout << "Error: No se puede agregar un producto nulo." << endl;
            return;
        }
        productos.agregaFinal(producto);
        calcularTotal();
    }
    string getFecha() const { return fecha; }
    void calcularTotal() {
        total = 0;
        for (int i = 0; i < productos.longitud(); ++i) {
            Categoria* p = productos.obtenerPos(i);

            if (p != nullptr) {
                double precioUnitario = p->getPrecioUnitario();
                double descuento = p->getPrecioDescuento(); // ✅ porcentaje entre 0.0 y 1.0
                int cantidad = p->getCantidad();

                double precioFinalUnitario = precioUnitario * (1.0 - descuento);

                if (precioFinalUnitario >= 0 && cantidad >= 0) {
                    total += precioFinalUnitario * cantidad;
                }
                else {
                    cout << " Advertencia: Producto invalido (precio final unitario: "
                        << precioFinalUnitario << ", cantidad: " << cantidad << ")" << endl;
                }
            }
            else {
                cout << " Advertencia: Producto nulo en posicion " << i << endl;
            }
        }
    }

    void mostrarBoleta() {
        // 1. OBTENER DATOS DEL CLIENTE
        string nombreClienteActual = sistemaUsuarios->getUsuarioActual().nombre + " " +
            sistemaUsuarios->getUsuarioActual().apellido_paterno;
        string dniClienteActual = sistemaUsuarios->getUsuarioActual().DNI;

        // 2. CALCULAR TOTALES
        double totalPagar = 0.0;
        for (int i = 0; i < productos.longitud(); ++i) {
            Categoria* p = productos.obtenerPos(i);
            if (p == nullptr) continue;
            totalPagar += p->getPrecioUnitario() * p->getCantidad();
        }

        double opGravada = totalPagar / 1.18;
        double igv = totalPagar - opGravada;

        // 3. FORMATEAR NÚMERO DE BOLETA
        stringstream ss;
        ss << "B001-" << setfill('0') << setw(8) << this->numeroBoleta;
        string numeroBoletaFormateado = ss.str();

        // 4. MOSTRAR CABECERA
        cout << "----------------------------------------------------------" << endl;
        cout << "            BOLETA DE VENTA ELECTRONICA" << endl;
        cout << "                 " << numeroBoletaFormateado << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << left << setw(14) << "Fecha y Hora:" << this->fecha << endl;
        cout << left << setw(14) << "Cliente:" << nombreClienteActual << endl;
        cout << left << setw(14) << "DNI:" << dniClienteActual << endl;
        cout << "---------------------------------------------------------" << endl;

        // 5. CABECERA DE PRODUCTOS
        cout << left << setw(27) << "DESCRIPCION"
            << right << setw(6) << "CANT."
            << setw(11) << "P. UNIT."
            << setw(12) << "SUBTOTAL" << endl;
        cout << "---------------------------------------------------------" << endl;

        // 6. DETALLE DE PRODUCTOS
        for (int i = 0; i < productos.longitud(); ++i) {
            Categoria* p = productos.obtenerPos(i);
            if (p == nullptr) continue;

            double subtotal = p->getCantidad() * p->getPrecioUnitario();
            string nombre = p->getNombre();
            size_t largoMax = 26;
            size_t inicio = 0;
            bool primeraLinea = true;

            while (inicio < nombre.length()) {
                string fragmento = nombre.substr(inicio, largoMax);
                if (primeraLinea) {
                    cout << left << setw(27) << fragmento
                        << right << setw(6) << p->getCantidad()
                        << "   S/ " << setw(6) << fixed << setprecision(2) << p->getPrecioUnitario()
                        << "   S/ " << setw(6) << fixed << setprecision(2) << subtotal << endl;
                    primeraLinea = false;
                }
                else {
                    cout << left << setw(27) << fragmento << endl;
                }
                inicio += largoMax;
            }
        }

        // 7. TOTALES
        cout << "---------------------------------------------------------" << endl;
        cout << right << setw(40) << "OP. GRAVADA:   S/ " << setw(7) << fixed << setprecision(2) << opGravada << endl;
        cout << right << setw(40) << "IGV:           S/ " << setw(7) << fixed << setprecision(2) << igv << endl;
        cout << right << setw(40) << "TOTAL:         S/ " << setw(7) << fixed << setprecision(2) << totalPagar << endl;
        cout << "=========================================================" << endl;
        cout << left << "TOTAL A PAGAR:" << right << setw(35) << "S/. " << fixed << setprecision(2) << totalPagar << endl;
        cout << "=========================================================" << endl;


    }

    void guardarBoletaEnArchivo() {
        string nombreClienteActual = sistemaUsuarios->getUsuarioActual().nombre + " " +
            sistemaUsuarios->getUsuarioActual().apellido_paterno;
        string dniClienteActual = sistemaUsuarios->getUsuarioActual().DNI;

        ofstream archivo("Boletas.txt", ios::app);
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo para guardar la boleta." << endl;
            return;
        }

        // 1. Calcular totales
        double totalPagar = 0.0;
        for (int i = 0; i < productos.longitud(); ++i) {
            Categoria* p = productos.obtenerPos(i);
            if (p != nullptr) {
                totalPagar += p->getCantidad() * p->getPrecioUnitario();
            }
        }

        double opGravada = totalPagar / 1.18;
        double igv = totalPagar - opGravada;

        // 2. Formatear número boleta
        stringstream ss;
        ss << "B001-" << setfill('0') << setw(8) << this->numeroBoleta;
        string numeroBoletaFormateado = ss.str();

        // 3. Cabecera
        archivo << "----------------------------------------------------------" << endl;
        archivo << "            BOLETA DE VENTA ELECTRONICA" << endl;
        archivo << "                 " << numeroBoletaFormateado << endl;
        archivo << "----------------------------------------------------------" << endl;
        archivo << left << setw(14) << "Fecha y Hora:" << this->fecha << endl;
        archivo << left << setw(14) << "Cliente:" << nombreClienteActual << endl;
        archivo << left << setw(14) << "DNI:" << dniClienteActual << endl;
        archivo << "----------------------------------------------------------" << endl;

        // 4. Cabecera productos
        archivo << left << setw(27) << "DESCRIPCION"
            << right << setw(6) << "CANT."
            << setw(11) << "P. UNIT."
            << setw(12) << "SUBTOTAL" << endl;
        archivo << "----------------------------------------------------------" << endl;

        // 5. Detalle productos
        for (int i = 0; i < productos.longitud(); ++i) {
            Categoria* p = productos.obtenerPos(i);
            if (p == nullptr) continue;

            try {
                int cantidad = p->getCantidad();
                double precioOriginal = p->getPrecioUnitario();
                double totalProducto = precioOriginal * cantidad;

                if (precioOriginal < 0 || precioOriginal > 10000 || cantidad < 0 || cantidad > 1000) {
                    archivo << " Producto con datos inválidos en posición " << i << endl;
                    continue;
                }

                string nombre = p->getNombre();
                size_t largoMax = 26;
                size_t inicio = 0;
                bool primeraLinea = true;

                while (inicio < nombre.length()) {
                    string fragmento = nombre.substr(inicio, largoMax);
                    if (primeraLinea) {
                        archivo << left << setw(27) << fragmento
                            << right << setw(6) << cantidad
                            << "   S/ " << setw(6) << fixed << setprecision(2) << precioOriginal
                            << "   S/ " << setw(6) << fixed << setprecision(2) << totalProducto << endl;
                        primeraLinea = false;
                    }
                    else {
                        archivo << left << setw(27) << fragmento << endl;
                    }
                    inicio += largoMax;
                }
            }
            catch (...) {
                archivo << " Error al acceder a los datos del producto " << i << endl;
            }
        }

        // 6. Totales
        archivo << "----------------------------------------------------------" << endl;
        archivo << right << setw(40) << "OP. GRAVADA:   S/ " << setw(7) << fixed << setprecision(2) << opGravada << endl;
        archivo << right << setw(40) << "IGV:           S/ " << setw(7) << fixed << setprecision(2) << igv << endl;
        archivo << right << setw(40) << "TOTAL:         S/ " << setw(7) << fixed << setprecision(2) << totalPagar << endl;
        archivo << "==========================================================" << endl;
        archivo << left << "TOTAL A PAGAR:" << right << setw(35) << "S/. " << fixed << setprecision(2) << totalPagar << endl;
        archivo << "==========================================================" << endl;
        archivo << endl;

        // 7. Registro para reporte
        archivo << "[REPORTE] "
            << numeroBoleta << ";"
            << nombreClienteActual << ";"
            << fixed << setprecision(2) << totalPagar << endl;

        archivo.close();
    }
    // ✅ Método para validar la integridad de la boleta
    bool validarIntegridad() {
        for (int i = 0; i < productos.longitud(); ++i) {
            Categoria* p = productos.obtenerPos(i);
            if (p == nullptr) {
                cout << "Error: Producto nulo en posicion " << i << endl;
                return false;
            }

            try {
                // Intentar acceder a los métodos para verificar que el objeto es válido
                p->getNombre();
                p->getPrecioUnitario();
                p->getCantidad();
            }
            catch (...) {
                cout << "Error: Producto corrupto en posicion " << i << endl;
                return false;
            }
        }
        return true;
    }

    double getTotal() const {
        return total;
    }

    int getNumeroBoleta() const {
        return numeroBoleta;
    }

    string getCliente() const {
        return nombreCliente;
    }

    string getDNI() const {
        return dniCliente;
    }

    bool estaVacia() {
        return productos.longitud() == 0;
    }

    static void buscarPorNumero(Lista<Boleta*>& boletas, int numero, int indice = 0) {
        if (indice >= boletas.longitud()) {
            cout << "\nBoleta no encontrada." << endl;
            return;
        }

        Boleta* boleta = boletas.obtenerPos(indice);
        if (boleta != nullptr && boleta->getNumeroBoleta() == numero) {
            boleta->mostrarBoleta();
            return;
        }
        buscarPorNumero(boletas, numero, indice + 1);
    }

    static void buscarPorRangoPrecio(Lista<Boleta*>& boletas, double min, double max, int indice = 0) {
        if (indice >= boletas.longitud()) return;

        Boleta* b = boletas.obtenerPos(indice);
        if (b != nullptr && b->getTotal() >= min && b->getTotal() <= max) {
            b->mostrarBoleta();
        }

        buscarPorRangoPrecio(boletas, min, max, indice + 1);
    }
};

int generarNumeroBoletaUnico() {
    const string archivo = "contador_boleta.txt";
    int numero = 1000;

    // Leer el último número si el archivo existe
    ifstream entrada(archivo);
    if (entrada.is_open()) {
        entrada >> numero;
        entrada.close();
    }

    // Guardar el siguiente número
    ofstream salida(archivo);
    if (salida.is_open()) {
        salida << (numero + 1);
        salida.close();
    }

    return numero;
}
