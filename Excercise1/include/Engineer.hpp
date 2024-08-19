#include<iostream>
using namespace std;
#ifndef ENGINEER_HPP
#define ENGINEER_HPP
#include"Officer.hpp"

class Engineer : public Officer{
    private:
        string major;
    public:
        Engineer(string name, short int age, string gender, string address, string major): Officer(name, age, gender, address){
            this -> major =major;
        }
        string getMajor() const override{
            return major;
        }
        void setMajor(string major){
            this->major = major;
        }
};
#endif

