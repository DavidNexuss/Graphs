#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    AdjacencyMatrix mat(n);
    mat.readMatrix();
    cout << n << endl;
    mat.writeMatrix();
}
