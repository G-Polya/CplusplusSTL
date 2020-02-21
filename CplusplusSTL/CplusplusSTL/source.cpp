#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
	vector<string> words = { "one","three","eight" };
	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));
	cout << endl;
	auto iter = words.insert(++begin(words), "two");
	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));
	cout << endl;
	string more[] = { "five", "six", "seven" };
	iter = words.insert(--end(words), begin(more), end(more));
	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));
	cout << endl;
	iter = words.insert(end(words), "ten");
	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));
	cout << endl;

	iter = words.insert(end(words), { string("twelve"), string("thirteen") });
	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));
	cout << endl;

	return 0;
}