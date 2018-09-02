#ifndef GRAFOSCPP_VERTICEMATRIZ_H
#define GRAFOSCPP_VERTICEMATRIZ_H
#include <vector>


using namespace std;

class VerticeMatriz {
public:
    VerticeMatriz(int numvertices);
    vector<bool> vetorVerticesVizinhos;
    void defineMatrizVertices(int numvertices);
};


#endif
