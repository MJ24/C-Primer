#include<iostream>
#include<fstream>
#include "query_result.h"
#include "text_query.h"

int main()
{
	ifstream ifs("./textFile.txt");
	TextQuery tq(ifs);
	QueryResult qr1 = tq.query("this");
	qr1.print();
	tq.query("a").print();
	tq.query("null").print();
	system("pause");
	return 0;
}