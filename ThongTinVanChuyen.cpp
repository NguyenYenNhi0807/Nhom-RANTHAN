#include "ThongTinVanChuyen.h"
#include<iomanip>

// Constructor 
ThongTinVanChuyen::ThongTinVanChuyen() {
    m_sPhuongThuc = "CoBan";
    m_dTienVanChuyen = 20000;
}

ThongTinVanChuyen::ThongTinVanChuyen(
    const string& phuongThuc,
    double tienVanChuyen
) {
    m_sPhuongThuc = "CoBan";
    m_dTienVanChuyen = 20000;

    setPhuongThuc(phuongThuc);

    if (tienVanChuyen >= 0) {
        m_dTienVanChuyen = tienVanChuyen;
    }
}

ThongTinVanChuyen::ThongTinVanChuyen(
    const ThongTinVanChuyen& ttv
) {
    m_sPhuongThuc = ttv.m_sPhuongThuc;
    m_dTienVanChuyen = ttv.m_dTienVanChuyen;
}

ThongTinVanChuyen& ThongTinVanChuyen::operator=(
    const ThongTinVanChuyen& ttv
) {
    if (this != &ttv) {
        m_sPhuongThuc = ttv.m_sPhuongThuc;
        m_dTienVanChuyen = ttv.m_dTienVanChuyen;
    }

    return *this;
}

// Destructor
ThongTinVanChuyen::~ThongTinVanChuyen() {
}

// Getter
string ThongTinVanChuyen::getPhuongThuc() const {
    return m_sPhuongThuc;
}

double ThongTinVanChuyen::getTienVanChuyen() const {
    return m_dTienVanChuyen;
}

// Setter
void ThongTinVanChuyen::setPhuongThuc(
    const string& phuongThuc
) {
    if (phuongThuc == "CoBan") {
        m_sPhuongThuc = phuongThuc;
        m_dTienVanChuyen = 20000;
    }
    else if (phuongThuc == "Nhanh") {
        m_sPhuongThuc = phuongThuc;
        m_dTienVanChuyen = 35000;
    }
    else if (phuongThuc == "HoaToc") {
        m_sPhuongThuc = phuongThuc;
        m_dTienVanChuyen = 50000;
    }
    else {
        cout << "Phuong thuc van chuyen khong hop le!" << endl;
    }
}

void ThongTinVanChuyen::setTienVanChuyen(
    double tienVanChuyen
) {
    if (tienVanChuyen >= 0) {
        m_dTienVanChuyen = tienVanChuyen;
    }
    else {
        cout << "Tien van chuyen khong hop le!" << endl;
    }
}

// Nhapxuat
istream& operator>>(
    istream& is,
    ThongTinVanChuyen& ttv
) {
    string phuongThuc;

    cout << "Phuong thuc (CoBan/Nhanh/HoaToc): ";
    is >> phuongThuc;

    while (is &&
           phuongThuc != "CoBan" &&
           phuongThuc != "Nhanh" &&
           phuongThuc != "HoaToc") {

        cout << "Phuong thuc khong hop le! Nhap lai: ";
        is >> phuongThuc;
    }

    if (is) {
        ttv.setPhuongThuc(phuongThuc);
    }

    return is;
}

ostream& operator<<(
    ostream& os,
    const ThongTinVanChuyen& ttv
) {
    os << "\n===== THONG TIN VAN CHUYEN =====\n";
    os << "┌──────────────────────────────┬──────────────────────┐\n";

    os << "│ "
       << left << setw(28) << "Phuong thuc van chuyen"
       << " │ "
       << left << setw(20) << ttv.m_sPhuongThuc
       << " │\n";

    os << "├──────────────────────────────┼──────────────────────┤\n";

    string tien = to_string((long long)ttv.m_dTienVanChuyen);
    for (int i = (int)tien.length() - 3; i > 0; i -= 3) {
        tien.insert(i, ".");
    }

    os << "│ "
       << left << setw(28) << "Tien van chuyen"
       << " │ "
       << left << setw(21) << (tien + " VND")
       << "│\n";

    os << "└──────────────────────────────┴──────────────────────┘\n";

    return os;
}

void ThongTinVanChuyen::nhapThongTin() {
    string phuongThuc;

    cout << "Nhap phuong thuc van chuyen (CoBan/Nhanh/HoaToc): ";
    cin >> phuongThuc;

    while (phuongThuc != "CoBan" &&
           phuongThuc != "Nhanh" &&
           phuongThuc != "HoaToc") {

        cout << "Phuong thuc khong hop le! Nhap lai: ";
        cin >> phuongThuc;
    }

    setPhuongThuc(phuongThuc);
}

void ThongTinVanChuyen::xuatThongTin() const {
    cout << "Phuong thuc van chuyen: "
         << m_sPhuongThuc << endl;

    cout << "Tien van chuyen: "
         << fixed << setprecision(0)
         << m_dTienVanChuyen << " VND " << endl;
}

// Tinh tien
double ThongTinVanChuyen::tinhTienVanChuyen() const {
    return m_dTienVanChuyen;
}

