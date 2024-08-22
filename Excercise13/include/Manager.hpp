#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Experience.hpp"
#include "Employee.hpp"
#include "Fresher.hpp"
#include "Intern.hpp"
#include "HandleException.hpp"

class Manager{
    private:
        vector<Employee*> manager;
    public:
        void enterGeneralInfor(int &ID,string &fullName,string &birthDay,string &phone, string &email, int &employeeType ){
            bool check = false;
            cout<<"Enter ID: \n";
            cin>>ID;
            cin.ignore();
            do{
                try {
                    cout<<"Enter fullname: \n";
                    getline(cin, fullName);	
                    if(!checkName(fullName)){
                        throw InvalidFullNameException();
                    }
                    check = true;
                }
                catch(InvalidFullNameException &invalidFullName){
                    cout<<invalidFullName.what()<<endl;
                }
            }while(!check);
            check = false;
            do{
                try {
                    cout<<"Enter birthday: \n";
                    getline(cin, birthDay);	
                    if(!checkBirthDay(birthDay)){
                        throw InvalidBirthdayException();
                    }
                    check = true;
                    cout<<endl;
                }
                catch(InvalidBirthdayException &invalidBirthday){
                    cout<<invalidBirthday.what()<<endl;
                }
            }while(!check);
            check = false;
            do{
                try {
                    cout<<"Enter phone number: \n";
                    getline(cin, phone);	
                    if(!checkPhoneNumber(phone)){
                        throw InvalidPhoneNumberException();
                    }
                    check = true;
                    cout<<endl;
                }
                catch(InvalidPhoneNumberException &invalidPhone){
                    cout<<invalidPhone.what()<<endl;
                }
            }while(!check);
            check = false;
            do{
                try {
                    cout<<"Enter email: \n";
                    getline(cin, email);	
                    if(!checkEmail(email)){
                        throw InvalidEmailException();
                    }
                    check = true;
                    cout<<endl;
                }
                catch(InvalidEmailException &invalidEmail){
                    cout<<invalidEmail.what()<<endl;
                }
            }while(!check);
            cout<<"Enter employee type: ";
            cin >>employeeType;
            cin.ignore();
            cout<<endl;
        }
        void enterCertificate(int &ID, string &name, string &rank, string &date){
            cout<<"Enter ID: \n";
            cin>>ID;
            cin.ignore();
            cout<<"Enter certificate name: \n";
            getline(cin, name);
            cout<<"Enter certificate rank: \n";
            getline(cin, rank);
            cout<<"Enter certificate date: \n";
            getline(cin, date);
        }
        void addEmployee(){
            char more;
            do{
                int ID;
                string fullName;
                string birthDay;
                string phone;
                string email;
                int employeeType;// 0 = experience, 1= fresher, 2= intern
                // int employeeCount = this->manager.size();
                enterGeneralInfor(ID, fullName, birthDay, phone, email, employeeType);
                if(employeeType ==0){
                    int expInYear;
                    string proSkill;
                    cout<<"Enter experience in year: \n";
                    cin>>expInYear;
                    cin.ignore();
                    cout<<"Enter proskill: \n";
                    getline(cin, proSkill);
                    this->manager.push_back(new Experience(ID,fullName, birthDay, phone, email,employeeType, expInYear, proSkill));              
                }
                else if(employeeType==1){
                    string graduationDate;
                    string graduationRank;
                    string education;      
                    cout<<"Enter graduation date: \n";
                    getline(cin, graduationDate);     
                    cout<<"Enter graduation rank: \n";
                    getline(cin, graduationRank);
                    cout<<"Enter education: \n";
                    getline(cin, education);  
                    this->manager.push_back(new Fresher(ID,fullName, birthDay, phone, email,employeeType, graduationDate, graduationRank, education));     
                }
                else{
                    string major;
                    int semeter;
                    string universityName;   
                    cout<<"Enter major: \n";
                    getline(cin, major);
                    cout<<"Enter semeter: \n";
                    cin>>semeter;
                    cin.ignore();
                    cout<<"Enter university name: \n";
                    getline(cin, universityName);
                    this->manager.push_back(new Intern(ID,fullName, birthDay, phone, email,employeeType, major, semeter, universityName));            
                }
                char hasCertificate;
                cout<<"Does this employee have certificates?\n";
                cout<<"Enter y - yes or n - no\n";
                cin>>hasCertificate;
                if(hasCertificate=='y'){
                    char add;
                    do{
                        int certificateID;
                        string certificateName;
                        string certificateRank;
                        string certificateDate;                    
                        enterCertificate(certificateID, certificateName,certificateRank,certificateDate);
                        this->manager.back()->setCertificate(new Certificate(certificateID, certificateName, certificateRank, certificateDate));
                        cout<<"Does this employee have another certificate?\n";
                        cout<<"Enter y - yes or any character - no\n";
                        cin>>add;
                        cin.ignore();
                    }while(add=='y');
                }
                    this->manager.back()->setEmployeeCount();
                    cout<<"Do you want to add another employee?\n";
                    cout<<"Enter y - yes or any character - no\n";
                    cin>>more;
                    cin.ignore();                
                }while(more =='y');
            }
            void changeInfor(int ID){
                auto it = this->manager.begin();
                while(it!=this->manager.end()){
                    if((*it)->getID() ==ID){
                        if((*it)->getEmployeeType()==0){
                            (*it)->showInfor();
                        }
                        else if((*it)->getEmployeeType()==1){
                            (*it)->showInfor();
                        }
                        else{
                            (*it)->showInfor();
                        }
                        int choice;
                        do{
                            cout<<"What you want to change\n";
                            cout<<"Enter 1: ID\n";
                            cout<<"Enter 2: Full name\n";
                            cout<<"Enter 3: Birthday\n";
                            cout<<"Enter 4: Phone number\n";
                            cout<<"Enter 5: Email\n";
                            cout<<"Enter 6: Employee type\n";
                            switch(choice){
                                case 1:
                                    {
                                        int newID;
                                        cout<<"Enter new ID:\n";
                                        cin>>newID;
                                        cin.ignore();
                                        (*it)->setID(newID);
                                        break;
                                    }
                                case 2:
                                    {
                                        string newName;
                                        cout<<"Enter new full name:\n";
                                        getline(cin,newName);
                                        (*it)->setFullName(newName);
                                        break;
                                    }
                                case 3:
                                    {
                                        string newBirthDay;
                                        cout<<"Enter new birthday:\n";
                                        getline(cin, newBirthDay);
                                        (*it)->setBirthDay(newBirthDay);
                                        break;
                                    }
                                case 4:
                                    {
                                        string newPhone;
                                        cout<<"Enter new phone number:\n";
                                        getline(cin, newPhone);
                                        (*it)->setPhone(newPhone);
                                        break;
                                    }
                                case 5:
                                    {
                                        string newEmail;
                                        cout<<"Enter new email:\n";
                                        getline(cin, newEmail);
                                        (*it)->setEmail(newEmail);
                                        break;
                                    }
                                case 6:
                                    {
                                        int newEmployeeType;
                                        cout<<"Enter new employee type:\n";
                                        cin>>newEmployeeType;
                                        cin.ignore();
                                        (*it)->setEmployeeType(newEmployeeType);
                                        break;
                                    }
                                default:
                                    {
                                    cout<<"Invalid!\n";
                                    break;
                                    }
                            }
                        }while(choice != 8);
                    }
                    it++;
                }
            }
            void deleteByID(int ID){
                // cout<<"Enter ID: \n";
                auto it = this->manager.begin();
                while(it != this->manager.end()){
                    if((*it)->getID()==ID){
                        delete *it;
                        it = this->manager.erase(it);
                        return;
                    }
                    it++;
                }
                cout<<"Invalid\n";
                cout<<endl;
            }
            void findExp(){
                // cout<<"Enter ID: \n";
                auto it = this->manager.begin();
                while(it != this->manager.end()){
                    if((*it)->getEmployeeType()==0){
                        (*it)->showInfor();
                    }
                    it++;
                }
                cout<<endl;
            }            
            void findFresher(){
                // cout<<"Enter ID: \n";
                auto it = this->manager.begin();
                while(it != this->manager.end()){
                    if((*it)->getEmployeeType()==1){
                        (*it)->showInfor();
                    }
                    it++;
                }
                cout<<endl;
            }   
            void findIntern(){
                // cout<<"Enter ID: \n";
                auto it = this->manager.begin();
                while(it != this->manager.end()){
                    if((*it)->getEmployeeType()==2){
                        (*it)->showInfor();
                    }
                    it++;
                }
                cout<<endl;
            } 
};
#endif
