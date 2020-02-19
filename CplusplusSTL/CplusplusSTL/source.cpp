#include <numeric>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>
#include <string>
#include <functional>

using namespace std;


int main()
{
	string str1[] = { "I am", "Gundam","내가","건담이다" };
	

	function<string(string)> op = [](string str)
	{
		for (auto iter = begin(str); iter != end(str); iter++)
		{
			*iter = toupper(*iter);
		}

		return str;
	};

	transform(begin(str1), end(str1), ostream_iterator<string>(cout, "\n"), op);

	return 0;
}