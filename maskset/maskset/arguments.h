/**********
Definition of the arguments class

Copyright (C) 2014 Alex Shows
Released under the MIT License

The arguments class accepts the number of arguments, 
and a pointer to the character arrays of the arguments.

It takes these and parses them, grouping them into 
pairs if a dash or dashes are found.

The character arrays are copied into a vector of
pairs of strings, so once initialized, those variables
can go out of scope.
***********/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <exception>

class arguments
{
public:
	arguments(int argc, char** argv);
	~arguments();
	bool get_argument_by_parameter(std::string param, std::string& argument);
	bool get_argument_by_parameter(std::string param);
	bool get_argument_by_index(unsigned int index, std::string& argument);
	void list_arguments();
private:
	std::vector<std::pair<std::string, std::string>> opts;

};