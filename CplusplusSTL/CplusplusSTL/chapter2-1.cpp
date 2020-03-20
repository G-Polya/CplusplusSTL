#include <iostream>
#include <array>
#include <functional>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename Iter>
void list_elements(Iter begin, Iter end)
{
	size_t perline = 8;
	size_t count = 0;
	while (begin != end)
	{
		cout << *begin++;
		if (++count % perline == 0)
			cout << "\n";
		cout << " ";
	}
}


int main()
{
	function<int(int)> fibonacci;

	fibonacci = [&fibonacci](int no) ->int
	{
		if (no == 0)
			return 0;
		else if (no == 1 || no == 2)
			return 1;
		else
			return fibonacci(no - 1) + fibonacci(no - 2);
	};

	array<int, 30> arr = {};
	
	for (int i = 0; i < arr.size() ; i++)
	{
		
		arr[i] = fibonacci(i);
	}
	list_elements(arr.begin(), arr.end());
	

	


	return 0;
}