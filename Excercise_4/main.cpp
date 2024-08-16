#include "./include/District.hpp"

int main(){
    int numberOfHousehold;
    cout<< "Enter number of household in this district: \n";
    cin>>numberOfHousehold;
    District dis(numberOfHousehold);
    dis.addHousehould(numberOfHousehold);
    
}