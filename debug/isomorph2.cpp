#include "graph.h"
#include "core.h"
#include "adjacency.h"
#include "algorithm.h"
#include <iostream>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    AdjacencyMatrix mat(n);
    mat.read_matrix();
    cin >> n;
    AdjacencyMatrix mat2(n);
    mat2.read_matrix();
    vector<int> v;
    if (isomorph_map(mat, mat2, v))
    {
        print_vector(v);
    }
}
