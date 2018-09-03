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
    int findIndiceVertice(Vertice* vertice);
    void inicializarGrafo(vector<Vertice> vetorVertices);
    int numeroArestas;
public:
    list<vector<Vertice*>> findComponentesConexos(int indiceVerticeRaiz);
    vector<Vertice*> BFSConectividade(int indiceVerticeRaiz);
    GrafoListaAdjacencia();
    void lerGrafo();
    vector<vector<int>> BFSArvoreGeradora(int indiceVerticeRaiz);
    vector<vector<int>> DFSArvoreGeradora(int indiceVerticeRaiz);
    void BFS(int indiceVerticeRaiz);
    void DFS(int indiceVerticeRaiz);
    void informacoesGrafo();
    vector<Vertice> vetorVertices;
};

#endif
