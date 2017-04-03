#include <cstring>
#include "Header.h"
using std::cout;


//C스타일 문자열로부터 StringBad를 생성
StringBad::StringBad(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 객체 생성\n";
}

//default constructor
StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 디폴트 객체 생성\n";
}

//꼭 필요한 파괴자
StringBad::~StringBad()
{
	cout << "\"" << str << "\" 객체파괴, ";
	--num_strings;
	cout << "남은 객체 수: " << num_strings << "\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}