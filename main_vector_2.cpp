#include "vector.hpp"
#include <iostream>
#include <iostream>
#include <locale>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;
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

//#define TESTED_TYPE foo<int>
#include "vector.hpp"
/*#include <sstream>
namespace ft
{
	std::string	to_string(size_t n)
	{
		std::stringstream tmp;
		tmp << n;
		return tmp.str();
	}
}*/
void	print_vector(ft::vector<int> &test)
{
	typename ft::vector<int>::iterator		beg = test.begin();
	typename ft::vector<int>::iterator		end = test.end();
	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
	for (typename ft::vector<int>::iterator it = beg; it != end; it++)
	{
		std::cout << *it << " ";
		if (((it - beg) % 10 == 9) && it > beg)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{


	std::cout << std::endl << "INSERT TESTS" << std::endl;
	std::vector<int> test_std(1, 1);
	std::vector<int> test2_std(5, 5);

	std::cout << "VECTOR.CAPACITY_1" << test_std.capacity() <<std::endl;
	test_std.insert(test_std.begin(), 200, 12);
	//print_vector(test_std);

	std::cout << "VECTOR.CAPACITY_2" << test_std.capacity() <<std::endl;
	test_std.insert(test_std.begin() + 12, 200, 30);
	//print_vector(test_std);


	std::cout << std::endl << "INSERT TESTS" << std::endl;
	ft::vector<int> test(1, 1);
	ft::vector<int> test2(5, 5);

	test.insert(test.begin(), 200, 12);
	print_vector(test);
	test.insert(test.begin() + 12, 200, 30);
	print_vector(test);
	/*test.insert(test.end(), 12, 50);
	print_vector(test);*/


	// std::cout << std::endl << "RESIZE TESTS" << std::endl;
	// ft::vector<int> test(12, 12);

	// test.resize(72);
	// std::cout << "s1: " << test.size() << ", c1: " << test.capacity() << std::endl;
	// test.resize(100);
	// std::cout << "s2: " << test.size() << ", c2: " << test.capacity() << std::endl;




	/*test.resize(4170);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(171, 12);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(62);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;*/
}
	
	// //INSERT RANGE
	// std::cout << "\nINSERT RANGE\n";
	// ft::vector<std::string>	insert_bis;
	// for (size_t i = 0; i < 7; i++)
	// 	insert_bis.push_back(ft::to_string(3 * i));
	// for (size_t i = 0; i < insert_bis.size(); i++)
	// 	std::cout << insert_bis[i] << ' ';
	// std::cout << '\n';

	// insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	// for (size_t i = 0; i < insert_bis.size(); i++)
	// 	std::cout << insert_bis[i] << ' ';
	// std::cout << '\n';


// 	//ERASE
// 	std::cout << "\nERASE\n";
// 	ft::vector<std::string>	erase_in_me;
// 	for (size_t i = 0; i < 15; i++)
// 		erase_in_me.push_back(ft::to_string(2 * i));
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 	{
// //		if (erase_in_me[i] < 10)
// //			std::cout << ' ';
// 		std::cout << erase_in_me.at(i) << ' ';
// 	}
// 	std::cout << '\n';

// 	erase_in_me.erase(erase_in_me.begin() + 7);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 	{
// //		if (erase_in_me[i] < 10)
// //			std::cout << ' ';
// 		std::cout << erase_in_me.at(i) << ' ';
// 	}
// 	std::cout << '\n';

// 	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 	{
// //		if (erase_in_me[i] < 10)
// //			std::cout << ' ';
// 		std::cout << erase_in_me.at(i) << ' ';
// 	}
// 	std::cout << '\n';

	// //SWAP
	// std::cout << "\nSWAP\n";
	// BOB.swap(MIKE);
	// /*
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	// */
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// 	std::cout << MIKE[i] << ' ';
	// std::cout << std::endl;

	// MIKE.swap(JOHN);
	// /*
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	// */
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// 	std::cout << MIKE[i] << ' ';
	// std::cout << std::endl;

	// //CLEAR
	// std::cout << "\nCLEAR\n";
	// JOHN.clear();
	// MIKE.clear();
	// /*
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	// */
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// 	std::cout << MIKE[i] << ' ';
	// std::cout << std::endl;

	// //NON MEMBER Functions
	// std::cout << "\nNON MEMBER functions\n";
	// swap(BOB, MIKE);
	// /*
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	// */
	// std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	// if (JOHN.capacity() >= JOHN.size())
	// 	std::cout << "Capacity of JOHN is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	// std::cout << "Size of BOB " << BOB.size() << std::endl;
	// if (BOB.capacity() >= BOB.size())
	// 	std::cout << "Capacity of BOB is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	// std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	// if (MIKE.capacity() >= MIKE.size())
	// 	std::cout << "Capacity of MIKE is sufficient\n";
	// else
	// 	std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	// for (size_t i = 0; i < MIKE.size(); i++)
	// 	std::cout << MIKE[i] << ' ';
	// std::cout << std::endl;
	
	// //RELATIONAL OPERATORS
	// std::cout << "\nRELATIONAL OPERATORS\n";
	// ft::vector<std::string> MIKE_2(MIKE);
	// std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	// std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	// ft::vector<std::string> real;
	// real.assign(5, "foo");
	// for (ft::vector<std::string>::iterator it = real.begin(); it != real.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << '\n';

	// std::cout << std::endl;
//	return 0;
//}
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