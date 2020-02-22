#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
using namespace std;


int main()
{
	deque<string> names;
	cout << "Enter first names separated by spaces. Enter Ctrl+Z on a new line to end: \n";
	copy(istream_iterator<string>(cin), istream_iterator<string>(), front_inserter(names));

	cout << "\nIn reverse order, the names you entered are:\n";
	copy(begin(names), end(names), ostream_iterator<string>(cout, " "));

	cout << endl;

	return 0;
}