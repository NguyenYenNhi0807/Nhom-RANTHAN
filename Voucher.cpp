#include "Voucher.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "GiaoDien.h"

using namespace std;

// Constructor
VoucherVanChuyen::VoucherVanChuyen() {
    m_sMaVoucher = "";
    m_sLoaiVoucher = "GIAM_TIEN";
    m_dGiaTriGiam = 0;
}

VoucherVanChuyen::VoucherVanChuyen(
    const string& maVoucher,
    const string& loaiVoucher,
    double giaTriGiam) {

    m_sMaVoucher = maVoucher;
    m_sLoaiVoucher = "GIAM_TIEN";
    m_dGiaTriGiam = 0;

    setLoaiVoucher(loaiVoucher);
    setGiaTriGiam(giaTriGiam);
}

VoucherVanChuyen::VoucherVanChuyen(
    const VoucherVanChuyen& voucher
) {
    m_sMaVoucher = voucher.m_sMaVoucher;
    m_sLoaiVoucher = voucher.m_sLoaiVoucher;
    m_dGiaTriGiam = voucher.m_dGiaTriGiam;
}

// Destructor
VoucherVanChuyen::~VoucherVanChuyen() {
}

// Getters
string VoucherVanChuyen::getMaVoucher() const {
    return m_sMaVoucher;
}

string VoucherVanChuyen::getLoaiVoucher() const {
    return m_sLoaiVoucher;
}

double VoucherVanChuyen::getGiaTriGiam() const {
    return m_dGiaTriGiam;
}

// Setters
void VoucherVanChuyen::setMaVoucher(const string& maVoucher) {
    m_sMaVoucher = maVoucher;
}

void VoucherVanChuyen::setLoaiVoucher(const string& loaiVoucher) {
    if (loaiVoucher == "GIAM_TIEN" ||
        loaiVoucher == "MIEN_PHI") {
        m_sLoaiVoucher = loaiVoucher;
    }
}

void VoucherVanChuyen::setGiaTriGiam(double giaTriGiam) {
    if (giaTriGiam >= 0) {
        m_dGiaTriGiam = giaTriGiam;
    }
}

// Nhap va xuat
istream& operator>>(istream& is, VoucherVanChuyen& vc) {
    cout << Mau::TIM << Mau::DAM
         << "Ma voucher: " << Mau::RESET;
    getline(is >> ws, vc.m_sMaVoucher);

    vector<string> tieuDeLoaiVoucher = {
        "PHIM", "LOAI VOUCHER"
    };

    vector<vector<string>> dsLoaiVoucher = {
        {"[1]", "Mien phi van chuyen"},
        {"[2]", "Giam mot so tien co dinh"}
    };

    inBang(tieuDeLoaiVoucher, dsLoaiVoucher, {12, 34});

    int luaChonVoucher;

    cout << Mau::TIM << Mau::DAM
        << "Nhap lua chon [1-2]: "
        << Mau::RESET;

    is >> luaChonVoucher;

    while (luaChonVoucher != 1 && luaChonVoucher != 2) {
        cout << Mau::DO << Mau::DAM
            << "Lua chon khong hop le. Vui long nhap 1 hoac 2: "
            << Mau::RESET;

        is >> luaChonVoucher;
    }

    string loai;

    if (luaChonVoucher == 1) {
        loai = "MIEN_PHI";
    }
    else {
        loai = "GIAM_TIEN";
    }

    vc.setLoaiVoucher(loai);

    if (loai == "GIAM_TIEN") {
        double giaTri;

        cout << Mau::TIM << Mau::DAM
             << "Gia tri giam: " << Mau::RESET;
        is >> giaTri;

        while (giaTri < 0) {
            cout << Mau::DO << Mau::DAM
                 << "Gia tri giam khong hop le. Nhap lai: "
                 << Mau::RESET;
            is >> giaTri;
        }

        vc.setGiaTriGiam(giaTri);
    }
    else {
        vc.setGiaTriGiam(0);
    }

    return is;
}

ostream& operator<<(ostream& os, const VoucherVanChuyen& vc) {
    os << "Ma voucher: " << vc.m_sMaVoucher << endl;
    os << "Loai voucher: " << vc.m_sLoaiVoucher << endl;

    if (vc.m_sLoaiVoucher == "MIEN_PHI") {
        os << "Uu dai: Mien phi van chuyen" << endl;
    }
    else {
        os << "Gia tri giam: "
           << fixed << setprecision(0)
           << vc.m_dGiaTriGiam << " VND" << endl;
    }

    return os;
}

// Nhap voucher
void VoucherVanChuyen::nhapVoucher() {
    cin >> *this;
}

// Xuat voucher
void VoucherVanChuyen::xuatVoucher() const {
    cout << *this;
}

// Tinh tien giam
double VoucherVanChuyen::tinhTienGiam(double tienVanChuyen) const {
    if (tienVanChuyen <= 0) {
        return 0;
    }

    if (m_sLoaiVoucher == "MIEN_PHI") {
        return tienVanChuyen;
    }

    if (m_sLoaiVoucher == "GIAM_TIEN") {
        if (m_dGiaTriGiam >= tienVanChuyen) {
            return tienVanChuyen;
        }

        return m_dGiaTriGiam;
    }

    return 0;
}