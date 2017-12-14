#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vertex.h>
#include <edge.h>
#include <edge.cpp>
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
    void insertEdge(Vertex<VertexType,EdgeType>*,Vertex<VertexType,EdgeType>*,EdgeType);
    void insertVertex(VertexType);
    bool isCicle(Vertex<VertexType,EdgeType>);
    void kruskal();
    void prim();
    int sumaDistancia(int,Graph<VertexType,EdgeType>);
    void print()
    {
        Vertex<VertexType,EdgeType> *p;
        while (p) {
            cout << p->getData() << endl;
            p=p->pointerToNextVertex;
        }
    }

private:
    Vertex<VertexType,EdgeType> *firstPointerToVertex;
    Vertex<VertexType,EdgeType> *lastPointerToVertex;
};

#endif // GRAPH_H

