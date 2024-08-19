#ifndef ADMISSON_HPP
#define ADMISSON_HPP

#include "CandidateA.hpp"
#include "CandidateB.hpp"
#include "CandidateC.hpp"
#include <vector>

class Admisson{
    private:
        vector<Candidate*> admisson;
    public:
        void addCandidate(Candidate *candidate){
            this->admisson.push_back(candidate);
        }
        void searchByCandidateNumber(string candidateNumber){
            for (auto i: this->admisson){
                if(i->getCandidateNumber()==candidateNumber){
                    displayInformation(i);
                    return;
                }
                cout<<"Not found!\n\n";
            }
        }
        void displayInformation(Candidate *candidate){
            cout<<"Candidate number: "<<candidate->getCandidateNumber()<<endl;
            cout<<"Candidate name: "<<candidate->getName()<<endl;
            cout<<"Candidate address: "<<candidate->getAddress()<<endl;
            cout <<"Candidate priority: "<<candidate->getPriority()<<endl;
            if(candidate->getSubjectA()!="\0"){
                cout <<"Class: A\n\n";
            }
            else if(candidate->getSubjectB()!="\0"){
                cout <<"Class: B\n\n";
            }
            else {
                cout <<"Class: C\n\n";
            }
        }
        void displayCandidate(){
            int count = 1;
            for (auto i:this->admisson){
                cout<<"Candidate number "<<count++<<endl;
                displayInformation(i);
            }
        }
        void Exit(){
            cout<<"=========Exit=========\n";
        }
        bool checkCandidateNumber(string candidateNumber){
            for(auto i: this->admisson){
                if(i->getCandidateNumber()== candidateNumber) return false;
            }
            return true;
        }
        ~Admisson(){
            auto it = this->admisson.begin();
            while(it!=this->admisson.end()){
                delete *it;
                it++;
            }
        }
};

#endif