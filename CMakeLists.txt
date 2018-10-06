cmake_minimum_required(VERSION 3.12)
project(grafoscpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(grafoscpp main.cpp Vertice.cpp Vertice.h GrafoListaAdjacencia.cpp GrafoListaAdjacencia.h GrafoMatriz.h GrafoMatriz.cpp VerticeMatriz.cpp VerticeMatriz.h GrafoComPeso.cpp GrafoComPeso.h Grafo.cpp Grafo.h)



