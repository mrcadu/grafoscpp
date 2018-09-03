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
vector<Vertice*> GrafoListaAdjacencia::BFSConectividade(int indiceVerticeRaiz){
    desmarcarVertices();
    queue<int> verticesDescobertos;
    vector<Vertice*> verticesPertencentesComponenteConexa;
    verticesPertencentesComponenteConexa.reserve(vetorVertices.size());
    Vertice *verticeRaiz = &vetorVertices[indiceVerticeRaiz];
    verticesPertencentesComponenteConexa.push_back(verticeRaiz);
    verticeRaiz->marcar();
    verticesDescobertos.push(indiceVerticeRaiz);
    while (!verticesDescobertos.empty()) {
        Vertice verticeAtual = vetorVertices[verticesDescobertos.front()];
        verticesDescobertos.pop();
        list<int> *vizinhos = &verticeAtual.verticesVizinhosIndices;
        for (auto &vizinho : *vizinhos) {
            Vertice *vizinhoAtual = & vetorVertices[vizinho];
            if(!vizinhoAtual->marcadoBusca) {
                verticesPertencentesComponenteConexa.push_back(vizinhoAtual);
                vizinhoAtual->marcar();
                verticesDescobertos.push(vizinho);
            }
        }
    }
    return verticesPertencentesComponenteConexa;
}
list<vector<Vertice*>> GrafoListaAdjacencia::findComponentesConexos(int indiceVerticeRaiz) {
    list<Vertice*> verticesNaoRemovidos;
    list<vector<Vertice*>> componentesConexos;
    for(int i = 0;i<vetorVertices.size();i++) {
        verticesNaoRemovidos.push_back(&vetorVertices[indiceVerticeRaiz]);
    }
    verticesNaoRemovidos.remove(&vetorVertices[indiceVerticeRaiz]);
    componentesConexos.push_back(BFSConectividade(indiceVerticeRaiz));
    for (auto vertice : componentesConexos.front()) {
        verticesNaoRemovidos.remove(vertice);
    }
    while(verticesNaoRemovidos.size() >= 0){
        int indiceVerticeAtual = findIndiceVertice(verticesNaoRemovidos.front());
        vector<Vertice*> verticesConexos = BFSConectividade(indiceVerticeAtual);
        componentesConexos.push_back(verticesConexos);
        for (auto vertice : verticesConexos) {
            verticesNaoRemovidos.remove(vertice);
        }
    }
    return componentesConexos;
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
vector<vector<int>>  GrafoListaAdjacencia::DFSArvoreGeradora(int indiceVerticeRaiz){
    desmarcarVertices();
    int nivelBuscaAtual = 0;
    stack<int> pilhaVertices;
    vector<vector<int>> informacoesArvore(vetorVertices.size());
    for(int i = 0;i<vetorVertices.size();i++){
        informacoesArvore[i].resize(2);
        informacoesArvore[i][1] = -2;
    };
    pilhaVertices.push(indiceVerticeRaiz);
    informacoesArvore[indiceVerticeRaiz][1] = -1;
    informacoesArvore[indiceVerticeRaiz][0] = 0;
    while(!pilhaVertices.empty()){
        int indiceVerticeAtual = pilhaVertices.top();
        Vertice *verticeAtual = &vetorVertices[pilhaVertices.top()];
        pilhaVertices.pop();
        if(!verticeAtual->marcadoBusca){
            verticeAtual->marcar();
            list<int> *vizinhos = &verticeAtual->verticesVizinhosIndices;
            for(auto &vizinho :*vizinhos){
                if(informacoesArvore[vizinho][1] == -2) {
                    informacoesArvore[vizinho][1] = indiceVerticeAtual + 1;
                    informacoesArvore[vizinho][0] = informacoesArvore[indiceVerticeAtual][0]+1;
                }
                pilhaVertices.push(vizinho);
            }
        }
    }
    return informacoesArvore;
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
            nivelAtual ++;
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
int GrafoListaAdjacencia::findIndiceVertice(Vertice* vertice){
    for(int i = 0; i< vetorVertices.size();i++ ){
        if (&vetorVertices[i] == vertice){
            return i;
        }
    }
}