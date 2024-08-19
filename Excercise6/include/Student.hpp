#pragma once 
#include <iostream>
using namespace std;
class Student{
    private:
        string name;
        int age;
        string homeTown;
    public:
        Student(string name, int age, string homeTown){
            this->name = name;
            this->age = age;
            this-> homeTown = homeTown;
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
        string getHomeTown(){
            return homeTown;
        }
        void setHomeTown(string homeTown){
            this->homeTown = homeTown;
        }        
};