# TOTTUS (Trabajo Final UPC) (C++)

<p align="center"><img src="https://i.ibb.co/HfxbYkyV/Logo-Tottus.png"</b><br>Software desarrollado en lenguaje C++, con el Visual Studio.</p>

---

## ***Introducción***

Este proyecto es un sistema de gestión de supermercados para Tottus, desarrollado como parte del trabajo final del curso de Algoritmos y Estructuras de Datos. La aplicación simula las operaciones de un supermercado, permitiendo la gestión de productos, clientes, administradores y ventas. El sistema está diseñado para ser robusto, eficiente y fácil de usar, con una interfaz de consola que guía al usuario a través de las diferentes funcionalidades.
> NOTA: NO todas las funcionalidades de la pagina web se encuentran implementadas.

## ***Instrucciones***
1. Clona el repositorio o descarga los archivos del proyecto en tu máquina local.
2. Abre el proyecto con Visual Studio.
3. Asegúrate de que todos los archivos de cabecera (.h) y los archivos de código fuente (.cpp) estén en la misma carpeta para que el compilador pueda encontrarlos.
4. Asegúrate de que los archivos de datos (.txt) se encuentren en la misma carpeta que el ejecutable, ya que el programa los lee para cargar la información inicial.
5. Compila y ejecuta el archivo Tottus.cpp desde Visual Studio.

## ***Especificaciones***

El sistema está desarrollado en C++ y utiliza diversas estructuras de datos para gestionar la información de manera eficiente.

***Estructuras de Datos Implementadas***

- Listas Enlazadas: Se utilizan para almacenar los productos dentro de cada categoría, así como los productos seleccionados en el carrito de compras.
- Árboles Binarios de Búsqueda: Para indexar y buscar productos por diferentes criterios como ID, nombre y precio, lo que permite búsquedas eficientes.
- Árboles AVL: Utilizados para la gestión de usuarios, garantizando búsquedas, inserciones y eliminaciones en tiempo logarítmico, manteniendo el árbol balanceado.
- Tablas Hash: Implementada para almacenar y buscar boletas por el DNI del cliente, lo que permite un acceso rápido a las transacciones de un usuario específico.
- Pilas: Usadas en el módulo de soporte para gestionar los tickets de los clientes, siguiendo una estructura LIFO (Last-In, First-Out).
- Colas: Para la gestión de pedidos pendientes, asegurando que se procesen en el orden en que fueron recibidos (FIFO - First-In, First-Out).
- Grafos: Se utilizan para modelar la red de tiendas y las relaciones entre proveedores, permitiendo visualizar conexiones y distancias.

***Funcionalidades Principales***

El sistema se divide en dos módulos principales: Administrador y Usuario.

****Módulo de Administrador****

- Gestión de Productos:

Agregar, modificar y eliminar productos del catálogo.
Buscar productos por ID, nombre o precio.
Listar todos los productos por categorías.

- Gestión de Cuentas de Usuario:

Listar y buscar usuarios registrados.

- Gestión de Promociones:

Ver y aplicar promociones a los productos de forma aleatoria.

- Generación de Reportes:

Reporte de inventario, mostrando productos con bajo stock.
Reporte de los productos más vendidos.
Reporte de ventas del día.

- Gestión de Boletas:

Búsqueda avanzada de boletas por número, DNI del cliente, y más.

Listar las últimas boletas generadas.

Gestionar y procesar pedidos pendientes de la cola.

Soporte al Cliente:

Visualizar y gestionar tickets de soporte enviados por los usuarios.

****Módulo de Usuario****

- Navegación y Compra:

Ver el catálogo de productos por categorías.
Buscar productos para una compra más rápida.
Ver promociones vigentes y agregar productos al carrito.

- Carrito de Compras:

Modificar la cantidad de productos en el carrito.
Eliminar productos del carrito.
Vaciar el carrito por completo.
Proceder al pago para finalizar la compra.

- Registro y Gestión de Cuenta:

Registrarse como nuevo usuario en el sistema.
Ver el historial de boletas generadas.

- Soporte:

Enviar solicitudes de soporte (reclamos, consultas, etc.).
Consultar el estado de las solicitudes enviadas.
Acceder a una sección de preguntas frecuentes (FAQ).
Visualizar la distancia entre las diferentes tiendas Tottus a través de un mapa de grafos.

## ***Views***

### *Logo Universidad*
<p align="center"><img src="https://i.ibb.co/8LLKJzYt/Captura-de-pantalla-486.png"></p>

### *Menu Principal*
<p align="center"><img src="https://i.ibb.co/mVY4zsf1/Menu-Principal.png"></p>

### *Panel de Administrador*
<p align="center"><img src="https://i.ibb.co/Qvwcrptz/Panel-Admin.png"></p>

### *Panel de Usuario*
<p align="center"><img src="https://i.ibb.co/yKv8J9g/Panel-Usuario.png"></p>

<p align="center"><img src="https://i.ibb.co/yBpn50cj/Panel-Usuario2.png"></p>

## ***Canvas***

https://www.canva.com/design/DAGsRBgcmGM/MKcDXjCf4kqTZjquvGBZZA/edit?utm_content=DAGsRBgcmGM&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
