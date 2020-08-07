#include "my_template.h"
#include "my_template_ut.h"
#include <iostream>

void DynamicArrayTest::SetUp()
{
    m_pArray = new DynamicArray<int>(10);
}

void DynamicArrayTest::TearDown()
{
    if (NULL != m_pArray)
    {
        delete m_pArray;
        m_pArray = NULL;
    }
}

TEST_F(DynamicArrayTest, SetValue)
{
    ASSERT_TRUE(m_pArray);
    //m_pArray[0] = 10;
    //EXPECT_EQ(10, m_pArray[0]);
}