#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

using std::deque;
using std::stack;

template <typename T, typename C = deque<T> >
class MutantStack : public stack<T, C> {
public:
	typedef typename C::iterator iterator;
	typedef typename C::const_iterator const_iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}
};

#endif
