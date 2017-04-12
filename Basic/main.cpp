#include <iostream>
#include "string_usage.h"
#include "sstream_usage.h"
#include "map_usage.h"
using namespace std;

int main()
{
	//StringUsage::showUsage();
	//SstreamUsage::showUsage();
	MapUsage mu;
	mu.show_usage();
	system("pause");
	return 0;
}