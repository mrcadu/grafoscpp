#ifndef GRAFOSCPP_GRAFO_H
#define GRAFOSCPP_GRAFO_H
#include <string>
class Grafo {
    enum tipoGrafo {listaAdjacencia,matriz,listaComPeso};
    void lerGrafo(tipoGrafo);
};

#endif
