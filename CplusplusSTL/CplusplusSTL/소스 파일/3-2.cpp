#include <iostream>
#include <stack>
#include <iterator>
#include <string>
#include <deque>
using namespace std;

template <typename T>
bool check_pailndrome(T stk, T reverse_stk)
{
	
	if (stk.top() == reverse_stk.top())
	{
		stk.pop();
		reverse_stk.pop();
		return true;

	}
	else
	{
		stk.pop();
		reverse_stk.pop();
		return false;
	}
	
	return check_pailndrome(stk, reverse_stk);
}

void print(bool check)
{
	if (check)
		cout << "회문입니다" << endl;
	else
		cout << "회문이 아닙니다" << endl;
}

int main()
{
	cout << "Input the string: ";
	deque<string> strList;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(strList));
	
	stack<string> stk(strList);
	stack<string> temp_stk = stk;
	stack<string> reverse_stk;

	while (!temp_stk.empty())
	{	
		reverse_stk.push(temp_stk.top());
		temp_stk.pop();
	}

	print(check_pailndrome(stk, reverse_stk));
	

	return 0;
	
	
}