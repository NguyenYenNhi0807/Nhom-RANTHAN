#ifndef THANHTOAN_H
#define THANHTOAN_H

#include <iostream>
using namespace std;

class ThanhToan {
private:
    double m_dTienHang;
    double m_dPhuPhiHang;
    double m_dPhiVanChuyen;
    double m_dPhiHaiQuan;
    double m_dUuDaiKhachHang;
    double m_dGiamGiaVoucher;

public:
    // Constructor
    ThanhToan();

    ThanhToan(double dTienHang,
              double dPhuPhiHang,
              double dPhiVanChuyen,
              double dPhiHaiQuan,
              double dUuDaiKhachHang,
              double dGiamGiaVoucher);

    ThanhToan(const ThanhToan& thanhtoan);

    // Destructor
    ~ThanhToan();

    // Getter
    double getTienHang() const;
    double getPhuPhiHang() const;
    double getPhiVanChuyen() const;
    double getPhiHaiQuan() const;
    double getUuDaiKhachHang() const;
    double getGiamGiaVoucher() const;

    // Setter
    void setTienHang(double dTienHang);
    void setPhuPhiHang(double dPhuPhiHang);
    void setPhiVanChuyen(double dPhiVanChuyen);
    void setPhiHaiQuan(double dPhiHaiQuan);
    void setUuDaiKhachHang(double dUuDaiKhachHang);
    void setGiamGiaVoucher(double dGiamGiaVoucher);

    // Ham tinh tien
    double tinhTienHangSauUuDai() const;
    double tinhPhiVanChuyenSauVoucher() const;
    double tinhTongTienTrongNuoc() const;
    double tinhTongTienQuocTe() const;

    // Nhap xuat
    friend istream& operator>>(istream& is, ThanhToan& tt);
    friend ostream& operator<<(ostream& os, const ThanhToan& tt);

    void nhapThanhToan();

    // Xuat chi tiet thanh toan
    void xuatThanhToan(bool laDonHangQuocTe) const;
    void xuatChiTietThanhToan(bool laDonHangQuocTe) const;
};

#endif
