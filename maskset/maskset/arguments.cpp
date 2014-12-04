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
			opts.push_back(std::make_pair(std::string(argv[i]), std::string()));
		}
	}
}

arguments::~arguments()
{

}

// Returns the argument corresponding to the parameter provided
// For example, if arguments "-p foo" are provided, the param is "p"
// or "-p" or "--p" and the argument is "foo"
// Throws an exception if no such parameter is found
void arguments::get_argument_by_parameter(std::string param, std::string& argument)
{
	// TODO
}

// Returns the argument corresponding to the index provided
// NOTE: Does not return parameters - just the arguments corresponding to them
// That means if the arguments are "-p foo" then the -p is not returned and 
// does not have its own index. Rather, it shares the same index with foo,
// and foo is returned if index.
// Throws an exception if the index is out of range
void get_argument_by_index(unsigned int index, std::string& argument)
{
	// TODO
}