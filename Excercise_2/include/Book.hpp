#ifndef BOOK_HPP
#define BOOK_HPP

#include "Document.hpp"

class Book: public Document{
    private:
        string authorName;
        int numberOfPage;
    public:
        Book(string idDocument, string publisherName, int circulationNumber, string authorName, int numberOfPage):Document(idDocument, publisherName, circulationNumber){
            this ->authorName= authorName;
            this ->numberOfPage = numberOfPage;
        }
        virtual string getAuthorName() const {
            return authorName;
        }
        void setAuthorName(string authorName){
            this->authorName = authorName;
        }
        virtual int getNumberOfPage(){
            return numberOfPage;
        }
        void setNumberOfPage(int numberOfPage){
            this->numberOfPage = numberOfPage;
        }
};

#endif