#include <Manager.hpp>

void enterInformation(string &idDocument, string &publisherName, int &circulationNumber){
    cout << "Enter ID of document: \n";
    getline(cin,idDocument);
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
        cout <<"Enter 1: Add new officer!\n";
        cout << "Enter 2: Show information\n";
        cout << "Enter 3: Search officer by name!\n";
        cout << "Enter 4: Exit!\n";
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
                                    enterInformation(idDocument, publisherName, circulationNumber);
                                    cout << "Enter name of author: \n";
                                    getline(cin, authorName);
                                    cout << "Enter number of page: \n";
                                    cin>>numberOfPage;
                                    cin.ignore();
                                    Document* ptr = new Book(idDocument, publisherName, circulationNumber, authorName, numberOfPage);
                                    manager.addDocument(ptr);
                                    break;
                                }
                            case 2:
                                {
                                    string issueNumber;
                                    string issueMonth;
                                    enterInformation(idDocument, publisherName, circulationNumber);
                                    cout << "Enter issue number: \n";
                                    getline(cin, issueNumber);
                                    cout << "Enter issue month: \n";
                                    getline(cin,issueMonth);
                                    Document* ptr = new Magazine(idDocument, publisherName, circulationNumber, issueNumber, issueMonth);
                                    manager.addDocument(ptr);
                                    break;
                                }
                            case 3:
                                {
                                    string issueDay;
                                    enterInformation(idDocument, publisherName, circulationNumber);
                                    cout << "Enter issue day: \n";
                                    getline(cin,issueDay);
                                    Document* ptr = new Newspaper(idDocument, publisherName, circulationNumber, issueDay);
                                    manager.addDocument(ptr);
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
                    manager.displayAllDocument();
                }
            case 3:
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
                    } while ((type <1||type>3));
                    manager.searchByType(type);
                    break;
                        
                }
            case 4:
                {
                    manager.Exit();
                }
            default:
                {
                    cout << "Error value, enter number from 1 to 4!\n";
                }
        }
    }while (select !=4);
}