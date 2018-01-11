#include "text_query.h"
#include<sstream>

TextQuery::TextQuery(istream &is)
{
	data = make_shared<vector<string>>();
	string line;
	unsigned lineNum = 0;
	while (getline(is, line))
	{
		++lineNum;
		data->push_back(line);
		string word;
		istringstream iss(line);
		while (iss >> word)
		{
			auto it = wordMap.find(word);
			if (it != wordMap.end())
			{
				++(it->second.first);
				it->second.second->insert(lineNum);
			}
			else
				wordMap.insert(make_pair(word, make_pair(1, new set<unsigned>{ lineNum })));
		}
	}
}

QueryResult TextQuery::query(const string &word) const
{
	auto it = wordMap.find(word);
	if (it != wordMap.end())
		return QueryResult(word, it->second.first, data, it->second.second);
	return QueryResult(word, 0, nullptr, nullptr);
}
