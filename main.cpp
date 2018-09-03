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
    GrafoListaAdjacencia grafoListaAdjacencia;
    grafoListaAdjacencia.lerGrafo();
    grafoListaAdjacencia.DFS(0);
}


