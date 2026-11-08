#include "Code.h"
#include "GiaoDien.h"

#include <vector>

// Constructor
Code::Code(){
    m_sScope="DED";
    m_sService="STD";
    m_sID="00001";
}
Code::Code(string sScope, string sService, string sID){
    m_sScope=sScope;
    m_sService=sService;
    m_sID=sID;
}
Code::Code(const Code &code){
    m_sScope=code.m_sScope;
    m_sService=code.m_sService;
    m_sID=code.m_sID;
}
Code& Code::operator=(const Code& code) {
    if (this != &code) {
        m_sScope = code.m_sScope;
        m_sService = code.m_sService;
        m_sID = code.m_sID;
    }

    return *this;
}

// Destructor
Code::~Code(){

}

// Getter
string Code::getScope() const{
    return m_sScope;
}
string Code::getService() const{
    return m_sService;
}
string Code::getID() const{
    return m_sID;
}

// Setter
void Code::setScope(string sScope){
    m_sScope=sScope;
}
void Code::setService(string sService){
    m_sService=sService;
}
void Code::setID(string sID){
    m_sID=sID;
}

// Nhap xuat
istream& operator>>(istream& in, Code &code){
    string temp;
    in>>temp;
    if (temp.length()!=13 || temp[3]!='-' || temp[7]!='-') {
        cout<<"Ma don hang khong dung dinh dang!";
        return in;
    }
    string scope=temp.substr(0,3);
    string service=temp.substr(4,3);
    string id=temp.substr(8,5);
    if ((scope!="DED" && scope!="IED") || (service!="STD" && service!="EXP" && service!="SUP")) {
        cout<<"Ma don hang khong hop le!";
        return in;
    }
    code.m_sScope=scope;
    code.m_sService=service;
    code.m_sID=id;
    return in;
}
ostream& operator<<(ostream& out, Code code){
    out << code.m_sScope << "-"
        << code.m_sService << "-"
        << code.m_sID << endl;
    out<<"[Pham vi van chuyen]: ";
    if(code.m_sScope=="DED")
        out<<"Trong nuoc";
    else if(code.m_sScope=="IED")
        out<<"Quoc te";

    out<<endl<<"[Goi van chuyen]: ";
    if(code.m_sService=="STD")
        out<<"Giao hang co ban - Standard";
    else if(code.m_sService=="EXP")
        out<<"Giao hang nhanh - Express";
    else if(code.m_sService=="SUP")
        out<<"Giao hang hoa toc - Super Express	";

    out<<endl<<"[Ma dinh danh]: "<<code.m_sID<<endl;
    return out;
}
void Code::nhapCode(string scope) {
    int luaChon;
    m_sScope = scope;

    hienThiTieuDeMuc("CHON GOI VAN CHUYEN");
    vector<string> tieuDeGoiVC = {
        "PHIM", "GOI VAN CHUYEN"
    };
    vector<vector<string>> dsGoiVC = {
        {"[1]", "Co ban - Standard"},
        {"[2]", "Nhanh - Express"},
        {"[3]", "Hoa toc - Super Express"}
    };
    inBang(tieuDeGoiVC, dsGoiVC, {12, 34});
    hienThiNhapLuaChon();
    cin >> luaChon;

    while (luaChon < 1 || luaChon > 3) {
        cout << "Lua chon khong hop le! Nhap lai: ";
        cin >> luaChon;
    }
    switch (luaChon) {
        case 1:
            m_sService = "STD";
            break;
        case 2:
            m_sService = "EXP";
            break;
        case 3:
            m_sService = "SUP";
            break;
    }
    
    cout << Mau::CAM << Mau::DAM
         << "Nhap ma dinh danh (5 chu so): "
         << Mau::RESET;
    cin >> m_sID;

    while (m_sID.length() != 5 ||
           m_sID.find_first_not_of("0123456789") != string::npos) {

        cout << Mau::DO << Mau::DAM
             << "Ma dinh danh khong hop le! Nhap lai: "
             << Mau::RESET;
        cin >> m_sID;
    }

    cout << "\nMa don hang cua ban: "
         << m_sScope << "-"
         << m_sService << "-"
         << m_sID << endl;
}
void Code::xuatCode() const{
    cout << m_sScope << "-"
        << m_sService << "-"
        << m_sID << endl;
    cout<<"[Pham vi van chuyen]: ";
    if(m_sScope=="DED")
        cout<<"Trong nuoc";
    else if(m_sScope=="IED")
        cout<<"Quoc te";

    cout<<endl<<"[Goi van chuyen]: ";
    if(m_sService=="STD")
        cout<<"Giao hang co ban - Standard";
    else if(m_sService=="EXP")
        cout<<"Giao hang nhanh - Express";
    else if(m_sService=="SUP")
        cout<<"Giao hang hoa toc - Super Express	";

    cout<<endl<<"[Ma dinh danh]: "<<m_sID<<endl;
}



