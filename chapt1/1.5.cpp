//
//// string-style
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string user_name;
//	cout << "Please enter your name:";
//	cin >> user_name;
//
//	switch (user_name.size())
//	{
//		case 0:
//		{
//			cout << "Ah, the user with no name." << "Well ok, user with no name\n";
//		}
//		break;
//		case 1:
//		{
//			cout << "A 1-characher name? Hmm, have you read Kafka?:"
//				<< "hello," << user_name << endl;
//		}
//		break;
//		default:
//		{
//			cout << "Hello, " << user_name << "--Happy to make your acquaintance!\n";
//		}
//		break;
//	}
//
//	return 0;
//}


// c_style
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	const int nm_size = 128;
	char user_name[nm_size];
	cout << "Please enter your name:";
	cin >> setw(nm_size) >> user_name;

	switch (strlen(user_name))
	{
	case 0:
	{
		cout << "Ah, the user with no name." << "Well ok, user with no name\n";
	}
	break;
	case 1:
	{
		cout << "A 1-characher name? Hmm, have you read Kafka?:"
			<< "hello," << user_name << endl;
	}
	break;
	case 127:
	{
		cout << "That is a very big name indeed -- "
			<< "we may have to shorten it!\n"
			<< "In any case, ";

	}//注意这里直接向下运行case语句
	default:
	{
		cout << "Hello, " << user_name << " -- Happy to make your acquaintance!\n";
	}
	break;
	}

	return 0;
}






