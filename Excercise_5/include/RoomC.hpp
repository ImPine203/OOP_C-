#ifndef ROOMC_HPP
#define ROOMC_HPP

#include "Room.hpp"
class RoomC: public Room{
    private:
        float price;
    public:
        RoomC(short int rentDay, float price = 100):Room(rentDay){
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