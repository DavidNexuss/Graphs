#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    AdjacencyMatrix mat(n);
    mat.read_matrix();
    Graph g(mat);
    g.write_graph();
}
