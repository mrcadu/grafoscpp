#ifndef GRAFOMATRIZ_H_
#define GRAFOMATRIZ_H_
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include "VerticeMatriz.h"

using namespace std;

class GrafoMatriz{
public:
    vector<VerticeMatriz> vertices;
    GrafoMatriz();
    void inicializarGrafo(int numvertices);
    void lerGrafo();

};


#endif
