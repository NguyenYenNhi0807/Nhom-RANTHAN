#include "KhachHang.h"
#include <iomanip>
#include "GiaoDien.h"

// Constructor
KhachHang::KhachHang() {
    m_sMaKH = "";
    m_sTenKhachHang = "";
    m_sDiaChi = "";
    m_dTongChiTieu = 0;
}

KhachHang::KhachHang(string sMaKH, string sTenKhachHang,
                     string sDiaChi, double dTongChiTieu) {
    m_sMaKH = sMaKH;
    m_sTenKhachHang = sTenKhachHang;
    m_sDiaChi = sDiaChi;
    m_dTongChiTieu = dTongChiTieu;
}

KhachHang::KhachHang(const KhachHang& khachhang) {
    m_sMaKH = khachhang.m_sMaKH;
    m_sTenKhachHang = khachhang.m_sTenKhachHang;
    m_sDiaChi = khachhang.m_sDiaChi;
    m_dTongChiTieu = khachhang.m_dTongChiTieu;
}

// Destructor
KhachHang::~KhachHang() {
}

// Getter
string KhachHang::getMaKH() const {
    return m_sMaKH;
}

string KhachHang::getTenKhachHang() const {
    return m_sTenKhachHang;
}

string KhachHang::getDiaChi() const {
    return m_sDiaChi;
}

double KhachHang::getTongChiTieu() const {
    return m_dTongChiTieu;
}

// Setter
void KhachHang::setMaKH(string sMaKH) {
    m_sMaKH = sMaKH;
}

void KhachHang::setTenKhachHang(string sTenKhachHang) {
    m_sTenKhachHang = sTenKhachHang;
}

void KhachHang::setDiaChi(string sDiaChi) {
    m_sDiaChi = sDiaChi;
}

void KhachHang::setTongChiTieu(double dTongChiTieu) {
    if (dTongChiTieu >= 0) {
        m_dTongChiTieu = dTongChiTieu;
    }
}

// Nhap khach hang
void KhachHang::nhapKhachHang() {
    cin >> *this;
}

// Xuat khach hang
void KhachHang::xuatKhachHang() const {
    cout << *this;
}

// Nhap xuat
istream& operator>>(istream& is, KhachHang& kh) {
    cout << Mau::TIM << Mau::DAM
         << "Ma khach hang: " << Mau::RESET;
    getline(is >> ws, kh.m_sMaKH);

    cout << Mau::TIM << Mau::DAM
         << "Ten khach hang: " << Mau::RESET;
    getline(is, kh.m_sTenKhachHang);

    cout << Mau::TIM << Mau::DAM
         << "Dia chi: " << Mau::RESET;
    getline(is, kh.m_sDiaChi);

    cout << Mau::TIM << Mau::DAM
         << "Tong chi tieu: " << Mau::RESET;
    is >> kh.m_dTongChiTieu;

    return is;
}

ostream& operator<<(ostream& os, const KhachHang& kh) {
    os << "Ma khach hang: " << kh.m_sMaKH << endl;
    os << "Ten khach hang: " << kh.m_sTenKhachHang << endl;
    os << "Dia chi: " << kh.m_sDiaChi << endl;
    os << "Tong chi tieu: "
       << fixed << setprecision(0)
       << kh.m_dTongChiTieu << " VND" << endl;
    os << "Xep hang: " << kh.xepHang() << endl;
    os << "Uu dai: " << kh.tinhUuDai() * 100 << "%" << endl;

    return os;
}


//_____________DINH NGHIA KHACHHANGDONG___________________

KhachHangDong::KhachHangDong() : KhachHang() {
}

// Constructor co tham so
KhachHangDong::KhachHangDong(
    string sMaKH,
    string sTenKhachHang,
    string sDiaChi,
    double dTongChiTieu
) : KhachHang(sMaKH, sTenKhachHang, sDiaChi, dTongChiTieu) {
}

// Constructor sao chep
KhachHangDong::KhachHangDong(
    const KhachHangDong& khachhang
) : KhachHang(khachhang) {
}

string KhachHangDong::xepHang() const {
    return "Dong";
}

double KhachHangDong::tinhUuDai() const {
    return 0.05;
}

double KhachHang::tinhTienUuDai(double tienHang) const {
    if (tienHang <= 0) {
        return 0;
    }

    return tienHang * tinhUuDai();
}


//_____________DINH NGHIA KHACHHANGBAC___________________

KhachHangBac::KhachHangBac() : KhachHang() {
}

// Constructor co tham so
KhachHangBac::KhachHangBac(
    string sMaKH,
    string sTenKhachHang,
    string sDiaChi,
    double dTongChiTieu
) : KhachHang(sMaKH, sTenKhachHang, sDiaChi, dTongChiTieu) {
}

// Constructor sao chep
KhachHangBac::KhachHangBac(
    const KhachHangBac& khachhang
) : KhachHang(khachhang) {
}

string KhachHangBac::xepHang() const {
    return "Bac";
}

double KhachHangBac::tinhUuDai() const {
    return 0.10;
}


//_____________DINH NGHIA KHACHHANGVANG___________________

KhachHangVang::KhachHangVang() : KhachHang() {
}

// Constructor co tham so
KhachHangVang::KhachHangVang(
    string sMaKH,
    string sTenKhachHang,
    string sDiaChi,
    double dTongChiTieu
) : KhachHang(sMaKH, sTenKhachHang, sDiaChi, dTongChiTieu) {
}

// Constructor sao chep
KhachHangVang::KhachHangVang(
    const KhachHangVang& khachhang
) : KhachHang(khachhang) {
}

string KhachHangVang::xepHang() const {
    return "Vang";
}

double KhachHangVang::tinhUuDai() const {
    return 0.15;
}


//_____________DINH NGHIA KHACHHANGKIMCUONG___________________

KhachHangKimCuong::KhachHangKimCuong() : KhachHang() {
}

// Constructor co tham so
KhachHangKimCuong::KhachHangKimCuong(
    string sMaKH,
    string sTenKhachHang,
    string sDiaChi,
    double dTongChiTieu
) : KhachHang(sMaKH, sTenKhachHang, sDiaChi, dTongChiTieu) {
}

// Constructor sao chep
KhachHangKimCuong::KhachHangKimCuong(
    const KhachHangKimCuong& khachhang
) : KhachHang(khachhang) {
}

string KhachHangKimCuong::xepHang() const {
    return "Kim Cuong";
}

double KhachHangKimCuong::tinhUuDai() const {
    return 0.20;
}
   
