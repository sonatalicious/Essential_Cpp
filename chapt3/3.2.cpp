#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;




// ���Ǹ� function template
// �������ʱ�Ż����ɣ�����дʱ�����������ֲ�����
template <typename elemType>
void display_vector(const vector<elemType>& vec, ofstream& os, int len = 8)
{
	//vector<elemType>::const_iterator iter = vec.begin(), end_it = vec.end();
	// ��֪��Ϊʲô�����������������
	auto iter = vec.begin(), end_it = vec.end();


	int elem_cnt = 1;
	while (iter != end_it)
		os << *iter++ << (!(elem_cnt++ % len) ? '\n' : ' ');

	os << endl;
}


// ���Ǹ� function object
// �������ͨ class ������ () �������ʹ�������ͨ�� () ֱ�ӵ���
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

