#pragma once
#include <iostream>
#include <conio.h>
#include <algorithm> 
#include <cmath>     
#include <cctype> 
#include "MetOrg.h"
#include"Usuario.h"

//SE HIZO CAMBIOSSSSSS

using namespace std;
//variables globales

Lista<Categoria> listaProductos;
HashTable<Boleta> tablaBoletas;  // Ahora usa template con Boleta, no Boleta*

Lista<Boleta*> listaBoletas;


User usuarioActual;
//para ignorar mayusuclas
string toLowerCase(const string& str) {
	string result = str;
	for (char& c : result)
		c = tolower(c);
	return result;
}

void comprar() {
	gestionarCategorias(true);
}
void verCarrito() {
	system("cls");
	system("cls");

	// Encabezado visual
	setColor(15, 4);
	cout << "                              SUPERMERCADO VIRTUAL                                         \n";
	setColor(0, 14);
	cout << "                                CARRITO DE COMPRAS                                         \n";
	setColor(0, 7);
	cout << left
		<< setw(5) << "ID"
		<< setw(45) << "Producto"
		<< setw(12) << "Cantidad"
		<< setw(12) << "Precio (S/.)" << endl;
	setColor(15, 0);

	if (productosSeleccionados->esVacia()) {
		cout << "\n\t\t\tNo hay productos en el carrito." << endl;
	}
	else {
		for (int i = 0; i < productosSeleccionados->longitud(); i++) {
			Categoria* producto = productosSeleccionados->getValor(i);
			float precioTotal = producto->getPrecioUnitario() * producto->getCantidad();

			cout << left
				<< setw(5) << (i + 1)
				<< setw(45) << producto->getNombre()
				<< setw(12) << producto->getCantidad()
				<< fixed << setprecision(2)
				<< "S/. " << precioTotal << endl;
		}
	}

	cout << endl;
	system("pause>0");
}
//funcion de modificar cantidad de un producto seleccionado en mi carrito
void modificarCantidad() {
	system("cls");
	cout << "\n\t\t\t-- Modificar Cantidad --" << endl;
	if (productosSeleccionados->esVacia()) {
		cout << "\n\t\t\tNo hay productos en el carrito." << endl;
	}
	else {
		cout << "\n\t\t\tProductos en el carrito:" << endl;
		for (int i = 0; i < productosSeleccionados->longitud(); i++) {
			Categoria* producto = productosSeleccionados->getValor(i);
			cout << "\t\t\t" << (i + 1) << ". " << producto->getNombre() << " - Cantidad: " << producto->getCantidad() << endl;
		}
		int opcion;
		cout << "\n\t\t\tSeleccione el producto a modificar (0 para cancelar): ";
		cin >> opcion;
		if (opcion > 0 && opcion <= productosSeleccionados->longitud()) {
			int nuevaCantidad;
			cout << "\n\t\t\tIngrese la nueva cantidad: ";
			cin >> nuevaCantidad;
			if (nuevaCantidad > 0) {
				productosSeleccionados->getValor(opcion - 1)->setCantidad(nuevaCantidad);
				cout << "\n\t\t\tCantidad modificada correctamente." << endl;
			}
			else {
				cout << "\n\t\t\tLa cantidad debe ser mayor a cero." << endl;
			}
		}
		else if (opcion == 0) {
			cout << "\n\t\t\tOperación cancelada." << endl;
		}
		else {
			cout << "\n\t\t\tOpción invalida." << endl;
		}
	}
	system("pause>0");
}

void eliminarProducto() {
	system("cls");
	cout << "\n\t\t\t-- Eliminar Producto --" << endl;
	if (productosSeleccionados->esVacia()) {
		cout << "\n\t\t\tNo hay productos en el carrito." << endl;
	}
	else {
		cout << "\n\t\t\tProductos en el carrito:" << endl;
		for (int i = 0; i < productosSeleccionados->longitud(); i++) {
			Categoria* producto = productosSeleccionados->getValor(i);
			cout << "\t\t\t" << (i + 1) << ". " << producto->getNombre() << " - Cantidad: " << producto->getCantidad() << endl;
		}
		int opcion;
		cout << "\n\t\t\tSeleccione el producto a eliminar (0 para cancelar): ";
		cin >> opcion;
		if (opcion > 0 && opcion <= productosSeleccionados->longitud()) {
			productosSeleccionados->eliminaPos(opcion - 1);
			cout << "\n\t\t\tProducto eliminado correctamente." << endl;
		}
		else if (opcion == 0) {
			cout << "\n\t\t\tOperación cancelada." << endl;
		}
		else {
			cout << "\n\t\t\tOpción invalida." << endl;
		}
	}
	system("pause>0");
}
void verOfertas() {
	system("cls");
	cout << "\n\t\t\t-- Ver Ofertas --" << endl;
	if (productosSeleccionados->esVacia()) {
		cout << "\n\t\t\tNo hay productos en el carrito." << endl;
	}
	else {
		cout << "\n\t\t\tOfertas disponibles:" << endl;
		for (int i = 0; i < productosSeleccionados->longitud(); i++) {
			Categoria* producto = productosSeleccionados->getValor(i);
			if (producto->getPrecioDescuento() > 0) {
				cout << "\t\t\t" << (i + 1) << ". " << producto->getNombre()
					<< " - Precio Original: S/." << producto->getPrecioUnitario()
					<< " - Precio con Descuento: S/." << producto->getPrecioDescuento()
					<< endl;
			}
		}
	}
	system("pause>0");
}


Categoria** convertirAArreglo(Lista<Categoria*>* lista, int& n) {
	n = lista->longitud();
	Categoria** arreglo = new Categoria * [n];
	for (int i = 0; i < n; ++i) {
		arreglo[i] = lista->getValor(i);  // ya es puntero
	}
	return arreglo;
}

//comparadores por nombre, precio y cantidad para el metodo binary search
bool compararPorNombre(const Categoria* a, const Categoria* b) { return toLowerCase(a->getNombre()) < toLowerCase(b->getNombre()); }
bool compararPorPrecio(const Categoria* a, const Categoria* b) { return a->getPrecioUnitario() < b->getPrecioUnitario(); }
bool compararPorCantidad(const Categoria* a, const Categoria* b) { return a->getCantidad() < b->getCantidad(); }
bool compararPorPrecioPtr(const Categoria* a, const Categoria* b) { return a->getPrecioUnitario() < b->getPrecioUnitario(); }
bool compararPorID(const Categoria* a, const Categoria* b) { return a->getID() < b->getID(); }
bool compararPorUnidadMedida(const Categoria* a, const Categoria* b) { return toLowerCase(a->getUnidadMedida()) < toLowerCase(b->getUnidadMedida()); }
bool compararPorPrecioFinal(const Categoria* a, const Categoria* b) { return a->getPrecioFinal() < b->getPrecioFinal(); }

// Funciones comparadoras para boletas
bool compararBoletasPorFecha(const Boleta* a, const Boleta* b) { return a->getFecha() < b->getFecha(); }
bool compararBoletasPorNumero(const Boleta* a, const Boleta* b) { return a->getNumeroBoleta() < b->getNumeroBoleta(); }
bool compararBoletasPorNombreCliente(const Boleta* a, const Boleta* b) { return a->getCliente() < b->getCliente(); }
bool compararBoletasPorDNI(const Boleta* a, const Boleta* b) { return a->getDNI() < b->getDNI(); }
bool compararBoletasPorTotal(const Boleta* a, const Boleta* b) { return a->getTotal() < b->getTotal(); }

//aca van los metodos binary search para buscar por nombre, precio y cantidad
int binarySearchPorNombre(Categoria** productos, int n, const string& nombreBuscado) {
	string buscadoLower = toLowerCase(nombreBuscado);
	int izquierda = 0, derecha = n - 1;

	while (izquierda <= derecha) {
		int medio = (izquierda + derecha) / 2;
		string actual = toLowerCase(productos[medio]->getNombre());

		if (actual == buscadoLower)
			return medio;
		else if (actual < buscadoLower)
			izquierda = medio + 1;
		else
			derecha = medio - 1;
	}
	return -1;
}

int binarySearchPorPrecio(Categoria** productos, int n, float precioBuscado) {
	int izquierda = 0, derecha = n - 1;

	while (izquierda <= derecha) {
		int medio = (izquierda + derecha) / 2;
		float actual = productos[medio]->getPrecioUnitario();

		if (fabs(actual - precioBuscado) < 0.01f)
			return medio;
		else if (actual < precioBuscado)
			izquierda = medio + 1;
		else
			derecha = medio - 1;
	}
	return -1;
}

int binarySearchPorCantidad(Categoria** productos, int n, int cantidadBuscada) {
	int izquierda = 0, derecha = n - 1;

	while (izquierda <= derecha) {
		int medio = (izquierda + derecha) / 2;
		int actual = productos[medio]->getCantidad();

		if (actual == cantidadBuscada)
			return medio;
		else if (actual < cantidadBuscada)
			izquierda = medio + 1;
		else
			derecha = medio - 1;
	}
	return -1;
}

//funcion para buscar en el que se incluira los 3 metodos binary search CREO QUE ESO NO LO USO
void buscarProducto() {
	system("cls");
	cout << "\n\t\t\t--- BUSCAR PRODUCTO ---\n";
	cout << "\t\t\t1. Por nombre\n";
	cout << "\t\t\t2. Por precio\n";
	cout << "\t\t\t3. Por cantidad\n";
	cout << "\t\t\t0. Volver\n";
	cout << "\n\t\t\tSeleccione una opcion: ";
	int opcion;
	cin >> opcion;

	if (opcion == 0) return;

	int n;
	Categoria** productos = convertirAArreglo(productosSeleccionados, n);
	if (opcion == 1) {
		sort(productos, productos + n, compararPorNombre);
		string nombre;
		cout << "\n\t\t\tIngrese el nombre a buscar: ";
		cin.ignore();
		getline(cin, nombre);
		int pos = binarySearchPorNombre(productos, n, nombre);
		if (pos != -1)
			cout << "\n\t\t\tProducto encontrado: " << productos[pos]->getNombre() << endl;
		else
			cout << "\n\t\t\tNo se encontró el producto.\n";
	}
	else if (opcion == 2) {
		sort(productos, productos + n, compararPorPrecio);
		float precio;
		cout << "\n\t\t\tIngrese el precio a buscar: ";
		cin >> precio;
		int pos = binarySearchPorPrecio(productos, n, precio);
		if (pos != -1)
			cout << "\n\t\t\tProducto encontrado: " << productos[pos]->getNombre()
			<< " - S/. " << productos[pos]->getPrecioUnitario() << endl;
		else
			cout << "\n\t\t\tNo se encontro ningun producto con ese precio.\n";
	}
	else if (opcion == 3) {
		sort(productos, productos + n, compararPorCantidad);
		int cantidad;
		cout << "\n\t\t\tIngrese la cantidad a buscar: ";
		cin >> cantidad;
		int pos = binarySearchPorCantidad(productos, n, cantidad);
		if (pos != -1)
			cout << "\n\t\t\tProducto encontrado: " << productos[pos]->getNombre()
			<< " - Cantidad: " << productos[pos]->getCantidad() << endl;
		else
			cout << "\n\t\t\tNo se encontro ningun producto con esa cantidad.\n";
	}
	else {
		cout << "\n\t\t\tOpcion invalida.\n";
	}

	delete[] productos;
	system("pause");
}

void merge(Categoria** arr, int left, int mid, int right, bool (*comparador)(const Categoria*, const Categoria*)) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	Categoria** L = new Categoria * [n1];
	Categoria** R = new Categoria * [n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (comparador(L[i], R[j])) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];

	delete[] L;
	delete[] R;
}

// mergeSort recursivo
void mergeSort(Categoria** arr, int left, int right, bool (*comparador)(const Categoria*, const Categoria*)) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid, comparador);
		mergeSort(arr, mid + 1, right, comparador);
		merge(arr, left, mid, right, comparador);
	}
}
// Función para ordenar productos (AVANZADO)
// QuickSort
int partition(Categoria** arr, int low, int high, bool (*comparador)(const Categoria*, const Categoria*)) {
	Categoria* pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (comparador(arr[j], pivot)) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(Categoria** arr, int low, int high, bool (*comparador)(const Categoria*, const Categoria*)) {
	if (low < high) {
		int pi = partition(arr, low, high, comparador);
		quickSort(arr, low, pi - 1, comparador);
		quickSort(arr, pi + 1, high, comparador);
	}
}
// HeapSort
void heapify(Categoria** arr, int n, int i, bool (*comparador)(const Categoria*, const Categoria*)) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && !comparador(arr[left], arr[largest]))
		largest = left;

	if (right < n && !comparador(arr[right], arr[largest]))
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest, comparador);
	}
}

void heapSort(Categoria** arr, int n, bool (*comparador)(const Categoria*, const Categoria*)) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, comparador);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, comparador);
	}
}
// Shell Sort
void shellSort(Categoria** arr, int n, bool (*comparador)(const Categoria*, const Categoria*)) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i += 1) {
			Categoria* temp = arr[i];
			int j;
			for (j = i; j >= gap && !comparador(arr[j - gap], temp); j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}
// 1. InsertionSort
void insertionSort(Boleta** arr, int n, bool (*comparador)(const Boleta*, const Boleta*)) {
	for (int i = 1; i < n; i++) {
		Boleta* key = arr[i];
		int j = i - 1;

		while (j >= 0 && !comparador(arr[j], key)) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// 2. BubbleSort
void bubbleSort(Boleta** arr, int n, bool (*comparador)(const Boleta*, const Boleta*)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (!comparador(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// 3. SelectionSort
void selectionSort(Boleta** arr, int n, bool (*comparador)(const Boleta*, const Boleta*)) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (comparador(arr[j], arr[min_idx])) {
				min_idx = j;
			}
		}
		swap(arr[min_idx], arr[i]);
	}
}

// Función auxiliar para RadixSort (declaración adelantada)
void countingSortByDigit(Boleta** arr, int n, int exp);

// RadixSort corregido
void radixSort(Boleta** arr, int n, bool (*comparador)(const Boleta*, const Boleta*)) {
	// Para RadixSort, necesitamos extraer valores numéricos
	// Implementación básica para números de boleta
	int max_val = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i]->getNumeroBoleta() > max_val) {
			max_val = arr[i]->getNumeroBoleta();
		}
	}

	// Hacer RadixSort solo por número de boleta
	for (int exp = 1; max_val / exp > 0; exp *= 10) {
		countingSortByDigit(arr, n, exp);
	}
}

// Función auxiliar para RadixSort
void countingSortByDigit(Boleta** arr, int n, int exp) {
	Boleta** output = new Boleta * [n];
	int count[10] = { 0 };

	// Contar ocurrencias de cada dígito
	for (int i = 0; i < n; i++) {
		count[(arr[i]->getNumeroBoleta() / exp) % 10]++;
	}

	// Cambiar count[i] para que contenga la posición actual de este dígito
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	// Construir el arreglo de salida
	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i]->getNumeroBoleta() / exp) % 10] - 1] = arr[i];
		count[(arr[i]->getNumeroBoleta() / exp) % 10]--;
	}

	// Copiar el arreglo de salida al original
	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}

	delete[] output;
}

// Coloca partitionBoletas ANTES de quickSortBoletas
int partitionBoletas(Boleta** arr, int low, int high, bool (*comparador)(const Boleta*, const Boleta*)) {
	Boleta* pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (comparador(arr[j], pivot)) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Ahora quickSortBoletas puede usar partitionBoletas
void quickSortBoletas(Boleta** arr, int low, int high, bool (*comparador)(const Boleta*, const Boleta*)) {
	if (low < high) {
		int pi = partitionBoletas(arr, low, high, comparador);
		quickSortBoletas(arr, low, pi - 1, comparador);
		quickSortBoletas(arr, pi + 1, high, comparador);
	}
}

// Función para convertir lista de boletas a arreglo (recibe referencia)
Boleta** convertirBoletasAArreglo(Lista<Boleta*>& lista, int& n) {
	n = lista.getTam();
	Boleta** arreglo = new Boleta * [n];
	for (int i = 0; i < n; i++) {
		arreglo[i] = lista.getValor(i);
	}
	return arreglo;
}


void ordenarBoletasAvanzado() {
	system("cls");
	cout << "\n\t\t\t--- ORDENAR BOLETAS ---\n";
	cout << "\t\t\t1. Por nombre de cliente\n";
	cout << "\t\t\t2. Por DNI de cliente\n";
	cout << "\t\t\t3. Por fecha\n";
	cout << "\t\t\t4. Por total\n";
	cout << "\t\t\t5. Por numero de boleta\n";
	cout << "\t\t\t0. Volver\n";
	cout << "\n\t\t\tSeleccione criterio (1-5): ";
	int criterio;
	cin >> criterio;
	if (criterio == 0) return;

	// Mostrar métodos de ordenamiento disponibles
	cout << "\n\t\t\tMétodo de ordenamiento:\n";
	cout << "\t\t\t1. InsertionSort\n";
	cout << "\t\t\t2. BubbleSort\n";
	cout << "\t\t\t3. SelectionSort\n";
	cout << "\t\t\t4. QuickSort\n";
	cout << "\n\t\t\tSeleccione método (1-4): ";
	int metodo;
	cin >> metodo;

	int n;
	Boleta** boletas = convertirBoletasAArreglo(listaBoletas, n);

	// Determinar función comparadora
	bool (*comparador)(const Boleta*, const Boleta*);
	switch (criterio) {
	case 1: comparador = compararBoletasPorNombreCliente; break;
	case 2: comparador = compararBoletasPorDNI; break;
	case 3: comparador = compararBoletasPorFecha; break;
	case 4: comparador = compararBoletasPorTotal; break;
	case 5: comparador = compararBoletasPorNumero; break;
	default:
		cout << "\n\t\t\tOpcion invalida.\n";
		delete[] boletas;
		return;
	}

	// Aplicar método de ordenamiento seleccionado
	switch (metodo) {
	case 1:
		insertionSort(boletas, n, comparador);
		break;
	case 2:
		bubbleSort(boletas, n, comparador);
		break;
	case 3:
		selectionSort(boletas, n, comparador);
		break;
	case 4:
		quickSortBoletas(boletas, 0, n - 1, comparador);
		break;
	default:
		cout << "\n\t\t\tMetodo invalido.\n";
		delete[] boletas;
		return;
	}

	// Actualizar listaBoletas con el nuevo orden
	for (int i = 0; i < n; ++i) {
		listaBoletas.setValor(i, boletas[i]);
	}

	// Mostrar boletas ordenadas
	cout << "\n\t\t\tBoletas ordenadas:\n";
	for (int i = 0; i < n; ++i) {
		cout << "\t\t\t" << (i + 1) << ". #" << boletas[i]->getNumeroBoleta()
			<< " | " << boletas[i]->getCliente()
			<< " | DNI: " << boletas[i]->getDNI()
			<< " | " << boletas[i]->getFecha()
			<< " | S/. " << boletas[i]->getTotal() << endl;
	}

	delete[] boletas;
	system("pause");
}

void ordenarProductosAvanzado() {
	system("cls");
	cout << "\n\t\t\t--- ORDENAR PRODUCTOS ---\n";
	cout << "\t\t\t1. Por ID\n";
	cout << "\t\t\t2. Por nombre\n";
	cout << "\t\t\t3. Por unidad de medida\n";
	cout << "\t\t\t4. Por precio final\n";
	cout << "\t\t\t5. Por cantidad\n";
	cout << "\t\t\t0. Volver\n";
	cout << "\n\t\t\tSeleccione criterio (1-5): ";
	int criterio;
	cin >> criterio;
	if (criterio == 0) return;

	// Mostrar métodos de ordenamiento disponibles
	cout << "\n\t\t\tMétodo de ordenamiento:\n";
	cout << "\t\t\t1. MergeSort\n";
	cout << "\t\t\t2. QuickSort\n";
	cout << "\t\t\t3. HeapSort\n";
	cout << "\t\t\t4. ShellSort\n";
	cout << "\n\t\t\tSeleccione método (1-4): ";
	int metodo;
	cin >> metodo;

	int n;
	Categoria** productos = convertirAArreglo(productosSeleccionados, n);

	// Determinar función comparadora
	bool (*comparador)(const Categoria*, const Categoria*);
	switch (criterio) {
	case 1: comparador = compararPorID; break;
	case 2: comparador = compararPorNombre; break;
	case 3: comparador = compararPorUnidadMedida; break;
	case 4: comparador = compararPorPrecioFinal; break;
	case 5: comparador = compararPorCantidad; break;
	default:
		cout << "\n\t\t\tOpcion invalida.\n";
		delete[] productos;
		return;
	}

	// Aplicar método de ordenamiento seleccionado
	switch (metodo) {
	case 1:
		mergeSort(productos, 0, n - 1, comparador);
		break;
	case 2:
		quickSort(productos, 0, n - 1, comparador);
		break;
	case 3:
		heapSort(productos, n, comparador);
		break;
	case 4:
		shellSort(productos, n, comparador);
		break;
	default:
		cout << "\n\t\t\tMetodo invalido.\n";
		delete[] productos;
		return;
	}

	// Actualizar productosSeleccionados con el nuevo orden
	for (int i = 0; i < n; ++i) {
		productosSeleccionados->setValor(i, productos[i]);
	}

	// Mostrar productos ordenados
	cout << "\n\t\t\tProductos ordenados:\n";
	for (int i = 0; i < n; ++i) {
		cout << "\t\t\t" << (i + 1) << ". ID: " << productos[i]->getID()
			<< "  " << productos[i]->getNombre()
			<< "  " << productos[i]->getUnidadMedida()
			<< "  S/. " << productos[i]->getPrecioFinal()
			<< "  Cant: " << productos[i]->getCantidad() << endl;
	}

	delete[] productos;
	system("pause");
}
//funcion para ordenar boletas


// Función para generar boleta (CORREGIDA)
void generarBoleta() {
	system("cls");

	if (productosSeleccionados->esVacia()) {
		cout << "\n No hay productos en el carrito." << endl;
		system("pause>0");
		return;
	}

	// Obtener nombre y DNI del usuario actual desde la instancia global
	string nombreCliente = sistemaUsuarios->getUsuarioActual().nombre + " " +
		sistemaUsuarios->getUsuarioActual().apellido_paterno;
	string dni = sistemaUsuarios->getUsuarioActual().DNI;


	int numeroBoleta = generarNumeroBoletaUnico();
	Boleta* nuevaBoleta = new Boleta(nombreCliente, dni, numeroBoleta);

	//// Verificar productos en el carrito
	//cout << "\n Productos en carrito:\n";
	//for (int i = 0; i < productosSeleccionados->longitud(); ++i) {
	//	Categoria* p = productosSeleccionados->getValor(i);
	//	if (p == nullptr) {
	//		cout << "-  Producto nulo en posicion " << i << endl;
	//		continue;
	//	}
	//	cout << "- " << p->getNombre() << " x" << p->getCantidad() << endl;
	//}

	//// Agregar productos (copias) a la boleta
	//cout << "\nAgregando productos a la boleta...\n";
	for (int i = 0; i < productosSeleccionados->longitud(); ++i) {
		Categoria* producto = productosSeleccionados->getValor(i);
		if (producto->getNombre().empty() || producto->getPrecioUnitario() == 0) {
			cout << " Producto invalido, no se agregara a la boleta" << endl;
			continue;
		}
		Categoria* copia = new Categoria();
		copia->setNombre(producto->getNombre());
		copia->setCantidad(producto->getCantidad());
		copia->setPrecioUnitario(producto->getPrecioUnitario());

		// Asegurar el descuento real (o uno por defecto)
		double descuento = producto->getPrecioDescuento();
		if (descuento == 0.0) {
			descuento = 0.2; // 20% si no tenía descuento
		}
		copia->setPrecioDescuento(descuento);

		nuevaBoleta->agregarProducto(copia);
	}

	// Verificar si realmente se agregaron productos a la boleta
	if (nuevaBoleta->estaVacia()) {
		cout << "\n No se pudo generar la boleta. La boleta esta vacia." << endl;
		delete nuevaBoleta;
		system("pause>0");
		return;
	}

	// Mostrar boleta
	cout << "\n Mostrando boleta:\n";
	nuevaBoleta->mostrarBoleta();

	tablaBoletas.insertar(nuevaBoleta);  // ⬅️ SOLO UN PARÁMETRO AHORA
	nuevaBoleta->guardarBoletaEnArchivo();

	// ✅ Agregar a listaBoletas para seguimiento
	listaBoletas.agregaFinal(nuevaBoleta);

	// --- PASO NUEVO: AÑADIR EL PEDIDO A LA COLA DE PROCESAMIENTO ---
	colaDePedidos.encolar(nuevaBoleta);
	cout << "\n>> Pedido Nro. " << nuevaBoleta->getNumeroBoleta()
		<< " ha sido enviado a la cola de procesamiento." << endl;
	// ----------------------------------------------------------------

	productosSeleccionados->limpiar();  // Limpiar el carrito después de generar la boleta
	system("pause>0");
}

// Función para buscar boleta específica (NUEVA)
void buscarBoletaEspecifica() {
	system("cls");
	string dni = sistemaUsuarios->getUsuarioActual().DNI;
	int numeroBoleta;

	cout << "\n=== BUSCAR BOLETA ESPECIFICA ===" << endl;
	cout << "Ingrese el numero de boleta: ";
	cin >> numeroBoleta;

	Boleta* boleta = tablaBoletas.buscar(dni, numeroBoleta);

	if (boleta != nullptr) {
		cout << "\n Boleta encontrada:\n";
		boleta->mostrarBoleta();
	}
	else {
		cout << "\n No se encontro la boleta numero " << numeroBoleta
			<< " para el DNI: " << dni << endl;
	}

	system("pause");
}
//NUEVAAAAAAAAZO
void adminBuscarBoletaEspecifica() {
	system("cls");
	int numeroBoleta;

	cout << "\n\t\t--- BUSCAR BOLETA ESPECIFICA (ADMIN) ---\n" << endl;
	cout << "\t\tIngrese el numero de boleta a buscar: ";
	cin >> numeroBoleta;

	// La búsqueda del admin debe ser global, sin depender de un DNI.
	// Usamos la lista principal de boletas para esto.
	Boleta* boletaEncontrada = nullptr;
	for (int i = 0; i < listaBoletas.longitud(); ++i) {
		if (listaBoletas.getValor(i)->getNumeroBoleta() == numeroBoleta) {
			boletaEncontrada = listaBoletas.getValor(i);
			break; // La encontramos, salimos del bucle
		}
	}

	if (boletaEncontrada != nullptr) {
		cout << "\n\t\tBoleta encontrada:\n";
		boletaEncontrada->mostrarBoleta();
	}
	else {
		cout << "\n\t\tNo se encontro ninguna boleta en el sistema con el numero " << numeroBoleta << endl;
	}

	system("pause>0");
}
// Función para mostrar estadísticas (NUEVA)
void mostrarEstadisticasTabla() {
	system("cls");
	cout << "\n=== ESTADISTICAS DE LA TABLA HASH ===" << endl;
	tablaBoletas.mostrarEstadisticas();
	system("pause");
}

// Menu de registro (MEJORADO)

//menu de cliente
void menuRegistroCliente() {
	int opcion;

	do {
		system("cls");
		cout << "\n\t===== MENU CLIENTE =====\n";
		cout << "1. Buscar mis boletas por DNI\n";
		cout << "2. Buscar boleta especifica\n";           // ⬅️ NUEVA OPCIÓN
		cout << "3. Mostrar todas las boletas\n";          // ⬅️ NUEVA OPCIÓN
		cout << "4. Salir\n";
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
			;

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
			cout << "Saliendo del menu...\n";
			break;

		default:
			cout << "Opcion no valida.\n";
			system("pause");
		}

	} while (opcion != 4);  // ⬅️ CAMBIÉ A 6 porque ahora hay más opciones
}



// Función auxiliar para verificar si una boleta existe (NUEVA)
bool existeBoleta(const string& dni, int numeroBoleta) {
	return tablaBoletas.contains(dni, numeroBoleta);
}

// Función para eliminar una boleta 
void eliminarBoleta() {
	system("cls");
	string dni = sistemaUsuarios->getUsuarioActual().DNI;
	int numeroBoleta;

	cout << "\n=== ELIMINAR BOLETA ===" << endl;
	cout << "Ingrese el numero de boleta a eliminar: ";
	cin >> numeroBoleta;

	if (tablaBoletas.remove(dni, numeroBoleta)) {
		cout << "\n Boleta eliminada correctamente." << endl;
	}
	else {
		cout << "\n No se pudo eliminar la boleta. Verifique el número." << endl;
	}

	system("pause");
}

//NUEVAAAZOO
void AdmineliminarBoleta() {
	system("cls");
	int numeroBoleta;
	cout << "\n\t\t--- ELIMINAR BOLETA (ADMIN) ---\n" << endl;
	cout << "\t\tIngrese el numero de boleta a eliminar: ";
	cin >> numeroBoleta;

	// --- Variables para guardar la información de la boleta a borrar ---
	Boleta* boletaAEliminar = nullptr;
	string dniDeLaBoleta = "";
	int indiceEnLista = -1;

	// 1. Buscamos la boleta en la lista principal para obtener sus datos
	for (int i = 0; i < listaBoletas.longitud(); ++i) {
		if (listaBoletas.getValor(i)->getNumeroBoleta() == numeroBoleta) {
			boletaAEliminar = listaBoletas.getValor(i);
			dniDeLaBoleta = boletaAEliminar->getDNI();
			indiceEnLista = i;
			break; // La encontramos, salimos del bucle
		}
	}

	// 2. Si encontramos la boleta, procedemos a eliminarla de todas partes
	if (boletaAEliminar != nullptr) {
		// A. Eliminar de la Tabla Hash, usando el método 'remove' que ya tienes
		tablaBoletas.remove(dniDeLaBoleta, numeroBoleta);

		// B. Eliminar de la Lista Principal, usando el método 'eliminaPos' que ya tienes
		listaBoletas.eliminaPos(indiceEnLista);

		// C. Liberar la memoria del objeto Boleta para evitar fugas de memoria
		delete boletaAEliminar;

		cout << "\n\t\t>> EXITO: Boleta " << numeroBoleta << " eliminada exitosamente." << endl;

		// IMPORTANTE: Aquí necesitarás una función que reescriba el archivo Boletas.txt
		// con la 'listaBoletas' actualizada para que el cambio sea permanente.
	}
	else {
		cout << "\n\t\tNo se encontro una boleta con el numero " << numeroBoleta << " para eliminar." << endl;
	}

	system("pause>0");
}

// Función para limpiar todas las boletas (NUEVA - Solo para administrador)
void limpiarTablaBoletas() {
	system("cls");
	cout << "\n  ¿Está seguro de que desea eliminar TODAS las boletas? (s/n): ";
	char confirmacion;
	cin >> confirmacion;

	if (confirmacion == 's' || confirmacion == 'S') {
		tablaBoletas.makeEmpty();
		cout << "\n Todas las boletas han sido eliminadas." << endl;
	}
	else {
		cout << "\n Operación cancelada." << endl;
	}

	system("pause");
}


//uso de generador database
void generarProductosDePrueba(Lista<Categoria*>& productos) {
	for (int i = 1; i <= 10; ++i) {
		string nombre = "Producto" + to_string(i);
		int cantidad = 1 + rand() % 5;
		double precio = 5.0 + rand() % 20;

		Categoria* p = new Categoria(nombre, cantidad, precio);

		// ✅ Descuento entre 10% y 30%
		double descuento = (rand() % 21 + 10) / 100.0; // entre 0.10 y 0.30
		p->setPrecioDescuento(descuento);

		productos.agregaFinal(p);
	}
}

void procesarCompra() {
	system("cls");
	// 1. VERIFICAR SI EL CARRITO ESTÁ VACÍO
	if (productosSeleccionados->esVacia()) {
		std::cout << "El carrito está vacío. No se puede procesar la compra.\n";
		return;
	}

	// 2. MOSTRAR RESUMEN FINAL DE LA COMPRA
	std::cout << "\n========== RESUMEN DE COMPRA ==========\n";
	double total = 0.0;
	for (int i = 0; i < productosSeleccionados->longitud(); ++i) {
		Categoria* item = productosSeleccionados->getValor(i);
		if (item) {
			double subtotal = item->getCantidad() * item->getPrecioUnitario();
			std::cout << item->getNombre() << " x" << item->getCantidad()
				<< " - S/. " << std::fixed << std::setprecision(2) << item->getPrecioUnitario()
				<< " c/u = S/. " << subtotal << std::endl;
			total += subtotal;
		}
	}
	std::cout << "----------------------------------------\n";
	std::cout << "TOTAL A PAGAR: S/. " << std::fixed << std::setprecision(2) << total << std::endl;
	std::cout << "========================================\n\n";

	// 3. PEDIR CONFIRMACIÓN FINAL
	char confirmar;
	do {
		system("cls"); // Limpia la pantalla para mostrar el resumen
		std::cout << "¿Confirma la compra? (S/N): ";
		std::cin >> confirmar;
		confirmar = tolower(confirmar);

		if (confirmar == 'n') {
			std::cout << "Compra cancelada.\n";
			return; // Sale de la función si el usuario cancela
		}
		if (confirmar != 's') {
			std::cout << "Opción no válida. Ingrese 'S' para confirmar o 'N' para cancelar.\n";
		}
	} while (confirmar != 's');

	// 4. SIMULAR ELECCIÓN DE MÉTODO DE PAGO
	int metodoPago;
	do {
		system("cls"); // Limpia la pantalla para mostrar el menú de pago
		std::cout << "\nSeleccione método de pago:\n";
		std::cout << "1. Tarjeta de Credito\n";
		std::cout << "2. Tarjeta de Debito\n";
		std::cout << "3. Yape / Plin\n";
		std::cout << "Opción: ";
		std::cin >> metodoPago;

		if (std::cin.fail() || metodoPago < 1 || metodoPago > 3) {
			std::cout << "Método de pago no válido. Intente nuevamente.\n";
			std::cin.clear(); // Limpia el estado de error de cin
			std::cin.ignore(10000, '\n'); // Descarta la entrada incorrecta
		}
	} while (metodoPago < 1 || metodoPago > 4);

	std::string metodos[] = { "", "Tarjeta de Crédito", "Tarjeta de Débito", "Efectivo", "Yape / Plin" };
	std::cout << "Método de pago seleccionado: " << metodos[metodoPago] << std::endl;

	/// Simular procesamiento de pago
	cout << "\nProcesando pago... ¡Pago aprobado!\n";

	// 5. ACTUALIZAR STOCK DE PRODUCTOS
	// ¡IMPORTANTE! Esto debe hacerse ANTES de generar la boleta, porque la boleta vacía el carrito.
	std::cout << "Actualizando inventario...\n";
	for (int i = 0; i < productosSeleccionados->longitud(); ++i) {
		Categoria* itemCarrito = productosSeleccionados->getValor(i);
		// Aquí debes buscar el producto en tu estructura de inventario principal y actualizarlo.
		// Por ejemplo, si tienes un árbol de productos:
		// Producto* productoEnInventario = arbolDeProductos->buscar(itemCarrito->getNombre());
		// if (productoEnInventario) {
		//     productoEnInventario->setStock(productoEnInventario->getStock() - itemCarrito->getCantidad());
		//     std::cout << " -> Stock de '" << productoEnInventario->getNombre() << "' actualizado.\n";
		// }
	}
	std::cout << "Inventario actualizado correctamente.\n\n";


	// 6. GENERAR LA BOLETA (esto también vaciará el carrito)
	generarBoleta();
	//FALTA LIMPIAR

	std::cout << "\n========================================\n";
	std::cout << "¡PROCESO DE COMPRA FINALIZADO EXITOSAMENTE!\n";
	std::cout << "========================================\n";
}


void confirmacioncase3() {
	system("cls"); // Limpia la pantalla para mostrar el mensaje de confirmación
	if (productosSeleccionados->esVacia()) {
		std::cout << "\nEl carrito de compras ya está vacío.\n";
		return;
	}

	char confirmacion;
	do {
		system("cls"); // Limpia la pantalla para mostrar el mensaje de confirmación
		std::cout << "\n¿Está seguro de que desea eliminar todos los productos de su carrito? (S/N): ";
		std::cin >> confirmacion;
		confirmacion = tolower(confirmacion); // Convertir a minúscula

		if (confirmacion == 's') {
			productosSeleccionados->limpiar(); // Llama a la función para vaciar la lista
			std::cout << "\n>> Su carrito de compras ha sido vaciado.\n";
			break; // Sale del bucle de confirmación
		}
		else if (confirmacion == 'n') {
			std::cout << "\nOperación cancelada. Sus productos siguen en el carrito.\n";
			break; // Sale del bucle de confirmación
		}
		else {
			std::cout << "Opción no válida. Por favor, ingrese 'S' o 'N'.\n";
			// Limpiar el buffer de entrada por si el usuario ingresó más de un carácter
			std::cin.ignore(10000, '\n');
		}
	} while (true); // El bucle se repite hasta que se ingrese 's' o 'n'
}

//aca va el menu
void menuCarrito() {
	system("cls");
	cout << "\n\n\t\t\t------ MENU CARRITO ------" << endl;
	cout << "\n\t\t\t1. Comprar\n";
	cout << "\n\t\t\t2. Ver carrito\n";
	cout << "\n\t\t\t3. Eliminar producto\n";
	cout << "\n\t\t\t4. Ver ofertas\n";
	cout << "\n\t\t\t5. Procesar compra\n";
	cout << "\n\t\t\t6. Buscar producto\n";
	cout << "\n\t\t\t7. Ordenar productos\n";
	cout << "\n\t\t\t0. Salir\n";
	cout << "\n\t\t\tSeleccione una opcion: ";
	int opcion;
	cin >> opcion;

	if (opcion < 0 || opcion > 7) {
		cout << "\t\t\tOpcion invalida. Presione una tecla para continuar...";
		system("pause>0");
		system("cls");
		return;
	}

	switch (opcion) {
	case 0:
		cout << "\n\t\t\tSALIENDO DEL SISTEMA..." << endl;
		break;
	case 1:
		comprar();
		break;
	case 2:
		verCarrito();
		break;
	case 3:
		eliminarProducto();
		break;
	case 4:
		verOfertas();
		break;
	case 5:
		procesarCompra();
		break;
	case 6:
		buscarProducto();
		break;
	case 7:
		ordenarProductosAvanzado();
		break;
	}
}

// --- FUNCIÓN AUXILIAR PARA LIMPIAR ESPACIOS Y CARACTERES INVISIBLES ---
string trim(const string& str) {
	const string whitespace = " \t\n\r\f\v";
	size_t first = str.find_first_not_of(whitespace);
	if (string::npos == first) {
		return "";
	}
	size_t last = str.find_last_not_of(whitespace);
	return str.substr(first, (last - first + 1));
}

// --- FUNCIÓN AUXILIAR PARA VALIDAR Y CONVERTIR PRECIO ---
bool convertirPrecio(const string& precioStr, double& precio) {
	string precioLimpio = trim(precioStr);

	// Reemplazar comas por puntos si es necesario
	for (char& c : precioLimpio) {
		if (c == ',') {
			c = '.';
		}
	}

	// Verificar que solo contenga dígitos, punto y posiblemente un signo negativo
	bool puntoEncontrado = false;
	for (size_t i = 0; i < precioLimpio.length(); i++) {
		char c = precioLimpio[i];
		if (c == '.') {
			if (puntoEncontrado) return false; // Más de un punto
			puntoEncontrado = true;
		}
		else if (c == '-' && i == 0) {
			// Permitir signo negativo al inicio
			continue;
		}
		else if (!isdigit(c)) {
			return false; // Carácter no válido
		}
	}

	if (precioLimpio.empty() || precioLimpio == "." || precioLimpio == "-") {
		return false;
	}

	try {
		precio = stod(precioLimpio);
		return true;
	}
	catch (const std::exception&) {
		return false;
	}
}

// --- FUNCIÓN PRINCIPAL CORREGIDA ---
void cargarBoletasDesdeArchivo() {
	ifstream archivo("Boletas.txt");
	if (!archivo.is_open()) {
		cout << "ADVERTENCIA: No se encontró 'Boletas.txt'." << endl;
		return;
	}

	string linea;
	Boleta* boletaActual = nullptr;
	int numeroDeLinea = 0;

	while (getline(archivo, linea)) {
		numeroDeLinea++;
		linea = trim(linea);

		if (linea.empty()) {
			continue;
		}

		try {
			if (linea.rfind("N° Boleta: ", 0) == 0) {
				// Procesar boleta anterior si existe
				if (boletaActual != nullptr) {
					boletaActual->calcularTotal();
					listaBoletas.agregaFinal(boletaActual);
					tablaBoletas.insertar(boletaActual);
				}

				// Crear nueva boleta
				int numero = stoi(linea.substr(linea.find(": ") + 2));
				getline(archivo, linea); numeroDeLinea++;

				size_t posDNI = linea.find(" (DNI: ");
				string nombre = linea.substr(linea.find(": ") + 2, posDNI - (linea.find(": ") + 2));
				string dni = linea.substr(posDNI + 7, 8);

				getline(archivo, linea); numeroDeLinea++; // Línea de fecha
				boletaActual = new Boleta(nombre, dni, numero);
			}
			else if (boletaActual != nullptr && isdigit(linea[0]) && linea.find(" - Cantidad: ") != string::npos) {
				// Procesar línea de producto
				string nombreProducto, cantidadStr, precioStr;

				// Extraer nombre del producto
				size_t inicioNombre = linea.find(". ") + 2;
				size_t finNombre = linea.find(" - Cantidad:");
				nombreProducto = linea.substr(inicioNombre, finNombre - inicioNombre);

				// Extraer cantidad
				size_t inicioCantidad = linea.find(": ", finNombre) + 2;
				size_t finCantidad = linea.find(" - Precio:", inicioCantidad);
				cantidadStr = linea.substr(inicioCantidad, finCantidad - inicioCantidad);
				int cantidad = stoi(trim(cantidadStr));

				// Extraer precio con mejor validación
				size_t posS = linea.find("S/. ");
				if (posS == string::npos) {
					cout << "ERROR: No se encontró 'S/. ' en línea " << numeroDeLinea << endl;
					cout << "Línea completa: " << linea << endl;
					continue;
				}

				size_t inicioPrecio = posS + 4; // Después de "S/. "
				size_t finPrecio = linea.find(" ", inicioPrecio);
				if (finPrecio == string::npos) {
					precioStr = linea.substr(inicioPrecio);
				}
				else {
					precioStr = linea.substr(inicioPrecio, finPrecio - inicioPrecio);
				}

				// Validar y convertir precio
				double precio;
				if (!convertirPrecio(precioStr, precio)) {
					cout << "ERROR: Precio inválido en línea " << numeroDeLinea
						<< ". Precio encontrado: '" << precioStr << "'" << endl;
					cout << "Línea completa: " << linea << endl;
					continue; // Saltar este producto pero continuar con la boleta
				}

				// Crear y agregar producto
				Categoria* producto = new Categoria();
				producto->setNombre(nombreProducto);
				producto->setCantidad(cantidad);
				producto->setPrecioUnitario(precio);
				producto->setPrecioDescuento(0.0);
				boletaActual->agregarProducto(producto);
			}
		}
		catch (const std::exception& e) {
			cout << "ERROR: Se ignoró la línea " << numeroDeLinea
				<< " por formato inválido. Motivo: " << e.what() << endl;
			cout << "Línea problemática: " << linea << endl;

			// Solo eliminar boleta si el error fue al crearla
			if (linea.rfind("N° Boleta: ", 0) == 0 && boletaActual != nullptr) {
				delete boletaActual;
				boletaActual = nullptr;
			}
		}
	}

	// Procesar última boleta
	if (boletaActual != nullptr) {
		boletaActual->calcularTotal();
		listaBoletas.agregaFinal(boletaActual);
		tablaBoletas.insertar(boletaActual);
	}

	//cout << "\nINFO: Carga de historial finalizada. Se cargaron "
		//<< listaBoletas.longitud() << " boletas." << endl;
	archivo.close();
}
//CAMBIO DE POSICION NUEVOOO
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
			string dniBuscar;
			cout << "\n\t\t--- BUSCAR BOLETAS POR DNI (ADMIN) ---\n" << endl;
			cout << "\t\tIngrese el DNI del cliente a buscar: ";
			cin >> dniBuscar;

			cout << "\n\t\tBuscando boletas para DNI: " << dniBuscar << "\n";
			tablaBoletas.buscarPorDNI(dniBuscar); // Tu función de tabla hash aquí funciona bien
			system("pause>0");
			break;
		}

		case 2:
			adminBuscarBoletaEspecifica();
			break;

		case 3:
			system("cls");
			cout << "\n=== TODAS LAS BOLETAS ===" << endl;
			tablaBoletas.mostrarTodas();
			system("pause");
			break;

		case 4:
			AdmineliminarBoleta();
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
