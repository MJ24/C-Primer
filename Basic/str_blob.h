/*
Refer to C++ Primer P404, show how to share data and control ref count by shared_ptr in different objs.
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class StrBlob
{
public:
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
	string &front()
	{
		check(0, "Try to call front() for an empty StrBlob.");
		return data->front();
	}
	string &back()
	{
		check(0, "Try to call back() for an empty StrBlob.");
		return data->back();
	}
	void push_back(const string& str)
	{
		data->push_back(str);
	}
	void pop_back()
	{
		data->pop_back();
	}
	vector<string>::size_type size()
	{
		return data->size();
	}
	void printRefCount()
	{
		cout << "RefCount : " << data.use_count() << endl;
	}
	void show_usage()
	{
		vector<string> vec1 = { "Hello", "world" };
		vector<string> vec2 = vec1;
		vec2.pop_back();
		cout << vec2.back() << "/" << vec1.back() << endl; // Hello/world

		StrBlob sb1 = { "Hello", "world" };
		sb1.printRefCount(); // 1
		StrBlob sb2 = sb1;
		sb1.printRefCount(); // 2
		sb2.pop_back();
		cout << sb2.back() << "/" << sb1.back() << endl; // Hello/Hello
		if (sb2.size() == 1)
		{
			StrBlob tempSB = sb2;
			sb1.printRefCount(); // 3
			tempSB.pop_back();
		}
		sb1.printRefCount(); // 2
		cout << sb1.size() << endl; // 0
	}
private:
	shared_ptr<vector<string>> data;
	void check(int i, const string &msg) const
	{
		if (i >= data->size())
			throw out_of_range(msg);
	}
};