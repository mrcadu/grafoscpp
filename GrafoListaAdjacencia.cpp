#include <utility>

#include "GrafoListaAdjacencia.h"

GrafoListaAdjacencia::GrafoListaAdjacencia()
= default;
void GrafoListaAdjacencia::inicializarGrafo(vector<Vertice> vetorVertices) {
    this -> vetorVertices = std::move(vetorVertices);
}
void GrafoListaAdjacencia::lerGrafo() {
    int numeroVertices;
    int numeroArestas = 0;
    int verticeOrigem;
    int verticeDestino;
    FILE *input;
    input = fopen("../arquivoGrafoMenor.txt", "r");
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
void GrafoListaAdjacencia::desmarcarVertices(){
    for (auto &vetorVertice : vetorVertices) {
        vetorVertice.desmarcar();
    }
}
void GrafoListaAdjacencia::BFS(int indiceVerticeRaiz){
    desmarcarVertices();
    queue<Vertice*> verticesDescobertos;
    Vertice *verticeRaiz = &vetorVertices[indiceVerticeRaiz];
    verticeRaiz->marcar();
    verticesDescobertos.push(verticeRaiz);
    while (!verticesDescobertos.empty()) {
        Vertice verticeAtual = *verticesDescobertos.front();
        verticesDescobertos.pop();
        list<int> *vizinhos = &verticeAtual.verticesVizinhosIndices;
        for (auto &vizinho : *vizinhos) {
            Vertice *vizinhoAtual = & vetorVertices[vizinho];
            if(!vizinhoAtual->marcadoBusca) {
                vizinhoAtual->marcar();
                verticesDescobertos.push(vizinhoAtual);
            }
        }
    }
}
