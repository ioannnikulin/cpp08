#include <list>
#include <vector>
#include <set>
#include <stdexcept>
#include <cassert>

#include "easyfind.hpp"

using std::runtime_error;
using std::string;

int main() {
	std::vector<int> vec(5);
	vec.at(0) = 1;
	vec.at(1) = 2;
	vec.at(2) = 3;
	vec.at(3) = 4;
	vec.at(4) = 5;
	assert(easyfind(vec, 3) == 3);
	easyfind(vec, 3) ++;
	try {
		easyfind(vec, 3);
		assert(false);
	} catch (const runtime_error &e) {
		assert(string(e.what()) == "Value not found in the container");
	}
	
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	assert(easyfind(lst, 20) == 20);
	
	std::set<int> st;
	st.insert(100);
	st.insert(200);
	st.insert(300);
	const std::set<int> &cst = st;
	assert(easyfind(cst, 200) == 200);
	
	return 0;
}
