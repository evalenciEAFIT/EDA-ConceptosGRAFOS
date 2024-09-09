#ifndef GRAFO_LISTA_ADYACENCIA_H
#define GRAFO_LISTA_ADYACENCIA_H

#include <vector>
#include <list>
#include <unordered_map>
#include "Ciudad.h"
#include "Data.h"

// Implementación de un grafo utilizando listas de adyacencia
class Grafo_listaAdyacencia {
private:
    // Estructura para representar una arista en la lista de adyacencia
    struct Arista {
        int destino;
        Data data;
        Arista(int d, const Data& dat) : destino(d), data(dat) {}
    };

    std::vector<Ciudad> ciudades;                        // Vector de ciudades
    std::vector<std::list<Arista>> listaAdyacencia;      // Lista de adyacencia
    std::unordered_map<std::string, int> nombreACiudadId;// Mapa de nombres de ciudades a sus IDs

public:
    // Constructor
    Grafo_listaAdyacencia();

    // Métodos para agregar ciudades y vuelos
    void agregarCiudad(const std::string& nombre, const std::string& pais, bool tieneAeropuerto);
    void agregarVuelo(const std::string& origen, const std::string& destino, int distancia, int duracion);

    // Métodos para imprimir y recorrer el grafo
    void imprimirRedVuelos() const;
    void BFS(const std::string& inicioCiudad) const;
};

#endif // GRAFO_LISTA_ADYACENCIA_H