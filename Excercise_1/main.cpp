#include <iostream>
#include <vector>
//#include "./include/Manager.hpp"
#ifndef __MANAGER
#include "./include/Manager.hpp"
#endif
void enterInformation(string &name, short int &age, string &gender, string &address){
    cout << "Enter name: \n";
    getline(cin,name);
    cout << "Enter age: \n";
    cin >>age;
    cin.ignore();
    cout << "Enter gender: \n";
    cin >>gender;
    cin.ignore();
    cout << "Enter address: \n";
    getline(cin,address);
}

int main(){
    Manager manager;
    int select;
    do{
        //int a;
        cout <<"================================================\n";
        cout <<"Enter 1: Add new officer!\n";
        cout << "Enter 2: Search officer by name!\n";
        cout << "Enter 3: Show infomation!\n";
        cout << "Enter 4: Exit!\n";
        cout <<"================================================\n";
        cin >> select;
        cin.ignore();
        switch(select){
            case 1:
                {
                    int position;
                    do{
                        string name, gender, address;
                        short int age;
                        cout <<"================================================\n";
                        cout <<"What is the position of this officer?\n";
                        cout <<"Enter 1: Engineer!\n";
                        cout <<"Enter 2: Worker!\n";
                        cout <<"Enter 3: Staff!\n";
                        cout <<"================================================\n";
                        cin >> position;
                        cin.ignore();
                        switch(position){
                        case 1:
                            {
                                string major;
                                enterInformation(name,age,gender,address);
                                cout << "Enter major: \n";
                                getline(cin,major);
                                Officer *ptr = new Engineer(name, age, gender, address, major);
                                manager.addOfficer(ptr);
                                break;
                            }
                        case 2:
                            {
                                short level;                            
                                enterInformation(name,age,gender,address);
                                do{
                                cout << "Enter level: \n";
                                cin >>level;
                                if(level<1||level>10) cout<< "Enter level from 1 to 10!\n";
                                } while (level<1||level>10);
                                cin.ignore();
                                Officer *ptr = new Worker(name, age, gender, address, level);
                                manager.addOfficer(ptr);
                                break;
                            }
                        case 3:
                            {
                                string job;
                                short int age;
                                enterInformation(name,age,gender,address);
                                cout << "Enter job: \n";
                                getline(cin,job);
                                Officer *ptr = new Staff(name, age, gender, address, job);
                                manager.addOfficer(ptr);
                                break;
                            }
                        default:
                            {
                                cout << "Invalid value!\n";
                                cout <<"Please enter number from 1 to 3!\n";
                            }
                        }
                    }while(position>3 && position<1);
                    break;
                }
            case 2:
                {
                    string name;
                    cout <<"================================================\n";
                    cout <<"Who do you want to search?\n";
                    getline(cin,name);
                    // cout <<"Length of name find" <<name.length()<<endl;
                    manager.findByName(name);
                    break; 
                }
            case 3:
                {
                    cout <<"====================INFORMATION=================\n";
                    manager.showInfor();
                    break;        
                }
            case 4:
                {
                    cout <<"=======================EXIT=====================\n";
                }
                break;
            default: 
                {
                    cout << "Invalid value!\n";
                    cout <<"Please enter number from 1 to 4!\n";
                }

        }        
    } while(select!=4);
    return 0;
}
