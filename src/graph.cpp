#include "graph.h"
#include <iostream>
#include <unordered_set>
using namespace std;

Graph::Graph() { }

Graph::Graph(AdjacencyMatrix& adj_mat)
{
    int n = adj_mat.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (adj_mat.get(i, j))
            {
                add_vertex(i);
                add_vertex(j);
                add_edge(i, j);
            }
        }
    }
}
int Graph::size()
{
    int n = adjacency_map.size();
    for(auto& vertex_list_pair : adjacency_map)
    {
        n += vertex_list_pair.second.size();
    }
    return n;
}
int Graph::add_vertex(int v)
{
    if (adjacency_map.count(v)) return 1;

    adjacency_map.insert({v,list<int>()});
    return 0;
}

int Graph::remove_vertex(int v)
{
    if (adjacency_map.count(v) == 0) return 1;
    adjacency_map.erase(v);
    return 0;
}

int Graph::add_edge(int a,int b)
{
    if (adjacency_map.count(a) == 0 or adjacency_map.count(b) == 0) return 1;
    adjacency_map[a].push_back(b);
    adjacency_map[b].push_back(a);
    return 0;
}

int Graph::remove_edge(int a, int b)
{
    if(adjacency_map.count(a) == 0 or adjacency_map.count(b) == 0) return 1;
    adjacency_map[a].remove(b);
    adjacency_map[b].remove(a);
    return 0;
}

list<int>& Graph::get_vertex_list(int v)
{
    return adjacency_map[v];
}
void Graph::write_graph(bool simplify)
{
    cout << adjacency_map.size() << endl;
    for(auto& vertex_list_pair : adjacency_map)
    {
        cout << vertex_list_pair.second.size() << endl;
        cout << vertex_list_pair.first << " ";
        for(auto jt : vertex_list_pair.second)
        {
            cout << jt << " ";
        }
        cout << endl;
    }
}

void Graph::read_graph()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int M,v;
        cin >> M;
        cin >> v;
        add_vertex(v);
        for(int j = 0; j < M; ++j)
        {
            int t;
            cin >> t;
            add_vertex(t);
            adjacency_map[v].push_back(t);
        }
    }
}

AdjacencyMatrix* Graph::create_adjacency_matrix()
{
    AdjacencyMatrix* adj_mat = new AdjacencyMatrix(get_vertex_count());

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
