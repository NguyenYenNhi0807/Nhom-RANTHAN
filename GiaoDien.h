#ifndef GIAODIEN_H
#define GIAODIEN_H

#include <iostream>
#include <string>
#include <vector>

namespace Mau {
    const std::string RESET = "\033[0m";
    const std::string DAM = "\033[1m";

    const std::string DO = "\033[91m";
    const std::string XANH_LA = "\033[92m";
    const std::string VANG = "\033[93m";

    const std::string XANH_DUONG = "\033[96m";
    const std::string XANH_NGOC = "\033[36m";

    const std::string TIM = "\033[95m";
    const std::string TRANG = "\033[97m";
    const std::string XAM = "\033[90m";
    const std::string CAM = "\033[38;5;214m";
}

// Kich hoat mau cho console
void khoiTaoMauConsole();

// Cac ham hien thi giao dien
void hienThiTieuDe();
void hienThiMenu();
void hienThiTieuDeMuc(const std::string& tieuDe);

// Tieu de chuc nang va cac muc nho
void hienThiTieuDeChucNang(const std::string& tieuDe);
void hienThiDongLuaChon(int so, const std::string& noiDung);
void hienThiNhapLuaChon();

// Cac ham thong bao
void thongBaoThanhCong(const std::string& noiDung);
void thongBaoLoi(const std::string& noiDung);
void thongBaoThongTin(const std::string& noiDung);
void hienThiLoiChao();

// ==========================================
// CAC HAM VE BANG CONSOLE
// ==========================================

// Ve duong ngang cua bang
void veDuongTren(const std::vector<int>& doRong);
void veDuongGiua(const std::vector<int>& doRong);
void veDuongDuoi(const std::vector<int>& doRong);

// In mot dong du lieu
void inDongBang(
    const std::vector<std::string>& duLieu,
    const std::vector<int>& doRong,
    bool tieuDe = false
);

// In toan bo bang
void inBang(
    const std::vector<std::string>& tieuDe,
    const std::vector<std::vector<std::string>>& duLieu,
    const std::vector<int>& doRong
);

#endif