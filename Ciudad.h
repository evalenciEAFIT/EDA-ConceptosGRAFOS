#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>

// Clase que representa una ciudad en la red de vuelos
class Ciudad {
private:
    int id;                 // Identificador único de la ciudad
    std::string nombre;     // Nombre de la ciudad
    std::string pais;       // País al que pertenece la ciudad
    bool tieneAeropuerto;   // Indica si la ciudad tiene aeropuerto

public:
    // Constructor
    Ciudad(int id, const std::string& nombre, const std::string& pais, bool tieneAeropuerto);

    // Métodos getter
    int getId() const;
    const std::string& getNombre() const;
    const std::string& getPais() const;
    bool getTieneAeropuerto() const;
};

#endif // CIUDAD_H