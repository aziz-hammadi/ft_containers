#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <cstddef>
# include <memory>
# include <iterator>
# include <algorithm>
# include <iostream>
# include <limits>
# include "iterator_vector.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include "lexicographical.hpp"
//faire insert et delete max size /OK! (return ) (element acces) front back data (capacity) empty size//OK max_size (modifier)//Ok pop_back//ok void pop_back 
//element acces, tout element acces 
//insert c compliquer penser a iterator
//faire constructeur pas copie 
//reserve (= push_back si capacity est plus grande que la valeur donnee, si cest plus petit alors resize donc push back dans un nouveau tableau que l'on alloue a la capacity donner) 
//at (element acces) verifie sstd::iterator_traitsi tu es pas en dehors verifie si pos < max_size (1h38)
//tout avec operator on fait pas 
//pour le moment itinerator on fait pas
namespace ft
{
    template<class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T	value_type;
		typedef ft::iterator_vector<T *>		iterator;
		typedef ft::iterator_vector<const T *>	const_iterator;
		typedef	typename	Alloc::reference reference;
		typedef	typename	Alloc::const_reference const_reference;
		typedef	typename	ft::reverse_iterator<T *> reverse_iterator;
		typedef	typename	ft::reverse_iterator<const T *> const_reverse_iterator;
		typedef	Alloc							allocator_type; //pas besoin de typemane car on essai pas d'acceder a qqchose qui dépend d'un template
		typedef	std::size_t						size_type;
		typedef	typename Alloc::pointer			pointer;
		typedef typename Alloc::difference_type difference_type;
		
		vector(const allocator_type &alloc = allocator_type())
			: _mem(NULL), _size(0), _capacity(0), _alloc(alloc)
		{
			//std::cout << "CTOR: " << this << " " << std::endl;
			////std::cout << "constructeur" << std::endl;
		}

		vector (const size_type &n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			: _mem(NULL), _size(0), _capacity(0), _alloc(alloc)
		{
			//_size = n;
			//_capacity = _size; 
			//std::cout << "NSERFF: " << " " << std::endl;
			this->assign(n, val);
		}
		
		template <class InputIterator>
		vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type())
			: _mem(NULL), _size(0), _capacity(0), _alloc(alloc)
		{
			//std::cout << "CTOR: " << this << " " << std::endl;
			//std::cout << "NSERFF_2: " << " " << std::endl;
			this->assign(first, last);
		}
	
		//constructeur par copy 
		vector(const ft::vector<T, allocator_type>& x)
			: _mem(NULL), _size(0), _capacity(0), _alloc(x.get_allocator())
		{
			this->assign(x.begin(), x.end());
		}

		//ici destructeur
		~vector()
		{
			clear();
			if (_mem != NULL)
			{
				//std::cout << "DEALLOC dtor: " << this << " " << _mem << std::endl;
				_alloc.deallocate(_mem, _capacity);
			}
			//deallocate _mem[]
		}

		/* fonction membr
		*/
		void assign (const size_type &n, const value_type& val)
		{
			this->impl_resize(n);
			//std::cout << "assign_resize" << std::endl;
			for (size_type i = 0; i < n; ++i)
			{
				_alloc.construct(_mem + i, val); //avec constructeur par copie en associant les valeurs a chaque espace 
			}
			//std::cout << "assign" << std::endl;
		}
		
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
		assign (InputIterator first, InputIterator last) //sur le type de retour
		{
				//ajoute un first et un last a la fin
			size_type i = 0;
			for (InputIterator it = first; it != last; ++it)
				++i;
			this->impl_resize(i); // -> [0, 0, 0, 0, 0] _mem de taille _size, allocation, mais valeur non initialisé
			for (size_t i = 0; first != last; ++i, ++first)
			{
				_alloc.construct(_mem + i, *first); // initialise (construit) chaque élement on associe une valeur		
 			} 
		}
						/*//:::::::::::ITERATOR:::::::::::\\*/
		iterator begin()
		{
			return (iterator(this->_mem));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->_mem));
		}

		iterator end()
		{
			return (iterator(this->_mem + _size));
		}

		const_iterator end() const
		{
			return (const_iterator(this->_mem + _size));
		}

		reverse_iterator	rbegin()
		{
			return (reverse_iterator(this->end()));
		}

		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(this->end()));
		}

		reverse_iterator	rend()
		{
			// return (reverse_iterator((this->begin() - 1).base()));			
			return (reverse_iterator(this->begin()));
		}
		
		const_reverse_iterator	rend() const
		{
			// return (const_reverse_iterator((this->begin() - 1).base()));
			return (reverse_iterator(this->begin()));
		}

						/*//:::::::::::ELEMENT ACCESS:::::::::::\\*/

		reference	at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("ft::vector at out of range");
			return (_mem[n]);
		}
		const_reference	at(size_type n)	const
		{
			if (n >= _size) //
				throw std::out_of_range("ft::vector at out of range");
			return (_mem[n]);
		}
		reference		front()
		{
			return (*this->begin());
		}
		
		const_reference	front() const
		{
			return (*this->begin());
		}
		
		reference		back()
		{
			return (*(this->end() - 1));
		}
		const_reference back() const
		{
			return (*(this->end() - 1));
		}
		//mettre en privee dans la class 
		// int			it_become_pos(iterator position)
		// {
		// 	int posi = 0;
		// 	ft::vector<T, allocator_type>::iterator iterator = this->begin();
		// 	while (iterator != position)
		// 	{
		// 		posi++;
		// 		iterator++;
		// 	}
		// 	return (posi);
		// }

		// iterator	insert(iterator position, const value_type &val)
		// {
		// 	int posi = it_become_pos(position);
		// 	this->insert(position, 1, val);
		// 	return (this->begin()+posi);
		// }

		iterator insert(iterator position, const value_type &val)
		{
			difference_type distance = position - this->begin();
			this->insert(position, 1, val);
			return this->begin() + distance;
		}


		
		void		insert(iterator position, size_type n, const value_type &val)
		{
			// [4, 5, 6, 7, 8]
			// insert 1, n=2, 3
			// [4, 5, 6, 7, 8, 3, 3]
			//std::cout << "CAPAC_DEBUT "<< _capacity <<std::endl;
			difference_type distance = position - this->begin();
			//std::cout << "CAPAC_IMPL_RESIZE "<< _capacity <<std::endl;
			this->impl_resize(_size + n); //_size_actuel + n_insertion
			iterator new_position = this->begin() + distance;
			iterator it = this->end() - 1;
			//std::cout << "CAPAC_201 "<< _capacity <<std::endl;
			while (it > (new_position + (n - 1)))
			{
				_alloc.construct(it.base(), *(it - (n)));
				_alloc.destroy((it - (n)).base());
				--it;
			}

			while (n > 0)
			{
				_alloc.construct(it.base(), val);
				--n;
				--it;
			}
			//std::cout << "CAPAC_402 "<< _capacity <<std::endl;
		}

		template <class InputIterator> 
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
		insert( iterator position, InputIterator first, InputIterator last)
		{
			size_type n = 0;
			for (InputIterator it = first; it != last; ++it)
				++n;

			difference_type distance = position - this->begin();
			std::cout << "Before: " << n << " - " << this->_mem << " - " << this->size() << " - " << this->capacity() << std::endl;
			this->impl_resize(_size + n);
			iterator new_position = this->begin() + distance;
			iterator it = this->end() - 1;
			std::cout << "After: " << n << " - " << this->_mem << " - " << this->size() << " - " << this->capacity() << std::endl;
			while(it > (new_position + (n - 1)))
			{
				std::cout << "Iterating..." << std::endl;
				_alloc.construct(it.base(), *(it - (n)));//VERIFIER it.base() POINTEUR non allouer ? 
				_alloc.destroy((it - (n)).base());
				--it;
			}

			/*
			[4, 5, 6, 7]
			insert 1, 2 au debut ----> [1, 2, 4, 5, 6, 7]
			[1, 2, 4, 5, 6, 7]
			*/

			size_type i = 0;
			while (i < n)
			{
				// _alloc.construct((it - (n - 1) + i).get_pointer(), *first);
				_alloc.construct((new_position + i).base(), *first);
				++i;
				// --it;
				++first;
			}
			//std::cout << "HELLO" << std::endl;
		}
						/*//:::::::::::MODIFIER:::::::::::\\*/

		iterator	erase(iterator position)
		{
			//if ((position >= this->begin()) && ((position + 1) < this->end()) )
			return (erase(position, position + 1));
			/*copie de tmp [begin, positon - 1];
			destroy _mem[position] 
			copie de tmp_2 [positon +1 , end];
			tmp : join tmp + tmp_2; 
			_mem = tmp;
			--_size;*/
		}

		iterator	erase(iterator first, iterator last)
		{
			if (first < this->begin() || first > last || last > this->end())
				return iterator();
			// [4, 7, 8, 9, 8, 9]
			// erase(this->begin() + 1, this->begin() + 3)
			// [4, 8, 9]
			iterator tmp_first = first;
			iterator it = first;
			size_type tmp_size = _size;
			while (first < last)
			{
				--tmp_size;
				_alloc.destroy(first.base());
				++first;
			}
			// last -> end()
			// *first = last
			// ++last -> end()
			// it = first;
			while (last < end())
			{
				*it = *(last++);
				++it;
			}
			_size = tmp_size;
			return tmp_first;
		}

		void		pop_back()
		{
			if (!this->_size)
				return;
			erase(this->end() - 1);
		}
		//
		void		push_back( const T& value)
		{
			insert(this->end(), value);
			return;
			//- si tu dois allouer 
			//- tu alloues la mememoire necessaire puis tu desalloues
			//sinon(tu insert l'element à la fin)
			if (_capacity == 0)
			{
				_capacity = 1;
				_mem = _alloc.allocate(_capacity);
			}
			if (_size + 1 > _capacity)
			{
				value_type	*tmp; //T *tmp;
				tmp = _alloc.allocate(_capacity * 2); //a verifier le doublement 
				size_t i(0);
				while(i < _size)
				{
					_alloc.construct(tmp + i, _mem[i]);
					_alloc.destroy(_mem + i);
					i++;
				}
				_alloc.construct(tmp + i, value);
				_alloc.deallocate(_mem, _capacity);
				_capacity *= 2; // *= 2;
				_mem = tmp;
			}
			else 
			{
				_alloc.construct(_mem + _size , value);
				// _mem[_size] = value;
			}
			_size++;
		};

		void		clear()
		{
			size_t i(0);

			while (i < _size)
			{
				_alloc.destroy(_mem + i);
				i++; 
			}
			_size = 0;
		}
		
		void		swap(vector& x)
		{
			size_type	tmp_capacity = _capacity;
			size_type	tmp_size = _size;
			pointer	tmp =	_mem;

			_mem = x._mem;
			x._mem = tmp;
			_size = x._size;
			x._size = tmp_size;
			_capacity = x._capacity;
			x._capacity = tmp_capacity; 
		}
						/*//:::::::::::CAPACITY:::::::::::\\*/

		typename Alloc::size_type	max_size()	const
		{
			return std::min<size_type>(std::numeric_limits<difference_type>::max(), _alloc.max_size());
		}

		void resize(const size_type &n, const value_type &val = value_type())
		{
			this->impl_resize(n, val);
		}

		//retourne la taille max 

		bool		empty() const
		{
			return (_size == 0);
		}

		size_type	size() const
		{
			return (_size);
		}

		size_type capacity() const
		{
			return (_capacity);
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

		//modifie la capacite par la nouvelle capacitie si new cap > _capacity du vector
		void		reserve(size_type new_cap)
		{

			if (new_cap > max_size())
				throw std::length_error("vector::reserve");
			if (new_cap > this->_capacity)
			{
				value_type *tmp = _alloc.allocate(new_cap); // retourne un nouveau tableau de taille new_cap -> [0, 0, 0, 0, ...]
				//this->_capacity = new_cap;
				if (!tmp)
					throw std::bad_alloc();
				// _mem = _alloc.allocate(new_cap - _capacity);
				// this->_mem = tmp;
				this->_capacity = new_cap;
				//std::cout << "_size :" << _size << std::endl; 
				// <- tableau actuelle [45, 21, 78]this->_mem;
				size_type i(0);
				while (i < this->_size)
				{
					_alloc.construct(tmp + i, this->_mem[i]);
					_alloc.destroy(this->_mem + i);
					i++;
				}
				_alloc.deallocate(this->_mem, _capacity);
				this->_mem = tmp;
				// this->_capacity = new_cap;

			}

		}
		reference operator[](const size_type &n)
		{
			return (_mem[n]);
		}

		const_reference operator[](const size_type &n) const
		{
			return (_mem[n]);
		}

		ft::vector<T, allocator_type> &operator=(const ft::vector<T, allocator_type> &vec)
		{
			this->_alloc = vec.get_allocator();
			this->assign(vec.begin(), vec.end());
			return *this;
		}
		
		bool operator==(const ft::vector<T, allocator_type> & b) const
		{
			if (this->_size != b._size)
				return false;
			return ft::equal(this->begin(), this->end(), b.begin());
		}

		bool operator<(const ft::vector<T, allocator_type> &b) const
		{ return ft::lexicographical_compare(this->begin(), this->end(), b.begin(), b.end()); }

		bool operator>(const ft::vector<T, allocator_type> &b) const
		{ return ft::lexicographical_compare(b.begin(), b.end(), this->begin(), this->end()); }

		bool operator<=(const ft::vector<T, allocator_type> &b) const
		{ return !this->operator>(b); }

		bool operator>=(const ft::vector<T, allocator_type> &b) const
		{ return !this->operator<(b); }

		bool operator!= (const ft::vector<T, allocator_type> &b) const
		{ return !this->operator==(b); }

		// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		/*bool operator==(const ft::vector<T> & b)
		{
			if (this->_size != b._size)
				return false;
			// ...
		}

		== 

		<

		>
*/
	private:
		//value_type		*_mem;
		T				*_mem;
		//ptr pour garder en memoire la place alloues
		//size_type		_size; valeur actuel
		size_type		_size;

		//pour connaitre la quantité de données à l'instant
		//size_type		_capacity;
		size_type		_capacity; 
		//connaitre la capacité total allouer, ce que peux contenir
		//allocator_type	_alloc;
		allocator_type	_alloc;
		//pour alouer/desalouer avec .allocate/deallocate
		//pour construire un objet/detruire
		//avec .construct/destroy
		int		it_become_pos(iterator position)
		{
			int posi = 0;
			ft::vector<T, allocator_type>::iterator iterator = this->begin();
			while (iterator != position)
			{
				posi++;
				iterator++;
			}
			return (posi);
		}
		//if size <  capacity 
		// size = size et capacity = capacity change
		//if size >  capacity
		// size reste a size et capacity = size (n -1)  * 2
		//max entre size size * 2 et size + N 	

		void	impl_resize(const size_type &n)
		{
			/*std::cout << "n "<< n << std::endl;
			std::cout << "_size "<< _size << std::endl;
			std::cout << "_capacity "<< _capacity << std::endl;*/
			// if  n > size -> size * 2
			/*
			n			: 413
			_size		: 401
			_capacity	: 402
			size 		: 413, capacity : 804
			ici n > size (401) && n > capacity (402)
			resultat size * 2
			normalement on prend le max entre size et capacity initiale et on double
			*/  
			std::cout << "N: " << n << " - " << _size << " - " << _capacity << std::endl;
			if (n < _size)
			{
				size_type i = n;
				while(i < _size)
				{
					_alloc.destroy(_mem + i); //&_mem[i]
					i++;
				}
				_size = n;
				//std::cout << "CAPAC_555 "<< _capacity <<std::endl;
			}

			else if (n > _size && n < _capacity)
			{
				std::cout << "n > _size && n < _capacity" << std::endl;
				_size = n;
				//std::cout << "CAPAC_666 "<< _capacity <<std::endl;
			}
			// if  n > size -> size * 2
			/*
			n			: 413
			_size		: 401
			_capacity	: 402
			size 		: 413, capacity : 804
			ici n > size (401) && n > capacity (402)
			resultat size * 2
			normalement on prend le max entre size et capacity initiale et on double
			*/  
			else // (n > _size) && (n > _capacity)
			{
				size_type new_cap = this->_size * 2;
				if (n > new_cap)
					new_cap = n;
				value_type *tmp = _alloc.allocate(new_cap); //uniquement n > C
				// if (!tmp)
					// throw std::
				size_type i(0);
				/*
				1/ size = size && cap = cap
				2/ size + n = size && cap = cap * 2 (si n < size)
				3/ size + n = size && cap = size + n  (si n > size)
				*/
				while (i < _size)
				{
					//std::cout << "ICI_2"<< std::endl;
					_alloc.construct(tmp + i, _mem[i]);					
					
					//std::cout << "CAPAC_772_else "<< _capacity <<std::endl;
					_alloc.destroy(_mem + i);
					++i;

				}
				_size = n;
				if (_mem)
				{
					//std::cout << "DEALLOC impl resize: " << this << " " << _mem << std::endl;
					_alloc.deallocate(_mem, _capacity);
				}
				if (n > _capacity)
					_capacity = new_cap;
				_mem = tmp;
			}
		}

		void	impl_resize(const size_type &n, const value_type &val) 
		{
			/*std::cout << "n "<< n << std::endl;
			std::cout << "_size "<< _size << std::endl;
			std::cout << "_capacity "<< _capacity << std::endl;*/
			// if  n > size -> size * 2
			/*
		x	 capacity : 804
			ici n > size (401) && n > capacity (402)
			resultat size * 2
			normalement on prend le max entre size et capacity initiale et on double
			*/  
			if (n < _size)
			{
				size_type i = n;
				while(i < _size)
				{
					_alloc.destroy(_mem + i); //&_mem[i]
					i++;
				}
				_size = n;
				//std::cout << "CAPAC_555 "<< _capacity <<std::endl;
			}

			else if (n > _size && n < _capacity)
			{
				//-std::cout << "n > _size && n < _capacity" << std::endl;
				while (_size < n)
					_alloc.construct(_mem + _size++, val);
				_size = n;
				//std::cout << "CAPAC_666 "<< _capacity <<std::endl;
			}
			// if  n > size -> size * 2
			/*
			n			: 413
			_size		: 401
			_capacity	: 402
			size 		: 413, capacity : 804
			ici n > size (401) && n > capacity (402)
			resultat size * 2
			normalement on prend le max entre size et capacity initiale et on double
			*/  
			else // (n > _size) && (n > _capacity)
			{
				size_type new_cap = this->_size * 2;
				if (n > new_cap)
					new_cap = n;
				value_type *tmp = _alloc.allocate(new_cap); //uniquement n > C
				// if (!tmp)
					// throw std::
				size_type i(0);
				/*
				1/ size = size && cap = cap
				2/ size + n = size && cap = cap * 2 (si n < size)
				3/ size + n = size && cap = size + n  (si n > size)
				*/
				while (i < _size)
				{
					//std::cout << "ICI_2"<< std::endl;
					_alloc.construct(tmp + i, _mem[i]);					
					
					//std::cout << "CAPAC_772_else "<< _capacity <<std::endl;
					_alloc.destroy(_mem + i);
					++i;

				}
				while (_size < n)
					_alloc.construct(tmp + _size++, val);
				_size = n;
				if (_mem)
				{
					//std::cout << "DEALLOC impl resize: " << this << " " << _mem << std::endl;
					_alloc.deallocate(_mem, _capacity);
				}
				if (n > _capacity)
					_capacity = new_cap;
				_mem = tmp;
			}
		}
	};

	template <class T, class Alloc>
	void	swap(ft::vector<T, Alloc> &vec_1, ft::vector<T, Alloc> &vec_2)
	{
		vec_1.swap(vec_2);
	}
}

#endif