#pragma once

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Stack {
public:
	bool push(const string& elem);
	bool pop(string& elem);
	bool peek(string& elem);
	bool find(const string& elem) const;
	int count(const string& elem) const;
	bool empty() const { return _stack.empty(); }
	bool full() const { return _stack.size() == _stack.max_size(); }
	int size() const { return _stack.size(); }

private:
	vector<string> _stack;

};

