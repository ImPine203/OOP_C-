#pragma once 
#include <iostream>
using namespace std;

class Student{
    private:
        string name;
        int age;
        string clas;
    public:
        Student(string name, int age, string clas){
            this->name = name;
            this->age=age;
            this->clas=clas;
        }
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        int getAge(){
            return age;
        }
        void setAge(int age){
            this->age = age;
        }
        string getClas(){
            return clas;
        }
        void setClas(string clas){
            this->clas = clas;
        }                
};