#ifndef HOTEL_HPP 
#define HOTEL_HPP

#include<vector>
#include<utility>

#include "Person.hpp"
#include "RoomA.hpp"
#include "RoomB.hpp"
#include "RoomC.hpp"

// class Hotel{
//     private:
//         vector<pair<Person*,Room*>* > hotel;
//     public:
//         void add(pair<Person*,Room*> *customer){
//             this->hotel.push_back(customer);
//         }
//         void deleteByID(string ID){
//             auto it = this->hotel.begin();
//             while(it!=this->hotel.end()){
//                 if((*it)->first->getID()==ID){
//                     delete *it;
//                     break;
//                 }
//             }
//             cout << "This ID not Existed"<< endl;
//         }
//         float caculateMoney(string ID){
//             auto it = this->hotel.begin();
//             while(it!=this->hotel.end()){
//                 if((*it)->first->getID() == ID){
//                     return (*it)->second->getPrice()*(*it)->second->getRentDay();
//                 }
//                 it++;
//             }
//             return -1;
//         }
//         void display(){
//             auto it = this->hotel.begin();
//             while(it!= this->hotel.end()){
//                 cout << (*it)->first<<endl;
//                 it++;
//             }
//         }
//         ~Hotel(){
//             auto it = this->hotel.begin();
//             while(it!=this->hotel.end()){
//                 delete *it;
//             }            
//         }
// };

class Hotel{
    private:
        vector<Person*> managePerson;
        vector<Room*> manageRoom;
    public:
        void addCustomer(Person* customer, Room* rentRoom){
            this->managePerson.push_back(customer);
            this->manageRoom.push_back(rentRoom);
        }
        void deleteByID(string ID){
            int count = 0;
            auto it = this->managePerson.begin();
            auto it1 = this->manageRoom.begin();
            while(it!=this->managePerson.end()&&it1!=this->manageRoom.end()){
                ++count;
                if((*it)->getID()==ID){
                    delete (*it);
                    delete (*it1);
                    it = this->managePerson.erase(it);
                    it1= this->manageRoom.erase(it1);
                    break;
                }
                it1++; it++;
            }
            // cout<<"This ID is not existed\n";
        }
        int caculateRental(string ID){
            for (int i = 0; i< this->managePerson.size(); i++){
                if (this->managePerson[i]->getID()==ID){
                    return this->manageRoom[i]->getPrice()*this->manageRoom[i]->getRentDay();
                }
            }
            cout<<"This ID is not existed\n";  
            return 0;          
        }
        void display(){
            for (int i =0; i<this->managePerson.size(); i++){
                cout << this->managePerson[i]->getID()<<endl;
            }            
        }

};

#endif
