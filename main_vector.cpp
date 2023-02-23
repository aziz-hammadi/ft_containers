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
//#include "common.hpp"

#define TESTED_TYPE foo<int>
#include "vector.hpp"
/*
int		main(void)
{
	ft::vector<int> a(5);

	a.insert(a.begin(), 9, 7);
	std::cout << "a.size :" << a.size() << std::endl;
	// std::cout << "a.size :" << a.max_size() << std::endl;

	std::cout << "a.capacity :" << a.capacity()  << std::endl;

	a.resize(3055);

	std::cout << "a.size :" << a.size() << std::endl;
	std::cout << "a.capacity :" << a.capacity()  << std::endl;
}
*/
int		main(void)
{
  std::vector<int>::size_type sz;
  std::vector<int> bar;
  std::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  sz = bar.capacity();
  bar.reserve(25);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  	std::cout<<"bar.size_1 :" << bar.size() <<std::endl;
  	std::cout<<"bar.cap :" << bar.capacity() <<std::endl;
	  	//std::cout<<"bar.res :" << bar.reserve() <<std::endl;

  for (int i=0; i<100; ++i) {
    bar.push_back(i);
	sz = bar.capacity();
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
	std::cout<<"bar.size_2 :" << bar.size() <<std::endl;
}
/*
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
*/
