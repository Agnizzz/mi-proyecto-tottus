#pragma once
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "CategoriaGeneral.h"
#include "CategoriasEstructura.h"
#include "Lista.h"
#include "IDpropio.h"
#include "Promociones.h"//NUEVO
#include "ArbolBB.h" // //CAMBIOS EL 06/07/2025 7:00 AM




using namespace std;

class Catalogo {
private:
    // Mapa: idPrincipal -> secundaria -> terciaria -> lista enlazada de productos
    map<int, map<string, map<string, Lista<Categoria>>>> productos;
    ArbolBinarioBusqueda<Categoria>* arbolDeProductos;//CAMBIOS EL 06/07/2025 7:00 AMSASASAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

public:
    //OJOOOOOO
    Catalogo() {
        arbolDeProductos = new ArbolBinarioBusqueda<Categoria>();//CAMBIOS EL 06/07/2025 7:00 AMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        cargarDesdeArchivo("producto.txt");
       
    }
    //DESTRUCTOR
    //CAMBIOS EL 06/07/2025 7:00 AM

    
    ~Catalogo() {
        // Liberamos la memoria en el destructor
        delete arbolDeProductos;
    }
    // REEMPLAZA LA VERSIÓN ANTERIOR CON ESTA:NUEVOOOOOOOOOOOO
    map<int, map<string, map<string, Lista<Categoria>>>>& getProductos() { return productos; }

    int buscarIndice(const string* arr, int tam, const string& valor) {
        for (int i = 0; i < tam; ++i)
            if (arr[i] == valor) return i + 1;
        return 0;
    }

    void cargarDesdeArchivo(const string& archivo) {
        ifstream file(archivo);
        if (!file.is_open()) {
            cerr << "No se pudo abrir el archivo: " << archivo << endl;
            return;
        }

        string linea;
        // Mapas para asignar índices únicos a secundaria y terciaria por nombre
        map<int, map<string, int>> secIndex;
        map<int, map<string, map<string, int>>> terIndex;
        map<int, map<string, map<string, int>>> prodIndex;

        while (getline(file, linea)) {
            if (linea.empty() || linea[0] == '#') continue;

            stringstream ss(linea);
            string idPrincipalStr, secundaria, terciaria, nombreProducto, precioUnitarioStr, unidadMedida;

            getline(ss, idPrincipalStr, ',');
            getline(ss, secundaria, ',');
            getline(ss, terciaria, ',');
            getline(ss, nombreProducto, ',');
            getline(ss, precioUnitarioStr, ',');
            getline(ss, unidadMedida, ',');

            if (idPrincipalStr.empty() || secundaria.empty() || terciaria.empty() ||
                nombreProducto.empty() || precioUnitarioStr.empty() || unidadMedida.empty()) {
                continue;
            }

            int idPrincipal;
            double precioUnitario;
            try {
                idPrincipal = stoi(idPrincipalStr);
                precioUnitario = stod(precioUnitarioStr);
            }
            catch (const std::exception& e) {
                cerr << "Error de conversión en línea: " << linea << "\nDetalle: " << e.what() << endl;
                continue;
            }

            // Índice de secundaria
            int idxSec = 0, idxTer = 0;
            if (idPrincipal == 1) { // Abarrotes
                idxSec = buscarIndice(subcategoriasAbarrotes, sizeof(subcategoriasAbarrotes) / sizeof(string), secundaria);
                if (secundaria == "Arroz")
                    idxTer = buscarIndice(terciariasArroz, sizeof(terciariasArroz) / sizeof(string), terciaria);
                else if (secundaria == "Conservas")
                    idxTer = buscarIndice(terciariasConservas, sizeof(terciariasConservas) / sizeof(string), terciaria);
                else if (secundaria == "Aceite")
                    idxTer = buscarIndice(terciariasAceite, sizeof(terciariasAceite) / sizeof(string), terciaria);
                else if (secundaria == "Pasta")
                    idxTer = buscarIndice(terciariasPasta, sizeof(terciariasPasta) / sizeof(string), terciaria);
                else if (secundaria == "Menestras")
                    idxTer = buscarIndice(terciariasMenestras, sizeof(terciariasMenestras) / sizeof(string), terciaria);
                else if (secundaria == "Sal")
                    idxTer = buscarIndice(terciariasSal, sizeof(terciariasSal) / sizeof(string), terciaria);
                else if (secundaria == "Salsas para Pasta")
                    idxTer = buscarIndice(terciariasSalsasPasta, sizeof(terciariasSalsasPasta) / sizeof(string), terciaria);
                else if (secundaria == "Salsas/Cremas")
                    idxTer = buscarIndice(terciariasSalsasCremas, sizeof(terciariasSalsasCremas) / sizeof(string), terciaria);
                else if (secundaria == "Condimentos")
                    idxTer = buscarIndice(terciariasCondimentos, sizeof(terciariasCondimentos) / sizeof(string), terciaria);
                else if (secundaria == "Especias")
                    idxTer = buscarIndice(terciariasEspecias, sizeof(terciariasEspecias) / sizeof(string), terciaria);
                else if (secundaria == "Pure Sopas y Bases")
                    idxTer = buscarIndice(terciariasPure, sizeof(terciariasPure) / sizeof(string), terciaria);
                else if (secundaria == "Harina")
                    idxTer = buscarIndice(terciariasHarina, sizeof(terciariasHarina) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 2) { // Desayunos
                idxSec = buscarIndice(subcategoriasDesayunos, sizeof(subcategoriasDesayunos) / sizeof(string), secundaria);
                if (secundaria == "Panaderia")
                    idxTer = buscarIndice(terciariasPan, sizeof(terciariasPan) / sizeof(string), terciaria);
                else if (secundaria == "Azucar y Sustitutos")
                    idxTer = buscarIndice(terciariasAzucar, sizeof(terciariasAzucar) / sizeof(string), terciaria);
                else if (secundaria == "Cafe e Infusiones")
                    idxTer = buscarIndice(terciariasCafe, sizeof(terciariasCafe) / sizeof(string), terciaria);
                else if (secundaria == "Cereales")
                    idxTer = buscarIndice(terciariasCereales, sizeof(terciariasCereales) / sizeof(string), terciaria);
                else if (secundaria == "Modificadores y Complementos")
                    idxTer = buscarIndice(terciariasModificadores, sizeof(terciariasModificadores) / sizeof(string), terciaria);
                else if (secundaria == "Mermeladas Mieles y Dulces")
                    idxTer = buscarIndice(terciariasMermeladas, sizeof(terciariasMermeladas) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 3) { // Lacteos y Quesos
                idxSec = buscarIndice(subcategoriasLacteos, sizeof(subcategoriasLacteos) / sizeof(string), secundaria);
                if (secundaria == "Leches")
                    idxTer = buscarIndice(terciariasLeches, sizeof(terciariasLeches) / sizeof(string), terciaria);
                else if (secundaria == "Yogurt")
                    idxTer = buscarIndice(terciariasYogurt, sizeof(terciariasYogurt) / sizeof(string), terciaria);
                else if (secundaria == "Quesos")
                    idxTer = buscarIndice(terciariasQuesos, sizeof(terciariasQuesos) / sizeof(string), terciaria);
                else if (secundaria == "Quesos del Mundo")
                    idxTer = buscarIndice(terciariasQuesosMundo, sizeof(terciariasQuesosMundo) / sizeof(string), terciaria);
                else if (secundaria == "Mantequillas y Margarinas")
                    idxTer = buscarIndice(terciariasMantequillas, sizeof(terciariasMantequillas) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 4) { // Huevos y Fiambres
                idxSec = buscarIndice(subcategoriasHuevos, sizeof(subcategoriasHuevos) / sizeof(string), secundaria);
                if (secundaria == "Huevos")
                    idxTer = buscarIndice(terciariasHuevo, sizeof(terciariasHuevo) / sizeof(string), terciaria);
                else if (secundaria == "Jamones")
                    idxTer = buscarIndice(terciariasJamones, sizeof(terciariasJamones) / sizeof(string), terciaria);
                else if (secundaria == "Jamonadas")
                    idxTer = buscarIndice(terciariasJamonadas, sizeof(terciariasJamonadas) / sizeof(string), terciaria);
                else if (secundaria == "Salchichas y Hot Dogs")
                    idxTer = buscarIndice(terciariasSalchichas, sizeof(terciariasSalchichas) / sizeof(string), terciaria);
                else if (secundaria == "Chorizos")
                    idxTer = buscarIndice(terciariasChorizos, sizeof(terciariasChorizos) / sizeof(string), terciaria);
                else if (secundaria == "Fiambres Gourmet")
                    idxTer = buscarIndice(terciariasFiambres, sizeof(terciariasFiambres) / sizeof(string), terciaria);
                else if (secundaria == "Otros Fiambres")
                    idxTer = buscarIndice(terciariasOtrasFiambres, sizeof(terciariasOtrasFiambres) / sizeof(string), terciaria);
                else if (secundaria == "Salsas y Cocktail")
                    idxTer = buscarIndice(terciariasSalsas, sizeof(terciariasSalsas) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 5) { // Frutas y Verduras
                idxSec = buscarIndice(subcategoriasFrutas, sizeof(subcategoriasFrutas) / sizeof(string), secundaria);
                if (secundaria == "Frutas")
                    idxTer = buscarIndice(terciariasFruta, sizeof(terciariasFruta) / sizeof(string), terciaria);
                else if (secundaria == "Verduras")
                    idxTer = buscarIndice(terciariasVerdura, sizeof(terciariasVerdura) / sizeof(string), terciaria);
                else if (secundaria == "Organicos")
                    idxTer = buscarIndice(terciariasOrganicos, sizeof(terciariasOrganicos) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 6) { // Carnes
                idxSec = buscarIndice(subcategoriasCarnes, sizeof(subcategoriasCarnes) / sizeof(string), secundaria);
                if (secundaria == "Pollo")
                    idxTer = buscarIndice(terciariasPollo, sizeof(terciariasPollo) / sizeof(string), terciaria);
                else if (secundaria == "Res")
                    idxTer = buscarIndice(terciariasRes, sizeof(terciariasRes) / sizeof(string), terciaria);
                else if (secundaria == "Cerdo")
                    idxTer = buscarIndice(terciariasCerdo, sizeof(terciariasCerdo) / sizeof(string), terciaria);
                else if (secundaria == "Pavo")
                    idxTer = buscarIndice(terciariasPavo, sizeof(terciariasPavo) / sizeof(string), terciaria);
                else if (secundaria == "Carnes Regionales")
                    idxTer = buscarIndice(terciariasCarnesRegionales, sizeof(terciariasCarnesRegionales) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 7) { // Pescados y Mariscos
                idxSec = buscarIndice(subcategoriasPescados, sizeof(subcategoriasPescados) / sizeof(string), secundaria);
                if (secundaria == "Pescados Congelados")
                    idxTer = buscarIndice(terciariasPescadosCongelados, sizeof(terciariasPescadosCongelados) / sizeof(string), terciaria);
                else if (secundaria == "Mariscos Congelados")
                    idxTer = buscarIndice(terciariasMariscosCongelados, sizeof(terciariasMariscosCongelados) / sizeof(string), terciaria);
                else if (secundaria == "Frescos")
                    idxTer = buscarIndice(terciariasFrescos, sizeof(terciariasFrescos) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 8) { // Congelados
                idxSec = buscarIndice(subcategoriasCongelados, sizeof(subcategoriasCongelados) / sizeof(string), secundaria);
                if (secundaria == "Hamburguesas")
                    idxTer = buscarIndice(terciariasHamburguesas, sizeof(terciariasHamburguesas) / sizeof(string), terciaria);
                else if (secundaria == "Nuggets y Empanizados")
                    idxTer = buscarIndice(terciariasNuggets, sizeof(terciariasNuggets) / sizeof(string), terciaria);
                else if (secundaria == "Frutas y Verduras Congeladas")
                    idxTer = buscarIndice(terciariasFrutasCongeladas, sizeof(terciariasFrutasCongeladas) / sizeof(string), terciaria);
                else if (secundaria == "Helados")
                    idxTer = buscarIndice(terciariasHelados, sizeof(terciariasHelados) / sizeof(string), terciaria);
                else if (secundaria == "Pizzas Pastas y Bocaditos")
                    idxTer = buscarIndice(terciariasPizzas, sizeof(terciariasPizzas) / sizeof(string), terciaria);
            }
            else if (idPrincipal == 9) { // Panaderia y Pasteleria
                idxSec = buscarIndice(subcategoriasPanaderia, sizeof(subcategoriasPanaderia) / sizeof(string), secundaria);
                if (secundaria == "Panes")
                    idxTer = buscarIndice(terciariasPanes, sizeof(terciariasPanes) / sizeof(string), terciaria);
                else if (secundaria == "Kekes y Chifones")
                    idxTer = buscarIndice(terciariasKekes, sizeof(terciariasKekes) / sizeof(string), terciaria);
                else if (secundaria == "Tostadas y Bocaditos")
                    idxTer = buscarIndice(terciariasTostadas, sizeof(terciariasTostadas) / sizeof(string), terciaria);
                else if (secundaria == "Postres y Tortas")
                    idxTer = buscarIndice(terciariasPostres, sizeof(terciariasPostres) / sizeof(string), terciaria);
            }
			else if (idPrincipal == 10) { // Dulces y Galletas
				idxSec = buscarIndice(subcategoriasDulces, sizeof(subcategoriasDulces) / sizeof(string), secundaria);
				if (secundaria == "Galletas")
					idxTer = buscarIndice(terciariasGalletas, sizeof(terciariasGalletas) / sizeof(string), terciaria);
				else if (secundaria == "Caramelos y Chupetes")
					idxTer = buscarIndice(terciariasCaramelos, sizeof(terciariasCaramelos) / sizeof(string), terciaria);
				else if (secundaria == "Chocolates")
					idxTer = buscarIndice(terciariasChocolates, sizeof(terciariasChocolates) / sizeof(string), terciaria);
				else if (secundaria == "Marshmallows y Gomitas")
					idxTer = buscarIndice(terciariasMarshmallows, sizeof(terciariasMarshmallows) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 11) { // Snack y Frutos Secos
				idxSec = buscarIndice(subcategoriasSnack, sizeof(subcategoriasSnack) / sizeof(string), secundaria);
				if (secundaria == "Frutos Secos")
					idxTer = buscarIndice(terciariasFrutosSecos, sizeof(terciariasFrutosSecos) / sizeof(string), terciaria);
				else if (secundaria == "Snacks")
					idxTer = buscarIndice(terciariasSnacks, sizeof(terciariasSnacks) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 12) { // Cervezas
				idxSec = buscarIndice(subcategoriasCervezas, sizeof(subcategoriasCervezas) / sizeof(string), secundaria);
				if (secundaria == "Cervezas Nacionales")
					idxTer = buscarIndice(terciariasCervezasNacionales, sizeof(terciariasCervezasNacionales) / sizeof(string), terciaria);
				else if (secundaria == "Cervezas Importadas")
					idxTer = buscarIndice(terciariasCervezasImportadas, sizeof(terciariasCervezasImportadas) / sizeof(string), terciaria);
				else if (secundaria == "Cervezas Artesanales")
					idxTer = buscarIndice(terciariasCervezasArtesanales, sizeof(terciariasCervezasArtesanales) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 13) { // Bebidas Alcoholicas
				idxSec = buscarIndice(subcategoriasBebidas, sizeof(subcategoriasBebidas) / sizeof(string), secundaria);
				if (secundaria == "Vinos y Espumantes")
					idxTer = buscarIndice(terciariasVinos, sizeof(terciariasVinos) / sizeof(string), terciaria);
				else if (secundaria == "Whisky")
					idxTer = buscarIndice(terciariasWhisky, sizeof(terciariasWhisky) / sizeof(string), terciaria);
				else if (secundaria == "Ron")
					idxTer = buscarIndice(terciariasRon, sizeof(terciariasRon) / sizeof(string), terciaria);
				else if (secundaria == "Pisco")
					idxTer = buscarIndice(terciariasPisco, sizeof(terciariasPisco) / sizeof(string), terciaria);
				else if (secundaria == "Vodka")
					idxTer = buscarIndice(terciariasVodka, sizeof(terciariasVodka) / sizeof(string), terciaria);
				else if (secundaria == "Tequila")
					idxTer = buscarIndice(terciariasTequila, sizeof(terciariasTequila) / sizeof(string), terciaria);
				else if (secundaria == "Gin")
					idxTer = buscarIndice(terciariasGin, sizeof(terciariasGin) / sizeof(string), terciaria);
				else if (secundaria == "Ready To Drink")
					idxTer = buscarIndice(terciariasReady, sizeof(terciariasReady) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 14) { // Gaseosas, Aguas y Jugos
				idxSec = buscarIndice(subcategoriasGaseosas, sizeof(subcategoriasGaseosas) / sizeof(string), secundaria);
				if (secundaria == "Aguas")
					idxTer = buscarIndice(terciariasAguas, sizeof(terciariasAguas) / sizeof(string), terciaria);
				else if (secundaria == "Energizantes y Rehidratantes")
					idxTer = buscarIndice(terciariasEnergizantes, sizeof(terciariasEnergizantes) / sizeof(string), terciaria);
				else if (secundaria == "Gaseosas")
					idxTer = buscarIndice(terciariasGaseosa, sizeof(terciariasGaseosa) / sizeof(string), terciaria);
				else if (secundaria == "Ginger Ale")
					idxTer = buscarIndice(terciariasGinger, sizeof(terciariasGinger) / sizeof(string), terciaria);
				else if (secundaria == "Jugos y Tes Liquidos")
					idxTer = buscarIndice(terciariasJugos, sizeof(terciariasJugos) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 15) { // Limpieza
				idxSec = buscarIndice(subcategoriasLimpieza, sizeof(subcategoriasLimpieza) / sizeof(string), secundaria);
				if (secundaria == "Accesorios de Limpieza")
					idxTer = buscarIndice(terciariasAccesorios, sizeof(terciariasAccesorios) / sizeof(string), terciaria);
				else if (secundaria == "Ambientadores")
					idxTer = buscarIndice(terciariasAmbientadores, sizeof(terciariasAmbientadores) / sizeof(string), terciaria);
				else if (secundaria == "Bolsas y Envolturas")
					idxTer = buscarIndice(terciariasBolsas, sizeof(terciariasBolsas) / sizeof(string), terciaria);
				else if (secundaria == "Descartables")
					idxTer = buscarIndice(terciariasDescartables, sizeof(terciariasDescartables) / sizeof(string), terciaria);
				else if (secundaria == "Detergente y Cuidado de la Ropa")
					idxTer = buscarIndice(terciariasDetergente, sizeof(terciariasDetergente) / sizeof(string), terciaria);
				else if (secundaria == "Encendido de Parrilla")
					idxTer = buscarIndice(terciariasEncendido, sizeof(terciariasEncendido) / sizeof(string), terciaria);
				else if (secundaria == "Lavavajillas")
					idxTer = buscarIndice(terciariasLavavajillas, sizeof(terciariasLavavajillas) / sizeof(string), terciaria);
				else if (secundaria == "Lejia")
					idxTer = buscarIndice(terciariasLejia, sizeof(terciariasLejia) / sizeof(string), terciaria);
				else if (secundaria == "Limpiadores")
					idxTer = buscarIndice(terciariasLimpiadores, sizeof(terciariasLimpiadores) / sizeof(string), terciaria);
				else if (secundaria == "Para Calzado")
					idxTer = buscarIndice(terciariasCalzado, sizeof(terciariasCalzado) / sizeof(string), terciaria);
				else if (secundaria == "Papeles Higienicos")
					idxTer = buscarIndice(terciariasPapeles, sizeof(terciariasPapeles) / sizeof(string), terciaria);
				else if (secundaria == "Otros Papeles")
					idxTer = buscarIndice(terciariasOtrosPapeles, sizeof(terciariasOtrosPapeles) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 16) { // Cuidado Personal
				idxSec = buscarIndice(subcategoriasCuidado, sizeof(subcategoriasCuidado) / sizeof(string), secundaria);
				if (secundaria == "Cuidado Capilar")
					idxTer = buscarIndice(terciariasCuidadoCapilar, sizeof(terciariasCuidadoCapilar) / sizeof(string), terciaria);
				else if (secundaria == "Jabones")
					idxTer = buscarIndice(terciariasJabones, sizeof(terciariasJabones) / sizeof(string), terciaria);
				else if (secundaria == "Higiene Bucal")
					idxTer = buscarIndice(terciariasHigiene, sizeof(terciariasHigiene) / sizeof(string), terciaria);
				else if (secundaria == "Cuidado Mujer")
					idxTer = buscarIndice(terciariasCuidadoMujer, sizeof(terciariasCuidadoMujer) / sizeof(string), terciaria);
				else if (secundaria == "Cuidado Hombre")
					idxTer = buscarIndice(terciariasCuidadoHombre, sizeof(terciariasCuidadoHombre) / sizeof(string), terciaria);
				else if (secundaria == "Incontinencia")
					idxTer = buscarIndice(terciariasIncontinencia, sizeof(terciariasIncontinencia) / sizeof(string), terciaria);
				else if (secundaria == "Salud y Bienestar")
					idxTer = buscarIndice(terciariasSalud, sizeof(terciariasSalud) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 17) { // Belleza
				idxSec = buscarIndice(subcategoriasBelleza, sizeof(subcategoriasBelleza) / sizeof(string), secundaria);
				if (secundaria == "Cremas Faciales")
					idxTer = buscarIndice(terciariasCremas, sizeof(terciariasCremas) / sizeof(string), terciaria);
				else if (secundaria == "Cuidado del Rostro")
					idxTer = buscarIndice(terciariasCuidadoRostro, sizeof(terciariasCuidadoRostro) / sizeof(string), terciaria);
				else if (secundaria == "Proteccion Solar")
					idxTer = buscarIndice(terciariasProteccion, sizeof(terciariasProteccion) / sizeof(string), terciaria);
				else if (secundaria == "Perfumeria")
					idxTer = buscarIndice(terciariasPerfumeria, sizeof(terciariasPerfumeria) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 18) { // Bebes y Niños
				idxSec = buscarIndice(subcategoriasBebes, sizeof(subcategoriasBebes) / sizeof(string), secundaria);
				if (secundaria == "Pa¤ales")
					idxTer = buscarIndice(terciariasPaniales, sizeof(terciariasPaniales) / sizeof(string), terciaria);
				else if (secundaria == "Aseo del Bebe")
					idxTer = buscarIndice(terciariasAseo, sizeof(terciariasAseo) / sizeof(string), terciaria);
				else if (secundaria == "Alimentos para Bebes")
					idxTer = buscarIndice(terciariasAlimentos, sizeof(terciariasAlimentos) / sizeof(string), terciaria);
			}
			else if (idPrincipal == 19) { // Mundo Mascotas
				idxSec = buscarIndice(subcategoriasMascotas, sizeof(subcategoriasMascotas) / sizeof(string), secundaria);
				if (secundaria == "Perros")
					idxTer = buscarIndice(terciariasPerros, sizeof(terciariasPerros) / sizeof(string), terciaria);
				else if (secundaria == "Gatos")
					idxTer = buscarIndice(terciariasGatos, sizeof(terciariasGatos) / sizeof(string), terciaria);
				else if (secundaria == "Higiene")
					idxTer = buscarIndice(terciariasHigieneMascota, sizeof(terciariasHigieneMascota) / sizeof(string), terciaria);
				else if (secundaria == "Accesorios")
					idxTer = buscarIndice(terciariasAccesoriosMascota, sizeof(terciariasAccesoriosMascota) / sizeof(string), terciaria);
			}

            // Índice de producto dentro de la terciaria
            int& idxP = prodIndex[idPrincipal][secundaria][terciaria];
            idxP++;

            // Generar el ID único
            string id = generarCodigo(idPrincipal, idxSec, idxTer, idxP);

            // Crear el producto (objeto Categoria)
            Categoria producto;
            producto.setID(id);
            producto.setNombre(nombreProducto);
            producto.setUnidadMedida(unidadMedida);
            producto.setPrecioUnitario(precioUnitario);

            productos[idPrincipal][secundaria][terciaria].agregaFinal(producto);
            arbolDeProductos->insertar(producto);//FORCHI NUEVO
        }
        file.close();
    }

    // Obtener todos los productos de una categoría principal
    const map<string, map<string, Lista<Categoria>>>& getPorIdPrincipal(int idPrincipal) const {
        return productos.at(idPrincipal);
    }

    // Obtener productos por secundaria y terciaria
    const Lista<Categoria>& getPorCategoria(int idPrincipal, const string& secundaria, const string& terciaria) const {
        return productos.at(idPrincipal).at(secundaria).at(terciaria);
    }

    // Puedes agregar más métodos según lo necesites
     // Obtener productos por secundaria y terciaria SIN CONST
    Lista<Categoria>& getPorCategoria(int idPrincipal, const string& secundaria, const string& terciaria) {
        return productos.at(idPrincipal).at(secundaria).at(terciaria);
    }

    //CAMBIOS EL 06/07/2025 7:00 AM
    ArbolBinarioBusqueda<Categoria>* getArbolProductos() {
        return arbolDeProductos; // El nombre aquí debe coincidir con el de arriba
    }
   
};
