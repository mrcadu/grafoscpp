#ifndef GRAFO_H_
#define GRAFO_H_
#include "Vertice.h"
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class GrafoListaAdjacencia{
    void desmarcarVertices();
    void inicializarGrafo(vector<Vertice> vetorVertices);
    int numeroArestas;
public:
    GrafoListaAdjacencia();
    void lerGrafo();
    vector<vector<int>> BFSArvoreGeradora(int indiceVerticeRaiz);
    void BFS(int indiceVerticeRaiz);
    void DFS(int indiceVerticeRaiz);
    void informacoesGrafo();
    vector<Vertice> vetorVertices;
};

#endif
