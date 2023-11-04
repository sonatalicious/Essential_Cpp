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

	//�����Ǵ���ģ�C2688�����룺�����غ����ĵ��ò���ȷ�����ϲ������⣬�������Զ����max��⺯��max���ͻ�ˣ�������������Ϊmymax����������
	//������Ϊ��д������ģ�庯��max()���׼���е�max()�����˳�ͻ�����߲��õĶ��巽ʽ���ƣ������ж�����غ���������б�ƥ�䡣
	//int imax = max(max(ivec), max(iarray, 7));
	//float fmax = max(max(fvec), max(farray, 5));
	//string smax = max(max(svec), max(sarray, 6));
	// 
	// ��һ���������
	//cout << ::max(max(A), max(arr1, 5)) << endl;//ϵͳ�Դ�һ��max������::����������ű�ʾ�ǵ��ñ��ļ����max������
	////�������::ģ�����غ����ͻ��ϵͳ������ͻ�����������max�������ĳ�max1�Ϳ��Խ��
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
