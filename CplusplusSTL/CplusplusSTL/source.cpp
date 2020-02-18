#include <numeric>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

using namespace std;


int main()
{
	shared_ptr<double> pdata(new double(999.9));

	auto pdata2 = make_shared<double>(999.8);

	cout << *pdata <<" "<<*pdata2 << endl;
	return 0;
}