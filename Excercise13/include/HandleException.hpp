#ifndef HANDLEEXCEPTION_HPP
#define HANDLEEXCEPTION_HPP
#include <iostream>
#include<stdexcept>
using namespace std;
bool checkBirthDay(string birthDay){
    string s1, s2, s3;
    int count = 1;
    // Divide phone into day-month-year
    for(int i=0; i<birthDay.length(); i++){
        if(count == 1){
            if(birthDay[i]!='/')
                s1 += birthDay[i];
            else
                count++;
        }
        else if(count ==2){
            if(birthDay[i]!='/')
                s2 += birthDay[i];
            else
                count++;            
        }
        else{
            s3 +=birthDay[i]; 
        }
    }
    if(s3<"1960"||s3>"2005") return false;
    else{
        if(s2>"12"||s2<"00") return false;
        else{
            switch(stoi(s2)){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if(stoi(s1)>31||stoi(s1)<0) return false;
                    else return true;
                case 2:
                if(stoi(s3)%4==0){
                        if(stoi(s1)>29||stoi(s1)<0) return false;
                        else return true;
                    }       
                    else{
                        if(stoi(s1)>28||stoi(s1)<0) return false;
                        else return true;                        
                    }                   
                case 4:
                case 6:
                case 9:
                case 11:
                    if(stoi(s1)>30||stoi(s1)<0) return false;
                    else return true;                    
            }
        }
    }
    return true;
}

// Function to check the character 
// is an alphabet or not 
bool isChar(char c) 
{ 
    return ((c >= 'a' && c <= 'z') 
            || (c >= 'A' && c <= 'Z')); 
} 
  
// Function to check the character 
// is an digit or not 
bool isDigit(const char c) 
{ 
    return (c >= '0' && c <= '9'); 
} 
// check valid of phone number
bool checkPhoneNumber(string phone){
    string tmp;
    tmp = phone[0]+phone[1]+phone[2];
    if(tmp!= "090"&&tmp!= "098"&&tmp!= "091"&&tmp!= "098"&&tmp!= "031"&&tmp!= "035"&&tmp!= "038"&&phone.length()!=10) return false;
    for(auto i : phone){
        if(!isDigit(i)) return false;
    }
    return true;
}
// check name 
bool checkName(string name){
    if(name.length()<10||name.length()>50) return false;
    for (auto i: name){
        if(isDigit(i)) return false;
    }
    return true;
}  
// Function to check email id is 
// valid or not 
bool checkEmail(string email) 
{ 
    int countAt=0,countDot=0;
    // Check the first character 
    // is an alphabet or not 
    if (!isChar(email[0])) { 
  
        // If it's not an alphabet 
        // email id is not valid 
        return 0; 
    } 
    // Variable to store position 
    // of At and Dot 
    int At = -1, Dot = -1; 
  
    // Traverse over the email id 
    // string to find position of 
    // Dot and At 
    for (int i = 0; 
         i < email.length(); i++) { 
  
        // If the character is '@' 
        if (email[i] == '@') { 
  
            At = i; 
            countAt++;
        } 
  
        // If character is '.' 
        else if (email[i] == '.') { 
  
            Dot = i; 
            countDot++;
        } 
    } 
  
    // If At or Dot is not present 
    if (At == -1 || Dot == -1||countDot!=1||countAt!=1) 
        return 0; 
  
    // If Dot is present before At 
    if (At > Dot) 
        return 0; 
  
    // If Dot is present at the end 
    return !(Dot >= (email.length() - 1)); 
} 

class InvalidFullNameException: public runtime_error{
    public:
        InvalidFullNameException(): runtime_error("\nFull name is invalid. Try again\n"){}
};

class InvalidEmailException: public runtime_error{
    public:
        InvalidEmailException(): runtime_error("\nEmail is invalid. Try again\n"){}
};

class InvalidBirthdayException: public runtime_error{
    public:
        InvalidBirthdayException(): runtime_error("\nBirthday is invalid. Try again\n"){}
};

class InvalidPhoneNumberException: public runtime_error{
    public:
        InvalidPhoneNumberException(): runtime_error("\nPhone number is invalid. Try again\n"){}
};
#endif