#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "Motorbike.hpp"
#include "Car.hpp"
#include "Truck.hpp"
#include<vector>
class Manager{
    private:
        vector<Vehicle*> manager;
    public:
        void addGeneralInfor(int &ID, string &manufacturer, int &yearOfManufacture, float &price, string &color){
            cout << "Enter ID: \n";
            cin >>ID;
            cin.ignore();
            cout << "Enter manufacturer: \n";
            getline(cin, manufacturer);
            cout << "Enter manufacture year: \n";
            cin >> yearOfManufacture;
            cout << "Enter price: \n";
            cin >> price;
            cin.ignore();
            cout << "Enter color: \n";
            getline(cin, color);
        }    
        void addVehicle(Vehicle *vehicle){
            this->manager.push_back(vehicle);
        }
        void deleteByID(int ID){
            auto it = this->manager.begin();
            // bool dele = false;
            while(it!= this->manager.end()){
                if((*it)->getID()==ID){
                    delete (*it);
                    it = this->manager.erase(it);
                    cout << "Deleted\n";
                    return;
                }
                it++;
            }
            if(it == this->manager.end()) cout << "Invalid ID\n\n";
        }
        void displayGeneralInfor(Vehicle *vehicle){
            cout <<"ID: "<< vehicle->getID()<<endl;
            cout<<"Manufacture: "<<vehicle->getManufactuer()<<endl;
            cout<<"Manufacture year: "<<vehicle->getYearOfManufacture()<<endl;
            cout<<"Price: "<<vehicle->getPrice()<<endl;
            cout<<"Color: "<<vehicle->getColor()<<endl;
            if(vehicle->getNumberOfSeat()!= -1){
                cout << "Number of seat: "<<vehicle->getNumberOfSeat()<<endl;
                cout << "Type of engine: "<<vehicle->getTypeOfEngine()<<endl;
            }
            else if (vehicle->getPower()!= -1){
                cout<< "Power: "<<vehicle->getPower()<<endl;
            }
            else{
                cout<<"Payload: "<<vehicle->getPayLoad()<<endl;
            }
        }
        void searchByManuColor(string manufacturer, string color){
            auto it = this->manager.begin();
            while(it!= this->manager.end()){
                if((*it)->getManufactuer()==manufacturer&& (*it)->getColor() == color){
                    displayGeneralInfor(*it);
                    cout << endl;
                    break;
                }
                it++;
            }
            if(it == this->manager.end()) cout << "Not exist\n\n";            
        }
        void display(){
            int count =1;
            auto it = this->manager.begin();
            while(it!= this->manager.end()){
                cout << "Vehicle number "<<count++<<endl;
                displayGeneralInfor(*it);
                cout << endl;
                it++;
            }            
        }
};

#endif