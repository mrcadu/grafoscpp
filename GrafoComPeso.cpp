#include <fstream>
#include "GrafoComPeso.h"

GrafoComPeso::GrafoComPeso()
= default;

void GrafoComPeso::lerGrafo() {
    int numeroVertices;
    int verticeOrigem;
    int verticeDestino;
    int peso;
    FILE *input;
    input = fopen("./live_journal.txt", "r");
    if(input) {
        fscanf(input, "%d\n", &numeroVertices);
        vertices.reserve(numeroVertices);
        while (fscanf(input, "%d %d %d \n", &verticeOrigem, &verticeDestino, &peso) != EOF) {
            vertices[verticeOrigem-1].verticesVizinhosIndices.push_back(verticeOrigem-1);
            vertices[verticeDestino-1].verticesVizinhosIndices.push_back(verticeOrigem-1);
        }
    }
    fclose(input);
}