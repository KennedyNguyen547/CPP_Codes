





#include <iostream>

#include <stack>

#include <string>

void post_fix(std::string post_fix_expression);


int main()
{
	bool keep_running = true;
	std::string input;

	std::cout << "post fix calculator \n";
	do
	{
		std::getline(std::cin, input);
		if (input != "quit")
		{
			post_fix(input);
		}
		else
		{
			keep_running = false;
		}

	} while (keep_running);

	return 0;
}


void post_fix(std::string post_fix_expression)
{
	std::stack<std::string> operator_stack;
	std::stack<long int> operand_stack;


	std::string some_string = " ";

	if (post_fix_expression[0] != ' ')
	{
		some_string = some_string.append(post_fix_expression);
	}
	if (post_fix_expression[post_fix_expression.length() - 1] != ' ')
	{
		some_string.append(" ");
	}


	size_t previous_space = 0;
	size_t next_space;

	// first loop reads operands
	// if an operator is encountered, stop the loop
	for (size_t i = 1; i < some_string.length(); i++)
	{
		if (some_string[i] == ' ')
		{
			next_space = i;

			size_t current_substring_len = next_space - previous_space - 1;
			std::string sub_string = some_string.substr(previous_space + 1, current_substring_len);

			/*
			std::cout << "round i: " << i << "\n";
			std::cout << previous_space << "\n";
			std::cout << next_space << "\n";

			std::cout << current_substring_len << "\n";
			std::cout << sub_string << "\n\n";
			*/

			// error #4
			if (sub_string[0] == '-')
			{
				if (sub_string[1] > '9' || sub_string[1] < '0')
				{
					std::cout << "ERROR #4 \n";
					return;
				}

			}
			else if (sub_string[0] == '+' || sub_string[0] == '*' || sub_string[0] == '/')
			{
				break;
			}
			


			if (sub_string != "+" || sub_string != "-" || sub_string != "/" || sub_string != "*" || sub_string != " ")
			{
				operand_stack.push(std::stol(sub_string));
				previous_space = next_space;
			}
			else if (sub_string == "+" || sub_string == "-" || sub_string == "/" || sub_string == "*")
			{
				break;
			}
			// error case #1
			else if (sub_string == " ")
			{
				std::cout << "ERROR #1 \n";
				return;

			}

		}

	}

	//std::cout << " i made it here\n";

	size_t old_previous_space = previous_space;


	// second loop reads operators
	for (size_t i = some_string.length() - 1; i > old_previous_space; i--)
	{

		if ((some_string[i] == '+' || some_string[i] == '-' || some_string[i] == '/' || some_string[i] == '*'))
		{
			operator_stack.push(std::string(1,some_string[i]));
		}
			// error case #2
		else if ((some_string[i] == ' '))
		{

		}
		else
		{
			std::cout << "ERROR #2 \n";
			return;
		}

	}

	long int current_operand_value = operand_stack.top();
	operand_stack.pop();

	//std::cout << operand_stack.size();
	//std::cout << operator_stack.size();

	while (!operand_stack.empty() && !operator_stack.empty())
	{
		if (operator_stack.top() == "*")
		{
			current_operand_value *= operand_stack.top();
			operand_stack.pop();
			operator_stack.pop();
		}
		else if (operator_stack.top() == "-")
		{
			current_operand_value = operand_stack.top() - current_operand_value;
			operand_stack.pop();
			operator_stack.pop();
		}
		else if (operator_stack.top() == "+")
		{
			current_operand_value += operand_stack.top();
			operand_stack.pop();
			operator_stack.pop();
		}
		else if (operator_stack.top() == "/")
		{
			// error case #3
			if (current_operand_value == 0)
			{
				std::cout << "ERROR #3 \n";
				return;
			}
			else
			{
				current_operand_value = operand_stack.top() / current_operand_value;
				operand_stack.pop();
				operator_stack.pop();
			}
		}

	}

	if (operand_stack.empty() && operator_stack.empty())
	{
		std::cout << current_operand_value << "\n";
		return;
	}
	// error # 5
	else if ((operand_stack.empty() && !operator_stack.empty()) || (!operand_stack.empty() && operator_stack.empty()))
	{
		std::cout << "ERROR #5 \n";
		return;
	}
	return;

}








