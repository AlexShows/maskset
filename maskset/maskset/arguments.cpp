/**********
Implementation of the arguments class

Copyright (C) 2014 Alex Shows
Released under the MIT License

***********/

#include "arguments.h"

arguments::arguments(int argc, char** argv)
{
	// the first argument is always the exe name/location
	std::vector<std::string> f;
	opts.push_back(f);
	opts.back().push_back(std::string(argv[0]));
	
	// If there is a second argument, it needs to be in a new vector
	if (argc > 1)
	{
		std::vector<std::string> second;
		opts.push_back(second);
	}

	// Now start with the second argument and add them
	for (int i = 1; i < argc; i++)
	{
		// If there's a dash, we're starting a new parameter's
		// vector of arguments
		if (argv[i][0] == '-')
		{
			std::string s(argv[i]);
			std::vector<std::string> v;
			v.push_back(s);
			opts.push_back(v);
		}
		else // Otherwise, no dash, so this argument is part of the last parameter
		{
			if (opts.size() == 0)
			{
				std::vector<std::string> f;
				opts.push_back(f);
			}
			opts.back().push_back(std::string(argv[i]));
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
		for (auto & p : it)
		{
			std::cout << p << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Returns the argument corresponding to the parameter provided
// For example, if arguments "-p foo" are provided, the param is "p"
// or "-p" or "--p" and the argument is "foo"
// Returns true if the parameter is found, false otherwise
bool arguments::get_arguments_by_parameter(std::string param, std::vector<std::string>& arguments)
{
	std::string param_alt1 = "-" + param;
	std::string param_alt2 = "--" + param;

	for (auto & it : opts)
	{
		if (it.front() == param ||
			it.front() == param_alt1 ||
			it.front() == param_alt2)
		{
			arguments = it;
			arguments.erase(it.begin());
			return true;
		}
	}

	return false;
}

// Checks whether a parameter was passed or not
// Returns true if the parameter is found, false otherwise
bool arguments::was_parameter_given(std::string param)
{
	std::string param_alt1 = "-" + param;
	std::string param_alt2 = "--" + param;

	for (auto & it : opts)
	{
		if (it.front() == param ||
			it.front() == param_alt1 ||
			it.front() == param_alt2)
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
bool arguments::get_arguments_by_index(unsigned int index, std::vector<std::string>& arguments)
{
	if (index >= opts.size())
		return false;

	unsigned int cnt = 0;
	for (auto &it : opts)
	{
		if (cnt == index)
		{
			arguments = it;
			return true;
		}
		cnt++;
	}

	return false;
}