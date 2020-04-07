#pragma once
#include "adjacency.h"
/** Basic Algorithm to test if two to graphs are isomorph given
 * their Adjacency Matrices, trivial algorithm that will perform a search
 * with all possible permutations of vertices to find a function that
 * maps all vertices of a to the vertices of b, n!.
 *
 * cost: O(n!)
 */
bool basic_isomorph(AdjacencyMatrix& a,AdjacencyMatrix& b,int n = -1);
