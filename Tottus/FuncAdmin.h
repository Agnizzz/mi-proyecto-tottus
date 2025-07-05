#pragma once
#include <iostream>
#include <conio.h>
#include <chrono> 
#include <functional>
#include "GestionCategorias.h"
#include "ArbolBB.h"

//SE HIZO CAMBIOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOS

using namespace std;



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
    system("cls");
    cout << "\n\n\t\t\t------ GESTION CATEGORIAS ------" << endl;
    int opcion;
    cout << "\n\t\t\t1. Ver productos\n";
    cout << "\n\t\t\t2. Agregar producto\n";
    cout << "\n\t\t\t3. Editar producto\n";
    cout << "\n\t\t\t4. Eliminar producto\n";
    cout << "\n\t\t\t5. Buscar Producto\n"; // <-- NUEVA OPCIÓN
    //cout << "\n\t\t\t6. Revisar Ventas del Dia (Nuevo)\n"; //Nuevo
    //cout << "\n\t\t\t7. Procesar Pedidos Pendientes (Nuevo)\n"; // <-- NUEVA OPCIÓN
    cout << "\n\t\t\t0. Regresar al menu principal\n";
    cout << "\n\t\t\tSeleccione una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
        gestionarCategorias();
        break;
    case 2:
        agregarProductoInteractivo(); // <-- MODIFICADO PARA AGREGAR PRODUCTO
        break;
    case 3:
        // Lógica para editar categoría
        editarProductoPorID(); // <-- MODIFICADO PARA EDITAR PRODUCTO
        break;
    case 4:
        // Lógica para eliminar categoría
        eliminarProductoPorID(); // <-- MODIFICADO PARA ELIMINAR PRODUCTO
        break;
    case 5: // <-- NUEVO CASE
        buscarProductoAdmin();
        break;
    //case 6: // <-- NUEVO CASE
	//    revisarVentasDelDia(); // Nuevo este es para revisar las ventas del día
    //    break;
    //case 7: // <-- NUEVO CASE
	//    procesarPedidos(); // Nuevo este es para procesar pedidos pendientes
    //    break;
    case 0:
        system("cls");
		return; // Salir del menú de gestión de categorías
        break;
    default:
        cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
        system("pause>0");
        system("cls");
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

void menuRegistroAdmin() {
    int opcion;

    do {
        system("cls");
        cout << "\n\t===== ADMIN-BOLETAS =====\n";
        cout << "1. Buscar  boletas por DNI\n";
        cout << "2. Buscar boleta especifica\n";           // ⬅️ NUEVA OPCIÓN
        cout << "3. Mostrar todas las boletas\n";          // ⬅️ NUEVA OPCIÓN
        cout << "4. Eliminar boleta\n";                // ⬅️ NUEVA OPCIÓN
        cout << "5. Ordenar boletas\n"; // ⬅️ NUEVA OPCIÓN
        cout << "6. Salir\n";
        cout << "\n\t\t0. Cerrar Sesion" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 0: // Cerrar sesión
            sistemaUsuarios->cerrarSesion();
            cout << "\n\t\t\tCerrando sesion...\n";
            system("pause");
            productosSeleccionados->limpiar();  // Limpia el carrito del usuario anterior
            return; // Salir del menú de registro


        case 1: {
            system("cls");
            string dniBuscar = sistemaUsuarios->getUsuarioActual().DNI;
            cout << "\nBuscando boletas para DNI: " << dniBuscar << "\n";
            tablaBoletas.buscarPorDNI(dniBuscar);
            system("pause");
            break;
        }

        case 2:
            buscarBoletaEspecifica();
            break;

        case 3:
            system("cls");
            cout << "\n=== TODAS LAS BOLETAS ===" << endl;
            tablaBoletas.mostrarTodas();
            system("pause");
            break;

        case 4:
            eliminarBoleta();
            break;
        case 5:
            ordenarBoletasAvanzado();
            break;

        case 6:
            cout << "Saliendo del menu...\n";
            break;

        default:
            cout << "Opcion no valida.\n";
            system("pause");
        }

    } while (opcion != 6);  // ⬅️ CAMBIÉ A 6 porque ahora hay más opciones
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
