#pragma once
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Quotations
{
private:
	vector<string> quotes;

public:
	Quotations& operator<<(const char* quote)
	{
		quotes.emplace_back(quote);
		return *this;
	}

	Quotations& operator<<(const string& quote)
	{
		quotes.emplace_back(quote);
		return *this;
	}

	Quotations& operator<<(string&& quote)
	{
		quotes.push_back(move(quote));
		return *this;
	}

	string& operator[](size_t index)
	{
		if (index < quotes.size())
			return quotes[index];
		else
			throw out_of_range("Invalid index to quotations.");

	}

	size_t size() const
	{
		return quotes.size();
	}

	vector<string>::iterator begin()
	{
		return std::begin(quotes);
	}

	vector<string>::const_iterator begin() const
	{
		return std::begin(quotes);
	}

	vector<string>::iterator end()
	{
		return std::end(quotes);
	}

	vector<string>::const_iterator end() const
	{
		return std::end(quotes);
	}
};