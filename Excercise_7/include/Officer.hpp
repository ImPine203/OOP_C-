#ifndef OFFICER_HPP
#define OFFICER_HPP
#include "Person.hpp"
class Officer: public Person{
    private:
        float baseSalary;
        float bonus;
        float fines;
        float netSalary;
    public:
        Officer(string name, int age, string homeTown, string ID, float baseSalary, float bonus, float fines, float netSalary = 0): Person(name, age, homeTown, ID){
            this->baseSalary = baseSalary;
            this->bonus = bonus;
            this-> fines = fines;
            this->netSalary = netSalary;
            // setNetSalary(baseSalary,bonus,fines);
        }
        float getBaseSalary(){
            return baseSalary;
        }
        void setBaseSalary(float baseSalary){
            this->baseSalary = baseSalary;
        }
        float getBonus(){
            return bonus;
        }
        void setBonus(float bonus){
            this->bonus = bonus;
        }
        float getFines(){
            return fines;
        }
        void setFines(float fines){
            this->fines = fines;
        }
        float getNetSalary(){
            return this->baseSalary+this->bonus-this->fines;
        }
        // void setNetSalary(float baseSalary, float bonus, float fines){
        //     this->baseSalary = baseSalary+bonus-fines;
        // }
};
#endif