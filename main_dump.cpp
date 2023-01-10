// #include "vector_2.hpp"
#include <iostream>

// class Test
// {
// public:
//     Test(int a)
//         : _a(a)
//     {}

//     int get_a() const
//     {
//         return _a;
//     }

//     void func()
//     {
//         this->get_a();
//     }

//     Test operator+(const int &b)
//     {
//         return Test(this->_a + b);
//     }

// private:
//     int _a;
// };

// // a, b en dhors de la class
// Test operator+(const Test &a, const int &b)
// {
//     std::cout << "Test + Int" << std::endl;
//     return Test(a.get_a() + b);
// }

// Test operator+(const int &a, const Test &b)
// {
//     std::cout << "Int + Test" << std::endl;
//     return Test(a + b.get_a());
// }

// Test operator+(const Test &a, const std::string &b)
// {
//     std::cout << "Test + string" << std::endl;
//     return Test(a.get_a() + b.size());
// }

// Test operator+(const std::string &a, const Test &b)
// {
//     return Test(a.size() + b.get_a());
// }

int main(){
    // Forgeron -> Test
    // Forgeron -> créer/allouer 2 Test -> 2 Test

    // std::allocator<Test> alloc; // creer un allocator pour le type Test, qui creer des tests

    // Test *mem = alloc.allocate(2); //ici on crée trois tests
    // for (int i = 0; i < 2; ++i)
    //     alloc.construct(mem + i);
    // for (int i = 0; i < 2; ++i)
    //     alloc.destroy(mem + i);
    // alloc.deallocate(mem, 2);
    //destroy : appelle le destructeur de la class en question et applique le destructeur
    //deallocate : desalloue le pointeur donner en parametre 

    // mem[1] = Test();
    // mem[2] = Test();

    // std::cout << mem[0].a << std::endl;
    // std::cout << mem[1] << std::endl;

    // int *tab = new int[5];

    // tab[0] = 4;
    // tab[1] = 89;

    // std::vector<int> vec;
    // vec.push_back(2);
    // vec.push_back(5);
    // vec.push_back(15);
    // vec.push_back(3);
    // vec.push_back(78);

    // vec.resize(3, 10);
    // vec.resize(7, 10);

    // for (size_t i = 0; i < vec.size(); ++i)
    //     std::cout << "E: " << vec[i] << std::endl;

    //std::vector<int> vtest;
    // ft::vector<int> test;
    // test.push_back(6);
    // test.push_back(9);
    // test.push_back(98);
    // std::cout << test[0] << std::endl;
    // std::cout << test[1] << std::endl;
    // std::cout << test[2] << std::endl;
    // test.clear();
    // test.push_back(4);
    // std::cout << test[0] << std::endl;

/*    test.push_back(9);
    test.push_back(34);
    std::cout << test[0] << std::endl;
    std::cout << test[1] << std::endl;
    std::cout << test[2] << std::endl;*/
    return 0;
}

// vector<int> -> int *
// vector<std::string> - > std::string *