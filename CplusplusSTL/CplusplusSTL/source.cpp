#include <numeric>
#include <iostream>
#include <iterator>

using namespace std;


int main()
{
	double data[] = { 2.5,4.56,55,58.5 };
	cout << "�迭 ���ҵ�:\n";
	for (auto iter = begin(data); iter != end(data); iter++)
	{
		cout << *iter << " ";
	}

	auto total = accumulate(begin(data), end(data), 0.0);
	cout << "\n�迭 ���ҵ��� �հ�: " << total << endl;

	return 0;
}