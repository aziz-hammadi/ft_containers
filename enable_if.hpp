#ifndef __ENABLE_IF_HPP__
# define __ENABLE_IF_HPP__

namespace ft
{
    template <bool _Cond, class T = void>
    struct enable_if;

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class T>
    struct enable_if<false, T>
    {};
}

#endif