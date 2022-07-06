#include <iostream>
using namespace std;

struct Tnode {
    int Key;
    Tnode* pLeft;
    Tnode* pRight;
};

typedef Tnode* Tree;

Tnode* CreateTnode(int x) {
    Tnode* p = new Tnode;
    if (p == NULL) {
        return NULL;
    }
    else {
        p->Key = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;
}

int InsertTnode(Tree& t, Tnode* node) {
    if (t != NULL) {
        if (node->Key == t->Key)
            return 0;
        else {
            if (node->Key < t->Key)
                InsertTnode(t->pLeft, node);
            else
                InsertTnode(t->pRight, node);
        }
    }
    else {
        t = node;
        return 1;
    }
}

void Nhap(Tree& t) {
    int n;
    cout << "Nhap so node: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Nhap gia tri Key: ";
        cin >> x;
        InsertTnode(t, CreateTnode(x));
    }
}

void Init(Tree& t) {
    t = NULL;
}

void LNR(Tree& t) {
    if (t != NULL) {
        LNR(t->pLeft);
        cout << t->Key << "\n";
        LNR(t->pRight);
    }
}

void LRN(Tree& t) {
    if (t != NULL) {
        LRN(t->pLeft);
        LRN(t->pRight);
        cout << t->Key << "\n";
    }
}

void NLR(Tree& t) {
    if (t != NULL) {
        cout << t->Key << "\n";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void NRL(Tree& t) {
    if (t != NULL) {
        cout << t->Key << "\n";
        NRL(t->pRight);
        NRL(t->pLeft);
    }
}

void RNL(Tree& t) {
    if (t != NULL) {
        RNL(t->pRight);
        cout << t->Key << "\n";
        RNL(t->pLeft);
    }
}

void RLN(Tree& t) {
    if (t != NULL) {
        LNR(t->pRight);
        LNR(t->pLeft);
        cout << t->Key << "\n";
    }
}

bool SearchTnode(Tree& t, int x) {
    if (t != NULL) {
        if (t->Key == x) {
            return 1;
        }
        else {
            if (t->Key < x) {
                return SearchTnode(t->pRight, x);
            }
            else {
                return SearchTnode(t->pLeft, x);
            }
        }
    }
    else
        return 0;
}

void SearchTM(Tree& pHuy, Tree& TM) {
    if (pHuy->pRight != NULL) {
        SearchTM(pHuy->pRight, TM);
    }
    else {
        pHuy->Key = TM->Key;
        pHuy = TM;
        TM = TM->pLeft;
    }
}

void Remove(Tree& t, int x) {
    if (t != NULL) {
        if (x < t->Key) {
            Remove(t->pLeft, x);
        }
        else {
            if (x > t->Key) {
                Remove(t->pRight, x);
            }
            else {
                Tnode* pHuy = t;
                if (t->pLeft == NULL) {
                    t = t->pRight;
                }
                else {
                    if (t->pRight == NULL) {
                        t = t->pLeft;
                    }
                    else {
                        SearchTM(t, t->pLeft);
                    }
                }
            }
        }
    
        
    }
}
int luaChonMenu()
{
    int lua_chon1;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 1. Nhap vao cay nhi phan tim kiem va in ra theo thu tu: LNR, LRN, NLR, NRL, RNL, RLN. ";
    cout << "\n 2. Tim node co khoa X";
    cout << "\n 3. Xoa 1 node co khoa X";
    cout << "\n 4. In ra tong so node";
    cout << "\n 15. Thoat chuong trinh";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> lua_chon1;
    return lua_chon1;
}

int main() {
    Tree t1;
    Init(t1);

    int lua_chon1;
    bool flag = true;
    while (flag == true) {
        lua_chon1 = luaChonMenu();
        switch (lua_chon1)
        {
        case 1:
        {
            Nhap(t1);
            LNR(t1);
            LRN(t1);
            NLR(t1);
            NRL(t1);
            RNL(t1);
            RLN(t1);

        }
        break;

        case 2: {
            int x;
            cout << "\nNhap khoa x can tim";
            cin >> x;

            if (SearchTnode(t1, x) == 1) {
                cout << "\nTim thay!";
            }
            else
                cout << "\nKhong tim thay!";
        }
              break;

        case 3: {
            int x;
            cout << "Nhap gia tri can xoa: ";
            cin >> x;
            Remove(t1, x);
            LNR(t1);
        }
              break;

        case 15:
        {
            cout << "Tam biet!";
            flag = false;
        }
        break;

        default:
            cout << "Lua chon khong dung, vui long nhap lai.\n";
            //break;
        }

    }
    return 0;
}
