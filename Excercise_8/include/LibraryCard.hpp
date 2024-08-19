#ifndef LIBRARYCARD_HPP
#define LIBRARYCARD_HPP
#include "Student.hpp"
class LibraryCard: public Student{
    private:
        string loanSlipNumber;
        unsigned int dateBorrowed;
        unsigned int dueDate;
        string bookNumber;
    public:
        LibraryCard(string name, int age, string clas, string loanSlipNumber, unsigned int dateBorrowed, unsigned int dueDate, string bookNumber):Student(name, age, clas){
            this->loanSlipNumber = loanSlipNumber;
            this->dateBorrowed = dateBorrowed;
            this->dueDate = dueDate;
            this->bookNumber = bookNumber;
        }
        string getLoanSlipNumber(){
            return loanSlipNumber;
        }
        void setLoanSlipNumber(string loanSlipNumber){
            this->loanSlipNumber = loanSlipNumber;
        }
        unsigned int getDateBorrowed(){
            return dateBorrowed;
        } 
        void setDateBorrowed(unsigned int dateBorrowed){
            this->dateBorrowed = dateBorrowed;
        }
        unsigned int getDueDate(){
            return dueDate;
        } 
        void setDueDate(unsigned int dueDate){
            this->dueDate = dueDate;
        }
        string getBookNumber(){
            return bookNumber;
        }        
        void setBookNumber(string bookNumber){
            this->bookNumber=bookNumber;
        }
};
#endif