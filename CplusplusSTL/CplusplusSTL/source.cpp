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
	cout << "단어는 공백으로 구분해서 입력하세요. 종료하려면 다음 줄에서 Ctrl+Z를 입력하세요" << endl;

	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(words));	// words에 입력
	
	cout << "정렬을 시작합니다" << endl;
	bool out_of_order = false;
	auto last = end(words);
	while (true)
	{
		for (auto first = begin(words) + 1; first != last; ++first)
		{
			if (*(first - 1) > * first) // 정렬 안되어있으면 교환
			{
				swap(*first, *(first - 1));
				out_of_order = true;
			}
		}
		if (!out_of_order)		// 정렬된 상태라면
			break;
		out_of_order = false;	// 그렇지 않으면 반복
	}


	cout << "오름차순으로 정렬된 단어: " << endl;
	copy(begin(words), end(words), ostream_iterator<string>(cout, " "));

	vector<string> words_copy = { make_move_iterator(begin(words)), make_move_iterator(end(words)) };
	cout << "\nwords에서 원소들을 이동한 후에 words_copy의 내용:" << endl;
	copy(begin(words_copy), end(words_copy), ostream_iterator<string>(cout, " "));
	cout << endl;

	cout << "\nwords 벡터는 원소 " << words.size() << "개를 갖고 있습니다\n";
	if (words.front().empty())
		cout << "첫번째 원소는 빈 문자열 객체입니다." << endl;

	cout << "첫번째 원소는 \"" << words.front() << "\"입니다." << endl;


	return 0;
}