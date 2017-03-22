#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "person_info.h"

class SstreamUsage
{
public:
	static void showUsage()
	{
		setPersonInfo();
	}
private:
	static void setPersonInfo()
	{
		std::string line, word;
		std::vector<PersonInfo> persons;
		while (getline(std::cin, line))
		{
			PersonInfo p;
			std::istringstream iss(line);
			iss >> p.name;
			while (iss >> word)
			{
				p.phones.push_back(word);
			}
			persons.push_back(p);
			std::cout << "Finished recording " + p.name + "'s info.\n";
		}
	}
};

