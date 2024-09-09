# Implementación de Grafos: Matriz de Adyacencia vs Lista de Adyacencia

Este proyecto implementa un sistema de red de vuelos utilizando dos representaciones diferentes de grafos: matriz de adyacencia y lista de adyacencia. A continuación, se explican ambas implementaciones, sus diferencias, ventajas y desventajas, así como una explicación detallada del algoritmo de recorrido BFS.

## Matriz de Adyacencia

En la implementación con matriz de adyacencia, el grafo se representa mediante una matriz bidimensional donde tanto las filas como las columnas representan los vértices (ciudades en nuestro caso). La presencia de una arista (vuelo) entre dos vértices se indica con un valor no nulo en la celda correspondiente de la matriz.

### Estructura Básica

```cpp
class Grafo_matrizAdyacencia {
private:
    std::vector<Ciudad> ciudades;
    std::vector<std::vector<Data*>> matrizAdyacencia;
    std::unordered_map<std::string, int> nombreACiudadId;
    // ...
};
```

### Pseudocódigo para Operaciones Principales

1. Agregar Vértice (Ciudad):
```
función agregarCiudad(nombre, pais, tieneAeropuerto):
    id = tamaño_de(ciudades)
    agregar_a(ciudades, nueva Ciudad(id, nombre, pais, tieneAeropuerto))
    nombreACiudadId[nombre] = id
    para cada fila en matrizAdyacencia:
        agregar nullptr a fila
    agregar nueva fila de nullptr a matrizAdyacencia
```

2. Agregar Arista (Vuelo):
```
función agregarVuelo(origen, destino, distancia, duracion):
    idOrigen = nombreACiudadId[origen]
    idDestino = nombreACiudadId[destino]
    matrizAdyacencia[idOrigen][idDestino] = nuevo Data(distancia, duracion)
    matrizAdyacencia[idDestino][idOrigen] = nuevo Data(distancia, duracion)
```

3. Recorrido BFS:
```
función BFS(inicioCiudad):
    inicio = nombreACiudadId[inicioCiudad]
    visitado = vector_de_booleanos(falso, tamaño_de(ciudades))
    cola = nueva cola()
    cola.encolar(inicio)
    visitado[inicio] = verdadero
    mientras no cola.esta_vacia():
        actual = cola.desencolar()
        imprimir(ciudades[actual].nombre)
        para i de 0 a tamaño_de(ciudades) - 1:
            si matrizAdyacencia[actual][i] no es nullptr y no visitado[i]:
                visitado[i] = verdadero
                cola.encolar(i)
```

### Ventajas de la Matriz de Adyacencia
- Acceso rápido (O(1)) para verificar si existe una arista entre dos vértices.
- Fácil de implementar y entender.
- Eficiente para grafos densos.

### Desventajas de la Matriz de Adyacencia
- Uso ineficiente de memoria para grafos dispersos (O(V^2) donde V es el número de vértices).
- Agregar o eliminar vértices es costoso (O(V^2)).

## Lista de Adyacencia

En la implementación con lista de adyacencia, cada vértice tiene una lista de sus vértices adyacentes. Esto se representa típicamente como un vector de listas, donde cada elemento del vector corresponde a un vértice y contiene una lista de sus vecinos.

### Estructura Básica

```cpp
class Grafo_listaAdyacencia {
private:
    struct Arista {
        int destino;
        Data data;
    };
    std::vector<Ciudad> ciudades;
    std::vector<std::list<Arista>> listaAdyacencia;
    std::unordered_map<std::string, int> nombreACiudadId;
    // ...
};
```

### Pseudocódigo para Operaciones Principales

1. Agregar Vértice (Ciudad):
```
función agregarCiudad(nombre, pais, tieneAeropuerto):
    id = tamaño_de(ciudades)
    agregar_a(ciudades, nueva Ciudad(id, nombre, pais, tieneAeropuerto))
    nombreACiudadId[nombre] = id
    agregar nueva lista vacía a listaAdyacencia
```

2. Agregar Arista (Vuelo):
```
función agregarVuelo(origen, destino, distancia, duracion):
    idOrigen = nombreACiudadId[origen]
    idDestino = nombreACiudadId[destino]
    agregar_a(listaAdyacencia[idOrigen], nueva Arista(idDestino, Data(distancia, duracion)))
    agregar_a(listaAdyacencia[idDestino], nueva Arista(idOrigen, Data(distancia, duracion)))
```

3. Recorrido BFS:
```
función BFS(inicioCiudad):
    inicio = nombreACiudadId[inicioCiudad]
    visitado = vector_de_booleanos(falso, tamaño_de(ciudades))
    cola = nueva cola()
    cola.encolar(inicio)
    visitado[inicio] = verdadero
    mientras no cola.esta_vacia():
        actual = cola.desencolar()
        imprimir(ciudades[actual].nombre)
        para cada arista en listaAdyacencia[actual]:
            si no visitado[arista.destino]:
                visitado[arista.destino] = verdadero
                cola.encolar(arista.destino)
```

### Ventajas de la Lista de Adyacencia
- Uso eficiente de memoria para grafos dispersos (O(V + E) donde V es el número de vértices y E el número de aristas).
- Agregar vértices es eficiente (O(1)).
- Iterar sobre los vecinos de un vértice es eficiente.

### Desventajas de la Lista de Adyacencia
- Verificar si existe una arista entre dos vértices específicos es menos eficiente que en la matriz de adyacencia (O(grado del vértice)).
- La implementación puede ser un poco más compleja que la matriz de adyacencia.

## Comparación de Complejidades

| Operación               | Matriz de Adyacencia | Lista de Adyacencia |
|-------------------------|----------------------|---------------------|
| Agregar Vértice         | O(V^2)               | O(1)                |
| Agregar Arista          | O(1)                 | O(1)                |
| Eliminar Vértice        | O(V^2)               | O(V + E)            |
| Eliminar Arista         | O(1)                 | O(E)                |
| Verificar Adyacencia    | O(1)                 | O(V)                |
| Obtener Vecinos         | O(V)                 | O(grado(V))         |
| Memoria                 | O(V^2)               | O(V + E)            |

Donde V es el número de vértices y E el número de aristas.

## Recorrido BFS (Breadth-First Search)

El recorrido BFS es un algoritmo fundamental en la teoría de grafos que se utiliza para explorar o buscar elementos en un grafo. En el contexto de nuestra red de vuelos, el BFS puede ser útil para encontrar las conexiones más cercanas a una ciudad dada o para determinar la ruta con el menor número de escalas entre dos ciudades.

### Funcionamiento del BFS

El BFS explora el grafo nivel por nivel, visitando primero todos los vértices directamente conectados al vértice de inicio antes de moverse al siguiente nivel. El proceso es el siguiente:

1. Se comienza desde un vértice inicial.
2. Se visitan todos los vértices adyacentes a este vértice inicial.
3. Para cada uno de estos vértices adyacentes, se visitan sus vértices adyacentes no visitados.
4. Este proceso continúa hasta que se han visitado todos los vértices alcanzables desde el vértice inicial.

### Implementación del BFS

La implementación del BFS utiliza una cola para mantener un registro de los vértices por visitar. Aquí está una explicación detallada del pseudocódigo:

```
función BFS(inicioCiudad):
    inicio = nombreACiudadId[inicioCiudad]
    visitado = vector_de_booleanos(falso, tamaño_de(ciudades))
    cola = nueva cola()
    cola.encolar(inicio)
    visitado[inicio] = verdadero

    mientras no cola.esta_vacia():
        actual = cola.desencolar()
        imprimir(ciudades[actual].nombre)

        para cada vecino de actual:
            si no visitado[vecino]:
                visitado[vecino] = verdadero
                cola.encolar(vecino)
```

Explicación paso a paso:

1. Inicialización:
   - Se crea un vector `visitado` para llevar un registro de las ciudades ya visitadas.
   - Se crea una cola y se encola la ciudad inicial.
   - Se marca la ciudad inicial como visitada.

2. Proceso principal:
   - Mientras la cola no esté vacía, se continúa el proceso.
   - Se desencola una ciudad (la llamamos `actual`).
   - Se procesa la ciudad actual (en este caso, imprimimos su nombre).

3. Exploración de vecinos:
   - Para cada vecino de la ciudad actual:
     - Si el vecino no ha sido visitado:
       - Se marca como visitado.
       - Se encola para ser procesado posteriormente.

4. El proceso continúa hasta que la cola se vacía, lo que significa que se han explorado todas las ciudades alcanzables desde la ciudad inicial.

### Diferencias en la Implementación según la Representación del Grafo

1. En la matriz de adyacencia:
   - Para encontrar los vecinos de un vértice, se recorre la fila correspondiente en la matriz.
   - Complejidad de tiempo: O(V) para encontrar vecinos, donde V es el número de vértices.

2. En la lista de adyacencia:
   - Los vecinos se obtienen directamente de la lista asociada al vértice.
   - Complejidad de tiempo: O(grado(V)) para encontrar vecinos, donde grado(V) es el número de vecinos del vértice.

### Aplicaciones del BFS en la Red de Vuelos

1. Encontrar todas las ciudades alcanzables desde una ciudad de origen con un número específico de vuelos.
2. Determinar la ruta con el menor número de escalas entre dos ciudades.
3. Explorar la conectividad de la red de vuelos desde una ciudad específica.
4. Identificar "hubs" o ciudades centrales en la red que tienen conexiones con muchas otras ciudades.

### Complejidad del BFS

- Tiempo: O(V + E) tanto para la implementación con matriz de adyacencia como para lista de adyacencia, donde V es el número de vértices y E el número de aristas.
- Espacio: O(V) para el vector de visitados y la cola.

### Ventajas del BFS

1. Garantiza encontrar el camino más corto en términos de número de aristas.
2. Es completo: si existe un camino, BFS lo encontrará.
3. Es óptimo cuando todas las aristas tienen el mismo peso (en nuestro caso, si consideramos solo el número de vuelos y no la distancia o duración).

### Desventajas del BFS

1. Puede ser ineficiente en grafos muy grandes o dispersos.
2. No considera el peso de las aristas (por ejemplo, la distancia o duración de los vuelos en nuestra red).

## Conclusión

La elección entre matriz de adyacencia y lista de adyacencia depende de las características específicas del grafo y de las operaciones que se realizarán con más frecuencia:

- Usa matriz de adyacencia para grafos pequeños y densos, o cuando necesites verificar la existencia de aristas frecuentemente.
- Usa lista de adyacencia para grafos grandes y dispersos, o cuando necesites iterar sobre los vecinos de los vértices frecuentemente.

En el contexto de nuestra red de vuelos, la lista de adyacencia podría ser más apropiada si tenemos muchas ciudades pero relativamente pocos vuelos entre ellas. Sin embargo, si la red es densa (muchos vuelos entre la mayoría de las ciudades), la matriz de adyacencia podría ser más eficiente.

El algoritmo BFS es una herramienta poderosa para analizar la conectividad de la red y encontrar rutas eficientes en términos de número de escalas. Su implementación puede variar ligeramente dependiendo de la estructura de datos utilizada para representar el grafo, pero su lógica fundamental y sus aplicaciones siguen siendo las mismas.

Este proyecto demuestra cómo diferentes representaciones de grafos y algoritmos pueden ser aplicados a problemas del mundo real, como la modelación y análisis de una red de vuelos.
