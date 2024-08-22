#ifndef FRESHER_HPP
#define FRESHER_HPP
#include "Employee.hpp"
class Fresher: public Employee{
    private:
        string graduationDate;
        string graduationRank;
        string education;
    public:
        Fresher(int ID, string fullName, string birthDay, string phone, string email, int employeeType, string graduationDate, string graduationRank, string education): Employee(ID, fullName, birthDay, phone, email, employeeType){
            this->graduationDate = graduationDate;
            this->graduationRank = graduationRank;
            this->education = education;
        }
        string getGraduationDate(){
            return graduationDate;
        }
        string getGraduationRank(){
            return graduationRank;
        }
        string getEducation(){
            return education;
        }
        void setGraduationDate(string graduationDate){
            this->graduationDate = graduationDate;
        }
        void setGraduationRank(string graduationRank){
            this->graduationRank = graduationRank;
        }
        void setEducation( string education){
            this->education = education;
        }
        void showInfor(){
            Employee:: showInfor();
            cout<<"Graduation date: "<<this->getGraduationDate()<<endl;
            cout<<"Graduation rank: "<<this->getGraduationRank()<<endl;
            cout<<"Education: "<<this->getEducation()<<endl;
            if(!this->getCertificate().empty()){
                cout << "--------CERTIFICATE--------- \n";
                this->showCertificate();
            }
        }
};
#endif