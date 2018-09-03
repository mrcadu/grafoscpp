#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cstring>
#include <stdio.h>
#include "GrafoListaAdjacencia.h"
#include "GrafoMatriz.h"
#include <time.h>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    clock_t tInicio, tFim, tDecorrido;
    GrafoMatriz matriz;
    matriz.lerGrafo();
    tInicio = clock();
    for(int i=0;i<100;i++){
    matriz.DFS(i);
    printf("%d-1 vezes rodada \n",i);
    }
    tFim = clock();
    tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    printf("%f", static_cast<double>(tDecorrido));
}


