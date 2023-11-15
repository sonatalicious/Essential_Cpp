#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

class UserProfile {
public:
	enum uLevel{Beginner, Intermediate, Advanced, Guru};
	UserProfile(string login, uLevel = Beginner);
	UserProfile();

	bool operator==(const UserProfile&);
	bool operator!=(const UserProfile&);

	// 读数据
	string login() const { return _login; };
	string user_name() const { return _user_name; }
	int login_count() const { return _times_logged; }
	int guess_count() const { return _guesses; }
	int guess_correct() const { return _correct_guesses; }
	double guess_average() const;
	string level() const;

	// 写数据
	void reset_login(const string& val) { _login = val; }
	void user_name(const string& val) { _user_name = val; }
	void reset_level(const string&);
	void reset_level(uLevel newlevel) { _user_level = newlevel; }
	void reset_login_count(int val) { _times_logged = val; }
	void reset_guess_count(int val) { _guesses = val; }
	void reset_guess_correct(int val) { _correct_guesses = val; }
	void bump_login_count(int cnt = 1) { _times_logged += cnt; }
	void bump_guess_count(int cnt = 1) { _guesses += cnt; }
	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }

private:
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	uLevel _user_level;
	static map<string, uLevel> _level_map;
	static void init_level_map();
	static string guest_login();

};

inline double UserProfile::guess_average() const
{
	return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}

inline UserProfile::UserProfile(string login, uLevel level) 
	: _login(login), _user_level(level), _times_logged(1), _guesses(0), _correct_guesses(0)
{}


#include <cstdlib>

inline UserProfile::UserProfile()
	: _login("guest"), _user_level(Beginner), _times_logged(1), _guesses(0), _correct_guesses(0)
{
	static int id = 0;
	char buffer[16];

	_itoa_s(id++, buffer, 10);
	_login += buffer;
}

inline bool UserProfile::
operator==(const UserProfile& rhs)
{
	if (_login == rhs._login &&
		_user_name == rhs._user_name)
		return true;
	return false;
}

inline bool UserProfile::
operator !=(const UserProfile& rhs) { return !(*this == rhs); }
inline string UserProfile::level() const {
	static string _level_table[] = {
	"Beginner", "Intermediate", "Advanced", "Guru" };
	return _level_table[_user_level];
}

ostream& operator<<(ostream& os, const UserProfile& rhs)
{ // output of the form: stanl Beginner 12 100 10 10%
	os << rhs.login() << ' '
		<< rhs.level() << ' '
		<< rhs.login_count() << ' '
		<< rhs.guess_count() << ' '
		<< rhs.guess_correct() << ' '
		<< rhs.guess_average() << endl;
	return os;
}

// overkill ... but it allows a demonstration ...
map<string, UserProfile::uLevel> UserProfile::_level_map;
void UserProfile::init_level_map() {
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}
inline void UserProfile::reset_level(const string& level) {
	map<string, uLevel>::iterator it;
	if (_level_map.empty())
		init_level_map();
	// confirm level is a recognized user level ...
	_user_level =
		((it = _level_map.find(level)) != _level_map.end())
		? it->second : Beginner;
}
istream& operator>>(istream& is, UserProfile& rhs)
{ // yes, this assumes the input is valid ...
	string login, level;
	is >> login >> level;
	int lcount, gcount, gcorrect;
	is >> lcount >> gcount >> gcorrect;
	rhs.reset_login(login);
	rhs.reset_level(level);
	rhs.reset_login_count(lcount);
	rhs.reset_guess_count(gcount);
	rhs.reset_guess_correct(gcorrect);
	return is;
}




