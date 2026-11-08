#pragma once
#include<iostream>
#include<string>
using namespace std;

class HangHoa {
private:
    string m_sTenHang;
    double m_dCanNang;
    double m_dGiaTien;

public:
    // Constructor
    HangHoa();
    HangHoa(string sTenHang, double dCanNang, double dGiaTien);
    HangHoa(const HangHoa& hanghoa);
    virtual ~HangHoa();
    friend istream& operator>>(istream& in, HangHoa& hanghoa);
    friend ostream& operator<<(ostream& out, const HangHoa& hanghoa);
    virtual void nhapHangHoa();
    virtual void xuatHangHoa() const;

    // Getter
    string getTenHang() const;
    double getCanNang() const;
    double getGiaTien() const;

    // Setter
    void setTenHang(string sTenHang);
    void setCanNang(double dCanNang);
    void setGiaTien(double dGiaTien);
    
    // Da hinh
    virtual double tinhPhuPhi() const = 0;
};

//_____________CLASS HANGHOATHUONG________________________
class HangHoaThuong : public HangHoa {
public:
    HangHoaThuong();
    HangHoaThuong(string sTenHang, double dCanNang, double dGiaTien);
    HangHoaThuong(const HangHoaThuong& hanghoa);

    double tinhPhuPhi() const override;
};

//_____________CLASS HANGHOADACBIET________________________
class HangHoaDacBiet : public HangHoa {
public:
    HangHoaDacBiet();
    HangHoaDacBiet(string sTenHang, double dCanNang, double dGiaTien);
    HangHoaDacBiet(const HangHoaDacBiet& hanghoa);

    double tinhPhuPhi() const override;
};

//_____________CLASS HANGHOACONGKENH________________________
class HangHoaCongKenh : public HangHoa {
public:
    HangHoaCongKenh();
    HangHoaCongKenh(string sTenHang, double dCanNang, double dGiaTien);
    HangHoaCongKenh(const HangHoaCongKenh& hanghoa);

    double tinhPhuPhi() const override;
};
