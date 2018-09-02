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
    input = fopen("../grafoteste.txt", "r");
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
    lerGrafo();
    int Infos[6];
    int arestas = numeroArestas;
    int tamVertices = vertices.size();
    int Graus[tamVertices];
    for (int i =0;i<tamVertices;i++){
        int grau=0;
        for (int j = 0; i<tamVertices;j++) {
            if (vertices[i].vetorVerticesVizinhos[j] == 1) {
                grau++;
            }
        }
        Graus[i] = grau;

    }
    int gmax = 0;
    int gmin = tamVertices;
    int gavg;
    int gmed;

    for(int i = 0;i<tamVertices;i++){
        if(Graus[i]>gmax){
            gmax = Graus[i];
        }
    }

    for(int i = 0;i<tamVertices;i++){
        if(Graus[i]<gmin){
            gmin = Graus[i];
        }
    }

    int totalGraus;
    for(int i = 0;i<tamVertices;i++){
        totalGraus+= Graus[i];
        }


    gavg = totalGraus/tamVertices;

    std::sort(Graus,Graus + tamVertices);

    if(tamVertices%2 == 0){
        int n = trunc(tamVertices%2);
        gmed = (Graus[n] + Graus[n+1])/2;
    } else {
        int n = tamVertices/2;
        gmed = Graus[n];
    }


    ofstream arquivoSaida;

    if(arquivoSaida){
        arquivoSaida.open("output.txt");
        arquivoSaida << "Numero de Vertices:" << tamVertices  << endl;
        arquivoSaida << "Numero de Arestas:" << arestas << endl;
        arquivoSaida << "Grau Médio:" << gmed << endl;
        arquivoSaida << "Mediana dos Graus:" << gavg << endl;
        arquivoSaida << "Grau Min:" << gmin << endl;
        arquivoSaida << "Grau Max:" << gmax << endl;

        arquivoSaida.close();
    }


}








