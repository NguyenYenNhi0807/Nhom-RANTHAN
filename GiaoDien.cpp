#include "GiaoDien.h"
#include <iomanip>
#include <algorithm>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// In mot dong van ban can giua theo do rong cho truoc
void inDongCanGiua(const string& noiDung, int doRong) {
    int khoangTrang = doRong - (int)noiDung.length();

    if (khoangTrang < 0) {
        cout << noiDung;
        return;
    }

    int trai = khoangTrang / 2;
    int phai = khoangTrang - trai;

    cout << string(trai, ' ')
         << noiDung
         << string(phai, ' ');
}

// Kich hoat mau ANSI tren Windows
void khoiTaoMauConsole() {
#ifdef _WIN32
    system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Dam bao ky tu Unicode cua bang va mau ANSI hien thi dung tren Windows.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    if (hConsole != INVALID_HANDLE_VALUE) {
        DWORD mode = 0;

        if (GetConsoleMode(hConsole, &mode)) {
            SetConsoleMode(
                hConsole,
                mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING
            );
        }
    }
#endif
}

// Tieu de chuong trinh
void hienThiTieuDe() {
    const int rong = 58;
    const int rongTrong = 54;

    cout << "\n";
    cout << Mau::XANH_DUONG << Mau::DAM;

    cout << string(rong, '=') << "\n";

    cout << "||";
    inDongCanGiua("QUAN LY DON HANG", rongTrong);
    cout << "||\n";

    cout << "||";
    inDongCanGiua("VAN CHUYEN HANG HOA", rongTrong);
    cout << "||\n";

    cout << string(rong, '=');

    cout << Mau::RESET << "\n\n";
}

// Menu chinh
void hienThiMenu() {
    cout << Mau::VANG << Mau::DAM;
    inDongCanGiua("MENU CHINH", 58);
    cout << Mau::RESET << "\n\n";

    vector<string> tieuDe = {"PHIM", "CHUC NANG"};
    vector<vector<string>> duLieu = {
        {"[1]", "Tao don hang trong nuoc"},
        {"[2]", "Tao don hang quoc te"},
        {"[3]", "Xem danh sach don hang"},
        {"[0]", "Thoat chuong trinh"}
    };

    inBang(tieuDe, duLieu, {10, 34});

    cout << Mau::VANG << Mau::DAM
         << "Nhap lua chon: "
         << Mau::RESET;
}


// Tieu de chuc nang cap lon - mau xanh
void hienThiTieuDeChucNang(const string& tieuDe) {
    cout << "\n"
         << Mau::XANH_DUONG << Mau::DAM
         << "========== " << tieuDe << " =========="
         << Mau::RESET << "\n";
}

// Tieu de muc nho - mau vang cam
void hienThiTieuDeMuc(const string& tieuDe) {
    cout << "\n"
         << Mau::CAM << Mau::DAM
         << "---------- " << tieuDe << " ----------"
         << Mau::RESET << "\n";
}

// Dong lua chon - so mau xanh ngoc
void hienThiDongLuaChon(int so, const string& noiDung) {
    cout << Mau::XANH_NGOC << "[" << so << "] "
         << Mau::TRANG << noiDung
         << Mau::RESET << "\n";
}

// Dong nhap lua chon - mau vang cam
void hienThiNhapLuaChon() {
    cout << Mau::CAM << Mau::DAM
         << "Nhap lua chon: "
         << Mau::RESET;
}

// Thong bao thanh cong
void thongBaoThanhCong(const string& noiDung) {
    cout << Mau::XANH_LA << Mau::DAM
         << "\n[THANH CONG] "
         << noiDung
         << Mau::RESET << "\n";
}

// Thong bao loi
void thongBaoLoi(const string& noiDung) {
    cout << Mau::DO << Mau::DAM
         << "\n[LOI] "
         << noiDung
         << Mau::RESET << "\n";
}

// Thong bao thong tin
void thongBaoThongTin(const string& noiDung) {
    cout << Mau::VANG
         << "\n[THONG TIN] "
         << noiDung
         << Mau::RESET << "\n";
}

// Loi chao khi thoat
void hienThiLoiChao() {
    cout << Mau::XANH_LA << Mau::DAM
         << "\nCam on ban da su dung chuong trinh!\n"
         << Mau::RESET;
}

// ==========================================
// BO HAM VE BANG CONSOLE
// ==========================================

void veDuong(
    const vector<int>& doRong,
    const string& dauTrai,
    const string& dauGiua,
    const string& dauPhai
) {
    cout << dauTrai;

    for (size_t i = 0; i < doRong.size(); i++) {
        for (int j = 0; j < doRong[i] + 2; j++)
            cout << "─";

        if (i != doRong.size() - 1)
            cout << dauGiua;
    }

    cout << dauPhai << "\n";
}

void veDuongTren(const vector<int>& doRong) {
    veDuong(doRong, "┌", "┬", "┐");
}

void veDuongGiua(const vector<int>& doRong) {
    veDuong(doRong, "├", "┼", "┤");
}

void veDuongDuoi(const vector<int>& doRong) {
    veDuong(doRong, "└", "┴", "┘");
}


// Dem so ky tu UTF-8
int demKyTuUTF8(const string& s) {
    int dem = 0;

    for (unsigned char c : s) {
        if ((c & 0xC0) != 0x80) {
            dem++;
        }
    }

    return dem;
}

// Cat chuoi theo so ky tu UTF-8
string catKyTuUTF8(const string& s, int soKyTu) {
    int dem = 0;
    size_t viTri = 0;

    while (viTri < s.size() && dem < soKyTu) {
        unsigned char c = s[viTri];

        if ((c & 0xC0) != 0x80) {
            dem++;
        }

        viTri++;
    }

    return s.substr(0, viTri);
}

void inDongBang(
    const vector<string>& duLieu,
    const vector<int>& doRong,
    bool tieuDe
) {
    cout << "│";

    for (size_t i = 0; i < doRong.size(); i++) {
        string noiDung = (i < duLieu.size()) ? duLieu[i] : "";

        int soKyTu = demKyTuUTF8(noiDung);

        if (soKyTu > doRong[i]) {
            noiDung = catKyTuUTF8(noiDung, doRong[i]);
            soKyTu = doRong[i];
        }

        int khoangTrang = doRong[i] - soKyTu;

        cout << " ";

        if (tieuDe) {
            cout << Mau::VANG << Mau::DAM;
        }
        else if (i == 0 && noiDung == "[0]") {
            cout << Mau::DO << Mau::DAM;
        }
        else if (i == 0 &&
                (noiDung == "[1]" ||
                noiDung == "[2]" ||
                noiDung == "[3]" ||
                noiDung == "[4]")) {
            cout << Mau::XANH_LA << Mau::DAM;
        }

        // Cac o chua so tien VND se duoc can phai
        if (noiDung.find("VND") != string::npos) {
            cout << string(khoangTrang, ' ')
                << noiDung;
        }
        else {
            cout << noiDung
                << string(khoangTrang, ' ');
        }

        cout << Mau::RESET << " │";
    }

    cout << "\n";
}

void inBang(
    const vector<string>& tieuDe,
    const vector<vector<string>>& duLieu,
    const vector<int>& doRong
) {
    // Tu dong mo rong cot theo noi dung dai nhat, khong cat ten/ dia chi.
    vector<int> doRongThucTe = doRong;

    for (size_t i = 0; i < tieuDe.size() && i < doRongThucTe.size(); ++i) {
        doRongThucTe[i] = max(doRongThucTe[i], demKyTuUTF8(tieuDe[i]));
    }

    for (const auto& dong : duLieu) {
        for (size_t i = 0; i < dong.size() && i < doRongThucTe.size(); ++i) {
            doRongThucTe[i] = max(doRongThucTe[i], demKyTuUTF8(dong[i]));
        }
    }

    veDuongTren(doRongThucTe);
    inDongBang(tieuDe, doRongThucTe, true);
    veDuongGiua(doRongThucTe);

    for (size_t i = 0; i < duLieu.size(); i++) {
        inDongBang(duLieu[i], doRongThucTe, false);
        if (i + 1 < duLieu.size()) {
            veDuongGiua(doRongThucTe);
        }
    }

    veDuongDuoi(doRongThucTe);
}
