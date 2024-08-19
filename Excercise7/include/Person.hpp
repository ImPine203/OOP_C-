#pragma once 
#include <iostream>
using namespace std;
class Person{
    private:
        string name;
        int age;
        string homeTown;
        string ID;
    public:
        Person(string name, int age, string homeTown, string ID){
            this->name = name;
            this->age = age;
            this->homeTown = homeTown;
            this->ID = ID;
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
        string getID(){
            return ID;
        }
        void setID(string ID){
            this->ID = ID;
        }
};