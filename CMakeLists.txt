cmake_minimum_required(VERSION 3.12)
project(grafoscpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(grafoscpp main.cpp Vertice.cpp Vertice.h Grafo.cpp Grafo.h GrafoMatriz.h GrafoMatriz.cpp MatrizQuadrada.cpp MatrizQuadrada.h)