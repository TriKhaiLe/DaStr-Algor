#include<string>
#include <iostream>

using namespace std;

class Tnode {
public:
    int value;

    Tnode* left;
    Tnode* right;
};

typedef Tnode* Tree;

void init(Tree& t){
    t = NULL;
}

bool isEmpty(Tree t) {
    if (t == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

Tnode* createNode(int x) {
    Tnode* p = new Tnode;
    p->value = x;
    p->left = p->right = NULL;

    return p;
}

void insert(Tree& t, Tnode* p) {
    if (isEmpty(t) == 1) {
        t = p;
    }
    else {
        if (p->value > t->value) {
            insert(t->right, p);
        }
        if (p->value < t->value) {
            insert(t->left, p);
        }
    }
}

void LRN(Tree t) {
    if (isEmpty(t) != 1) {
        LRN(t->left);
        LRN(t->right);
        cout << t->value << " ";
    }
}



int luaChonMenu()
{
    int lua_chon1;
    cout << "\n ================================";
    cout << "\n Vui long chon chuc nang tuong ung";
    cout << "\n 1. Duyet cay LRN. ";
    cout << "\n 2. In tat ca node o muc k.";
    cout << "\n 3. In tat ca so chinh phuong co tren cay.";
    cout << "\n 4. Thoat chuong trinh";
    cout << "\n ================================";
    cout << "\n Lua chon cua ban: ";
    cin >> lua_chon1;
    return lua_chon1;
}

int main()
{
    Tree orangeTree;
    init(orangeTree);
    int n;

    int lua_chon1;
    bool flag = true;
    while (flag == true) {
        lua_chon1 = luaChonMenu();
        switch (lua_chon1)
        {
        case 1:
        {
            cout << "\nNhap so node: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                insert(orangeTree, createNode(x));
            }

            LRN(orangeTree);
        }
        continue;

        case 2: {
            
        }
              continue;

        case 3: {
            
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
            //break;
        }

    }

}

