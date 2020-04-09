#include "associative_graph.h"
#include <iostream>
using namespace std;

int main()
{
    AssociativeGraph my_map;
    my_map.add_vertex(0,"hello");
    my_map.add_vertex(1,"pepe");
    my_map.add_vertex(2,"tomas");
    my_map.add_edge(0,1);
    my_map.add_edge(0,2);
    my_map.add_edge(1,2);
    my_map.write_graph();
}
