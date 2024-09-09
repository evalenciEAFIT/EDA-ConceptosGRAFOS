#include "Grafo_matrizAdyacencia.h"
#include <iostream>
#include <queue>
#include <stdexcept>

Grafo_matrizAdyacencia::Grafo_matrizAdyacencia() {}

Grafo_matrizAdyacencia::~Grafo_matrizAdyacencia() {
    // Liberar memoria de la matriz de adyacencia
    for (auto& fila : matrizAdyacencia) {
        for (auto& data : fila) {
            delete data;
        }
    }
}

void Grafo_matrizAdyacencia::agregarCiudad(const std::string& nombre, const std::string& pais, bool tieneAeropuerto) {
    // Agregar nueva ciudad al vector y al mapa
    int id = ciudades.size();
    ciudades.emplace_back(id, nombre, pais, tieneAeropuerto);
    nombreACiudadId[nombre] = id;

    // Ampliar la matriz de adyacencia
    for (auto& fila : matrizAdyacencia) {
        fila.push_back(nullptr);
    }
    matrizAdyacencia.emplace_back(ciudades.size(), nullptr);
}

void Grafo_matrizAdyacencia::agregarVuelo(const std::string& origen, const std::string& destino, int distancia, int duracion) {
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

    // Agregar vuelo a la matriz de adyacencia
    matrizAdyacencia[idOrigen][idDestino] = new Data(distancia, duracion);
    matrizAdyacencia[idDestino][idOrigen] = new Data(distancia, duracion); // Para grafo no dirigido
}

void Grafo_matrizAdyacencia::imprimirRedVuelos() const {
    // Imprimir información de vuelos para cada ciudad con aeropuerto
    for (size_t i = 0; i < ciudades.size(); ++i) {
        const Ciudad& ciudad = ciudades[i];
        if (ciudad.getTieneAeropuerto()) {
            std::cout << ciudad.getNombre() << " (" << ciudad.getPais() << "):" << std::endl;
            
            for (size_t j = 0; j < ciudades.size(); ++j) {
                if (matrizAdyacencia[i][j] != nullptr) {
                    const Ciudad& ciudadDestino = ciudades[j];
                    const Data& vuelo = *matrizAdyacencia[i][j];
                    std::cout << "  -> " << ciudadDestino.getNombre() << " (" << ciudadDestino.getPais() 
                              << "): " << vuelo.distancia << " km, " << vuelo.duracion << " minutos" << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }
}

void Grafo_matrizAdyacencia::BFS(const std::string& inicioCiudad) const {
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

        for (size_t i = 0; i < ciudades.size(); ++i) {
            if (matrizAdyacencia[actual][i] != nullptr && !visitado[i]) {
                visitado[i] = true;
                cola.push(i);
            }
        }
    }
    std::cout << std::endl;
}