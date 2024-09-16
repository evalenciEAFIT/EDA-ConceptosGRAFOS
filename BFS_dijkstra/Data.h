#ifndef DATA_H
#define DATA_H

#include <string>

// Clase Data: Almacena y maneja la información asociada a cada nodo del grafo
class Data {
private:
    std::string valor;  // Almacena el valor (por ejemplo, nombre de una ciudad)

public:
    // Constructor: Inicializa el objeto Data con un valor
    explicit Data(std::string val);

    // Obtiene el valor almacenado
    // Retorna: El valor almacenado como string
    std::string obtenerValor() const;

    // Establece un nuevo valor
    // Parámetro val: El nuevo valor a establecer
    void establecerValor(const std::string& val);

    // Compara dos objetos Data
    // Parámetro other: Objeto Data a comparar
    // Retorna: true si los valores son iguales, false en caso contrario
    bool operator==(const Data& other) const;
};

#endif // DATA_H