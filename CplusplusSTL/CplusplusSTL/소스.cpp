#include <iostream>
#include <memory>
#include <vector>
#include "header.h"
#include "header2.h"

using namespace std;

int main()
{
	vector<unique_ptr<Box>> boxes;
	boxes.push_back(make_unique<Box>(1, 2, 3));
	boxes.push_back(make_unique<Carton>(1, 2, 3));
	boxes.push_back(make_unique<Carton>(4, 5, 6));
	boxes.push_back(make_unique<Box>(4, 5, 6));

	for (auto&& ptr : boxes)
		cout << *ptr << " volume is " << ptr->volume() << endl;

}