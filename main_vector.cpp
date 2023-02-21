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

#define TESTED_TYPE foo<int>

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(vct.rbegin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite(vct.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);
	printSize(vct, 1);

	it = vct.rbegin();
	ite = vct.rbegin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	return (0);
}
