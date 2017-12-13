#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vertex.h>
#include <edge.h>
using namespace std;
template<typename VertexType,typename EdgeType>
class Graph
{
public:
    Graph();
    void inicializate();
    int getSize();
    bool isEmpty();
    Vertex<VertexType,EdgeType> * findVertex(VertexType);
    void insertEdge(Vertex<VertexType,EdgeType>,Vertex<VertexType,EdgeType>,EdgeType);
    void insertVertex(VertexType);
private:
    Vertex<VertexType,EdgeType> *firstPointerToVertex;
    Vertex<VertexType,EdgeType> *lastPointerToVertex;
};

#endif // GRAPH_H

