/*
 * Utility program for printing to standard output square matrices.
 * Given a parameter n (default == 5) the utility will print:
 * -n
 * -the matrix
 * the matrix is generated with random 0 and 1 with a specific probability
 */
#include <iostream>
#include <time.h>
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
    srand(time(NULL));
    int n = 5;
    if (argc > 1) n = number(argv[1]);

    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (rand() % 10 > 7) << " ";
        }
        cout << endl;
    }
}
