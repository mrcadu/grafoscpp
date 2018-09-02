#include <utility>

#include "GrafoListaAdjacencia.h"

Grafo::Grafo()
= default;

void Grafo::inicializarGrafo(vector<Vertice> vetorVertices) {
    this -> vetorVertices = std::move(vetorVertices);
}
void Grafo::lerGrafo() {
    int numeroVertices;
    int numeroArestas = 0;
    int primeiroVertice;
    int segundoVertice;
    FILE *arquivoGrafo;
    arquivoGrafo = fopen("../input.txt", "r");
    if(arquivoGrafo) {
        fscanf(arquivoGrafo, "%d\n", &numeroVertices);
        vector<Vertice> vetorVertices(numeroVertices);
        while (fscanf(arquivoGrafo, "%d %d \n", &primeiroVertice, &segundoVertice) != EOF){
            Vertice *verticeOrigem = &vetorVertices[primeiroVertice-1];
            Vertice *verticeDestino = &vetorVertices[segundoVertice-1];
            verticeDestino->verticesVizinhos.push_back(verticeOrigem);
            verticeOrigem->verticesVizinhos.push_back(verticeDestino);
            numeroArestas += 1;
        }
        inicializarGrafo(vetorVertices);
    }
    fclose(arquivoGrafo);
}
void Grafo::desmarcarVertices(){
    for(auto &vertice : vetorVertices){
        vertice.marcadoBusca = false;
    }
}
void Grafo::BFS(int indiceVerticeRaiz){
    desmarcarVertices();
    queue<Vertice*> verticesDescobertos;
    Vertice *verticeRaiz = &vetorVertices[indiceVerticeRaiz];
    verticesDescobertos.push(verticeRaiz);
    while (!verticesDescobertos.empty()) {
        Vertice verticeAtual = *verticesDescobertos.front();
        verticesDescobertos.pop();
        list<Vertice*> *vizinhos = &verticeAtual.verticesVizinhos;
        for (auto &vizinho : *vizinhos) {
            if(!vizinho->marcadoBusca) {
                vizinho->marcar();
                verticesDescobertos.push(vizinho);
            }
        }
    }
}
