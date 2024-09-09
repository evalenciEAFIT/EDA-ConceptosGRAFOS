#ifndef GRAFO_MATRIZ_ADYACENCIA_H
#define GRAFO_MATRIZ_ADYACENCIA_H

#include <vector>
#include <unordered_map>
#include "Ciudad.h"
#include "Data.h"

// Implementación de un grafo utilizando una matriz de adyacencia
class Grafo_matrizAdyacencia {
private:
    std::vector<Ciudad> ciudades;                        // Vector de ciudades
    std::vector<std::vector<Data*>> matrizAdyacencia;    // Matriz de adyacencia
    std::unordered_map<std::string, int> nombreACiudadId;// Mapa de nombres de ciudades a sus IDs

public:
    // Constructor y destructor
    Grafo_matrizAdyacencia();
    ~Grafo_matrizAdyacencia();

    // Métodos para agregar ciudades y vuelos
    void agregarCiudad(const std::string& nombre, const std::string& pais, bool tieneAeropuerto);
    void agregarVuelo(const std::string& origen, const std::string& destino, int distancia, int duracion);

    // Métodos para imprimir y recorrer el grafo
    void imprimirRedVuelos() const;
    void BFS(const std::string& inicioCiudad) const;
};

#endif // GRAFO_MATRIZ_ADYACENCIA_H