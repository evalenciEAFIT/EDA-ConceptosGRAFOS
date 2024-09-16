CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS =

SRCS = Data.cpp Nodo.cpp HashTable.cpp Grafo.cpp
OBJS = $(SRCS:.cpp=.o)

all: grafo_programa europa_grafo

grafo_programa: $(OBJS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

europa_grafo: $(OBJS) main2.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o grafo_programa europa_grafo

run: grafo_programa
	./grafo_programa

run2: europa_grafo
	./europa_grafo

.PHONY: all clean run run2