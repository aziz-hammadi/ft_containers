#include "vector.hpp"
#include <iostream>
#include <iostream>
#include <locale>
//#include <vector>

/*
template <class T>
typename ft::enable_if<!(std::is_integral<T>::value || std::is_floating_point<T>::value), void>::type
hello()
{
    // rentrer la pour tout autre type
    std::cout << "T est un autre type" << std::endl;
}

template <class T>
typename ft::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, void>::type
hello()
{
    // rentrer dans hello seulement si T est un nombre ===> double, float, int, size_t, long long, unsigned long, ...
    std::cout << "T est un entier ou un nombre a virgule" << std::endl;
}

template <bool _Cond>
struct Hello;

template <>
struct Hello<true>
{
    typedef int type;
};

template <>
struct Hello<false>
{
    typedef std::string type;
};

*/
//#include "./containers_test/srcs/vector/common.hpp"
#include <list>
#define TESTED_TYPE int
#include "common.hpp"

int main()
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}
/*
struct Test
{
    static int CONSTRUCT_COUNT;
    Test()
        : i(0)
    {
        ++CONSTRUCT_COUNT;
    }

    Test(const int &i)
        : i(i)
    {
        std::cout << "CONSTRUCTING: ";
        ++CONSTRUCT_COUNT;
    }

    Test(const Test &t)
        : i(t.i)
    {
        ++CONSTRUCT_COUNT;
    }

    ~Test()
    {
        --CONSTRUCT_COUNT;
    }

    int i;
};
int Test::CONSTRUCT_COUNT = 0;

int main()
{
    std::vector<Test> vec;

    // vec.push_back(Test());
    for (int i = 0; i < 1000; ++i)
        vec.insert(vec.begin(), 1, Test(i));

    for (int i = 0; i < vec.size(); ++i)
        std::cout << "VAL: " << vec.at(i).i << std::endl;
    vec.clear();
    std::cout << "COUNT: " << Test::CONSTRUCT_COUNT << std::endl;
    // for (size_t i = 0; i < vec.size(); ++i)
        // std::cout << "Val: " << vec.at(i) << std::endl;

    
//   std::vector<int> myvector (10);   // 10 zero-initialized ints

//   // assign some values:
//   for (unsigned i=0; i<myvector.size(); i++)
//     myvector.at(i)=i;

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector.at(i);
//   std::cout << '\n';

  return 0;
}*/

    // std::vector<Test> t;
    // t.push_back(Test());
    // t.push_back(Test());
    // t.push_back(Test());

    // ft::vector<Test> vvec;
    // vvec.push_back(Test());
    // vvec.push_back(Test());
    // vvec.push_back(Test());
    // std::cout << "END" << std::endl;
    // return 0;
    // Test t;
    // std::cout << "[" << t.a << ", " << t.b << ", " << t.c << "]" << std::endl;
//     std::vector<int> vec_; //accede a vector dans le namespace ft pour la variable vec
//     vec_.push_back(3);

//     ft::vector<int> vec; //accede a vector dans le namespace ft pour la variable vec
//     vec.push_back(3);

//     std::cout << "max_size" << std::endl;
//     std::cout << "Maximum size of a std::vector is " << vec.max_size() << '\n';
//     std::cout << "original : max_size" << std::endl;

//     std::cout << "Maximum size of a std::vector is " << vec_.max_size() << '\n';
//     std::cout << vec[0] << std::endl;
//     std::cout << vec.size() << std::endl;
//     vec.push_back(4);
//     vec.push_back(5);
//     vec.push_back(43);
//     vec.push_back(46);
//     vec.push_back(49);
//     std::cout << vec[5] << std::endl;
//     std::cout << vec.size() << std::endl;
//     size_t i(0);
//     while (i < vec.size())
//         std::cout << vec[i++] << std::endl;
//     std::cout << vec.size() << std::endl;
//         vec.pop_back();
//     i = 0;
//     while (i < vec.size())
//         std::cout << vec[i++] << std::endl;
//     std::cout << vec.size() << std::endl;
//     std::cout << vec.size() << std::endl;
//     std::cout << vec[5] << std::endl;
//     std::cout << "max_size" << std::endl;
//     std::cout << vec.max_size() << std::endl;
//     std::cout << "original : max_size" << std::endl;

//  std::cout << "Maximum size of a std::vector is " << vec.max_size() << '\n';
//     std::cout << "empty" << std::endl;

//     std::cout << vec.empty() << std::endl;
//     std::cout << "clear" << std::endl;

//     vec.clear();
//     std::cout << vec.size() << std::endl;
//     std::cout << "empty" << std::endl;

//     std::cout << vec.empty() << std::endl;
//     vec.clear();
//     vec_.clear();
//     std::cout << "empty vec :" << vec.empty() << "empty vec_" << vec_.empty() << std::endl;
//     vec.push_back(2);
//     vec.push_back(4);
//     vec.push_back(6);


//     ft::vector<int> vec2; //accede a vector dans le namespace ft pour la variable vec
//     vec2.push_back(1);
//     vec2.push_back(3);
//     vec2.push_back(5);
//     vec2.swap(vec);
//     std::cout << vec[0] << std::endl;
//     std::cout << vec[1] << std::endl;
//     std::cout << vec[2] << std::endl;
//     std::cout << vec2[0] << std::endl;
//     std::cout << vec2[1] << std::endl;
//     std::cout << vec2[2] << std::endl;

/*reverse it
std::vector<int> vec { 1, 2, 3, 4, 5 };
std::reverse_iterator<std::vector<int>::iterator> rit(vec.end());
std::reverse_iterator<std::vector<int>::iterator> rend(vec.begin());
for (; rit != rend; ++rit) {
    std::cout << *rit << " ";
}
*/
