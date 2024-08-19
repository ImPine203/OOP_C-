#pragma once 
#include<iostream>

using namespace std;

class Candidate{
    private:
        string candidateNumber;
        string name;
        string address;
        int priority;
    public:
        Candidate(string candidateNumber, string name, string address, int priority){
            this ->candidateNumber = candidateNumber;
            this->name = name;
            this-> address = address;
            this-> priority = priority;
        }
        string getCandidateNumber(){
            return candidateNumber;
        }
        void setCandidateNumber(string candidateNumber){
            this->candidateNumber = candidateNumber;
        }
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        string getAddress(){
            return address;
        }
        void setAddress(string address){
            this->address = address;
        }
        int getPriority(){
            return priority;
        }
        void setPriority(int priority){
            this->priority = priority;
        }
        virtual string getSubjectA(){
            return "\0";
        }
        virtual string getSubjectB(){
            return "\0";
        }
        virtual string getSubjectC(){
            return "\0";
        }


};
