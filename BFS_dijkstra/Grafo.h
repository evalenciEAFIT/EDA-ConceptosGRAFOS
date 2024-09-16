#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Nodo.h"
#include "HashTable.h"

// Clase Grafo: Representa el grafo completo
class Grafo {
private:
    std::vector<Nodo*> nodos;  // Almacena todos los nodos del grafo
    HashTable tablaHash;  // Tabla hash para búsqueda rápida de nodos

public:
    Grafo();
    ~Grafo();

    void agregarNodo(const Data& dato);
    void agregarArista(const std::string& origen, const std::string& destino, int peso = 1);
    void imprimirGrafo() const;
    void bfs(const std::string& inicio) const;
    void dijkstra(const std::string& inicio, const std::string& fin) const;
};

#endif // GRAFO_H