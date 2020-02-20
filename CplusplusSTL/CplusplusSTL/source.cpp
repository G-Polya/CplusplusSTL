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
	words.reserve(10);
	cout << "�ܾ�� �������� �����ؼ� �Է��ϼ���. �����Ϸ��� ���� �ٿ��� Ctrl+Z�� �Է��ϼ���" << endl;

	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(words));	// words�� �Է�
	
	cout << "������ �����մϴ�" << endl;
	bool out_of_order = false;
	auto last = end(words);
	while (true)
	{
		for (auto first = begin(words) + 1; first != last; ++first)
		{
			if (*(first - 1) > * first) // ���� �ȵǾ������� ��ȯ
			{
				swap(*first, *(first - 1));
				out_of_order = true;
			}
		}
		if (!out_of_order)		// ���ĵ� ���¶��
			break;
		out_of_order = false;	// �׷��� ������ �ݺ�
	}


	cout << "������������ ���ĵ� �ܾ�: " << endl;
	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));

	vector<string> words_copy = { make_move_iterator(begin(words)), make_move_iterator(end(words)) };
	cout << "\nwords���� ���ҵ��� �̵��� �Ŀ� words_copy�� ����:" << endl;
	copy(begin(words_copy), end(words_copy), ostream_iterator<string>(cout, " "));
	cout << endl;

	cout << "\nwords ���ʹ� ���� " << words.size() << "���� ���� �ֽ��ϴ�\n";
	if (words.front().empty())
		cout << "ù��° ���Ҵ� �� ���ڿ� ��ü�Դϴ�." << endl;

	cout << "ù��° ���Ҵ� \"" << words.front() << "\"�Դϴ�." << endl;


	return 0;
}