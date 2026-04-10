#ifndef EASYFIND_HPP

# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &list, const int i){
    return(find(list.begin(), list.end(), i));
}

template <typename T>
typename T::const_iterator easyfind(const T &list, const int i){
    return(find(list.begin(), list.end(), i));
}

#endif