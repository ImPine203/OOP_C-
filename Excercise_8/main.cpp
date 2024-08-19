#include "./include/Manager.hpp"

int main(){
    Manager manager;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new library card\n";
        cout<<"Enter 2: Delete a library card by loan slip number\n";
        cout<< "Enter 3: Display information of library card\n";
        cout<<"Enter 4: Exit\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch (select)
        {
        case 1:
            {
                manager.addCard();
                cout << endl;
                break;
            }
        case 2:
            {
                string loanSlipNumber;
                cout<<"Enter loan slip number: \n";
                getline(cin,loanSlipNumber);
                manager.deleteCard(loanSlipNumber);
                cout << endl;
                break;
            }
        case 3:
            {
                manager.displayCard();
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