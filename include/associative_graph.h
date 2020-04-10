#include "graph.h"
#include <string>
class AssociativeGraph : public Graph
{
    std::unordered_map<int,std::string> associative_map;
    std::unordered_map<std::string,int> reverse_associative_map;

    public:
    int add_vertex(int v,std::string p_val);
    int append_vertex(int vertex_father,std::string p_val);

    std::string& operator[](int v) { return associative_map[v]; }

    void write_associative_map();
    void write_associative_entry(int v);
    void read_associative_map();

    void write_graph();
    void read_graph();
};
