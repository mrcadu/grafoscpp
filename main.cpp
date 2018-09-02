#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>
#include <stdio.h>
#include "GrafoListaAdjacencia.h"
#include <time.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    clock_t tInicio, tFim, tDecorrido;
    GrafoListaAdjacencia grafoListaAdjacencia;
    grafoListaAdjacencia.lerGrafo();
    tInicio = clock();
    grafoListaAdjacencia.BFS(0);
    tFim = clock();
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("%f", static_cast<double>(tDecorrido));
}


