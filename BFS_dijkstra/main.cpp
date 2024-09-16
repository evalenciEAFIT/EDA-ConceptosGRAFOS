#include "Grafo.h"
#include <iostream>

int main() {
    Grafo grafo;

    // Agregar nodos
    grafo.agregarNodo(Data("A"));
    grafo.agregarNodo(Data("B"));
    grafo.agregarNodo(Data("C"));
    grafo.agregarNodo(Data("D"));
    grafo.agregarNodo(Data("E"));

    // Agregar aristas
    grafo.agregarArista("A", "B", 4);
    grafo.agregarArista("A", "C", 2);
    grafo.agregarArista("B", "D", 3);
    grafo.agregarArista("C", "D", 1);
    grafo.agregarArista("D", "E", 5);

    std::cout << "Estructura del grafo:" << std::endl;
    grafo.imprimirGrafo();

    std::cout << "\nRecorrido BFS desde A: ";
    grafo.bfs("A");

    std::cout << "\nRuta más corta de A a E:" << std::endl;
    grafo.dijkstra("A", "E");

    return 0;
}