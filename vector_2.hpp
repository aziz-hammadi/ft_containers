#ifndef VECTOR_2_HPP
#define VECTOR_2_HPP

#include <memory>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <vector>
#include "iterator_vector.hpp"
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
		
		typedef	typename	Alloc::reference reference;
		typedef	typename	Alloc::const_reference const reference;
		typedef	typename	Alloc::const_pointer const_pointer;
		typedef	typename	Alloc::pointer	pointer;
		typedef	typename	std::ptrdiff_t	difference_type;
		typedef	typename	std::size_t		size_type;
		typedef	typename	ft::vector_iterator<value_type>	iterator;
		typedef typename	ft::vector_iterator<const_value_type> const_iterator;
		typedef	typename	ft::reverse_iterator<iterator> reverse iterator;
		typedef	typename	ft::reverse_iterator<const_iterator> const reverse iterator;*/
		typedef	Alloc			allocator_type; //pas besoin de typemane car on essai pas d'acceder a qqchose qui dépend d'un template
		typedef	std::size_t		size_type;
		typedef ft::iterator_vector<T *> iterator;
		typedef ft::iterator_vector<const T *> const_iterator;
	
		vector() : mem(nullptr), m_Size(0), m_Capacity(0)
		{
			
		}

		//ici destructeur
		~vector()
		{
			clear();
			m_alloc.deallocate(mem, m_Capacity);
			//deallocate mem[]
		}

		typename Alloc::size_type	max_size()	const
		{
			return std::min(std::numeric_limits<typename Alloc::difference_type >::max(), m_alloc.max_size);
		}
		/* fonction membr
		*/
		
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

		/*
		abcdef -> push_back(X) -> abcdef_ -> abcdefX
		abcdef -> insert(2, X) -> abcdef_ -> ab_cdef -> abXcdef
		*/

				/*//:::::::::::MODIFIERS:::::::::::\\*/
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
/*
		iterator	erase(iterator position)
		{

		}

		iterator	erase(iterator first, iterator last)
		{
			
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
				m_Capacity += 1; // *= 2;
				value_type	*tmp; //T *tmp;
				tmp = m_alloc.allocate(m_Capacity); //a verifier le doublement 
				size_t i(0);
				while(i < m_Size)
				{
					tmp[i] = mem[i];
					i++;
				}
				tmp[i] = value; 
				m_alloc.deallocate(mem, m_Capacity);
				mem = tmp;
			}
			else 
			{
				mem[m_Size] = value;
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
		/*
		void		swap(vector& x)
		{
			value_type *tmp;

		}*/

// [4, 5, 7, 9, 6]
// resize(7 > capacity, 10)
// [4, 5, 7, 10, 10] == pop_back 
/*
		void resize (size_type n, value_type val = value_type());
		{
			
		}*/
		//retourne la taille max 
				/*//:::::::::::CAPACITY:::::::::::\\*/

		bool		empty() const
		{
			if (m_Size != 0)
				return false;
			return true;
		}

		size_type	size() const
		{
			return (m_Size);
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
	

				/*//:::::::::::ITERATOR:::::::::::\\*/

		/*iterator end()
		{
			if (this->empty())
				return (this->begin());
			return (end);
		}*/

		T	&operator[](size_type pos)
		{
			return (mem[pos]);
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
}

#endif