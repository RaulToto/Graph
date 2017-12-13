#ifndef VERTEX_H
#define VERTEX_H
template<typename VertexType,typename EdgeType> class Edge;
template<typename VertexType,typename EdgeType>
class Vertex
{
public:
    friend class Graph<VertexType,EdgeType>;
    Vertex();
};

#endif // VERTEX_H
