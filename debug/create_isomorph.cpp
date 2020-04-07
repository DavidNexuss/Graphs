#include "graph.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n; cin >> n;
    AdjacencyMatrix mat(n);
    mat.read_matrix();

    for(int i = 0; i < n/3; i++)
    {
        int ai = rand() % n;
        int bi = rand() % n;
        mat.swap_vertex(ai,bi);
    }
    cout << n << endl;
    mat.write_matrix();
}
