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

Polynomial Polynomial::increaseOrderTo(int order) const{
    if (this->order >= order){
        Polynomial p(this->coeficients);
        return p;
    }
    
    vector<double> increased;
    
    int diff = order - this->order;

    for (int i=0; i < this->coeficients.size(); i++){
        increased.push_back(this->coeficients[i]);
    }
    
    for (int i=0; i < diff; i++){
        increased.push_back(0.);
    }
    
    Polynomial p(increased);
    return p;
}

Polynomial Polynomial::operator- (const Polynomial& other){
    //TODO change to smart_pointer
    Polynomial res;
    
    if (this->order > other.order){
        res = other.increaseOrderTo(this->order);
        printPolynomial(res);
        for (int i=0; i <= res.order; i++){
            res.coeficients[i] = this->coeficients[i] - other.coeficients[i]; 
        }
    } else if (this->order < other.order) {
        res = this->increaseOrderTo(other.order);
        Polynomial r(*this);
        for (int i=0; i <= res.order; i++){
            res.coeficients[i] = this->coeficients[i] - other.coeficients[i];
        }
    } else {
        Polynomial r(*this);
        for (int i=0; i <= this->order; i++){
            r.coeficients[i] -= other.coeficients[i]; 
        }
        res = r;
    }
    
    return res;
}

Polynomial Polynomial::operator/ (const Polynomial& other){

    Polynomial res;
        
    return res;
}

void Polynomial::printPolynomial(const Polynomial& poly )const{
        for(int i=poly.order; i >=0 ; i--){
            cout << poly.coeficients[i] << "x^" << i << " + ";
        }
        cout << endl;
    }