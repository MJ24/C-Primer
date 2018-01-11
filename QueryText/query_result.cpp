#include "query_result.h"
#include<iostream>
#include<string>

QueryResult::QueryResult(const string &word, unsigned wordCount, shared_ptr<vector<string>> data, shared_ptr<set<unsigned>> lineNums)
	: word(word), wordCount(wordCount), data(data), lineNums(lineNums)
{
}

void QueryResult::print() const
{
	cout << "Query word: " << word << endl;
	cout << "Word count: " << wordCount << endl;
	if (wordCount != 0)
	{
		for (auto lineNum : *lineNums)
		{
			cout << "(line " << lineNum << "): " << data->at(lineNum - 1) << endl;
		}
	}
	cout << endl;
}