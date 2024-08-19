#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Receipt.hpp"
#include<vector>

class Manager{
    private:
        vector<Receipt*> manager;
    public:
        void addInfor(string &owner, int &homeNumber, int &elecMeterNumber, int &oldNumber, int &newNumber){
            cout<<"Enter owner's name: \n";
            getline(cin,owner);
            cout<<"Enter home number: \n";
            cin>>homeNumber;
            cout<<"Enter electronic meter number: \n";
            cin >> elecMeterNumber;
            cin.ignore();
            cout<< "Old number: \n";
            cin >> oldNumber;
            cout << "New number: \n";
            cin >> newNumber;
            cin.ignore();
        }
        void addReceipt(){
            string owner;
            int homeNumber;
            int elecMeterNumber;
            int oldNumber;
            int newNumber;   
            addInfor(owner, homeNumber, elecMeterNumber, oldNumber, newNumber);
            this->manager.push_back(new Receipt(owner, homeNumber, elecMeterNumber, oldNumber, newNumber));         
        }
        void display(){
            int count = 1;
            auto it = this->manager.begin();
            while(it!= this->manager.end()){
                cout <<"Household number "<<count++<<endl;
                cout<<"Owner's name: "<<(*it)->getOwner()<<endl;
                cout<<"Home number: "<<(*it)->getHomeNumber()<<endl;
                cout<<"Electric meter number: "<<(*it)->getElecMeterNumber()<<endl;
                cout<<"Payment: "<<(*it)->getPayment()<<endl;
                it++;
            }
        }
        ~Manager(){
            auto it = this->manager.begin();
            while(it!= this->manager.end()){
                delete (*it);
                it++;
            }            
        }
};

#endif