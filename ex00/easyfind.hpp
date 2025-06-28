#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::reference easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end()) {
		return *it;
	} else {
		throw std::runtime_error("Value not found in the container");
	}
}

template <typename T>
typename T::const_reference easyfind(const T &container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end()) {
		return *it;
	} else {
		throw std::runtime_error("Value not found in the container");
	}
}
#endif
