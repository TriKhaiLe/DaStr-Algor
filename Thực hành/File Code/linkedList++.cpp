#include<iostream>
#include<string>
using namespace std;

struct Sv {
	string hoTen, maSoSv;
	int namSinh;
	float diemTb;
};

struct node {
	Sv data;
	node* pnext;
};
struct lisst {
	node* ptail;
	node* phead;
}l1, l2;

int luaChonMenu();

void initiate(lisst& l) {
	l.phead = NULL;
	l.ptail = NULL;
}

node* get_x() {
	node* p = new node;
	p->pnext = NULL;

	cout << "\nNhap ten: ";
	cin.ignore();
	getline(cin, p->data.hoTen);

	cout << "\nNhap mssv: ";
	getline(cin, p->data.maSoSv);

	cout << "\nNhap nam sinh: ";
	cin >> p->data.namSinh;

	cout << "\nNhap diem TB: ";
	cin >> p->data.diemTb;

	return p;
}

//node* create_node(int x) {
//	node* p = new node;
//	p->data = x;
//	p->pnext = NULL;
//	return p;
//}

void add_head(lisst& l, node* p) {
	if (l.phead != NULL) {
		p->pnext = l.phead;
		l.phead = p;
	}
	else {
		l.phead = l.ptail = p;
	}
}

void add_tail(lisst& l, node* p) {
	if (l.ptail != NULL) {
		l.ptail->pnext = p;
		l.ptail = p;
	}
	else {
		l.phead = l.ptail = p;
	}
}

//node* print_reverse(node* p) {
//	if (p->pnext == NULL) {
//		return p;
//	}
//	else
//		cout << print_reverse(p->pnext)->data << " ";
//
//	return p;
//}

void get_list_from_keyboard_head(lisst& l) {
	int n;
	cout << "\nNhap so sinh vien: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		add_head(l, get_x());
	}
}

void get_list_from_keyboard_tail(lisst& l) {
	int n;
	cout << "\nNhap so sinh vien: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		add_tail(l, get_x());
	}
}

void show_list(lisst l) {
	node* p = l.phead;
	int count = 1;
	while (p != NULL) {
		cout << "\nSinh vien " << count << ":";

		cout << "\nTen sv: ";
		cout << p->data.hoTen;

		cout << "\nMssv: ";
		cout << p->data.maSoSv;

		cout << "\nNam sinh: ";
		cout << p->data.namSinh;

		cout << "\nDiem TB: ";
		cout << p->data.diemTb;

		++count;
		p = p->pnext;
	}
}

void show_conditionList(lisst l) {
	node* p = l.phead;

	int count = 1;
	while (p != NULL) {
		if (p->data.diemTb < 5) {
			cout << "\nSinh vien " << count << ":";

			cout << "\nTen sv: ";
			cout << p->data.hoTen;

			cout << "\nMssv: ";
			cout << p->data.maSoSv;

			cout << "\nNam sinh: ";
			cout << p->data.namSinh;

			cout << "\nDiem TB: ";
			cout << p->data.diemTb;

			++count;		
		}
		p = p->pnext;
	}
}

//int count_node(lisst l) {
//	node* p = l.phead;
//	int count = 1;
//
//	if (p == NULL)
//		return 0;
//
//	while (p->pnext != NULL) {
//		count++;
//		p = p->pnext;
//	}
//	return count;
//}

//node* find_node(lisst l, int x) {
//	node* p = l.phead;
//	for (int i = count_node(l); i >= 0; i--) {
//		if (p->data == x)
//			return p;
//		else {
//			p = p->pnext;
//		}
//	}
//}

int main() {
	int n;
	int lua_chon1;
	bool flag = true;

	initiate(l1);
	while (flag == true) {
		lua_chon1 = luaChonMenu();
		switch (lua_chon1)
		{
		case 1:
		{

			get_list_from_keyboard_head(l1);
			show_list(l1);
		}
		break;

		case 2: {
			get_list_from_keyboard_tail(l1);
			show_list(l1);
		}
			  break;

		case 3: {
			//get_list_from_keyboard_head(l1);
			show_conditionList(l1);
		}
			  break;

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
	return 0;
}

int luaChonMenu()
{
	int lua_chon1;
	cout << "\n ================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 1. Nhap N sinh vien tu ban phim (add head) va xuat ra";
	cout << "\n 2. Nhap N sinh vien tu ban phim (add tail) va xuat ra";
	cout << "\n 3. In danh sach sinh vien co diem TB < 5";
	cout << "\n 4. Thoat chuong trinh";
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> lua_chon1;
	return lua_chon1;
}


