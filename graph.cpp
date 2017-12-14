#include "graph.h"
#include <fibonacciheap.h>
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
        this->firstPointerToVertex=newVertex;
    }
    else
    {
        this->lastPointerToVertex->pointerToNextVertex=newVertex;
        this->lastPointerToVertex=newVertex;
    }

}

template<typename VertexType, typename EdgeType>
bool Graph<VertexType,EdgeType>::isCicle(Vertex<VertexType,EdgeType> v)
{
    Vertex<VertexType,EdgeType> *tem=this->firstPointerToVertex;
    //insertEdge();
}
/*
template<typename VertexType, typename EdgeType>
void Graph<VertexType,EdgeType>::prim()
{
       FibonacciHeap<VertexType> heap(nVertices, nFilhos);
       Vertice *u, *v;
       int i;
       list<aresta>::iterator it;
       bool mstSet[nVertices + 1];
       g->tabela[1]->distancia = 1231231;
       g->tabela[1]->ultimoVertice = 0;
       heap.insert(g->tabela[1]);
       for (i = 1; i <= nVertices; i++) {
           mstSet[i] = false;
       }
       while (heap.tamanhoAtual > 0) {
           u = heap.deleteMin();
           mstSet[u->numero] = true;
           for (it = u->adj.begin(); it != u->adj.end(); it++) {
               v = (*it).first;
               if (v->distancia == INFINITO && mstSet[v->numero] == false) {
                   v->distancia = g->valorAresta(v->numero, u->numero);
                   v->ultimoVertice = u->numero;
                   heap.insert(v);
               } else if (v->distancia > g->valorAresta(v->numero, u->numero) && mstSet[v->numero] == false) {
                   v->ultimoVertice = u->numero;
                   heap.decreaseKey(v, g->valorAresta(v->numero, u->numero));
               }
           }
       }
       return somaDistanciaHeap2(nVertices, g);
}

template<typename VertexType, typename EdgeType>
int Graph<VertexType,EdgeType>::sumaDistancia(int, Graph<VertexType, EdgeType>)
{
    int valor = 0;
        int i;
        for (i = 1; i <= nVertices; i++) {
            if (g->valorAresta(g->tabela[i]->numero, g->tabela[i]->ultimoVertice) != INFINITO) {
                valor += g->valorAresta(g->tabela[i]->numero, g->tabela[i]->ultimoVertice);
            }
        }
    return valor;
*/
