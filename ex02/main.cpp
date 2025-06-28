#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>
#include <cassert>

#include "MutantStack.hpp"

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

static void subjectTest() {
	MutantStack<int> mstack;
	mstack.push(5);
	assert(mstack.size() == 1);
	assert(*mstack.begin() == 5);
	mstack.push(17);
	assert(mstack.size() == 2);
	assert(*mstack.begin() == 5);
	assert(mstack.top() == 17);
	mstack.pop();
	assert(mstack.size() == 1);
	assert(*mstack.begin() == 5);
	assert(mstack.top() == 5);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	assert(mstack.size() == 5);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int exp[] = {5, 3, 5, 737, 0};
	int i = 0;
	while (it != ite) {
		assert(*it == exp[i++]);
		++it;
	}
	stack<int> s(mstack);
}

static void listTest() {
	list<int> mstack;
	mstack.push_back(5);
	assert(mstack.size() == 1);
	assert(*mstack.begin() == 5);
	mstack.push_back(17);
	assert(mstack.size() == 2);
	assert(*mstack.begin() == 5);
	assert(mstack.back() == 17);
	mstack.pop_back();
	assert(mstack.size() == 1);
	assert(*mstack.begin() == 5);
	assert(mstack.back() == 5);
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	assert(mstack.size() == 5);
	list<int>::iterator it = mstack.begin();
	list<int>::iterator ite = mstack.end();
	++it;
	--it;
	int exp[] = {5, 3, 5, 737, 0};
	int i = 0;
	while (it != ite) {
		assert(*it == exp[i++]);
		++it;
	}
	list<int> s(mstack);
}
int main() {
	subjectTest();
	listTest();
	return 0;
}
