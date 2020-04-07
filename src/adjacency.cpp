#include <iostream>
#include "adjacency.h"
#include "core.h"
using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int p_size) : _size(p_size),
    mat(p_size,vector<bool>(p_size)),order_mask(p_size)
{ 
    //Sets order mask to a natural order, this will map
    //evry vertex i to itself
    for(int i=0;i<order_mask.size();i++)
    {
        order_mask[i] = i;
    }
}

void AdjacencyMatrix::update_order_mask() {}

void AdjacencyMatrix::swap_row(int i,int j)
{
    mat[order_mask[i]].swap(mat[order_mask[j]]);
}

void AdjacencyMatrix::swap_col(int i, int j)
{
    for(int w = 0; w < size();w++)
    {
        swap(mat[w][i],mat[w][j]);
    }
}

void AdjacencyMatrix::swap_vertex(int a,int b)
{
    int t  = order_mask[a];
    order_mask[a] = order_mask[b];
    order_mask[b] = t;
}

int AdjacencyMatrix::count_connected(int a)
{
    int sum = 0;
    for(int i = 0; i < size();i++)
    {
        sum += mat[a][i];
    }
    return sum;
}

int AdjacencyMatrix::edge_count()
{
    int c = 0;
    for(int i = 1; i < size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            c+= mat[i][j];
        }
    }
    return c;
}
void AdjacencyMatrix::write_matrix()
{
    for(int i = 0; i < size();i++)
    {
        for(int j = 0; j < size();j++)
        {
            cout << get(i,j) << " ";
        }
        cout << endl;
    }
}

void AdjacencyMatrix::read_matrix(bool normalize)
{
    for (int i = 0; i < size(); i++)
    {
        for (int j = 0; j < size(); j++)
        {
            bool t; cin >> t;
            mat[i][j] = mat[i][j] || t;
            if (normalize) mat[j][i] = mat[j][i] || mat[i][j];
        }
    }
}
