#include "Ciudad.h"

// Constructor de la clase Ciudad
Ciudad::Ciudad(int id, const std::string& nombre, const std::string& pais, bool tieneAeropuerto)
    : id(id), nombre(nombre), pais(pais), tieneAeropuerto(tieneAeropuerto) {}

// Implementación de los métodos getter

int Ciudad::getId() const {
    return id;
}

const std::string& Ciudad::getNombre() const {
    return nombre;
}

const std::string& Ciudad::getPais() const {
    return pais;
}

bool Ciudad::getTieneAeropuerto() const {
    return tieneAeropuerto;
}