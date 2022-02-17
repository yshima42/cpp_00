#ifndef INCLUDE_GUARD_EASYFIND_HPP
#define INCLUDE_GUARD_EASYFIND_HPP

#include <iostream>

template< typename T>
typename T::const_iterator easyfind(const T& t, int val) {
    typename T::const_iterator it = std::find(t.begin(), t.end(), val);
    if (it == t.end()) {
        throw std::invalid_argument("value not found");
    }
    return it;
}

#endif

