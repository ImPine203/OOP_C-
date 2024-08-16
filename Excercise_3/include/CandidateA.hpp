#ifndef CANDIDATEA_HPP
#define CANDIDATEA_HPP
#include "Candidate.hpp"

class CandidateA: public Candidate{
    private:
        string subjectA = "Math, Physic, Chemistry";
    public:
        CandidateA(string candidateNumber, string name, string address, int priority): Candidate(candidateNumber, name, address, priority){};
        string getSubjectA(){
            return subjectA;
        }
};
#endif