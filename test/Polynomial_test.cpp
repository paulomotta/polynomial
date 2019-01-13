
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

TEST_F(PolynomialFixture, IncreaseOrderToEqual)
{
    int order = 2;
    int size = order + 1;
    vector<double> vec1; 
    for (int i = order; i >= 0; i--) 
        vec1.push_back(i+2); 
    
    Polynomial p1(vec1);
    ASSERT_EQ (order, p1.order);
    
    Polynomial res = p1.increaseOrderTo(2);
    
    ASSERT_EQ (2, res.order);
    ASSERT_EQ (3, res.coeficients.size());
    ASSERT_EQ (4, res.coeficients[0]);
    
}

TEST_F(PolynomialFixture, SubtractPolynomials)
{
    int order = 2;
    int size = order + 1;
    vector<double> vec1; 
    for (int i = order; i >= 0; i--) 
        vec1.push_back(i+2); 
    
    vector<double> vec2; 
    for (int i = order; i >= 0; i--) 
        vec2.push_back(i+4); 
    
    Polynomial p1(vec1);
    Polynomial p2(vec2);
    
    Polynomial res = p1 - p2;
    
    ASSERT_EQ (order, res.order);
    ASSERT_EQ (size, res.coeficients.size());
    
}