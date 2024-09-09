#include "Grafo_listaAdyacencia.h"
#include <iostream>
#include <queue>
#include <stdexcept>

Grafo_listaAdyacencia::Grafo_listaAdyacencia() {}

void Grafo_listaAdyacencia::agregarCiudad(const std::string& nombre, const std::string& pais, bool tieneAeropuerto) {
    // Agregar nueva ciudad al vector y al mapa
    int id = ciudades.size();
    ciudades.emplace_back(id, nombre, pais, tieneAeropuerto);
    nombreACiudadId[nombre] = id;
    listaAdyacencia.emplace_back();
}

void Grafo_listaAdyacencia::agregarVuelo(const std::string& origen, const std::string& destino, int distancia, int duracion) {
    // Verificar existencia de ciudades y validar reglas de vuelo
    auto itOrigen = nombreACiudadId.find(origen);
    auto itDestino = nombreACiudadId.find(destino);
    
    if (itOrigen == nombreACiudadId.end() || itDestino == nombreACiudadId.end()) {
        throw std::runtime_error("Ciudad no encontrada");
    }

    int idOrigen = itOrigen->second;
    int idDestino = itDestino->second;

    const Ciudad& ciudadOrigen = ciudades[idOrigen];
    const Ciudad& ciudadDestino = ciudades[idDestino];

    if (!ciudadOrigen.getTieneAeropuerto() || !ciudadDestino.getTieneAeropuerto()) {
        throw std::runtime_error("Una de las ciudades no tiene aeropuerto");
    }

    if (ciudadOrigen.getPais() == ciudadDestino.getPais()) {
        throw std::runtime_error("No se permiten vuelos entre ciudades del mismo país");
    }

    // Agregar vuelo a la lista de adyacencia
    listaAdyacencia[idOrigen].emplace_back(idDestino, Data(distancia, duracion));
    listaAdyacencia[idDestino].emplace_back(idOrigen, Data(distancia, duracion)); // Para grafo no dirigido
}

void Grafo_listaAdyacencia::imprimirRedVuelos() const {
    // Imprimir información de vuelos para cada ciudad con aeropuerto
    for (size_t i = 0; i < ciudades.size(); ++i) {
        const Ciudad& ciudad = ciudades[i];
        if (ciudad.getTieneAeropuerto()) {
            std::cout << ciudad.getNombre() << " (" << ciudad.getPais() << "):" << std::endl;
            
            for (const auto& arista : listaAdyacencia[i]) {
                const Ciudad& ciudadDestino = ciudades[arista.destino];
                std::cout << "  -> " << ciudadDestino.getNombre() << " (" << ciudadDestino.getPais() 
                          << "): " << arista.data.distancia << " km, " << arista.data.duracion << " minutos" << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

void Grafo_listaAdyacencia::BFS(const std::string& inicioCiudad) const {
    // Realizar recorrido BFS desde la ciudad de inicio
    auto it = nombreACiudadId.find(inicioCiudad);
    if (it == nombreACiudadId.end()) {
        throw std::runtime_error("Ciudad de inicio no encontrada");
    }

    int inicio = it->second;
    std::vector<bool> visitado(ciudades.size(), false);
    std::queue<int> cola;

    visitado[inicio] = true;
    cola.push(inicio);

    while (!cola.empty()) {
        int actual = cola.front();
        std::cout << ciudades[actual].getNombre() << " (" << ciudades[actual].getPais() << ") ";
        cola.pop();

        for (const auto& arista : listaAdyacencia[actual]) {
            if (!visitado[arista.destino]) {
                visitado[arista.destino] = true;
                cola.push(arista.destino);
            }
        }
    }
    std::cout << std::endl;
}