# Proyecto de Grafo en C++

Este proyecto implementa una estructura de datos de grafo en C++ con funcionalidades para agregar nodos y aristas, realizar búsquedas en anchura (BFS) y encontrar la ruta más corta usando el algoritmo de Dijkstra.

## Estructura del Proyecto

- `Data.h` y `Data.cpp`: Definen la clase que almacena la información de cada nodo.
- `Nodo.h` y `Nodo.cpp`: Implementan la clase Nodo, que representa un vértice en el grafo.
- `HashTable.h` y `HashTable.cpp`: Implementan una tabla hash para búsqueda eficiente de nodos.
- `Grafo.h` y `Grafo.cpp`: Contienen la implementación principal del grafo y sus algoritmos.
- `main.cpp`: Programa de ejemplo que utiliza la clase Grafo con un grafo simple.
- `main2.cpp`: Programa de ejemplo que crea un grafo de ciudades europeas.
- `Makefile`: Archivo para compilar el proyecto.

## Estructuras de Datos Utilizadas y su Eficiencia

1. **Grafo**: 
   - Vector de nodos: $O(1)$ para acceso, $O(1)$ amortizado para inserción.
   - HashTable para búsqueda: $O(1)$ promedio, $O(n)$ peor caso.

2. **Nodo**: 
   - Objeto Data: $O(1)$ para acceso y modificación.
   - unordered_map para aristas: $O(1)$ promedio, $O(n)$ peor caso para operaciones.

3. **HashTable**: 
   - Vector de listas: $O(1)$ promedio, $O(n)$ peor caso para operaciones.

4. **Data**: 
   - String simple: $O(1)$ para operaciones básicas.

## Algoritmos Implementados

### Búsqueda en Anchura (BFS)

BFS explora el grafo nivel por nivel, visitando primero todos los vecinos directos de un nodo antes de pasar al siguiente nivel.

Pseudocódigo:
```
función BFS(G, s):
    para cada vértice u en V[G] - {s}:
        estado[u] = NO_VISITADO
        distancia[u] = infinito
        padre[u] = NULO
    estado[s] = VISITADO
    distancia[s] = 0
    padre[s] = NULO
    Q = nueva Cola()
    ENCOLAR(Q, s)
    mientras NO_ESTA_VACIA(Q):
        u = DESENCOLAR(Q)
        para cada v en ADY[u]:
            si estado[v] == NO_VISITADO:
                estado[v] = VISITADO
                distancia[v] = distancia[u] + 1
                padre[v] = u
                ENCOLAR(Q, v)
    return distancia, padre
```

Explicación:
- Inicializamos todos los nodos como no visitados, con distancia infinita y sin padre.
- Comenzamos desde el nodo inicial 's', marcándolo como visitado, con distancia 0 y sin padre.
- Usamos una cola para procesar los nodos en el orden correcto (primero en entrar, primero en salir).
- Para cada nodo en la cola, exploramos todos sus vecinos no visitados.
- Marcamos los vecinos como visitados, actualizamos su distancia y padre, y los añadimos a la cola.
- El proceso continúa hasta que la cola esté vacía, lo que significa que hemos explorado todo el grafo alcanzable desde 's'.

Complejidad: $O(|V| + |E|)$, donde $|V|$ es el número de vértices y $|E|$ el número de aristas.

### Algoritmo de Dijkstra

Dijkstra encuentra la ruta más corta entre dos nodos en un grafo con pesos positivos.

Pseudocódigo:
```
función Dijkstra(G, origen, destino):
    para cada vértice v en V[G]:
        distancia[v] = infinito
        padre[v] = NULO
    distancia[origen] = 0
    Q = nueva ColaPrioridad()
    INSERTAR(Q, (0, origen))
    mientras NO_ESTA_VACIA(Q):
        (dist, u) = EXTRAER_MINIMO(Q)
        si u == destino:
            break
        para cada v en ADY[u]:
            nueva_dist = distancia[u] + peso(u, v)
            si nueva_dist < distancia[v]:
                distancia[v] = nueva_dist
                padre[v] = u
                INSERTAR(Q, (nueva_dist, v))
    return reconstruir_camino(padre, origen, destino), distancia[destino]
```

Explicación:
- Inicializamos todas las distancias como infinito y los padres como NULO.
- La distancia al nodo origen se establece en 0.
- Usamos una cola de prioridad para seleccionar siempre el nodo más cercano no procesado.
- En cada iteración, seleccionamos el nodo con la menor distancia de la cola.
- Si alcanzamos el destino, terminamos la búsqueda.
- Para cada vecino del nodo actual, calculamos la nueva distancia pasando por este nodo.
- Si encontramos un camino más corto, actualizamos la distancia y el padre del vecino.
- Añadimos el vecino a la cola de prioridad con su nueva distancia.
- Al final, reconstruimos el camino más corto usando los padres y devolvemos la distancia total.

Complejidad: $O((|V| + |E|) \log |V|)$ con cola de prioridad, donde $|V|$ es el número de vértices y $|E|$ el número de aristas.

## Compilación y Ejecución

Para compilar el proyecto:
```
make
```

Para ejecutar el ejemplo simple:
```
make run
```

Para ejecutar el ejemplo de ciudades europeas:
```
make run2
```

Para limpiar los archivos compilados:
```
make clean
```

## Ejemplos de Uso

### Ejemplo Simple (main.cpp)

```cpp
Grafo grafo;
grafo.agregarNodo(Data("A"));
grafo.agregarNodo(Data("B"));
// ... (más nodos y aristas)
grafo.imprimirGrafo();
grafo.bfs("A");
grafo.dijkstra("A", "E");
```

### Ejemplo de Ciudades Europeas (main2.cpp)

```cpp
Grafo europa;
europa.agregarNodo(Data("Madrid"));
europa.agregarNodo(Data("Paris"));
// ... (más ciudades y conexiones)
europa.imprimirGrafo();
imprimirRuta("Madrid", "Berlin", europa);
```

## Características Principales

1. Flexibilidad en tipos de datos de nodos.
2. Búsqueda eficiente con tabla hash.
3. Implementación de BFS y Dijkstra.
4. Ejemplos prácticos incluidos.

## Limitaciones y Posibles Mejoras

- Extensión a grafos dirigidos.
- Validación de nodos duplicados.
- Implementación de más algoritmos (DFS, Prim, Kruskal).
- Generalización para otros tipos de identificadores.
