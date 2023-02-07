#ifndef __ITERATOR_VECTOR_HPP__
# define __ITERATOR_VECTOR_HPP__

#include "iterator_traits.hpp"

namespace ft
{
	template<class T>
	class reverse_iterator
	{
	public:
		typedef T 													iterator_type;
		typedef	typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef	typename ft::iterator_traits<T>::reference			reference;
		typedef	typename ft::iterator_traits<T>::const_reference	const_reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef	typename ft::iterator_traits<T>::value_type			value_type;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

	protected:
		T current;
		//construtors
		/*default*/
		reverse_iterator() : current(NULL){};
		/*initialisation*/
		explicit reverse_iterator(iterator_type it) : current(it){}
		/*copy*/
		template <class Itr>
		reverse_iterator(const reverse_iterator<Itr>& rev_it) : current(rev_it.base()){};

		//assign
		template<class Itr>
		reverse_iterator& operator=(const reverse_iterator<Itr>& rev_it)
		{
			current = rev_it.current;
			return(*this);
		}

		//base
		iterator_type base() const
		{
			return(current);
		}

		//operator overloads
		reverse_iterator operator*() const
		{
			iterator_type tmp = current;
			return (*(--tmp));
		}
		reverse_iterator  operator+(difference_type n) const
		{
			return (current - n);
		}
		reverse_iterator& operator++(int)
		{
			reverse_iterator tmp = *this;
			**(*this);
			return tmp;
		}
		reverse_iterator& operator++()
		{
			++current;
			return (*this);
		}
		reverse_iterator operator+= (difference_type n)
		{
			current -= n;
			return (*this);
		}
		reverse_iterator operator- (difference_type n) const
		{
			return (current + n);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return tmp;
		}
		reverse_iterator operator--()
		{
			++current;
			return *this;
		}

		reverse_iterator& operator-= (difference_type n) const
		{
			current += n;
			return *this;
		}

		pointer operator->() const
		{
			return &(operator*());
		}
		reference operator[] (difference_type n) const
		{
			return(current[-n - 1]);
		}	
		//reverse_iterator fonction non membres
		template<class Iterator1, class Iterator2>
		friend bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() == rhs.base());
		}
		template<class Iterator1, class Iterator2>
		friend bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() == rhs.base());
		}
		template<class Iterator1, class Iterator2>
		friend bool operator< (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() < rhs.base());
		}
		template<class Iterator1, class Iterator2>
		friend bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() <= rhs.base());
		}
		template<class Iterator1, class Iterator2>
		friend bool operator> (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() > rhs.base());
		}		
		template<class Iterator1, class Iterator2>
		friend bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
		{
			return (lhs.base() >= rhs.base());
		}
		template<class Itr>
		friend reverse_iterator<Itr> operator+(typename reverse_iterator<Itr>::difference_type n, const reverse_iterator<Itr>& it)
		{
			return (it.base() - n);
		}
		template<class Itr>
		friend typename reverse_iterator<Itr>::difference_type operator-(const reverse_iterator<Itr>& lhs, const reverse_iterator<Itr>& rhs)
		{
			return (rhs.base() - lhs.base());
		}
	};

	template<class T>
	class iterator_vector
	{
	public:
		typedef typename ft::iterator_traits<T>::difference_type 	difference_type; //alias
		typedef typename ft::iterator_traits<T>::reference			reference;
		typedef typename ft::iterator_traits<T>::const_reference	const_reference;
		typedef typename ft::iterator_traits<T>::value_type			value_type;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

		//missing typedef for: value_type pointer
		
		iterator_vector()
			: _pointer()
		{}

		explicit iterator_vector(const T &p)    //constructeur iterator en copie 
			: _pointer(p)
		{}

		template <typename Itr>
		iterator_vector(const iterator_vector<Itr> &it)
			: _pointer(it.get_pointer())
		{}

		iterator_vector<T> &operator++()  //operator necessaire insert   //inverse pour reverse iterator 
		{
			++_pointer;
			return *this;
		}

		iterator_vector<T> operator++(int)
		{
			iterator_vector it(*this);
			++_pointer;
			return it;
		}

		iterator_vector<T> &operator--()  //operator necessaire insert   //inverse pour reverse iterator 
		{
			--_pointer;
			return *this;
		}

		iterator_vector<T> operator--(int)
		{
			iterator_vector it(*this);
			--_pointer;
			return it;
		}

		//== a, b
		//!(a._pointer < b._pointer || a._pointer > b._pointer)  ->    a._pointer == b._pointer

		template< class P >
		bool operator==(const iterator_vector<P> &b) const
		{ return !(this->operator<(b) || this->operator>(b)); }

		template< class P >
		bool operator!=(const iterator_vector<P> &b) const
		{ return !(this->operator==(b)); }

		template< class P >
		bool operator>(const iterator_vector<P> &b) const
		{ return (this->get_pointer() > b.get_pointer()); }

		template< class P >
		bool operator<(const iterator_vector<P> &b) const
		{ return (this->get_pointer() < b.get_pointer()); }

		template< class P >
		bool operator>=(const iterator_vector<P> &b) const
		{ return !(this->operator<(b)); }

		template< class P >
		bool operator<=(const iterator_vector<P> &b) const
		{ return !(this->operator>(b)); }

		template <typename Itr, typename Itr2>
		friend difference_type operator-(const iterator_vector<Itr> &a, const iterator_vector<Itr2> &b)
		{ return a._pointer - b._pointer; }

		friend iterator_vector<T> operator+(const iterator_vector<T> &a, const difference_type &b)
		{ return iterator_vector<T>(a._pointer + b); }

		friend iterator_vector<T> operator-(const iterator_vector<T> &a, const difference_type &b)
		{ return iterator_vector<T>(a._pointer - b); }

		friend iterator_vector<T> operator+(const difference_type &a, const iterator_vector<T> &b)
		{ return iterator_vector<T>(a + b._pointer); }

		friend iterator_vector<T> operator-(const difference_type &a, const iterator_vector<T> &b)
		{ return iterator_vector<T>(a - b._pointer); }

		iterator_vector<T> &operator+=(const difference_type &b)
		{
			this->_pointer += b;
			return *this;
		}

		iterator_vector<T> &operator-=(const difference_type &b)
		{
			this->_pointer -= b;
			return *this;
		}

		reference operator*()
		{
			return *this->_pointer; //dereferencer le pointeur
		}

		const_reference operator*() const
		{
			return *this->_pointer; //dereferencer le pointeur
		}

		T operator->()
		{
			return this->_pointer;
		}

		const T operator->() const
		{
			return this->_pointer;
		}

		reference operator[](const std::ptrdiff_t &n)
		{
			return this->_pointer[n];
		}

		const_reference operator[](const std::ptrdiff_t &n) const
		{
			return this->_pointer[n];
		}

		T get_pointer()
		{
			return (_pointer);
		}

		const T get_pointer() const
		{
			return (_pointer);
		}

		

	private :
		T	_pointer;
	};
    //implementer 
    // difference_type + iterator_vector<T>

    // difference_type - iterator_vector<T>
}
#endif