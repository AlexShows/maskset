/*
maskset.cpp

Main entry point for the maskset utility

Given a process ID, process name, or thread ID, set the processor group
and affinity mask to a mask provided, causing the corresponding threads
to run only on the logical processors enabled by the bit mask.
*/

#include <iostream>
#include <vector>
#include <string>
#include "arguments.h"

#define MASKSET_VERSION "0.0.4"

void display_version_info()
{
	std::cout << "maskset version: " << MASKSET_VERSION << std::endl;
	std::cout << "Build date: " << __DATE__ << std::endl;
	std::cout << "Sets processor group and affinity mask for threads" << std::endl;
	std::cout << std::endl;
}

void args_test(arguments* args)
{
	args->list_arguments();

	std::vector<std::string> result;
	int index = 2;
	bool success = args->get_arguments_by_index(index, result);

	if (success)
	{
		std::cout << "Argument(s) by index " << index << " returned ";
		for (auto & it : result)
			std::cout << it << " ";
		std::cout << std::endl;
	}
	else
		std::cout << "Failed to get argument by index " << index << std::endl;
}

int main(int argc, char** argv)
{
	/************
	Options:
	-g GROUP		Processor Group, to which thread(s) will be masked
	-m MASK			Mask to apply to the THREAD_ID or all threads of the PROCESS_ID
	-p PROCESS_ID	Process ID, if specified, where all threads will be set to the MASK provided
	-t THREAD_ID	Thread ID, if specified, will be set to the MASK provided
	-n PROCESS_NAME	String specifying a process name to be masked (all processes matching will be masked)
	-V --version	Display version information
	*************/
	arguments* args = new arguments(argc, argv);
	args_test(args);

	if (args->was_parameter_given("V"))
		display_version_info();

	std::cout << "Ironically press Enter to Exit...";
	std::cin.get();

	return 0;
}