#ifndef GRAFOMATRIZ_H_
#define GRAFOMATRIZ_H_
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class GrafoMatriz{
public:
    MatrizGrafo();
    void inicializarGrafo(int numeroVertices);
    int matrizArestas[int][int];
    void lerGrafo();


};


#endif
