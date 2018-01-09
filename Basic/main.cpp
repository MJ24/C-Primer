#include <iostream>
#include "string_usage.h"
#include "sstream_usage.h"
#include "map_usage.h"
#include "sizeof_usage.h"
#include "虚函数表.h"
#include "str_blob.h"
using namespace std;

int main()
{
	StrBlob sb;
	sb.show_usage();
	//StringUsage::showUsage();
	//SizeofUsage::showUsage();
	//SstreamUsage::showUsage();
	//MapUsage mu;
	//mu.showUsage();

	//虚函数表::showUsage();
	system("pause");
	return 0;
}