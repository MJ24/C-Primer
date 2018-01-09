#pragma once
#include <iostream>
using namespace std;

class SizeofUsage
{
public:
	static void showUsage()
	{
		int arr[] = { 1,2,3 };
		const size_t len = sizeof(arr) / sizeof(arr[0]);
		cout << "Arr length\t" << len << endl;
		int *parr = arr;
		int(&rarr)[3] = arr; // 等价于auto &rarr = arr;
		cout << "sizeof(arr)\t" << sizeof(arr) << endl;
		cout << "sizeof(parr)\t" << sizeof(parr) << endl;
		cout << "sizeof(rarr)\t" << sizeof(rarr) << endl;
		cout << "getArrSize(arr)\t" << getArrSize(arr) << endl;
	}
private:
	static int getArrSize(int arr[]/* 等价于int *arr */)
	{
		return sizeof(arr);
	}
};