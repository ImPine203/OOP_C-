#include "./include/Hotel.hpp"

int main(){
    Hotel manager;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new customer\n";
        cout<<"Enter 2: Delete customer by ID\n";
        cout<< "Enter 3: Caculate rental\n";
        cout<<"Enter 4: Exit\n";
        cin >> select;
        cin.ignore();
        switch(select){
            case 1:
                {   char type;
                    do{
                        cout <<"What kind of room?\n";
                        cout<<"Enter a: Room A\n";
                        cout<<"Enter b: Room B\n";
                        cout<<"Enter c: Room C\n";
                        cin >> type;
                        cin.ignore();
                        switch(type){
                            case 'a':
                                
                        }
                    } while (type!='a'&&type!='b'&&type!='c');
                    break;
                }
            case 2:
                {
                    string ID;
                    cout<<"Enter ID of customer\n";
                    getline(cin,ID);
                    manager.deleteByID(ID);
                    break;
                }
            case 3:
                {
                    string ID;
                    cout<<"Enter ID of customer\n";
                    getline(cin,ID);
                    if(manager.caculateMoney(ID))
                        cout<<"Retal: "<<manager.caculateMoney(ID)<<"$\n";
                    else cout<<"This ID not Existed\n";
                    break;
                }
            case 4:
                {
                    cout << "=========EXIT========\n";
                    break;
                }
            default:
                {
                    cout<<"This value is invalid\n";
                    break;
                }
        }
    }while(select!=4);
}