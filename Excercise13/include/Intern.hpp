#ifndef INTERN_HPP
#define INTERN_HPP
#include "Employee.hpp"
class Intern: public Employee{
    private:
        string major;
        int semeter;
        string universityName;
    public:
        Intern(int ID, string fullName, string birthDay, string phone, string email, int employeeType, string major, int semeter, string universityName): Employee(ID, fullName, birthDay, phone, email, employeeType){
            this->major = major;
            this->semeter = semeter;
            this->universityName = universityName;
        }
        string getMajor(){
            return major;
        }
        int getSemester(){
            return semeter;
        }
        string getUniversityName(){
            return universityName;
        }
        void setMajor(string major){
            this->major = major;
        }
        void setSemeter(int semeter){
            this->semeter = semeter;
        }
        void setUniversityName(string universityName){
            this->universityName = universityName;
        }
        void showInfor(){
            Employee:: showInfor();
            cout<<"Major: "<<this->getMajor()<<endl;
            cout<<"Semeter: "<<this->getSemester()<<endl;
            cout<<"University name: "<<this->getUniversityName()<<endl;
            if(!this->getCertificate().empty()){
                cout << "--------CERTIFICATE--------- \n";
                this->showCertificate();
            }
        }        
};
#endif