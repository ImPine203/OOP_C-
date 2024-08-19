//#ifndef OFFFICER_HPP
//#define OFFICER_HPP
#pragma once
#include<iostream>
using namespace std;

class Officer{
    protected:
        string name;
        short int age;
        string gender;
        string address;
    public:
        Officer(string name, short int age, string gender, string address){
            this -> name = name;
            this -> age = age;
            this -> gender = gender;
            this -> address = address;
        }
        string getName(){
            return name;
        }
        void setName(string name){
            this -> name = name;
        }
        short int getAge(){
            return age;
        }
        void setAge(int age){
            this->age = age;
        }
        string getGender(){
            return gender;
        }
        void setGender(string gender){
            this -> gender = gender;
        }
        string getAddress(){
            return address;
        }
        void setAddress(string address){
            this -> address = address;
        }
        virtual short int getLevel() const{
            return -1;
        }
        virtual string getJob() const{
            return "\0";
        }
        virtual string getMajor() const{
            return "\0";
        }
 
};
//#endif

