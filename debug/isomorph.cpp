#include "graph.h"
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
    cout << basic_isomorph(mat, mat2) << endl;
}
