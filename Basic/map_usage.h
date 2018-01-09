#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;
class MapUsage
{
public:
	void showUsage()
	{
		unordered_map<int, string> ump = { {24,"Nolan"},{23,"Echo"} };
		cout << ump.find(24)->second << endl;;
		for (unordered_map<int, string>::iterator it = ump.begin(); it != ump.end(); ++it)
		{
			cout << it->second << endl;
		}
	}
	void tansMap()
	{
		//���ַ���������
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

		//���ļ�������
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
		//����ֱ���Ƚ�ist��ÿ�еĵ�һ�����ʴ���key
		//����ʣ��Ĵ���val��������istream������
		while (ist >> key && getline(ist, val))
		{
			//���val��ֵ��ȥ��ǰ��Ŀո�
			if (val.size() > 1)
				transMap[key] = val.substr(1);
		}
	}

	void transform(istream &oringInfoIst)
	{
		string line, word;
		//���б���oringInfoIst
		while (getline(oringInfoIst, line))
		{
			//��iss����line
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
			cout << endl; //��ǰ�н���
		}
	}
};