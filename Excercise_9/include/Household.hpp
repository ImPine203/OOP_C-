#pragma once 
#include<iostream>
using namespace std;

class Household{
    private:
        string owner;
        int homeNumber;
        int elecMeterNumber;
    public:
        Household(string owner, int homeNumber, int elecMeterNumber){
            this->owner = owner;
            this->homeNumber = homeNumber;
            this->elecMeterNumber = elecMeterNumber;
        }
        string getOwner(){
            return owner;
        }
        void setOwner(string owner){
            this->owner = owner;
        }
        int getHomeNumber(){
            return homeNumber;
        }
        void setHomeNumber(int homeNumber){
            this->homeNumber = homeNumber;
        }
        int getElecMeterNumber(){
            return elecMeterNumber;
        }
        void setElecMeterNumber(int elecMeterNumber){
            this->elecMeterNumber = elecMeterNumber;
        }        

};