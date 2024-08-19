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
        // getter and setter for name
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        // getter and setter for age
        short int getAge(){
            return age;
        }
        void setAge(short int age){
            this->age = age;
        }
        // getter and setter for Job
        string getJob(){
            return job;
        }
        void setJob(string job){
            this->job = job;
        }
        // getter and setter for ID
        string getID(){
            return ID;
        }
        void setID(string ID){
            this->ID = ID;
        }

};

#endif