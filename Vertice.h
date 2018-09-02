#ifndef VERTICE_H_
#define VERTICE_H_
#include <map>
#include <vector>
#include <list>
using namespace std;

class Vertice{
public:
    Vertice();
    void defineVerticesVizinhos();
    void marcar();
    void desmarcar();
    list<int> verticesVizinhosIndices;
    bool marcadoBusca;
};


#endif