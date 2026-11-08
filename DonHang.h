#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Code.h"
#include "Date.h"
#include "HangHoa.h"
#include "ThongTinVanChuyen.h"

using namespace std;

class DonHang {
private:
    Code m_sMaDonHang;
    Date m_sNgayDatHang;
    vector<HangHoa*> m_dsHangHoa;
    ThongTinVanChuyen m_tThongTinVanChuyen;
    double m_dUuDaiKhachHang;
    double m_dGiamGiaVoucher;

public:
    // Constructor
    DonHang();
    DonHang(Code sMaDonHang, Date sNgayDatHang);
    DonHang(const DonHang& donhang);

    // Destructor
    virtual ~DonHang();

    // Getter
    Code getMaDonHang() const;
    Date getNgayDatHang() const;
    vector<HangHoa*> getDanhSachHangHoa() const;
    Date getNgayGiaoHangSomNhat() const;
    Date getNgayGiaoHangMuonNhat() const;
    double getUuDaiKhachHang() const;
    double getGiamGiaVoucher() const;
    ThongTinVanChuyen getThongTinVanChuyen() const;

    // Setter
    virtual void setMaDonHang(Code sMaDonHang);
    virtual void setNgayDatHang(Date sNgayDatHang);
    void setUuDaiKhachHang(double tien);
    void setGiamGiaVoucher(double tien);
    void setThongTinVanChuyen(const ThongTinVanChuyen& thongTinVanChuyen);
    
    // Nhap xuat
    friend istream& operator>>(istream& in, DonHang &donhang);
    friend ostream& operator<<(ostream& out, const DonHang& donhang);
    virtual void nhapDonHang(string scope) = 0;
    virtual void xuatDonHang() const = 0;
    
    // Quan ly hang hoa
    void themHangHoa(HangHoa* hangHoa);
    void xuatDanhSachHangHoa() const;

    // Tinh toan
    double tinhTongTienHang() const;
    double tinhTongPhuPhiHangHoa() const;
    double tinhTienHang() const;
    double tinhPhiVanChuyen() const;

    // Da hinh
    virtual double TinhTongTien() const = 0;
    virtual void InThongTin() const = 0;
};




