#pragma once
#include <string>

// 1. VAT TU - BST
struct Vattu{
    std:: string MAVT;
    std:: string TENVT;
    std:: string DVT;
    int SOLUONGTON;
};

struct NodeVT{
    Vattu info;
    NodeVT* left = nullptr;
    NodeVT* right = nullptr;
};

// 2. CHI TIET HOA DON - LINKED LIST
struct CT_HOADON{
    std::string MAVT;
    int Soluong;
    float Dongia;
    float VAT;
};

struct NodeCTHD{
    CT_HOADON info;
    NodeCTHD* next = nullptr;
};

// 3. HOA DON - LINKED LIST
struct HOADON{
    std:: string SoHD;
    std:: string NLHD;
    char LOAI;
    NodeCTHD* dscthd = nullptr;
};
struct NodeHD{
    HOADON info;
    NodeHD* next = nullptr;
};

// 4. NHAN VIEN - MANG CON TRO
struct Nhanvien{
    std:: string MANV;
    std:: string HO;
    std:: string TEN;
    std:: string PHAI;
    NodeHD* dshd = nullptr;
};

struct DSNhanVien{
    int n{0};
    Nhanvien* nodes[500] = {};
};
