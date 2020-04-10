#include "associative_graph.h"
#include <iostream>
using namespace std;

int main()
{
    AssociativeGraph graph;
    char operation;
    int operator1;
    string operator2;
    int operator3;
    AdjacencyMatrix* mat;
    while(cin >> operation)
    {
        switch(operation)
        {
            case 'C':
                graph.read_graph();
                break;
            case 'P':
                graph.write_graph();
                break;
            case 'A':
                mat = graph.create_adjacency_matrix();
                mat->write_matrix();
                delete mat;
                break;
            case '+':
                cin >> operator1 >> operator2;
                graph.add_vertex(operator1,operator2);
                break;
            case '*':
                cin >> operator1 >> operator2;
                graph.append_vertex(operator1,operator2);
                break;
            case '-':
                cin >> operator1;
                graph.remove_vertex(operator1);
                break;
            case '|':
                cin >> operator1 >> operator3;
                graph.add_edge(operator1,operator3);
                break;
            case '/':
                cin >> operator1 >> operator3;
                graph.remove_edge(operator1,operator3);
                break;
            case '[':
                cin >> operator1;
                graph.write_associative_entry(operator1);
                break;
        }
    }
}
