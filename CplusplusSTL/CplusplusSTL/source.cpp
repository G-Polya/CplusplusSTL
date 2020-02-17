#include <numeric>
#include <iostream>
#include <iterator>

using namespace std;


int main()
{
	cout << "값은 공백으로 구분해서 입력하세요. 종료하려면 Ctrl+Z를 입력하세요: " << endl;

	cout << "\nThe sum of the values you entered is "
		<< accumulate(istream_iterator<double>(cin), istream_iterator<double>(), 0.0)
		<< endl;

	return 0;
}