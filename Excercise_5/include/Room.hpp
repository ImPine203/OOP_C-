#pragma once 
#include <iostream>
using namespace std;
class Room{
    private:
        short int rentDay;
    public:
        Room(short int rentDay){
            this->rentDay = rentDay;
        }
        virtual float getPrice(){
            return -1;
        }
        short int getRentDay(){
            return rentDay;
        }
        void setRentDay(short int rentDay){
            this->rentDay = rentDay;
        }
};