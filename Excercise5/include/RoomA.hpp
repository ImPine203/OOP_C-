#ifndef ROOMA_HPP
#define ROOMA_HPP

#include "Room.hpp"
class RoomA: public Room{
    private:
        float price;
    public:
        RoomA(short int rentDay, float price = 500):Room(rentDay){
            this->price = price;
        }
        float getPrice(){
            return price;
        }
        void setPrice(float price){
            this->price=price;
        }
};

#endif