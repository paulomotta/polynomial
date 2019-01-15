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

Polynomial::Polynomial(const int order){
    for (int i=0; i <= order; i++){
        this->coeficients.push_back(0.);
    }
    this->order = order; 
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
    //cout<<"inside increaseOrderTo" << endl;
    //printPolynomial(p);
    //cout << "=====================" << endl;
    return p;
}

Polynomial Polynomial::trim() const{
    vector<double> trimmed;
    bool found = false;
    for (int i=this->order; i>=0; i--){
        if (this->coeficients[i] == 0 && !found) {
            continue;
        } else {
            trimmed.insert(trimmed.begin(),this->coeficients[i]);
            found =  true;
        }
    }
    Polynomial res(trimmed);
    return res;
}

Polynomial Polynomial::operator- (const Polynomial& other){
    //TODO change to smart_pointer
    Polynomial res;
    
    if (this->order > other.order){
        res = other.increaseOrderTo(this->order);
        //cout<<"called increase on other" << endl;
        //printPolynomial(res);
        for (int i=0; i <= res.order; i++){
            //cout << this->coeficients[i] << " " << other.coeficients[i] <<" " << this->coeficients[i] - other.coeficients[i] << endl;
            res.coeficients[i] = this->coeficients[i] - res.coeficients[i]; 
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

    double quocientCoeficient = this->coeficients[this->order] / other.coeficients[other.order];
    double quocientOrder = this->order - other.order;
    
    Polynomial quocient(quocientOrder);
    quocient[quocientOrder] = quocientCoeficient;
    
    Polynomial subtractor(this->order);
    
    for (int i=other.order; i >= 0; i--) {
        subtractor[quocientOrder + (other.order - i)] = quocientCoeficient * other.coeficients[(other.order - i)];
    }
    
    Polynomial rest = *this - subtractor;
    rest = rest.trim();
    
    if (rest.order >= other.order) {
        Polynomial p = rest / other;
        p = p.increaseOrderTo(quocientOrder);
        for (int i=0; i < quocientOrder; i++) {
            quocient[i] = quocient[i] + p[i]; 
        }
    }
    
    return quocient;
    
}

Polynomial Polynomial::operator+ (const Polynomial& other){

    Polynomial res;
    if (this->order > other.order){
        res = other.increaseOrderTo(this->order);
        for (int i=0; i <= res.order; i++){
            res.coeficients[i] = this->coeficients[i] + res.coeficients[i]; 
        }
    } else if (this->order < other.order) {
        res = this->increaseOrderTo(other.order);
        Polynomial r(*this);
        for (int i=0; i <= res.order; i++){
            res.coeficients[i] = this->coeficients[i] + other.coeficients[i];
        }
    } else {
        Polynomial r(*this);
        for (int i=0; i <= this->order; i++){
            r.coeficients[i] += other.coeficients[i]; 
        }
        res = r;
    }
    
    return res;
    
}

void Polynomial::printPolynomial(const Polynomial& poly )const{
        for(int i=poly.order; i >=0 ; i--){
            cout << poly.coeficients[i] << "x^" << i << " + ";
        }
        cout << endl;
    }