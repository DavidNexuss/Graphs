#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    AdjacencyMatrix mat(n);
    mat.read_matrix();
    cout << n << endl;
    mat.write_matrix();
}
