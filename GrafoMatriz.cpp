#include <utility>
#include "GrafoMatriz.h"

GrafoMatriz::GrafoMatriz()
= default;

void GrafoMatriz::inicializarGrafo(int matriz)
{
    this -> matrizArestas =  matriz;
}

void GrafoMatriz::lerGrafo() {
    int numeroVertices;
    int numeroArestas = 0;
    int verticeOrigem;
    int verticeDestino;
    FILE *input;
    input = fopen("../arquivoGrafoMedio.txt", "r");
    if(input) {
        fscanf(input, "%d\n", &numeroVertices);
        int matriz[numeroVertices][numeroVertices];
        while (fscanf(input, "%d %d \n", &verticeOrigem, &verticeDestino) != EOF) {
            matriz[verticeOrigem-1][verticeDestino-1] = 1;
            matriz[verticeDestino-1][verticeOrigem-1] = 1;
            numeroArestas += 1;
        }
        inicializarGrafo(matriz);
    }
    fclose(input);
}