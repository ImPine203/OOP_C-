#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "Student.hpp"
#include<vector>
class Manager{
    private:
        vector<Student*> manager;
    public:
    void addInfor(string &name, int &age, string &homeTown){
        cout<<"Enter name: \n";
        getline(cin, name);
        cout<<"Enter age: \n";
        cin>>age;
        cin.ignore();
        cout<<"Enter home town: \n";
        getline(cin, homeTown);
    }
        void addStudent(){
            string name;
            int age;
            string homeTown;
            addInfor(name, age, homeTown);
            this->manager.push_back(new Student(name, age, homeTown));
        }
        void displayStudent(Student *student){
            cout<<"Name: "<<student->getName()<<endl;
            cout <<"Age: "<<student->getAge()<<endl;
            cout<<"Home town: "<<student->getHomeTown()<<endl;
        }
        void displayGreater20(){
            auto it = this->manager.begin();
            int count = 1;
            while(it!=this->manager.end()){
                if((*it)->getAge()>20){
                    cout<<"Student number "<<count++<<endl;
                    displayStudent(*it);
                }
                it++;
            }
        }
        int Count(){
            auto it = this->manager.begin();
            int count = 0;
            while(it!=this->manager.end()){
                // cout << (*it)->getAge()<<endl;
                // cout << (*it)->getHomeTown()<<endl;
                if((*it)->getAge()==23&&(*it)->getHomeTown()=="DN"){
                    // displayStudent(*it);
                    count ++;
                }
                it++;
            }            
            return count;
        }
        ~Manager(){
            auto it = this->manager.begin();
            while(it != this->manager.end()){               
                delete (*it);
                it = this->manager.erase(it);
                break;
                it++;
            }            
        }
};
#endif