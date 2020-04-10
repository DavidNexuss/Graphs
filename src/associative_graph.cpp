#include "associative_graph.h"
#include <iostream>
using namespace std;

int AssociativeGraph::add_vertex(int v,string p_val)
{
    if (Graph::add_vertex(v) || associative_map.count(v)) return 1;
    associative_map.insert({v,p_val});
    reverse_associative_map.insert({p_val,v});
    return 0;
}

int AssociativeGraph::append_vertex(int vertex_father,string p_val)
{
    Graph::add_vertex(vertex_father);
    if (reverse_associative_map.count(p_val))
    {
        int v = reverse_associative_map[p_val];
        add_edge(v,vertex_father);
    }else 
    {
        int v = size();
        add_vertex(v,p_val);
        add_edge(v,vertex_father);

    }
    return 0;
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
