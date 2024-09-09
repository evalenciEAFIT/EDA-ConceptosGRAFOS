#ifndef DATA_H
#define DATA_H

// Estructura que representa los datos de un vuelo entre ciudades
struct Data {
    int distancia;  // Distancia del vuelo en kilómetros
    int duracion;   // Duración del vuelo en minutos

    // Constructor
    Data(int d = 0, int t = 0);

    // Métodos adicionales
    void setDistancia(int d);
    void setDuracion(int t);
    int getDistancia() const;
    int getDuracion() const;
    
    // Método para calcular la velocidad promedio
    double calcularVelocidadPromedio() const;
};

#endif // DATA_H