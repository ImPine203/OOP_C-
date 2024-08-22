#ifndef NORMALSTUDENT_HPP
#define NORMALSTUDENT_HPP
#include "Student.hpp"
class NormalStudent: public Student{
    private:
        int englishScore;
        int entryTestScore;
    public:
        NormalStudent(string fullName, string doB, string sex, string phoneNumber, string universityName, string gradeLevel, int englishScore, int entryTestScore): Student(fullName,doB, sex, phoneNumber, universityName, gradeLevel){
            this->englishScore = englishScore;
            this->entryTestScore = entryTestScore;
        }
        void showInfor() const {
            Student::showInfor();
            cout<<"Enlish score: "<<englishScore<<endl;
            cout<<"Entry test score: "<<entryTestScore<<endl;
        }
        int getEnlishScore(){
            return englishScore;
        }
        int getEntryTestScore(){
            return entryTestScore;
        }
};
#endif