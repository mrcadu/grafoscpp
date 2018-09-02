#include <utility>

#include "GrafoListaAdjacencia.h"

Grafo::Grafo()
= default;

void Grafo::inicializarGrafo(vector<Vertice> vetorVertices)
{
    this -> vetorVertices = std::move(vetorVertices);
}

void Grafo::lerGrafo() {
    int numeroVertices;
    int numeroArestas = 0;
    int verticeOrigem;
    int verticeDestino;
    FILE *input;
    input = fopen("../as_graph.txt", "r");
    if(input) {
        fscanf(input, "%d\n", &numeroVertices);
        vector<Vertice> vetorVertices(numeroVertices);
        while (fscanf(input, "%d %d \n", &verticeOrigem, &verticeDestino) != EOF) {
            vetorVertices[verticeOrigem-1].verticesVizinhosIndices.push_back(verticeDestino-1);
            vetorVertices[verticeDestino-1].verticesVizinhosIndices.push_back(verticeOrigem-1);
            numeroArestas += 1;
        }
        inicializarGrafo(vetorVertices);
    }
    fclose(input);
}
