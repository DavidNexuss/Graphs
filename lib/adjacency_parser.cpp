/* Simple program to parse an adjacency matrix to an
 * adjacency list.
 * It is expected as input the size of the matrix and
 * a normalized adjacency matrix
 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < n; ++j)
        {
            bool t; cin >> t;
            if(t) cout << j << " ";
        }
        cout << endl;
    }

}
