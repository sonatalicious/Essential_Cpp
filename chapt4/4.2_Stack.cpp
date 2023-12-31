#include "Stack.h"

bool 
Stack::pop(string& elem)
{
	if (empty()) return false;

	elem = _stack.back();
	_stack.pop_back();
	return true;
}

bool
Stack::peek(string& elem)
{
	if (empty()) return false;

	elem = _stack.back();
	return true;
}

bool
Stack::push(const string& elem)
{
	if (full())
		return false;

	_stack.push_back(elem);
	return true;
}

// ::是全局范围运算符，不加上的话find会递归调用本身函数
bool Stack::find(const string& elem) const
{
	vector<string>::const_iterator end_it = _stack.end();
	return ::find(_stack.begin(), end_it, elem) != end_it;
}

int Stack::count(const string& elem) const
{
	return ::count(_stack.begin(), _stack.end(), elem);
}