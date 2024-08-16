#include "./include/Admisson.hpp"

void enterInformation(string &candidateNumber, string &name, string &address, int &priority, Admisson &admisson){
    do{
        cout << "Enter candidate number: \n";
        getline(cin,candidateNumber);
        if(!admisson.checkCandidateNumber(candidateNumber)){
            cout<<"This candidate's number is existed\n";
        }
    }while(!admisson.checkCandidateNumber(candidateNumber));
    cout<<"Enter candidate's name: \n";
    getline(cin,name);
    cout<<"Enter candidate's address: \n";
    getline(cin,address);
    cout<<"Enter candidate's priority: \n";
    cin>>priority;
    cin.ignore();
    cout << endl;
}

int main(){
    Admisson admission;
    int select;
    do{
        cout <<"================================================\n";
        cout <<"Enter 1: Add new candidate!\n";
        cout << "Enter 2: Search candidate by candidate's number!\n";
        cout << "Enter 3: Show infomation!\n";
        cout << "Enter 4: Exit!\n";
        cout <<"================================================\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch(select){
            case 1:
                {
                    string candidateNumber;
                    string name;
                    string address;
                    int priority; 
                    char clas;
                    do{
                        cout<< "What is candidate's class?\n";
                        cout<<"Enter a: class A\n";
                        cout<<"Enter b: class B\n";
                        cout<<"Enter c: class C\n";
                        cin>>clas;
                        cin.ignore();
                        switch(clas){
                            case 'a':
                                {
                                    enterInformation(candidateNumber, name, address, priority, admission);
                                    admission.addCandidate(new CandidateA(candidateNumber, name, address, priority));
                                    break;
                                }
                            case 'b':
                                {
                                    enterInformation(candidateNumber, name, address, priority, admission);
                                    admission.addCandidate(new CandidateB(candidateNumber, name, address, priority));
                                    break;
                                }
                            case 'c':
                                {
                                    enterInformation(candidateNumber, name, address, priority, admission);
                                    admission.addCandidate(new CandidateC(candidateNumber, name, address, priority));
                                    break;
                                }
                            default:
                                {
                                    cout<<"Invalid value, enter only char a, b or c\n";
                                }
                        }
                        }while(clas!='a'&&clas!='b'&&clas!='c');
                    break;
                }
            case 2:
                {
                    string candidateNumber;
                    cout <<"Enter candidate's number you want to search\n";
                    getline(cin,candidateNumber);
                    admission.searchByCandidateNumber(candidateNumber);
                    break;
                }
            case 3:
                {
                    admission.displayCandidate();
                    break;
                }
            case 4:
                {
                    admission.Exit();
                    break;
                }
            default:
                {
                    cout << "Invalid value, enter a number from 1 to 4\n\n";
                }
        }        
    }while(select!=4);
    return 0;
}