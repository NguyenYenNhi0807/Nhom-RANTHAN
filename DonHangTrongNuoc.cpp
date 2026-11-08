#include "DonHangTrongNuoc.h"
#include "GiaoDien.h"

#include<iomanip>

// Constructor
DonHangTrongNuoc::DonHangTrongNuoc()
    : DonHang() {
}

DonHangTrongNuoc::DonHangTrongNuoc(
    Code sMaDonHang,
    Date sNgayDatHang
)
    : DonHang(sMaDonHang, sNgayDatHang) {
}

DonHangTrongNuoc::DonHangTrongNuoc(
    const DonHangTrongNuoc& donhangtrongnuoc
)
    : DonHang(donhangtrongnuoc) {
}

// Destructor
DonHangTrongNuoc::~DonHangTrongNuoc() {
}

// Nhap xuat
istream& operator>>(
    istream& in,
    DonHangTrongNuoc& donhangtrongnuoc
) {
    in >> static_cast<DonHang&>(donhangtrongnuoc);
    return in;
}

ostream& operator<<(
    ostream& out,
    const DonHangTrongNuoc& donhangtrongnuoc
) {
    out << "[DON HANG TRONG NUOC]" << endl;
    out << "[Ma don hang]: "
        << donhangtrongnuoc.getMaDonHang() << endl;

    out << "[Ngay dat hang]: "
        << donhangtrongnuoc.getNgayDatHang() << endl;

    vector<HangHoa*> dsHangHoa =
        donhangtrongnuoc.getDanhSachHangHoa();

    for (vector<HangHoa*>::size_type i = 0;
         i < dsHangHoa.size(); i++) {
        if (dsHangHoa[i] != nullptr) {
            out << "Hang hoa thu " << i + 1 << ":" << endl;
            out << "Ten hang: "
                << dsHangHoa[i]->getTenHang() << endl;
            out << "Gia tien: "
                << fixed << setprecision(0)
                << dsHangHoa[i]->getGiaTien() 
                << " VND" << endl;
        }
    }
    out << donhangtrongnuoc.getThongTinVanChuyen();
    return out;
}

// Nhap don hang trong nuoc
void DonHangTrongNuoc::nhapDonHangTrongNuoc() {
    cin >> *this;
}

// Xuat don hang trong nuoc
void DonHangTrongNuoc::xuatDonHangTrongNuoc() const {
    cout << *this;
}

// Da hinh
void DonHangTrongNuoc::nhapDonHang(string scope) {
    DonHang::nhapDonHang(scope);
}

void DonHangTrongNuoc::xuatDonHang() const {
    DonHang::xuatDonHang();
    cout << "\n===== DANH SACH HANG HOA =====" << endl;
    xuatDanhSachHangHoa();
}

double DonHangTrongNuoc::TinhTongTien() const {
    double tienHangSauUuDai =
        tinhTienHang() - getUuDaiKhachHang();

    double phiVanChuyenSauVoucher =
        tinhPhiVanChuyen() - getGiamGiaVoucher();

    if (tienHangSauUuDai < 0)
        tienHangSauUuDai = 0;

    if (phiVanChuyenSauVoucher < 0)
        phiVanChuyenSauVoucher = 0;

    return tienHangSauUuDai
         + phiVanChuyenSauVoucher;
}

void DonHangTrongNuoc::InThongTin() const {
    cout << Mau::XANH_DUONG << Mau::DAM
         << "===== DON HANG TRONG NUOC ====="
         << Mau::RESET << endl;

    xuatDonHang();

    cout << fixed << setprecision(0);

    cout << "Tien hang: "
         << tinhTongTienHang() << " VND" << endl;

    cout << "Phu phi hang hoa: "
         << tinhTongPhuPhiHangHoa() << " VND" << endl;

    cout << "Phi van chuyen: "
         << tinhPhiVanChuyen() << " VND" << endl;

    cout << Mau::XANH_LA << Mau::DAM
         << "=> Tong tien don hang: "
         << TinhTongTien() << " VND"
         << Mau::RESET << endl;
}