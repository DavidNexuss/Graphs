#include "associative_graph.h"
#include <iostream>
using namespace std;
void AssociativeGraph::add_vertex(int v,std::string p_val)
{
    Graph::add_vertex(v);
    if (associative_map.count(v)) return;
    associative_map.insert({v,p_val});
}

void AssociativeGraph::write_graph()
{
    Graph::write_graph();
    write_associative_map();
}
void AssociativeGraph::read_graph()
{
    Graph::read_graph();
    read_associative_map();
}

void AssociativeGraph::write_associative_entry(int v)
{
    for(auto i : get_vertex_list(v))
    {
        cout << i << " " << associative_map[i] << endl;
    }
}
void AssociativeGraph::write_associative_map()
{
    cout << associative_map.size() << endl;
    for(auto& entry : associative_map)
    {
        cout << entry.first << " " << entry.second << endl;
    }
}

void AssociativeGraph::read_associative_map()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int v;
        string s;
        cin >> v >> s;
        associative_map.insert({v,s});
    }
}
