#include "./include/Khoa.hpp"

int main(){
    Khoa khoa;
    int luaChon;
    do{
        cout<<"Ban muon thuc hien chuc nang nao?\n";
        cout<<"Nhap 1: Them sinh vien moi\n";
        cout<<"Nhap 2: Tong so sinh vien chinh quy cua khoa\n";
        cout<<"Nhap 3: Sinh vien co diem dau vao cao nhat\n";
        cout<<"Nhap 4: Sinh vien tai chuc theo noi lien ket\n";
        cout<<"Nhap 5: Sinh vien co diem ki hoc gan nhat lon hon 8\n";
        cout<<"Nhap 6: Sinh vien co diem trung binh cao nhat\n";
        cout<<"Nhap 7: So luong sinh vien theo nam hoc\n";
        cout<<"Nhap 8: Thoat chuong trinh\n";
        cin>>luaChon;
        cin.ignore();
        switch(luaChon){
            case 1:
                {
                    int loaiSV;
                    do{
                        string maSV;
                        string hoTen;
                        string ngaySinh;
                        int namVaoHoc;
                        float diemDauVao;  
                        vector<KetQuaHocTap*> ds;                      
                        cout<<"Loai sinh vien:\n";
                        cout<<"Nhap 1: Chinh quy\n";
                        cout<<"Nhap 2: Tai chuc\n";
                        cin >> loaiSV;
                        cin.ignore();
                        switch(loaiSV){
                            case 1:
                                {
                                    khoa.themThongTinChung(maSV, hoTen, ngaySinh,namVaoHoc,diemDauVao);
                                    khoa.nhapDiemTBTheoKy(ds);
                                    khoa.themSV(new ChinhQuy(maSV, hoTen,ngaySinh,namVaoHoc,diemDauVao,ds));
                                    break;
                                }
                            case 2:
                                {   
                                    string noiLK;
                                    khoa.themThongTinChung(maSV, hoTen, ngaySinh,namVaoHoc,diemDauVao);
                                    cout<<"Nhap noi lien ket dao tao: \n";
                                    getline(cin, noiLK);
                                    khoa.nhapDiemTBTheoKy(ds);
                                    khoa.themSV(new TaiChuc(maSV, hoTen,ngaySinh,namVaoHoc,diemDauVao,ds, noiLK));
                                    break;
                                }
                            default:
                                cout<<"Loi, nhap lai\n";
                        }
                    }while(loaiSV>2||loaiSV<1);
                }
            case 2:
                {
                    cout<<"Tong so sinh vien chinh quy: "<<khoa.tongSVCQ()<<endl<<endl;
                    break;
                }
            case 3:
                {
                    khoa.svDauVaoCaoNhat();
                    cout<<endl;
                    break;
                }
            case 4:
                {
                    khoa.svTCTheoNoiDaoTao();
                    cout<<endl;
                    break;
                }
            case 5:
                {
                    khoa.svDiemTBHon8();
                    cout<<endl;
                    break;
                }
            case 6:
                {
                    khoa.svDiemTBCaoNhat();
                    cout<<endl;
                    break;
                }
            case 7:
                {
                    khoa.svTheoNamHoc();
                    cout<<endl;
                    break;
                }
            case 8:
                {
                    cout<<"Thoat chuong trinh!!!!\n\n";
                    break;
                }
            default:
                cout<<"Nhap lai\n";
        }
    }while(luaChon!=8);
}