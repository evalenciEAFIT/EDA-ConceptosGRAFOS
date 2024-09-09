#include <iostream>
#include "Grafo_matrizAdyacencia.h"
#include "Grafo_listaAdyacencia.h"

// Función para probar la implementación de matriz de adyacencia
void probarMatrizAdyacencia() {
    std::cout << "Probando implementación con Matriz de Adyacencia:" << std::endl;
    Grafo_matrizAdyacencia grafoMA;

    // Agregar ciudades
    grafoMA.agregarCiudad("Madrid", "España", true);
    grafoMA.agregarCiudad("París", "Francia", true);
    grafoMA.agregarCiudad("Londres", "Reino Unido", true);
    grafoMA.agregarCiudad("Berlín", "Alemania", true);
    grafoMA.agregarCiudad("Roma", "Italia", true);

    // Agregar vuelos
    try {
        grafoMA.agregarVuelo("Madrid", "París", 1054, 125);
        grafoMA.agregarVuelo("Madrid", "Londres", 1264, 145);
        grafoMA.agregarVuelo("París", "Berlín", 876, 110);
        grafoMA.agregarVuelo("Londres", "Berlín", 932, 115);
        grafoMA.agregarVuelo("Berlín", "Roma", 1181, 135);
    } catch (const std::exception& e) {
        std::cout << "Error al agregar vuelo: " << e.what() << std::endl;
    }

    // Imprimir red de vuelos y realizar BFS
    grafoMA.imprimirRedVuelos();
    std::cout << "Recorrido BFS desde Madrid:" << std::endl;
    grafoMA.BFS("Madrid");
}

// Función para probar la implementación de lista de adyacencia
void probarListaAdyacencia() {
    std::cout << "\nProbando implementación con Lista de Adyacencia:" << std::endl;
    Grafo_listaAdyacencia grafoLA;

    // Agregar ciudades
    grafoLA.agregarCiudad("New York", "Estados Unidos", true);
    grafoLA.agregarCiudad("Toronto", "Canadá", true);
    grafoLA.agregarCiudad("México City", "México", true);
    grafoLA.agregarCiudad("Bogotá", "Colombia", true);
    grafoLA.agregarCiudad("Sao Paulo", "Brasil", true);

    // Agregar vuelos
    try {
        grafoLA.agregarVuelo("New York", "Toronto", 551, 90);
        grafoLA.agregarVuelo("New York", "México City", 3364, 315);
        grafoLA.agregarVuelo("Toronto", "Bogotá", 4000, 360);
        grafoLA.agregarVuelo("México City", "Bogotá", 3158, 270);
        grafoLA.agregarVuelo("Bogotá", "Sao Paulo", 4155, 390);
    } catch (const std::exception& e) {
        std::cout << "Error al agregar vuelo: " << e.what() << std::endl;
    }

    // Imprimir red de vuelos y realizar BFS
    grafoLA.imprimirRedVuelos();
    std::cout << "Recorrido BFS desde New York:" << std::endl;
    grafoLA.BFS("New York");
}

int main() {
    probarMatrizAdyacencia();
    probarListaAdyacencia();
    return 0;
}