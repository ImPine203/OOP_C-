#include "./include/Manager.hpp"

int main(){
    Manager manager;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new officer\n";
        cout<<"Enter 2: Delete a teacher with ID\n";
        cout<< "Enter 3: Display information with net salary\n";
        cout<<"Enter 4: Exit\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch (select)
        {
        case 1:
            {
                manager.addOfficer();
                cout << endl;
                break;
            }
        case 2:
            {
                string id;
                cout<<"Enter id: \n";
                getline(cin,id);
                manager.deleteByID(id);
                cout << endl;
                break;
            }
        case 3:
            {
                manager.display();
                cout << endl;
                break;
            }
        case 4:
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

    } while(select!= 4);    
}