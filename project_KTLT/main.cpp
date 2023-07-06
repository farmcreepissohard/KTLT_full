#include"header.h"

int main() {
	int year, semester;
	int truycap, mark;
	fstream f;
	f.open("truycap.txt", ios::in);
	f >> truycap;
	f >> mark;
	f.close();
	while (1) {
		system("cls");
		cout << "-------chon doi tuong-------" << endl;
		cout << "1. Giao vu" << endl;
		cout << "2. Sinh vien" << endl;
		int l;
		cin >> l;
		cin.ignore();
		if (l == 1) {
			system("cls");
			int flag;
			if (log_in("login_asm.txt", flag)) {
				giaovu gv;
				while (1) {
					system("cls");
					int luachon;
					cout << "---------MENU---------" << endl;
					cout << "1. he thong chinh " << endl;
					cout << "2. thong tin ca nhan " << endl;
					cout << "3. doi mat khau " << endl;
					cout << "4. dang xuat" << endl;
					cout << "5. thoat " << endl;
					cout << "nhap lua chon: ";
					cin >> luachon;
					cin.ignore();
					if (luachon == 1) {
						hethongchinh_gv(year, semester, truycap, mark);
					}
					else if (luachon == 2) {
						cout << "thong tin ca nhan: " << endl;
						if (flag == 0) {
							thongtin_asm("asm_1.txt", gv);
							cout << "chon 1 de quay ve" << endl;
							int x;
							cin >> x;

						}
						else if (flag == 1) {
							thongtin_asm("asm_2.txt", gv);
							cout << "chon 1 de quay ve" << endl;
							int x;
							cin >> x;
						}
						else if (flag == 2) {
							thongtin_asm("asm_3.txt", gv);
							cout << "chon 1 de quay ve" << endl;
							int x;
							cin >> x;
						}
						cin.ignore();
					}
					if (luachon == 3) {
						cout << "doi mat khau " << endl;
						doimatkhau("login_asm.txt", flag);
						cout << "chon 1 de quay ve" << endl;
						int x;
						cin >> x;
						cin.ignore();
					}
					if (luachon == 4) {
						fstream f1;
						f1.open("truycap.txt", ios::out);
						f1 << truycap << endl;
						f1 << mark;
						f1.close();
						break;
					}
					if (luachon == 5){
						cout << "cam on ban da su dung he thong" << endl;
						fstream f1;
						f1.open("truycap.txt", ios::out);
						f1 << truycap << endl;
						f1 << mark;
						f1.close();
						exit(0);
					}
				}
			}
		}
		else if (l == 2) {
			while (1) {
				system("cls");
				cout << "---------MENU---------" << endl;
				cout << "1. dau hoc ky" << endl;
				cout << "2. cuoi hoc ky" << endl;
				cout << "3. dang xuat" << endl;
				cout << "4. thoat" << endl;
				int luachon;
				cin >> luachon;
				cin.ignore();
				if (luachon == 1) {
					dauhk_sv();
				}
				else if (luachon == 2) {
					if (mark == 0) {
						system("cls");
						cout << "giao vu chua ghi diem" << endl;
						cout << "chon 1 de thoat" << endl;
						int x;
						cin >> x;
						cin.ignore();
					}
					else {
						cuoihk_sv();
					}
				}
				else if (luachon == 3) {
					break;
				}
				else if (luachon == 4) {
					cout << "cam on ban da su dung he thong" << endl;
					fstream f1;
					f1.open("truycap.txt", ios::out);
					f1 << truycap << endl;
					f1 << mark;
					f1.close();
					exit(0);
				}
			}
		}
	}
}