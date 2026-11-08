#pragma once
#include<iostream>
#include<string>
using namespace std;

class Code{
    private:
        string m_sScope, m_sService, m_sID;
    public:
        // Constructor
        Code();
        Code(string sScope, string sService, string sID);
        Code(const Code &code);
        Code& operator=(const Code& code);

        // Destructor
        ~Code();
        
        // Getter
        string getScope() const;
        string getService() const;
        string getID() const;

        // Setter
        void setScope(string sScope);
        void setService(string sService);
        void setID(string sID);

        // Nhap xuat
        friend istream& operator>>(istream& in, Code &code);
        friend ostream& operator<<(ostream& out, Code code);
        void nhapCode(string scope);
        void xuatCode() const;
};

