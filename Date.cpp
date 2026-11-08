#include "Date.h"

// Constructor
Date::Date(){
    m_iDay=1;
    m_iMonth=1;
    m_iYear=2000;
}
Date::Date(int iDay, int iMonth, int iYear){
    m_iDay=iDay;
    m_iMonth=iMonth;
    m_iYear=iYear;
}
Date::Date(const Date &date){
    m_iDay=date.m_iDay;
    m_iMonth=date.m_iMonth;
    m_iYear=date.m_iYear;
}
Date& Date::operator=(const Date& date) {
    if (this != &date) {
        m_iDay = date.m_iDay;
        m_iMonth = date.m_iMonth;
        m_iYear = date.m_iYear;
    }

    return *this;
}

// Destructor
Date::~Date(){

}

// Getter
int Date::getDay() const{
    return m_iDay;
}
int Date::getMonth() const{
    return m_iMonth;
}
int Date::getYear() const{
    return m_iYear;
}

// Setter
void Date::setDay(int iDay){
    m_iDay=iDay;
}
void Date::setMonth(int iMonth){
    m_iMonth=iMonth;
}
void Date::setYear(int iYear){
    m_iYear=iYear;
}

// Nhap xuat
istream& operator>>(istream& in, Date &date){
    string temp;
    in>>temp;
    date.m_iDay= stoi(temp.substr(0,2));
    date.m_iMonth= stoi(temp.substr(3,2));
    date.m_iYear= stoi(temp.substr(6,4));
    return in;
}
ostream& operator<<(ostream& out, Date date){
    out<<date.m_iDay<<"/"<<date.m_iMonth<<"/"<<date.m_iYear<<endl;
    return out;
}
void Date::nhapDate(){
    string temp, b;
    cin>>temp;
    m_iDay= stoi(temp.substr(0,2));
    m_iMonth= stoi(temp.substr(3,2));
    m_iYear= stoi(temp.substr(6,4));
}
void Date::xuatDate(){
    cout<<m_iDay<<"/"<<m_iMonth<<"/"<<m_iYear<<endl;
}

// Xu ly
Date Date::congNgay(int soNgay) const {
    int day = m_iDay;
    int month = m_iMonth;
    int year = m_iYear;

    const int soNgayTrongThang[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (month < 1 || month > 12 || day < 1)
        return *this;

    while (soNgay > 0) {
        int maxDay = soNgayTrongThang[month - 1];

        // Kiem tra nam nhuan
        bool namNhuan = (year % 400 == 0) ||
                        (year % 4 == 0 && year % 100 != 0);

        if (month == 2 && namNhuan)
            maxDay = 29;

        if (day < maxDay) {
            ++day;
        }
        else {
            day = 1;
            ++month;

            if (month > 12) {
                month = 1;
                ++year;
            }
        }

        --soNgay;
    }

    return Date(day, month, year);
}
