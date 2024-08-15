#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include "Document.hpp"

class Magazine: public Document{
    private:
        string issueNumber;
        string issueMonth;
    public:
        Magazine(string idDocument, string publisherName, int circulationNumber, string issueNumber, string issueMonth):Document(idDocument, publisherName, circulationNumber){
            this ->issueNumber= issueNumber;
            this ->issueMonth = issueMonth;
        }
        string getIssueNumber() const {
            return issueNumber;
        }
        void setIssueNumber(string issueNumber){
            this->issueNumber=issueNumber; 
        }
        string getIssueMonth(){
            return issueMonth;
        }
        void setIssueMonth(string issueMonth){
            this->issueNumber=issueMonth; 
        }
};

#endif