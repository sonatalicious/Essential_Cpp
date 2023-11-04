//// vector_style
//#include <iostream>
//#include <iomanip>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> ivec;
//	int ival;
//
//	cout << "Please start inputing integers:" << endl;
//
//	while (cin >> ival)
//	{
//		ivec.push_back(ival);
//	}
//	int sum = 0;
//	for (int ix = 0; ix < ivec.size(); ++ix)
//	{
//		sum += ivec[ix];
//	}
//	double average = double(sum) / ivec.size();
//
//	cout << "Sum of " << ivec.size() << " elements:"
//		<< sum << ". Average:" << average << endl;
//
//	return 0;
//}


// array_style
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	const int array_size = 128;
	int ia[array_size];
	int ival, icnt = 0;

	cout << "Please start inputing integers:" << endl;

	while (cin >> ival && icnt < array_size)
	{
		ia[icnt++] = ival;
	}
	int sum = 0;
	for (int ix = 0; ix < icnt; ++ix)
	{
		sum += ia[ix];
	}
	double average = double(sum) / icnt;

	cout << "Sum of " << icnt << " elements:"
		<< sum << ". Average:" << average << endl;

	return 0;
}




