#ifndef GRAFOMATRIZ_H_
#define GRAFOMATRIZ_H_
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include "VerticeMatriz.h"

using namespace std;

class GrafoMatriz{
public:
    vector<VerticeMatriz> vertices;
    GrafoMatriz();
    void inicializarGrafo(int numvertices);
    void lerGrafo();
    int numeroArestas;
    void info();
    void desmarcarVertices();
    void BFS(int indiceVerticeRaiz);
    void DFS(int indiceVerticeRaiz);
    vector<vector<int>> BFSArvoreGeradora(int indiceVerticeRaiz);
    vector<vector<int>> DFSArvoreGeradora(int indiceVerticeRaiz);
};


#endif
