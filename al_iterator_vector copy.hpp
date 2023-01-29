	template<class Iter>
	class reverse_iterator : public iterator	<typename iterator_traits<Iter>::iterator_category,
												typename iterator_traits<Iter>::value_type,
												typename iterator_traits<Iter>::difference_type,
												typename iterator_traits<Iter>::pointer,
												typename iterator_traits<Iter>::reference>
	{
	protected:
		//		Member Objects
		Iter current;
	public:
		//		Member Types
		typedef Iter											iterator_type;
		typedef typename iterator_traits<Iter>::difference_type	difference_type;
		typedef typename iterator_traits<Iter>::reference		reference;
		typedef typename iterator_traits<Iter>::pointer			pointer;

		//		Constructors
		reverse_iterator() : current(){}
		explicit reverse_iterator(iterator_type x) : current(x){}
		template<class U>
		reverse_iterator(const reverse_iterator<U>& other) : current(other.current){}

		//		Assignement Operator Overload
		template<class U>
		reverse_iterator& operator=(const reverse_iterator<U>& other){current = other.current; return (*this);}

		//		Member functions
		iterator_type base() const {return(current);}

		//		Operator Overloads
		reference operator*() const {iterator_type tmp = current; return *--tmp;}
		pointer operator->() const {return &(operator*());}
		reference operator[](difference_type n) const {return(current[-n - 1]);}
		reverse_iterator& operator++(){--current; return(*this);}
		reverse_iterator& operator--(){++current; return(*this);}
		reverse_iterator operator++(int){reverse_iterator tmp = *this; --current; return (tmp);}
		reverse_iterator operator--(int){reverse_iterator tmp = *this; ++current; return (tmp);}
		reverse_iterator operator+(difference_type n) const {return (current - n);}
		reverse_iterator operator-(difference_type n) const {return (current + n);}
		reverse_iterator& operator+=(difference_type n) const {current -= n; return (*this);}
		reverse_iterator& operator-=(difference_type n) const {current += n; return (*this);}
	};
	//		reverse_iterator Non Members Functions
	template<class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() == rhs.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() == rhs.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator< (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() < rhs.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() <= rhs.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator> (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() > rhs.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs){
		return (lhs.base() >= rhs.base());
	}
	template<class Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it){
		return (it.base() - n);
	}
	template<class Iter>
	typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs){
		return (rhs.base() - lhs.base());
	}