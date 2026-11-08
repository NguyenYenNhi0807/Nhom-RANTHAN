#include "ThanhToan.h"
#include "GiaoDien.h"
#include <iomanip>
#include <cmath>
#include <sstream>
#include <vector>

// Constructor

ThanhToan::ThanhToan() {
    m_dTienHang = 0;
    m_dPhuPhiHang = 0;
    m_dPhiVanChuyen = 0;
    m_dPhiHaiQuan = 0;
    m_dUuDaiKhachHang = 0;
    m_dGiamGiaVoucher = 0;
}

ThanhToan::ThanhToan(
    double dTienHang,
    double dPhuPhiHang,
    double dPhiVanChuyen,
    double dPhiHaiQuan,
    double dUuDaiKhachHang,
    double dGiamGiaVoucher
) {
    m_dTienHang = 0;
    m_dPhuPhiHang = 0;
    m_dPhiVanChuyen = 0;
    m_dPhiHaiQuan = 0;
    m_dUuDaiKhachHang = 0;
    m_dGiamGiaVoucher = 0;

    setTienHang(dTienHang);
    setPhuPhiHang(dPhuPhiHang);
    setPhiVanChuyen(dPhiVanChuyen);
    setPhiHaiQuan(dPhiHaiQuan);
    setUuDaiKhachHang(dUuDaiKhachHang);
    setGiamGiaVoucher(dGiamGiaVoucher);
}

ThanhToan::ThanhToan(const ThanhToan& thanhtoan) {
    m_dTienHang = thanhtoan.m_dTienHang;
    m_dPhuPhiHang = thanhtoan.m_dPhuPhiHang;
    m_dPhiVanChuyen = thanhtoan.m_dPhiVanChuyen;
    m_dPhiHaiQuan = thanhtoan.m_dPhiHaiQuan;
    m_dUuDaiKhachHang = thanhtoan.m_dUuDaiKhachHang;
    m_dGiamGiaVoucher = thanhtoan.m_dGiamGiaVoucher;
}

// Destructor
ThanhToan::~ThanhToan() {
}

//Getter
double ThanhToan::getTienHang() const {
    return m_dTienHang;
}

double ThanhToan::getPhuPhiHang() const {
    return m_dPhuPhiHang;
}

double ThanhToan::getPhiVanChuyen() const {
    return m_dPhiVanChuyen;
}

double ThanhToan::getPhiHaiQuan() const {
    return m_dPhiHaiQuan;
}

double ThanhToan::getUuDaiKhachHang() const {
    return m_dUuDaiKhachHang;
}

double ThanhToan::getGiamGiaVoucher() const {
    return m_dGiamGiaVoucher;
}

// Setter
void ThanhToan::setTienHang(double dTienHang) {
    if (dTienHang >= 0) {
        m_dTienHang = dTienHang;
    }
}

void ThanhToan::setPhuPhiHang(double dPhuPhiHang) {
    if (dPhuPhiHang >= 0) {
        m_dPhuPhiHang = dPhuPhiHang;
    }
}

void ThanhToan::setPhiVanChuyen(double dPhiVanChuyen) {
    if (dPhiVanChuyen >= 0) {
        m_dPhiVanChuyen = dPhiVanChuyen;
    }
}

void ThanhToan::setPhiHaiQuan(double dPhiHaiQuan) {
    if (dPhiHaiQuan >= 0) {
        m_dPhiHaiQuan = dPhiHaiQuan;
    }
}

void ThanhToan::setUuDaiKhachHang(double dUuDaiKhachHang) {
    if (dUuDaiKhachHang >= 0) {
        m_dUuDaiKhachHang = dUuDaiKhachHang;
    }
}

void ThanhToan::setGiamGiaVoucher(double dGiamGiaVoucher) {
    if (dGiamGiaVoucher >= 0) {
        m_dGiamGiaVoucher = dGiamGiaVoucher;
    }
}

// Toan tu nhap
istream& operator>>(istream& is, ThanhToan& tt) {
    double tienHang;
    double phuPhiHang;
    double phiVanChuyen;
    double phiHaiQuan;
    double uuDaiKhachHang;
    double giamGiaVoucher;

    cout << "Nhap tien hang: ";
    is >> tienHang;

    cout << "Nhap phu phi hang: ";
    is >> phuPhiHang;

    cout << "Nhap phi van chuyen: ";
    is >> phiVanChuyen;

    cout << "Nhap phi hai quan: ";
    is >> phiHaiQuan;

    cout << "Nhap uu dai khach hang: ";
    is >> uuDaiKhachHang;

    cout << "Nhap giam gia voucher: ";
    is >> giamGiaVoucher;

    if (!is) {
        return is;
    }

    if (tienHang < 0 ||
        phuPhiHang < 0 ||
        phiVanChuyen < 0 ||
        phiHaiQuan < 0 ||
        uuDaiKhachHang < 0 ||
        giamGiaVoucher < 0) {

        is.setstate(ios::failbit);
        return is;
    }

    tt.setTienHang(tienHang);
    tt.setPhuPhiHang(phuPhiHang);
    tt.setPhiVanChuyen(phiVanChuyen);
    tt.setPhiHaiQuan(phiHaiQuan);
    tt.setUuDaiKhachHang(uuDaiKhachHang);
    tt.setGiamGiaVoucher(giamGiaVoucher);

    return is;
}

// Toan tu xuat
ostream& operator<<(ostream& os, const ThanhToan& tt) {
    os << "Tien hang: " << fixed << setprecision(0)
       << tt.m_dTienHang << " VND" << endl;

    os << "Phu phi hang: "
       << tt.m_dPhuPhiHang << " VND" << endl;

    os << "Phi van chuyen: "
       << tt.m_dPhiVanChuyen << " VND" << endl;

    os << "Phi hai quan: "
       << tt.m_dPhiHaiQuan << " VND" << endl;

    os << "Uu dai khach hang: "
       << tt.m_dUuDaiKhachHang << " VND" << endl;

    os << "Giam gia voucher: "
       << tt.m_dGiamGiaVoucher << " VND" << endl;

    return os;
}

// Phuong thuc nhap
void ThanhToan::nhapThanhToan() {
    cin >> *this;
}

// Tinh tien
double ThanhToan::tinhTienHangSauUuDai() const {
    double tienHang = m_dTienHang + m_dPhuPhiHang;

    double tienSauUuDai =
        tienHang - m_dUuDaiKhachHang;

    if (tienSauUuDai < 0) {
        return 0;
    }

    return tienSauUuDai;
}

double ThanhToan::tinhPhiVanChuyenSauVoucher() const {
    double phiSauVoucher =
        m_dPhiVanChuyen - m_dGiamGiaVoucher;

    if (phiSauVoucher < 0) {
        return 0;
    }

    return phiSauVoucher;
}

double ThanhToan::tinhTongTienTrongNuoc() const {
    return tinhTienHangSauUuDai()
         + tinhPhiVanChuyenSauVoucher();
}

double ThanhToan::tinhTongTienQuocTe() const {
    return tinhTongTienTrongNuoc()
         + m_dPhiHaiQuan;
}

// Xuat
void ThanhToan::xuatThanhToan(bool laDonHangQuocTe) const {
    xuatChiTietThanhToan(laDonHangQuocTe);
}

void ThanhToan::xuatChiTietThanhToan(bool laDonHangQuocTe) const {
    auto dinhDangTienBang = [](double tien) {
        long long soTien = llround(tien);
        bool am = soTien < 0;
        string chuoi = to_string(am ? -soTien : soTien);

        for (int i = static_cast<int>(chuoi.size()) - 3; i > 0; i -= 3) {
            chuoi.insert(static_cast<size_t>(i), ".");
        }

        return string(am ? "-" : "") + chuoi + " VND";
    };

    cout << "\n";
    hienThiTieuDeChucNang("CHI TIET THANH TOAN");

    vector<string> tieuDe = {
        "KHOAN THANH TOAN", "SO TIEN"
    };

    vector<vector<string>> duLieu = {
        {"Tien hang", dinhDangTienBang(m_dTienHang)},
        {"Phu phi hang hoa", dinhDangTienBang(m_dPhuPhiHang)},
        {"Uu dai khach hang", "-" + dinhDangTienBang(m_dUuDaiKhachHang)},
        {"Phi van chuyen", dinhDangTienBang(m_dPhiVanChuyen)},
        {"Voucher giam van chuyen", "-" + dinhDangTienBang(m_dGiamGiaVoucher)},
        {"Phi van chuyen sau voucher",
         dinhDangTienBang(tinhPhiVanChuyenSauVoucher())}
    };

    if (laDonHangQuocTe) {
        duLieu.push_back({
            "Phi hai quan", dinhDangTienBang(m_dPhiHaiQuan)
        });
        duLieu.push_back({
            "TONG THANH TOAN",
            dinhDangTienBang(tinhTongTienQuocTe())
        });
    }
    else {
        duLieu.push_back({
            "TONG THANH TOAN",
            dinhDangTienBang(tinhTongTienTrongNuoc())
        });
    }

    inBang(tieuDe, duLieu, {30, 28});
}

