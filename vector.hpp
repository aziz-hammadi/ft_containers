#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <cstddef>
# include <memory>
# include <iterator>
# include <algorithm>
# include <iostream>
# include <limits>
# include <vector>
# include "iterator_vector.hpp"
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
		typedef	typename	Alloc::reference reference;
		typedef	typename	Alloc::const_reference const_reference;
		typedef	typename	ft::reverse_iterator<iterator> reverse_iterator;
		typedef	typename	ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef	Alloc							allocator_type; //pas besoin de typemane car on essai pas d'acceder a qqchose qui dépend d'un template
		typedef	std::size_t						size_type;
		typedef ft::iterator_vector<T *>		iterator;
		typedef ft::iterator_vector<const T *>	const_iterator;
		typedef	typename Alloc::pointer			pointer;
		typedef typename Alloc::difference_type difference_type;
		
		vector() : mem(NULL), _size(0), _capacity(0)
		{
			//std::cout << "constructeur" << std::endl;
		}

		vector (size_type n, const value_type &val = value_type()/*, const allocator_type &alloc = allocator_type())*/)
			: mem(NULL)
		{
			this->assign(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: mem(NULL)
		{
			this->assign(first, last);
		}

		//ici destructeur
		~vector()
		{
			clear();
			if (mem != NULL)
				_alloc.deallocate(mem, _capacity);
			//deallocate mem[]
		}

		/* fonction membr
		*/
		void assign (size_type n, const value_type& val)
		{
			//ajoute n fois la val
			this->resize(n)
			for (size_type i = 0; i < n; ++i)
			{
				_alloc.construct(mem + i, val); //avec constructeur par copie en associant les valeurs a chaque espace 
			}
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
				//ajoute un first et un last a la fin
			this->resize(last - first); // -> [0, 0, 0, 0, 0] mem de taille _size, allocation, mais valeur non initialisé
			for (size_t i = 0; first != last; ++i, ++first)
			{
				_alloc.construct(mem + i, *first); // initialise (construit) chaque élement on associe une valeur		
 			} 
		}
						/*//:::::::::::ITERATOR:::::::::::\\*/
		iterator begin()
		{
			return (iterator(this->mem));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->mem));
		}

		iterator end()
		{
			return (iterator(this->mem + _size));
		}

		const_iterator end() const
		{
			return (const_iterator(this->mem + _size));
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
			return (this->begin() - 1);			
		}
		
		const_reverse_iterator	rend() const
		{
			return (this->begin() - 1);
		}

						/*//:::::::::::ELEMENT ACCESS:::::::::::\\*/

		reference	at(size_type n)
		{
			if (n > _size)
				throw std::out_of_range("ft::vector at out of range");
			return (mem[n]);
		}
		const_reference	at(size_type n)	const
		{
			if (n > _size)
				throw std::out_of_range("ft::vector at out of range");
			return (mem[n]);
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
		iterator	insert(iterator position, const value_type &val)
		{
			return (insert(position, 1, val));
			/*
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
			_alloc.construct(it.pointer(), val);*/
		}

		void		insert(iterator position, size_type n, const value_type &val)
		{
			// [4, 5, 6, 7, 8]
			// insert 1, n=2, 3
			// [4, 5, 4, 5, 6, 7, 8]

			difference_type distance = position - this->begin();
			this_>resize(_size + n);
			iterator new_position = this->begin() + distance;
			iterator it = this->end() - 1;
			while(it > (new_position + (n - 1)))
			{
				*it = it - n;
				--it;
			}
			while (n > 0)
			{
				_alloc.construc(it.pointer(), val);
				--n;
				--it;
			}

			/*
			value_type *tmp;
			tmp = _alloc.allocate(_capacity * 2);
			tmp._size = _size + 1;
			while ( position < men.end)
			{
				_alloc.construct(tmp[men.end()], mem[men.end()]);
				--men.end();
			}
			while ( 0 < n)
			{
				tmp[position] = val;
				--n;
			}
			while (mem.begin < position)
			{
				_alloc.construct(tmp[men.end()], mem[men.end()]);
				--mem.end();
			}
			_alloc.deallocate(mem, _capacity);
			mem = tmp;*/
		}

		template <class InputIterator> 
		void insert( iterator position, InputIterator first, InputIterator last)
		{
			size_type n = last - first;
			difference_type distance = position - this->begin();
			this_>resize(_size + n);
			iterator new_position = this->begin() + distance;
			iterator it = this->end() - 1;
			while(it > (new_position + (n - 1)))
			{
				*it = it - n;
				--it;
			}
			while (n > 0)
			{
				_alloc.construc(it.pointer(), last);
				--n;
				--it;
				--last;
			}
			


/*
			value_type *tmp;
			tmp = _alloc.allocate(_capacity * 2);
			tmp._size = _size + 2;
			while ( position < men.end())
			{
				_alloc.construct(tmp[men.end()], mem[men.end()]);
				--men.end();
			}

				tmp[position] = last;
				--position;
				tmp[position] = first;

			while (mem.begin < position)
			{
				_alloc.construct(tmp[men.end()], mem[men.end()]);
				--mem.end();
			}
			_alloc.deallocate(mem, _capacity);
			mem = tmp;*/
		}
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

			// copier tab actuelle (mem) jusqua position (2) dans tab temporaire -> [4, 15, 0, 0]
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
			return (erase(positon, position + 1));
			/*copie de tmp [begin, positon - 1];
			destroy mem[position] 
			copie de tmp_2 [positon +1 , end];
			tmp : join tmp + tmp_2; 
			mem = tmp;
			--_size;*/
		}

		iterator	erase(iterator first, iterator last)
		{
			// [4, 5, 6, 7, 8, 9]
			// erase(this->begin() + 1, this->begin() + 3)
			// [4, 8, 9]
			while (first < last)
			{
				_alloc.destroy(first.pointer());
				++first;
			}
			// last -> end()
			// *first = last
			// ++last -> end()
			while (last < end())
			{
				*it = *(last++);
				++it;
			}
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
			mem = tmp;
			_size - [begin - last];
		}
*/
		void		pop_back()
		{
			_alloc.destroy((this->end() - 1).pointer());
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
				mem = _alloc.allocate(_capacity);
			}
			if (_size + 1 > _capacity)
			{
				value_type	*tmp; //T *tmp;
				tmp = _alloc.allocate(_capacity * 2); //a verifier le doublement 
				size_t i(0);
				while(i < _size)
				{
					_alloc.construct(tmp + i, mem[i]);
					_alloc.destroy(mem + i);
					i++;
				}
				_alloc.construct(tmp + i, value);
				_alloc.deallocate(mem, _capacity);
				_capacity *= 2; // *= 2;
				mem = tmp;
			}
			else 
			{
				_alloc.construct(mem + _size, value);
				// mem[_size] = value;
			}
			_size++;
		};

		void		clear()
		{
			size_t i(0);

			while (i < _size)
			{
				_alloc.destroy(mem + i);
				i++; 
			}
			_size = 0;
		}
		
		void		swap(vector& x)
		{
			size_type	tmp_capacity = _capacity;
			size_type	tmp_size = _size;
			pointer	tmp =	mem;

			mem = x.mem;
			x.mem = tmp;
			_size = x._size;
			x._size = tmp_size;
			_capacity = x._capacity;
			x._capacity = tmp_capacity; 
		}

// [4, 5, 7, 9, 6]
// resize(7 > capacity, 10)
// [4, 5, 7, 10, 10] == pop_back 
						/*//:::::::::::CAPACITY:::::::::::\\*/

		typename Alloc::size_type	max_size()	const
		{
			return std::min<size_type>(std::numeric_limits<difference_type>::max(), _alloc.max_size());
		}

		void resize (size_type n, value_type val = value_type()) //a verifier
		{
			// n = 8 size = 5 5 + (8 - 5 )
			// si n < size 
			// conteneur reduit à n 
			// si n > size 
			// size + (n-size)
			// si n > capacity 
			// reallocation

			if (n < _size)
			{
				size_type i = n;
				while(i < _size)
				{
					_alloc.destroy(mem + i); //&mem[i]
					i++;
				}
				_size = n;
			}
			/*cas  size < n < capacity
			reattribu size = n 			
			attribue val n - size
			plus val dans le tableau 
			n >  capacity realloc  sinon
			definie size = n 
			val idem*/ 
			else if (n > _size && n < _capacity)
			{
				while (_size < n)
				{
					_alloc.construct(mem + i, val);
					++_size;
				}
			}
			else /* (n > _size) && (n > _capacity)*/
			{
				value_type  *tmp;
				tmp = _alloc.allocate(n * 2); //uniquement n > C
				size_type i(0);
				while (i < _size)
				{
					_alloc.construct(tmp + i, mem[i]);
					_alloc.destroy(mem + i);
					++i;
				}
			
				while (_size < n)
				{	
					_alloc.construct(tmp + _size, val);
					++_size;
				}
				_capacity = n * 2;
				mem = tmp;
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
			// mem -> ancien tableau
			// push_back 45
			// push_back 21
			// push_back 78
			// [45, 21, 78]
			// reserve 10
			// [45, 21, 78, 0, 0, 0, 0, 0, 0, 0]
			// nouveau allocate -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
			// mem -> 

			if (new_cap > _capacity)
			{
				value_type *tmp;
				_alloc.allocate(new_cap); // retourne un nouveau tableau de taille new_cap -> [0, 0, 0, 0, ...]
				this->mem; // <- tableau actuelle [45, 21, 78]
				size_type i(0);
				while ( i < _capacity)
				{
					tmp[i] = mem[i];
					i++;
				}
			}
		}
		// new_cap > _capacity
		// reallouer mem pour qu'il puisse contenir au moins new_cap
		// new_cap < _capacity
		// on fait rien...
		//if new_cap < _capacity || new_cap == _capacity = capacity
		//if new_cap > _capacity then capacity = new cap et réallouer mem new_cap
	
		reference operator[](size_type n)
		{
			return (mem[n]);
		}

		const_reference operator[](size_type n)
		{
			return (mem[n]);
		}

	private:
		//value_type		*mem;
		T				*mem;
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