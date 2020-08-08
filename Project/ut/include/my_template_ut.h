#pragma once

#include "gtest/gtest.h"
#include "my_template.h"

class DynamicArrayTest : public testing::Test
{
protected:
    static void SetUpTestCase();
	static void TearDownTestCase();
    virtual void SetUp();
    virtual void TearDown();

//private:
    DynamicArray<int>* m_pArray;
};


