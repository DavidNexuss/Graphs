#include "graph.h"
#include <iostream>
#include <unordered_set>
using namespace std;

Graph::Graph() { }

Graph::Graph(AdjacencyMatrix& adj_mat)
{
    int n = adj_mat.getSize();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (adj_mat.get(i, j))
            {
                addVertex(i);
                addVertex(j);
                addEdge(i, j);
            }
        }
    }
}
int Graph::addVertex(int v)
{
    if (adjacency_map.count(v)) return 1;

    adjacency_map.insert({v,list<int>()});
    return 0;
}

int Graph::removeVertex(int v)
{
    if (adjacency_map.count(v) == 0) return 1;
    adjacency_map.erase(v);
    return 0;
}

int Graph::addEdge(int a,int b)
{
    if (adjacency_map.count(a) == 0 or adjacency_map.count(b) == 0) return 1;
    adjacency_map[a].push_back(b);
    adjacency_map[b].push_back(a);
    return 0;
}

int Graph::removeEdge(int a, int b)
{
    if(adjacency_map.count(a) == 0 or adjacency_map.count(b) == 0) return 1;
    adjacency_map[a].remove(b);
    adjacency_map[b].remove(a);
    return 0;
}

void Graph::writeGraph(bool simplify)
{
    for(auto& vertex_list_pair : adjacency_map)
    {
        cout << vertex_list_pair.first << " -> ";
        for(auto jt : vertex_list_pair.second)
        {
            cout << jt << " ";
        }
        cout << endl;
    }
}

void Graph::readGraph()
{
    int a,b;
    while (cin >> a and a != -1 and cin >> b)
    {
        addVertex(a);
        addVertex(b);
        adjacency_map[a].push_back(b);
    }
}

AdjacencyMatrix* Graph::createAdjacencyMatrix()
{
    AdjacencyMatrix* adj_mat = new AdjacencyMatrix(getVertexCount());

    vector<vector<bool> >* _mat = adj_mat->get_matrix();
    for (auto& vertex_list_pair : adjacency_map)
    {
        for(int jt : vertex_list_pair.second)
        {
            (*_mat)[vertex_list_pair.first][jt] = 1;
        }
    }
    return adj_mat;
}
