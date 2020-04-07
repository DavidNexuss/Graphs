#include "algorithm.h"
#include "core.h"
#include "adjacency.h"
#include <iostream>
#include <vector>
using namespace std;
//Basic search algorithm to test if two matrices are equal
//Since they are simmetrcal there is no need to test numbers
//beyond the main diagonal including the diagonal.
bool same_matrix(AdjacencyMatrix& a, AdjacencyMatrix& b)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a.get(i, j) != b.get(i, j)) return false;
        }
    }
    return true;
}

bool basic_isomorph(AdjacencyMatrix& a,AdjacencyMatrix& b, int n)
{
    if (a.size() != b.size()) return false;
    if (same_matrix(a,b)) return true;

    if (n == -1) n = a.size();
    for (int i = 0; i < n; i++)
    {
        a.swap_vertex(i,n-1);
        bool iso = basic_isomorph(a,b,n-1);
        a.swap_vertex(i,n-1);
        if (iso) return true;
    }
    return false;
}
