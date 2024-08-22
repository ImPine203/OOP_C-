#ifndef GOODSTUDENT_HPP
#define GOODSTUDENT_HPP
#include "Student.hpp"
class GoodStudent: public Student{
    private:
        float gpa;
        string bestRewardName;
    public:
        GoodStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, float gpa, string bestRewardName): Student(fullName,doB, sex, phoneNumber, universityName, gradeLevel){
            this->gpa=gpa;
            this->bestRewardName  = bestRewardName;
        }
        void showInfor()const{
            Student::showInfor();
            cout<<"GPA: "<<gpa<<endl;
            cout<<"Best reward name: "<<bestRewardName<<endl;
        }
        float getGPA(){
            return gpa;
        }
        string getBestRewardName(){
            return bestRewardName;
        }
};
#endif