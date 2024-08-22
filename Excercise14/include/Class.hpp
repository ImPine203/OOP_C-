#ifndef CLASS_HPP
#define CLASS_HPP
#include"GoodStudent.hpp"
#include"NormalStudent.hpp"
#include "../../Excercise13/include/HandleException.hpp"
#include<set>
#include<vector>
#include<algorithm>

class Class{
    private:
        vector<Student*> clas;
    public:
        void addGeneralInfor(string &fullName, string &doB, string &sex, string &phoneNumber, string &universityName, string &gradeLevel){
            bool check = false;
            do{
                try {
                    cout<<"Enter fullname: \n";
                    getline(cin, fullName);	
                    if(!checkName(fullName)){
                        throw InvalidFullNameException();
                    }
                    check = true;
                }
                catch(InvalidFullNameException &invalidFullName){
                    cout<<invalidFullName.what()<<endl;
                }
            }while(!check);
            check = false;
            do{
                try {
                    cout<<"Enter birthday: \n";
                    getline(cin, doB);	
                    if(!checkBirthDay(doB)){
                        throw InvalidBirthdayException();
                    }
                    check = true;
                    cout<<endl;
                }
                catch(InvalidBirthdayException &invalidBirthday){
                    cout<<invalidBirthday.what()<<endl;
                }
            }while(!check);
            check = false;
            cout<<"Enter sex: \n";
            getline(cin,sex);
            cout<<endl;
            do{
                try {
                    cout<<"Enter phone number: \n";
                    getline(cin, phoneNumber);	
                    if(!checkPhoneNumber(phoneNumber)){
                        throw InvalidPhoneNumberException();
                    }
                    check = true;
                    cout<<endl;
                }
                catch(InvalidPhoneNumberException &invalidPhone){
                    cout<<invalidPhone.what()<<endl;
                }
            }while(!check);
            cout<<"Enter university name: \n";
            getline(cin,universityName);
            cout<<endl;
            cout<<"Enter grade level: \n";
            getline(cin,gradeLevel);
            cout<<endl;
        }
        void addStudent(Student* st){
            this->clas.push_back(st);
        }
        bool compare(Student* a, Student*b){
            if ((a->getGPA()!=-1)&&(b->getEnglishScore()!=-1)) return true;
            else if(a->getEnglishScore()!=-1&&b->getGPA()!=-1) return false;
            else if(a->getGPA()!=-1&&b->getGPA()!=-1){
                if(a->getGPA()>b->getGPA()) return true;
                else if(a->getGPA()<b->getGPA()) return false;
                else{
                    if (a->getFullName()>b->getFullName()) return true;
                    else return false;
                }
            }
            else{
                if(a->getEntryTestScore()>b->getEntryTestScore()) return true;
                else if(a->getEntryTestScore()<b->getEntryTestScore()) return false;
                else{
                    if(a->getEnglishScore()>b->getEnglishScore()) return true;
                    else if(a->getEnglishScore()<b->getEnglishScore()) return false;
                    else{
                        if (a->getFullName()>b->getFullName()) return true;
                        else return false;                        
                    }
                }
            }
        }
        void selectStudent(){
            int min, max;
            cout<<"Enter minimum and maximum candidate: \n";
            cin>>min>>max;
            sort(clas.begin(), clas.end(), [](Student* a, Student* b) {
                GoodStudent* gsA = dynamic_cast<GoodStudent*>(a);
                GoodStudent* gsB = dynamic_cast<GoodStudent*>(b);

                if (gsA && gsB) {
                    // both are GoodStudent, compare with GPA
                    if (gsA->getGPA() != gsB->getGPA()) {
                        return gsA->getGPA() > gsB->getGPA();
                    }
                    // GPA are equal, compare with name
                    return gsA->getFullName() < gsB->getFullName();
                }

                if (gsA) {
                    // a is GoodStudent, b not 
                    return true;
                }

                if (gsB) {
                    // b is GoodStudent, a not
                    return false;
                }

                // both are not GoodStudent
                if (a->getEntryTestScore() != b->getEntryTestScore()) {
                    return a->getEntryTestScore() > b->getEntryTestScore();
                }

                if (a->getEnglishScore() != b->getEnglishScore()) {
                    return a->getEnglishScore() > b->getEnglishScore();
                }

                // Finally compare with name
                return a->getFullName() < b->getFullName();
            });
            cout<<"Candidates are chosen: \n";
            cout<<endl;
            int count = 1;
            auto it = this->clas.begin();
            while(it!=this->clas.end()){
                if(count <= min){
                    cout <<"Candidate passed number: "<<count++<<endl;
                    (*it)->showInfor();
                    cout<<endl;
                }
                if(count <= max && count >min){
                    if((*it)->getGPA()!=-1){
                        cout <<"Candidate passed number: "<<count++<<endl;
                        (*it)->showInfor();   
                        cout<<endl;                     
                    }
                }
                it++;
            }
        }
        void display(){
            sort(clas.begin(),clas.end(),[](Student*a, Student*b){
                return a->getFullName()<b->getFullName();
            });
            auto it = this->clas.begin();
            while(it!=this->clas.end()){
                (*it)->showInfor();
                cout <<endl;
                it++;
            }
        }
};
#endif