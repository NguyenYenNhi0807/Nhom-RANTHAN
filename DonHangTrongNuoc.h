#pragma once
#include <iostream>
#include <string>
#include "DonHang.h"

using namespace std;

class DonHangTrongNuoc : public DonHang {
public:
    // Constructor
    DonHangTrongNuoc();
    DonHangTrongNuoc(Code sMaDonHang, Date sNgayDatHang);
    DonHangTrongNuoc(const DonHangTrongNuoc& donhangtrongnuoc);

    // Destructor
    ~DonHangTrongNuoc();

    // Nhap xuat
    friend istream& operator>>(istream& in, DonHangTrongNuoc& donhangtrongnuoc);
    friend ostream& operator<<(ostream& out, const DonHangTrongNuoc& donhangtrongnuoc);
    void nhapDonHangTrongNuoc();
    void xuatDonHangTrongNuoc() const;

    // Da hinh
    void nhapDonHang(string scope) override;
    void xuatDonHang() const override;
    double TinhTongTien() const override;
    void InThongTin() const override;
};
