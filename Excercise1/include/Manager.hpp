#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "Engineer.hpp"
#include "Staff.hpp"
#include "Worker.hpp"
#include <vector>
class Manager{
    private:
        vector<Officer*> officer;
    public:
        void addOfficer(Officer *Officer){
            this->officer.push_back(Officer);
        }
        void findByName(string name){
            int count = 0;
            for (auto i : this->officer){
                if(i->getName()== name){
                    ++count;
                    cout << "Name: "<<i->getName()<<endl;
                    cout << "Age: "<<i->getAge()<<endl;
                    cout << "Gender: "<<i->getGender()<<endl;
                    cout << "Address: "<<i->getAddress()<<endl;
                    if(i->getLevel()!=-1){
                        cout << "Level: "<<i->getLevel()<<endl;
                    }
                    if(i->getJob()!="\0"){
                        cout << "Job: "<<i->getJob()<<endl;
                    }
                    if(i->getMajor()!="\0"){
                        cout << "Major: "<<i->getMajor()<<endl;
                    }
                }
            }
            if(count == 0) cout<<"Can't search person name "<<name<<endl;
            cout << endl;
        }
        void showInfor(){
            int number=1;
            for (auto i:this->officer){
                cout<<"Person number "<<number<<":"<<endl;
                cout << "Name: "<<i->getName()<<endl;
                cout << "Age: "<<i->getAge()<<endl;
                cout << "Gender: "<<i->getGender()<<endl;
                cout << "Address: "<<i->getAddress()<<endl;
                if(i->getLevel()!=-1){
                    cout << "Level: "<<i->getLevel()<<endl;
                }
                if(i->getJob()!="\0"){
                    cout << "Job: "<<i->getJob()<<endl;
                }
                if(i->getMajor()!="\0"){
                    cout << "Major: "<<i->getMajor()<<endl;
                }
                number++;
                cout << endl;
            }
        }
        ~Manager(){
            for (auto i : this->officer){
                delete(i);
            }
        }
 
};
#endif
