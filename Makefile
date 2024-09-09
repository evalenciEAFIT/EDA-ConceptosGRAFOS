CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
SOURCES = main.cpp Ciudad.cpp Data.cpp Grafo_matrizAdyacencia.cpp Grafo_listaAdyacencia.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = red_vuelos

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean