#ifndef NEWSPAPER_HPP
#define NEWSPAPER_HPP

#include "Document.hpp"

class Newspaper: public Document{
    private:
        string issueDay;
    public:
        Newspaper(string idDocument, string publisherName, int circulationNumber, string issueDay):Document(idDocument, publisherName, circulationNumber){
            this->issueDay = issueDay;
        }
        string getIssueDay() const{
            return issueDay;
        }
        void setIssueDay(string issueDay){
            this->issueDay = issueDay;
        }

};

#endif