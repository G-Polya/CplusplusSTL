#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Header.h"

using std::cin;
using std::cout;

//static 클래스 멤버를 초기화한다
int String::num_strings = 0;

//static 메서드
int String::HowMany()
{
	return num_strings;
}

//클래스 메서드
String::String(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String() //디폴트 생성자
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)	//복사 생성자
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;
}

//오버로드 연산자 메서드
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char *s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

//오버로딩 연산자 프렌드
bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	//return (std::strcmp(st1.str, st2.str) > 0);
	return st1.str > st2.str;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}