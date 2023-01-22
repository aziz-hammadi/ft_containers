#include <iostream>

int main() {
    std::pair<float, int> p;
    /*p.first = 1;
    p.second = "hello";*/
    std::cout << p.first << " " << p.second << std::endl; // imprime "1 hello"
    return 0;
}