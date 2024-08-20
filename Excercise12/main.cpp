#include "./include/Manager.hpp"

int main(){
    Manager manager;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new vehicle\n";
        cout<<"Enter 2: Delete vehicle by ID\n";
        cout<<"Enter 3: Search a vehicle by manafacturer and color\n";
        cout<< "Enter 4: Display information of all vehicle\n";
        cout<<"Enter 5: Exit\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch (select)
        {
        case 1:
            {
                int type;
                int ID;
                string manufacturer;
                int yearOfManufacture;
                float price;
                string color;                
                do{
                    cout << "Type of vehicle: \n";
                    cout<<"Enter 1: Car\n";
                    cout<<"Enter 2: Motorbike\n";
                    cout<<"Enter 3: Truck\n";
                    cin>>type;
                    cin.ignore();
                    cout<<endl;
                    switch (type)
                    {
                        case 1:
                            {
                                int numberOfSeat;
                                string typeOfEngine;
                                manager.addGeneralInfor(ID, manufacturer, yearOfManufacture, price, color);
                                cout << "Enter number of seat: \n";
                                cin>>numberOfSeat;
                                cin.ignore();
                                cout<<"Enter type of engine: \n";
                                getline(cin, typeOfEngine);
                                manager.addVehicle(new Car(ID, manufacturer, yearOfManufacture, price, color, numberOfSeat, typeOfEngine));
                                break;
                            }
                        case 2:
                            {
                                float power;
                                manager.addGeneralInfor(ID, manufacturer, yearOfManufacture, price, color);
                                cout<<"Enter power: \n";
                                cin >> power;
                                manager.addVehicle(new Motorbike(ID, manufacturer, yearOfManufacture, price, color, power));
                                break;
                            }
                        case 3:
                            {
                                float payload;
                                manager.addGeneralInfor(ID, manufacturer, yearOfManufacture, price, color);
                                cout<<"Enter payload: \n";
                                cin >> payload;
                                manager.addVehicle(new Truck(ID, manufacturer, yearOfManufacture, price, color, payload));
                                break;
                            }
                        default:
                            cout << "Invalid value\n";
                    }
                }while(type>3&&type<1);
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
                string manufacturer;
                string color;
                cout<<"Enter manufacturer: \n";
                getline(cin, manufacturer);
                cout<<"Enter color: \n";
                getline(cin, color);
                manager.searchByManuColor(manufacturer, color);
                cout << endl;
                break;
            }
        case 4:
            {
                manager.display();
                cout <<endl;
            }
        case 5:
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