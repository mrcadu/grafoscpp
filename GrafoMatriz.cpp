#include <utility>
#include <algorithm>
#include <math.h>
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
    numeroArestas=0;

}

void GrafoMatriz::lerGrafo() {
    int numeroVertices;
    int verticeOrigem;
    int verticeDestino;
    FILE *input;
    input = fopen("../as_graph.txt", "r");
    if(input) {
        fscanf(input, "%d\n", &numeroVertices);
        inicializarGrafo(numeroVertices);
        while (fscanf(input, "%d %d \n", &verticeOrigem, &verticeDestino) != EOF) {
            vertices[verticeOrigem-1].vetorVerticesVizinhos[verticeDestino-1] = true;
            vertices[verticeDestino-1].vetorVerticesVizinhos[verticeOrigem-1] = true;
            numeroArestas++;
        }

    }
    fclose(input);
}

void GrafoMatriz::info() {
    int arestas = numeroArestas;
    int tamVertices = vertices.size();
    vector<int> Graus;
    Graus.reserve(tamVertices);
    for (int i =0;i<tamVertices;i++){
        int grau=0;
        for (int j = 0; j < tamVertices; j++) {
            if (vertices[i].vetorVerticesVizinhos[j] == 1) {
                grau++;
            }

        }
        Graus[i] = grau;

    }
    int gmax = 0;
    int gmin = tamVertices;
    double gavg;
    int gmed;

    double totalGraus=0;
    for(int i = 0;i<tamVertices;i++){
        totalGraus+= Graus[i];
        }


    gavg = totalGraus/tamVertices;

    std::sort(Graus.begin(),Graus.end());

    if(tamVertices%2 == 0){
        int n = trunc(tamVertices/2);
        gmed = (Graus[n-1] + Graus[n])/2;
    } else {
        int n = tamVertices/2;
        gmed = Graus[n];
    }

    gmin=Graus[tamVertices-1];
    gmax=Graus[0];


    ofstream arquivoSaida;

    if(arquivoSaida){
        arquivoSaida.open("output.txt");
        arquivoSaida << "Numero de Vertices:" << tamVertices  << endl;
        arquivoSaida << "Numero de Arestas:" << arestas << endl;
        arquivoSaida << "Grau Médio:" << gavg << endl;
        arquivoSaida << "Mediana dos Graus:" << gmed << endl;
        arquivoSaida << "Grau Min:" << gmin << endl;
        arquivoSaida << "Grau Max:" << gmax << endl;

        arquivoSaida.close();
    }


}

void GrafoMatriz::desmarcarVertices(){
    for (auto &vetorVertice : vertices) {
        vetorVertice.desmarcar();
    }
}

void GrafoMatriz::BFS(int indiceVerticeRaiz) {
    desmarcarVertices();
    queue<VerticeMatriz *> verticesDescobertos;
    VerticeMatriz *verticeRaiz = &vertices[indiceVerticeRaiz];
    verticeRaiz->marcar();
    verticesDescobertos.push(verticeRaiz);
    while (!verticesDescobertos.empty()) {
        VerticeMatriz verticeAtual = *verticesDescobertos.front();
        verticesDescobertos.pop();
        vector<bool> *vetorVerticesVizinhos = &verticeAtual.vetorVerticesVizinhos;
        for (int i = 0; i < vertices.size(); i++) {
            if (vetorVerticesVizinhos->at(i) == true) {
                VerticeMatriz *vizinhoAtual = &vertices[i];
                if (!vizinhoAtual->marcadoBusca) {
                    vizinhoAtual->marcar();
                    verticesDescobertos.push(vizinhoAtual);
                }
            }

        }
    }
}

void GrafoMatriz::DFS(int indiceVerticeRaiz){
    desmarcarVertices();
    stack<int> pilhaVertices;
    pilhaVertices.push(indiceVerticeRaiz);
    while(!pilhaVertices.empty()){
        VerticeMatriz *verticeAtual = &vertices[pilhaVertices.top()];
        pilhaVertices.pop();
        if(!verticeAtual->marcadoBusca){
            verticeAtual->marcar();
            vector<bool> *vizinhos = &verticeAtual->vetorVerticesVizinhos;
            for(int i = 0; i < vertices.size(); i++){
                if(vizinhos->at(i) == true) {
                    pilhaVertices.push(i);
                }
            }
        }

    }
}