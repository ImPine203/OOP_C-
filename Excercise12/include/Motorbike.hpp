#ifndef MOTORBIKE_HPP
#define MOTORBIKE_HPP
#include "Vehicle.hpp"

class Motorbike: public Vehicle{
    private:
        float Power;
    public:
        Motorbike(int ID, string manufacturer, int yearOfManufacture, float price, string color, float Power): Vehicle(ID, manufacturer, yearOfManufacture, price, color){
            this-> Power = Power;
        }
        float getPower(){
            return Power;
        }
        void setPower(float power){
            this->Power = power;
        }
};

#endif