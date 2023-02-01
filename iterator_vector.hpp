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
		//missing typedef for: value_type pointer
		
		iterator_vector(T p)    //constructeur iterator en copie 
			: _pointer(p)
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
			-_pointer;
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


		bool operator==(const iterator_vector<T> &b)
		{
			//return (!(this->_pointer < b._pointer || this->_pointer > b._pointer));
			// return (a._pointer == b._pointer);
			return !(this->operator<(b) || this->operator>(b));
		}
		bool operator!=(const iterator_vector<T> &b)
		{
			//return (a._pointer != b._pointer);
			return !(this->operator==(b));
		}
		bool operator>(const iterator_vector<T> &b)
		{
			return (this->_pointer > b._pointer);
		}
		bool operator<(const iterator_vector<T> &b)
		{
			return (this->_pointer < b._pointer);
		}
		bool operator>=(const iterator_vector<T> &b)
		{
			return !(this->operator<(b));
		}
		bool operator<=(const iterator_vector<T> &b)
		{
			return !(this->operator>=(b));
		}

		difference_type operator-(const iterator_vector<T> &b)
		{
			return this->_pointer - b._pointer;
		}

		iterator_vector<T> operator+(const difference_type &b)
		{
			return iterator_vector<T>(this->_pointer + b);
		}

		iterator_vector<T> operator-(const difference_type &b)
		{
			return iterator_vector<T>(this->_pointer - b);
		}

		reference operator*()
		{
			return *this->_pointer; //dereferencer le pointeur
		}

		const_reference operator*() const
		{
			return *this->_pointer; //dereferencer le pointeur
		}

		T pointer()
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