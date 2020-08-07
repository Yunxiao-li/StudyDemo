#include <iostream>
#include "my_template.h"
#include "my_operator.h"

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
        ("test,t", "test function")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(agc, argv, desc), vm);
	po::notify(vm);    

	// print help info
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
	}
	
    foo<int>();
    foo<double>();

    std::cout << "1 + 1 = " << CMath::add(1,1) << std::endl;
    try
    {
        std::cout << "5.0 / 2 = " << CMath::div(5.0, 2.0) << std::endl;
        std::cout << "5.0 / 0 = " << CMath::div(5.0, 0.0) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }

    CDigit<int> d1(1);
    CDigit<int> d2(10);
    CDigit<int> d3;
    d3 = d2 + d1;
    std::cout << "d2 + d1 = " << d3.value() << std::endl;
    d3 = 20;
    d3 += 10;
    std::cout << "d3 = " << d3.value() << std::endl;

    Complex c1(5, 4), c2(2, 10), c3;
    cout << "c1= " << c1 << endl;

    Clock clo(10,30,20);
    cout << clo++;
    cout << ++clo;

    return 0;
}
