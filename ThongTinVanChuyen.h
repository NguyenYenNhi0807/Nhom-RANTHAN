
#pragma once
#include<iostream>
#include<string>
using namespace std;

class ThongTinVanChuyen {
private:
    string m_sPhuongThuc;
    double m_dTienVanChuyen;

public:
    // Constructor
    ThongTinVanChuyen();
    ThongTinVanChuyen(const string& phuongThuc,
                      double tienVanChuyen);
    ThongTinVanChuyen(const ThongTinVanChuyen& ttv);
    ThongTinVanChuyen& operator=(const ThongTinVanChuyen& ttv);

    // Destructor
    ~ThongTinVanChuyen();

    // Getter
    string getPhuongThuc() const;
    double getTienVanChuyen() const;

    // Setter
    void setPhuongThuc(const string& phuongThuc);
    void setTienVanChuyen(double tienVanChuyen);

    // Nhap va xuat
    friend istream& operator>>(istream& is, ThongTinVanChuyen& ttv);
    friend ostream& operator<<(ostream& os, const ThongTinVanChuyen& ttv);
    void nhapThongTin();
    void xuatThongTin() const;

    // Tinh tien van chuyen
    double tinhTienVanChuyen() const;
};
