#include "DonHang.h"
#include "GiaoDien.h"

// Constructor
DonHang::DonHang()
    : m_sMaDonHang("DED","STD","00001"),
      m_sNgayDatHang(1,1,2000),
      m_dUuDaiKhachHang(0),
      m_dGiamGiaVoucher(0) {
}

DonHang::DonHang(Code sMaDonHang, Date sNgayDatHang)
    : m_sMaDonHang(sMaDonHang),
      m_sNgayDatHang(sNgayDatHang),
      m_dUuDaiKhachHang(0),
      m_dGiamGiaVoucher(0) {
}

DonHang::DonHang(const DonHang &donhang)
    : m_sMaDonHang(donhang.m_sMaDonHang),
      m_sNgayDatHang(donhang.m_sNgayDatHang),
      m_dsHangHoa(donhang.m_dsHangHoa),
      m_tThongTinVanChuyen(donhang.m_tThongTinVanChuyen),
      m_dUuDaiKhachHang(donhang.m_dUuDaiKhachHang),
      m_dGiamGiaVoucher(donhang.m_dGiamGiaVoucher) {
}

// Destructor
DonHang::~DonHang(){

}

// Getter
Code DonHang::getMaDonHang() const{
    return m_sMaDonHang;
}

Date DonHang::getNgayDatHang() const{
    return m_sNgayDatHang;
}

Date DonHang::getNgayGiaoHangSomNhat() const {
    string dichVu = m_sMaDonHang.getService();

    if (dichVu == "STD")
        return m_sNgayDatHang.congNgay(5);

    if (dichVu == "EXP")
        return m_sNgayDatHang.congNgay(3);

    if (dichVu == "SUP")
        return m_sNgayDatHang.congNgay(1);

    return m_sNgayDatHang.congNgay(5);
}

Date DonHang::getNgayGiaoHangMuonNhat() const {
    string dichVu = m_sMaDonHang.getService();

    if (dichVu == "STD")
        return m_sNgayDatHang.congNgay(7);

    if (dichVu == "EXP")
        return m_sNgayDatHang.congNgay(4);

    if (dichVu == "SUP")
        return m_sNgayDatHang.congNgay(2);

    return m_sNgayDatHang.congNgay(7);
}

vector<HangHoa*> DonHang::getDanhSachHangHoa() const{
    return m_dsHangHoa;
}

double DonHang::getUuDaiKhachHang() const {
    return m_dUuDaiKhachHang;
}

double DonHang::getGiamGiaVoucher() const {
    return m_dGiamGiaVoucher;
}

ThongTinVanChuyen DonHang::getThongTinVanChuyen() const {
    return m_tThongTinVanChuyen;
}

// Setter
void DonHang::setMaDonHang(Code sMaDonHang){
    m_sMaDonHang=sMaDonHang;
}

void DonHang::setNgayDatHang(Date sNgayDatHang){
    m_sNgayDatHang=sNgayDatHang;
}

void DonHang::setUuDaiKhachHang(double tien) {
    if (tien >= 0)
        m_dUuDaiKhachHang = tien;
}

void DonHang::setGiamGiaVoucher(double tien) {
    if (tien >= 0)
        m_dGiamGiaVoucher = tien;
}

void DonHang::setThongTinVanChuyen(
    const ThongTinVanChuyen& thongTinVanChuyen
) {
    m_tThongTinVanChuyen = thongTinVanChuyen;
}

// Nhap xuat
istream& operator>>(istream& in, DonHang& donhang) {

    hienThiTieuDeMuc("HUONG DAN NHAP MA DON HANG");

    cout << "Ma don hang co cau truc: A-B-C\n";
    cout << "Trong do:\n";

    cout << "A - Pham vi van chuyen:\n";
    cout << "    DED: Don hang trong nuoc\n";
    cout << "    IED: Don hang quoc te\n";

    cout << "\nB - Goi van chuyen:\n";
    cout << "    STD: Co ban\n";
    cout << "    EXP: Nhanh\n";
    cout << "    SUP: Hoa toc\n";

    cout << "\nC - Ma dinh danh:\n";
    cout << "    00001, 00002, 00003, ...\n";

    cout << "\nVi du: DED-STD-00001\n";
    cout << "================================================\n";

    cout << "Nhap ma don hang (VD: DED-STD-00001): ";
    in >> donhang.m_sMaDonHang;

    cout << "Nhap ngay dat hang (VD: 02/07/2024): ";
    in >> donhang.m_sNgayDatHang;
    in >> donhang.m_tThongTinVanChuyen;

    return in;
}

ostream& operator<<(ostream& out, const DonHang& donhang){
    out<<"[Ma don hang]: "<<donhang.m_sMaDonHang<<endl;
    out<<"[Ngay dat hang]: "<<donhang.m_sNgayDatHang<<endl;
    out << donhang.m_tThongTinVanChuyen;
    return out;
}

void DonHang::nhapDonHang(string scope) {
    hienThiTieuDeMuc("TAO MA DON HANG");

    m_sMaDonHang.nhapCode(scope);

    string goiVanChuyen = m_sMaDonHang.getService();

    if (goiVanChuyen == "STD") {
        m_tThongTinVanChuyen.setPhuongThuc("CoBan");
    }
    else if (goiVanChuyen == "EXP") {
        m_tThongTinVanChuyen.setPhuongThuc("Nhanh");
    }
    else if (goiVanChuyen == "SUP") {
        m_tThongTinVanChuyen.setPhuongThuc("HoaToc");
    }

    cout << Mau::CAM << Mau::DAM
         << "\nNhap ngay dat hang (dd/mm/yyyy): "
         << Mau::RESET;

    cin >> m_sNgayDatHang;
    cout << m_tThongTinVanChuyen;
}

void DonHang::xuatDonHang() const{
    cout << "- Ma don hang: " << m_sMaDonHang;
    cout << "- Ngay dat hang: " << m_sNgayDatHang << endl;
}

// Quan ly hang hoa
void DonHang::themHangHoa(HangHoa* hangHoa){
    if(hangHoa != nullptr){
        m_dsHangHoa.push_back(hangHoa);
    }
}

void DonHang::xuatDanhSachHangHoa() const{
    if(m_dsHangHoa.empty()){
        cout<<"Don hang chua co hang hoa!"<<endl;
        return;
    }

    for(vector<HangHoa*>::size_type i = 0;
        i < m_dsHangHoa.size(); i++){
        cout<<"\n- Hang hoa thu "<<i+1<<":"<<endl;
        m_dsHangHoa[i]->xuatHangHoa();
    }
}

// Tinh toan
double DonHang::tinhTongTienHang() const {
    double tongTien = 0;

    for (vector<HangHoa*>::size_type i = 0;
         i < m_dsHangHoa.size(); i++){
        if (m_dsHangHoa[i] != nullptr) {
            tongTien += m_dsHangHoa[i]->getGiaTien();
        }
    }

    return tongTien;
}

double DonHang::tinhTongPhuPhiHangHoa() const {
    double tongPhuPhi = 0;

    for (vector<HangHoa*>::size_type i = 0;
         i < m_dsHangHoa.size(); i++) {
        if (m_dsHangHoa[i] != nullptr) {
            tongPhuPhi += m_dsHangHoa[i]->tinhPhuPhi();
        }
    }

    return tongPhuPhi;
}

double DonHang::tinhTienHang() const {
    return tinhTongTienHang()
         + tinhTongPhuPhiHangHoa();
}

double DonHang::tinhPhiVanChuyen() const {
    return m_tThongTinVanChuyen.tinhTienVanChuyen();
}
