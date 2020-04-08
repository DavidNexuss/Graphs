#pragma once
#include "adjacency.h"
#include <vector>
/** Basic Algorithm to test if two to graphs are isomorph given
 * their Adjacency Matrices, trivial algorithm that will perform a search
 * with all possible permutations of vertices to find a function that
 * maps all vertices of a to the vertices of b, n!.
 *
 * If keep_solutoins is set to true the function will leave the matrix a with an order_mask
 * set to match the matrix a with b.
 *
 * cost: O(n!)
 */
bool basic_isomorph(AdjacencyMatrix& a,AdjacencyMatrix& b,int n = -1,bool keep_solution = false);

/** If graph of matrix a is isomoroph with graph of matrix b, map_function will be the function to 
 * transform a into b, otherwise it will be a order_mask
 * Returns wheter the graphs are isomorph or not.
 * cost: O(n!)
 */
bool isomorph_map(AdjacencyMatrix& a, AdjacencyMatrix& b,std::vector<int>& map_function);
