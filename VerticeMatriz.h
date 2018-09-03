#ifndef GRAFOSCPP_VERTICEMATRIZ_H
#define GRAFOSCPP_VERTICEMATRIZ_H
#include <vector>


using namespace std;

class VerticeMatriz {
public:
    VerticeMatriz();
    explicit VerticeMatriz(int numvertices);
    vector<bool> vetorVerticesVizinhos;
    void defineMatrizVertices(int numvertices);
    void marcar();
    void desmarcar();
    bool marcadoBusca;
};


#endif
