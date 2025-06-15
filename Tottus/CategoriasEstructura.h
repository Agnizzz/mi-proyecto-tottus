#pragma once
#include <string>
using namespace std;

// Categor�as principales
const int numCategoriasPrincipales = 19;
const string categoriasPrincipales[numCategoriasPrincipales] = {
    "Abarrotes", "Desayunos", "Lacteos y Quesos", "Huevos y Fiambres", "Frutas y Verduras",
    "Carnes", "Pescados y Mariscos", "Congelados", "Panaderia y Pasteleria", "Dulces y Galletas",
    "Snack y Frutos Secos", "Cervezas", "Bebidas Alcoholicas", "Gaseosas, Aguas y Jugos",
    "Limpieza", "Cuidado Personal", "Belleza", "Bebes y Ninios", "Mundo Mascotas"
};

// -------------------- SUBCATEGOR�AS --------------------

const int numSubcategoriasAbarrotes = 12;
const string subcategoriasAbarrotes[numSubcategoriasAbarrotes] = {
    "Arroz","Conservas","Aceite","Pasta","Menestras","Sal",
    "Salsas para Pasta","Salsas/Cremas","Condimentos",
    "Especias","Pur�, Sopas y Bases","Harina"
};

const int numSubcategoriasDesayunos = 6;
const string subcategoriasDesayunos[numSubcategoriasDesayunos] = {
    u8"Panader�a",u8"Az�car y Sustitutos",u8"Caf� e Infusiones",
    "Cereales","Modificadores y Complementos","Mermeladas, Mieles y Dulces"
};

const int numSubcategoriasLacteos = 5;
const string subcategoriasLacteos[numSubcategoriasLacteos] = {
    "Leches","Yogurt","Quesos","Quesos del Mundo","Mantequillas y Margarinas"
};

const int numSubcategoriasHuevos = 8;
const string subcategoriasHuevos[numSubcategoriasHuevos] = {
    "Huevos","Jamones","Jamonadas","Salchichas y Hot Dogs",
            "Chorizos","Fiambres Gourmet","Otros Fiambres","Salsas y Cocktail",
};

const int numSubcategoriasFrutas = 3;
const string subcategoriasFrutas[numSubcategoriasFrutas] = {
    "Frutas","Verduras",u8"Org�nicos"
};

const int numSubcategoriasCarnes = 5;
const string subcategoriasCarnes[numSubcategoriasCarnes] = {
    "Pollo","Res","Cerdo","Pavo","Carnes Regionales"
};

const int numSubcategoriasPescados = 4;
const string subcategoriasPescados[numSubcategoriasPescados] = {
    "Pescados Congelados","Mariscos Congelados","Frescos"
};

const int numSubcategoriasCongelados = 5;
const string subcategoriasCongelados[numSubcategoriasCongelados] = {
    "Hamburguesas","Nuggets y Empanizados",
            "Frutas y Verduras Congeladas","Helados",
            "Pizzas,Pastas y Bocaditos"
};

const int numSubcategoriasPanaderia = 4;
const string subcategoriasPanaderia[numSubcategoriasPanaderia] = {
    "Panes","Kekes y Chifones","Tostadas y Bocaditos","Postres y Tortas"
};

const int numSubcategoriasDulces = 4;
const string subcategoriasDulces[numSubcategoriasDulces] = {
    "Galletas","Caramelos y Chupetes","Chocolates","Marshmallows y Gomitas"
};

const int numSubcategoriasSnack = 2;
const string subcategoriasSnack[numSubcategoriasSnack] = {
    "Frutos Secos","Snacks"
};

const int numSubcategoriasCervezas = 3;
const string subcategoriasCervezas[numSubcategoriasCervezas] = {    
    "Cervezas Nacionales","Cervezas Importadas","Cervezas Artesanales"
};

const int numSubcategoriasBebidas = 8;
const string subcategoriasBebidas[numSubcategoriasBebidas] = {  
    "Vinos y Espumantes","Whisky","Ron",
          "Pisco","Vodka","Tequila","Gin","Ready To Drink"
};

const int numSubcategoriasGaseosas = 5;
const string subcategoriasGaseosas[numSubcategoriasGaseosas] = {
    "Aguas","Energizantes y Rehidratantes","Gaseosas",
            "Ginger Ale",u8"Jugos y T�s Liquidos"
};

const int numSubcategoriasLimpieza = 12;
const string subcategoriasLimpieza[numSubcategoriasLimpieza] = {
            "Accesorios de Limpieza","Ambientadores","Bolsas y Envolturas",
            "Descartables","Detergente y Cuidado de la Ropa","Encendido de Parrilla",
            "Lavavajillas",u8"Lej�a","Limpiadores","Para Calzado",
            u8"Papeles Higi�nicos","Otros Papeles"
};

const int numSubcategoriasCuidado = 7;
const string subcategoriasCuidado[numSubcategoriasCuidado] = {  
            "Cuidado Capilar","Jabones","Higiene Bucal","Cuidado Mujer",
            "Cuidado Hombre","Incontinencia","Salud y Bienestar",
};

const int numSubcategoriasBelleza = 4;
const string subcategoriasBelleza[numSubcategoriasBelleza] = {
    "Cremas Faciales","Cuidado del Rostro",
          u8"Protecci�n Solar",u8"Perfumer�a"
};

const int numSubcategoriasBebes = 3;
const string subcategoriasBebes[numSubcategoriasBebes] = {
    u8"Pa�ales",u8"Aseo del Beb�",u8"Alimentos para Beb�s"
};

const int numSubcategoriasMascotas = 4;
const string subcategoriasMascotas[numSubcategoriasMascotas] = {
    "Perros","Gatos","Higiene","Accesorios",
};
// -------------------- TERCIARIAS POR SUBCATEGOR�A --------------------

// Abarrotes
const string terciariasArroz[] = { "Especial","Extra","Integral","Superior" };
const string terciariasConservas[] = { "Comidas Preparadas","Frutas","Pescados","Vegetales" };
const string terciariasAceite[] = { "Especial","Girasol","Oliva",u8"Org�nico","Vegetal y Soya" };
const string terciariasPasta[] = { "Pastas Cortas","Pastas Especiales","Pastas Largas","Pastas Rellenas" };
const string terciariasMenestras[] = { "Arvejas","Frijoles","Garbanzos","Lentejas","Otras Legumbres","Pallares","Pop Corn","Quinua" };
const string terciariasSal[] = { "Con Especias","De Cocina","De Maras","De Mesa","Parrilla" };
const string terciariasSalsasPasta[] = { "Salsa Pesto","Salsa Tomate","Otras Salsas" };
const string terciariasSalsasCremas[] = { u8"Aj� y Rocoto",u8"Ali�os y Vinagretas","BBQ",u8"Huanca�na","Ketchup","Mayonesa","Mostaza","Otras Salsas" };
const string terciariasCondimentos[] = { "Aderezos","Ajo Molido","Salsas Orientales","Sazonadores","Sillao","Tuco","Vinagre" };
const string terciariasEspecias[] = { "Ajo","Canela",u8"Oregano","Pimienta","Otras Especias" };
const string terciariasPure[] = { "Bases","Mezclas para Apanar",u8"Pur�s","Sopas" };
const string terciariasHarina[] = { "Especiales","Preparada","Sin Preparar" };

const int numTerciariasAbarrotes[numSubcategoriasAbarrotes] = {
    4,4,5,4,8,5,3,8,7,5,4,3
};
const string* terciariasAbarrotes[numSubcategoriasAbarrotes] = {
    terciariasArroz,terciariasConservas,terciariasAceite,terciariasPasta,terciariasMenestras,terciariasSal,
    terciariasSalsasPasta,terciariasSalsasCremas,terciariasCondimentos,terciariasEspecias,terciariasPure,terciariasHarina
};

// Desayunos
const string terciariasPan[] = { "Kekes, Turrones y King kongs",u8"Pan �rabe y Pita","Pan de Molde Blanco","Pan de Molde Integral","Pan Hamburguesa y Hot Dog",u8"Panet�n","Panqueques","Tostadas, Crissinies y Tortillas" };
const string terciariasAzucar[] = { u8"Az�car Blanca",u8"Az�car Rubia","Edulcorantes","Panela y Otros Endulzantes","Stevias" };
const string terciariasCafe[] = { u8"Caf� Instant�neo",u8"Caf� Molido y Grano",u8"C�psulas y Complemetos","Cebada","Hierbas",u8"T�, An�s y Manzanilla",u8"T�s Especiales y Saludables" };
const string terciariasCereales[] = { "Avena","Barras de Cereal",u8"Creales de Ma�z natural",u8"Cereales Diet�ticos","Cereales Infantiles","Granolas y Muslis","Quinua, Kiwicha y Otros" };
const string terciariasModificadores[] = { "Chocolate de Taza","Cocoas","Complentos y Suplementos","Modificadores de Leche","Superfoods" };
const string terciariasMermeladas[] = { "Algarrobina",u8"Mantequilla de Man�","Mermelada de Fresa","Mermelada de Sabores",u8"Mermelada Light y sin Az�car","Miel de Abeja","Siropes y Jaleas" };

const int numTerciariasDesayunos[numSubcategoriasDesayunos] = { 8,5,7,7,5,7 };
const string* terciariasDesayunos[numSubcategoriasDesayunos] = {
    terciariasPan,terciariasAzucar,terciariasCafe,terciariasCereales,terciariasModificadores,terciariasMermeladas
};

// Lacteos y Quesos
const string terciariasLeches[] = { "Crema de Leche","Leche Condensada","Leche en Bolsa","Leche en Polvo","Leche Entera","Leche Evaporada","Leche Fresca","Leche Light","Leche para Ni�os","Leche Saborizada","Leche sin Lactosa","Leche UHT","Leches Vegetales", u8"Mezclas L�cteas" };
const string terciariasYogurt[] = { "Yogurt Batido y Frutado","Yogurt Familiar","Yogurt Griego","Yogurt Light Familiar","Yogurt Mix","Yogurt Personal" };
const string terciariasQuesos[] = { "Cremas Untables","Queso Edam, Gouda y Danbo","Queso Andino y Paria","Queso Fresco y Mozzarella","Queso Parmesano" };
const string terciariasQuesosMundo[] = { u8"Espa�a","Francia","Italia","Suiza",u8"Pa�ses Bajos","Otros" };
const string terciariasMantequillas[] = { "Mantequillas","Margarinas" };

const int numTerciariasLacteos[numSubcategoriasLacteos] = { 14,6,5,6,2 };
const string* terciariasLacteos[numSubcategoriasLacteos] = {
    terciariasLeches,terciariasYogurt,terciariasQuesos,terciariasQuesosMundo,terciariasMantequillas
};

// Huevos y Fiambres
const string terciariasHuevo[] = {
    "Huevos de Codorniz","Huevos de Gallina"
};
const string terciariasJamones[] = {
    u8"Jam�n de Pavo y Pavita",u8"Jam�n del Pa�s y Ahumado",
                u8"Jam�n Pizzero e Ingl�s",u8"Pack Jam�n y Queso"
};
const string terciariasJamonadas[] = {
    "Jamonada de Cerdo","Jamonada de Pollo","Jamonada de Pavo y Pavita"
};
const string terciariasSalchichas[] = {
    "Cerdo","Pavo","Pollo","Frankfurter y Otras Salchichas"
};
const string terciariasChorizos[] = {
    "Especiales","Parrilleros"
};
const string terciariasFiambres[] = {
    u8"Espa�a","Italia"
};
const string terciariasOtrasFiambres[] = {
    "Morcillas",u8"Pat� y Mortadela","Tocino Cabanossi y Salame"
};
const string terciariasSalsas[] = {
    "Aceitunas y Encurtidos","Salsas","Cocktail"
};

const int numTerciariasHuevos[numSubcategoriasHuevos] = { 2,4,3,4,2,2,2,3 };
const string* terciariasHuevos[numSubcategoriasHuevos] = {
	terciariasHuevo,terciariasJamones,terciariasJamonadas,terciariasSalchichas,
	terciariasChorizos,terciariasFiambres,terciariasOtrasFiambres,terciariasSalsas
};

// Frutas y Verduras

const string terciariasFruta[] = {
    "Durazno, Melocotones y Ciruelas","Ensaladas Mixes y Frutas Picadas",
                u8"Ex�ticas y Tropicales",u8"Fresas, Ar�ndanos, Aguaymantos y Otros Berries",
                "Granadillas, Granadas, Tunas y Pitahayas",u8"Limones, Narajas,Mandarinas y Otros C�tricos",
                "Manzanas, Peras y Membrillos","Paltas y Frutas Nativas",u8"Pl�tanos, Papayas y Pi�as",
                u8"Sand�as, Melones y Mangos","Uvas"
};
const string terciariasVerdura[] = {
                u8"Apios, Esp�rragos y Otros Tallos","Arvejas, Vainitas, Habas y Otras Legumbres",
                u8"Br�coli, Col, Coliflor y Alcachofa",u8"Cebollas, Ajos y Aj�es",
                u8"Choclos y Ma�ces","Ensaladas y Verduras Picadas","Hongos, Setas y Germinados",
                "Insumos Orientales","Lechugas, Espinacas y Hierbas",
                u8"Papas, Camotes y Otros Tub�rculos","Tomates, Pimientos y Pepinos",
                u8"Zanahoria, Beterraga y Otras Ra�ces","Zapallos, Berenjenas y Caihuas"
};
const string terciariasOrganicos[] = {
    u8"Frutas Org�nicas",u8"Verduras Org�nicas"
};

const int numTerciariasFrutas[numSubcategoriasFrutas] = { 11,12,2 };
const string* terciariasFrutas[numSubcategoriasFrutas] = {
	terciariasFruta,terciariasVerdura,terciariasOrganicos
};

// Carnes
const string terciariasPollo[] = {
                "Cortes Congelados","Cortes Frescos","Cortes Light",
                "Elaborados","Entero","Menudencias","Pack Ahorradores"
};
const string terciariasRes[] = {
	"Argentina","Black","Cortes Caseros Nacionales",
				"Cortes Parrilleros Nacional","Elaborados y Menudencias",
				"Molidas","Porterhouse Angus Choice","Uruguaya","USA Angus Choice"
};
const string terciariasCerdo[] = {
    "Cerdo Duroc","Cortes Caseros","Cortes Parrilleros","Elaborados"
};
const string terciariasPavo[] = {
    "Cortes Caseros","Elaborados","Entero"
};
const string terciariasCarnesRegionales[] = {
	"Cabrito","Conejo","Gallina","Pato"
};

const int numTerciariasCarnes[numSubcategoriasCarnes] = { 7,8,4,3,5 };
const string* terciariasCarnes[numSubcategoriasCarnes] = {
	terciariasPollo,terciariasRes,terciariasCerdo,terciariasPavo,terciariasCarnesRegionales
};

// Pescados y Mariscos
const string terciariasPescadosCongelados[] = {
    "Ahumados","Empanizados","Enteros",
                "Filetes y Porciones","Otros"
};
const string terciariasMariscosCongelados[] = {
    "Calamares","Conchas","Langostinos","Mixtura"
};
const string terciariasFrescos[] = {
    "Entero","Filete"
};

const int numTerciariasPescados[numSubcategoriasPescados] = { 5,4,2 };
const string* terciariasPescados[numSubcategoriasPescados] = {
	terciariasPescadosCongelados,terciariasMariscosCongelados,terciariasFrescos
};

// Congelados
const string terciariasHamburguesas[] = {
    "Parrilleras","Regulares","Saludables"
};
const string terciariasNuggets[] = {
    "Nuggets","Empanizados"
};
const string terciariasFrutasCongeladas[] = {
    "Frutas Congeladas","Verduras Congeladas"
};
const string terciariasHelados[] = {
    "Bandejas Familiares","Helados Importados",
                "Paletas y Postres","Potes"
};
const string terciariasPizzas[] = {
    "Pizzas","Pastas","Bocaditos"
};

const int numTerciariasCongelados[numSubcategoriasCongelados] = { 3,2,2,4,3 };
const string* terciariasCongelados[numSubcategoriasCongelados] = {
	terciariasHamburguesas,terciariasNuggets,terciariasFrutasCongeladas,
	terciariasHelados,terciariasPizzas
};

// Panaderia y Pasteleria
const string terciariasPanes[] = {
    "Franceses y Tradicionales","Gourmet"
};
const string terciariasKekes[] = {
	"Kekes","Chifones"
};
const string terciariasTostadas[] = {
	"Tostadas","Bocaditos"
};
const string terciariasPostres[] = {
    "Postres","Tortas de Chocolate, Fudge y Manjar",
                "Tortas Tres Leches","Otras Tortas"
};

const int numTerciariasPanaderia[numSubcategoriasPanaderia] = { 2,8,2,4 };
const string* terciariasPanaderia[numSubcategoriasPanaderia] = {
	terciariasPanes,terciariasKekes,terciariasTostadas,terciariasPostres
};

// Dulces y Galletas
const string terciariasGalletas[] = {
    u8"Ba�adas","Integrales, Arroz y Saludables","Rellenas",
                "Saborizadas","Soda y Saladas","Wafers e Importadas"
};
const string terciariasCaramelos[] = {
	"Caramelos","Chupetes"
};
const string terciariasChocolates[] = {
    u8"Ba�ados y Lentejas","Barras y Tabletas","Bombones y Pastillas"
};
const string terciariasMarshmallows[] = {
    "Marshmallows","Chicles","Gomitas"
};

const int numTerciariasDulces[numSubcategoriasDulces] = { 6,2,3,2 };
const string* terciariasDulces[numSubcategoriasDulces] = {
	terciariasGalletas,terciariasCaramelos,terciariasChocolates,terciariasMarshmallows
};

// Snack y Frutos Secos
const string terciariasFrutosSecos[] = {
              "Almendras",u8"Ma�z, Pistachos y Habas",u8"Man�","Mixes",
              u8"Pasas, Guindones, Damascos, Albaricoques y D�tiles","Pecanas y Cashews",
};
const string terciariasSnacks[] = {
	"Camotes y Chifles","Cancha Chullpi","Chizitos y Chicharrones",
              "Mix","Papitas y Yucas","Popcorn","Saludables",u8"Tortillas de Ma�z"
};

const int numTerciariasSnack[numSubcategoriasSnack] = { 6,8 };
const string* terciariasSnack[numSubcategoriasSnack] = {
	terciariasFrutosSecos,terciariasSnacks
};

// Cervezas
const string terciariasCervezasNacionales[] = {
    u8"Cusque�a","Cristal","Pilsen","Tres Cruces"
};
const string terciariasCervezasImportadas[] = {
    "Amstel","Budweiser","Corona","Estrella Damm",
              "Heineken","Scolta","Stella Artois"
};
const string terciariasCervezasArtesanales[] = {
                  "Barbarian","Candelaria","Erdinger",
              "Paulaner", "Sierra Andina", "7 Vidas"
};

const int numTerciariasCervezas[numSubcategoriasCervezas] = { 4,7,6 };
const string* terciariasCervezas[numSubcategoriasCervezas] = {
	terciariasCervezasNacionales,terciariasCervezasImportadas,terciariasCervezasArtesanales
};

// Bebidas Alcoholicas
const string terciariasVinos[] = {
    "Espumante y Cava","Sangria","Vino Blanco",
              "Vino Dulce","Vino Rose","Vino Tinto"
};
const string terciariasWhisky[] = {
    "Ballantines","Chivas Regal","Johnnie Walker","Old Parr"
};
const string terciariasRon[] = {
    "Appleton Estate","Bacardi","Barcelo","Cartavio",u8"Flor de Ca�a"
};
const string terciariasPisco[] = {
    "Cuatro Gallos","Porton",
              "Santiago Queirolo","Taberna","Vargas"
};
const string terciariasVodka[] = {
	"Absolut","Grey Goose",
              "Russkaya","Skyy","Smirnoff"
};
const string terciariasTequila[] = {
    "Don Julio","Espolon","Jimador",
              "Jose Cuervo","Olmeca","1800"
};
const string terciariasGin[] = {
    "Beefeater","Bombay","Bulldog","Gordon's",
              "Hendrick's","GIN MG","Tanqueray"
};
const string terciariasReady[] = {
    "Cartavio Hit","Four Loko","Mikes",
              "Piscano","Russkaya","Smirnoff",
};

const int numTerciariasBebidas[numSubcategoriasBebidas] = { 7,6,6,5,6,6,6,6 };
const string* terciariasBebidas[numSubcategoriasBebidas] = {
	terciariasVinos,terciariasWhisky,terciariasRon,terciariasPisco,
	terciariasVodka,terciariasTequila,terciariasGin,terciariasReady
};

// Gaseosas, Aguas y Jugos
const string terciariasAguas[] = {
    "Agua con Gas","Agua Saborizada","Agua sin Gas"
};
const string terciariasEnergizantes[] = {
    "Energizantes","Rehidratantes"
};
const string terciariasGaseosa[] = {
    "Coca Cola","Fanta","Fresh",u8"Guaran�",
                "Inca Kola","Pepsi","Seven Up","Sprite"
};
const string terciariasGinger[] = {
    "Britvic","Canada Dry","Evervess","Schweppes"
};
const string terciariasJugos[] = {
    "Aloe Vera","Jugos en Polvo","Jugos Naturales",
                "Jugos y Otras Bebidas",u8"T�s L�quidos"
};

const int numTerciariasGaseosas[numSubcategoriasGaseosas] = { 3,2,8,4,8 };
const string* terciariasGaseosas[numSubcategoriasGaseosas] = {
	terciariasAguas,terciariasEnergizantes,terciariasGaseosa,
	terciariasGinger,terciariasJugos
};

// Limpieza
const string terciariasAccesorios[] = {
    "Desatorador","Escobas","Escobillas","Esponjas","Guantes",
                "Mopas",u8"Pa�os","Pa�os","Recogedores","Trapeadores",
};
const string terciariasAmbientadores[] = {
    "Aerosol","Deshumedecedores",u8"El�ctricos"
};
const string terciariasBolsas[] = {
    "Bolsas para Alimentos","Bolsas para Basura",
                "Papel Aluminio",u8"Pl�sticos y Bandejas"
};
const string terciariasDescartables[] = {
    "Cubiertos","Mondadientes","Palitos","Platos","Vasos"
};
const string terciariasDetergente[] = {
    "Cloro","Detergente en Polvo",u8"Detergente L�quido",
                "Jabones","Quitamanchas","Suavizantes"
};
const string terciariasEncendido[] = {
    u8"Carb�n y Le�a",u8"F�sforos"
};
const string terciariasLavavajillas[] = {
    "Especializados","En pasta ",u8"L�quidos"
};
const string terciariasLejia[] = {
    "Aromas","Tradicional"
};
const string terciariasLimpiadores[] = {
    "Alfombras",u8"Ba�o","Ceras","Cocina","Desinfectantes",
                "Limpia Vidrios y Multiusos","Limpiatodo","Lustramuebles",
                "Metales","Toallitas Desinfecantes"
};
const string terciariasCalzado[] = {
    "Accesorios de Calzado",u8"Bet�n",
};
const string terciariasPapeles[] = {
    "Doble Hoja","Simple","Triple Hoja"
};
const string terciariasOtrosPapeles[] = {
    "Papel Toalla",u8"Pa�uelos Desechables","Servilletas"
};

const int numTerciariasLimpieza[numSubcategoriasLimpieza] = { 10,3,4,5,6,2,3,2,9,2,2 };
const string* terciariasLimpieza[numSubcategoriasLimpieza] = {
	terciariasAccesorios,terciariasAmbientadores,terciariasBolsas,
	terciariasDescartables,terciariasDetergente,terciariasEncendido,
	terciariasLavavajillas,terciariasLejia,terciariasLimpiadores,
	terciariasCalzado,terciariasPapeles,terciariasOtrosPapeles
};

// Cuidado Personal
const string terciariasCuidadoCapilar[] = {
    "Acondicionador",u8"Coloraci�n","Cremas para Peinar",
                "Fijadores de Cabello","Shampoo","Tratamiento Capilar"
};
const string terciariasJabones[] = {
    "Gel de Ducha",u8"Jab�n Antibacterial",u8"Jab�n de Glicerina",
              u8"Jab�n en Barra",u8"L�quido Antibacterial"
};
const string terciariasHigiene[] = {
    u8"Cepillos El�ctricos","Cepillos Regulares",
                "Cremas Dentales","Enjuague Bucal","Hilo Dental"
};
const string terciariasCuidadoMujer[] = {
    u8"Depilaci�n Femenina","Desodorantes Aerosol", "Desodorantes en Barra","Desodorantes Roll-On",
                u8"Higiene �ntima","Protectores Diarios",u8"Toallitas Higi�nicas y Tampones"
};
const string terciariasCuidadoHombre[] = {
    u8"Desodorantes Aerosol","Desodorantes en Barra",
                u8"Desodorantes Roll-On","Espumas de Afeitar",
                u8"M�quinas de Afeitary Repuestos"
};
const string terciariasIncontinencia[] = {
    "Incontinencia Leve","u8Pa�ales para Adulto",
                "Protectores de Cama","Ropa Interior Desechable"
};
const string terciariasSalud[] = {
    u8"Alcohol y Antis�pticos","Algodones e Hisopos",
                "Bienestar Sexual", u8"Botiqu�n","Curitas y Banditas",
                "Repelentes", "Talcos y Desodorantes para Pies","Vitaminas"
};

const int numTerciariasCuidado[numSubcategoriasCuidado] = { 6,5,5,7,5,4,8 };
const string* terciariasCuidado[numSubcategoriasCuidado] = {
	terciariasCuidadoCapilar,terciariasJabones,terciariasHigiene,
	terciariasCuidadoMujer,terciariasCuidadoHombre,terciariasIncontinencia,
	terciariasSalud
};

// Belleza
const string terciariasCremas[] = {
    u8"�cido Hialur�nico","Aclaradores","Antiedad",
              "Antimanchas","Hidratantes",u8"S�rum Facial"
};
const string terciariasCuidadoRostro[] = {
    u8"Aguas Micelares y T�nicos","Desmaquillantes","Exfoliantes",
              "Limpieza Facial","Mascarillas","Toallitas Desmaquillantes"
};
const string terciariasProteccion[] = {
    "Bloqueadores","Bronceadores"
};
const string terciariasPerfumeria[] = {
    "Aromaterapia","Colonias","Perfumes"
};

const int numTerciariasBelleza[numSubcategoriasBelleza] = { 6,6,2,4 };
const string* terciariasBelleza[numSubcategoriasBelleza] = {
	terciariasCremas,terciariasCuidadoRostro,terciariasProteccion,
	terciariasPerfumeria
};

// Bebes y Ni�os
const string terciariasPa�ales[] = {
    "Babysec","Bambo Nature","Huggies",
                "Mimi","Pampers","Tottus"
};
const string terciariasAseo[] = {
    "Aceites e Hisopos","Cepillos Dentales","Colonias",
              "Cremas Dentales","Cremas y Lociones","Cuidado del Cabello",
              "Jabones","Talcos",u8"Toallitas H�medas"
};
const string terciariasAlimentos[] = {
    "Biberones","Cereales y Galletas","Colados",u8"F�rmulas y L�cteas"
};

const int numTerciariasBebes[numSubcategoriasBebes] = { 6,9,4 };
const string* terciariasBebes[numSubcategoriasBebes] = {
	terciariasPa�ales,terciariasAseo,terciariasAlimentos
};

// Mundo Mascotas
const string terciariasPerros[] = {
    "Alimento Seco",u8"Alimento H�medo","Snacks"
};
const string terciariasGatos[] = {
	"Alimento Seco",u8"Alimento H�medo","Snacks"
};
const string terciariasHigieneMascota[] = {
    "Cuidado para Mascotas","Shampoo",u8"Toallas H�medas"
};
const string terciariasAccesoriosMascota[] = {
    u8"Arn�s","Collares","Huesos","Juguetes",
              "Pelotas","Platos","Sogas"
};

const int numTerciariasMascotas[numSubcategoriasMascotas] = { 3,3,3,7 };
const string* terciariasMascotas[numSubcategoriasMascotas] = {
	terciariasPerros,terciariasGatos,terciariasHigieneMascota,
	terciariasAccesoriosMascota
};

// -------------------- ARREGLOS GENERALES PARA ACCESO DIN�MICO --------------------
const string* subcategoriasPorCategoria[numCategoriasPrincipales] = {
    subcategoriasAbarrotes,
    subcategoriasDesayunos,
    subcategoriasLacteos,
    subcategoriasHuevos,
    subcategoriasFrutas,
    subcategoriasCarnes,
    subcategoriasPescados,
    subcategoriasCongelados,
    subcategoriasPanaderia,
    subcategoriasDulces,
    subcategoriasSnack,
    subcategoriasCervezas,
    subcategoriasBebidas,
    subcategoriasGaseosas,
    subcategoriasLimpieza,
    subcategoriasCuidado,
    subcategoriasBelleza,
    subcategoriasBebes,
    subcategoriasMascotas
};

const int numSubcategoriasPorCategoria[numCategoriasPrincipales] = {
    numSubcategoriasAbarrotes,
    numSubcategoriasDesayunos,
    numSubcategoriasLacteos,
	numSubcategoriasHuevos,
	numSubcategoriasFrutas,
	numSubcategoriasCarnes,
	numSubcategoriasPescados,
	numSubcategoriasCongelados,
	numSubcategoriasPanaderia,
	numSubcategoriasDulces, 
	numSubcategoriasSnack,
	numSubcategoriasCervezas,   
	numSubcategoriasBebidas,
	numSubcategoriasGaseosas,
	numSubcategoriasLimpieza,
	numSubcategoriasCuidado,
	numSubcategoriasBelleza,    
	numSubcategoriasBebes,
	numSubcategoriasMascotas
};

const string** terciariasPorSubcategoria[numCategoriasPrincipales] = {
    terciariasAbarrotes,
    terciariasDesayunos,
    terciariasLacteos,
	terciariasHuevos,
	terciariasFrutas,
	terciariasCarnes,
	terciariasPescados,
	terciariasCongelados,
	terciariasPanaderia,
	terciariasDulces,
	terciariasSnack,
	terciariasCervezas,
	terciariasBebidas,
	terciariasGaseosas,
	terciariasLimpieza,
	terciariasCuidado,
	terciariasBelleza,
	terciariasBebes,
	terciariasMascotas
};

const int* numTerciariasPorSubcategoria[numCategoriasPrincipales] = {
    numTerciariasAbarrotes,
    numTerciariasDesayunos,
    numTerciariasLacteos,
	numTerciariasHuevos,
	numTerciariasFrutas,
	numTerciariasCarnes,
	numTerciariasPescados,
	numTerciariasCongelados,
	numTerciariasPanaderia,
	numTerciariasDulces,
	numTerciariasSnack,
	numTerciariasCervezas,
	numTerciariasBebidas,
	numTerciariasGaseosas,
	numTerciariasLimpieza,
	numTerciariasCuidado,
	numTerciariasBelleza,
	numTerciariasBebes,
	numTerciariasMascotas
};