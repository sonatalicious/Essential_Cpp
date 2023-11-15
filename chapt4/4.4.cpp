#include <iostream>
#include "UserProfile.h"
using namespace std;


int main()
{
	UserProfile anon;
	cout << anon; // test out output operator
	UserProfile anon_too; // to see if we get unique id
	cout << anon_too;
	UserProfile anna("AnnaL", UserProfile::Guru);
	cout << anna;
	anna.bump_guess_count(27);
	anna.bump_guess_correct(25);
	anna.bump_login_count();
	cout << anna;
	cin >> anon; // test out input operator
	cout << anon;

}

