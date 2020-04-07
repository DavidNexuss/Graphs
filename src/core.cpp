#include "core.h"
#include <iostream>
using namespace std;

template <typename T>
void print_vector(const vector<T>& a,int n)
{
    if (n == -1) n = a.size();
    for(int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}
