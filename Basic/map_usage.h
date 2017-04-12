#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;
class MapUsage
{
public:
	void show_usage()
	{
		//从字符串来翻译
		string transMapStr = "asap as soon as possible\n"
			"r are\n"
			"u you\n"
			"thk thanks!";
		string oringInfoStr = "where r u now?\n"
			"reply me asap\n"
			"thk\n";
		istringstream transMapIss(transMapStr);
		istringstream oringInfoIss(oringInfoStr);
		buildTransMap(transMapIss);
		transform(oringInfoIss);

		//从文件来翻译
		ifstream transMapIfs("./transMap.txt");
		ifstream oringInfoIfs("./oringInfo.txt");
		buildTransMap(transMapIfs);
		transform(oringInfoIfs);
	}
private:
	map<string, string> transMap;
	void buildTransMap(istream &ist)
	{
		string key, val;
		//这里直接先将ist的每行的第一个单词存入key
		//这行剩余的存入val，利用了istream的特性
		while (ist >> key && getline(ist, val))
		{
			//检查val有值并去掉前面的空格
			if (val.size() > 1)
				transMap[key] = val.substr(1);
		}
	}

	void transform(istream &oringInfoIst)
	{
		string line, word;
		//按行遍历oringInfoIst
		while (getline(oringInfoIst, line))
		{
			//用iss遍历line
			istringstream iss(line);
			bool firstWord = true;
			while (iss >> word)
			{
				if (firstWord)
					firstWord = false;
				else
					cout << " ";

				auto ret = transMap.find(word);
				if (ret != transMap.end())
					cout << ret->second;
				else
					cout << word;
			}
			cout << endl; //当前行结束
		}
	}
};