/* 
 * File:   Polynomial.cpp
 * Author: paulo
 * 
 * Created on 11 de Janeiro de 2019, 12:54
 */

#include "Polynomial.h"
#include <iostream>
using namespace std;

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

Polynomial Polynomial::increaseOrderTo(int order){
    if (this->order >= order) return *this;
    
    vector<double> increased;
    
    int diff = order - this->order;

    for (int i=0; i < diff; i++){
        increased.push_back(0.);
    }
    
    for (int i=0; i < this->coeficients.size(); i++){
        increased.push_back(this->coeficients[i]);
    }
    
    Polynomial p(increased);
    return p;
}
Polynomial Polynomial::operator- (const Polynomial& other){
    //TODO change to smart_pointer
    Polynomial res;
    
    if (this->order >= other.order){
        int index = this->order;
        
    } else {
        
    }
    
    return res;
}
