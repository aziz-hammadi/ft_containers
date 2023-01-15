#include "vector.hpp"
#include <iostream>
#include <iostream>
#include <locale>
#include <vector>

class Json
{
public:
    Json(std::string filename)
    {
        std::ifstream fs(filename);

        fs.getlin()
    }

    ~Json()
    {
        std::cout << "FINISH " << this << std::endl;
    }

    int _matrix[][];
};

int main()
{
    std::vector<int> t;
    t.push_back(4);
    t.push_back(3);
    t.push_back(2);
    t.push_back(1);

    t.resize(2, 7);

    for (size_t i = 0; i < t.size(); ++i)
        std::cout << t[i] << std::endl;

    // std::vector<Test> t;
    // t.push_back(Test());
    // t.push_back(Test());
    // t.push_back(Test());

    // ft::vector<Test> vvec;
    // vvec.push_back(Test());
    // vvec.push_back(Test());
    // vvec.push_back(Test());
    // std::cout << "END" << std::endl;
    return 0;
    // Test t;
    // std::cout << "[" << t.a << ", " << t.b << ", " << t.c << "]" << std::endl;
    std::vector<int> vec_; //accede a vector dans le namespace ft pour la variable vec
    vec_.push_back(3);

    ft::vector<int> vec; //accede a vector dans le namespace ft pour la variable vec
    vec.push_back(3);

    std::cout << "max_size" << std::endl;
    std::cout << "Maximum size of a std::vector is " << vec.max_size() << '\n';
    std::cout << "original : max_size" << std::endl;

    std::cout << "Maximum size of a std::vector is " << vec_.max_size() << '\n';
    std::cout << vec[0] << std::endl;
    std::cout << vec.size() << std::endl;
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(43);
    vec.push_back(46);
    vec.push_back(49);
    std::cout << vec[5] << std::endl;
    std::cout << vec.size() << std::endl;
    size_t i(0);
    while (i < vec.size())
        std::cout << vec[i++] << std::endl;
    std::cout << vec.size() << std::endl;
        vec.pop_back();
    i = 0;
    while (i < vec.size())
        std::cout << vec[i++] << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec[5] << std::endl;
    std::cout << "max_size" << std::endl;
    std::cout << vec.max_size() << std::endl;
    std::cout << "original : max_size" << std::endl;

 std::cout << "Maximum size of a std::vector is " << vec.max_size() << '\n';
    std::cout << "empty" << std::endl;

    std::cout << vec.empty() << std::endl;
    std::cout << "clear" << std::endl;

    vec.clear();
    std::cout << vec.size() << std::endl;
    std::cout << "empty" << std::endl;

    std::cout << vec.empty() << std::endl;
    vec.clear();
    vec_.clear();
    std::cout << "empty vec :" << vec.empty() << "empty vec_" << vec_.empty() << std::endl;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);


    ft::vector<int> vec2; //accede a vector dans le namespace ft pour la variable vec
    vec2.push_back(1);
    vec2.push_back(3);
    vec2.push_back(5);
    vec2.swap(vec);
    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << vec[2] << std::endl;
    std::cout << vec2[0] << std::endl;
    std::cout << vec2[1] << std::endl;
    std::cout << vec2[2] << std::endl;
    
}