#include "graph.h"
#include <string>
class AssociativeGraph : public Graph
{
    std::unordered_map<int,std::string> associative_map;

    public:
    void add_vertex(int v,std::string p_val);
    std::string& operator[](int v) { return associative_map[v]; }

    void write_associative_map();
    void write_associative_entry(int v);
    void read_associative_map();

    void write_graph();
    void read_graph();
};
