#include<iostream>
#include<string>
using namespace std;

class String_usage
{
private:
	//用auto+范围for遍历
	static string toUpper(const string &org)
	{
		string result;
		for (auto c : org)
			result += toupper(c);
		return result;
	}
	//用引用+范围for遍历并直接修改
	static void toLower(string &org)
	{
		for (auto &c : org)
			c = tolower(c);
	}
	//用decltype+下标遍历并直接修改
	static void headUp(string &org)
	{
		for (decltype(org.size()) i = 0; i < org.size() && !isspace(org[i]); ++i)
			org[i] = toupper(org[i]);
	}
	//用auto+迭代器iterator遍历并直接修改
	static void headDown(string &org)
	{
		for (auto it = org.begin(); it != org.end() && !isspace(*it); ++it)
			*it = tolower(*it);
	}
public:
	static void show_usage()
	{
		string st1 = "hello world!";
#pragma region 字符串遍历等操作
		string st2 = toUpper(st1);
		cout << st2 << endl;
		toLower(st2);
		cout << st2 << endl;
		headUp(st2);
		cout << st2 << endl;
		headDown(st2);
		cout << st2 << endl;
#pragma endregion
	}
};