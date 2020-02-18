#include <numeric>
#include <iostream>
#include <iterator>
#include <memory>

using namespace std;


int main()
{
	unique_ptr<string> pname ( new string ("Algermon") );
	cout << *pname << endl;

	return 0;
}