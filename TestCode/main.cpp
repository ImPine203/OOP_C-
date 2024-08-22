#include"../Excercise13/include/HandleException.hpp"

int main(){
	string s1 = "Pham Thanh1 Tung", email, birthDay, phone;
	// cout<<"Enter fullname: \n";
	bool check = false;
	// getline(cin, s1);
	do{
		try {
			cout<<"Enter fullname: \n";
			getline(cin, s1);	
			if(!checkName(s1)){
				throw InvalidFullNameException();
				// check = true;
			}
			check = true;
			cout<<endl;
		}
		catch(InvalidFullNameException &invalidFullName){
			cout<<invalidFullName.what()<<endl;
			// check = false;
		}
		// check = true;
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
}