#include <numeric>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>

using namespace std;

class Box
{
private:
	double length, width, height;
public:
	Box(double length, double width, double height)
		: length(length), width(width), height(height)
	{}

	double getLength() const
	{
		return this->length;
	}

	double getWidth() const
	{
		return this->width;
	}

	double getHeight() const
	{
		return this->height;
	}

};

class Volume
{
public:
	double operator()(double x, double y, double z)
	{
		return x * y * z;
	}

	double operator()(const Box& box)
	{
		return box.getLength() * box.getWidth() * box.getHeight();
	}
};

int main()
{
	Volume volume;
	Box box( 1.0, 2.0, 3.0 );
	cout << "상자의 두피" << volume(box) << endl;
	return 0;
}