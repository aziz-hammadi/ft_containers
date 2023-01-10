#ifndef __ITERATOR_TRAIT_HPP__
#define __ITERATOR_TRAIT_HPP__

#include <cstddef>
#include <iterator>

namespace ft
{
    template<class Iter>
	class iterator_traits //creer une class iterator trait
	{
		public :
		typedef typename Iter::difference_type	difference_type; //typename necessaire car on accede a un éléement (difference_type) qui dépend d'un template (Iter)
		typedef typename Iter::value_type		value_type;
		typedef typename Iter::pointer			pointer;
		typedef typename Iter::reference		reference;
		typedef typename Iter::iterator_category iterator_category; 
	};
	template <class T>
	class iterator_traits <T*>
	{
		public:
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef	T*								pointer;
		typedef T&								reference;
		typedef	std::random_access_iterator_tag	iterator_category;							
	};
	template <class T>
	class iterator_traits <const T*>
	{
		public:
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef	const T*						pointer;
		typedef const T&						reference;
		typedef	std::random_access_iterator_tag	iterator_category;							
	};
}
#endif