#include <algorithm>
#include <climits>
#include <stdexcept>

#include "Span.hpp"

using std::length_error;
using std::max;
using std::min;
using std::multiset;

Span::Span() {
}

Span::Span(const Span& other) :
	_capacity(other._capacity)
	,_numbers(multiset<int>(other._numbers))
	, _short(other._short)
{}

Span& Span::operator=(const Span& other) {
	if (&other == this) {
		return (*this);
	}
	_capacity = other._capacity;
	_numbers = multiset<int>(other._numbers);
	_short = other._short;
	return (*this);
}

Span::Span(unsigned int capacity) :
	_capacity(capacity)
	, _numbers(multiset<int>())
	, _short(INT_MAX)
{}

Span::~Span() {
}

void Span::addNumber(int n) {
	if (_numbers.size() >= _capacity) {
		throw length_error("Span full, cannot add numbers");
	}
	multiset<int>::iterator pos = _numbers.insert(n);
	multiset<int>::iterator prev = pos, next = pos;
	if (pos != _numbers.begin()) {
		prev --;
		_short = min(_short, *pos - *prev);
	}
	next ++;
	if (next != _numbers.end()) {
		_short = min(_short, *next - *pos);
	}
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw length_error("Too few numbers in the span");
	}
	return (_short);
}

int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw length_error("Too few numbers in the span");
	}
	multiset<int>::iterator biggest = _numbers.end();
	biggest --;
	return (*biggest - *_numbers.begin());
}
