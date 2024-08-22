#ifndef KHOA_HPP
#define KHOA_HPP
#include "ChinhQuy.hpp"
#include "TaiChuc.hpp"
#include "../../Excercise13/include/HandleException.hpp"
#include <algorithm>
#include <vector>
class Khoa{
    private:
        vector<SinhVien*> khoa;
    public:
        void themThongTinChung(string &maSV, string &hoTen, string &ngaySinh, int &namVaoHoc, float &diemDauVao){
            bool check;
            cout<<"Nhap ma sinh vien: \n";
            getline(cin,maSV);
            do{
                try {
                    cout<<"Nhap ho va ten: \n";
                    getline(cin, hoTen);	
                    if(!checkName(hoTen)){
                        throw InvalidFullNameException();
                    }
                    check = true;
                }
                catch(InvalidFullNameException &invalidFullName){
                    cout<<invalidFullName.what()<<endl;
                }
            }while(!check);
            check = false;
            do{
                try {
                    cout<<"Nhap ngay sinh: \n";
                    getline(cin, ngaySinh);	
                    if(!checkBirthDay(ngaySinh)){
                        throw InvalidBirthdayException();
                    }
                    check = true;
                    cout<<endl;
                }
                catch(InvalidBirthdayException &invalidBirthday){
                    cout<<invalidBirthday.what()<<endl;
                }
            }while(!check);
            cout<<"Nhap nam vao hoc: \n";
            cin>>namVaoHoc;
            cin.ignore();
            cout<<"Nhap diem dau vao: \n";
            cin >> diemDauVao;
            cin.ignore();
        }
        void nhapDiemTBTheoKy(vector<KetQuaHocTap*> &kq){
            char tiepTuc;
            do{
                string tenHocKy;
                float diemTB;
                cout<<"Nhap hoc ki: \n";
                getline(cin,tenHocKy);
                cout<<"Nhap diem trung binh: \n";
                cin>>diemTB;
                kq.push_back(new KetQuaHocTap(tenHocKy, diemTB));
                cout<<"Nhap y de tiep tuc nhap diem: \n";
                cin>>tiepTuc;
                cin.ignore();
            }while(tiepTuc=='y');
        }
        void themSV(SinhVien* sv){
            khoa.push_back(sv);
        }
        //7
        int tongSVCQ(){
            int count = 0;
            auto it= this->khoa.begin();
            while(it!= this->khoa.end()){
                if((*it)->isChinhQuy()){
                    count ++;
                }
                it++;
            }
            return count;
        }
        //8
        void svDauVaoCaoNhat(){
            float max =0;
            auto it= this->khoa.begin();
            auto tmp = this->khoa.begin();
            while(it!= this->khoa.end()){
                if((*it)->getDiemDauVao()>max){
                    max = (*it)->getDiemDauVao();
                    tmp = it;
                }
                it++;
            }
            cout<<"Sinh vien co diem dau vao cao nhat la: \n\n";
            (*tmp)->hienThi();
        }
        //9
        void svTCTheoNoiDaoTao(){
            string noiLK;
            cout<<"Nhap noi lien ket dao tao: \n";
            getline(cin,noiLK);
            int count = 1;
            auto it = this->khoa.begin();
            while(it!= this->khoa.end()){
                if ((*it)->getNoiLienKet()==noiLK){
                    cout<<"Sinh vien tai chuc thu "<<count ++<<endl;
                    (*it)->hienThi();
                    cout << endl;
                }
                it++;
            }
            if(it==khoa.end()){
                cout<<"Khong co sinh vien nao\n";
            }
        }
        //10
        void svDiemTBHon8(){
            int count = 1;
            auto it = this->khoa.begin();
            while(it!= this->khoa.end()){
                if ((*it)->getdsKQHT().back()->getDiemTB()>=8){
                    cout<<"Sinh vien thu "<<count ++<<endl;
                    (*it)->hienThi();
                    cout << endl;
                }
                it++;
            }
            if(it==khoa.end()){
                cout<<"Khong co sinh vien nao\n";
            }
        }
        //11
        void svDiemTBCaoNhat(){
            int max;
            auto it = khoa.begin();
            auto tmp = it;
            while(it!= khoa.end()){
                auto ds = (*it)->getdsKQHT();
                auto it1=ds.begin();
                while(it1!= ds.end()){
                    if((*it1)->getDiemTB()>max){
                        max = (*it1)->getDiemTB();
                        tmp = it;
                    }
                    it1++;
                }
                it++;
            }
            (*tmp)->hienThi();
        }
        //12
        void sapXep(){
            sort(khoa.begin(),khoa.end(),[](SinhVien* a, SinhVien* b){
                ChinhQuy* cqA = dynamic_cast<ChinhQuy*>(a);
                ChinhQuy* cqB = dynamic_cast<ChinhQuy*>(b);
                // a la chinh quy
                if(cqA) return true;
                // b la chinh quy
                if(cqB) return false;
                //cung la chinh quy hoac cung la tai chuc
                if(cqA->getNamVaoHoc()!=cqB->getNamVaoHoc()) return cqA->getNamVaoHoc()>cqB->getNamVaoHoc();
                else{
                    return cqA->getHoVaTen()>cqB->getHoVaTen();
                }
            });            
        }
        //13
        void svTheoNamHoc(){
            int namVaoHoc;
            cout<<"Nhap nam hoc:\n";
            cin>>namVaoHoc;
            cin.ignore();
            auto it = this->khoa.begin();
            int count = 0;
            while(it!=this->khoa.end()){
                if((*it)->getNamVaoHoc()==namVaoHoc){
                    count++;
                }
                it++;
            }
            cout<<namVaoHoc<<": "<<count<<endl;
        }        
};

#endif