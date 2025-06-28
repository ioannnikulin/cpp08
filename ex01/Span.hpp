#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

class Span {
private:
	unsigned int _capacity;
	std::multiset<int> _numbers;
	Span();
	Span& operator=(const Span& other);
	int _short;

public:
	Span(unsigned int capacity);
	Span(const Span& other);
	~Span();
	void addNumber(int n);
	template <typename T>
	void addNumbers(
		T from
		, T to
	) {
		for (T f = from; f < to; f ++) {
			addNumber(*f);
		}
	}
	int shortestSpan() const;
	int longestSpan() const;
};

#endif
