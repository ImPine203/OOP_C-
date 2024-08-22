#ifndef TAICHUC_HPP
#define TAICHUC_HPP
#include "SinhVien.hpp"
class TaiChuc: public SinhVien{
    private:
        string noiLienKet;
    public:
        TaiChuc();
        TaiChuc(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap*> dsKQHT,string noiLienKet): SinhVien(maSV,hoTen,ngaySinh,namVaoHoc,diemDauVao,dsKQHT){
            this->noiLienKet = noiLienKet;
        }
        void hienThi(){
            SinhVien::hienThi();
            cout<<"Noi lien ket dao tao: "<<noiLienKet<<endl;
        }
};
#endif