#pragma once 
#include <iostream>
using namespace std;
class Vehicle{
    private:
        int ID;
        string manufacturer;
        int yearOfManufacture;
        float price;
        string color;
    public:
        Vehicle(int ID, string manufacturer, int yearOfManufacture, float price, string color){
            this->ID = ID;
            this->manufacturer = manufacturer;
            this->yearOfManufacture = yearOfManufacture;
            this->price = price;
            this->color = color;
        }
        int getID(){
            return ID;
        }
        string getManufactuer(){
            return manufacturer;
        }
        int getYearOfManufacture(){
            return yearOfManufacture;
        }
        float getPrice(){
            return price;
        }
        string getColor(){
            return color;
        }
        void setID(int ID){
            this->ID = ID;
        }
        void setManufactuer(string manufactuer){
            this->manufacturer=manufactuer;
        }
        void setYearOfManufacture(int yearOfmanufactuer){
            this->yearOfManufacture = yearOfmanufactuer;
        }
        void setPrice(float price){
            this->price = price;
        }
        void getColor(string color){
            this->color = color;
        }
        virtual int getNumberOfSeat(){
            return -1;
        }
        virtual string getTypeOfEngine(){
            return "\0";
        }
        virtual float getPower(){
            return -1;
        }
        virtual float getPayLoad(){
            return -1;
        }
};