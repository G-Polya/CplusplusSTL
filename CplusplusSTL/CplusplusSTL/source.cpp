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

	cout << "string객체 name의 주소: " << &name << endl;
	cout << "string객체 name의 내용: " << name << endl;
	cout << "유니크 포인터 객체 pname의 주소: " << &pname << endl;
	cout << "유니크 포인터 객체 pname값: " << pname << endl;
	cout << "유니크 포인터 객체 pname값이 가리키는 내용: " << *pname << endl << endl;

	int num = 10;
	auto pnum = make_unique<int>(num);
	cout << "int형 num의 주소: " << &num << endl;
	cout << "int형 num의 값: " << num << endl;
	cout << "유니크 포인터 객체 pnum의 주소: " << &pnum << endl;
	cout << "유니크 포인터 객체 pnum의 값: " << pnum << endl;
	cout << "유니크 포인터 객체 pnum의 값이 가리키는 내용: " << *pnum << endl << endl;

	int* num2 = (int*)malloc(sizeof(int));
	*num2 = 20;
	cout << "malloc int형 num2의 주소: " << &num2 << endl;
	int* num3 = new int(30);
	cout << "new int형 num3의 주소:" << &num3 << endl;

	return 0;
}