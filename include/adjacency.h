#pragma once
#include <vector>
class AdjacencyMatrix
{
    std::vector<std::vector<bool> > mat;
    std::vector<int> order_mask;
    int size;

    void swap_row(int i, int j);
    void swap_col(int i, int j);

    public:

    AdjacencyMatrix(int _size);

    inline std::vector<std::vector<bool> >* get_matrix() { return &mat; }
    inline bool get(int a,int b) const { return mat[order_mask[a]][order_mask[b]]; }
    inline int getSize() { return size; }

    void update_order_mask();

    void swap_vertex(int a, int b);
    
    int countConnected(int a);

    void writeMatrix();
    void readMatrix(bool normalize = true);
};
