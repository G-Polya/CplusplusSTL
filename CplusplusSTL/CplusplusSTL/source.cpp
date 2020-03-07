#include <iostream>
#include <list>
#include <string>
#include <functional>

using namespace std;

template<typename Iter>
void list_elements(Iter begin, Iter end)
{
	while (begin != end)
	{
		cout << *begin++ << endl;
	}
}

int main()
{
	list<string> proverbs;

	cout << "Enter a few proverbs and enter an empty line to end: " << endl;
	string proverb;
	while (getline(cin, proverb, '\n'), !proverb.empty())
		proverbs.push_front(proverb);
	cout << "Go on, just one more:" << endl;
	getline(cin, proverb, '\n');
	proverbs.emplace_back(proverb);

	cout << "\nThe elements in the list in reverse ordera are : " << endl;
	list_elements(rbegin(proverbs), rend(proverbs));

	proverbs.sort();
	cout << "\nYour proverbs in ascending sequence are: " << endl;
	list_elements(begin(proverbs), end(proverbs));

	proverbs.sort(greater<>());
	cout << "\nYour proverbs in descending sequence: " << endl;
	list_elements(begin(proverbs), end(proverbs));

	return 0;
}