#pragma once
#include<memory>
#include<vector>
#include<set>

using namespace std;

class QueryResult
{
public:
	QueryResult(const string &, unsigned, shared_ptr<vector<string>>, shared_ptr<set<unsigned>>);
	void print() const;
private:
	string word;
	unsigned wordCount;
	shared_ptr<vector<string>> data;
	shared_ptr<set<unsigned>> lineNums;
};

