
#include <iostream>

#include <gtest/gtest.h>

#include "Polynomial.h"

using namespace std;
using namespace testing;

class PolynomialFixture : public Test {
protected:

    static void SetUpTestCase() {

    }

    static void TearDownTestCase() {

    }

    void SetUp() {
    }

    void TearDown() {
    }


};

TEST_F(PolynomialFixture, ConstructPolynomialWithoutParams)
{
    Polynomial p;
    ASSERT_EQ (0, p.order);
    ASSERT_EQ (0, p.coeficients.size());
    
}

TEST_F(PolynomialFixture, ConstructPolynomialWithVectorParam)
{
    vector<double> vec; 
    for (int i = 4; i >= 0; i--) 
        vec.push_back(i); 
    
    Polynomial p(vec);
    ASSERT_EQ (4, p.order);
    ASSERT_EQ (5, p.coeficients.size());
    
}