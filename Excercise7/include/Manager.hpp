#ifndef MANAGER_HPP
#define MANAGER_HPP
#include<vector>
#include "Officer.hpp"
class Manager{
    private:
        vector<Officer*> manager;
    public:
        void addInfor(string &name, int &age, string &homwTown, string &ID, float &baseSalary, float &bonus, float &fines){
            cout<<"Enter name: \n";
            getline(cin,name);
            cout<<"Enter age: \n";
            cin>>age;
            cin.ignore();
            cout << "Enter home town: \n";
            getline(cin, homwTown);
            cout<<"Enter ID: \n";
            getline(cin, ID);
            cout<<"Enter base salary: \n";
            cin>>baseSalary;
            cout<<"Enter bonus: \n";
            cin>>bonus;
            cout<<"Enter fines: \n";
            cin >> fines;
        }
        void addOfficer(){
            string name;
            int age;
            string homeTown;
            string ID;   
            float baseSalary;
            float bonus;
            float fines;
            addInfor(name, age, homeTown,ID, baseSalary, bonus, fines);
            this->manager.push_back(new Officer(name,age,homeTown,ID,baseSalary,bonus,fines));         
        }
        void deleteByID(string ID){
            auto it = this->manager.begin();
            while(it!= this->manager.end()){
                if((*it)->getID()==ID){
                    delete *it;
                    it = this->manager.erase(it);
                    break;
                }
            }
        }
        void display(){
            auto it= this->manager.begin();
            int count = 1;
            while(it != this->manager.end()){
                cout << "Teacher number "<<count++<<endl;
                cout<<"Name: "<<(*it)->getName()<<endl;
                cout<<"Age: "<<(*it)->getAge()<<endl;
                cout<<"Home town: "<<(*it)->getHomeTown()<<endl;
                cout<<"ID: "<<(*it)->getID()<<endl;
                cout<<"Net salary: "<<(*it)->getNetSalary()<<endl;
                it++;
                cout << endl;
            }
        }
        ~Manager(){
            auto it = this->manager.begin();
            while(it != this->manager.end()){               
                delete (*it);
                it = this->manager.erase(it);
                break;
                it++;
            }            
        }
};

#endif