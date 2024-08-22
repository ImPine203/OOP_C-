#pragma once 
#include<iostream>
using namespace std;

class KetQuaHocTap{
    private:
        string tenHocKy;
        float diemTB;
    public:
        KetQuaHocTap(){};
        KetQuaHocTap(string tenHocKy, float diemTB){
            this->tenHocKy = tenHocKy;
            this->diemTB = diemTB;
        }
        float getDiemTB(){
            return diemTB;
        }
        string getKyHoc(){
            return tenHocKy;
        }
};