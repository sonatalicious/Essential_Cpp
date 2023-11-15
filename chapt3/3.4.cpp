#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class even_elem {
public:
	bool operator()(int elem)
	{
		return elem % 2 ? false : true;
	}
};


int main()
{
	vector<int> input;
	istream_iterator<int> in(cin), eos;

	// STL真是强大
	copy(in, eos, back_inserter(input));

	vector<int>::iterator division = partition(input.begin(), input.end(), even_elem());

	ofstream even_file("evenfile.txt"), odd_file("odd_file.txt");

	if (!even_file || !odd_file)
	{
		cerr << "arghh!! unable to open the output files, bailing out!";
		return -1;
	}
	ostream_iterator<int> even_iter(even_file, "\n"), odd_iter(odd_file, " ");

	// STL十分抽象地用copy实现了输出功能
	copy(input.begin(), division, even_iter);
	copy(division, input.end(), odd_iter);
}

