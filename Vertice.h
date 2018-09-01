#ifndef VERTICE_H_
#define VERTICE_H_
#include <map>
#include <vector>
#include <list>
using namespace std;

class Vertice{
public:
    Vertice();
    list<int> verticesVizinhosIndices;
    void defineCodigo(int codigo);
    int codigoVertice;
    int numeroAtualIterador;
    bool marcado;
    int nivelBusca;
    map<int,int> mapaDistancia;
};


#endif