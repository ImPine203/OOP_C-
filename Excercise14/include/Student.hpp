#pragma once 
#include <iostream>
using namespace std;
class Student{
    private:
        string fullName;
        string doB;
        string sex;
        string phoneNumber;
        string universityName;
        string gradeLevel;
    public:
        Student(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel){
            this->fullName = fullName;
            this->doB = doB;
            this->sex = sex;
            this->phoneNumber = phoneNumber;
            this->universityName = universityName;
            this->gradeLevel = gradeLevel;
        }
        string getFullName() const{
            return fullName;
        }
        bool operator<(const Student& other) const{
            return this->getFullName() < other.getFullName();
        }
        virtual void showInfor() const {
            cout << "Full Name: " << fullName << endl;
            cout << "Date of Birth: " << doB << endl;
            cout << "Sex: " << sex << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "University Name: " << universityName << endl;
            cout << "Grade Level: " << gradeLevel << endl;
        }
        virtual float getGPA(){
            return -1;
        }
        virtual int getEnglishScore(){
            return -1;
        }
        virtual int getEntryTestScore(){
            return -1;
        }
};