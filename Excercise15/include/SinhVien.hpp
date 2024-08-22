#ifndef SINHVIEN_HPP
#define SINHVIEN_HPP
#include"KetQuaHocTap.hpp"
#include<vector>
class SinhVien: public KetQuaHocTap{
    private:
        string maSV;
        string hoTen;
        string ngaySinh;
        int namVaoHoc;
        float diemDauVao;
        vector<KetQuaHocTap*> dsKQHT;
    public:
        SinhVien();
        SinhVien(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao,vector<KetQuaHocTap*> dsKQHT){
            this->maSV = maSV;
            this->hoTen = hoTen;
            this->ngaySinh = ngaySinh;
            this->namVaoHoc = namVaoHoc;
            this->diemDauVao = diemDauVao;
            this->dsKQHT = dsKQHT;
        }
        int getNamVaoHoc(){
            return namVaoHoc;
        }
        void setKetQuaHocTap(KetQuaHocTap* kq){
            this->dsKQHT.push_back(kq);
        }
        virtual bool isChinhQuy(){
            return false;
        }
        float getDiemDauVao(){
            return diemDauVao;
        }
        string getHoVaTen(){
            return hoTen;
        }
        vector<KetQuaHocTap*> getdsKQHT(){
            return dsKQHT;
        }
        virtual string getNoiLienKet(){
            return "\0";
        }
        virtual void hienThi(){
            cout<<"Ma sinh vien: "<<maSV<<endl;
            cout<<"Ho va ten: "<<hoTen<<endl;
            cout<<"Ngay sinh: "<<ngaySinh<<endl;
            cout<<"Nam vao hoc: "<<namVaoHoc<<endl;
            cout<<"Diem dau vao: "<<diemDauVao<<endl;
            auto it = dsKQHT.begin();
            cout<<"Diem cac ki hoc: \n\n";
            while(it!=dsKQHT.end()){
                cout<<"Hoc ki: "<<(*it)->getKyHoc()<<endl;
                cout<<"Diem trung binh cac mon: "<<(*it)->getDiemTB()<<endl;
                it++;
            }
            cout<<endl;
        }
        //6
        float getDiemTBTheoKy(string kyHoc){
            auto it = dsKQHT.begin();
            while(it!= dsKQHT.end()){
                if((*it)->getKyHoc()==kyHoc) return (*it)->getDiemTB();
                it++;
            }
            return 0;

        }

};
#endif