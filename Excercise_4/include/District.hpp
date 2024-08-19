#ifndef DISTRICT_HPP
#define DISTRICT_HPP
#include"Household.hpp"
#include<vector>
class District{
    private:
        vector<Household*> district;
        int numberOfHousehold;
    public:
        District(int numberOfHousehold){
            this->numberOfHousehold = numberOfHousehold;
        }
        vector<Household*> getDistrict(){
            return district;
        }
        void setDistrict(vector<Household*> district){
            this->district = district;
        }
        int getNumberOfHousehold(){
            return numberOfHousehold;
        }
        void setNumberOfHousehold(int numberOfHousehold){
            this->numberOfHousehold = numberOfHousehold;
        }
        void addInforOfHousehold(int &houseNumber, short int &numberOfMember, Household &household){
            cout << "Enter house's number: \n";
            cin>>houseNumber;
            cout<<"Enter number of member: \n";
            cin>>numberOfMember;
            cin.ignore();
            // household.addPerson(numberOfMember);
        }
        void addHousehould(int numberOfHousehold){
            int count = 1;
            while (count <= numberOfHousehold)
            {
                int houseNumber = 0;
                short int numberOfMember = 0;
                Household household(houseNumber, numberOfMember);
                cout <<"Enter information of household number "<<count++<<endl;
                addInforOfHousehold(houseNumber, numberOfMember, household);
                this->district.push_back(new Household(houseNumber, numberOfMember,household.addPerson(numberOfMember)));
            }
            
        }
        void display(){
            auto i = this->district.begin();
            int count = 1;
            while(i!=this->district.end()){
                cout << "Household number "<<count++<<endl;
                (*i)->displayHousehold();
                i++;
            }
        }


};
#endif