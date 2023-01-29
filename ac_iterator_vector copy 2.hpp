#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
class reverse_iterator {
public:
    typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    typedef typename iterator_traits<Iterator>::value_type        value_type;
    typedef typename iterator_traits<Iterator>::difference_type   difference_type;
    typedef typename iterator_traits<Iterator>::pointer           pointer;
    typedef typename iterator_traits<Iterator>::reference         reference;

    reverse_iterator() : current() {}
    explicit reverse_iterator(Iterator x) : current(x) {}
    reverse_iterator(const reverse_iterator& x) : current(x.current) {}

    template <class U>
    reverse_iterator(const reverse_iterator<U>& x) : current(x.base()) {}

    Iterator base() const { return current; }

    reference operator*() const {
        Iterator tmp = current;
        return *--tmp;
    }

    pointer operator->() const { return &(operator*()); }

    reverse_iterator& operator++() {
        --current;
        return *this;
    }

    reverse_iterator operator++(int) {
        reverse_iterator tmp = *this;
        --current;
        return tmp;
    }

    reverse_iterator& operator--() {
        ++current;
        return *this;
    }

    reverse_iterator operator--(int) {
        reverse_iterator tmp = *this;
        ++current;
        return tmp;
    }

    reverse_iterator operator+(difference_type n) const {
        return reverse_iterator(current - n);
    }

    reverse_iterator& operator+=(difference_type n) {
        current -= n;
        return *this;
    }

    reverse_iterator operator-(difference_type n) const {
        return reverse_iterator(current + n);
    }

    reverse_iterator& operator-=(difference_type n) {
        current += n;
        return *this;
    }

    reference operator[](difference_type n) const {
        return *(*this + n);
    }

protected:
    Iterator current;
};

}