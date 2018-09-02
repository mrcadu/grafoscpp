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
    Grafo grafo = Grafo();
    grafo.lerGrafo();
    clock_t tInicio, tFim, tDecorrido;
    tInicio = clock();
    grafo.BFS(0);
    tFim = clock();
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("%f \n", static_cast<double>(tDecorrido));
}


