#pragma once
#include <iostream>
using namespace std;
using Funcp = void(*)(void);
class �麯����
{
public:
	static void showUsage()
	{
		/* VS Debugѡ��x86�ſ����У�ѡx64���쳣 */
		Base b;
		cout << "�麯����ĵ�ַ��" << (int*)(&b) << endl; //����&b��ַת��intָ����Ϊ�˺���ȡ���麯��
		cout << "��1���麯��f�ĵ�ַ��" << (int*)*((int*)(&b) + 0) << endl;
		cout << "��2���麯��g�ĵ�ַ��" << (int*)*((int*)(&b) + 1) << endl;
		cout << "��3���麯��h�ĵ�ַ��" << (int*)*((int*)(&b) + 2) << endl;
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
		//fp = (Funcp)*((int*)*(int*)(&son1) + 5); fp(); //�������ܴ��z��z�����麯��

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