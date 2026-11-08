#pragma once

#include <iostream>
#include <string>

using namespace std;

class VoucherVanChuyen {
private:
    string m_sMaVoucher;
    string m_sLoaiVoucher;
    double m_dGiaTriGiam;

public:
    // Constructors
    VoucherVanChuyen();
    VoucherVanChuyen(const string& ma, const string& loai,
                     double giaTri);
    VoucherVanChuyen(const VoucherVanChuyen& voucher);

    // Destructor
    ~VoucherVanChuyen();

    // Getters
    string getMaVoucher() const;
    string getLoaiVoucher() const;
    double getGiaTriGiam() const;

    // Setters
    void setMaVoucher(const string& ma);
    void setLoaiVoucher(const string& loai);
    void setGiaTriGiam(double giaTri);

    // Nhap va xuat
    void nhapVoucher();
    void xuatVoucher() const;
    friend istream& operator>>(istream& is, VoucherVanChuyen& vc);
    friend ostream& operator<<(ostream& os, const VoucherVanChuyen& vc);

    // Tinh tien
    double tinhTienGiam(double tienVanChuyen) const;
};
