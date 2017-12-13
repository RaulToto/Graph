#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vertex.h>
using namespace std;
template<typename VertexType,typename EdgeType>
class Graph
{
public:
    Graph();
    void inicializate();
    int getSize();
    bool isEmpty();
private:
    Vertex<VertexType,EdgeType> *firstPointerToVertex;
};

#endif // GRAPH_H
