#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
	vector<string> words;
	words.push_back(string("facetious"));
	words.emplace_back("abstemious");

	string str = "alleged";
	words.emplace_back(str, 2, 3);

	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));


	return 0;
}