/* 
 * File:   Polynomial.cpp
 * Author: paulo
 * 
 * Created on 11 de Janeiro de 2019, 12:54
 */

#include "Polynomial.h"

Polynomial::Polynomial(const vector<double>& coeficients): order(0){
    this->coeficients = coeficients;
    this->order = this->coeficients.size() - 1;
}

Polynomial::Polynomial(const Polynomial& orig) {
    this->coeficients = orig.coeficients;
    this->order = orig.order;
}

Polynomial::~Polynomial() {
}

Polynomial &Polynomial::increaseOrderTo(int order){
    if (this->order >= order) return *this;
    
    
}
Polynomial &Polynomial::operator- (const Polynomial& other){
    //TODO change to smart_pointer
    Polynomial res;
    
    if (this->order >= other.order){
        int index = this->order;
        
    } else {
        
    }
    
    return res;
}
