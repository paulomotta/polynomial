/* 
 * File:   Polynomial.h
 * Author: paulo
 *
 * Created on 11 de Janeiro de 2019, 12:54
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector> 

using namespace std;

class Polynomial {
public:
    Polynomial():order(0){};
    Polynomial(const int order);
    Polynomial(const Polynomial& orig);
    Polynomial(const vector<double>& coeficients);
    virtual ~Polynomial();
    
    Polynomial operator- (const Polynomial&);
    
    Polynomial operator/ (const Polynomial&);
    
    Polynomial increaseOrderTo(int order) const;
    
    Polynomial trim() const;
    
    void printPolynomial(const Polynomial& poly )const;
    
    vector<double> coeficients;
    int order;
private:

};

#endif /* POLYNOMIAL_H */

