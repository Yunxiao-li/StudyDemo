#include "my_template.h"
#include "my_template_ut.h"
#include <iostream>

void read(int *p, int n)
{
	for (int i=0; i<n; ++i)
	{
		std::cin >> p[i];
	}
}

void DynamicArrayTest::SetUpTestCase()
{
	std::cout << "DynamicArrayTest::SetUpTestCase" << std::endl;
}

void DynamicArrayTest::TearDownTestCase()
{
	std::cout << "DynamicArrayTest::TearDownTestCase" << std::endl;
}

void DynamicArrayTest::SetUp()
{
	std::cout << "DynamicArrayTest::SetUp" << std::endl;
    m_pArray = new DynamicArray<int>(10);
}

void DynamicArrayTest::TearDown()
{
	std::cout << "DynamicArrayTest::TearDown" << std::endl;
    if (NULL != m_pArray)
    {
        delete m_pArray;
        m_pArray = NULL;
    }
}

TEST_F(DynamicArrayTest, SetValue)
{
    ASSERT_TRUE(m_pArray);
    m_pArray[0] = 10;
	int* iv = m_pArray[0];
    EXPECT_EQ(10, *iv);
}