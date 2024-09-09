#include "Data.h"

// Constructor
Data::Data(int d, int t) : distancia(d), duracion(t) {}

// Implementación de los métodos setter
void Data::setDistancia(int d) {
    distancia = d;
}

void Data::setDuracion(int t) {
    duracion = t;
}

// Implementación de los métodos getter
int Data::getDistancia() const {
    return distancia;
}

int Data::getDuracion() const {
    return duracion;
}

// Método para calcular la velocidad promedio
double Data::calcularVelocidadPromedio() const {
    // Evitar división por cero
    if (duracion == 0) return 0;
    
    // Convertir duración de minutos a horas
    double duracionHoras = duracion / 60.0;
    
    // Calcular y retornar la velocidad promedio en km/h
    return distancia / duracionHoras;
}