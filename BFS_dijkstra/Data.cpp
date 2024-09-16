#include "Data.h"

// Constructor: Inicializa el objeto Data con un valor
Data::Data(std::string val) : valor(std::move(val)) {}

// Obtiene el valor almacenado
std::string Data::obtenerValor() const {
    return valor;
}

// Establece un nuevo valor
void Data::establecerValor(const std::string& val) {
    valor = val;
}

// Compara dos objetos Data
bool Data::operator==(const Data& other) const {
    return valor == other.valor;
}