#include <iostream>
#include "gtest/gtest.h"
#include "my_template_ut.h"

using namespace std;

int main (int argc, char* argv[])
{
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
