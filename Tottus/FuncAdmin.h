#pragma once
#include <iostream>
#include <conio.h>
#include <chrono> 
#include <functional>
#include <algorithm> // Para std::sort NUEVO
#include <limits>    // Para std::numeric_limits NUEVO
#include "GestionCategorias.h"
#include "ArbolBB.h"
#include "Promociones.h"//NUEVO AGREGADO

//SE HIZO CAMBIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOS

using namespace std;
bool ofertasAplicadas = false;
extern Lista<Boleta*> listaBoletas;

// Árboles para indexar productos por diferentes atributos.
ArbolBinarioBusqueda<Categoria*> arbolPorId;
ArbolBinarioBusqueda<Categoria*> arbolPorNombre;
ArbolBinarioBusqueda<Categoria*> arbolPorPrecio;

// Para evitar fugas de memoria, usaremos tu clase Lista para guardar los punteros a las copias.
Lista<Categoria*> copiasDeProductos;



// Bandera para asegurar que los árboles se construyan una sola vez.
bool arbolesDeBusquedaInicializados = false;

// Funciones de comparación (lambdas), no cambian.
auto comparadorPorId = [](const Categoria* a, const Categoria* b) {
    if (a->getID() < b->getID()) return -1;
    if (a->getID() > b->getID()) return 1;
    return 0;
    };

auto comparadorPorNombre = [](const Categoria* a, const Categoria* b) {
    if (a->getNombre() < b->getNombre()) return -1;
    if (a->getNombre() > b->getNombre()) return 1;
    return 0;
    };

auto comparadorPorPrecio = [](const Categoria* a, const Categoria* b) {
    if (a->getPrecioUnitario() < b->getPrecioUnitario()) return -1;
    if (a->getPrecioUnitario() > b->getPrecioUnitario()) return 1;
    return 0;
    };


// Función para poblar los árboles de búsqueda desde el catálogo principal.
void inicializarArbolesDeBusqueda() {
    if (arbolesDeBusquedaInicializados) {
        return;
    }

    for (int i = 1; i <= numCategoriasPrincipales; ++i) {
        try {
            const auto& subcategoriasMap = catalogo.getPorIdPrincipal(i);
            for (const auto& parSub : subcategoriasMap) {
                for (const auto& parTer : parSub.second) {
                    const Lista<Categoria>& listaProds = parTer.second;
                    for (int j = 0; j < listaProds.getTam(); ++j) {
                        const Categoria& productoOriginal = listaProds.getValor(j);

                        Categoria* copiaProducto = new Categoria(productoOriginal);

                        // CAMBIO: Usamos el método de tu lista (ej. agregaFinal) en lugar de push_back.
                        copiasDeProductos.agregaFinal(copiaProducto);

                        arbolPorId.insertar(copiaProducto, comparadorPorId);
                        arbolPorNombre.insertar(copiaProducto, comparadorPorNombre);
                        arbolPorPrecio.insertar(copiaProducto, comparadorPorPrecio);
                    }
                }
            }
        }
        catch (const std::out_of_range&) {
            continue;
        }
    }
    arbolesDeBusquedaInicializados = true;
    cout << "\nArboles de busqueda han sido inicializados." << endl;
}

// Función para limpiar las copias de productos creadas dinámicamente.
void limpiarRecursosDeBusqueda() {
    // CAMBIO: Iteramos sobre la Lista en lugar del vector.
    for (int i = 0; i < copiasDeProductos.longitud(); i++) {
        // Usamos el método para obtener el elemento (ej. obtenerPos o getValor).
        // Nota: Asegúrate de que el método devuelva un Categoria*.
        Categoria* ptr = copiasDeProductos.obtenerPos(i);
        delete ptr;
    }
    // Opcional: Si tu lista tiene un método para limpiarse, llámalo aquí.
    // ej. copiasDeProductos.limpiar();
    copiasDeProductos.limpiar(); // Asegúrate de que este método exista en tu clase Lista.
}


// Función principal para la búsqueda de productos del administrador con navegación por flechas
void buscarProductoAdmin() {
    system("cls");

    inicializarArbolesDeBusqueda();

    int seleccion = 0;
    int maxSeleccion = 4;
    AccionTecla accion = NINGUNA;

    while (accion != SELECCIONAR && accion != CANCELAR) {
        system("cls");

        cout << "\n\n\t\t\t------ BUSCAR PRODUCTO EN CATALOGO ------" << endl;
        cout << "\n\t\t\tUse las flechas para navegar y Enter para seleccionar:\n" << endl;

        // Opción 1: Buscar por ID
        cout << "\t\t\t";
        if (seleccion == 0) {
            setColor(0, 14); // Fondo amarillo, texto negro para opción seleccionada
            cout << "> 1. Buscar por ID <";
            setColor(15, 0); // Volver a colores normales
        }
        else {
            cout << "  1. Buscar por ID";
        }
        cout << endl;

        // Opción 2: Buscar por Nombre
        cout << "\t\t\t";
        if (seleccion == 1) {
            setColor(0, 14);
            cout << "> 2. Buscar por Nombre <";
            setColor(15, 0);
        }
        else {
            cout << "  2. Buscar por Nombre";
        }
        cout << endl;

        // Opción 3: Buscar por Precio
        cout << "\t\t\t";
        if (seleccion == 2) {
            setColor(0, 14);
            cout << "> 3. Buscar por Precio <";
            setColor(15, 0);
        }
        else {
            cout << "  3. Buscar por Precio";
        }
        cout << endl;

        // Opción 4: Volver al menú anterior
        cout << "\t\t\t";
        if (seleccion == 3) {
            setColor(0, 14);
            cout << "> 0. Volver al menu anterior <";
            setColor(15, 0);
        }
        else {
            cout << "  0. Volver al menu anterior";
        }
        cout << endl;

        cout << "\n\t\t\tESC para cancelar" << endl;

        accion = navegarConFlechas(seleccion, maxSeleccion);
    }

    if (accion == CANCELAR) {
        return;
    }

    // Procesar la selección
    NodoArbol<Categoria*>* resultado = nullptr;
    Categoria claveBusqueda;

    switch (seleccion) {
    case 0: { // Buscar por ID
        system("cls");
        cout << "\n\t\t\t------ BUSCAR POR ID ------" << endl;
        cout << "\n\t\t\tIngrese el ID del producto a buscar: ";
        string id;
        cin >> id;
        claveBusqueda.setID(id);
        resultado = arbolPorId.buscar(&claveBusqueda, comparadorPorId);
        break;
    }
    case 1: { // Buscar por Nombre
        system("cls");
        cout << "\n\t\t\t------ BUSCAR POR NOMBRE ------" << endl;
        cout << "\n\t\t\tIngrese el Nombre del producto a buscar: ";
        string nombre;
        cin.ignore();
        getline(cin, nombre);
        claveBusqueda.setNombre(nombre);
        resultado = arbolPorNombre.buscar(&claveBusqueda, comparadorPorNombre);
        break;
    }
    case 2: { // Buscar por Precio
        system("cls");
        cout << "\n\t\t\t------ BUSCAR POR PRECIO ------" << endl;
        cout << "\n\t\t\tIngrese el Precio a buscar: ";
        double precio;
        cin >> precio;
        claveBusqueda.setPrecioUnitario(precio);
        resultado = arbolPorPrecio.buscar(&claveBusqueda, comparadorPorPrecio);
        break;
    }
    case 3: // Volver al menú anterior
        return;
    }

    // Mostrar resultado
    system("cls");

    if (resultado != nullptr) {
        cout << "\n\t\t\t--- Producto Encontrado ---" << endl;
        resultado->dato->mostrarResumen();
        cout << "\n\t\t\tNota: Para editar o eliminar, use la funcion correspondiente con el ID del producto." << endl;
    }
    else {
        cout << "\n\t\t\tProducto no encontrado." << endl;
    }

    cout << "\n\t\t\tPresione cualquier tecla para continuar...";
    system("pause>0");
}
//FUNCION PARA REVISAR LA VENTAS DEL DÍA
void revisarVentasDelDia() {
    system("cls");
    cout << "\n\n\t\t\t------ REPORTE DE VENTAS DEL DIA ------" << endl;

    // --- 1. OBTENER LA FECHA DE HOY ---
    // Replicamos la lógica de tu clase Boleta para obtener la fecha en el formato correcto "d/m/aaaa"
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);
    string fechaHoy = to_string(timeinfo.tm_mday) + "/" +
        to_string(timeinfo.tm_mon + 1) + "/" +
        to_string(timeinfo.tm_year + 1900);

    cout << "\n\t\tFecha del reporte: " << fechaHoy << endl;
    cout << "\t\t-------------------------------------------" << endl;

    // --- 2. RECORRER LAS BOLETAS Y CALCULAR EL TOTAL ---
    double totalVentasDia = 0.0;
    int cantidadVentasDia = 0;

    // Suponemos que tu clase Lista tiene los métodos longitud() y obtenerPos()
    if (listaBoletas.esVacia()) {
        cout << "\n\t\tNo hay ventas registradas en el sistema." << endl;
    }
    else {
        // Primero, mostramos las boletas que coinciden con la fecha de hoy
        cout << "\n\t\tBoletas generadas hoy:" << endl;
        cout << left << setw(15) << "\t\tN. Boleta" << setw(30) << "Cliente" << setw(15) << "Total (S/.)" << endl;
        cout << "\t\t------------------------------------------------------------" << endl;

        for (int i = 0; i < listaBoletas.longitud(); i++) {
            Boleta* boletaActual = listaBoletas.obtenerPos(i);

            // Usamos el nuevo método getFecha() que acabamos de añadir
            if (boletaActual != nullptr && boletaActual->getFecha() == fechaHoy) {
                double totalBoleta = boletaActual->getTotal();
                cout << left << setw(15) << "\t\t" + to_string(boletaActual->getNumeroBoleta())
                    << setw(30) << boletaActual->getCliente()
                    << fixed << setprecision(2) << setw(15) << totalBoleta
                    << endl;

                totalVentasDia += totalBoleta;
                cantidadVentasDia++;
            }
        }

        if (cantidadVentasDia == 0) {
            cout << "\n\t\tNo se encontraron ventas para la fecha de hoy." << endl;
        }
    }

    // --- 3. MOSTRAR EL RESULTADO FINAL ---
    cout << "\n\t\t-------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "\n\t\t>> TOTAL DE VENTAS DEL DIA: S/. " << totalVentasDia << endl;
    cout << "\t\t>> Cantidad de transacciones: " << cantidadVentasDia << endl;

    cout << "\n\n";
    system("pause>0");
}

//funcion de procesar pedidos con el uso de COLAS
void procesarPedidos() {
    int opcion;
    do {
        system("cls");
        cout << "\n\n\t\t\t------ GESTION DE PEDIDOS PENDIENTES ------" << endl;

        if (colaDePedidos.esVacia()) {
            cout << "\n\t\t>> No hay pedidos pendientes en la cola." << endl;
            opcion = 0;
            system("pause>0");
        }
        else {
            // MOSTRAR TODOS LOS PEDIDOS PENDIENTES
            cout << "\n\t\tTotal de pedidos en cola: " << colaDePedidos.size() << endl;
            colaDePedidos.mostrarTodos();

            // MOSTRAR EL PRÓXIMO A PROCESAR
            Boleta* proximoPedido = colaDePedidos.frente();
            cout << "\n\t\t>>> PRÓXIMO PEDIDO A PROCESAR <<<" << endl;
            cout << "\t\t---------------------------------" << endl;
            cout << "\t\tBoleta Nro: " << proximoPedido->getNumeroBoleta() << endl;
            cout << "\t\tCliente: " << proximoPedido->getCliente() << endl;
            cout << fixed << setprecision(2);
            cout << "\t\tTotal: S/. " << proximoPedido->getTotal() << endl;
            cout << "\t\t---------------------------------" << endl;

            cout << "\n\t\t1. Procesar y Despachar Pedido (Desencolar)";
            cout << "\n\t\t2. Ver detalles del próximo pedido";
            cout << "\n\t\t0. Volver al Menu Principal";
            cout << "\n\n\t\tSeleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1: {
                Boleta* pedidoProcesado = colaDePedidos.desencolar();
                cout << "\n\t\t>> Pedido Nro. " << pedidoProcesado->getNumeroBoleta()
                    << " procesado y eliminado de la cola." << endl;
                cout << "\t\t>> Pedidos restantes en cola: " << colaDePedidos.size() << endl;
                system("pause>0");
                break;
            }
            case 2: {
                cout << "\n\t\t=== DETALLES DEL PEDIDO ===" << endl;
                proximoPedido->mostrarBoleta();
                system("pause>0");
                break;
            }
            case 0:
                break;
            default:
                cout << "\n\t\t>> Opción inválida." << endl;
                system("pause>0");
            }
        }
    } while (opcion != 0);
}

//funcion para gestionar las categorias
void gestionarCategoriasAdminCase0() {
	SetBackgroundColor(Black);
	system("cls");
	while (true) {
		// Variables para la navegación del menú
		int seleccion = 0;
		int maxSeleccion = 6; // 6 opciones, de 0 a 5
		AccionTecla accion = NINGUNA;

		// Obtener ancho de la consola para centrado
		int ancho = GetConsoleWidth();

		// Encabezado centrado
		SetForegroundColor(Green);
		string titulo = "====== GESTION DE PRODUCTOS ======";
		int posX = (ancho - titulo.length()) / 2;
		SetCursorPosition(posX, 2);
		cout << titulo << endl;
		SetForegroundColor(BrightWhite);

		// Ciclo de navegación del menú
		while (true) {
			// Reiniciar acción
			accion = NINGUNA;

			// Limpiar área de menú
			for (int i = 5; i < 20; i++) {
				SetCursorPosition(0, i);
				cout << string(ancho, ' ');
			}

			// Mostrar opciones de menú centradas
			SetForegroundColor(BrightWhite);

			string opciones[] = {
				"Agregar Nuevo Producto",
				"Modificar Producto",
				"Eliminar Producto",
				"Buscar Producto",
				"Listar Todos los Productos",
				"Volver al Menu Anterior"
			};

			// Calcular la posición más ancha para centrado uniforme
			int maxLength = 0;
			for (int i = 0; i < 6; i++) {
				if (opciones[i].length() > maxLength) {
					maxLength = opciones[i].length();
				}
			}

			// Añadir espacio para los caracteres de selección
			maxLength += 6; // Para "> - " y " <"

			for (int i = 0; i < 6; i++) {
				int posY = 6 + (i * 3);
				posX = (ancho - maxLength) / 2;

				SetCursorPosition(posX, posY);
				if (seleccion == i) {
					setColor(0, 15); // Fondo blanco, texto negro
					cout << "> - " << opciones[i] << " <";
					setColor(15, 0); // Volver a colores normales
				}
				else {
					cout << "  - " << opciones[i] << "  ";
				}
			}

			// Esperar por la entrada del usuario
			accion = navegarConFlechas(seleccion, maxSeleccion);

			// Si el usuario selecciona una opción
			if (accion == SELECCIONAR) {
				break;
			}
		}

		// Procesar la selección
		switch (seleccion) {
		case 0: // Agregar Nuevo Producto
			agregarProductoInteractivo();
			system("cls");
			break;
		case 1: // Modificar Producto
			editarProductoPorID();
			system("cls");
			break;
		case 2: // Eliminar Producto
			eliminarProductoPorID();
			system("cls");
			break;
		case 3: // Buscar Producto
			buscarProductoAdmin();
			system("cls");
			break;
		case 4: // Listar Todos los Productos
			gestionarCategorias();
			system("cls");
			break;
		case 5: // Volver al menú anterior
			SetCursorPosition((ancho - 30) / 2, 24);
			cout << "VOLVIENDO AL MENU ANTERIOR...";
			Sleep(500);
			return;
		}
	}
}

//funcion para ver un reporte de los productos mas vendidos
void verProductosMasVendidos() {
    system("cls");
    cout << "\n\n\t\t\t------ PRODUCTOS MÁS VENDIDOS ------" << endl;
    // Aquí deberías implementar la lógica para calcular los productos más vendidos.
    // Por ejemplo, podrías usar un mapa o un arreglo para contar las ventas de cada producto.
    // Simulación de productos más vendidos (esto debería ser dinámico en una implementación real)
    cout << "\n\t\tProducto A - 150 unidades vendidas" << endl;
    cout << "\t\tProducto B - 120 unidades vendidas" << endl;
    cout << "\t\tProducto C - 100 unidades vendidas" << endl;
    cout << "\n\n";
    system("pause>0");
}
//funcion para solo ver las boletas del día
void verBoletasDelDia() {
    system("cls");
    cout << "\n\n\t\t\t------ BOLETAS DEL DIA ------" << endl;
    // --- 1. OBTENER LA FECHA DE HOY ---
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);
    string fechaHoy = to_string(timeinfo.tm_mday) + "/" +
        to_string(timeinfo.tm_mon + 1) + "/" +
        to_string(timeinfo.tm_year + 1900);
    cout << "\n\t\tFecha del reporte: " << fechaHoy << endl;
    cout << "\t\t-------------------------------------------" << endl;
    // --- 2. RECORRER LAS BOLETAS Y MOSTRAR LAS QUE COINCIDEN CON LA FECHA ---
    if (listaBoletas.esVacia()) {
        cout << "\n\t\tNo hay boletas registradas en el sistema." << endl;
    }
    else {
        cout << "\n\t\tBoletas generadas hoy:" << endl;
        cout << left << setw(15) << "\t\tN. Boleta" << setw(30) << "Cliente" << setw(15) << "Total (S/.)" << endl;
        cout << "\t\t------------------------------------------------------------" << endl;
        for (int i = 0; i < listaBoletas.longitud(); i++) {
            Boleta* boletaActual = listaBoletas.obtenerPos(i);
            if (boletaActual != nullptr && boletaActual->getFecha() == fechaHoy) {
                double totalBoleta = boletaActual->getTotal();
                cout << left << setw(15) << "\t\t" + to_string(boletaActual->getNumeroBoleta())
                    << setw(30) << boletaActual->getCliente()
                    << fixed << setprecision(2) << setw(15) << totalBoleta
                    << endl;
            }
        }
    }
    cout << "\n\n";
    system("pause>0");
}



// NUEVO PARA GENERAR REPORTE DE VENTAS
void GenerarReporteDeVentasRegistro() {
    //primero limpio
    system("cls");
    //hago un menu de reportes del dia con opciones de revisar ventas del día
    cout << "\n\n\t\t\t------ REPORTE DE VENTAS DEL DIA ------" << endl;
    cout << "\n\t\t\t1. Ver ventas del día\n";
    cout << "\n\t\t\t2. ver reporte de Productos Más Vendidos\n";
    cout << "\n\t\t\t0. Regresar al menu principal\n";
    cout << "\n\t\t\tSeleccione una opcion: ";

    int opcion;
    cin >> opcion;
    switch (opcion) {
    case 1:
        revisarVentasDelDia();
        break;
    case 2:
        verProductosMasVendidos(); // Llamamos a la función para ver productos más vendidos
        break;
    case 0:
        return; // Regresar al menú principal
    default:
        cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
        system("pause>0");
        system("cls");
    }
}

//funcion para busqueda de boletas con menu
void BusquedaBoletas() {
    system("cls");
    cout << "\n\t\t\t------ BUSQUEDA DE BOLETAS ------" << endl;
    cout << "\n\t\t\t1. Buscar por numero de boleta\n";
    cout << "\n\t\t\t2. Buscar por rango de precio\n";
    cout << "\n\t\t\t3. Volver al menu anterior\n";
    cout << "\n\t\t\tSeleccione una opcion: ";
    int opcion;
    cin >> opcion;
    switch (opcion) {
    case 1: {
        int numeroBoleta;
        cout << "\nIngrese el numero de boleta a buscar: ";
        cin >> numeroBoleta;
        Boleta::buscarPorNumero(listaBoletas, numeroBoleta);
        break;
    }
    case 2: {
        double min, max;
        cout << "\nIngrese el precio minimo: ";
        cin >> min;
        cout << "Ingrese el precio maximo: ";
        cin >> max;
        Boleta::buscarPorRangoPrecio(listaBoletas, min, max);
        break;
    }
    case 3:
        return; // Volver al menú anterior
    default:
        cout << "\nOpcion invalida." << endl;
        break;
    }
    system("pause>0");
}


//NUEVO METODO
void ManejoUsuariosDeAdmin() {
    // Creamos el objeto principal de nuestro sistema.
    SistemaUsuarios sistema;

    char opcion;
    bool continuar = true;

    // Creamos un bucle para el menú de opciones.
    while (continuar) {
        system("cls");
        std::cout << "===== MENU PRINCIPAL DE PRUEBA =====" << std::endl;
        std::cout << "1. Listar todos los usuarios (ordenados)" << std::endl;
        std::cout << "2. Buscar usuarios por nombre" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << "\nSeleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case '1':
            // Llama a la función para mostrar la lista ordenada.
            sistema.mostrarUsuariosOrdenados();
            break;
        case '2':
            // Llama a la función para buscar por nombre.
            sistema.buscarUsuariosPorNombre();
            break;
        case '3':
            continuar = false;
            std::cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
            system("pause>0");
            break;
        }
    }
}
void inicializarOfertasDeProductos() {
    if (ofertasPosibles.empty()) return;

    for (auto& parPrincipal : catalogo.getProductos()) {
        for (auto& parSecundaria : parPrincipal.second) {
            for (auto& parTerciaria : parSecundaria.second) {
                Lista<Categoria>& listaProds = parTerciaria.second;
                for (int i = 0; i < listaProds.getTam(); ++i) {
                    // Reinicia la oferta antes de asignar una nueva
                    Categoria& prod = listaProds.getValor(i);
                    prod.setOferta("");
                    prod.setPrecioDescuento(0.0);

                    // Ahora asigna una nueva aleatoria
                    asignarOfertaAleatoria(prod);
                }
            }
        }
    }
}
//NUEVOOOOOOOOOOOOOO
void verPromocionesVigentes() {
    system("cls");

    inicializarOfertasDeProductos(); // Aplica ofertas aleatorias al entrar

    // Reunimos todos los productos que tienen oferta
    Lista<Categoria> productosConOferta;
    for (int i = 1; i <= numCategoriasPrincipales; ++i) {
        try {
            const auto& subMapa = catalogo.getPorIdPrincipal(i);
            for (const auto& parSub : subMapa) {
                for (const auto& parTer : parSub.second) {
                    const Lista<Categoria>& listaProds = parTer.second;
                    for (int j = 0; j < listaProds.getTam(); ++j) {
                        Categoria prod = listaProds.getValor(j);
                        if (!prod.getOferta().empty()) {
                            productosConOferta.agregaFinal(prod);
                        }
                    }
                }
            }
        }
        catch (const out_of_range&) { continue; }
    }

    if (productosConOferta.esVacia()) {
        cout << "\n\n\t\tNo hay promociones vigentes en este momento." << endl;
        system("pause>0");
        return;
    }

    // Mostrar directamente la tabla con productos con oferta
    int idxProducto = seleccionarProductoEnTabla(productosConOferta);

    if (idxProducto != -1) {
        Categoria& productoOriginal = productosConOferta.getValor(idxProducto);
        int cantidad;
        cout << "\nIngrese la cantidad a comprar: ";
        cin >> cantidad;
        if (cantidad > 0 && cantidad <= productoOriginal.getStock()) {
            Categoria* copiaParaCarrito = new Categoria(productoOriginal);
            copiaParaCarrito->setCantidad(cantidad);
            productosSeleccionados->agregaFinal(copiaParaCarrito);
            cout << "\n>> " << cantidad << "x " << copiaParaCarrito->getNombre() << " agregado al carrito!" << endl;
        }
        else {
            cout << "\nCantidad no válida o sin stock suficiente." << endl;
        }
        system("pause>0");
    }
}
//aca va para arbror el tx es nuvo esta webada


// Lee el archivo promociones.txt y carga los datos en la lista 'ofertasPosibles'
void cargarPromociones() {
    ifstream archivo("promociones.txt");
    if (!archivo.is_open()) {
        cout << "ADVERTENCIA: No se encontró promociones.txt. No se cargarán ofertas." << endl;
        return;
    }

    string linea;
    ofertasPosibles.clear(); // Limpiamos la lista por si acaso
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            ofertasPosibles.push_back(linea);
        }
    }
    archivo.close();
}

// Sobrescribe el archivo promociones.txt con la lista actual de 'ofertasPosibles'
void guardarPromociones() {
    ofstream archivo("promociones.txt");
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir promociones.txt para guardar." << endl;
        return;
    }

    for (const string& promo : ofertasPosibles) {
        archivo << promo << endl;
    }
    archivo.close();
}
void gestionarPromociones() {
    string opciones[] = { "Ver Promociones Actuales", "Crear Nueva Promocion", "Eliminar Promocion", "Volver" };
    int nOpciones = 4;
    int seleccion = 0;

    while (true) {
        system("cls");
        cout << "\n\t\t\t------ GESTION DE PROMOCIONES ------\n" << endl;
        for (int i = 0; i < nOpciones; ++i) {
            if (i == seleccion) setColor(0, 15); else setColor(15, 0);
            cout << "\t\t\t" << (i + 1) << ". " << opciones[i] << endl;
        }
        setColor(15, 0);

        int key = _getch();
        if (key == 27) break;
        if (key == 13) {
            switch (seleccion) {
            case 0: { // Ver Promociones
                system("cls");
                cout << "\n\t\t--- LISTA DE PROMOCIONES ACTIVAS ---\n" << endl;
                for (size_t i = 0; i < ofertasPosibles.size(); ++i) {
                    cout << "\t\t" << (i + 1) << ". " << ofertasPosibles[i] << endl;
                }
                cout << endl;
                system("pause>0");
                break;
            }
            case 1: { // Crear
                system("cls");
                string nuevaPromo;
                cout << "\n\t\t--- CREAR NUEVA PROMOCION ---\n" << endl;

                cout << "\t\tIngrese el nombre de la nueva promocion:\n";
                cout << "\t\tFormato válido:\n";
                cout << "\t\t - S/ 9.90   (descuento fijo de 9.90 soles)\n";
                cout << "\t\t - 15% Dcto. (descuento porcentual del 15%)\n";
                cout << "\t\t - 2x1       (descuento del 50% simulado)\n";
                cout << "\t\t-------------------------------------------\n";
                cout << "\t\t>> ";

                cin.ignore(); // limpiar el salto de línea pendiente
                getline(cin, nuevaPromo);

                if (!nuevaPromo.empty()) {
                    // Verificamos si es solo un número → lo convertimos a formato "S/ x.xx"
                    bool esNumero = all_of(nuevaPromo.begin(), nuevaPromo.end(), [](char c) {
                        return isdigit(c) || c == '.'; // permite decimales
                        });

                    if (esNumero) {
                        nuevaPromo = "S/ " + nuevaPromo;
                    }

                    ofertasPosibles.push_back(nuevaPromo);
                    guardarPromociones();
                    cout << "\n\t\t>> EXITO: Promocion '" << nuevaPromo << "' creada y guardada." << endl;
                }
                else {
                    cout << "\n\t\tERROR: El nombre no puede estar vacio." << endl;
                }
                system("pause>0");
                break;
            }
            case 2: { // Eliminar
                system("cls");
                cout << "\n\t\t--- ELIMINAR PROMOCION ---\n" << endl;
                if (ofertasPosibles.empty()) {
                    cout << "\t\tNo hay promociones para eliminar." << endl;
                    system("pause>0");
                    break;
                }
                for (size_t i = 0; i < ofertasPosibles.size(); ++i) {
                    cout << "\t\t" << (i + 1) << ". " << ofertasPosibles[i] << endl;
                }

                // Declaramos la variable 'numeroAEliminar' aquí
                int numeroAEliminar;
                cout << "\n\t\tIngrese el numero de la promocion a eliminar: ";
                cin >> numeroAEliminar;

                if (!cin.fail() && numeroAEliminar > 0 && numeroAEliminar <= ofertasPosibles.size()) {
                    string promoEliminada = ofertasPosibles[numeroAEliminar - 1];
                    ofertasPosibles.erase(ofertasPosibles.begin() + (numeroAEliminar - 1));
                    guardarPromociones(); // Guardamos los cambios en el archivo
                    cout << "\n\t\t>> EXITO: Promocion '" << promoEliminada << "' eliminada y guardada." << endl;
                }
                else {
                    cout << "\n\t\tERROR: Numero no valido." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                system("pause>0");
                break;
            }
            case 3: { // Volver
                return;
            }
            }
        }
        if (key == 224) {
            key = _getch();
            if (key == 72 && seleccion > 0) seleccion--;
            if (key == 80 && seleccion < nOpciones - 1) seleccion++;
        }
    }
}


void generarReporteMasVendidos() {
    system("cls");
    cout << "\n\t\t\t------ REPORTE DE PRODUCTOS MAS VENDIDOS ------\n" << endl;

    if (listaBoletas.esVacia()) {
        cout << "\t\tNo hay ventas registradas para generar un reporte." << endl;
        system("pause>0");
        return;
    }

    // --- Paso 1: Contar las ventas de cada producto usando un mapa ---
    map<string, int> ventasPorProducto;
    for (int i = 0; i < listaBoletas.longitud(); ++i) {
        Boleta* boleta = listaBoletas.getValor(i);
        // Asumiendo que Boleta tiene un getter para su lista de productos
        for (int j = 0; j < boleta->getProductos().longitud(); ++j) {
            Categoria* productoVendido = boleta->getProductos().getValor(j);
            ventasPorProducto[productoVendido->getNombre()] += productoVendido->getCantidad();
        }
    }

    // --- Paso 2: Copiar el mapa a un arreglo dinámico para poder ordenarlo ---
    int numProductosUnicos = ventasPorProducto.size();
    // Creamos un arreglo dinámico en lugar de un vector
    pair<string, int>* sortedVentas = new pair<string, int>[numProductosUnicos];

    int index = 0;
    for (const auto& par : ventasPorProducto) {
        sortedVentas[index] = par;
        index++;
    }

    // --- Paso 3: Ordenar el arreglo dinámico ---
    // Usamos el algoritmo de ordenamiento sort, que también funciona con arreglos dinámicos.
    sort(sortedVentas, sortedVentas + numProductosUnicos, [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second; // Ordena de mayor a menor cantidad
        });

    // --- Paso 4: Mostrar el reporte Top N ---
    int topN;
    cout << "\t\tIngrese la cantidad de los prodcutos mas vendidos que desea ver: ";
    cin >> topN;

    if (cin.fail() || topN <= 0) {
        cout << "\n\t\tNúmero no válido." << endl;
    }
    else {
        system("cls");
        cout << "\n\t\t\t------ TOP " << topN << " PRODUCTOS MAS VENDIDOS ------\n" << endl;
        cout << "\t\t" << left << setw(5) << "RANK" << setw(50) << "PRODUCTO" << "CANT. VENDIDA" << endl;
        cout << "\t\t" << string(70, '-') << endl;

        for (int i = 0; i < topN && i < numProductosUnicos; ++i) {
            cout << "\t\t" << left << setw(5) << (i + 1)
                << setw(50) << sortedVentas[i].first
                << sortedVentas[i].second << endl;
        }
    }

    // --- Paso 5: Opción para rellenar el stock (sin cambios) ---
    char opcion;
    cout << "\n\n\t\tDesea rellenar el stock de todos los productos a 100 unidades? (S/N): ";
    cin >> opcion;
    if (tolower(opcion) == 's') {
        cout << "\n\t\tRellenando stock..." << endl;
        for (auto& parPrincipal : catalogo.getProductos()) {
            for (auto& parSecundaria : parPrincipal.second) {
                for (auto& parTerciaria : parSecundaria.second) {
                    Lista<Categoria>& listaProds = parTerciaria.second;
                    for (int i = 0; i < listaProds.getTam(); ++i) {
                        listaProds.getValor(i).setStock(100);
                    }
                }
            }
        }
        cout << "\t\t>> EXITO: Stock de todos los productos rellenado." << endl;
    }

    // --- Paso 6: Liberar la memoria del arreglo dinámico ---
    // ¡Muy importante para evitar fugas de memoria!
    delete[] sortedVentas;

    system("pause>0");
}

//CAMBIOS EL 06/07/2025 7:00 AM
void generarReporteInventario() {
    system("cls");
    cout << "\n\t\t\t------ REPORTE RESUMIDO DE INVENTARIO ------\n" << endl;

    // Variables para guardar las estadísticas
    int totalProductos = 0;
    double valorTotalInventario = 0.0;

    // ==========================================================
    //  CAMBIO PRINCIPAL: Usamos tu clase Lista en lugar de std::vector
    // ==========================================================
    Lista<Categoria> productosBajoStock;

    // Usamos el recorrido in-orden del árbol para procesar cada producto
    catalogo.getArbolProductos()->inOrden([&](Categoria prod) {
        totalProductos++;
        valorTotalInventario += prod.getPrecioUnitario() * prod.getStock();

        // Consideramos "bajo stock" si hay 20 o menos unidades
        if (prod.getStock() <= 20) {
            // Usamos tu método 'agregaFinal'
            productosBajoStock.agregaFinal(prod);
        }
        });

    // --- Mostramos las Estadísticas Generales ---
    cout << "\t\t=============================================" << endl;
    cout << "\t\t Estadisticas Generales del Inventario" << endl;
    cout << "\t\t=============================================" << endl;
    cout << "\t\t - Total de productos unicos: " << totalProductos << endl;
    cout << "\t\t - Valor total del inventario: S/. " << fixed << setprecision(2) << valorTotalInventario << endl;
    cout << "\n\n";

    // --- Mostramos los Productos con Bajo Stock ---
    cout << "\t\t=============================================" << endl;
    cout << "\t\t Alerta de Productos con Bajo Stock (<= 20 u.)" << endl;
    cout << "\t\t=============================================" << endl;

    // Usamos tu método 'esVacia()'
    if (productosBajoStock.esVacia()) {
        cout << "\t\t>> Felicitaciones! No hay productos con bajo stock." << endl;
    }
    else {
        cout << "\t\t" << left << setw(45) << "PRODUCTO" << "STOCK ACTUAL" << endl;
        cout << "\t\t" << string(60, '-') << endl;

        // Recorremos tu 'Lista' con un bucle for tradicional
        for (int i = 0; i < productosBajoStock.getTam(); ++i) {
            Categoria prod = productosBajoStock.getValor(i);
            cout << "\t\t" << left << setw(45) << prod.getNombre().substr(0, 44)
                << prod.getStock() << endl;
        }
    }

    cout << endl;
    system("pause>0");
}