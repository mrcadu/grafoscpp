#include <utility>
#include <algorithm>
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
    input = fopen("../input.txt", "r");
    if(input) {
        fscanf(input, "%d\n", &numeroVertices);
        vector<Vertice> vetorVertices(numeroVertices);
        while (fscanf(input, "%d %d \n", &verticeOrigem, &verticeDestino) != EOF) {
            vetorVertices[verticeOrigem-1].verticesVizinhosIndices.push_back(verticeDestino-1);
            vetorVertices[verticeDestino-1].verticesVizinhosIndices.push_back(verticeOrigem-1);
            numeroArestas += 1;
        }
        inicializarGrafo(vetorVertices);
        this -> numeroArestas = numeroArestas;
    }
    fclose(input);
}
void GrafoListaAdjacencia::desmarcarVertices(){
    for (auto &vetorVertice : vetorVertices) {
        vetorVertice.desmarcar();
    }
}
void GrafoListaAdjacencia::informacoesGrafo(){
    ofstream arquivoGrafoInformacoes;
    int numeroVertices = vetorVertices.size();
    int somatorioGraus=0;
    int medianaGrau;
    int grauMaximo;
    int grauMinimo;
    double grauMedio;
    vector<int> vetorGraus;
    vetorGraus.reserve(numeroVertices);
    if(arquivoGrafoInformacoes){
        for(auto &vertice : vetorVertices){
            int grauVertice = vertice.verticesVizinhosIndices.size();
            vetorGraus.push_back(grauVertice);
            somatorioGraus += grauVertice;
        }
        sort(vetorGraus.begin(),vetorGraus.end());
        grauMinimo = vetorGraus.front();
        grauMaximo = vetorGraus.back();
        grauMedio = (double) somatorioGraus/numeroVertices;
        if(vetorGraus.size()%2 == 0){
            medianaGrau = vetorGraus[vetorGraus.size()/2];
        }
        else{
            medianaGrau = vetorGraus[(vetorGraus.size()/2)+1];
        }

        arquivoGrafoInformacoes.open("../informacoesGrafo.txt");
        arquivoGrafoInformacoes << "numero de vertices:" << numeroVertices  << endl;
        arquivoGrafoInformacoes << "numero de arestas:" << numeroArestas << endl;
        arquivoGrafoInformacoes << "grau Médio:" << grauMedio << endl;
        arquivoGrafoInformacoes << "grau Min:" << grauMinimo << endl;
        arquivoGrafoInformacoes << "grau Max:" << grauMaximo << endl;
        arquivoGrafoInformacoes << "Mediana dos Graus:" << medianaGrau << endl;

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
void GrafoListaAdjacencia::DFS(int indiceVerticeRaiz){
    desmarcarVertices();
    stack<Vertice*> pilhaVertices;
    Vertice *verticeRaiz = &vetorVertices[indiceVerticeRaiz];
    pilhaVertices.push(verticeRaiz);
    while(!pilhaVertices.empty()){
        pilhaVertices.top()->marcar();
        Vertice verticeAtual = *pilhaVertices.top();
        pilhaVertices.pop();
        list<int> *vizinhos = &verticeAtual.verticesVizinhosIndices;
        for(auto &vizinho :*vizinhos){
            Vertice *vizinhoAtual = &vetorVertices[vizinho];
            if(!vizinhoAtual->marcadoBusca) {
                pilhaVertices.push(vizinhoAtual);
            }
        }
    }
}
