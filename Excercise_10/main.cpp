#include <iostream>
using namespace std;

class Document{
    private:
        string doc;
    public:
        Document(){};
        Document(string doc){
            this->doc = doc;
        }
        int getAmountCharactor(){
            return this->doc.length();
        }
        int countA(){
            int count = 0;
            for(int i =0;i<this->doc.length();i++){
                if(doc[i]=='a'||doc[i]=='A'){
                    count++;
                }
            }
            return count;
        }
        string normalizaDoc(){
            string result;
            bool isSpace = false;
            int count = 0;
            if(doc[0]!=' ') result+= doc[0];
            for(int i = 1; i< this->doc.length()-2; i++){
                if(doc[i]!=' '){
                    result+=doc[i];
                    count = 0;
                }
                else {
                    count ++;
                    if(count <2) result+= doc[i];
                }
            }
            if(doc[doc.length()-2]!= ' ') result+= doc[doc.length()-2];
            return result;
        }
};

int main(){
    Document document(" This is a  test  document ");
    cout<< document.normalizaDoc()<<endl;
}