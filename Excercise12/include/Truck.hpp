#ifndef TRUCK_HPP
#define TRUCK_HPP
#include "Vehicle.hpp"

class Truck: public Vehicle{
    private:
        float payload;
    public:
        Truck(int ID, string manufacturer, int yearOfManufacture, float price, string color, float payload): Vehicle(ID, manufacturer, yearOfManufacture, price, color){
            this-> payload = payload;
        }
        float getPayload(){
            return payload;
        }
        void setPayload(float payload){
            this->payload = payload;
        }
};

#endif