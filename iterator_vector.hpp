#ifndef __ITERATOR_VECTOR_HPP__
# define __ITERATOR_VECTOR_HPP__

#include "iterator_traits.hpp"
#include "enable_if.hpp"

namespace ft
{
	template <class T>
	struct remove_const { typedef T type; };

	template <class T>
	struct remove_const<const T> { typedef T type; };

	template <class T>
	struct is_const { static const bool value = false; };

	template <class T>
	struct is_const<const T> { static const bool value = true; };

	template <class T>
	class base_iterator_vector
	{
	public:
		typedef T 													iterator_type;
		typedef	typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef	typename ft::iterator_traits<T>::reference			reference;
		typedef	typename ft::iterator_traits<T>::const_reference	const_reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef	typename ft::iterator_traits<T>::value_type			value_type;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

	public:

		explicit base_iterator_vector(const T &t = T())
			: _current(t)
		{}

		template <typename Itr>
		base_iterator_vector(const base_iterator_vector<Itr> &it)
			: _current(it.base())
		{}

		// template <typename Itr>
		// base_iterator_vector(const base_iterator_vector<T> &it)
		// 	: _current(it.base())
		// {}

		// template <class Itr>
		// base_iterator_vector(const typename ft::enable_if<ft::is_const<T>::value && !ft::is_const<Itr>::value, base_iterator_vector<Itr> >::type &it)
		// 	: _current(it.base())
		// {}

		template <typename Itr>
		base_iterator_vector<T> &operator=(const base_iterator_vector<Itr> &it)
		{
			this->_current = it->base();
			return *this;
		}

		virtual reference operator[](const std::ptrdiff_t &n)
		{ return this->_current[n]; }

		virtual const_reference operator[](const std::ptrdiff_t &n) const
		{ return this->_current[n]; }

		reference operator*()
		{ return *this->_current; } //dereferencer le pointeur

		const_reference operator*() const
		{ return *this->_current; } //dereferencer le pointeur

		T operator->()
		{ return this->_current; }

		const T operator->() const
		{ return this->_current; }

		T base() { return this->_current; }
		const T base() const { return this->_current; }

	protected:
		T _current;
	};

	// template<class T>
	// class reverse_iterator: public ft::base_iterator_vector<T>
	// {
	// public:
	// 	typedef T 													iterator_type;
	// 	typedef	typename ft::iterator_traits<T>::difference_type	difference_type;
	// 	typedef	typename ft::iterator_traits<T>::reference			reference;
	// 	typedef	typename ft::iterator_traits<T>::const_reference	const_reference;
	// 	typedef typename ft::iterator_traits<T>::pointer			pointer;
	// 	typedef	typename ft::iterator_traits<T>::value_type			value_type;
	// 	typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
	// 	//construtors
	// 	/*default*/
	// 	// reverse_iterator() : this->_current(NULL){};
	// 	/*initialisation*/
	// 	// explicit reverse_iterator(iterator_type it) : this->_current(it){}
	// 	/*copy*/
	// 	// template <class Itr>
	// 	// reverse_iterator(const reverse_iterator<Itr>& rev_it) : this->_current(rev_it.base()){};

	// 	//assign
	// 	// template<class Itr>
	// 	// reverse_iterator& operator=(const reverse_iterator<Itr>& rev_it)
	// 	// {
	// 	// 	this->_current = rev_it.this->_current;
	// 	// 	return(*this);
	// 	// }

	// 	//base
	// 	// iterator_type base() const
	// 	// {
	// 	// 	return(this->_current);
	// 	// }

	// 	//operator overloads
	// 	// reverse_iterator<T> operator*() const
	// 	// {
	// 	// 	iterator_type tmp = this->_current;
	// 	// 	return (*(--tmp));
	// 	// }

	// 	explicit reverse_iterator(const T &t = T())
	// 		: base_iterator_vector<T>(t)
	// 	{}

	// 	template <typename Itr>
	// 	reverse_iterator(const base_iterator_vector<Itr> &it)
	// 		: base_iterator_vector<T>(it)
	// 	{}

	// 	reverse_iterator<T>  operator+(difference_type n) const
	// 	{
	// 		return (reverse_iterator<T>(this->base() - n));
	// 	}
	// 	reverse_iterator<T> operator++(int)
	// 	{
			
	// 		reverse_iterator<T> tmp = *this;
	// 		++(*this);
	// 		return tmp;
	// 	}
	// 	reverse_iterator<T>& operator++()
	// 	{
	// 		--this->_current;
	// 		return (*this);
	// 	}
	// 	reverse_iterator<T> operator+= (difference_type n)
	// 	{
	// 		this->_current -= n;
	// 		return (*this);
	// 	}
	// 	reverse_iterator<T> operator- (difference_type n) const
	// 	{
	// 		return (reverse_iterator<T>(this->_current + n));
	// 	}
	// 	reverse_iterator<T> operator--(int)
	// 	{
	// 		reverse_iterator<T> tmp = *this;
	// 		--(*this);
	// 		return tmp;
	// 	}
	// 	reverse_iterator<T> operator--()
	// 	{
	// 		++this->_current;
	// 		return *this;
	// 	}

	// 	reverse_iterator<T>& operator-= (const difference_type &n)
	// 	{
	// 		this->_current += n;
	// 		return *this;
	// 	}

	// 	// pointer operator->() const
	// 	// {
	// 	// 	return &(operator*());
	// 	// }
	// 	// reference operator[] (difference_type n) const
	// 	// {
	// 	// 	return(this->_current[-n - 1]);
	// 	// }	
	// 	//reverse_iterator<T> fonction non membres
	// 	template<class Iterator1>
	// 	friend bool operator==(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
	// 	{
	// 		return (lhs.base() == rhs.base());
	// 	}

	// 	friend bool operator==(const ft::reverse_iterator<T>& lhs, const T& rhs)
	// 	{
	// 		return (lhs.base() == rhs);
	// 	}
	// 	template<class Iterator1>
	// 	friend bool operator!=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
	// 	{
	// 		return (lhs.base() != rhs.base());
	// 	}

	// 	friend bool operator!=(const ft::reverse_iterator<T>& lhs, const T& rhs)
	// 	{
	// 		return (lhs.base() != rhs);
	// 	}
	// 	template<class Iterator1>
	// 	friend bool operator< (const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
	// 	{
	// 		return (lhs.base() > rhs.base());
	// 	}

	// 	friend bool operator< (const ft::reverse_iterator<T>& lhs, const T& rhs)
	// 	{
	// 		return (lhs.base() > rhs);
	// 	}
	// 	template<class Iterator1>
	// 	friend bool operator<=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
	// 	{
	// 		return (lhs.base() >= rhs.base());
	// 	}

	// 	friend bool operator<=(const ft::reverse_iterator<T>& lhs, const T& rhs)
	// 	{
	// 		return (lhs.base() >= rhs);
	// 	}
	// 	template<class Iterator1>
	// 	friend bool operator> (const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
	// 	{
	// 		return (lhs.base() < rhs.base());
	// 	}		

	// 	template<class Iterator1>
	// 	friend bool operator>=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
	// 	{
	// 		return (lhs.base() <= rhs.base());
	// 	}

	// 	friend bool operator>=(const ft::reverse_iterator<T>& lhs, const T& rhs)
	// 	{
	// 		return (lhs.base() <= rhs);
	// 	}
	// 	// template<class Itr>
	// 	friend reverse_iterator<T> operator+(difference_type n, const reverse_iterator<T>& it)
	// 	{
	// 		return (reverse_iterator<T>(it.base() - n));
	// 	}

	// 	template<class Iterator1>
	// 	friend difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<Iterator1>& rhs)
	// 	{
	// 		return (rhs.base() - lhs.base());
	// 	}
	// };

	template<class T>
	class iterator_vector: public ft::base_iterator_vector<T>
	{
	public:
		typedef T 													iterator_type;
		typedef	typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef	typename ft::iterator_traits<T>::reference			reference;
		typedef	typename ft::iterator_traits<T>::const_reference	const_reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef	typename ft::iterator_traits<T>::value_type			value_type;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		// typedef typename ft::iterator_traits<T>::difference_type 	difference_type; //alias
		// typedef typename ft::iterator_traits<T>::reference			reference;
		// typedef typename ft::iterator_traits<T>::const_reference	const_reference;
		// typedef typename ft::iterator_traits<T>::value_type			value_type;
		// typedef typename ft::iterator_traits<T>::pointer			pointer;
		// typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;

		//missing typedef for: value_type pointer
		
		// iterator_vector()
		// 	: this->base()
		// {}

		// explicit iterator_vector(const T &p)    //constructeur iterator en copie 
		// 	: this->_current(p)
		// {}

		// template <typename Itr>
		// iterator_vector(const iterator_vector<Itr> &it)
		// 	: this->_current(it.getthis->base())
		// {}

		explicit iterator_vector(const T &t = T())
			: base_iterator_vector<T>(t)
		{}

		template <typename Itr>
		iterator_vector(const base_iterator_vector<Itr> &it)
			: base_iterator_vector<T>(it)
		{}

		iterator_vector<T> &operator++()  //operator necessaire insert   //inverse pour reverse iterator 
		{
			++this->_current;
			return *this;
		}

		iterator_vector<T> operator++(int)
		{
			iterator_vector it(*this);
			++this->_current;
			return it;
		}

		iterator_vector<T> &operator--()  //operator necessaire insert   //inverse pour reverse iterator 
		{
			--this->_current;
			return *this;
		}

		iterator_vector<T> operator--(int)
		{
			iterator_vector it(*this);
			--this->_current;
			return it;
		}

		//== a, b
		//!(a.this->_current < b.this->_current || a.this->_current > b.this->_current)  ->    a.this->_current == b.this->_current

		template< class P >
		bool operator==(const iterator_vector<P> &b) const
		{ return !(this->operator<(b) || this->operator>(b)); }

		bool operator==(const T &b) const
		{ return !(this->operator<(b) || this->operator>(b)); }

		template< class P >
		bool operator!=(const iterator_vector<P> &b) const
		{ return !(this->operator==(b)); }

		bool operator!=(const T &b) const
		{ return !(this->operator==(b)); }

		template< class P >
		bool operator>(const iterator_vector<P> &b) const
		{ return (this->base() > b.base()); }

		bool operator>(const T &b) const
		{ return (this->base() > b); }

		template< class P >
		bool operator<(const iterator_vector<P> &b) const
		{ return (this->base() < b.base()); }

		bool operator<(const T &b)  const
		{ return (this->base() < b); }

		template< class P >
		bool operator>=(const iterator_vector<P> &b) const
		{ return !(this->operator<(b)); }

		bool operator>=(const T &b) const
		{ return !(this->operator<(b)); }

		template< class P >
		bool operator<=(const iterator_vector<P> &b) const
		{ return !(this->operator>(b)); }

		bool operator<=(const T &b) const
		{ return !(this->operator>(b)); }

		template <typename Itr>
		friend difference_type operator-(const iterator_vector<Itr> &a, const iterator_vector<T> &b)
		{ return a.base() - b.base(); }

		friend iterator_vector<T> operator+(const iterator_vector<T> &a, const difference_type &b)
		{ return iterator_vector<T>(a._current + b); }

		friend iterator_vector<T> operator-(const iterator_vector<T> &a, const difference_type &b)
		{ return iterator_vector<T>(a._current - b); }

		friend iterator_vector<T> operator+(const difference_type &a, const iterator_vector<T> &b)
		{ return iterator_vector<T>(a + b._current); }

		friend iterator_vector<T> operator-(const difference_type &a, const iterator_vector<T> &b)
		{ return iterator_vector<T>(a - b._current); }

		iterator_vector<T> &operator+=(const difference_type &b)
		{
			this->_current += b;
			return *this;
		}

		iterator_vector<T> &operator-=(const difference_type &b)
		{
			this->_current -= b;
			return *this;
		}

		// reference operator*()
		// {
		// 	return *this->_current; //dereferencer le pointeur
		// }

		// const_reference operator*() const
		// {
		// 	return *this->_current; //dereferencer le pointeur
		// }

		// T operator->()
		// {
		// 	return this->_current;
		// }

		// const T operator->() const
		// {
		// 	return this->_current;
		// }

		// reference operator[](const std::ptrdiff_t &n)
		// {
		// 	return this->_current[n];
		// }

		// const_reference operator[](const std::ptrdiff_t &n) const
		// {
		// 	return this->_current[n];
		// }

		// T getthis->base()
		// {
		// 	return (this->_current);
		// }

		// const T getthis->base() const
		// {
		// 	return (this->_current);
		// }

	// private :
	// 	T	_pointer;
	};
    //implementer 
    // difference_type + iterator_vector<T>

    // difference_type - iterator_vector<T>

	
	template<class T>
	class reverse_iterator: public ft::base_iterator_vector<T>
	{
	public:
		typedef T 													iterator_type;
		typedef	typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef	typename ft::iterator_traits<T>::reference			reference;
		typedef	typename ft::iterator_traits<T>::const_reference	const_reference;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef	typename ft::iterator_traits<T>::value_type			value_type;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		//construtors
		/*default*/
		// reverse_iterator() : this->_current(NULL){};
		/*initialisation*/
		// explicit reverse_iterator(iterator_type it) : this->_current(it){}
		/*copy*/
		// template <class Itr>
		// reverse_iterator(const reverse_iterator<Itr>& rev_it) : this->_current(rev_it.base()){};

		//assign
		// template<class Itr>
		// reverse_iterator& operator=(const reverse_iterator<Itr>& rev_it)
		// {
		// 	this->_current = rev_it.this->_current;
		// 	return(*this);
		// }

		//base
		// iterator_type base() const
		// {
		// 	return(this->_current);
		// }

		//operator overloads
		// reverse_iterator<T> operator*() const
		// {
		// 	iterator_type tmp = this->_current;
		// 	return (*(--tmp));
		// }

		explicit reverse_iterator(const T &t = T())
			: base_iterator_vector<T>(t)
		{}

		template <typename Itr>
		reverse_iterator(const base_iterator_vector<Itr> &it)
			: base_iterator_vector<T>(it)
		{
			// std::cout << "REVERSE !" << std::endl;
			// this->_current = it.base();
		}

		// template <typename Itr>
		// reverse_iterator(const iterator_vector<Itr> &it)
		// {
		// 	this->_current = it.base() - 1;
		// }


		reference operator[](const std::ptrdiff_t &n)
		{ return *(this->_current - n); }

		const_reference operator[](const std::ptrdiff_t &n) const
		{ return *(this->_current - n); }

		reverse_iterator<T>  operator+(const difference_type &n) const
		{
			return (reverse_iterator<T>(this->base() - n));
		}
		reverse_iterator<T> operator++(int)
		{
			
			reverse_iterator<T> tmp = *this;
			++(*this);
			return tmp;
		}
		reverse_iterator<T>& operator++()
		{
			--this->_current;
			return (*this);
		}
		reverse_iterator<T> &operator+= (const difference_type &n)
		{
			this->_current -= n;
			return (*this);
		}
		reverse_iterator<T> operator- (const difference_type &n) const
		{
			return (reverse_iterator<T>(this->base() + n));
		}
		reverse_iterator<T> operator--(int)
		{
			reverse_iterator<T> tmp = *this;
			--(*this);
			return tmp;
		}
		reverse_iterator<T> &operator--()
		{
			++this->_current;
			return *this;
		}

		//reference operator[](const std::ptrdiff_t &n);
		// reference operator*() const
		// { 
		// 	iterator_type tmp(this->_current);
		// 	return(*--tmp); }
		/*
		reverse_iterator<T> operator*(int)
		{
			reverse_iterator<T> tmp = *(this);
			*--tmp;
			return tmp;
		}*/

		reverse_iterator<T>& operator-= (const difference_type &n)
		{
			this->_current += n;
			return *this;
		}

		friend reverse_iterator<T> operator+(const difference_type &n, const reverse_iterator<T>& it)
		{
			return (reverse_iterator<T>(it.base() - n));
		}

		friend reverse_iterator<T> operator-(const difference_type &n, const reverse_iterator<T>& it)
		{
			return (reverse_iterator<T>(it.base() + n));
		}

		template<class Iterator1>
		friend difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<Iterator1>& rhs)
		{
			return (rhs.base() - lhs.base());
		}
		// pointer operator->() const
		// {
		// 	return &(operator*());
		// }
		// reference operator[] (difference_type n) const
		// {
		// 	return(this->_current[-n - 1]);
		// }	
		//reverse_iterator<T> fonction non membres
		template<class Iterator1>
		friend bool operator==(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
		{
			return (lhs.base() == rhs.base());
		}

		friend bool operator==(const ft::reverse_iterator<T>& lhs, const T& rhs)
		{
			return (lhs.base() == rhs);
		}
		template<class Iterator1>
		friend bool operator!=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
		{
			return (lhs.base() != rhs.base());
		}

		friend bool operator!=(const ft::reverse_iterator<T>& lhs, const T& rhs)
		{
			return (lhs.base() != rhs);
		}
		template<class Iterator1>
		friend bool operator< (const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

		friend bool operator< (const ft::reverse_iterator<T>& lhs, const T& rhs)
		{
			return (lhs.base() > rhs);
		}
		template<class Iterator1>
		friend bool operator<=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
		{
			return (lhs.base() >= rhs.base());
		}

		friend bool operator<=(const ft::reverse_iterator<T>& lhs, const T& rhs)
		{
			return (lhs.base() >= rhs);
		}
		template<class Iterator1>
		friend bool operator> (const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
		{
			return (lhs.base() < rhs.base());
		}		

		template<class Iterator1>
		friend bool operator>=(const ft::reverse_iterator<T>& lhs, const ft::reverse_iterator<Iterator1>& rhs)
		{
			return (lhs.base() <= rhs.base());
		}

		friend bool operator>=(const ft::reverse_iterator<T>& lhs, const T& rhs)
		{
			return (lhs.base() <= rhs);
		}
		// template<class Itr>
	};
}
#endif