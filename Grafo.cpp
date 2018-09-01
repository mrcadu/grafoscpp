#include <utility>

#include "Grafo.h"

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
    input = fopen("../arquivoGrafoMaior.txt", "r");
    if(input) {
        fscanf(input, "%d\n", &numeroVertices);
        vector<Vertice> vetorVertices(numeroVertices);
        for (int i = 0; i < numeroVertices; i++) {
            vetorVertices[i].defineCodigo(i + 1);
        }
        while (fscanf(input, "%d %d \n", &verticeOrigem, &verticeDestino) != EOF) {
            try {
                vetorVertices[verticeOrigem-1].verticesVizinhosIndices.push_back(verticeDestino-1);
                vetorVertices[verticeDestino-1].verticesVizinhosIndices.push_back(verticeOrigem-1);
                numeroArestas += 1;
            }
            catch(int e) {
                printf("%d",e);
            }
        }
        inicializarGrafo(vetorVertices);
    }
    fclose(input);
}
