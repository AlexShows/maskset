/**********
Definition of the arguments class

Copyright (C) 2014 Alex Shows
Released under the MIT License

The arguments class accepts the number of arguments, 
and a pointer to the character arrays of the arguments.

The character arrays are copied into a vector of a 
vector of strings, so once initialized, those variables
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
	bool get_arguments_by_parameter(std::string param, std::vector<std::string>& arguments);
	bool was_parameter_given(std::string param);
	bool get_arguments_by_index(unsigned int index, std::vector<std::string>& arguments);
	void list_arguments();
private:
	std::vector<std::vector<std::string>> opts;

};