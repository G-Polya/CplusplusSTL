#include <iostream>
#include <queue>
#include <string>

using namespace std;

template<typename T>
void list_pq(priority_queue<T> pq, size_t count = 5)
{
	size_t n = count;
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
		if (--n)
			continue;
		cout << endl;
		n = count;
	}
	cout << endl;
}

int main()
{
	priority_queue<string> words;
	string word;
	cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
	while (true)
	{
		if ((cin>>word).eof())
			break;
		words.push(word);

	}
	cout << "You entered " << words.size() << " words" << endl;
	list_pq(words);

	return 0;
}