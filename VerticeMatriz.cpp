#include "VerticeMatriz.h"

void VerticeMatriz::defineMatrizVertices(int numvertices)
{
    vector<bool> MatrizVertices(numvertices);
    this -> vetorVerticesVizinhos = MatrizVertices;
}
VerticeMatriz::VerticeMatriz(int numvertices){

    vector<bool > MatrizVertices(numvertices);
    this -> vetorVerticesVizinhos = MatrizVertices;

}