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
		/*typedef	const	T	const_value_type;
		typedef	typename	Alloc::const_pointer const_pointer;
		typedef	typename	Alloc::pointer	pointer;
		typedef	typename	std::ptrdiff_t	difference_type;
		typedef	typename	std::size_t		size_type;  peut etre
		typedef	typename	ft::vector_iterator<value_type>	iterator;
		typedef typename	ft::vector_iterator<const_value_type> const_iterator;*/
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
			//std::cout << "CTOR: " << this << " " << std::endl;
			this->assign(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type())
			: _mem(NULL), _size(0), _capacity(0), _alloc(alloc)
		{
			//std::cout << "CTOR: " << this << " " << std::endl;
			this->assign(first, last);
		}
	
		//constructeur par copy 
		vector(const ft::vector<T, allocator_type>& x)
			: _mem(NULL), _size(0), _capacity(0), _alloc(x.get_allocator())
		{
			//std::cout << "CTOR: " << this << " " << std::endl;
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

		
		/*
		vector_iterator() : _ptr(NULL) {}

		vector_iterator(vector_iterator const &copy) : _ptr(copy._ptr) {}

		explicit vector_iterator(pointer const ptr) : _ptr(ptr) {}

		~vector_iterator() {}*/


		/* fonction membr
		*/
		void assign (size_type n, const value_type& val)
		{
			//ajoute n fois la val
			this->resize(n);

			for (size_type i = 0; i < n; ++i)
			{
				_alloc.construct(_mem + i, val); //avec constructeur par copie en associant les valeurs a chaque espace 
			}
		}
		
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
		assign (InputIterator first, InputIterator last) //sur le type de retour
		{
				//ajoute un first et un last a la fin
			size_type i = 0;
			for (InputIterator it = first; it != last; ++it)
				++i;
			this->resize(i); // -> [0, 0, 0, 0, 0] _mem de taille _size, allocation, mais valeur non initialisé
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
			return (this->end() - 1);
		}

		const_reverse_iterator rbegin() const
		{
			return (this->end() - 1);
		}

		reverse_iterator	rend()
		{
			return (reverse_iterator(*(this->begin() - 1)));			
		}
		
		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(*(this->begin() - 1)));
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
		/*
		abcdef -> push_back(X) -> abcdef_ -> abcdefX
		abcdef -> insert(2, X) -> abcdef_ -> ab_cdef -> abXcdef
		*/

						/*//:::::::::::MODIFIERS:::::::::::\\*/
						//le vrai
						/*
		int			it_become_pos(iterator position)
		{
			int posi = 0;
			ft::vector<T, Allocator>::iterator iterator = this->begin();
			while (iterator != position)
			{
				posi++;
				iterator++;
			}
			return (posi);
		}

		----void insert (iterator position, size_type n, const value_type& val)
		{
		size_type newSize = n + this->_size;
			if (newSize > this->_capacity)
			{
				size_type newCap = this->_size == 0 ? 1 : this->_size * 2;
				if (newCap < newSize)
					newCap = newSize;
				T* newArray = this->try_allocation(newCap);
				unsigned int i = 0;
				ft::vector<T, Allocator>::iterator it = this->begin();
				for (; it != position; it++, i++)
				{
					this->_allocator_type.construct(newArray + i, *it);
				}
				for (unsigned int j = i + n; i < j; i++)
				{
					this->_allocator_type.construct(newArray + i, val);
				}
				for (; it != this->end(); it++, i++)
				{
					this->_allocator_type.construct(newArray + i, *it);
				}
				if (this->_array)
					this->destroy_and_deallocate();
				this->_array = newArray;
				this->_capacity = newCap;
			}
			else
			{
				if (position == this->end())
				{
					for (unsigned int j = this->_size; j < newSize; j++)
						this->_allocator_type.construct(this->_array + j, val);
				}
				else
				{
					ft::vector<T, Allocator>::iterator place = this->end() - 1;
					for (; place >= position; place--)
					{
						this->_allocator_type.construct((place+n).base(), *place);
						this->_allocator_type.destroy(place.base());
					}
					for (unsigned int i = 0; i < n; i++)
						this->_allocator_type.construct((++place).base(), val);
				}
			}
			this->_size = newSize;
		}
				template <class InputIterator>
		----void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type last)
		{
			//si pas integral rentre ici
			int pos = it_become_pos(position);
			for (InputIterator it = first; it != last; it++)
			{
				insert(this->begin()+pos, 1, *it);
				pos++;
			}
		}
		----iterator	insert(iterator position, const value_type &val)
		{
			int posi = it_become_pos(position);
			this->insert(position, 1, val);
			return (this->begin()+posi);
			
			// recuperer la distance entre le début du tableau et la position d'insertion
			difference_type distance = positon - this->begin();
			// on redimensionne le tab avec la taille actuelle + 1
			this->resize(_size + 1); // si reallocation, begin() pointe autre part donc position devient obsolête
			// on recupére la nouvelle position au cas ou il y'a eu une reallocation
			iterator new_position = this->begin() + distance;
			//on se positon juste avant la fin
			iterator it = this->end() - 1;
			//on recule et transfert les valeurs jusqu'à positon
			while (it > new_position)
			{
				*it = it - 1;
				--it;
			}
			//insertion de element
			_alloc.construct(it.get_pointer(), val);

		}
		*/
		//le faux
		int			it_become_pos(iterator position)
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
			difference_type distance = position - this->begin();
			this->impl_resize(_size + n, val, false);
			iterator new_position = this->begin() + distance;
			iterator it = this->end() - 1;
			while (it > (new_position + (n - 1)))
			{
				*it = *(it - n);
				--it; //on a definie operator -- donc c'est possible de le faire
			}

			while (n > 0)
			{
				_alloc.construct(it.get_pointer(), val);
				--n;
				--it;
			}

			/*
			value_type *tmp;
			tmp = _alloc.allocate(_capacity * 2);
			tmp._size = _size + 1;
			while ( position < men.end)
			{
				_alloc.construct(tmp[men.end()], _mem[men.end()]);
				--men.end();
			}
			while ( 0 < n)
			{
				tmp[position] = val;
				--n;
			}
			while (_mem.begin < position)
			{
				_alloc.construct(tmp[men.end()], _mem[men.end()]);
				--_mem.end();
			}
			_alloc.deallocate(_mem, _capacity);
			_mem = tmp;*/
		}

		template <class InputIterator> 
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
		insert( iterator position, InputIterator first, InputIterator last)
		{
			size_type n = 0;
			for (InputIterator it = first; it != last; ++it)
				++n;

			difference_type distance = position - this->begin();
			this->impl_resize(_size + n, value_type(), false);
			iterator new_position = this->begin() + distance;
			iterator it = this->end() - 1;
			while(it > (new_position + (n - 1)))
			{
				*it = *(it - n);
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
				_alloc.construct((new_position + i).get_pointer(), *first);
				++i;
				// --it;
				++first;
			}
		}
			// while (n > 0)
			// {
			// 	_alloc.construct(it.get_pointer(), last);
			// 	--n;
			// 	--it;
			// 	--last;
			// }
	//verifier si mes input sont true avec is integral 	si true insert avec size_t
	//sans --last et --first	


/*
			value_type *tmp;
			tmp = _alloc.allocate(_capacity * 2);
			tmp._size = _size + 2;
			while ( position < men.end())
			{
				_alloc.construct(tmp[men.end()], _mem[men.end()]);
				--men.end();
			}

				tmp[position] = last;
				--position;
				tmp[position] = first;

			while (_mem.begin < position)
			{
				_alloc.construct(tmp[men.end()], _mem[men.end()]);
				--_mem.end();
			}
			_alloc.deallocate(_mem, _capacity);
			_mem = tmp;*/

/*
		iterator 	insert(iterator position, const value_type& val)
		{
			//connaitre la taille de vecteur
			//01234;  pos : 2 ; val : 9
			//5-2 = 3 ça correspond "234"
			//pointeur sur position 2 insert 9
			//ajout element "234"

			// push_back  4
			// push_back  15
			// push_back  12
			// 4, 15, 12
			// insert 2, 78
			
			// alloue tab temporaire avec taille actuelle _size + 1 -> [0, 0, 0, 0]
			value_type *tmp = _alloc.allocate(_size + 1);

			// copier tab actuelle (_mem) jusqua position (2) dans tab temporaire -> [4, 15, 0, 0]
			for(iterator i = this->begin(); i < position; ++i)
			{

			}
			// inserer val (78) dans tab temporaire -> [4, 15, 78, 0]
			// copie le reste après la position dans tab temporaire -> [4, 15, 78, 12]
			//incrementer type + vector
		}
*/
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
			// [4, 7, 8, 9, 8, 9]
			// erase(this->begin() + 1, this->begin() + 3)
			// [4, 8, 9]
			iterator tmp_first = first;
			iterator it = first;
			size_type tmp_size = _size;
			while (first < last)
			{
				--tmp_size;
				_alloc.destroy(first.get_pointer());
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

/*AZERTYUIO

		iterator	erase(iterator first, iterator last) //last pas compris	
		{
			tmp_first = first;
			while (first < last)
				destroy first 
				fist++ 
			
			while (last != end)
			first = last
			first++
			last++

			copie de tmp [begin, first - 1; 
			copie de tmp [last + 1 , end];
			while (first < last)
				destroy first 
				fist++ 
			tmp : join tmp + tmp_2; 
			_mem = tmp;
			_size - [begin - last];
		}
*/
		void		pop_back()
		{
			_alloc.destroy((this->end() - 1).get_pointer());
			--_size;
		}
		//
		void		push_back( const T& value)
		{
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
				_alloc.construct(_mem + _size, value);
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

		void resize(size_type n, const value_type &val = value_type())
		{
			this->impl_resize(n, val, true);
		}

		void impl_resize(size_type n, const value_type &val, const bool &call_constructor) 
		{
			if (n < _size)
			{
				size_type i = n;
				while(i < _size)
				{
					_alloc.destroy(_mem + i); //&_mem[i]
					i++;
				}
				_size = n;
			}
			else if (n > _size && n < _capacity)
			{
				if (call_constructor)
					while (_size < n)
						_alloc.construct(_mem + _size++, val);
				_size = n;
			}
			else /* (n > _size) && (n > _capacity)*/
			{
				value_type  *tmp;
				tmp = _alloc.allocate(n * 2); //uniquement n > C
				size_type i(0);
				while (i < _size)
				{
					_alloc.construct(tmp + i, _mem[i]);
					_alloc.destroy(_mem + i);
					++i;
				}

				if (call_constructor)
					while (_size < n)
						_alloc.construct(tmp + _size++, val);
				_size = n;
				if (_mem)
				{
					//std::cout << "DEALLOC impl resize: " << this << " " << _mem << std::endl;
					_alloc.deallocate(_mem, _capacity);
				}
				_capacity = n * 2;
				_mem = tmp;
			}
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
			// _alloc.allocate(new_cap) -> nouveau tableau de taille new_cap
			// _mem -> ancien tableau
			// push_back 45
			// push_back 21
			// push_back 78
			// [45, 21, 78]
			// reserve 10
			// [45, 21, 78, 0, 0, 0, 0, 0, 0, 0]
			// nouveau allocate -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
			// _mem -> 

			if (new_cap > this->_capacity)
			{
				value_type *tmp = _alloc.allocate(new_cap); // retourne un nouveau tableau de taille new_cap -> [0, 0, 0, 0, ...]
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
				this->_capacity = new_cap;
			}
		}
		// new_cap > _capacity
		// reallouer _mem pour qu'il puisse contenir au moins new_cap
		// new_cap < _capacity
		// on fait rien...
		//if new_cap < _capacity || new_cap == _capacity = capacity
		//if new_cap > _capacity then capacity = new cap et réallouer _mem new_cap
	
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
/*
		bool operator==(const ft::vector<T> & b)
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
	};

	template <class T, class Alloc>
	void	swap(ft::vector<T, Alloc> &vec_1, ft::vector<T, Alloc> &vec_2)
	{
		vec_1.swap(vec_2);
	}
}

#endif