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
vector<vector<int>> GrafoListaAdjacencia::BFSArvoreGeradora(int indiceVerticeRaiz){
    desmarcarVertices();
    queue<int> verticesDescobertos;
    int nivelAtual=0;
    int indicePaiAtual;
    vector<vector<int>> informacoesArvore(vetorVertices.size());
    for(int i = 0;i<vetorVertices.size();i++){
        informacoesArvore[i].resize(2);
    }
    Vertice *verticeRaiz = &vetorVertices[indiceVerticeRaiz];
    verticeRaiz->marcar();
    verticesDescobertos.push(indiceVerticeRaiz);
    informacoesArvore[indiceVerticeRaiz][0] = 0;
    informacoesArvore[indiceVerticeRaiz][1] = -1;
    indicePaiAtual = indiceVerticeRaiz;
    while (!verticesDescobertos.empty()) {
        int indiceVerticeAtual = verticesDescobertos.front();
        if(informacoesArvore[verticesDescobertos.front()][1] != indicePaiAtual){
            nivelAtual += 1;
            indicePaiAtual = verticesDescobertos.front();
        }
        Vertice verticeAtual = vetorVertices[indiceVerticeAtual];
        verticesDescobertos.pop();
        list<int> *vizinhos = &verticeAtual.verticesVizinhosIndices;
        for (auto &vizinho : *vizinhos) {
            Vertice *vizinhoAtual = & vetorVertices[vizinho];
            if(!vizinhoAtual->marcadoBusca) {
                informacoesArvore[vizinho][0] = nivelAtual;
                informacoesArvore[vizinho][1] = indiceVerticeAtual+1;
                vizinhoAtual->marcar();
                verticesDescobertos.push(vizinho);
            }
        }
    }
    return informacoesArvore;
}
void GrafoListaAdjacencia::BFS(int indiceVerticeRaiz){
    desmarcarVertices();
    queue<int> verticesDescobertos;
    Vertice *verticeRaiz = &vetorVertices[indiceVerticeRaiz];
    verticeRaiz->marcar();
    verticesDescobertos.push(indiceVerticeRaiz);
    while (!verticesDescobertos.empty()) {
        Vertice verticeAtual = vetorVertices[verticesDescobertos.front()];
        verticesDescobertos.pop();
        list<int> *vizinhos = &verticeAtual.verticesVizinhosIndices;
        for (auto &vizinho : *vizinhos) {
            Vertice *vizinhoAtual = & vetorVertices[vizinho];
            if(!vizinhoAtual->marcadoBusca) {
                vizinhoAtual->marcar();
                verticesDescobertos.push(vizinho);
            }
        }
    }
}
void GrafoListaAdjacencia::DFS(int indiceVerticeRaiz){
    desmarcarVertices();
    stack<int> pilhaVertices;
    pilhaVertices.push(indiceVerticeRaiz);
    while(!pilhaVertices.empty()){
        Vertice *verticeAtual = &vetorVertices[pilhaVertices.top()];
        pilhaVertices.pop();
        if(!verticeAtual->marcadoBusca){
            verticeAtual->marcar();
            list<int> *vizinhos = &verticeAtual->verticesVizinhosIndices;
            for(auto &vizinho :*vizinhos){
                pilhaVertices.push(vizinho);
            }
        }

    }
}
