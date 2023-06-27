#include"header.h"

int main() {
	cout << "nhap 1 neu la Academic staff members, nhap 2 neu la students: ";
	int n;
	do {
		cin >> n;
		if (n != 1 && n != 2) {
			cout << " nhap lai lua chon: ";
		}
	} while (n != 1 && n != 2);

	//giao vu
	if (n == 1) { 
		int flag;
		if (log_in("login_asm.txt",flag)) {
			giaovu gv;
			int luachon;
			cout << "---------MENU---------" << endl;
			cout << "1. he thong chinh " << endl;
			cout << "2. thong tin ca nhan " << endl;
			cout << "3. doi mat khau " << endl;
			cout << "4. dang xuat" << endl;
			cout << "5. thoat " << endl;
			cout << "nhap lua chon: ";
			cin >> luachon;
			while (1) {
				switch (luachon) {
				case 1:
					break;
				case 2:
					cout << "thong tin ca nhan: " << endl;
					if (flag == 0) {
						thongtin_asm("asm_1.txt", gv);
					}
					else if (flag == 1) {
						thongtin_asm("asm_2.txt", gv);
					}
					else if (flag == 2) {
						thongtin_asm("asm_3.txt", gv);
					}
					break;
				case 3:
					cout << "doi mat khau " << endl;
					doimatkhau("login_asm.txt", flag);
					break;
				case 4:
					break;
				case 5:
					cout << "cam on ban da su dung he thong";
					exit(1);
				}
			}
		}
		else {
			exit(1);
		}
	}
}