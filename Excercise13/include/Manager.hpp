#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Experience.hpp"
#include "Employee.hpp"
#include "Fresher.hpp"
#include "Intern.hpp"
#include "CheckValid.hpp"

class Manager{
    private:
        vector<Employee*> manager;
    public:
        void enterGeneralInfor(int &ID,string &fullName,string &birthDay,string &phone, string &email, int &employeeType ){
            cout<<"Enter ID: \n";
            cin>>ID;
            cout<<"Enter full name: \n";
            getline(cin, fullName);
            cout<<"Enter birthday: \n";
            getline(cin, birthDay);
            cout<<"Enter phone number: \n";
            getline(cin, phone);
            cout<<"Enter email: \n";
            getline(cin, email);
            cout<<"Enter employee type: ";
            cin >>employeeType;
            cin.ignore();
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
                int employeeCount = this->manager.size();

                int expInYear;
                string proSkill;
                string graduationDate;
                string graduationRank;
                string education;
                string major;
                int semeter;
                string universityName;
                enterGeneralInfor(ID, fullName, birthDay, phone, email, employeeType);
                if(employeeType ==0){
                    int expInYear;
                    string proSkill;
                    cout<<"Enter experience in year: \n";
                    cin>>expInYear;
                    cin.ignore();
                    cout<<"Enter proskill: \n";
                    getline(cin, proSkill);
                    this->manager.push_back(new Experience(ID,fullName, birthDay, phone, email,employeeType,employeeCount, expInYear, proSkill));              
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
                    this->manager.push_back(new Fresher(ID,fullName, birthDay, phone, email,employeeType,employeeCount, graduationDate, graduationRank, education));     
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
                    this->manager.push_back(new Intern(ID,fullName, birthDay, phone, email,employeeType,employeeCount, major, semeter, universityName));            
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
                            (*it)->showInforEx();
                        }
                        else if((*it)->getEmployeeType()==1){
                            (*it)->showInforFresher();
                        }
                        else{
                            (*it)->showInforIntern();
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
                        }while(choice != 8);
                    }
                    it++;
                }
            }

};
#endif
