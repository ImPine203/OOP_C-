#ifndef CANDIDATEC_HPP
#define CANDIDATEC_HPP
#include "Candidate.hpp"

class CandidateC: public Candidate{
    private:
        string subjectC = "Literature, History, Geography";
    public:
        CandidateC(string candidateNumber, string name, string address, int priority): Candidate(candidateNumber, name, address, priority){};
        string getSubjectC(){
            return subjectC;
        }
};
#endif