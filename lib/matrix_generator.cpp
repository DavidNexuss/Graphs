/*
 * Utility program for printing to standard output square matrices.
 * Given a parameter n (default == 5) the utility will print:
 * -n
 * -the matrix
 * the matrix is generated with random 0 and 1 with a specific probability
 * the element aii for each i in 0 <= i < n is equal to 0
 */
#include <iostream>
#include "rand.h"
using namespace std;

int number(char* str) //Utility function for converting char* to int, wont deal with unsupported conversions
{
    int n = 0;
    while(*str)
    {
        n = n * 10 + ((*str) - '0');
        str++;
    }
    return n;
}
int main(int argc, char* argv[])
{
    srand(SEED);
    int n = 5;
    if (argc > 1) n = number(argv[1]);

    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (rand() % 10 > 7 and j != i) << " ";
        }
        cout << endl;
    }
}
