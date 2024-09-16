#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <string>
#include "Nodo.h"

// Clase HashTable: Implementa una tabla hash para búsqueda eficiente de nodos
class HashTable {
private:
    std::vector<std::list<Nodo*>> tabla;  // Vector de listas para manejar colisiones
    int tamanio;  // Tamaño de la tabla hash

    // Función hash: Calcula el índice para una clave dada
    // Parámetro clave: String para el cual se calcula el hash
    // Retorna: Índice calculado
    int hash(const std::string& clave) const;

public:
    // Constructor: Inicializa la tabla hash con un tamaño dado
    // Parámetro tam: Tamaño inicial de la tabla hash
    explicit HashTable(int tam);

    // Inserta un nodo en la tabla hash
    // Parámetro nodo: Puntero al nodo a insertar
    void insertar(Nodo* nodo);

    // Busca un nodo por su clave (valor)
    // Parámetro clave: Valor a buscar
    // Retorna: Puntero al nodo si se encuentra, nullptr si no
    Nodo* buscar(const std::string& clave) const;
};

#endif // HASHTABLE_H