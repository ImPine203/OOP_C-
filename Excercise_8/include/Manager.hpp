#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "LibraryCard.hpp"
#include <vector>
class Manager{
    private:
        vector<LibraryCard*> manager;
    public:
        void addInfor(string &name, int &age, string &clas, string &loanSlipNumber, unsigned int &dateBorrowed, unsigned int &dueDate, string &bookNumber){
            cout<<"Enter loan slip number: \n";
            getline(cin, loanSlipNumber);
            cout<<"Enter date borrowed: \n";
            cin>>dateBorrowed;
            cout<<"Enter due date: \n";
            cin >> dueDate;
            cin.ignore();
            cout<<"Enter book number: \n";
            getline(cin,bookNumber);
            cout<<"Enter name of stdudent: \n";
            getline(cin, name);
            cout<<"Enter age: \n";
            cin>>age;
            cin.ignore();
            cout<<"Enter class: \n";
            getline(cin, clas);
        }
        void addCard(){
            string loanSlipNumber;
            unsigned int dateBorrowed;
            unsigned int dueDate;
            string bookNumber;
            string name;
            int age;
            string clas;
            addInfor(name, age, clas, loanSlipNumber, dateBorrowed, dueDate, bookNumber);
            this->manager.push_back(new LibraryCard(name, age, clas, loanSlipNumber, dateBorrowed, dueDate, bookNumber));
        }
        void deleteCard(string loanSlipCard){
            auto it = this->manager.begin();
            while(it != this->manager.end()){
                if((*it)->getLoanSlipNumber() == loanSlipCard){
                    delete (*it);
                    it = this->manager.erase(it);
                    break;
                }
                it++;
            }
            if(it == this->manager.end()) cout << "This card is not existed\n";
            cout << endl;
        }
        void displayCard(){
            auto it = this->manager.begin();
            int count = 1;
            while(it != this->manager.end()){
                cout<<"Library card number "<<count++<<endl;
                cout << "Loan slip number: "<<(*it)->getLoanSlipNumber()<<endl;
                cout<<"Date borrowed: "<<(*it)->getDateBorrowed()<<endl;
                cout<<"Due date: "<<(*it)->getDueDate()<<endl;
                cout<<"Book number: "<<(*it)->getBookNumber()<<endl;
                cout<<"Student's name: "<<(*it)->getName()<<endl;
                cout<<"Student's age: "<<(*it)->getAge()<<endl;
                cout<<"Student's class: "<<(*it)->getClas()<<endl;
                it++;
            }            
        }
};
#endif