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
		
		vector() : mem(NULL), m_Size(0), m_Capacity(0)
		{
			//std::cout << "constructeur" << std::endl;
		}

		vector (size_type n, const value_type &val = value_type()/*, const allocator_type &alloc = allocator_type())*/)
			: m_Size(n), m_Capacity(n)
		{
			mem = m_alloc.allocate(n); // -> [0, 0, 0, 0, 0]
			for (size_type i = 0; i < n; ++i)
			{
				m_alloc.construct(mem + i, val); //avec constructeur par copie en associant les valeurs a chaque espace 
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: m_Size(last - first), m_Capacity(last - first)
		{
			mem = m_alloc.allocate(m_Size); // -> [0, 0, 0, 0, 0] mem de taille m_size, allocation, mais valeur non initialisé
			for (size_t i = 0; first != last; ++i, ++first)
			{
				m_alloc.construct(mem + i, *first); // initialise (construit) chaque élement on associe une valeur		
 			} 
		}

		//ici destructeur
		~vector()
		{
			clear();
			if (mem != NULL)
				m_alloc.deallocate(mem, m_Capacity);
			//deallocate mem[]
		}

		/* fonction membr
		*/
		void assign (size_type n, const value_type& val)
		{
			//ajoute n fois la val a la fin
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
				//ajoute un first et un last a la fin 
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
			return (iterator(this->mem + m_Size));
		}

		const_iterator end() const
		{
			return (const_iterator(this->mem + m_Size));
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
			if (n > m_Size)
				throw std::out_of_range("ft::vector at out of range");
			return (mem[n]);
		}
		const_reference	at(size_type n)	const
		{
			if (n > m_Size)
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
	value_type *tmp;
	tmp = m_alloc.allocate(m_Capacity * 2);
	tmp.m_Size = m_Size + 1;
	while ( position < men.end())
	{
		m_alloc.construct(tmp[men.end()], mem[men.end()]);
		--men.end();
	}
	tmp[position] = val;
	while (mem.begin < position)
	{
		m_alloc.construct(tmp[men.end()], mem[men.end()]);
		--mem.end();
	}
	m_alloc.deallocate(mem, m_Capacity);
	mem = tmp;
}

void		insert(iterator position, size_type n, const value_type &val)
{
	value_type *tmp;
	tmp = m_alloc.allocate(m_Capacity * 2);
	tmp.m_Size = m_Size + 1;
	while ( position < men.end)
	{
		m_alloc.construct(tmp[men.end()], mem[men.end()]);
		--men.end();
	}
	while ( 0 < n)
	{
		tmp[position] = val;
		--n;
	}
	while (mem.begin < position)
	{
		m_alloc.construct(tmp[men.end()], mem[men.end()]);
		--mem.end();
	}
	m_alloc.deallocate(mem, m_Capacity);
	mem = tmp;
}

template <class InputIterator> 
void insert( iterator position, InputIterator first, InputIterator last)
{
	value_type *tmp;
	tmp = m_alloc.allocate(m_Capacity * 2);
	tmp.m_Size = m_Size + 2;
	while ( position < men.end())
	{
		m_alloc.construct(tmp[men.end()], mem[men.end()]);
		--men.end();
	}

		tmp[position] = last;
		--position;
		tmp[position] = first;

	while (mem.begin < position)
	{
		m_alloc.construct(tmp[men.end()], mem[men.end()]);
		--mem.end();
	}
	m_alloc.deallocate(mem, m_Capacity);
	mem = tmp;
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
			
			// alloue tab temporaire avec taille actuelle m_Size + 1 -> [0, 0, 0, 0]
			value_type *tmp = m_alloc.allocate(m_Size + 1);

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
			--m_Size;*/
		}

		iterator	erase(iterator first, iterator last)
		{
			while (first < last)
			{
				m_alloc.destroy(mem + first);
				++first;
			}
			first = last;
			while( last != mem.end)
			{
				mem.first = mem.last;
				++first;
				++last;
			}
			m_Size = m_Size - (last - first); 
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
			m_Size - [begin - last];
		}
*/
		void		pop_back()
		{
			m_alloc.destroy((this->end() - 1).pointer());
			--m_Size;
		}
		//
		void		push_back( const T& value)
		{
			//- si tu dois allouer 
			//- tu alloues la mememoire necessaire puis tu desalloues
			//sinon(tu insert l'element à la fin)
			if (m_Capacity == 0)
			{
				m_Capacity = 1;
				mem = m_alloc.allocate(m_Capacity);
			}
			if (m_Size + 1 > m_Capacity)
			{
				value_type	*tmp; //T *tmp;
				tmp = m_alloc.allocate(m_Capacity * 2); //a verifier le doublement 
				size_t i(0);
				while(i < m_Size)
				{
					m_alloc.construct(tmp + i, mem[i]);
					m_alloc.destroy(mem + i);
					i++;
				}
				m_alloc.construct(tmp + i, value);
				m_alloc.deallocate(mem, m_Capacity);
				m_Capacity *= 2; // *= 2;
				mem = tmp;
			}
			else 
			{
				m_alloc.construct(mem + m_Size, value);
				// mem[m_Size] = value;
			}
			m_Size++;
		};

		void		clear()
		{
			size_t i(0);

			while (i < m_Size)
			{
				m_alloc.destroy(mem + i);
				i++; 
			}
			m_Size = 0;
		}
		
		void		swap(vector& x)
		{
			size_type	tmp_capacity = m_Capacity;
			size_type	tmp_size = m_Size;
			pointer	tmp =	mem;

			mem = x.mem;
			x.mem = tmp;
			m_Size = x.m_Size;
			x.m_Size = tmp_size;
			m_Capacity = x.m_Capacity;
			x.m_Capacity = tmp_capacity; 
		}

// [4, 5, 7, 9, 6]
// resize(7 > capacity, 10)
// [4, 5, 7, 10, 10] == pop_back 
						/*//:::::::::::CAPACITY:::::::::::\\*/

		typename Alloc::size_type	max_size()	const
		{
			return std::min<size_type>(std::numeric_limits<difference_type>::max(), m_alloc.max_size());
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

			if (n < m_Size)
			{
				size_type i = n;
				while(i < m_Size)
				{
					m_alloc.destroy(mem + i); //&mem[i]
					i++;
				}
				m_Size = n;
			}
			/*cas  size < n < capacity
			reattribu size = n 			
			attribue val n - size
			plus val dans le tableau 
			n >  capacity realloc  sinon
			definie size = n 
			val idem*/ 
			else if (n > m_Size && n < m_Capacity)
			{
				while (m_Size < n)
				{
					m_alloc.construct(mem + i, val);
					++m_Size;
				}
			}
			else /* (n > m_Size) && (n > m_Capacity)*/
			{
				value_type  *tmp;
				tmp = m_alloc.allocate(n * 2); //uniquement n > C
				size_type i(0);
				while (i < m_Size)
				{
					m_alloc.construct(tmp + i, mem[i]);
					m_alloc.destroy(mem + i);
					++i;
				}
			
				while (m_Size < n)
				{	
					m_alloc.construct(tmp + m_Size, val);
					++m_Size;
				}
				m_Capacity = n * 2;
				mem = tmp;
			}
		}
		//retourne la taille max 

		bool		empty() const
		{
			return (m_Size == 0);
		}

		size_type	size() const
		{
			return (m_Size);
		}

		size_type capacity() const
		{
			return (m_Capacity);
		}

		//modifie la capacite par la nouvelle capacitie si new cap > m_capacity du vector
		void		reserve(size_type new_cap)
		{
			// m_alloc.allocate(new_cap) -> nouveau tableau de taille new_cap
			// mem -> ancien tableau
			// push_back 45
			// push_back 21
			// push_back 78
			// [45, 21, 78]
			// reserve 10
			// [45, 21, 78, 0, 0, 0, 0, 0, 0, 0]
			// nouveau allocate -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
			// mem -> 

			if (new_cap > m_Capacity)
			{
				value_type *tmp;
				m_alloc.allocate(new_cap); // retourne un nouveau tableau de taille new_cap -> [0, 0, 0, 0, ...]
				this->mem; // <- tableau actuelle [45, 21, 78]
				size_type i(0);
				while ( i < m_Capacity)
				{
					tmp[i] = mem[i];
					i++;
				}
			}
		}
		// new_cap > m_Capacity
		// reallouer mem pour qu'il puisse contenir au moins new_cap
		// new_cap < m_Capacity
		// on fait rien...
		//if new_cap < m_Capacity || new_cap == m_Capacity = capacity
		//if new_cap > m_Capacity then capacity = new cap et réallouer mem new_cap
	
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
		//size_type		m_Size; valeur actuel
		size_type		m_Size;

		//pour connaitre la quantité de données à l'instant
		//size_type		m_Capacity;
		size_type		m_Capacity; 
		//connaitre la capacité total allouer, ce que peux contenir
		//allocator_type	m_alloc;
		allocator_type	m_alloc;
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