#pragma once
#include <iostream>
using namespace std;
class Certificate{
    private:
        int certificateID;
        string certificateName;
        string certificateRank;
        string certificateDate;
    public:
        Certificate(int certificateID = 0,string certificateName="\0", string certificateRank="\0", string certificateDate = "\0"){
            this->certificateID = certificateID;
            this->certificateName = certificateName;
            this->certificateRank = certificateRank;
            this->certificateDate = certificateDate;
        }
        int getCertificateID(){
            return certificateID;
        }
        string getCertificateName(){
            return certificateName;
        }
        string getCertificateRank(){
            return certificateRank;
        }
        string getCertificateDate(){
            return certificateDate;
        }
        void setCertificateID(int certificateID){
            this->certificateID = certificateID;
        }
        void setCertificateName(string certificateName){
            this->certificateName = certificateName;
        }
        void setCertificateRank(string certificateRank){
            this->certificateRank= certificateRank;
        }
        void setCertificateDate(string certificateDate){
            this->certificateDate= certificateDate;
        }
};

