#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <vector>
#include "Book.hpp"
#include "Newspaper.hpp"
#include "Magazine.hpp"

class Manager {
    private:
        vector<Document*> manager;
    public:
        void addDocument(Document *document){
            manager.push_back(document);
        }
        void deleteDocumentByID(string id){
            auto it = this->manager.begin();
            while (it != this->manager.end()) {
                if ((*it)->getIdDocument() == id) {
                    delete *it;
                    it = this->manager.erase(it);
                    cout << "Delete document with ID " << id << " successful\n\n";
                    return;
                } else {
                    ++it;
                }
            }
            // Can't find this id to delete
            cout << "This ID is incorrect\n\n";
        }
        void generalInformation(Document * document){
            cout << "ID of this document: "<<document->getIdDocument()<<endl;
            cout << "Publisher name of this document: "<<document->getPublisherName()<<endl;
            cout << "Circulation number of this document: "<<document->getCirculationNumber()<<endl;            
        }
        void displayAllDocument(){
            if(this->manager.empty() == 1) {
                cout << "Don't have document\n";
                return; 
            }
            int count =1;
            for (auto i: this->manager){
                cout << i<< endl;
                if(i==nullptr) continue;
                cout << "Document number "<<count++<<endl;
                // General information
                generalInformation(i);
                // Specific information
                // Book
                if(i->getAuthorName()!="\0"){
                    cout<<"Author of this document: "<<i->getAuthorName()<<endl;
                    cout<<"Number of pages of this document: "<<i->getNumberOfPage()<<endl;
                    cout << endl;
                }
                // Magazine
                else if(i->getIssueMonth()!="\0"){
                    cout<<"Issue month of this document: "<<i->getIssueMonth()<<endl;
                    cout<<"Issue number of this document: "<<i->getIssueNumber()<<endl;
                    cout << endl;
                }
                // Newspaper
                else{
                    cout<<"Issue day of this document: "<<i->getIssueDay()<<endl;
                    cout << endl;
                }
                
            }
        }
        void searchByType(int type){
            int count =1;
            for (auto i: this->manager){
                if(type == 1){
                    if(i->getAuthorName()!="\0"){
                        cout << "Book number "<<count++<<endl;
                        generalInformation(i);
                        cout<<"Author of this document: "<<i->getAuthorName()<<endl;
                        cout<<"Number of pages of this document: "<<i->getNumberOfPage()<<endl;
                        cout << endl;
                    }
                }
                else if (type ==2){
                    if (i->getIssueMonth()!="\0"){
                        cout << "Magazine number "<<count++<<endl;
                        generalInformation(i);
                        cout<<"Issue month of this document: "<<i->getIssueMonth()<<endl;
                        cout<<"Issue number of this document: "<<i->getIssueNumber()<<endl;
                        cout << endl;                        
                    }
                }
                else{
                    if (i->getIssueDay()!="\0"){
                        cout << "Newspaper number "<<count++<<endl;
                        generalInformation(i);
                        cout<<"Issue day of this document: "<<i->getIssueDay()<<endl;
                        cout << endl;
                    }
                }
            }
        }
        void Exit(){
            cout <<"=============Exit===============\n";
        }
        bool checkIdNumber(string id){
            for (auto i: this->manager){
                if (i->getIdDocument() == id) return false;
            }
            return true;
        }
        ~Manager(){
            auto it = this->manager.begin();
            while(it!= this->manager.end()){
                delete *it;
                it++;
            }
        }
};

#endif