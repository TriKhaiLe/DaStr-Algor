#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include<string>
#define MAX 100

using namespace std;

int arr[MAX];
int n;

int luaChonMenu()
{
	int lua_chon1;
	cout << "\n ================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 1. In ra mang";
	cout << "\n 2. Tim max";
	cout << "\n 3. Tim max's index";
	cout << "\n 4. Tim tat ca max's index";
	cout << "\n 5. Tim vi tri co gia tri x bang tim kiem tuyen tinh";
	cout << "\n 6. Tim vi tri co gia tri x bang tim kiem tuyen tinh cai tien";
	cout << "\n 7. Tim tat ca vi tri co gia tri x";

	cout << "\n 13. Thoat chuong trinh";
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> lua_chon1;
	return lua_chon1;
}

int linearSearch(int A[], int n, int x) {
	int i = 0;
	while (i < n)
	{
		if (A[i] == x)
			return i;
		i++;
	}
	return -1;
}

int linearSearchA(int A[], int n, int x) {
	int i = 0; A[n] = x;
	while (A[i] != x)
		i++;
	if (i < n)
		return i;
	else
		return -1;
}

int main() {
	cout << "Nhap n = ";
	cin >> n;
	
	int lua_chon1;
	bool flag = true;
	while (flag == true) {
		lua_chon1 = luaChonMenu();
		switch (lua_chon1)
		{
		case 1:
		{
			srand((int)time(0));
			for (int i = 0; i < n; i++)
			{
				arr[i] = rand();
				cout << arr[i] << " ";

			}
		}
			break;

		case 2: {
			int max = -1;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] > max)
					max = arr[i];
			}
			cout << max;
		}
			break;

		case 3: {
			int index = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] > arr[index])
					index = i;
			}
			cout << index;
		}
			break;

		case 4: {
			int index = 0;
			int indexArr[MAX];

			for (int i = 0; i < n; i++)
			{
				if (arr[i] > arr[index])
					index = i;
			}
			for (int i = 0; i < n; i++)
			{
				int ii = 0;
				if (arr[i] == arr[index])
				{
					indexArr[ii] = i;
					cout << indexArr[ii] << " ";
					ii++;
				}
			}
		}
			  break;

		case 5: 
		{
			int x;
			cout << "Nhap x can tim: ";
			cin >> x;

			clock_t start, finish;

			start = clock();

			for (int ii = 0; ii < 100000000; ii++)
			{
				linearSearch(arr, n, x);
			}

			finish = clock();

			cout << (float)(finish - start) / (float)CLOCKS_PER_SEC << ".10^(-8) (s)";
		}
			  break;

		case 6: 
		{
			int x;
			cout << "Nhap x can tim: ";
			cin >> x;

			clock_t start, finish;

			start = clock();

			for (int ii = 0; ii < 100000000; ii++)
			{
				linearSearchA(arr, n, x);
			}

			finish = clock();

			cout << (float)(finish - start) / (float)CLOCKS_PER_SEC << ".10^(-8) (s)";
		}
			  break;

		case 7:
		{
			int x;
			cout << "Nhap x can tim: ";
			cin >> x;

			int index = linearSearch(arr, n, x);
			if (index != -1)
			{
				for (int i = 0; i < n; i++)
				{
					if (arr[i] == arr[index])
					{
						cout << i << " ";
					}
				}
			}
			else
			{
				cout << "Khong tim thay\n";
			}
		}
			break;

		case 8:
		{
			int x;
			cout << "Nhap x can tim: ";
			cin >> x;

			int index = linearSearch(arr, n, x);
			if (index != -1)
			{
				for (int i = 0; i < n; i++)
				{
					if (arr[i] == arr[index])
					{
						cout << i << " ";
					}
				}
			}
			else
			{
				cout << "Khong tim thay\n";
			}
		}
		break;
		case 13:
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



