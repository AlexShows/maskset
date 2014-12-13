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
	// TODO
}

void args_test(arguments* args)
{
	args->list_arguments();

	std::string result;
	int index = 2;
	bool success = args->get_argument_by_index(index, result);

	if (success)
		std::cout << "Argument by index " << index << " returned " << result << std::endl;
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
//	args_test(args);

	if (args->get_argument_by_parameter("V"))
		display_version_info();

	std::cout << "Ironically press Enter to Exit...";
	std::cin.get();

	return 0;
}