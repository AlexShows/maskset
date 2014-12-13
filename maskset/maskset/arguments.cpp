/**********
Implementation of the arguments class

Copyright (C) 2014 Alex Shows
Released under the MIT License

***********/

#include "arguments.h"

arguments::arguments(int argc, char** argv)
{
	for (int i = 0; i < argc; i++)
	{
		// Check to see if we have a dash "-" as the first character, 
		// in which case this is a pair
		if (argv[i][0] == '-')
		{
			if (i + 1 < argc)
			{
				opts.push_back(std::make_pair(std::string(argv[i]), std::string(argv[i + 1])));
				i++;
			}
			else
			{
				std::cerr << "Missing the argument for the parameter " << argv[i] << std::endl;
			}
		}
		else
		{
			opts.push_back(std::make_pair(std::string(), std::string(argv[i])));
		}
	}
}

arguments::~arguments()
{

}

void arguments::list_arguments()
{
	std::cout << "Options found: " << std::endl;
	for (auto & it : opts)
	{
		std::cout << it.first << " : " << it.second << std::endl;
	}
}

// Returns the argument corresponding to the parameter provided
// For example, if arguments "-p foo" are provided, the param is "p"
// or "-p" or "--p" and the argument is "foo"
// Returns true if the parameter is found, false otherwise
bool arguments::get_argument_by_parameter(std::string param, std::string& argument)
{
	std::string param_alt1 = "-" + param;
	std::string param_alt2 = "--" + param;

	for (auto & it : opts)
	{
		if (it.first == param ||
			it.first == param_alt1 ||
			it.first == param_alt2)
		{
			argument = it.second;
			return true;
		}
	}

	return false;
}

// Checks whether an argument was passed or not
// Returns true if the parameter is found, false otherwise
bool arguments::get_argument_by_parameter(std::string param)
{
	std::string param_alt1 = "-" + param;
	std::string param_alt2 = "--" + param;

	for (auto & it : opts)
	{
		if (it.first == param ||
			it.first == param_alt1 ||
			it.first == param_alt2)
			return true;
	}

	return false;
}

// Returns the argument corresponding to the index provided
// NOTE: Does not return parameters - just the arguments corresponding to them
// That means if the arguments are "-p foo" then the -p is not returned and 
// does not have its own index. Rather, it shares the same index with foo,
// and foo is returned if index.
// Returns true if the parameter is found, false otherwise
bool arguments::get_argument_by_index(unsigned int index, std::string& argument)
{
	if (index >= opts.size())
		return false;

	unsigned int cnt = 0;
	for (auto &it : opts)
	{
		if (cnt == index)
		{
			argument = it.second;
			return true;
		}
		cnt++;
	}

	return false;
}