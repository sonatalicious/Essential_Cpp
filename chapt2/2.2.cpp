#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool calc_elements(vector<int>&, int);
void display_elems(vector<int>&, const string&, ostream& = cout);

int main()
{
	vector<int> pent;
	const string title("Pentagonal Numeric Series");

	if (calc_elements(pent, 0))
		display_elems(pent, title);

	if (calc_elements(pent, 8))
		display_elems(pent, title);

	if (calc_elements(pent, 14))
		display_elems(pent, title);

	if (calc_elements(pent, 8)) //很显然，size减小后再调用函数，结果表示vector<int> pent的值还是在最大的调用状态
		display_elems(pent, title);

	if (calc_elements(pent, 138))
		display_elems(pent, title);
	return 0;
}

bool calc_elements(vector<int>& vec, int pos)
{
	if (pos <= 0 || pos > 64)
	{
		cerr << "Sorry. Invalid position: "
			<< pos << endl;
		return false;
	}

	for (int ix = vec.size() + 1; ix <= pos; ++ix) {
		// cout << "ix : " << ix << " == " << (ix*(3*ix-1))/2 << endl;
		vec.push_back((ix * (3 * ix - 1)) / 2);
	}

	return true;
}

void display_elems(vector<int>& vec, const string& title,
	ostream& os)
{
	os << '\n' << title << "\n\t";
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}