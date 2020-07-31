#include <iostream>
#include "header.h"

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

namespace po = boost::program_options;
using namespace std;

int main (int agc, char* argv[])
{
	// Declare the supported options.
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("compression", po::value<int>(), "set compression level")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(agc, argv, desc), vm);
	po::notify(vm);    
//test
    if (0 == vm.size())
	{
		std::cout << desc << std::endl;
		return -1;
	}
	
	if (vm.count("help")) {
		cout << desc << "\n";
		return 1;
	}

	if (vm.count("compression")) {
		cout << "Compression level was set to " 
	 << vm["compression"].as<int>() << ".\n";
	} else {
		cout << "Compression level was not set.\n";
	}
	
    std::cout << "hello world" << std::endl;
    foo();
    return 0;
}
