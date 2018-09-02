#ifndef GRAFO_H_
#define GRAFO_H_
#include "Vertice.h"
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class GrafoListaAdjacencia{
public:
    GrafoListaAdjacencia();
    void inicializarGrafo(vector<Vertice> vetorVertices);
    void lerGrafo();
    void desmarcarVertices();
    void BFS(int indiceVerticeRaiz);
    vector<Vertice> vetorVertices;
};

#endif
