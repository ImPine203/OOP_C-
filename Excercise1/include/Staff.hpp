#include<iostream>
using namespace std;
#ifndef STAFF_HPP
#define STAFF_HPP
#include"Officer.hpp"

class Staff : public Officer{
    private:
        string job;
    public:
        Staff(string name, short int age, string gender, string address, string job): Officer(name, age, gender, address){
            this -> job =job;
        }
        string getJob() const override{
            return job;
        }
        void getJob(string job){
            this->job = job;
        }
};
#endif
