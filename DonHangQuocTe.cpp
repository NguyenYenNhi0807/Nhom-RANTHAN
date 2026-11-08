#include "DonHangQuocTe.h"
#include "GiaoDien.h"

#include<iomanip>

// Constructor
DonHangQuocTe::DonHangQuocTe()
    : DonHang(), m_dPhiHaiQuan(0) {
}

DonHangQuocTe::DonHangQuocTe(double dPhiHaiQuan)
    : DonHang(), m_dPhiHaiQuan(0) {
    setPhiHaiQuan(dPhiHaiQuan);
}

DonHangQuocTe::DonHangQuocTe(
    Code sMaDonHang,
    Date sNgayDatHang,
    double dPhiHaiQuan
)
    : DonHang(sMaDonHang, sNgayDatHang), m_dPhiHaiQuan(0) {
    setPhiHaiQuan(dPhiHaiQuan);
}

DonHangQuocTe::DonHangQuocTe(
    const DonHangQuocTe& donhangquocte
)
    : DonHang(donhangquocte),
      m_dPhiHaiQuan(donhangquocte.m_dPhiHaiQuan) {
}

// Destructor
DonHangQuocTe::~DonHangQuocTe() {
}

// Getter
double DonHangQuocTe::getPhiHaiQuan() const {
    return m_dPhiHaiQuan;
}

// Setter
void DonHangQuocTe::setPhiHaiQuan(double dPhiHaiQuan) {
    if (dPhiHaiQuan >= 0) {
        m_dPhiHaiQuan = dPhiHaiQuan;
    }
    else {
        cout << "Phi hai quan khong hop le!" << endl;
    }
}

// Nhap xuat
istream& operator>>(
    istream& in,
    DonHangQuocTe& donhangquocte
) {
    in >> static_cast<DonHang&>(donhangquocte);

    double phiHaiQuan;
    cout << "Nhap phi hai quan: ";
    in >> phiHaiQuan;

    if (in && phiHaiQuan >= 0) {
        donhangquocte.m_dPhiHaiQuan = phiHaiQuan;
    }
    else {
        in.setstate(ios::failbit);
    }

    return in;
}

ostream& operator<<(
    ostream& out,
    const DonHangQuocTe& donhangquocte
) {
    out << static_cast<const DonHang&>(donhangquocte);
    out << "[Phi hai quan]: "
        << fixed << setprecision(0)
        << donhangquocte.m_dPhiHaiQuan
        << " VND" << endl;
    return out;
}

void DonHangQuocTe::nhapDonHangQuocTe() {
    cin >> *this;
}

void DonHangQuocTe::xuatDonHangQuocTe() const {
    cout << *this;
}

// Da hinh
void DonHangQuocTe::nhapDonHang(string scope) {
    DonHang::nhapDonHang(scope);

    double phiHaiQuan;

    cout << "Nhap phi hai quan: ";
    cin >> phiHaiQuan;

    while (phiHaiQuan < 0) {
        cout << "Phi hai quan khong hop le! Nhap lai: ";
        cin >> phiHaiQuan;
    }

    setPhiHaiQuan(phiHaiQuan);
}

void DonHangQuocTe::xuatDonHang() const {
    // Lớp cha đã xuất thông tin vận chuyển
    DonHang::xuatDonHang();

    cout << "\n===== DANH SACH HANG HOA =====" << endl;
    xuatDanhSachHangHoa();
}

double DonHangQuocTe::TinhTongTien() const {

    double tienHangSauUuDai =
        tinhTienHang() - getUuDaiKhachHang();

    double phiVanChuyenSauVoucher =
        tinhPhiVanChuyen() - getGiamGiaVoucher();

    if (tienHangSauUuDai < 0)
        tienHangSauUuDai = 0;

    if (phiVanChuyenSauVoucher < 0)
        phiVanChuyenSauVoucher = 0;

    return tienHangSauUuDai
         + phiVanChuyenSauVoucher
         + getPhiHaiQuan();
}

void DonHangQuocTe::InThongTin() const {
    cout << Mau::TIM << Mau::DAM
         << "===== DON HANG QUOC TE ====="
         << Mau::RESET << endl;

    xuatDonHang();

    cout << fixed << setprecision(0);

    cout << "Tien hang: "
         << tinhTongTienHang() << " VND" << endl;

    cout << "Phu phi hang hoa: "
         << tinhTongPhuPhiHangHoa() << " VND" << endl;

    cout << "Phi van chuyen: "
         << tinhPhiVanChuyen() << " VND" << endl;

    cout << "Phi hai quan: "
         << getPhiHaiQuan() << " VND" << endl;

    cout << Mau::XANH_LA << Mau::DAM
         << "=> Tong tien don hang quoc te: "
         << TinhTongTien() << " VND"
         << Mau::RESET << endl;
}