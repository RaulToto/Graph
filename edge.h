#ifndef EDGE_H
#define EDGE_H


template<typename VertexType,typename EdgeType> class Vertex;
template<typename VertexType,typename EdgeType> class Graph;
template<typename VertexType,typename EdgeType>
class Edge
{

    friend class Graph<VertexType,EdgeType>;
public:
    Edge();
};

#endif // EDGE_H
