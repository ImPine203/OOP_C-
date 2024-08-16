#ifndef CANDIDATEB_HPP
#define CANDIDATEB_HPP
#include "Candidate.hpp"

class CandidateB: public Candidate{
    private:
        string subjectB = "Math, Chemistry, Biology";
    public:
        CandidateB(string candidateNumber, string name, string address, int priority): Candidate(candidateNumber, name, address, priority){};
        string getSubjectB(){
            return subjectB;
        }
};
#endif