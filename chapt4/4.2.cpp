#include <iostream>
#include "Stack.h"
using namespace std;


int main()
{
	Stack st;
	string str;

	while (cin >> str && !st.full() && str != "EndNow!")
		st.push(str);

	if (st.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n";
		return 0;
	}

	st.peek(str);
	if (st.size() == 1 && str.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n";
		return  0;
	}

	cout << '\n' << "Read in " << st.size() << " stirngs!\n";
	cin.clear(); // ��� end-of-file ���趨
	
	cout << "what word to search for? ";
	cin >> str;

	bool found = st.find(str);
	int count = found ? st.count(str) : 0;

	cout << str << (found ? " is " : " isn't ") << " in the stack. ";
	if (found)
		cout << "It occurs " << count << " times\n";

}

