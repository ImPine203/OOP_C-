#ifndef HOUSEHOLD_HPP
#define HOUSEHOULD_HPP
#include "Person.hpp"
#include<vector>
class Household{
    private:
        int houseNumber;
        short int numberOfMember;
        vector<Person*> member;
    public:
        Household(int houseNumber = 0, short int numberOfMember = 0, vector<Person*> member ={}){
            this-> numberOfMember = numberOfMember;
            this->member = member;
            this->houseNumber = houseNumber;
        }
        int getHouseNumber(){
            return houseNumber;
        }
        void setHouseNumber(int houseNumber){
            this->houseNumber = houseNumber;
        }
        short int getNumberOfMember(){
            return numberOfMember;
        }
        void setNumberOfMember(short int numberOfPerson){
            this->numberOfMember = numberOfPerson;
        }
        vector<Person*> getMember(){
            return member;
        }
        void setMember(vector<Person*> member){
            this->member = member;
        }
        // void add(Person* member){
        //     this->member.push_back(member);
        // }
        void addInforMember(string &name, short int &age, string &job, string &ID){
                cout<<"Enter name of member: "<<endl;
                getline(cin,name);
                cout<<"Enter age of member: "<<endl;
                cin>>age;
                cin.ignore();
                cout<<"Enter job of member: "<<endl;
                getline(cin,job);
                cout<<"Enter ID of member: "<<endl;
                getline(cin,ID);
        }
        vector<Person*> addPerson(short int numberOfMember){
            int count = 1;
            while(count <= numberOfMember){
                cout << "Enter information of member number "<<count++<<endl;
                string name;
                short int age;
                string job;
                string ID;
                addInforMember(name,age, job, ID);
                this->member.push_back(new Person(name, age, job, ID));
            }
            return this->member;
        }
        void displayHousehold(){
            int count = 1;
            cout <<"----------------------\n";
            cout << "Household's Number: "<<this->getHouseNumber()<<endl;
            auto it = this->member.begin();
            while(it!=this->member.end()){
                cout<<"Member number "<<count++<<endl;
                cout << "Name: "<< (*it)->getName()<<endl;
                cout << "Age: "<< (*it)->getAge()<<endl;
                cout << "Job: "<< (*it)->getJob()<<endl;
                cout << "ID: "<< (*it)->getID()<<endl;
                cout << endl;
                it++;
            }
        }
};

#endif