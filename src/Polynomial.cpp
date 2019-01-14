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

    Polynomial res;
    
    
    double value = this->coeficients[this->order] / other.coeficients[other.order];
    double quocientOrder = this->order - other.order;
    cout <<quocientOrder<< " " << value<< endl; 
    vector<double> quocientValues;
    for (int i=0; i< quocientOrder; i++){
        quocientValues.push_back(0.);
    }
    quocientValues.push_back(value);
    
    vector<double> subtractor;
    for (int i=0; i <= this->order; i++){
        subtractor.push_back(0.);
    }
    
    subtractor[quocientOrder + other.order] = value * other.coeficients[other.order];
    subtractor[quocientOrder + other.order-1] = value * other.coeficients[other.order-1];
    subtractor[quocientOrder + other.order-2] = value * other.coeficients[other.order-2];
    
    Polynomial sub(subtractor);
    printPolynomial(sub);
    
    Polynomial partial1 = *this - sub;
    printPolynomial(partial1);
    
    double value2 = partial1.coeficients[partial1.order-1] / other.coeficients[other.order];
    cout << " partial1.order=" << partial1.order-1<< endl;
    cout << " other.order=" << other.order<< endl;
    double quocientOrder2 = (partial1.order-1) - other.order;
    quocientValues[quocientOrder2]=value2;
    cout <<quocientOrder2<< " " << value2<< endl; 
    vector<double> subtractor2;
    for (int i=0; i <= partial1.order-1; i++){
        subtractor2.push_back(0.);
    }
    
    subtractor2[quocientOrder2 + other.order] = value2 * other.coeficients[other.order];
    subtractor2[quocientOrder2 + other.order-1] = value2 * other.coeficients[other.order-1];
    subtractor2[quocientOrder2 + other.order-2] = value2 * other.coeficients[other.order-2];
    
    cout << "partial1.order=" << partial1.order <<endl;
    printPolynomial(partial1);
    
    Polynomial sub2(subtractor2);
    printPolynomial(sub2);
    
    cout << "sub2.order=" << sub2.order <<endl;
    Polynomial partial2 = partial1 - sub2;
    printPolynomial(partial2);
    cout << "partial2.coeficients[partial2.order-2]=" << partial2.coeficients[partial2.order-2]<< endl;
    cout << "other.coeficients[other.order]=" << other.coeficients[other.order] << endl;
    double value3 = partial2.coeficients[partial2.order-2] / other.coeficients[other.order];
    cout << " partial2.order=" << partial2.order-2<< endl;
    cout << " other.order=" << other.order<< endl;
    double quocientOrder3 = (partial2.order-2) - other.order;
    quocientValues[quocientOrder3]=value3;
    cout <<quocientOrder3<< " " << value3<< endl; 
    vector<double> subtractor3;
    for (int i=0; i <= partial2.order-2; i++){
        subtractor3.push_back(0.);
    }
    
    subtractor3[quocientOrder3 + other.order] = value3 * other.coeficients[other.order];
    subtractor3[quocientOrder3 + other.order-1] = value3 * other.coeficients[other.order-1];
    subtractor3[quocientOrder3 + other.order-2] = value3 * other.coeficients[other.order-2];
    
    cout << "partial2.order=" << partial2.order <<endl;
    printPolynomial(partial2);
    
    Polynomial sub3(subtractor3);
    cout << "sub3.order=" << sub3.order <<endl;
    printPolynomial(sub3);
    
    Polynomial partial3 = partial2 - sub3;
    printPolynomial(partial3);
    
    Polynomial quocient(quocientValues);
    printPolynomial(quocient);
    
    return quocient;
}

void Polynomial::printPolynomial(const Polynomial& poly )const{
        for(int i=poly.order; i >=0 ; i--){
            cout << poly.coeficients[i] << "x^" << i << " + ";
        }
        cout << endl;
    }