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
#include "vector.hpp"
// template <typename T>
// struct template_test
// {
//     typedef T type;
// };


int		main(void)
{
	ft::vector<int> vec(5);
	for (size_t i = 0; i < vec)
	// vec.insert(vec.begin(), )
	return 0;
    // TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	// const int cut = 3;

	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	vct[i] = (vct.size() - i) * 7;
	// printSize(vct);

	// vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	// printSize(vct2);
	// vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	// printSize(vct2);
	// vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	// printSize(vct2);

	// std::cout << "insert return:" << std::endl;

	// std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	// std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	// std::cout << "----------------------------------------" << std::endl;

	// printSize(vct2);
	return (0);
}
