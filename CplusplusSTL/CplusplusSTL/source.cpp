#include <numeric>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

using namespace std;


int main()
{
	string name = "Jack";
	auto pname = make_unique<string>(name);

	cout << "string��ü name�� �ּ�: " << &name << endl;
	cout << "string��ü name�� ����: " << name << endl;
	cout << "����ũ ������ ��ü pname�� �ּ�: " << &pname << endl;
	cout << "����ũ ������ ��ü pname��: " << pname << endl;
	cout << "����ũ ������ ��ü pname���� ����Ű�� ����: " << *pname << endl << endl;

	int num = 10;
	auto pnum = make_unique<int>(num);
	cout << "int�� num�� �ּ�: " << &num << endl;
	cout << "int�� num�� ��: " << num << endl;
	cout << "����ũ ������ ��ü pnum�� �ּ�: " << &pnum << endl;
	cout << "����ũ ������ ��ü pnum�� ��: " << pnum << endl;
	cout << "����ũ ������ ��ü pnum�� ���� ����Ű�� ����: " << *pnum << endl << endl;

	int* num2 = (int*)malloc(sizeof(int));
	*num2 = 20;
	cout << "malloc int�� num2�� �ּ�: " << &num2 << endl;
	int* num3 = new int(30);
	cout << "new int�� num3�� �ּ�:" << &num3 << endl;

	return 0;
}