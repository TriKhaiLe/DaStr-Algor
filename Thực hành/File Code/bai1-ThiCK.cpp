#include <iostream>
#include<string>
using namespace std;

class Data {
public:
    long maSP, soLuong, namSX, donGia1SP;
    string tenSP;
};

class MatHang {
public:
    Data info;
    MatHang* pnext;
};

class List {
public:
    MatHang* phead;
    MatHang* ptail;
};

void init(List& l) {
    l.phead = l.ptail = NULL;
}

void addMatHang(List& l, MatHang* p) {
    if (l.ptail == NULL) {
        l.phead = l.ptail = p;
    }
    else {
        l.ptail->pnext = p;
        l.ptail = l.ptail->pnext;
    }


}

MatHang* newMatHang() {
    MatHang* p = new MatHang;
    p->pnext = NULL;

    cin >> p->info.maSP >> p->info.tenSP 
        >> p->info.soLuong >> p->info.namSX 
        >> p->info.donGia1SP;

    return p;
}

void xuat(List l) {
    MatHang* p = new MatHang;
    p = l.phead;

    long i = 1;

    while (p != NULL) {
        cout << "\nThong tin mat hang thu " << i << ":";
        cout << "\n" << p->info.maSP << "\n" << p->info.tenSP
            << "\n" << p->info.soLuong << "\n" << p->info.namSX
            << "\n" << p->info.donGia1SP;

        i++;
        p = p->pnext;
    }
}

void timGiaCaoNhat(List l) {
    MatHang* p = new MatHang;
    p = l.phead;

    MatHang* pLuuTru = new MatHang;

    long max = 0;

    while (p != NULL) {
        if (p->info.donGia1SP > max) {
            max = p->info.donGia1SP;
            pLuuTru = p;
        }
        p = p->pnext;
    }

    cout << "\nThong tin mat hang gia cao nhat :";
    cout << "\n" << pLuuTru->info.maSP << "\n" << pLuuTru->info.tenSP
        << "\n" << pLuuTru->info.soLuong << "\n" << pLuuTru->info.namSX
        << "\n" << pLuuTru->info.donGia1SP;
}

void sapXep(List& l) {
    MatHang* p = new MatHang;
    p = l.phead;

    // neu list khong rong
    if (p != NULL) {
        long soLanDoiCho = -1;

        while (soLanDoiCho != 0) {
            soLanDoiCho = 0;

            while (p->pnext != NULL) {
                if (p->info.maSP > p->pnext->info.maSP) {
                    swap(p->info, p->pnext->info);

                    soLanDoiCho++;
                }

                p = p->pnext;
            }

        }
    }
}

//
//void timBaiBao(List& l, string x) {
//    Paper* p = new Paper;
//    p = l.phead;
//    long soLanTimThay = 0;
//
//    while (p != NULL) {
//        for (long i = 0; i < p->info.soTacGia; i++) {
//            if (p->info.tacGia[i].name == x) {
//                cout << "\n" << p->info.name;
//                soLanTimThay++;
//            }
//        }
//
//        p = p->pnext;
//    }
//
//    if (soLanTimThay == 0) {
//        cout << "\nKhong co tac gia nay.";
//    }
//}
//
//
//
//void timVaXoa(List& l, string x) {
//    Paper* p = new Paper;
//    p = l.phead;
//
//    if (l.ptail != NULL) {
//        // kiem tra phead
//        for (long i = 0; i < l.phead->info.soTacGia; i++) {
//            if (l.phead->info.tacGia[i].noiCongTac == x) {
//                l.phead = l.phead->pnext;
//            }
//        }
//
//        while (p != NULL && p->pnext != NULL)
//        {
//            for (long i = 0; i < p->pnext->info.soTacGia; i++) {
//                if (p->pnext->info.tacGia[i].noiCongTac == x) {
//                    p->pnext = p->pnext->pnext;
//                    break;
//                }
//                else {
//                    if (i == p->pnext->info.soTacGia - 1) {
//                        p = p->pnext;
//                        break;
//                    }
//                }
//            }
//
//        }
//    }
//}

long luaChonMenu()
{
    long lua_chon1;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 1. Nhap danh sach n mat hang va xuat ra danh sach vua nhap. ";
    cout << "\n 2. Tim mat hang co gia cao nhat trong danh sach.";
    cout << "\n 3. Sap xep mat hang theo chieu tang dan cua ma san pham.";
    cout << "\n 4. Thoat chuong trinh";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> lua_chon1;
    return lua_chon1;
}

int main() {
    List l1;
    init(l1);
    long n;

    long lua_chon1;
    bool flag = true;
    while (flag == true) {
        lua_chon1 = luaChonMenu();
        switch (lua_chon1)
        {
        case 1:
        {
            cout << "Nhap so luong mat hang: ";
            cin >> n;
            for (long i = 0; i < n; i++) {
                addMatHang(l1, newMatHang());
            }

            xuat(l1);
        }
        continue;

        case 2: {
            timGiaCaoNhat(l1);
        }
              continue;

        case 3: {
            sapXep(l1);
            xuat(l1);
        }
              continue;
        case 4:
        {
            cout << "Tam biet!";
            flag = false;
        }
        break;

        default:
            cout << "Lua chon khong dung, vui long nhap lai.\n";
        }

    }
    return 0;
}
