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

Eficiencia general:
- Acceso a nodos: $O(1)$ promedio
- Inserción de nodos: $O(1)$ amortizado
- Búsqueda de nodos: $O(1)$ promedio, $O(n)$ peor caso
- Manejo de aristas: $O(1)$ promedio, $O(n)$ peor caso

## Algoritmos Implementados

### Búsqueda en Anchura (BFS)

Complejidad: $O(|V| + |E|)$, donde $|V|$ es el número de vértices y $|E|$ el número de aristas.

Pseudocódigo:
```
función BFS(G, s):
    para cada vértice u ∈ V[G] - {s}:
        color[u] = BLANCO
        d[u] = ∞
        π[u] = NIL
    color[s] = GRIS
    d[s] = 0
    π[s] = NIL
    Q = ∅
    ENCOLAR(Q, s)
    mientras Q ≠ ∅:
        u = DESENCOLAR(Q)
        para cada v ∈ Adj[u]:
            si color[v] = BLANCO:
                color[v] = GRIS
                d[v] = d[u] + 1
                π[v] = u
                ENCOLAR(Q, v)
        color[u] = NEGRO
```

### Algoritmo de Dijkstra

Complejidad: $O((|V| + |E|) \log |V|)$ con cola de prioridad.

Pseudocódigo:
```
función Dijkstra(G, w, s):
    INICIALIZAR-FUENTE-ÚNICA(G, s)
    S = ∅
    Q = V[G]
    mientras Q ≠ ∅:
        u = EXTRAER-MÍNIMO(Q)
        S = S ∪ {u}
        para cada vértice v ∈ Adj[u]:
            RELAJACIÓN(u, v, w)
```

## Compilación y Ejecución

Compilar:
```
make
```

Ejecutar ejemplo simple:
```
make run
```

Ejecutar ejemplo de ciudades europeas:
```
make run2
```

Limpiar archivos compilados:
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
