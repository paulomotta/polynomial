
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

    void printPolynomial(const Polynomial& poly ){
        for(int i=poly.order; i >=0 ; i--){
            cout << i<< "(" << poly.coeficients[i] << ") ";
        }
        cout << endl;
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
    
    for(int i=res.order; i >=0 ; i--){
        ASSERT_EQ (vec1[i], res.coeficients[i]);
    }
    
}

TEST_F(PolynomialFixture, IncreaseOrderTo3)
{
    int order = 2;
    int size = order + 1;
    vector<double> vec1; 
    for (int i = order; i >= 0; i--) 
        vec1.push_back(i+2); 
    
    Polynomial p1(vec1);
    ASSERT_EQ (order, p1.order);
    
    Polynomial res = p1.increaseOrderTo(3);
    
    ASSERT_EQ (3, res.order);
    ASSERT_EQ (4, res.coeficients.size());
    ASSERT_EQ (0, res.coeficients[res.order]);
    
    for(int i=res.order-1; i >=0 ; i--){
        ASSERT_EQ (vec1[i], res.coeficients[i]);
    }
    
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
    
    for(int i=res.order; i >=0 ; i--){
        double result = res.coeficients[i]; 
        double expected = p1.coeficients[i] - p2.coeficients[i];
        ASSERT_EQ (expected, result);
    }
    
}

TEST_F(PolynomialFixture, SubtractPolynomialsP1GreaterThanP2)
{
    int order = 3;
    int size = order + 1;
    vector<double> vec1; 
    for (int i = order; i >= 0; i--) 
        vec1.push_back(i+2); 
    
    order = 2;
    size = order + 1;
    vector<double> vec2; 
    for (int i = order; i >= 0; i--) 
        vec2.push_back(i+4); 
    
    Polynomial p1(vec1);
    Polynomial p2(vec2);
    
    p1.printPolynomial(p1);
    p2.printPolynomial(p2);
    
    Polynomial res = p1 - p2;
    
    ASSERT_EQ (3, res.order);
    ASSERT_EQ (4, res.coeficients.size());
    
    res.printPolynomial(res);
    
    ASSERT_EQ (2, p1.coeficients[p1.order] - 0);
        
    for(int i=res.order-1; i >=0 ; i--){
        double result = res.coeficients[i]; 
        double expected = p1.coeficients[i] - p2.coeficients[i];
        ASSERT_EQ (expected, result);
    }
    
}

TEST_F(PolynomialFixture, SubtractPolynomialsP2GreaterThanP1)
{
    int order = 3;
    int size = order + 1;
    vector<double> vec1; 
    for (int i = order; i >= 0; i--) 
        vec1.push_back(i+2); 
    
    order = 2;
    size = order + 1;
    vector<double> vec2; 
    for (int i = order; i >= 0; i--) 
        vec2.push_back(i+4); 
    
    Polynomial p1(vec1);
    Polynomial p2(vec2);
    
    p1.printPolynomial(p1);
    p2.printPolynomial(p2);
    
    Polynomial res = p2 - p1;
    
    ASSERT_EQ (3, res.order);
    ASSERT_EQ (4, res.coeficients.size());
    
    res.printPolynomial(res);
    
    ASSERT_EQ (4, p2.coeficients[p2.order] - 0);
        
    for(int i=res.order-1; i >=0 ; i--){
        double result = res.coeficients[i]; 
        double expected = p2.coeficients[i] - p1.coeficients[i];
        ASSERT_EQ (expected, result);
    }
    
}

TEST_F(PolynomialFixture, DividePolynomialsP1P2)
{
    int order = 4;
    int size = order + 1;
    vector<double> vec1; 
    vec1.push_back(-1);
    vec1.push_back(9);
    vec1.push_back(-7);
    vec1.push_back(1);
    vec1.push_back(1);
    
    Polynomial p1(vec1);
    p1.printPolynomial(p1);
    
    order = 2;
    size = order + 1;
    vector<double> vec2; 
    vec2.push_back(-2);
    vec2.push_back(3);
    vec2.push_back(1);
    
    Polynomial p2(vec2);
    p2.printPolynomial(p2);
    
    Polynomial res = p1 / p2;
    
    ASSERT_EQ (2, res.order);
    ASSERT_EQ (3, res.coeficients.size());
    
    res.printPolynomial(res);
    
    ASSERT_EQ (1, res.coeficients[res.order] );
    ASSERT_EQ (-2, res.coeficients[res.order-1] );
    ASSERT_EQ (1, res.coeficients[res.order-2] );
    
}

TEST_F(PolynomialFixture, TrimPolynomial)
{
    int order = 4;
    int size = order + 1;
    vector<double> vec1; 
    vec1.push_back(-1);
    vec1.push_back(9);
    vec1.push_back(-7);
    vec1.push_back(0);
    vec1.push_back(0);
    
    Polynomial p1(vec1);
    p1.printPolynomial(p1);
    
    Polynomial res = p1.trim();
    
    ASSERT_EQ (2, res.order);
    ASSERT_EQ (3, res.coeficients.size());
    
    res.printPolynomial(res);
    
    ASSERT_EQ (-7, res.coeficients[res.order] );
    ASSERT_EQ (9, res.coeficients[res.order-1] );
    ASSERT_EQ (-1, res.coeficients[res.order-2] );
    
}

TEST_F(PolynomialFixture, PolynomialWithOrder)
{   
    Polynomial res(2);
    
    ASSERT_EQ (2, res.order);
    ASSERT_EQ (3, res.coeficients.size());
    
    res.printPolynomial(res);
    
    ASSERT_EQ (0, res.coeficients[res.order] );
    ASSERT_EQ (0, res.coeficients[res.order-1] );
    ASSERT_EQ (0, res.coeficients[res.order-2] );

}

TEST_F(PolynomialFixture, CoeficientsAccess)
{   
    Polynomial res(2);
    res[0] = 1;
    res[1] = 2;
    res[2] = 3;
    
    ASSERT_EQ (2, res.order);
    ASSERT_EQ (3, res.coeficients.size());
    
    res.printPolynomial(res);
    
    ASSERT_EQ (3, res.coeficients[res.order] );
    ASSERT_EQ (2, res.coeficients[res.order-1] );
    ASSERT_EQ (1, res.coeficients[res.order-2] );

}