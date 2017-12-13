#include "graph.h"
template<typename VetexType,typename EdgeType>
Graph<VetexType,EdgeType>::Graph()
{

}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::inicializate()
{
    this->firstPointerToVertex=nullptr;
}

template<typename VertexType, typename EdgeType>
int Graph<VertexType,EdgeType>::getSize()
{
    int cont=0;
    Vertex<VertexType,EdgeType> *temp=firstPointerToVertex;
    while (temp) {
        temp=temp->pointerToNextVertex;
        cont++;
    }
    return cont;
}

template<typename VertexType, typename EdgeType>
bool Graph<VertexType,EdgeType>::isEmpty()
{
    return this->firstPointerToVertex==nullptr;
}
