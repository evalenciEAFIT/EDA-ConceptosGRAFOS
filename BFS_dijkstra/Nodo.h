#ifndef NODO_H
#define NODO_H

#include <unordered_map>
#include "Data.h"

// Clase Nodo: Representa un vértice en el grafo
class Nodo {
private:
    Data dato;  // Información asociada al nodo
    std::unordered_map<Nodo*, int> aristas;  // Mapa de aristas: Nodo destino -> peso

public:
    // Constructor: Crea un nodo con un valor dado
    explicit Nodo(const Data& valor);

    // Obtiene el dato almacenado en el nodo
    // Retorna: Referencia constante al objeto Data del nodo
    const Data& obtenerDato() const;

    // Agrega una arista del nodo actual a otro nodo
    // Parámetro destino: Puntero al nodo destino
    // Parámetro peso: Peso de la arista
    void agregarArista(Nodo* destino, int peso);

    // Obtiene todas las aristas del nodo
    // Retorna: Mapa de aristas (nodo destino -> peso)
    const std::unordered_map<Nodo*, int>& obtenerAristas() const;
};

#endif // NODO_H