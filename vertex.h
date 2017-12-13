#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
using namespace std;
template<typename VertexType,typename EdgeType> class Edge;
template<typename VertexType,typename EdgeType> class Graph;
template<typename VertexType,typename EdgeType>
class Vertex
{
    friend class Graph<VertexType,EdgeType>;
public:
    Vertex();
private:
    VertexType vertexData;
    Vertex<VertexType,EdgeType> *pointerToNextVertex;
    Edge<VertexType,EdgeType> *pointerToNextEdge;

};

#endif // VERTEX_H
