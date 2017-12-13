#include "vertex.h"

template<typename VertexType, typename EdgeType>
Vertex<VertexType,EdgeType>::Vertex(VertexType d)
    :vertexData(d),pointerToNextEdge(nullptr),pointerToNextVertex(nullptr)
{

}
template<typename VertexType, typename EdgeType>
VertexType Vertex<VertexType,EdgeType>::getData()
{
    return this->vertexData;
}
