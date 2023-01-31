#ifndef __EQUAL_HPP__
# define __EQUAL_HPP__

namespace ft
{
    template    <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        //comparaison entre la premiere iteration first1-> last1 et la deuxieme a partir de first2 jusqu a last1
        //retourne true si pas de difference 
        //retourne false si different
        while (first1 != last1)
        {
			if (!(*first1 == *first2))
                return false;
            ++first1; ++first2;
        }
		return true;
    }

    template    <class InputIterator1, class InputIterator2, class BinaryPredicate> 
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        //idem pour ici sauf que lon etudie le retour de pred si ok alors retour true 
        //sinon false
		//pred bool binaire qui prend deux elements en argument true si les deux elements identiques
		while (first1 != last1)
		{
			if(!pred(*first1,*first2))
				return false;
			++first1;++first2;
		}
		return true;
	}
}

#endif