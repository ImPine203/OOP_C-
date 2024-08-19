#include "./include/Hotel.hpp"

void addInfor(string &name, short int &age, string &ID, short int &rentDay){
    cout << "Enter name: \n";
    getline(cin,name);
    cout << "Enter age: \n";
    cin>>age;
    cin.ignore();
    cout<<"Enter ID: \n";
    getline(cin,ID);
    cout << "Enter number of rent day:\n";
    cin >> rentDay;
    cin.ignore();
}

// Person *ptrP;
// Room *ptrR;

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
        cout << endl;
        switch(select){
            case 1:
                {   char type;
                    string name;
                    string ID;
                    short int age;
                    short int rentDay;
                    do{
                        cout <<"What kind of room?\n";
                        cout<<"Enter a: Room A\n";
                        cout<<"Enter b: Room B\n";
                        cout<<"Enter c: Room C\n";
                        cin >> type;
                        cin.ignore();
                        switch(type){
                            case 'a':
                                {
                                    addInfor(name, age, ID, rentDay);
                                    // ptrP = new Person(name, age, ID);
                                    // Room *ptrR = new RoomC(rentDay);
                                    // pair<Person*, Room*> customer = make_pair(new Person(name, age, ID), new RoomA(rentDay));
                                    // customera = make_pair(new Person(name, age, ID), new RoomA(rentDay));
                                    manager.addCustomer(new Person(name, age, ID), new RoomA(rentDay));
                                    cout << endl;
                                    break;
                                }
                            case 'b':
                                {
                                    addInfor(name, age, ID, rentDay);
                                    // ptrP = new Person(name, age, ID);
                                    // Room *ptrR = new RoomC(rentDay);
                                    // pair<Person*, Room*> customer = make_pair(new Person(name, age, ID), new RoomB(rentDay));
                                    // customerb = make_pair(new Person(name, age, ID), new RoomA(rentDay));
                                    manager.addCustomer(new Person(name, age, ID), new RoomB(rentDay));
                                    cout << endl;
                                    break;
                                }                            
                            case 'c':
                                {
                                    addInfor(name, age, ID, rentDay);
                                    // ptrP = new Person(name, age, ID);
                                    // Room *ptrR = new RoomC(rentDay);
                                    // pair<Person*, Room*> customer = make_pair(new Person(name, age, ID), new RoomC(rentDay));
                                    // customerc = make_pair(new Person(name, age, ID), new RoomA(rentDay));
                                    manager.addCustomer(new Person(name, age, ID), new RoomC(rentDay));
                                    cout << endl;
                                    break;
                                }
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
                    cout << endl;
                    break;
                }
            case 3:
                {
                    string ID;
                    cout<<"Enter ID of customer\n";
                    getline(cin,ID);
                    if(manager.caculateRental(ID))
                        cout<<"Retal: "<<manager.caculateRental(ID)<<"$\n";
                    else cout<<"This ID not Existed\n";
                    cout << endl;
                    break;
                }
            case 4:
                {
                    cout << "=========EXIT========\n";
                    break;
                }
            case 5:
                manager.display();
                break;
            default:
                {
                    cout<<"This value is invalid\n";
                    break;
                }
        }
    }while(select!=6);
}