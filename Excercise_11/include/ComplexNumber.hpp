#ifndef COMPLEXNUMBER_HPP
#define COMPLEXNUMBER_HPP
#include<iostream>
using namespace std;
class ComplexNumber{
    private:
        int real;
        int imag;
    public:
    ComplexNumber(int real, int imag){
        this->real = real;
        this->imag = imag;
    }
    int getReal(){
        return real;
    }
    int getImag(){
        return imag;
    }
    void setReal(int real){
        this->real = real;
    }
    void setImag(int imag){
        this->imag = imag;
    }
    void display(){
        cout << "This complex number is: "<<this->real<<" + i*"<<this->imag<<endl;
    }
    void addTwoComplexNumber(ComplexNumber a, ComplexNumber b){
        cout << "Sum is: "<<a.real+b.real<<" + i*"<<a.imag+b.imag<<endl;
    }
    void mutiple(ComplexNumber a, ComplexNumber b){
        cout << "Mutiple is: "<<a.real*b.real-a.imag*b.imag<<" + i*"<<a.real*b.imag+b.real*a.imag<<endl;    
    }
};
#endif