#ifndef GRAFO_H_
#define GRAFO_H_
#include "Vertice.h"
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class Grafo{
public:
    Grafo();
    void inicializarGrafo(vector<Vertice> vetorVertices);
    void lerGrafo();
    void BFS(int indiceVerticeRaiz);
    void desmarcarVertices();
    vector<Vertice> vetorVertices;
};

#endif
