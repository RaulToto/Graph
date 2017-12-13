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

template<typename VertexType, typename EdgeType>

Vertex<VertexType, EdgeType> *Graph<VertexType,EdgeType>::findVertex(VertexType d)
{
    Vertex<VertexType,EdgeType> *temp=firstPointerToVertex;
    while (temp->getData()==d) {
        temp=temp->pointerToNextVertex;
    }
}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::insertEdge(Vertex<VertexType, EdgeType> *origin, Vertex<VertexType, EdgeType> *destyne, EdgeType d)
{
    Edge<VertexType,EdgeType> *newEdge=new Edge<VertexType,EdgeType>(d);
    Edge<VertexType,EdgeType> *temp=origin->pointerToNextEdge;
    if(temp)
    {
        origin->pointerToNextEdge=newEdge;
        newEdge->pointerToNextVertex=destyne;
    }
    else
    {
        while (temp) {
            temp=temp->pointerToNextEdge;
        }
        temp->pointerToNextEdge=newEdge;
        newEdge->pointerToNextVertex=destyne;
    }
}

template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::insertVertex(VertexType d)
{
    Vertex<VertexType,EdgeType> *newVertex = new Vertex<VertexType,EdgeType>(d);
    if(isEmpty())
    {
        this->firstPointerToVertex=lastPointerToVertex=newVertex;
    }
    else
    {
        this->lastPointerToVertex->pointerToNextVertex=newVertex;
        this->lastPointerToVertex=newVertex;
    }

}

