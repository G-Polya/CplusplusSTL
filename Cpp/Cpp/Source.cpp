#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Header.h"

using std::cout;


int StringBad::num_strings = 0;


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

//복사생성자
StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ": \"" << str << "\"객체 생성\n";
}

//대입연산자
StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
