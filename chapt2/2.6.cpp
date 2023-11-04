#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename Type>
inline Type mymax(Type t1, Type t2)
{
	return t1 > t2 ? t1 : t2;
}

template <typename elemType>
inline elemType mymax(const vector<elemType> &vec)
{
	return *max_element(vec.begin(), vec.end());
}

template <typename arrayType>
inline arrayType mymax(const arrayType *parray, int size)
{
	return *max_element(parray, parray + size);
}

int main()
{
	string sarray[] = { "we", "were", "her", "pride", "of", "ten" };
	vector<string> svec(sarray, sarray + 6);

	int iarray[] = { 12, 70, 2, 169, 1, 5, 29 };
	vector<int> ivec(iarray, iarray + 7);

	float farray[] = { 2.5, 24.8, 18.7, 4.1, 23.9 };
	vector<float> fvec(farray, farray + 5);

	//这样是错误的，C2688错误码：对重载函数的调用不明确，网上查找问题，发现是自定义的max与库函数max起冲突了，将函数名都改为mymax，问题解决。
	//这是因为编写的重载模板函数max()与标准库中的max()发现了冲突。两者采用的定义方式相似，所以有多个重载函数与参数列表匹配。
	//int imax = max(max(ivec), max(iarray, 7));
	//float fmax = max(max(fvec), max(farray, 5));
	//string smax = max(max(svec), max(sarray, 6));
	// 
	// 另一个解决方案
	//cout << ::max(max(A), max(arr1, 5)) << endl;//系统自带一个max函数，::是作用域符号表示是调用本文件里的max函数，
	////如果不用::模板重载函数就会和系统函数冲突报错，或者你把max函数名改成max1就可以解决
	//cout << ::max(max(B), max(arr2, 5)) << endl;
	//cout << ::max(max(C), max(arr3, 5));

	int imax = mymax(mymax(ivec), mymax(iarray, 7));
	float fmax = mymax(mymax(fvec), mymax(farray, 5));
	string smax = mymax(mymax(svec), mymax(sarray, 6));




	cout << "imax should be 169  -- found: " << imax << "\n"
		<< "fmax should be 24.8 -- found: " << fmax << "\n"
		<< "smax should be were -- found: " << smax << "\n";
	return 0;
}
