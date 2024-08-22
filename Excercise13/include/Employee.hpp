#pragma once
#include "Certificate.hpp"
#include <vector>
// class Employee;
// int Employee::employeeCount = 0;
class Employee{
    private:
        int ID;
        string fullName;
        string birthDay;
        string phone;
        string email;
        int employeeType;// 0 = experience, 1= fresher, 2= intern
        static int employeeCount;
        vector<Certificate*> certificate;

    public:
        Employee(int ID, string fullName, string birthDay, string phone, string email, int employeeType){
            this->ID = ID;
            this->birthDay = birthDay;
            this-> phone = phone;
            this-> email = email;
            this-> employeeType = employeeType;
        }
        int getID(){
            return ID;
        }
        string getFullName(){
            return fullName;
        }
        string getBirthDay(){
            return birthDay;
        }
        string getPhone(){
            return phone;
        }
        string getEmail(){
            return email;
        }
        int getEmployeeType(){
            return employeeType;
        }
        int getEmployeeCount(){
            return employeeCount;
        }
        vector<Certificate*> getCertificate(){
            return certificate;
        }

        void setID(int ID){
            this->ID = ID;
        }
        void setFullName(string fullName){
            this->fullName = fullName;
        }
        void setBirthDay(string birthDay){
            this->birthDay = birthDay;
        }
        void setPhone(string phone){
            this->phone = phone;
        }
        void setEmail(string email){
            this->email= email;
        }
        void setEmployeeType(int employeeType){
            this->employeeType= employeeType;
        }
        void setEmployeeCount(){
            Employee::employeeCount++;
        }
        void setCertificate(Certificate* certificate){
            this->certificate.push_back(certificate);
        }
        virtual int getExpInYear(){
            return -1;
        }
        virtual string getProSkill(){
            return "\0";
        }
        virtual string getGraduationDate(){
            return "\0";
        }
        virtual string getGraduationRank(){
            return "\0";
        }
        virtual string getEducation(){
            return "\0";
        }
        virtual string getMajor(){
            return "\0";
        }
        virtual int getSemester(){
            return -1;
        }
        virtual string getUniversityName(){
            return "\0";
        }
        void showCertificate(){
            auto it = this->certificate.begin();
            int count = 1;
            while(it!= this->certificate.end()){
                cout << "Certificate number "<<count++<<endl;
                cout<<"ID: "<<(*it)->getCertificateID()<<endl;
                cout<<"Name: "<<(*it)->getCertificateName()<<endl;
                cout<<"Rank: "<<(*it)->getCertificateRank()<<endl;
                cout<<"Date: "<<(*it)->getCertificateDate()<<endl;
            }
        }
        virtual void showInfor(){
            cout <<"ID: "<< this->getID()<<endl;
            cout <<"Full name: "<<this->getFullName()<<endl;
            cout<<"Birthday: "<<this->getBirthDay()<<endl;
            cout<<"Phone: "<<this->getPhone()<<endl;
            cout << "Email: "<<this->getEmail()<<endl;
            cout<<"Employee type: "<<this->getEmployeeType()<<endl;
        }

};