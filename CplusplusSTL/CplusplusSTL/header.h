#pragma once
#include <iostream>
#include <istream>
#include <utility>

using namespace std::rel_ops;

class Box
{
protected:
	size_t length = 0;
	size_t width = 0;
	size_t height = 0;

public:
	explicit Box(size_t l = 1, size_t w = 1, size_t h = 1)
		: length(l), width(w), height(h)
	{}
	virtual ~Box() = default;


	virtual inline double volume() const
	{
		return length * width * height;
	}

	bool operator<(const Box& box) const
	{
		return volume() < box.volume();
	}
	
	bool operator==(const Box& box) const
	{
		return length == box.length && width == box.width && height == box.height;
	}

	virtual std::istream& read(std::istream& in);
	virtual std::ostream& write(std::ostream& out) const;

};