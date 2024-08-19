#ifndef ROOMB_HPP
#define ROOMB_HPP

#include "Room.hpp"
class RoomB: public Room{
    private:
        float price;
    public:
        RoomB(short int rentDay, float price = 300):Room(rentDay){
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