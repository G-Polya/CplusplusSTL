#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Header.h"

using std::cout;


int StringBad::num_strings = 0;


//C��Ÿ�� ���ڿ��κ��� StringBad�� ����
StringBad::StringBad(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" ��ü ����\n";
}

//default constructor
StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" ����Ʈ ��ü ����\n";
}

//�� �ʿ��� �ı���
StringBad::~StringBad()
{
	cout << "\"" << str << "\" ��ü�ı�, ";
	--num_strings;
	cout << "���� ��ü ��: " << num_strings << "\n";
	delete[] str;
}

//���������
StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ": \"" << str << "\"��ü ����\n";
}

//���Կ�����
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
