#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class StringBad
{
private:
	char *str;
	int len;
	static int num_strings;

public:
	StringBad(const char *s);
	StringBad();
	~StringBad();
	StringBad(const StringBad& st);
	
	StringBad& operator=(const StringBad& st);

	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);

};