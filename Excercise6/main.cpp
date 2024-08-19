#include "./include/Manager.hpp"
int main(){
    Manager manager;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new student\n";
        cout<<"Enter 2: Display student > 20 years old\n";
        cout<< "Enter 3: Student = 23 years and live in DN\n";
        cout<<"Enter 4: Exit\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch (select)
        {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.displayGreater20();
            break;
        case 3:
            cout <<"We have "<<manager.Count()<<" students\n";
            break;
        case 4:
            cout<<"========EXIT========\n";
            break;
        default:
            cout<<"Invalid value\n";
            break;
        }

    } while(select!= 4);    
}