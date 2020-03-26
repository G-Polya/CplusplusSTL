#pragma once
#include "header.h"

class Carton : public Box
{
public:
	explicit Carton(size_t l =1, size_t w=1, size_t h =1)
		: Box(l,w,h)
	{}

	double volume() const override
	{
		return 0.85 * Box::volume();
	}
};