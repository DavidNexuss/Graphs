#include <iostream>
#include <stack>
#include "rand.h"
using namespace std;

/*
 * Mutable BinaryTree difined using raw pointers for convenience, so need to pay attention to deallocate memory!*/
struct node
{
    int val = 0;
    struct node* a = nullptr;
    struct node* b = nullptr;

    node(int _val,node* _a,node* _b) : val(_val), a(_a), b(_b) { }
    node(int _val) : val(_val) { }
    node() { }

    //Delete recursively all its children
    ~node()
    {
        delete a;       //The call of delete against a nullptr has no effect by especification, so its unnecessary to test if its a nullptr
        delete b;
    };
};

/**
 * Singleton container for storing tree generation invariants
 */
struct _tree_generator_invariants
{
    int path_tail;
    int max_branching;
};

_tree_generator_invariants tree_generator_invariants = {20,2};

/*
 * Given a root node an maximum path tail, builds a random tree with the root node.
 * Path_tail means that given any leaf of the tree and the root node, its path wont be longer than path_tail 
 * */
node* generate_random_tree(node* root,int path_tail)
{
    root->val = (rand() % 100) + 1;
    if (path_tail <= 0) return root;
    
    //20 and 8 are magic numbers, changing their values will make the tree, less or more dense
    //Changing its values dynamically (saying changing in every recursive call) could make interesting effects.
    if (rand() % 20 >= 8) root->a = generate_random_tree(new node(),path_tail - 1);
    if (rand() % 20 >= 8) root->b = generate_random_tree(new node(),path_tail - 1);
    return root;    //Returning same value for convenience in writing recursive function
}
/*
 * Prints tree in preorder
 */
void print_tree(node* root)
{
    if (root != nullptr)
    {
         cout << root->val << endl;
         print_tree(root->a);
         print_tree(root->b);
    } else cout << 0 << endl;   //Given an empty tree print 0
}

/**
 * Prints a random tree given its maximum path_tail
 * */
void print_random_tree(int path_tail)
{
    cout << (rand() % 100) + 1 << endl;
    if (path_tail > 0)
    {
        for (int i = 0; i < tree_generator_invariants.max_branching; i++)
        {
            if (rand() % 20 >= 10)
            {
                print_random_tree(path_tail - 1);

            }else cout << "0" << endl;
        }
    }
}

node* read_tree()
{
    int n;
    cin >> n;
    if (n == 0) return nullptr;
    return new node(n,read_tree(),read_tree());
}

void pretty_print(node* root,int indent=0)
{
    if (root != nullptr)
    {
        for(int i=0;i<indent;i++)
        {
            cout << " ";
        }
        cout << root->val << endl;
        if(root->a) pretty_print(root->a,indent + 1);
        if(root->b) pretty_print(root->b,indent + 1);
    }
}

/**
 * Returns a pointer to the root of the clone of tree src
 */
node* cpy_tree(node* src)
{
    if (src != nullptr)
        return new node(src->val,cpy_tree(src->a),cpy_tree(src->b));
    return nullptr;

}

/**
 * First leaf of binary tree root, (dfs)
 */
node* first_leaf(node* root)
{
    if (root->a == nullptr && root->b == nullptr) return root;
    if (root->a != nullptr) return first_leaf(root->a);
    return first_leaf(root->b);
}

void add_tree(node* src,node* dst)
{
    node* leaf = first_leaf(dst);
    leaf->a = src;
}
//-------------------------------------PROCEDURES----------------------------

void randomize(bool verbose)
{
    auto t = time(NULL);
    if (verbose)
        cout << "Using seed: " << t << endl;
    srand(SEED);
}
int main(int argc, char* argv[])
{
    bool verbose = false;
    string no_element_str = "Tried to use top element, but no element exists in stack!.";
    if (argc < 2)
    {
        cout << "Not enough arguments provided!" << endl;
        return 1;
    }

    char *op_code = argv[1];
    bool std_enabled = false;
    if (*op_code == '-')
    {
        std_enabled = true;
        op_code++;
    }
    stack<node*> node_stack_pile;

    node* global_ptr = nullptr;
    node* ta = nullptr;
    node* tb = nullptr;
    int tt = 0;
    char std_op_code;
    bool using_std = false;
    randomize(false);
    while (*op_code != '\0' or (std_enabled and cin >> std_op_code))
    {   
        if (*op_code == '\0' and std_enabled){ *op_code = std_op_code; using_std = true;}

        if (*op_code >= '0' && *op_code <= '9')
        {
            node_stack_pile.push(new node(*op_code - '0'));
        }else 
        switch(*op_code)
        {
            case 'h':
                cout << "Program for creating and manipulating trees in the shell, compiled " << __DATE__ << endl;
            case 'v':
                verbose = true;
                break;
            case 'p':
                delete node_stack_pile.top();
                node_stack_pile.pop();
                break;
            case 'O':
                print_random_tree(tree_generator_invariants.path_tail);
                break;
            case 'C':
                node_stack_pile.push(generate_random_tree(new node(),20));
                break;
            case 'R':
                node_stack_pile.push(read_tree());
                break;
            case 'b':
                if (node_stack_pile.size() >= 1)
                    print_tree(node_stack_pile.top());
                else if (verbose) cout << no_element_str << endl;
                break;
            case 'c':
                if (node_stack_pile.size() >= 1)
                    node_stack_pile.push(cpy_tree(node_stack_pile.top()));
                else if (verbose) cout << no_element_str << endl;
                break;
            case 'f':
                if (node_stack_pile.size() >= 1)
                   cout << first_leaf(node_stack_pile.top())->val << endl;
                else if (verbose) cout << no_element_str << endl;
                break;
            case 'a':
                if (node_stack_pile.size() >= 2)
                {
                    ta = node_stack_pile.top();
                    node_stack_pile.pop();
                    tb = node_stack_pile.top();
                    add_tree(ta,tb);
                    node_stack_pile.push(tb);
                }
                break;
            case 'g':
                if (node_stack_pile.size() >= 1)
                    global_ptr = node_stack_pile.top();
                else if (verbose) cout << no_element_str << endl;
                break;
            case 'G':
                if (global_ptr != nullptr)
                    node_stack_pile.push(global_ptr);
                else if (verbose) cout << no_element_str << endl;
                break;
            case 'l':
                if (node_stack_pile.size() >= 1)
                    ta = node_stack_pile.top();
                    if (ta->a != nullptr) node_stack_pile.push(ta->a);
                    else if (verbose) cout << "End of root" << endl;
                else if (verbose) cout << no_element_str << endl;
                break;
            case 'r':
                if (node_stack_pile.size() >= 1)
                    ta = node_stack_pile.top();
                    if (ta->b != nullptr) node_stack_pile.push(ta->b);
                    else if (verbose) cout << "End of root" << endl;
                else if (verbose) cout << no_element_str << endl;
                break;
            default:
                if(verbose)
                {
                    cout << "Unsupported option: " << *op_code << endl;
                }
                break;
        }
        if(not using_std) op_code++;
        else *op_code = '\0';
    }
}
