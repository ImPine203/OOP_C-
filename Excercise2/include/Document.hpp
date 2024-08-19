#pragma once

#include<iostream>

using namespace std;

class Document{
    protected:
        string idDocument;
        string publisherName;
        int circulationNumber;
    public:
        Document(string idDocument, string publisherName, int circulationNumber){
            this->idDocument = idDocument;
            this->publisherName = publisherName;
            this->circulationNumber = circulationNumber;
        }
        void setIdDocument(string idDocument){
            this->idDocument = idDocument;
        }
        string getIdDocument(){
            return idDocument;
        }
        void setPublisherName(string publisherName){
            this->publisherName = publisherName;
        }
        string getPublisherName(){
            return publisherName;
        }
        void setCirculationNumber(int circulationNumber){
            this->circulationNumber = circulationNumber;
        }
        int getCirculationNumber(){
            return circulationNumber;
        }
        // Function for Book
        virtual string getAuthorName() const {
            return "\0";
        }
        virtual int getNumberOfPage(){
            return -1;
        }
        // Function for Magazine
        virtual string getIssueNumber() const {
            return "\0";
        }
        virtual string getIssueMonth(){
            return "\0";
        }
        // Function for Newspaper
        virtual string getIssueDay(){
            return "\0";
        }

};