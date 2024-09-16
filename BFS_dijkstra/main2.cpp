#include "Grafo.h"
#include <iostream>

void imprimirRuta(const std::string& inicio, const std::string& fin, const Grafo& grafo) {
    std::cout << "\nRuta más corta de " << inicio << " a " << fin << ":" << std::endl;
    grafo.dijkstra(inicio, fin);
}

int main() {
    Grafo europa;

    // Agregar ciudades como nodos
    europa.agregarNodo(Data("Madrid"));
    europa.agregarNodo(Data("Paris"));
    europa.agregarNodo(Data("Roma"));
    europa.agregarNodo(Data("Berlin"));
    europa.agregarNodo(Data("Londres"));
    europa.agregarNodo(Data("Amsterdam"));

    // Agregar conexiones entre ciudades (distancias aproximadas en km)
    europa.agregarArista("Madrid", "Paris", 1054);
    europa.agregarArista("Madrid", "Roma", 1364);
    europa.agregarArista("Paris", "Londres", 344);
    europa.agregarArista("Paris", "Berlin", 878);
    europa.agregarArista("Roma", "Berlin", 1181);
    europa.agregarArista("Londres", "Amsterdam", 358);
    europa.agregarArista("Amsterdam", "Berlin", 577);

    std::cout << "Mapa de conexiones entre ciudades europeas:" << std::endl;
    europa.imprimirGrafo();

    std::cout << "\nEjemplos de rutas más cortas:" << std::endl;
    imprimirRuta("Madrid", "Berlin", europa);
    imprimirRuta("Londres", "Roma", europa);
    imprimirRuta("Amsterdam", "Madrid", europa);

    return 0;
}