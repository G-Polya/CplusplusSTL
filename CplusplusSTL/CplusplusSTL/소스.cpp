#include <iostream>
#include <list>
#include <stack>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;

inline size_t precedence(const char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;

	throw runtime_error(string("invalid operator: ") + op);
}

double execute(stack<char>& ops, stack<double>& operands)
{
	double result = 0;
	double rhs = operands.top();
	operands.pop();
	double lhs = operands.top();
	operands.pop();

	switch (ops.top())
	{
	case '+':
		result = lhs + rhs;
		break;
	case '-':
		result = lhs - rhs;
		break;
	case '*':
		result = lhs * rhs;
		break;
	case '/':
		result = lhs / rhs;
		break;
	case '^':
		result = pow(lhs, rhs);
		break;
	default:
		throw runtime_error(string("invalid operator: ") + ops.top());
	}

	ops.pop();
	operands.push(result);
	return result;
}



int main()
{
	stack<double> operands;
	stack<char> operators;
	string exp;
	cout << "An arithmetic expression can include the operator +, -, *, / and ^ for exponetiation. " << endl;

	try
	{
		while (true)
		{
			cout << "Enter an arithmetic expression and press Enter - enter an empty line to end: " << endl;
			getline(cin, exp, '\n');
			if (exp.empty()) break;

			exp.erase(remove(begin(exp), end(exp), ' '), end(exp));

			size_t index = 0;

			operands.push(stod(exp, &index));

			while (true)
			{
				operators.push(exp[index++]);

				size_t i = 0;
				operands.push(stod(exp.substr(index), &i));
				index += i;
				if (index == exp.length())
				{
					while (!operators.empty())
						execute(operators, operands);
					break;
				}

				while (operators.empty() && precedence(exp[index]) != precedence(operators.top()))
					execute(operators, operands);
			}
			cout << "result = " << operands.top() << endl;
		}
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}

	cout << "Calculator ending..." << endl;
}