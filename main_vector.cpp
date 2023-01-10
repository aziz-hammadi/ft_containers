#include "vector_2.hpp"
#include <iostream>

int main()
{
    // Test t;
    // std::cout << "[" << t.a << ", " << t.b << ", " << t.c << "]" << std::endl;

    ft::vector<int> vec; //accede a vector dans le namespace ft pour la variable vec
    vec.push_back(3);
    std::cout << vec[0] << std::endl;
    std::cout << vec.size() << std::endl;
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(43);
    vec.push_back(46);
    vec.push_back(49);
    std::cout << vec[5] << std::endl;
    std::cout << vec.size() << std::endl;
    int i(0);
    while (i < vec.size())
        std::cout << vec[i++] << std::endl;
    std::cout << vec.size() << std::endl;
        vec.pop_back();
    i = 0;
    while (i < vec.size())
        std::cout << vec[i++] << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec.size() << std::endl;
}