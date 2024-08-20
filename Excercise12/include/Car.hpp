#ifndef CAR_HPP
#define CAR_HPP
#include "Vehicle.hpp"

class Car: public Vehicle{
    private:
        int numberOfSeat;
        string typeOfEngine;
    public:
        Car(int ID, string manufacturer, int yearOfManufacture, float price, string color, int numberOfSeat, string typeOfEngine): Vehicle(ID, manufacturer, yearOfManufacture, price, color){
            this-> numberOfSeat = numberOfSeat;
            this-> typeOfEngine = typeOfEngine;
        }
        int getNumberOfSeat(){
            return numberOfSeat;
        }
        string getTypeOfEngine(){
            return typeOfEngine;
        }
        void setNumberOfSeat(int numberOfSeat){
            this->numberOfSeat = numberOfSeat;
        }
        void setTypeOfEngine(string typeOfEngine){
            this->typeOfEngine = typeOfEngine;
        }
};

#endif