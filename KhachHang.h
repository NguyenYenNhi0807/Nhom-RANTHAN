#pragma once
#include<iostream>
#include<string>
using namespace std;

class KhachHang {
private:
    string m_sMaKH;
    string m_sTenKhachHang;
    string m_sDiaChi;
    double m_dTongChiTieu;

public:
    // Constructor
    KhachHang();
    KhachHang(string sMaKH, string sTenKhachHang,
              string sDiaChi, double dTongChiTieu);
    KhachHang(const KhachHang& khachhang);
    virtual ~KhachHang();
    friend istream& operator>>(istream& is, KhachHang& kh);
    friend ostream& operator<<(ostream& os, const KhachHang& kh);
    void nhapKhachHang();
    void xuatKhachHang() const;

    // Getter
    string getMaKH() const;
    string getTenKhachHang() const;
    string getDiaChi() const;
    double getTongChiTieu() const;

    // Setter
    void setMaKH(string sMaKH);
    void setTenKhachHang(string sTenKhachHang);
    void setDiaChi(string sDiaChi);
    void setTongChiTieu(double dTongChiTieu);

    // Da hinh
    virtual string xepHang() const = 0;
    virtual double tinhUuDai() const = 0;

    // Tinh so tien uu dai
    double tinhTienUuDai(double tienHang) const;

};


//_____________CLASS KHACHHANGDONG___________________
class KhachHangDong : public KhachHang {
public:
    KhachHangDong();
    KhachHangDong(string sMaKH, string sTenKhachHang,
              string sDiaChi, double dTongChiTieu);
    KhachHangDong(const KhachHangDong& khachhang);

    string xepHang() const override;
    double tinhUuDai() const override;
};


//_____________CLASS KHACHHANGBAC___________________
class KhachHangBac : public KhachHang {
public:
    KhachHangBac();
    KhachHangBac(string sMaKH, string sTenKhachHang,
             string sDiaChi, double dTongChiTieu);
    KhachHangBac(const KhachHangBac& khachhang);

    string xepHang() const override;
    double tinhUuDai() const override;
};


//_____________CLASS KHACHHANGVANG___________________
class KhachHangVang : public KhachHang {
public:
    KhachHangVang();
    KhachHangVang(string sMaKH, string sTenKhachHang,
              string sDiaChi, double dTongChiTieu);
    KhachHangVang(const KhachHangVang& khachhang);

    string xepHang() const override;
    double tinhUuDai() const override;
};


//_____________CLASS KHACHHANGKIMCUONG___________________
class KhachHangKimCuong : public KhachHang {
public:
    KhachHangKimCuong();
    KhachHangKimCuong(const KhachHangKimCuong& khachhang);
    KhachHangKimCuong(string sMaKH, string sTenKhachHang,
                  string sDiaChi, double dTongChiTieu);

    string xepHang() const override;
    double tinhUuDai() const override;
};
