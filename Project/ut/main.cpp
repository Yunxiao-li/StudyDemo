#include <iostream>
#include "gtest/gtest.h"
#include "my_template_ut.h"
#include "my_operator.h"

using namespace std;

TEST(Temp, data)
{
	Clock c(10, 20, 30);
	cout << ++c;
}

class CEnv : public testing::Environment
{
public:
	virtual void SetUp()
	{
		std::cout << "CEnv::SetUp" << std::endl;
	}
	
	virtual void TearDown()
	{
		std::cout << "CEnv::TearDown" << std::endl;
	}
};

int main (int argc, char* argv[])
{
	testing::AddGlobalTestEnvironment(new CEnv);
    if (0)
    {
        argc=2;
        char* argvDummy[]={"","--gtest_filter=*.*"}; 
        testing::InitGoogleTest( &argc, argvDummy );
    }
    else
    {
        testing::InitGoogleTest( &argc, argv );
    }

    RUN_ALL_TESTS();
    return 0;
}
