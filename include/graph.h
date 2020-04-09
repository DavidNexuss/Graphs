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

    int size();

    int add_vertex(int v);
    int remove_vertex(int v);

    int add_edge(int a,int b);
    int remove_edge(int a,int b);

    inline int get_vertex_count() { return adjacency_map.size(); }

    std::list<int>& get_vertex_list(int i);
    std::list<int>& operator[](int i) { return get_vertex_list(i);}
    
    AdjacencyMatrix* create_adjacency_matrix();

    void write_graph(bool simplify = false);
    void read_graph();
};
