#include <iostream>
#include "../include/my_operator.h"
#include "../include/my_template.h"
#include "../include/my_thread.h"

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <functional>

namespace po = boost::program_options;
using namespace std;

void testOperator()
{
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1= " << c1 << endl;

	Clock clo(10, 30, 20);
	cout << clo++;
	cout << ++clo;
}

void testTemplate1()
{
	foo<int>();
	foo<double>();

	std::cout << "1 + 1 = " << CMath::add(1, 1) << std::endl;
	std::cout << "1 + 1 = " << CMath::add(1.1, 1.1) << std::endl;
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
}

void testTemplate2()
{
	DynamicArray<int> arr(1);
	arr[0] = 10;
	arr.resize(2);
	arr[1] = 20;
	std::cout << "arr[0] = " << arr[0] << std::endl;
	std::cout << "arr[1] = " << arr[1] << std::endl;
}

void testThread1()
{
	thread t1(ThreadFoo1);
	

	thread t2(ThreadFoo2, 200);
	
	MyFunctor myfunc;
	thread t3(myfunc);

	Worker wk;
	thread t4(std::bind(&Worker::run, &wk, 300));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

int main (int agc, char* argv[])
{	
	// Declare the supported options.
	try
	{
		po::options_description desc("test options");
		desc.add_options()
			("help,h", "produce help message")
			("operator,o", "test operator")
			("template,t", po::value<int>(), "test template, args: 1, 2")
			("thread,p", po::value<int>(), "test thread, args: 1, 2");

		po::variables_map vm;
		po::store(po::parse_command_line(agc, argv, desc), vm);
		po::notify(vm);

		// print help info
		if (0 == vm.size())
		{
			std::cout << desc << std::endl;
			return -1;
		}
		if (vm.count("help"))
		{
			cout << desc << "\n";
			return 1;
		}
		if (vm.count("operator"))
		{
			testOperator();
		}
		if (vm.count("template"))
		{
			switch (vm["template"].as<int>())
			{
			case 1:
			{
				testTemplate1();
				break;
			}
			case 2:
			{
				testTemplate2();
				break;
			}
			default:
				break;
			}
		}
		if (vm.count("thread"))
		{
			switch (vm["thread"].as<int>())
			{
			case 1:
			{
				testThread1();
				break;
			}
			case 2:
			{
				testThread2();
				break;
			}
			default:
				break;
			}
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Invalid command! \n";
	}
	
    return 0;
}
