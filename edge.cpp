#include "edge.h"

template<typename VertexType, typename EdgeType>
Edge<VertexType,EdgeType>::Edge(EdgeType d)
    :edgeData(d),pointerToNextEdge(nullptr),pointerToNextVertex(nullptr)
{

}

template<typename VertexType, typename EdgeType>
EdgeType Edge<VertexType,EdgeType>::getData()
{
    return this->edgeData;
}
