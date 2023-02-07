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
#include "common.hpp"

#define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7

	return (0);
}
