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

int		main(void)
{
	ft::vector<int> vec(10, 1);
	ft::vector<int>::iterator cit(vec.begin());
	ft::vector<int>::const_iterator it(cit);

	std::cout << "Vallll: " << *it << std::endl;

	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct;
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

	// TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

	// TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);

	// /* error expected
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit_(crit);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit2(cit);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it2(rit);
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit2(crit);
	// */

	// std::cout << "OK" << std::endl;
	return (0);
}
