#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;




// 这是个 function template
// 程序调用时才会生成，所以写时，许多错误都显现不出来
template <typename elemType>
void display_vector(const vector<elemType>& vec, ofstream& os, int len = 8)
{
	//vector<elemType>::const_iterator iter = vec.begin(), end_it = vec.end();
	// 不知道为什么，下面这个才能运行
	auto iter = vec.begin(), end_it = vec.end();


	int elem_cnt = 1;
	while (iter != end_it)
		os << *iter++ << (!(elem_cnt++ % len) ? '\n' : ' ');

	os << endl;
}


// 这是个 function object
// 相对于普通 class 重置了 () 运算符，使得其可以通过 () 直接调用
class LessThan {
public:
	bool operator()(const string& s1, const string& s2)
	{
		return s1.size() < s2.size();
	}
};

int main()
{
	ifstream ifile("column1.txt");
	ofstream ofile("column1.map");
	if (!ifile || !ofile)
	{
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}
	vector<string> text;
	string word;

	while (ifile >> word)
		text.push_back(word);

	sort(text.begin(), text.end(), LessThan());
	display_vector(text, ofile);

	return 0;
}

