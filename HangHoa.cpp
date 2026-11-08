#include "HangHoa.h"
#include <iomanip>
#include "GiaoDien.h"

// Constructor
HangHoa::HangHoa() {
    m_sTenHang = "";
    m_dCanNang = 0;
    m_dGiaTien = 0;
}

HangHoa::HangHoa(string sTenHang, double dCanNang, double dGiaTien) {
    m_sTenHang = sTenHang;
    m_dCanNang = dCanNang;
    m_dGiaTien = dGiaTien;
}

HangHoa::HangHoa(const HangHoa& hanghoa) {
    m_sTenHang = hanghoa.m_sTenHang;
    m_dCanNang = hanghoa.m_dCanNang;
    m_dGiaTien = hanghoa.m_dGiaTien;
}

// Destructor
HangHoa::~HangHoa() {
}

// Getter
string HangHoa::getTenHang() const {
    return m_sTenHang;
}

double HangHoa::getCanNang() const {
    return m_dCanNang;
}

double HangHoa::getGiaTien() const {
    return m_dGiaTien;
}

// Setter
void HangHoa::setTenHang(string sTenHang) {
    m_sTenHang = sTenHang;
}

void HangHoa::setCanNang(double dCanNang) {
    m_dCanNang = dCanNang;
}

void HangHoa::setGiaTien(double dGiaTien) {
    m_dGiaTien = dGiaTien;
}

// Toan tu nhap
istream& operator>>(istream& in, HangHoa& hanghoa) {
    cout << "Nhap ten hang: ";
    getline(in >> ws, hanghoa.m_sTenHang);

    cout << "Nhap can nang (kg): ";
    in >> hanghoa.m_dCanNang;

    cout << "Nhap gia tien: ";
    in >> hanghoa.m_dGiaTien;

    return in;
}

// Toan tu xuat
ostream& operator<<(ostream& out, const HangHoa& hanghoa) {
    out << "Ten hang: " << hanghoa.m_sTenHang << endl;
    out << "Can nang: " << hanghoa.m_dCanNang << " kg" << endl;

    out << "Gia tien: "
        << fixed << setprecision(0)
        << hanghoa.m_dGiaTien << " VND" << endl;

    return out;
}

// Nhap xuat
void HangHoa::nhapHangHoa() {
    cout << Mau::CAM << Mau::DAM
         << "Nhap ten hang: " << Mau::RESET;
    getline(cin >> ws, m_sTenHang);

    cout << Mau::CAM << Mau::DAM
         << "Nhap can nang (kg): " << Mau::RESET;
    cin >> m_dCanNang;

    cout << Mau::CAM << Mau::DAM
         << "Nhap gia tien: " << Mau::RESET;
    cin >> m_dGiaTien;
}

void HangHoa::xuatHangHoa() const {
    cout << fixed << setprecision(0);
    
    cout << "Ten hang: " << m_sTenHang << endl;
    cout << "Can nang: " << m_dCanNang << " kg" << endl;
    cout << "Gia tien: " << m_dGiaTien << " VND" << endl;
}

//_____________CLASS HANGHOATHUONG________________________

// Constructor
HangHoaThuong::HangHoaThuong() : HangHoa() {
}

HangHoaThuong::HangHoaThuong(string sTenHang, double dCanNang, double dGiaTien)
    : HangHoa(sTenHang, dCanNang, dGiaTien) {
}

HangHoaThuong::HangHoaThuong(
    const HangHoaThuong& hanghoa
) : HangHoa(hanghoa) {
}

// Tinh phu phi
double HangHoaThuong::tinhPhuPhi() const {
    return 0;
}

//_____________CLASS HANGHOADACBIET________________________

// Constructor
HangHoaDacBiet::HangHoaDacBiet() : HangHoa() {
}

HangHoaDacBiet::HangHoaDacBiet(string sTenHang, double dCanNang, double dGiaTien)
    : HangHoa(sTenHang, dCanNang, dGiaTien) {
}

HangHoaDacBiet::HangHoaDacBiet(
    const HangHoaDacBiet& hanghoa
) : HangHoa(hanghoa) {
}

// Tinh phu phi
double HangHoaDacBiet::tinhPhuPhi() const {
    return getGiaTien() * 0.10;
}

//_____________CLASS HANGHOACONGKENH________________________

// Constructor
HangHoaCongKenh::HangHoaCongKenh() : HangHoa() {
}

HangHoaCongKenh::HangHoaCongKenh(string sTenHang, double dCanNang, double dGiaTien)
    : HangHoa(sTenHang, dCanNang, dGiaTien) {
}

HangHoaCongKenh::HangHoaCongKenh(
    const HangHoaCongKenh& hanghoa
) : HangHoa(hanghoa) {
}

// Tinh phu phi
double HangHoaCongKenh::tinhPhuPhi() const {
    return getCanNang() * 5000;
}
