#include <bits/stdc++.h>
#include "models.h"
#include "vattu.h"
using namespace std;


// =============== MAIN ===============

int main(){
    NodeVT* root = nullptr;

    // ========== 1. THEM VAT TU ==========
    cout << "\n===== 1. THEM VAT TU =====\n";

    Vattu a{"VT050", "Xi mang", "Bao", 50};
    Vattu b{"VT030", "Gach", "Vien", 1000};
    Vattu c{"VT080", "Sat", "Cay", 100};
    Vattu d{"VT020", "Cat", "Khoi", 200};
    Vattu e{"VT040", "Da", "Khoi", 300};
    Vattu f{"VT060", "Thep", "Cay", 150};
    Vattu g{"VT090", "Son", "Thung", 80};
    Vattu h{"VT070", "Ong nhua", "Met", 400};

    themvattu(root, a);
    themvattu(root, b);
    themvattu(root, c);
    themvattu(root, d);
    themvattu(root, e);
    themvattu(root, f);
    themvattu(root, g);
    themvattu(root, h);

    cout << "Them VT030 trung ma: "
         << themvattu(root, b) << '\n';

    // ========== 2. IN DANH SACH ==========
    cout << "\n===== 2. DANH SACH VAT TU =====\n";
    invattu(root);

    // ========== 3. TIM VAT TU ==========
    cout << "\n===== 3. TIM VAT TU =====\n";

    NodeVT* p = timvattu(root, "VT030");

    if(p != nullptr) {
        cout << "Tim thay: " << p->info.MAVT
             << " - " << p->info.TENVT << '\n';
    }

    cout << "Tim VT999: "
         << (timvattu(root, "VT999") != nullptr) << '\n';

    // ========== 4. HIEU CHINH ==========
    cout << "\n===== 4. HIEU CHINH =====\n";

    cout << "Hieu chinh VT030: "
         << hieuchinhvattu(root, "VT030", "Gach do", "Vien")
         << '\n';

    p = timvattu(root, "VT030");

    if(p != nullptr) {
        cout << "Ten moi: " << p->info.TENVT << '\n';
        cout << "So luong ton: " << p->info.SOLUONGTON << '\n';
    }

    // ========== 5. XOA VAT TU ==========
    cout << "\n===== 5. XOA VAT TU =====\n";

    // Truong hop 1: Xoa node la
    cout << "Xoa VT020 (node la): "
         << xoavattu(root, "VT020") << '\n';

    // Truong hop 2: Xoa node co 1 con
    cout << "Xoa VT060 (co 1 con phai): "
         << xoavattu(root, "VT060") << '\n';

    // Truong hop 3: Xoa node co 2 con
    cout << "Xoa VT050 (node goc co 2 con): "
         << xoavattu(root, "VT050") << '\n';

    if(root != nullptr)
        cout << "Root moi: " << root->info.MAVT << '\n';

    // Xoa ma khong ton tai
    cout << "Xoa VT999: "
         << xoavattu(root, "VT999") << '\n';

    cout << "\nDANH SACH SAU KHI XOA:\n";
    invattu(root);

    // ========== 6. GIAI PHONG BST ==========
    cout << "\n===== 6. GIAI PHONG CAY =====\n";

    giaiphongcay(root);

    if(root == nullptr)
        cout << "Da giai phong BST thanh cong!\n";
    else
        cout << "Giai phong that bai!\n";

    // Goi lai de kiem tra cay rong
    giaiphongcay(root);

    cout << "Kiem tra root == nullptr: "
         << (root == nullptr) << '\n';

    return 0;
}
