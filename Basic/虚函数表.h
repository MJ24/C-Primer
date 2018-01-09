#pragma once
#include <iostream>
using namespace std;
using Funcp = void(*)(void);
class 虚函数表
{
public:
	static void showUsage()
	{
		/* VS Debug选择x86才可运行，选x64抛异常 */
		Base b;
		cout << "虚函数表的地址：" << (int*)(&b) << endl; //等于&b地址转成int指针是为了后面取各虚函数
		cout << "第1个虚函数f的地址：" << (int*)*((int*)(&b) + 0) << endl;
		cout << "第2个虚函数g的地址：" << (int*)*((int*)(&b) + 1) << endl;
		cout << "第3个虚函数h的地址：" << (int*)*((int*)(&b) + 2) << endl;
		Funcp fp = nullptr;
		fp = (Funcp)*((int*)*(int*)(&b) + 0); fp(); //f()
		fp = (Funcp)*((int*)*(int*)(&b) + 1); fp(); //g()
		fp = (Funcp)*((int*)*(int*)(&b) + 2); fp(); //h()

		DeriveWithoutOverride son1;
		fp = (Funcp)*((int*)*(int*)(&son1) + 0); fp(); //f()
		fp = (Funcp)*((int*)*(int*)(&son1) + 1); fp(); //g()
		fp = (Funcp)*((int*)*(int*)(&son1) + 2); fp(); //h()
		fp = (Funcp)*((int*)*(int*)(&son1) + 3); fp(); //f1()
		fp = (Funcp)*((int*)*(int*)(&son1) + 4); fp(); //g1()
		//fp = (Funcp)*((int*)*(int*)(&son1) + 5); fp(); //报错，不能打出z，z不是虚函数

		DeriveWithOverride son2;
		fp = (Funcp)*((int*)*(int*)(&son2) + 0); fp(); //DeriveWithOverride::f()
		fp = (Funcp)*((int*)*(int*)(&son2) + 1); fp(); //g()
		fp = (Funcp)*((int*)*(int*)(&son2) + 2); fp(); //h()
		fp = (Funcp)*((int*)*(int*)(&son2) + 3); fp(); //g1()
	}
private:
	class Base
	{
	public:
		virtual void f() { cout << "f()" << endl; }
		virtual void g() { cout << "g()" << endl; }
		virtual void h() { cout << "h()" << endl; }
	};
	class DeriveWithoutOverride : public Base
	{
	public:
		virtual void f1() { cout << "f1()" << endl; }
		virtual void g1() { cout << "g1()" << endl; }
		void z() { cout << "z()" << endl; }
	};
	class DeriveWithOverride : public Base
	{
	public:
		virtual void f() { cout << "DeriveWithOverride::f()" << endl; }
		virtual void g1() { cout << "g1()" << endl; }
	};
};