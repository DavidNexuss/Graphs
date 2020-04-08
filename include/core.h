#pragma once
#include <vector>
#include <iostream>

template <typename T>
void print_vector(const std::vector<T>& v,int n = -1)
{
    if (n == -1)
        n = v.size();
    for (int i = 0; i < n; ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
