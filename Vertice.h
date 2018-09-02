#ifndef VERTICE_H_
#define VERTICE_H_
#include <map>
#include <vector>
#include <list>
using namespace std;

class Vertice{
public:
    Vertice();
    void marcar();
    list<Vertice*> verticesVizinhos;
    bool marcadoBusca;
};


#endif