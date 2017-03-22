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
		std::vector<PersonInfo> persons;
		setPersonInfo(persons);
		printPersonInfo(persons);
	}
private:
	static void setPersonInfo(std::vector<PersonInfo> &persons)
	{
		std::cout << "Please input persons info(name phone1 phone2...):\n";
		std::string line, word;
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

	static void printPersonInfo(std::vector<PersonInfo> &persons)
	{
		ostringstream oss;
		for (auto person : persons)
		{
			oss << "Name: " << person.name << "\tPhone(s): ";
			for (auto phone : person.phones)
			{
				oss << phone << "\t";
			}
			oss << "\n";
		}
		std::cout << oss.str();
	}
};

