#include <iostream>
#include <array>
#include <functional>
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
		cout << endl;
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

	array<int, 50> arr = {};
	cout << arr[0] << endl;
	arr[0] = fibonacci(1);
	
	for (int i = 0; i < 50; i++)
	{
		arr[i] = fibonacci(i);
	}


	cout << arr[0] << endl;
	return 0;
}