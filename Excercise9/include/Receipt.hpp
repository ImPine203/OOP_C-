#ifndef RECEIPT_HPP
#define RECEIPT_HPP
#include "Household.hpp"
class Receipt: public Household{
    private:
        int oldNumber;
        int newNumber;
        int payment;
    public:
        Receipt(string owner, int homeNumber, int elecMeterNumber, int oldNumber, int newNumber, int payment = 0): Household(owner, homeNumber, elecMeterNumber){
            this->oldNumber = oldNumber;
            this->newNumber = newNumber;
            this->payment = payment;
        }
        int getOldNumber(){
            return oldNumber;
        }
        void setOldNumber(int oldNumber){
            this->oldNumber = oldNumber;
        }
        int getNewNumber(){
            return newNumber;
        }
        void setNewNumber(int newNumber){
            this->newNumber = newNumber;
        }
        int getPayment(){
            return (this->newNumber-this->oldNumber)*5;
        }
};
#endif