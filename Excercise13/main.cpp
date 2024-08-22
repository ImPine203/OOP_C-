#include "./include/Manager.hpp"
int Employee::employeeCount = 0;
int main(){
    Manager manager;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new employee\n";
        cout<<"Enter 2: Delete a employee by ID\n";
        cout<< "Enter 3: Show experience employee\n";
        cout<< "Enter 4: Show fresher employee\n";
        cout<< "Enter 5: Show intern employee\n";
        cout<< "Enter 6: Change information by ID\n";
        cout<<"Enter 7: Exit\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch (select)
        {
        case 1:
            {
                manager.addEmployee();
                cout << endl;
                break;
            }
        case 2:
            {
                int ID;
                cout<<"Enter ID: \n";
                cin>>ID;
                cin.ignore();
                manager.deleteByID(ID);
                cout << endl;
                break;
            }
        case 3:
            {
                manager.findExp();
                cout << endl;
                break;
            }
        case 4:
            {
                manager.findFresher();
                cout << endl;
                break;
            }   
        case 5:
            {
                manager.findIntern();
                cout << endl;
                break;
            }
        case 6:
            {
                int ID;
                cout<<"Enter ID: \n";
                cin>>ID;
                cin.ignore();
                manager.changeInfor(ID);
                cout << endl;
                break;
            }
        case 7:
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

    } while(select!= 7);    
}