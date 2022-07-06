#include<iostream>
using namespace std;

struct node {
	int data;
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

int get_x() {
	int x;
	cout << "\nNhap du lieu cho node: ";
	cin >> x;
	return x;
}

node* create_node(int x) {
	node* p = new node;
	p->data = x;
	p->pnext = NULL;
	return p;
}

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

node* print_reverse(node* p) {
	if (p->pnext == NULL) {
		return p;
	}
	else
		cout << print_reverse(p->pnext)->data << " ";

	return p;
}

void get_list_from_keyboard(lisst& l, char i) {
	int n;
	cout << "\nNhap so node: ";
	cin >> n;

	if (i - 'h' == 0) {
		for (int i = 0; i < n; i++) {
			add_head(l, create_node(get_x()));
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			add_tail(l, create_node(get_x()));
		}
	}

}

void show_list(lisst l) {
	node* p = l.phead;

	while (p != NULL) {
		cout << p->data << " ";
		p = p->pnext;
	}
}

int count_node(lisst l) {
	node* p = l.phead;
	int count = 1;

	if (p == NULL)
		return 0;

	while (p->pnext != NULL) {
		count++;
		p = p->pnext;
	}
	return count;
}

node* find_node(lisst l, int x) {
	node* p = l.phead;
	for (int i = count_node(l); i >= 0; i--) {
		if (p->data == x)
			return p;
		else {
			p = p->pnext;
		}
	}
}

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

			get_list_from_keyboard(l1, 'h');
			show_list(l1);
		}
		break;

		case 2: {

			get_list_from_keyboard(l2, 't');
			show_list(l2);
		}
			  break;

		case 3: {
			cout << print_reverse(l2.phead)->data << "\n";
		}
			  break;

		case 4: {
			cout << "\nList nay co so node la: " << count_node(l2);
		}

			  break;
		case 5:
			find_node(l2, get_x());
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			break;

		case 9: {
			cout << "Tam biet.\n";
			flag = false;
		}
			  break;

		default:
			cout << "Lua chon khong dung, vui long nhap lai.\n";
			break;
		}

	}
	return 0;
}

int luaChonMenu()
{
	int lua_chon1;
	cout << "\n ================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 1. Input and output n elements to the list by add to the top of the list and print the imported list.";
	cout << "\n 2. Input and output n elements to the list by add to the end of the list and print the imported list.";
	cout << "\n 3. Print the list in the reverse order";
	cout << "\n 4. Count the number of nodes in a singly linked list.";
	cout << "\n 5. Find a node whose data element is X entered from the keyboard.";
	cout << "\n 6. Delete the head node of the list.";
	cout << "\n 7. Delete the tail node of the list.";
	cout << "\n 8. elete a node whose data field is equal to X, otherwise the message is absent.";
	cout << "\n 8. Delete a node whose data field is equal to X, otherwise the message is absent.";
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> lua_chon1;
	return lua_chon1;
}


