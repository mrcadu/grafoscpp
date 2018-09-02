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
    vector<Vertice> vetorVertices;
    void lerGrafo();
};

#endif
