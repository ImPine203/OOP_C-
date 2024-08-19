#ifndef PERSON_HPP
#define PERSON_HPP
#include "RoomA.hpp"
#include "RoomB.hpp"
#include "RoomC.hpp"

class Person{
    private:
        string name;
        short int age;
        string ID;
    public:
        Person(string name, short int age, string ID){
            this->name = name;
            this->age = age;
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
        void setName(short int age){
            this->age = age;
        }        
        string getID(){
            return ID;
        }
        void setID(string ID){
            this->ID = ID;
        }
};
#endif