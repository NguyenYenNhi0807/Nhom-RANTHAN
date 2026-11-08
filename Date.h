#pragma once
#include<iostream>
#include<string>
using namespace std;

class Date{
    private:
        int m_iDay, m_iMonth, m_iYear;
    public:
        // Constructor
        Date();
        Date(int iDay, int iMonth, int iYear);
        Date(const Date &date);
        Date& operator=(const Date& date);

        // Destructor
        ~Date();
        
        // Getter
        int getDay() const;
        int getMonth() const;
        int getYear() const;

        // Setter
        void setDay(int iDay);
        void setMonth(int iMonth);
        void setYear(int iYear);

        // Nhapxuat
        friend istream& operator>>(istream& in, Date &date);
        friend ostream& operator<<(ostream& out, Date date);
        void nhapDate();
        void xuatDate();

        // Xu ly
        Date congNgay(int soNgay) const;
};