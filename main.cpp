#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <cmath>
#include <string>

#include "DonHangTrongNuoc.h"
#include "DonHangQuocTe.h"
#include "HangHoa.h"
#include "KhachHang.h"
#include "Voucher.h"
#include "ThanhToan.h"
#include "GiaoDien.h"

using namespace std;

// ==========================================
// NHAP DANH SACH HANG HOA
// ==========================================

void nhapDanhSachHangHoa(DonHang* donHang) {
    int soLuong;

    hienThiTieuDeMuc("NHAP SO LUONG HANG HOA");
    hienThiNhapLuaChon();
    cin >> soLuong;

    while (soLuong <= 0) {
        cout << "So luong phai lon hon 0. Nhap lai: ";
        cin >> soLuong;
    }

    for (int i = 0; i < soLuong; i++) {
        int loai;

        hienThiTieuDeMuc("HANG HOA THU " + to_string(i + 1));

        vector<string> tieuDeLoaiHang = {
            "PHIM", "LOAI HANG HOA"
        };

        vector<vector<string>> dsLoaiHang = {
            {"[1]", "Hang hoa thuong"},
            {"[2]", "Hang hoa dac biet"},
            {"[3]", "Hang hoa cong kenh"}
        };

        inBang(tieuDeLoaiHang, dsLoaiHang, {12, 30});

        hienThiNhapLuaChon();
        cin >> loai;
        
        HangHoa* hangHoa = nullptr;

        switch (loai) {
        case 1:
            hangHoa = new HangHoaThuong();
            break;

        case 2:
            hangHoa = new HangHoaDacBiet();
            break;

        case 3:
            hangHoa = new HangHoaCongKenh();
            break;

        default:
            cout << "Loai hang khong hop le!\n";
            i--;
            continue;
        }

        hangHoa->nhapHangHoa();
        donHang->themHangHoa(hangHoa);
    }
}

// ==========================================
// TAO DON HANG TRONG NUOC
// ==========================================

DonHang* taoDonHangTrongNuoc() {
    DonHangTrongNuoc* donHang =
        new DonHangTrongNuoc();

    hienThiTieuDeChucNang("TAO DON HANG TRONG NUOC");

    donHang->nhapDonHang("DED");

    nhapDanhSachHangHoa(donHang);

    return donHang;
}

// ==========================================
// TAO DON HANG QUOC TE
// ==========================================

DonHang* taoDonHangQuocTe() {
    DonHangQuocTe* donHang =
        new DonHangQuocTe();

    hienThiTieuDeChucNang("TAO DON HANG QUOC TE");

    donHang->nhapDonHang("IED");

    nhapDanhSachHangHoa(donHang);

    return donHang;
}

// ==========================================
// TAO KHACH HANG
// ==========================================

KhachHang* taoKhachHang() {
    int luaChon;
    KhachHang* kh = nullptr;

    hienThiTieuDeChucNang("CHON HANG KHACH HANG");

    vector<string> tieuDeHangKH = {
        "PHIM", "HANG KHACH HANG"
    };

    vector<vector<string>> dsHangKH = {
        {"[1]", "Khach hang Dong (5%)"},
        {"[2]", "Khach hang Bac (10%)"},
        {"[3]", "Khach hang Vang (15%)"},
        {"[4]", "Khach hang Kim Cuong (20%)"}
    };

    inBang(tieuDeHangKH, dsHangKH, {12, 34});

    hienThiNhapLuaChon();
    cin >> luaChon;

    switch (luaChon) {
    case 1:
        kh = new KhachHangDong();
        break;

    case 2:
        kh = new KhachHangBac();
        break;

    case 3:
        kh = new KhachHangVang();
        break;

    case 4:
        kh = new KhachHangKimCuong();
        break;

    default:
        cout << "Lua chon khong hop le!\n";
        return nullptr;
    }

    hienThiTieuDeChucNang("NHAP THONG TIN KHACH HANG");
    cin >> *kh;

    return kh;
}

// ==========================================
// TAO VOUCHER
// ==========================================

VoucherVanChuyen taoVoucher() {
    VoucherVanChuyen voucher;

    hienThiTieuDeChucNang("NHAP VOUCHER VAN CHUYEN");

    cin >> voucher;

    return voucher;
}

// ==========================================
// TAO DOI TUONG THANH TOAN
// ==========================================

ThanhToan taoThanhToan(
    DonHang* donHang,
    KhachHang* kh,
    const VoucherVanChuyen& voucher
) {
    double tienHang =
        donHang->tinhTongTienHang();

    double phuPhiHang =
        donHang->tinhTongPhuPhiHangHoa();

    double phiVanChuyen =
        donHang->tinhPhiVanChuyen();

    double phiHaiQuan = 0;

    // Uu dai khach hang ap dung tren tien hang va phu phi
    double uuDaiKhachHang =
        kh->tinhTienUuDai(tienHang + phuPhiHang);

    // Voucher chi ap dung tren phi van chuyen
    double giamGiaVoucher =
        voucher.tinhTienGiam(phiVanChuyen);

    // Neu la don hang quoc te thi lay phi hai quan
    DonHangQuocTe* donQuocTe =
        dynamic_cast<DonHangQuocTe*>(donHang);

    if (donQuocTe != nullptr) {
        phiHaiQuan = donQuocTe->getPhiHaiQuan();
    }

    donHang->setUuDaiKhachHang(uuDaiKhachHang);
    donHang->setGiamGiaVoucher(giamGiaVoucher);

    ThanhToan thanhToan(
        tienHang,
        phuPhiHang,
        phiVanChuyen,
        phiHaiQuan,
        uuDaiKhachHang,
        giamGiaVoucher
    );

    return thanhToan;
}

string dinhDangTien(double tien) {
    long long soTien = llround(tien);
    bool am = soTien < 0;
    string chuoi = to_string(am ? -soTien : soTien);

    for (int i = static_cast<int>(chuoi.size()) - 3; i > 0; i -= 3) {
        chuoi.insert(static_cast<size_t>(i), ".");
    }

    return string(am ? "-" : "") + chuoi + " VND";
}

string dinhDangMaDon(const Code& maDon) {
    return maDon.getScope() + "-" +
           maDon.getService() + "-" +
           maDon.getID();
}

string dinhDangNgay(const Date& ngay) {
    ostringstream ss;
    ss << setfill('0')
       << setw(2) << ngay.getDay() << "/"
       << setw(2) << ngay.getMonth() << "/"
       << ngay.getYear();
    return ss.str();
}

// ==========================================
// HIEN THI DANH SACH DON HANG
// ==========================================

void hienThiDanhSach(
    const vector<DonHang*>& danhSachDonHang,
    const vector<KhachHang*>& danhSachKhachHang,
    const vector<VoucherVanChuyen>& danhSachVoucher,
    const vector<ThanhToan>& danhSachThanhToan
) {
    if (danhSachDonHang.empty()) {
        thongBaoThongTin("Chua co don hang nao!");
        return;
    }

    hienThiTieuDeChucNang("DANH SACH DON HANG");

    // Bang tong quan: moi don hang la mot dong.
    vector<string> tieuDeTongQuan = {
    "STT", "MA DON", "NGAY DAT", "DU KIEN GIAO",
    "LOAI DON", "GOI VC", "KHACH HANG", "TONG TIEN"
};

    vector<vector<string>> duLieuTongQuan;

    for (size_t i = 0; i < danhSachDonHang.size(); ++i) {
        DonHang* donHang = danhSachDonHang[i];
        KhachHang* khachHang = danhSachKhachHang[i];

        Code maDon = donHang->getMaDonHang();
        Date ngayDat = donHang->getNgayDatHang();

        string maDonHienThi = dinhDangMaDon(maDon);
        string ngayDatHienThi = dinhDangNgay(ngayDat);

        // Tinh khoang ngay du kien giao hang
        string ngayGiaoHienThi =
        dinhDangNgay(donHang->getNgayGiaoHangSomNhat())
        + " - " +
        dinhDangNgay(donHang->getNgayGiaoHangMuonNhat());

        bool laQuocTe =
            dynamic_cast<DonHangQuocTe*>(donHang) != nullptr;

        string goiVanChuyen = maDon.getService();
        if (goiVanChuyen == "STD") goiVanChuyen = "Co ban";
        else if (goiVanChuyen == "EXP") goiVanChuyen = "Nhanh";
        else if (goiVanChuyen == "SUP") goiVanChuyen = "Hoa toc";

        double tongTien = laQuocTe
            ? danhSachThanhToan[i].tinhTongTienQuocTe()
            : danhSachThanhToan[i].tinhTongTienTrongNuoc();

        duLieuTongQuan.push_back({
        to_string(i + 1),
        maDonHienThi,
        ngayDatHienThi,
        ngayGiaoHienThi,
        laQuocTe ? "Quoc te" : "Trong nuoc",
        goiVanChuyen,
        khachHang->getTenKhachHang(),
        dinhDangTien(tongTien)
        });
    }

    inBang(
        tieuDeTongQuan,
        duLieuTongQuan,
        {3, 13, 10, 23, 12, 9, 16, 15}
    );

    // Bang chi tiet theo tung don hang.
    for (size_t i = 0; i < danhSachDonHang.size(); ++i) {
        DonHang* donHang = danhSachDonHang[i];
        KhachHang* khachHang = danhSachKhachHang[i];
        const VoucherVanChuyen& voucher = danhSachVoucher[i];
        const ThanhToan& thanhToan = danhSachThanhToan[i];

        DonHangQuocTe* donQuocTe =
            dynamic_cast<DonHangQuocTe*>(donHang);
        
        hienThiTieuDeChucNang(
            "CHI TIET DON HANG " + to_string(i + 1)
        );

        Code maDon = donHang->getMaDonHang();
        Date ngayDat = donHang->getNgayDatHang();
        string maDonHienThi = dinhDangMaDon(maDon);
        string ngayDatHienThi = dinhDangNgay(ngayDat);

        string goiVanChuyen = maDon.getService();
        if (goiVanChuyen == "STD") goiVanChuyen = "Co ban";
        else if (goiVanChuyen == "EXP") goiVanChuyen = "Nhanh";
        else if (goiVanChuyen == "SUP") goiVanChuyen = "Hoa toc";

        vector<string> tieuDeDon = {
        "THONG TIN DON HANG", "GIA TRI"
    };

        // Xac dinh so ngay giao hang theo goi van chuyen
        int soNgayGiaoMin = 5;
        int soNgayGiaoMax = 7;

        string maGoiVanChuyen = maDon.getService();

        if (maGoiVanChuyen == "EXP") {
        soNgayGiaoMin = 3;
        soNgayGiaoMax = 4;
    }
        else if (maGoiVanChuyen == "SUP") {
        soNgayGiaoMin = 1;
        soNgayGiaoMax = 2;
    }

        // Tinh ngay giao hang
        string ngayDuKienGiao =
        dinhDangNgay(ngayDat.congNgay(soNgayGiaoMin))
        + " - " +
        dinhDangNgay(ngayDat.congNgay(soNgayGiaoMax));

        vector<vector<string>> duLieuDon = {
        {"Ma don hang", maDonHienThi},
        {"Ngay dat hang", ngayDatHienThi},
        {"Pham vi van chuyen", donQuocTe ? "Quoc te" : "Trong nuoc"},
        {"Goi van chuyen", goiVanChuyen},
        {"Ngay du kien giao hang", ngayDuKienGiao}
    };

        if (donQuocTe != nullptr) {
            duLieuDon.push_back({
                "Phi hai quan", dinhDangTien(donQuocTe->getPhiHaiQuan())
            });
        }

        inBang(tieuDeDon, duLieuDon, {26, 34});

        // Danh sach hang hoa cua don.
        hienThiTieuDeMuc("DANH SACH HANG HOA");
        vector<string> tieuDeHang = {
            "TEN HANG HOA", "CAN NANG (KG)", "GIA TIEN", "LOAI HANG", "PHU PHI"
        };
        vector<vector<string>> duLieuHang;
        vector<HangHoa*> danhSachHang = donHang->getDanhSachHangHoa();

        for (size_t j = 0; j < danhSachHang.size(); ++j) {
            if (danhSachHang[j] == nullptr) continue;

            ostringstream canNang;
            canNang << fixed << setprecision(2)
                    << danhSachHang[j]->getCanNang();

            string loaiHang = "Thuong";
            if (dynamic_cast<HangHoaDacBiet*>(danhSachHang[j]) != nullptr) {
                loaiHang = "Dac biet";
            }
            else if (dynamic_cast<HangHoaCongKenh*>(danhSachHang[j]) != nullptr) {
                loaiHang = "Cong kenh";
            }

            duLieuHang.push_back({
                danhSachHang[j]->getTenHang(),
                canNang.str(),
                dinhDangTien(danhSachHang[j]->getGiaTien()),
                loaiHang,
                dinhDangTien(danhSachHang[j]->tinhPhuPhi())
            });
        }

        if (duLieuHang.empty()) {
            duLieuHang.push_back({"Khong co hang hoa", "-", "-", "-", "-"});
        }

        inBang(tieuDeHang, duLieuHang, {18, 12, 15, 14, 15});

        // Thong tin van chuyen lay truc tiep tu lop co so DonHang
        hienThiTieuDeMuc("THONG TIN VAN CHUYEN");

        string phuongThucVC =
        donHang->getThongTinVanChuyen().getPhuongThuc();

        // Chuyen ten phuong thuc sang dang hien thi tren giao dien
        if (phuongThucVC == "CoBan") {
        phuongThucVC = "Co ban";
        }
        else if (phuongThucVC == "HoaToc") {
        phuongThucVC = "Hoa toc";
        }
        vector<string> tieuDeVC = {"THONG TIN VAN CHUYEN", "GIA TRI"};
        vector<vector<string>> duLieuVC = {
            {"Phuong thuc van chuyen", phuongThucVC},
            {"Tien van chuyen", dinhDangTien(donHang->tinhPhiVanChuyen())}
        };
        inBang(tieuDeVC, duLieuVC, {26, 34});

        // Thong tin khach hang.
        hienThiTieuDeMuc("THONG TIN KHACH HANG");
        vector<string> tieuDeKH = {"THONG TIN KHACH HANG", "GIA TRI"};
        vector<vector<string>> duLieuKH = {
            {"Ma khach hang", khachHang->getMaKH()},
            {"Ten khach hang", khachHang->getTenKhachHang()},
            {"Dia chi", khachHang->getDiaChi()},
            {"Tong chi tieu", dinhDangTien(khachHang->getTongChiTieu())},
            {"Xep hang", khachHang->xepHang()}
        };

        ostringstream uuDai;
        uuDai << fixed << setprecision(0)
              << khachHang->tinhUuDai() * 100 << "%";
        duLieuKH.push_back({"Uu dai khach hang", uuDai.str()});

        inBang(tieuDeKH, duLieuKH, {26, 34});

        // Thong tin voucher.
        hienThiTieuDeMuc("THONG TIN VOUCHER");
        vector<string> tieuDeVoucher = {
            "THONG TIN VOUCHER", "GIA TRI"
        };
        vector<vector<string>> duLieuVoucher = {
            {"Ma voucher", voucher.getMaVoucher()},
            {"Loai voucher", voucher.getLoaiVoucher()},
            {"Gia tri giam", dinhDangTien(voucher.getGiaTriGiam())}
        };
        inBang(tieuDeVoucher, duLieuVoucher, {26, 34});

        // Chi tiet thanh toan dung cung ham xuat bang o ThanhToan.
        thanhToan.xuatThanhToan(donQuocTe != nullptr);
    }
}

// ==========================================
// MENU CHINH
// ==========================================

void menuChinh() {
    hienThiTieuDe();
    hienThiMenu();
}


// ==========================================
// MAIN
// ==========================================

int main() {
    khoiTaoMauConsole();

    // Danh sach don hang
    vector<DonHang*> danhSachDonHang;

    // Danh sach khach hang
    vector<KhachHang*> danhSachKhachHang;

    // Danh sach voucher
    vector<VoucherVanChuyen> danhSachVoucher;

    // Danh sach thanh toan
    vector<ThanhToan> danhSachThanhToan;

    int luaChon;

    do {
        menuChinh();
        cin >> luaChon;

        switch (luaChon) {

        // ----------------------------------
        // TAO DON HANG TRONG NUOC
        // ----------------------------------

        case 1: {
            DonHang* donHang =
                taoDonHangTrongNuoc();

            KhachHang* kh =
                taoKhachHang();

            if (kh == nullptr) {
                delete donHang;
                break;
            }

            VoucherVanChuyen voucher =
                taoVoucher();

            ThanhToan thanhToan =
                taoThanhToan(donHang, kh, voucher);

            danhSachDonHang.push_back(donHang);
            danhSachKhachHang.push_back(kh);
            danhSachVoucher.push_back(voucher);
            danhSachThanhToan.push_back(thanhToan);

            thongBaoThanhCong(
                "Tao don hang va thanh toan thanh cong!"
            );

            thanhToan.xuatThanhToan(false);

            break;
        }

        // ----------------------------------
        // TAO DON HANG QUOC TE
        // ----------------------------------

        case 2: {
            DonHang* donHang =
                taoDonHangQuocTe();

            KhachHang* kh =
                taoKhachHang();

            if (kh == nullptr) {
                delete donHang;
                break;
            }

            VoucherVanChuyen voucher =
                taoVoucher();

            ThanhToan thanhToan =
                taoThanhToan(donHang, kh, voucher);

            danhSachDonHang.push_back(donHang);
            danhSachKhachHang.push_back(kh);
            danhSachVoucher.push_back(voucher);
            danhSachThanhToan.push_back(thanhToan);

            thongBaoThanhCong(
                "Tao don hang quoc te va thanh toan thanh cong!"
            );

            thanhToan.xuatThanhToan(true);

            break;
        }

        // ----------------------------------
        // XEM DANH SACH DON HANG
        // ----------------------------------

        case 3: {
            hienThiDanhSach(
                danhSachDonHang,
                danhSachKhachHang,
                danhSachVoucher,
                danhSachThanhToan
            );

            break;
        }

        // ----------------------------------
        // THOAT
        // ----------------------------------

        case 0:
            hienThiLoiChao();
            break;

        default:
            thongBaoLoi("Lua chon khong hop le!");
        }

    } while (luaChon != 0);

    // ======================================
    // GIAI PHONG BO NHO
    // ======================================

    for (size_t i = 0;
         i < danhSachDonHang.size(); i++) {

        vector<HangHoa*> dsHangHoa =
            danhSachDonHang[i]->getDanhSachHangHoa();

        for (size_t j = 0;
             j < dsHangHoa.size(); j++) {

            delete dsHangHoa[j];
        }

        delete danhSachDonHang[i];
        delete danhSachKhachHang[i];
    }

    return 0;
}
