#include "./include/Class.hpp"

int main(){
    Class clas;
    int select;
    do{
        cout << "===================\n";
        cout<<"Enter 1: Add new student\n";
        cout<<"Enter 2: Select candidate\n";
        cout<< "Enter 3: Display information of candidate\n";
        cout<<"Enter 4: Exit\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch (select)
        {
        case 1:
            {
                int type;
                do{
                    string fullName;
                    string doB;
                    string sex;
                    string phoneNumber;
                    string universityName;
                    string gradeLevel;                    
                    cout<<"What kind of this student:\n";
                    cout<<"Enter 1: Good student\n";
                    cout<<"Enter 2: Normal student\n";
                    cin>>type;
                    cin.ignore();
                    switch (type)
                    {
                    case 1:
                        {
                            float gpa;
                            string bestReward;
                            clas.addGeneralInfor(fullName, doB,sex,phoneNumber,universityName,gradeLevel);
                            cout<<"Enter GPA: \n";
                            cin>>gpa;
                            cin.ignore();
                            cout<<"Enter best reward: \n";
                            getline(cin,bestReward);
                            clas.addStudent(new GoodStudent(fullName, doB,sex,phoneNumber,universityName,gradeLevel,gpa,bestReward));
                            break;
                        }
                    case 2:
                        {
                            int englishScore;
                            int entryTestScore;
                            clas.addGeneralInfor(fullName, doB,sex,phoneNumber,universityName,gradeLevel);
                            cout<<"Enter english score: \n";
                            cin>>englishScore;
                            cin.ignore();
                            cout<<"Enter entry test score: \n";
                            cin>>entryTestScore;
                            cin.ignore();
                            clas.addStudent(new NormalStudent(fullName, doB,sex,phoneNumber,universityName,gradeLevel,englishScore,entryTestScore));
                            break;
                        }
                    default:
                        cout<<"Invalid\n";
                        break;
                    }
                }while(type >2||type<1);
                cout<<endl;
                break;
            }
        case 2:
            {
                clas.selectStudent();
                break;
            }
        case 3:
            {
                clas.display();
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