#ifndef EXPERIENCE_HPP
#define EXPERIENCE_HPP
#include "Employee.hpp"
class Experience: public Employee{
    private:
        int expInYear;
        string proSkill;
    public:
        Experience(int ID, string fullName, string birthDay, string phone, string email, int employeeType, int employeeCount, int expInYear, string proSkill): Employee(ID, fullName, birthDay, phone, email, employeeType, employeeCount){
            this->expInYear = expInYear;
            this->proSkill = proSkill;
        }
        int getExpInYear(){
            return expInYear;
        }
        string getProSkill(){
            return proSkill;
        }
        void setExpInYear(int expInYear){
            this->expInYear = expInYear;
        }
        void setProSkill(string proSkill){
            this->proSkill = proSkill;
        }
        void showInforEx(){
            this->showGeneralInfor();
            cout<<"Experience in year: "<<this->getExpInYear()<<endl;
            cout<<"Proskill: "<<this->getProSkill()<<endl;
            if(!this->getCertificate().empty()){
                cout << "--------CERTIFICATE--------- \n";
                this->showCertificate();
            }
        }
};
#endif