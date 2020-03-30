#include <iostream>
#include <deque>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	deque<string> deq_string;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(deq_string));
	copy(begin(deq_string), end(deq_string), ostream_iterator<string>(cout, " "));
	cout << endl;
	cout << endl;

	list<string> stringList;


	for (size_t i = 0; i < deq_string.size(); i++)
	{
		stringList.push_back(deq_string[i]);
	}


	copy(begin(stringList), end(stringList), ostream_iterator<string>(cout, " "));
	cout << endl;

	stringList.sort();
	
	copy(begin(stringList), end(stringList), ostream_iterator<string>(cout, " "));
	cout << endl;


	return 0;
}