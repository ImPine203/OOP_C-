#ifndef CHINHQUY_HPP
#define CHINHQUY_HPP
#include "SinhVien.hpp"
class ChinhQuy: public SinhVien{
    public:
        ChinhQuy();
        ChinhQuy(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap*> dsKQHT): SinhVien(maSV,hoTen,ngaySinh,namVaoHoc,diemDauVao, dsKQHT){};
        bool isChinhQuy(){
            return true;
        }
};
#endif