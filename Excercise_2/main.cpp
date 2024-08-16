#include <Manager.hpp>

void enterInformation(string &idDocument, string &publisherName, int &circulationNumber, Manager &manager){
    do{
        cout << "Enter ID of document: \n";
        getline(cin,idDocument);
        if(!manager.checkIdNumber(idDocument)){
            cout << "This ID is existed, enter another ID!\n";
        }
    }while(!manager.checkIdNumber(idDocument));
    cout << "Enter name of publisher: \n";
    getline(cin,publisherName);
    cout << "Enter circulation number: \n";
    cin >>circulationNumber;
    cin.ignore();
}

int main(){
    Manager manager;
    int select;
    do{
        //int a;
        cout <<"================================================\n";
        cout <<"Enter 1: Add new document!\n\n";
        cout <<"Enter 2: Delete document by ID\n\n";
        cout << "Enter 3: Show information\n\n";
        cout << "Enter 4: Search officer by type!\n\n";
        cout << "Enter 5: Exit!\n\n";
        cout <<"================================================\n";
        cin >> select;
        cin.ignore();
        cout << endl;
        switch(select){
            case 1: 
                {
                    string idDocument, publisherName;
                    int circulationNumber;
                    int typeOfDocument;
                    do{
                        cout <<"================================================\n";
                        cout <<"What type of this document?\n";
                        cout <<"Enter 1: Book!\n";
                        cout <<"Enter 2: Magazine!\n";
                        cout <<"Enter 3: Newspaper!\n";
                        cout <<"================================================\n";
                        cin>>typeOfDocument;
                        cin.ignore();
                        cout << endl;
                        switch(typeOfDocument){
                            case 1:
                                {
                                    string authorName;
                                    int numberOfPage;
                                    enterInformation(idDocument, publisherName, circulationNumber,manager);
                                    cout << "Enter name of author: \n";
                                    getline(cin, authorName);
                                    cout << "Enter number of page: \n";
                                    cin>>numberOfPage;
                                    cin.ignore();
                                    //Document* ptr = new Book(idDocument, publisherName, circulationNumber, authorName, numberOfPage);
                                    manager.addDocument(new Book(idDocument, publisherName, circulationNumber, authorName, numberOfPage));
                                    break;
                                }
                            case 2:
                                {
                                    string issueNumber;
                                    string issueMonth;
                                    enterInformation(idDocument, publisherName, circulationNumber,manager);
                                    cout << "Enter issue number: \n";
                                    getline(cin, issueNumber);
                                    cout << "Enter issue month: \n";
                                    getline(cin,issueMonth);
                                    //Document* ptr = new Magazine(idDocument, publisherName, circulationNumber, issueNumber, issueMonth);
                                    manager.addDocument(new Magazine(idDocument, publisherName, circulationNumber, issueNumber, issueMonth));
                                    break;
                                }
                            case 3:
                                {
                                    string issueDay;
                                    enterInformation(idDocument, publisherName, circulationNumber,manager);
                                    cout << "Enter issue day: \n";
                                    getline(cin,issueDay);
                                    //Document* ptr = new Newspaper(idDocument, publisherName, circulationNumber, issueDay);
                                    manager.addDocument(new Newspaper(idDocument, publisherName, circulationNumber, issueDay));
                                    break;                                
                                }
                            default:
                                {
                                    cout << "Error value, enter number from 1 to 3!\n";
                                }
                        }
                    } while(typeOfDocument<1||typeOfDocument>3);
                    break;
                }
            case 2:
                {
                    string id;
                    cout << "Endter ID of document you want to delete \n";
                    getline(cin,id);
                    manager.deleteDocumentByID(id);
                    break;
                }
            case 3:
                {
                    manager.displayAllDocument();
                    break;
                }
            case 4:
                {
                    int type;
                    do{
                        cout <<"================================================\n";
                        cout <<"What type of document does you want to search?\n";
                        cout <<"Enter 1: Book!\n";
                        cout <<"Enter 2: Magazine!\n";
                        cout <<"Enter 3: Newspaper!\n";
                        cout <<"================================================\n";
                        cin >> type;
                        cin.ignore();
                        if(type >3||type <1) cout << "Invalid value, enter a number from 1 to 3\n";
                    } while ((type <1||type>3));
                    manager.searchByType(type);
                    break;
                        
                }
            case 5:
                {
                    manager.Exit();
                    break;
                }
            default:
                {
                    cout << "Error value, enter number from 1 to 5!\n";
                }
        }
    }while (select !=5);
}