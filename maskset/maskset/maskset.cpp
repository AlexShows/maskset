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

int main(int argc, char** argv)
{
	std::vector<std::pair<std::string, std::string>> opts;

	/************
	Options:
	-g GROUP		Processor Group, to which thread(s) will be masked
	-m MASK			Mask to apply to the THREAD_ID or all threads of the PROCESS_ID
	-p PROCESS_ID	Process ID, if specified, where all threads will be set to the MASK provided
	-t THREAD_ID	Thread ID, if specified, will be set to the MASK provided
	-n PROCESS_NAME	String specifying a process name to be masked (all processes matching will be masked)
	-V --version	Display version information
	*************/
	
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
				std::cout << "Missing the argument for the parameter " << argv[i] << std::endl;
			}
		}
		else
		{
			opts.push_back(std::make_pair(std::string(argv[i]), std::string()));
		}
	}

	std::cout << "Options found: " << std::endl;
	for (auto & it : opts)
	{
		std::cout << it.first << " : " << it.second << std::endl;
	}

	std::cout << "Ironically press Enter to Exit...";
	std::cin.get();

	return 0;
}