#ifndef HOTEL_HPP 
#define HOTEL_HPP

#include<vector>
#include<utility>

#include "Person.hpp"
#include "RoomA.hpp"
#include "RoomB.hpp"
#include "RoomC.hpp"

class Hotel{
    private:
        vector<pair<Person*,Room*>* > hotel;
    public:
        void add(pair<Person*,Room*> *customer){
            this->hotel.push_back(customer);
        }
        void deleteByID(string ID){
            auto it = this->hotel.begin();
            while(it!=this->hotel.end()){
                if((*it)->first->getID()==ID){
                    delete *it;
                    break;
                }
            }
            cout << "This ID not Existed"<< endl;
        }
        float caculateMoney(pair<Person*,Room*> *customer){
            return customer->second->getRentDay()*customer->second->getPrice();
        }
        ~Hotel(){
            auto it = this->hotel.begin();
            while(it!=this->hotel.end()){
                delete *it;
            }            
        }
};

#endif
