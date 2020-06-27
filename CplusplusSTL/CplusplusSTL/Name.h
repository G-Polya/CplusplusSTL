#pragma once

#include <string>
#include <ostream>
#include <istream>

using namespace std;

class Name
{
private:
	string first{};
	string second{};

public:
	Name(const string& name1, const string& name2)
		:first(name1), second(name2)
	{}

	Name() = default;

	bool operator<(const Name& name) const
	{
		return second < name.second || (second == name.second && first < name.first);
	}

	friend istream& operator >> (istream& in, Name& name);
	friend ostream& operator << (ostream& out, const Name& box);
};

inline istream& operator>>(istream& in, Name& name)
{
	in >> name.first >> name.second;
	return in;
}

inline ostream& operator << (ostream& out, const Name& name)
{
	out << name.first + " " + name.second;
	return out;
}