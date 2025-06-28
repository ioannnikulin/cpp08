#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>

#include "Span.hpp"

using std::cout;
using std::endl;
using std::length_error;
using std::string;
using std::vector;

static void subjectTest() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	cout << sp.shortestSpan() << endl;
	cout << sp.longestSpan() << endl;
}

static void toofew(const Span &s) {
	try {
		s.shortestSpan();
	} catch (length_error e) {
		assert(e.what() == string("Too few numbers in the span"));
	}
	try {
		s.longestSpan();
	} catch (length_error e) {
		assert(e.what() == string("Too few numbers in the span"));
	}
}

static void myTest() {
	srand(time(0));
	const int MAX_CAP = 10001;
	Span s(MAX_CAP);
	toofew(s);
	s.addNumber(0);
	toofew(s);
	s.addNumber(15);
	assert(s.shortestSpan() == 15);
	assert(s.longestSpan() == 15);
	vector<int> v(MAX_CAP - 2);
	for (int i = 0; i < MAX_CAP - 2; i ++) {
		v.at(i) = i;
	}
	vector<int>::iterator to = v.end();
	s.addNumbers(v.begin(), to);
	assert(s.shortestSpan() == 0);
	assert(s.longestSpan() == 9998);
	try {
		s.addNumbers(v.begin(), to);
		assert(false);
	} catch (length_error e) {
		assert(e.what() == string("Span full, cannot add numbers"));
	}
}

int main() {
	myTest();
	subjectTest();
	return 0;
}
