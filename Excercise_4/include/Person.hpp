#ifndef PERSON_HPP
#define PERSON_HPP
#include<iostream>
using namespace std;
class Person{
    private:
        string name;
        short int age;
        string job;
        string ID;
    public:
        Person(string name, short int age, string job, string ID){
            this ->name = name;
            this ->age = age;
            this->job = job;
            this->ID = ID;
        }
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        short int getAge(){
            return age;
        }
        void setAge(short int age){
            this->age = age;
        }
        string getJob(){
            return job;
        }
        void setName(string job){
            this->job = job;
        }
        string getID(){
            return ID;
        }
        void setName(string ID){
            this->ID = ID;
        }

};

#endif