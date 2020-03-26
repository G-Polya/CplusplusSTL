#include <iostream>
#include "header.h"

std::istream& Box::read(std::istream& in)
{
	size_t value = 0;
	if ((in >> value).eof())
		return in;

	length = value;
	in >> width >> height;
	return in;
}

std::ostream& Box::write(std::ostream& out) const
{
	out << typeid(*this).name() << "(" << length << "," << width << "," << height << ")";
	return  out;
}

