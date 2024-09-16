#include "HashTable.h"

// Constructor: Inicializa la tabla hash con un tamaño dado
HashTable::HashTable(int tam) : tabla(tam), tamanio(tam) {}

// Función hash: Calcula el índice para una clave dada
int HashTable::hash(const std::string& clave) const {
    int suma = 0;
    for (char c : clave) {
        suma += c;
    }
    return suma % tamanio;
}

// Inserta un nodo en la tabla hash
void HashTable::insertar(Nodo* nodo) {
    int indice = hash(nodo->obtenerDato().obtenerValor());
    tabla[indice].push_back(nodo);
}

// Busca un nodo por su clave (valor)
Nodo* HashTable::buscar(const std::string& clave) const {
    int indice = hash(clave);
    for (Nodo* nodo : tabla[indice]) {
        if (nodo->obtenerDato().obtenerValor() == clave) {
            return nodo;
        }
    }
    return nullptr;
}