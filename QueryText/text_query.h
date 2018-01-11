#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<memory>
#include "query_result.h"

using namespace std;

class TextQuery
{
public:
	TextQuery(istream &is);
	QueryResult query(const string &word) const;
private:
	shared_ptr<vector<string>> data;
	unordered_map<string, pair<unsigned, shared_ptr<set<unsigned>>>> wordMap;
};

