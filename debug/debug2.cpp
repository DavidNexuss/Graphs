/* Test program to validate efficient method for swaping vertices in
 * adjacency matrix
 * Given a matrix and all the swapings that are desired, after all swapings,
 * performing again all the swaps in reverse order should give the initial matrix.
 */

#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    AdjacencyMatrix mat(n);
    mat.read_matrix();
    cout << "Current adjacency matrix: " << endl;
    mat.write_matrix();
    
    //TODO: Use stacks to automatate comprobations:
    int a,b;
    while (cin >> a >> b)
    {
        mat.swap_vertex(a, b);
        mat.write_matrix();
    }
}
