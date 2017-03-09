#include<iostream>
#include<string>
using namespace std;

class String_usage
{
private:
	static string toUpper(const string &org)
	{
		string result;
		for (auto c : org)
			result += toupper(c);
		return result;
	}
	static void toLower(string &org)
	{
		for (auto &c : org)
			c = tolower(c);
	}
	static void headUp(string &org)
	{
		for (decltype(org.size()) i = 0; i < org.size() && !isspace(org[i]); ++i)
			org[i] = toupper(org[i]);
	}
public:
	static void show_usage() 
	{
		string st1 = "hello world!";
		string st2 = toUpper(st1);
		cout << st2 << endl;
		toLower(st2);
		cout << st2 << endl;
		headUp(st2);
		cout << st2 << endl;
	}
};