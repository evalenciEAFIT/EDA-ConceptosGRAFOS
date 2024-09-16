#include "Nodo.h"

// Constructor: Crea un nodo con un valor dado
Nodo::Nodo(const Data& valor) : dato(valor) {}

// Obtiene el dato almacenado en el nodo
const Data& Nodo::obtenerDato() const {
    return dato;
}

// Agrega una arista del nodo actual a otro nodo
void Nodo::agregarArista(Nodo* destino, int peso) {
    aristas[destino] = peso;
}

// Obtiene todas las aristas del nodo
const std::unordered_map<Nodo*, int>& Nodo::obtenerAristas() const {
    return aristas;
}