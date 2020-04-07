#pragma once
#include <vector>
class AdjacencyMatrix
{
    std::vector<std::vector<bool> > mat;
    std::vector<int> order_mask;
    int _size;

    void swap_row(int i, int j);
    void swap_col(int i, int j);

    public:

    AdjacencyMatrix(int p_size);

    inline int size() { return _size; }
    inline bool get(int a,int b) const { return mat[order_mask[a]][order_mask[b]]; }

    inline std::vector<std::vector<bool> >* get_matrix() { return &mat; }

    void update_order_mask();   //TODO: Need to initialize order_mask with an especific vertex order???

    void swap_vertex(int a, int b);
    
    int count_connected(int a);
    int edge_count();

    void write_matrix();
    void read_matrix(bool normalize = true);
};
