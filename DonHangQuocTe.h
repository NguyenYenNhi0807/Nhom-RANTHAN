
#pragma once
#include<iostream>
#include<string>
#include "DonHang.h"
using namespace std;

class DonHangQuocTe : public DonHang {
private:
    double m_dPhiHaiQuan;

public:
    // Constructor
    DonHangQuocTe();
    DonHangQuocTe(double dPhiHaiQuan);
    DonHangQuocTe(Code sMaDonHang, Date sNgayDatHang, double dPhiHaiQuan);
    DonHangQuocTe(const DonHangQuocTe& donhangquocte);

    // Destructor
    ~DonHangQuocTe();

    // Getter
    double getPhiHaiQuan() const;

    // Setter
    void setPhiHaiQuan(double dPhiHaiQuan);

    // Nhap xuat
    friend istream& operator>>(istream& in, DonHangQuocTe& donhangquocte);
    friend ostream& operator<<(ostream& out, const DonHangQuocTe& donhangquocte);
    void nhapDonHangQuocTe();
    void xuatDonHangQuocTe() const;

    // Ham da hinh
    void nhapDonHang(string scope) override;
    void xuatDonHang() const override;
    double TinhTongTien() const override;
    void InThongTin() const override;
};
