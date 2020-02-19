#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


int main()
{
	array<double, 4> these = { 1.0,2.0,3.0,4.0 };
	array<double, 4> those = { 1.0,2.0,3.0,4.0 };
	array<double, 4> them = { 1.0,3.0,3.0,4.0 };

	if (these == those)
		cout << "these and those are equal" << endl;
	if (those != them)
		cout << "those and them are not equal" << endl;
	if (those < them)
		cout << "those are less than them" << endl;
	if (them > those)
		cout << "them are greater than those" << endl;


	return 0;
}