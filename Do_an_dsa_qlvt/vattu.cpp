#include "vattu.h"
#include <algorithm>
#include <iostream>
using namespace std;

// ===== TAO VA QUAN LY CAY BST VAT TU =====
bool themvattu(NodeVT*& root, const Vattu& vt){
    if(root == nullptr){
        NodeVT* p = new NodeVT{vt, nullptr, nullptr};
        root = p;
        return true;
    }
    
    if(root->info.MAVT == vt.MAVT) return false;
    
    if(vt.MAVT < root->info.MAVT) return themvattu(root->left, vt);
    
    return themvattu(root->right, vt);
    
}

NodeVT* timvattu(NodeVT* root, const string& MAVT){
    if(root == nullptr) return root;
    
    if(MAVT == root->info.MAVT) return root;
    
    if(MAVT < root->info.MAVT) return timvattu(root->left, MAVT);
    
    return timvattu(root->right, MAVT);
}

//hieu chinh khong duoc sua so luong ton
bool hieuchinhvattu(NodeVT* root, const string& MAVT,
                                  const string& tenmoi,                 
                                  const string& dvtmoi){
                       
    NodeVT* p = timvattu(root, MAVT);
    if(p == nullptr)
         return false;
         
    p->info.TENVT = tenmoi;
    p->info.DVT = dvtmoi;
    
    return true;
}

bool xoavattu(NodeVT*& root, const string& MAVT){
    if(root == nullptr) return false;
    
    if(MAVT < root->info.MAVT)
        return xoavattu(root->left, MAVT);
    
    if(MAVT > root->info.MAVT)
        return xoavattu(root->right, MAVT);
    
    //truong hop node la
    if(root->left == nullptr && root->right == nullptr){
        delete root;
        root = nullptr;
        return true;
    }
    
    //truong hop la node cha co 1 con
    if(root->left != nullptr && root->right == nullptr){
        NodeVT* p = root;
        root = root->left;
        delete p;
        p = nullptr;
        return true;
    }
    if(root->left == nullptr && root->right != nullptr){
        NodeVT* p = root;
        root = root->right;
        delete p;
        p = nullptr;
        return true;
    }
    // truong hop co 2 node con(tim node con nho nhat ben phai thay the)
    NodeVT* p = timmin(root->right);
    string mathaythe = p->info.MAVT;
    root->info = p->info;
    return xoavattu(root->right, mathaythe);
}

NodeVT* timmin(NodeVT* root){
    if(root == nullptr || root->left == nullptr) return root;
    
    return timmin(root->left);
}

// ===== IN DANH SACH VAT TU VA HAM CHUC NANG =====

void layvattu(NodeVT* root, vector<Vattu>& ds){
    if(root == nullptr) return;
    
    layvattu(root->left,ds);
    ds.push_back(root->info);
    layvattu(root->right,ds);
}

bool sosanhten(const Vattu& a, const Vattu& b){
    if(a.TENVT != b.TENVT) return a.TENVT < b.TENVT;
    
    return a.MAVT < b.MAVT;
}

void invattu(NodeVT* root){
    vector<Vattu> ds;
    layvattu(root, ds);
    
    sort(ds.begin(), ds.end(), sosanhten);
    
    for(size_t i{0}; i < ds.size(); i++){
        cout << ds[i].MAVT << endl;
        cout << ds[i].TENVT << endl;
        cout << ds[i].DVT << endl;
        cout << ds[i].SOLUONGTON << endl;
    }
}

// ===== GIAI PHONG CAY =====
void giaiphongcay(NodeVT*& root){
    if(root == nullptr) return;
    
    giaiphongcay(root->left);
    giaiphongcay(root->right);
    delete root;
    root = nullptr;
}