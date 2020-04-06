#pragma once
#include <list>
#include <unordered_map>
#include "adjacency.h"

class Graph
{
    std::unordered_map<int,std::list<int> > adjacency_map;

    public:

    Graph();
    Graph(AdjacencyMatrix& adj_mat);

    int addVertex(int v);
    int removeVertex(int v);

    int addEdge(int a,int b);
    int removeEdge(int a,int b);

    inline int getVertexCount() { return adjacency_map.size(); }

    std::list<int>& operator[](int i);
    
    AdjacencyMatrix* createAdjacencyMatrix();

    void writeGraph(bool simplify = false);
    void readGraph();
};
