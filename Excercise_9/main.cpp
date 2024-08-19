#include "./include/Manager.hpp"

int main(){
    Manager manager;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new household\n";
        cout<< "Enter 2: Display information of all household\n";
        cout<<"Enter 3: Exit\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch (select)
        {
        case 1:
            {
                manager.addReceipt();
                cout << endl;
                break;
            }
        case 2:
            {
                manager.display();
                cout << endl;
                break;
            }
        case 3:
            {
                cout<<"========EXIT========\n";
                break;
            }
        default:
            {
                cout<<"Invalid value\n";
                cout <<endl;
                break;
            }
        }

    } while(select!= 3);    
}