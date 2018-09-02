#include <utility>
#include "GrafoMatriz.h"


GrafoMatriz::GrafoMatriz()=default;

void GrafoMatriz::inicializarGrafo(int numvertices)
{
    VerticeMatriz matriz = VerticeMatriz(numvertices);
    vector<VerticeMatriz> vetorVertices(numvertices);
    for(int f =0;f<numvertices;f++){
        vetorVertices[f].vetorVerticesVizinhos.resize(numvertices);
    }
    vertices = vetorVertices;

}

void GrafoMatriz::lerGrafo() {
    int numeroVertices;
    int numeroArestas = 0;
    int verticeOrigem;
    int verticeDestino;
    FILE *input;
    input = fopen("../as_graph.txt", "r");
    if(input) {
        fscanf(input, "%d\n", &numeroVertices);
        inicializarGrafo(numeroVertices);
        while (fscanf(input, "%d %d \n", &verticeOrigem, &verticeDestino) != EOF) {
            vertices[verticeOrigem].vetorVerticesVizinhos[verticeDestino] = true;
            vertices[verticeDestino].vetorVerticesVizinhos[verticeOrigem] = true;
            numeroArestas++;
        }

    }
    fclose(input);
}